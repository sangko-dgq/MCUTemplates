#include "HAL.h"

#if WebSever_EN
//web网站相关函数
//web设置页面
void handleconfig()
{
  String msg;
  int web_cc, web_setro, web_lcdbl, web_upt, web_dhten;

  if (server.hasArg("web_ccode") || server.hasArg("web_bl") ||
      server.hasArg("web_upwe_t") || server.hasArg("web_DHT11_en") || server.hasArg("web_set_rotation"))
  {
    web_cc = server.arg("web_ccode").toInt();
    web_setro = server.arg("web_set_rotation").toInt();
    web_lcdbl = server.arg("web_bl").toInt();
    web_upt = server.arg("web_upwe_t").toInt();
    web_dhten = server.arg("web_DHT11_en").toInt();
    Serial.println("");
    if (web_cc >= 101000000 && web_cc <= 102000000)
    {
      saveCityCodetoEEP(&web_cc);
      readCityCodefromEEP(&web_cc);
      cityCode = web_cc;
      Serial.print("城市代码:");
      Serial.println(web_cc);
    }
    if (web_lcdbl > 0 && web_lcdbl <= 100)
    {
      EEPROM.write(BL_addr, web_lcdbl); //亮度地址写入亮度值
      EEPROM.commit();                  //保存更改的数据
      delay(5);
      LCD_BL_PWM = EEPROM.read(BL_addr);
      delay(5);
      Serial.printf("亮度调整为：");
      analogWrite(LCD_BL_PIN, 1023 - (LCD_BL_PWM * 10));
      Serial.println(LCD_BL_PWM);
      Serial.println("");
    }
    if (web_upt > 0 && web_upt <= 60)
    {
      EEPROM.write(UpWeT_addr, web_upt); //亮度地址写入亮度值
      EEPROM.commit();                   //保存更改的数据
      delay(5);
      updateweater_time = web_upt;
      Serial.print("天气更新时间（分钟）:");
      Serial.println(web_upt);
    }

    EEPROM.write(DHT_addr, web_dhten);
    EEPROM.commit(); //保存更改的数据
    delay(5);
    if (web_dhten != DHT_img_flag)
    {
      DHT_img_flag = web_dhten;
      tft.fillScreen(0x0000);
      LCD_reflash(1); //屏幕刷新程序
      UpdateWeater_en = 1;
      TJpgDec.drawJpg(15, 183, temperature, sizeof(temperature)); //温度图标
      TJpgDec.drawJpg(15, 213, humidity, sizeof(humidity));       //湿度图标
    }
    Serial.print("DHT Sensor Enable： ");
    Serial.println(DHT_img_flag);

    EEPROM.write(Ro_addr, web_setro);
    EEPROM.commit(); //保存更改的数据
    delay(5);
    if (web_setro != LCD_Rotation)
    {
      LCD_Rotation = web_setro;
      tft.setRotation(LCD_Rotation);
      tft.fillScreen(0x0000);
      LCD_reflash(1); //屏幕刷新程序
      UpdateWeater_en = 1;
      TJpgDec.drawJpg(15, 183, temperature, sizeof(temperature)); //温度图标
      TJpgDec.drawJpg(15, 213, humidity, sizeof(humidity));       //湿度图标
    }
    Serial.print("LCD Rotation:");
    Serial.println(LCD_Rotation);
  }

  //网页界面代码段
  String content = "<html><style>html,body{ background: #1aceff; color: #fff; font-size: 10px;}</style>";
  content += "<body><form action='/' method='POST'><br><div>SDD Web Config</div><br>";
  content += "City Code:<br><input type='text' name='web_ccode' placeholder='city code'><br>";
  content += "<br>Back Light(1-100):(default:50)<br><input type='text' name='web_bl' placeholder='10'><br>";
  content += "<br>Weather Update Time:(default:10)<br><input type='text' name='web_upwe_t' placeholder='10'><br>";
#if DHT_EN
  content += "<br>DHT Sensor Enable  <input type='radio' name='web_DHT11_en' value='0'checked> DIS \
                                          <input type='radio' name='web_DHT11_en' value='1'> EN<br>";
#endif
  content += "<br>LCD Rotation<br>\
                    <input type='radio' name='web_set_rotation' value='0' checked> USB Down<br>\
                    <input type='radio' name='web_set_rotation' value='1'> USB Right<br>\
                    <input type='radio' name='web_set_rotation' value='2'> USB Up<br>\
                    <input type='radio' name='web_set_rotation' value='3'> USB Left<br>";
  content += "<br><div><input type='submit' name='Save' value='Save'></form></div>" + msg + "<br>";
  content += "By WCY<br>";
  content += "</body></html>";
  server.send(200, "text/html", content);
}

//no need authentication
void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

//Web服务初始化
void Web_Sever_Init()
{
  uint32_t counttime = 0; //记录创建mDNS的时间
  Serial.println("mDNS responder building...");
  counttime = millis();
  while (!MDNS.begin("SD3"))
  {
    if (millis() - counttime > 30000)
      ESP.restart(); //判断超过30秒钟就重启设备
  }

  Serial.println("mDNS responder started");
  //输出连接wifi后的IP地址
  // Serial.print("本地IP： ");
  // Serial.println(WiFi.localIP());

  server.on("/", handleconfig);
  server.onNotFound(handleNotFound);

  //开启TCP服务
  server.begin();
  Serial.println("HTTP服务器已开启");

  Serial.println("连接: http://sd3.local");
  Serial.print("本地IP： ");
  Serial.println(WiFi.localIP());
  //将服务器添加到mDNS
  MDNS.addService("http", "tcp", 80);
}
//Web网页设置函数
void Web_Sever()
{
  MDNS.update();
  server.handleClient();
}
//web服务打开后LCD显示登陆网址及IP
void Web_sever_Win()
{
  IPAddress IP_adr = WiFi.localIP();
  // strcpy(IP_adr,WiFi.localIP().toString());
  clk.setColorDepth(8);

  clk.createSprite(200, 70); //创建窗口
  clk.fillSprite(0x0000);    //填充率

  // clk.drawRoundRect(0,0,200,100,5,0xFFFF);       //空心圆角矩形
  clk.setTextDatum(CC_DATUM); //设置文本数据
  clk.setTextColor(TFT_GREEN, 0x0000);
  clk.drawString("Connect to Config:", 70, 10, 2);
  // clk.drawString("IP:",45,60,2);
  clk.setTextColor(TFT_WHITE, 0x0000);
  clk.drawString("http://sd3.local", 100, 40, 4);
  // clk.drawString(&IP_adr,125,70,2);
  clk.pushSprite(20, 40); //窗口位置

  clk.deleteSprite();
}
#endif