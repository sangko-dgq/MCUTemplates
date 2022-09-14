#include "HAL.h"


//EEPROM参数存储地址位
int BL_addr = 1;    //被写入数据的EEPROM地址编号  1亮度
int Ro_addr = 2;    //被写入数据的EEPROM地址编号  2 旋转方向
int DHT_addr = 3;   //3 DHT使能标志位
int UpWeT_addr = 4; //4 更新时间记录
int CC_addr = 10;   //被写入数据的EEPROM地址编号  10城市
int wifi_addr = 30; //被写入数据的EEPROM地址编号  20wifi-ssid-psw

/* *****************************************************************
 *  函数
 * *****************************************************************/
//读取保存城市代码
void saveCityCodetoEEP(int *citycode)
{
  for (int cnum = 0; cnum < 5; cnum++)
  {
    EEPROM.write(CC_addr + cnum, *citycode % 100); //城市地址写入城市代码
    EEPROM.commit();                               //保存更改的数据
    *citycode = *citycode / 100;
    delay(5);
  }
}
void readCityCodefromEEP(int *citycode)
{
  for (int cnum = 5; cnum > 0; cnum--)
  {
    *citycode = *citycode * 100;
    *citycode += EEPROM.read(CC_addr + cnum - 1);
    delay(5);
  }
}

//wifi ssid，psw保存到eeprom
void savewificonfig()
{
  //开始写入
  uint8_t *p = (uint8_t *)(&wificonf);
  for (int i = 0; i < sizeof(wificonf); i++)
  {
    EEPROM.write(i + wifi_addr, *(p + i)); //在闪存内模拟写入
  }
  delay(10);
  EEPROM.commit(); //执行写入ROM
  delay(10);
}
//删除原有eeprom中的信息
void deletewificonfig()
{
  config_type deletewifi = {{""}, {""}};
  uint8_t *p = (uint8_t *)(&deletewifi);
  for (int i = 0; i < sizeof(deletewifi); i++)
  {
    EEPROM.write(i + wifi_addr, *(p + i)); //在闪存内模拟写入
  }
  delay(10);
  EEPROM.commit(); //执行写入ROM
  delay(10);
}

//从eeprom读取WiFi信息ssid，psw
void readwificonfig()
{
  uint8_t *p = (uint8_t *)(&wificonf);
  for (int i = 0; i < sizeof(wificonf); i++)
  {
    *(p + i) = EEPROM.read(i + wifi_addr);
  }
  // EEPROM.commit();
  // ssid = wificonf.stassid;
  // pass = wificonf.stapsw;
  Serial.printf("Read WiFi Config.....\r\n");
  Serial.printf("SSID:%s\r\n", wificonf.stassid);
  Serial.printf("PSW:%s\r\n", wificonf.stapsw);
  Serial.printf("Connecting.....\r\n");
}




