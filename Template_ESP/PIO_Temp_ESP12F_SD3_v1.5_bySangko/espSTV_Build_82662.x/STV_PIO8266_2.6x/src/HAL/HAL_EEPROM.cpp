#include "HAL.h"

//EEPROM参数存储地址位分配
int BL_addr = 1;    //被写入数据的EEPROM地址编号  1亮度
int Ro_addr = 2;    //被写入数据的EEPROM地址编号  2 旋转方向
int DHT_addr = 3;   //3 DHT使能标志位
int UpWeT_addr = 4; //4 更新时间记录
int CC_addr = 10;   //被写入数据的EEPROM地址编号  10城市
int wifi_addr = 30; //被写入数据的EEPROM地址编号  20wifi-ssid-psw

/* *****************************************************************
 *  EEPROM_Init
 * *****************************************************************/
void EEPROM_Init()
{
  /*初始化，申请1MB的EEPROM*/
  EEPROM.begin(1024);
  /*从EEPROM更新数据配置变量*/
  update_DHTen_fromEEP();
  update_BLKval_fromEEP();
  update_Rotation_fromEEP();
  update_WeaterFlushPer_fromEEP();

  update_WifiConfig_fromEEP();
}

/* *****************************************************************
 *  CityCode_EEP
 * *****************************************************************/
/*保存CityCode到EEPROM*/
void save_CityCode_toEEP(int *citycode)
{
  for (int cnum = 0; cnum < 5; cnum++)
  {
    EEPROM.write(CC_addr + cnum, *citycode % 100); //城市地址写入城市代码
    EEPROM.commit();                               //保存更改的数据
    *citycode = *citycode / 100;
    delay(5);
  }
}
/*更新CityCode从EEP*/
void update_CityCode_fromEEP(int *citycode)
{
  for (int cnum = 5; cnum > 0; cnum--)
  {
    *citycode = *citycode * 100;
    *citycode += EEPROM.read(CC_addr + cnum - 1);
    delay(5);
  }
}

/* *****************************************************************
 *  WifiConfig_EEP
 * *****************************************************************/
/*wifi ssid，psw保存到eeprom*/
void save_WifiConfig_toEEP()
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
//删除原有eeprom中的wificonfigs信息
void delete_WifiConfig_inEEP()
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

//从eeprom读取WiFi信息ssid，psw，并更新给wificonf
void update_WifiConfig_fromEEP()
{
  uint8_t *p = (uint8_t *)(&wificonf);
  for (int i = 0; i < sizeof(wificonf); i++)
  {
    *(p + i) = EEPROM.read(i + wifi_addr);
  }
  // EEPROM.commit();
  // ssid = wificonf.stassid;
  // pass = wificonf.stapsw;
  Serial.printf("Read WiFi Config from EEPROM.....\r\n");
  Serial.printf("SSID:%s\r\n", wificonf.stassid);
  Serial.printf("PSW:%s\r\n", wificonf.stapsw);
  Serial.printf("Connecting.....\r\n");
}

/* *****************************************************************
 *  DHT_EEP
 * *****************************************************************/
void update_DHTen_fromEEP()
{
  /*从eeprom读取DHT传感器使能标志，更新给is_DHT_Use*/
#if DHT_EN
  dht.begin();
  is_DHT_Use = EEPROM.read(DHT_addr);
#endif
}

/* *****************************************************************
 *  LCD_BLK_EEP
 * *****************************************************************/
void update_BLKval_fromEEP()
{
  /*从eeprom读取背光亮度设置，满足条件下则更新给LCD_BL_PWM*/
  if (EEPROM.read(BL_addr) > 0 && EEPROM.read(BL_addr) < 100) /*属于0~100范围的情况下才读取并更新LCD_BL_PWM，否则LCD_BL_PWM使用g_config配置的默认值*/
    LCD_BL_PWM = EEPROM.read(BL_addr);
}
/* *****************************************************************
 *  LCD_Rotation_EEP
 * *****************************************************************/
void update_Rotation_fromEEP()
{
  /*从eeprom读取屏幕方向设置，更新给LCD_Rotation*/
  if (EEPROM.read(Ro_addr) >= 0 && EEPROM.read(Ro_addr) <= 3)
    LCD_Rotation = EEPROM.read(Ro_addr);
}

/* *****************************************************************
 *  weatherFlushTime_EEP
 * *****************************************************************/
void update_WeaterFlushPer_fromEEP()
{
  /*从eeprom读取天气更新时间，更新给updateweater_time*/
  updateweater_time = EEPROM.read(UpWeT_addr);
}