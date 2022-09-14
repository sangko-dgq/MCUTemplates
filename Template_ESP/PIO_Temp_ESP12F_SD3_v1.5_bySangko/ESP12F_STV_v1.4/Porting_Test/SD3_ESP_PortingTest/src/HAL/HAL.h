

#ifndef _HAL_H
#define _HAL_H
#include "../Common/g_config.h"
#include "../APP/APP.h"



/*EEPROM*/
void saveCityCodetoEEP(int *citycode);
void readCityCodefromEEP(int *citycode);
void savewificonfig();
void deletewificonfig();
void readwificonfig();

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
void Web_win();
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
void getCityWeater();

/*NTP*/
time_t getNtpTime();
void sendNTPpacket(IPAddress &address);






#endif // !_HAL_H