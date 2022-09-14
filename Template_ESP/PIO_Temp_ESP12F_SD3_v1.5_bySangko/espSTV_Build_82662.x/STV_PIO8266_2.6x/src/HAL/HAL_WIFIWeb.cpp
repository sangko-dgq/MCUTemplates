#include "HAL.h"



#if WM_EN
/*
*                             PleaseConfigWIFI
* @Preference  绘制页面
* @Of          WEB页面配网方式
* @How         开机后，自动从EEPROM读取WIFI配置来连接WIFI，如果EEPROM里没有数据或其他原因导致连接失败，才调用此函数
* @Break       阻塞等待跳出while
* 
*/
//
void TipPage_PleaseConfigWIFI_Web()
{
  clk.setColorDepth(8);

  clk.createSprite(200, 60); //创建窗口
  clk.fillSprite(0x0000);    //填充率

  clk.setTextDatum(CC_DATUM); //设置文本数据
  clk.setTextColor(TFT_YELLOW, 0x000000); /*文本颜色*/

  clk.drawString("WiFi Connect Fail!", 100, 10, 2);
  clk.drawString("SSID:", 45, 40, 2);
  clk.setTextColor(TFT_YELLOW, 0x000000);
  clk.drawString("AutoConnectAP", 125, 40, 2);
  clk.pushSprite(20, 50); //窗口位置

  clk.deleteSprite();
}

//WEB配网函数
void Webconfig()
{
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP

  delay(3000);
  wm.resetSettings(); // wipe settings 擦除设置

  // add a custom input field
  int customFieldLength = 40;

  // new (&custom_field) WiFiManagerParameter("customfieldid", "Custom Field Label", "Custom Field Value", customFieldLength,"placeholder=\"Custom Field Placeholder\"");

  // test custom html input type(checkbox)
  //  new (&custom_field) WiFiManagerParameter("customfieldid", "Custom Field Label", "Custom Field Value", customFieldLength,"placeholder=\"Custom Field Placeholder\" type=\"checkbox\""); // custom html type

  // test custom html(radio)
  // const char* custom_radio_str = "<br/><label for='customfieldid'>Custom Field Label</label><input type='radio' name='customfieldid' value='1' checked> One<br><input type='radio' name='customfieldid' value='2'> Two<br><input type='radio' name='customfieldid' value='3'> Three";
  // new (&custom_field) WiFiManagerParameter(custom_radio_str); // custom html input

  const char *set_rotation = "<br/><label for='set_rotation'>Set Rotation</label>\
                              <input type='radio' name='set_rotation' value='0' checked> One<br>\
                              <input type='radio' name='set_rotation' value='1'> Two<br>\
                              <input type='radio' name='set_rotation' value='2'> Three<br>\
                              <input type='radio' name='set_rotation' value='3'> Four<br>";
  WiFiManagerParameter custom_rot(set_rotation); // custom html input
  WiFiManagerParameter custom_bl("LCDBL", "LCD BackLight(1-100)", "10", 3);
#if DHT_EN
  WiFiManagerParameter custom_DHT11_en("DHT11_en", "Enable DHT11 sensor", "0", 1);
#endif
  WiFiManagerParameter custom_weatertime("WeaterUpdateTime", "Weather Update Time(Min)", "10", 3);
  WiFiManagerParameter custom_cc("CityCode", "CityCode", "101250101", 9);
  WiFiManagerParameter p_lineBreak_notext("<p></p>");

  // wm.addParameter(&p_lineBreak_notext);
  // wm.addParameter(&custom_field);
  wm.addParameter(&p_lineBreak_notext);
  wm.addParameter(&custom_cc);
  wm.addParameter(&p_lineBreak_notext);
  wm.addParameter(&custom_bl);
  wm.addParameter(&p_lineBreak_notext);
  wm.addParameter(&custom_weatertime);
  wm.addParameter(&p_lineBreak_notext);
  wm.addParameter(&custom_rot);

#if DHT_EN
  wm.addParameter(&p_lineBreak_notext);
  wm.addParameter(&custom_DHT11_en);
#endif
  wm.setSaveParamsCallback(saveParamCallback);

  // custom menu via array or vector
  //
  // menu tokens, "wifi","wifinoscan","info","param","close","sep","erase","restart","exit" (sep is seperator) (if param is in menu, params will not show up in wifi page!)
  // const char* menu[] = {"wifi","info","param","sep","restart","exit"};
  // wm.setMenu(menu,6);
  std::vector<const char *> menu = {"wifi", "restart"};
  wm.setMenu(menu);

  // set dark theme
  wm.setClass("invert");

  //set static ip
  // wm.setSTAStaticIPConfig(IPAddress(10,0,1,99), IPAddress(10,0,1,1), IPAddress(255,255,255,0)); // set static ip,gw,sn
  // wm.setShowStaticFields(true); // force show static ip fields
  // wm.setShowDnsFields(true);    // force show dns field always

  // wm.setConnectTimeout(20); // how long to try to connect for before continuing
  //  wm.setConfigPortalTimeout(30); // auto close configportal after n seconds
  // wm.setCaptivePortalEnable(false); // disable captive portal redirection
  // wm.setAPClientCheck(true); // avoid timeout if client connected to softap

  // wifi scan settings
  // wm.setRemoveDuplicateAPs(false); // do not remove duplicate ap names (true)
  wm.setMinimumSignalQuality(20); // set min RSSI (percentage) to show in scans, null = 8%
  // wm.setShowInfoErase(false);      // do not show erase button on info page
  // wm.setScanDispPerc(true);       // show RSSI as percentage not graph icons

  // wm.setBreakAfterConfig(true);   // always exit configportal even if wifi save fails

  bool res;
  // res = wm.autoConnect(); // auto generated AP name from chipid
  res = wm.autoConnect("AutoConnectAP"); // anonymous ap
  //  res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

  while (!res)
    ;
}

