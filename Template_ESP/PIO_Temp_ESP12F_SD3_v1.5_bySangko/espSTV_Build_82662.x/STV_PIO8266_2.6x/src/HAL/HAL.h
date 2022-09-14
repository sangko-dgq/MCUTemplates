

#ifndef _HAL_H
#define _HAL_H
#include "../Common/g_config.h"
#include "../APP/APP.h"



/*EEPROM*/
void EEPROM_Init();//MAIN

void save_CityCode_toEEP(int *citycode);
void update_CityCode_fromEEP(int *citycode);

void save_WifiConfig_toEEP();
void delete_WifiConfig_inEEP();
void update_WifiConfig_fromEEP();

void update_DHTen_fromEEP();

void update_BLKval_fromEEP();
void update_Rotation_fromEEP();

void update_WeaterFlushPer_fromEEP();

/*TFTLcd*/
void TFTLcd_Init();

/*DHT11*/
#if DHT_EN
void IndoorTem();
#endif

/*方式1：微信扫码配置网络*/
#if !WM_EN
void SmartConfig(void);
#endif

/*方式2: WEB配网*/
#if WM_EN
void TipPage_PleaseConfigWIFI_Web();
void Webconfig();
String getParam(String name);
void saveParamCallback();
#endif


/*WebServer*/
#if WebSever_EN
void handleconfig();
void handleNotFound();
void Web_Sever_Init();
void Web_sever_Win();
void Web_Sever();
#endif

/*串口调试*/
void Serial_set();

/*CityCode*/
void getCityCode();
void buildCityWeater();

/*NTP*/
time_t getNtpTime();
void sendNTPpacket(IPAddress &address);






#endif // !_HAL_H