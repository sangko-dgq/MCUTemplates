#include "HAL/HAL.h"
#include "APP/APP.h"

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(1024);
  // WiFi.forceSleepWake();
  // wm.resetSettings();    //在初始化中使wifi重置，需重新配置WiFi

/*********************************************************************/

#if DHT_EN
  dht.begin();
  //从eeprom读取DHT传感器使能标志
  DHT_img_flag = EEPROM.read(DHT_addr);
#endif
  //从eeprom读取背光亮度设置
  if (EEPROM.read(BL_addr) > 0 && EEPROM.read(BL_addr) < 100)
    LCD_BL_PWM = EEPROM.read(BL_addr);
  pinMode(LCD_BL_PIN, OUTPUT);
  analogWrite(LCD_BL_PIN, 1023 - (LCD_BL_PWM * 10));
  //从eeprom读取屏幕方向设置
  if (EEPROM.read(Ro_addr) >= 0 && EEPROM.read(Ro_addr) <= 3)
    LCD_Rotation = EEPROM.read(Ro_addr);

  //从eeprom读取天气更新时间
  updateweater_time = EEPROM.read(UpWeT_addr);

/*********************************************************************/

  tft.begin();          /* TFT init */
  tft.invertDisplay(1); //反转所有显示颜色：1反转，0正常
  tft.setRotation(LCD_Rotation);
  tft.fillScreen(0x0000);
  tft.setTextColor(TFT_BLACK, bgColor);
/*********************************************************************/
  targetTime = millis() + 1000;
  readwificonfig(); //读取存储的wifi信息
  Serial.print("正在连接WIFI ");
  Serial.println(wificonf.stassid);
  WiFi.begin(wificonf.stassid, wificonf.stapsw);
/*********************************************************************/
  TJpgDec.setJpgScale(1);
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(tft_output);

/*********************************************************************/
  while (WiFi.status() != WL_CONNECTED)
  {
    loading(30);

    if (loadNum >= 194)
    {
//使能web配网后自动将smartconfig配网失效
#if WM_EN
      Web_win();
      Webconfig();
#endif

#if !WM_EN
      SmartConfig();
#endif
      break;
    }
  }
  delay(10);
  while (loadNum < 194) //让动画走完
  {
    loading(1);
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    // Serial.print("SSID:");
    // Serial.println(WiFi.SSID().c_str());
    // Serial.print("PSW:");
    // Serial.println(WiFi.psk().c_str());
    strcpy(wificonf.stassid, WiFi.SSID().c_str()); //名称复制
    strcpy(wificonf.stapsw, WiFi.psk().c_str());   //密码复制
    savewificonfig();
    readwificonfig();
#if WebSever_EN
    //开启web服务器初始化
    Web_Sever_Init();
    Web_sever_Win();
    delay(10000);
#endif
  }

  // Serial.print("本地IP： ");
  // Serial.println(WiFi.localIP());
  Serial.println("启动UDP");
  Udp.begin(localPort);
  Serial.println("等待同步...");
  setSyncProvider(getNtpTime);
  setSyncInterval(300);

  TJpgDec.setJpgScale(1);
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(tft_output);

  int CityCODE = 0;
  readCityCodefromEEP(&CityCODE);
  // for(int cnum=5;cnum>0;cnum--)
  // {
  //   CityCODE = CityCODE*100;
  //   CityCODE += EEPROM.read(CC_addr+cnum-1);
  //   delay(5);
  // }
  if (CityCODE >= 101000000 && CityCODE <= 102000000)
    cityCode = CityCODE;
  else
    getCityCode(); //获取城市代码

  tft.fillScreen(TFT_BLACK); //清屏

  TJpgDec.drawJpg(15, 183, temperature, sizeof(temperature)); //温度图标
  TJpgDec.drawJpg(15, 213, humidity, sizeof(humidity));       //湿度图标

  getCityWeater();
#if DHT_EN
  if (DHT_img_flag != 0)
    IndoorTem();
#endif
#if !WebSever_EN
  WiFi.forceSleepBegin(); //wifi off
  Serial.println("WIFI休眠......");
  Wifi_en = 0;
#endif
}

void loop()
{
#if WebSever_EN
  Web_Sever();
#endif
  LCD_reflash(0);
  Serial_set();
}