String getParam(String name)
{
  //read parameter from server, for customhmtl input
  String value;
  if (wm.server->hasArg(name))
  {
    value = wm.server->arg(name);
  }
  return value;
}
void saveParamCallback()
{
  int cc;

  Serial.println("[CALLBACK] saveParamCallback fired");
// Serial.println("PARAM customfieldid = " + getParam("customfieldid"));
// Serial.println("PARAM CityCode = " + getParam("CityCode"));
// Serial.println("PARAM LCD BackLight = " + getParam("LCDBL"));
// Serial.println("PARAM WeaterUpdateTime = " + getParam("WeaterUpdateTime"));
// Serial.println("PARAM Rotation = " + getParam("set_rotation"));
// Serial.println("PARAM DHT11_en = " + getParam("DHT11_en"));

//将从页面中获取的数据保存
#if DHT_EN
  is_DHT_Use = getParam("DHT11_en").toInt();
#endif
  updateweater_time = getParam("WeaterUpdateTime").toInt();
  cc = getParam("CityCode").toInt();
  LCD_Rotation = getParam("set_rotation").toInt();
  LCD_BL_PWM = getParam("LCDBL").toInt();

  //对获取的数据进行处理
  //城市代码
  Serial.print("CityCode = ");
  Serial.println(cc);
  if (cc >= 101000000 && cc <= 102000000 || cc == 0)
  {
    save_CityCode_toEEP(&cc);
    // for(int cnum=0;cnum<5;cnum++)
    // {
    //   EEPROM.write(CC_addr+cnum,cc%100);//城市地址写入城市代码
    //   EEPROM.commit();//保存更改的数据
    //   cc = cc/100;
    //   delay(5);
    // }
    update_CityCode_fromEEP(&cc);
    // for(int cnum=5;cnum>0;cnum--)
    // {
    //   CCODE = CCODE*100;
    //   CCODE += EEPROM.read(CC_addr+cnum-1);
    //   delay(5);
    // }
    cityCode = cc;
  }
  //屏幕方向
  Serial.print("LCD_Rotation = ");
  Serial.println(LCD_Rotation);
  if (EEPROM.read(Ro_addr) != LCD_Rotation)
  {
    EEPROM.write(Ro_addr, LCD_Rotation);
    EEPROM.commit();
    delay(5);
  }
  tft.setRotation(LCD_Rotation);
  tft.fillScreen(0x0000);
  TipPage_PleaseConfigWIFI_Web();
  loadingBarValue--;
  LcdBuild_LoadingBar(1);
  if (EEPROM.read(BL_addr) != LCD_BL_PWM)
  {
    EEPROM.write(BL_addr, LCD_BL_PWM);
    EEPROM.commit();
    delay(5);
  }
  //屏幕亮度
  Serial.printf("亮度调整为：");
  analogWrite(LCD_BL_PIN, 1023 - (LCD_BL_PWM * 10));
  Serial.println(LCD_BL_PWM);
  //天气更新时间
  Serial.printf("天气更新时间调整为：");
  Serial.println(updateweater_time);

#if DHT_EN
  //是否使用DHT11传感器
  Serial.printf("DHT11传感器：");
  EEPROM.write(DHT_addr, is_DHT_Use);
  EEPROM.commit(); //保存更改的数据
  Serial.println((is_DHT_Use ? "已启用" : "未启用"));
#endif
}
#endif