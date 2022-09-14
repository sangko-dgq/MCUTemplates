#include "HAL.h"

#if !WM_EN
//微信配网函数
void SmartConfig(void)
{
  WiFi.mode(WIFI_STA); //设置STA模式
  //tft.pushImage(0, 0, 240, 240, qr);
  tft.pushImage(0, 0, 240, 240, qr);
  Serial.println("\r\nWait for Smartconfig..."); //打印log信息
  WiFi.beginSmartConfig();                       //开始SmartConfig，等待手机端发出用户名和密码
  while (1)
  {
    Serial.print(".");
    delay(100);                 // wait for a second
    if (WiFi.smartConfigDone()) //配网成功，接收到SSID和密码
    {
      Serial.println("SmartConfig Success");
      Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
      Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
      break;
    }
  }
  loadNum = 194;
}
#endif