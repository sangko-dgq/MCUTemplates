#include "HAL/HAL.h"
#include "APP/APP.h"

void setup()
{
  Serial.begin(115200);
  // WiFi.forceSleepWake();
  // wm.resetSettings();    //在初始化中使wifi重置，需重新配置WiFi
  /*********************************************************************/
  EEPROM_Init(); /*读取存储的配置，更新给对应数据变量*/
  /*********************************************************************/
  TFTLcd_Init();
  /*********************************************************************/
  targetTime = millis() + 1000;
  /*********************************************************************/
  //update_WifiConfig_fromEEP();
  Serial.print("正在连接: ");
  Serial.println(wificonf.stassid);
  WiFi.begin(wificonf.stassid, wificonf.stapsw);
  /*********************************************************************/
  TJpgDec.setJpgScale(1);
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(tft_output);

  /*********************************************************************/
  /*
    当WIFi处于未连接成功状态（处于连接中或处于用户配网中）
    先加载进度条，然后进入阻塞等待页面
    直到WIFI成功完全连接（配网成功或从EEP成功更新来配置成功后，才跳出While进入下一个页面（主页面））
   */
  while (WiFi.status() != WL_CONNECTED)
  {
    /*
    EEPROM中无数据的情况下需要重新配网，相当于一个预加载动画
    如果基于EEPROM保存的WIFI配置，一般很快，这一条代码LcdBuild_LoadingBar参数效果不会太明显
    当EEPROM中没有WIFi配置数据，这一条LcdBuild_LoadingBar参数作用明显
    */
    LcdBuild_LoadingBar(30); //以每30ms进度增1的方式运行进度条动画（在此while里面实现循环loadingBarValue递增到最大）

    if (loadingBarValue >= 194) /*进度条走完后,还没有连接成功，说明EEPROM里面无配置数据，则开启配置提示*/
    {
/* 1. WEB配网方式*/
#if WM_EN
      TipPage_PleaseConfigWIFI_Web();  /*显示相关提示UI*/
      Webconfig();/*开启WIFi热点等*/
#endif

/* 2. 微信扫码配网方式*/
#if !WM_EN
      SmartConfig(); /*显示二维码*/
#endif
      break;
    }
  }

  /*********************************************************************/
  delay(10); 
  /*********************************************************************/

  /*
   防止WIFI在loading中途中连接成功（正常情况下基于EEPROM数据配置WIFI很快，所以这一条LcdBuild_LoadingBar的传入参数作用很明显）
  */
  while (loadingBarValue < 194) //让动画走完
  {
    LcdBuild_LoadingBar(1);
  }

  /*********************************************************************/
  /*WIFi连接成功*/
  if (WiFi.status() == WL_CONNECTED)
  {
    // Serial.print("SSID:");
    // Serial.println(WiFi.SSID().c_str());
    // Serial.print("PSW:");
    // Serial.println(WiFi.psk().c_str());
    strcpy(wificonf.stassid, WiFi.SSID().c_str()); //名称复制
    strcpy(wificonf.stapsw, WiFi.psk().c_str());   //密码复制
    save_WifiConfig_toEEP();
    update_WifiConfig_fromEEP();
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
  update_CityCode_fromEEP(&CityCODE);
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

  buildCityWeater();
#if DHT_EN
  if (is_DHT_Use != 0)
    IndoorTem();
#endif
#if !WebSever_EN
  WiFi.forceSleepBegin(); //wifi off
  Serial.println("WIFI休眠......");
  is_Wifi_ON = 0;
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
