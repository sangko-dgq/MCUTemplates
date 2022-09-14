/***********************************
 *           
 *          @file 全局配置文件 
 *       
 * *******************************/

#ifndef _G_CONFIG_H
#define _G_CONFIG_H

#include "../Common/headers.h"

/*版本*/
#define Version "SDD V1.4"

//WEB配网使能标志位----WEB配网打开后会默认关闭smartconfig功能
#define WM_EN 1
//Web服务器使能标志位----打开后将无法使用wifi休眠功能。
#define WebSever_EN 1

//注意，此版本中的DHT11传感器和太空人图片选择可以通过web网页设置来进行选择，无需通过使能标志来重新编译。
//设定DHT11温湿度传感器使能标志
#define DHT_EN 0
//设置太空人图片是否使用
#define imgAst_EN 1

#if WM_EN
#include "../../lib/WiFiManager/WiFiManager.h"
extern WiFiManager wm;
#endif

#if DHT_EN
#include "../../lib/DHT_sensor_library/DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT11
extern DHT dht;
#endif

#if imgAst_EN
extern int Anim;      //太空人图标显示指针记录
extern int AprevTime; //太空人更新时间记录
#endif

struct config_type
{
    char stassid[32]; //定义配网得到的WIFI名长度(最大32字节)
    char stapsw[64];  //定义配网得到的WIFI密码长度(最大64字节)
};
extern config_type wificonf;

/* *****************************************************************
 *  参数设置
 * *****************************************************************/

extern int updateweater_time; //天气更新时间  X 分钟
extern int LCD_Rotation;      //LCD屏幕方向
extern int LCD_BL_PWM;        //屏幕亮度0-100，默认50
extern String cityCode;       //天气城市代码 长沙:101250101株洲:101250301衡阳:101250401

//LCD屏幕相关设置
extern TFT_eSPI tft; // 引脚请自行配置tft_espi库中的 User_Setup.h文件
extern TFT_eSprite clk;
#define LCD_BL_PIN 5 //LCD背光引脚
extern uint16_t bgColor;

//其余状态标志位
extern uint8_t Wifi_en;         //wifi状态标志位  1：打开    0：关闭
extern uint8_t UpdateWeater_en; //更新时间标志位
extern int prevTime;            //滚动显示更新标志位
extern int DHT_img_flag;        //DHT传感器使用标志位

//EEPROM参数存储地址位
extern int BL_addr;    //被写入数据的EEPROM地址编号  1亮度
extern int Ro_addr;    //被写入数据的EEPROM地址编号  2 旋转方向
extern int DHT_addr;   //3 DHT使能标志位
extern int UpWeT_addr; //4 更新时间记录
extern int CC_addr;    //被写入数据的EEPROM地址编号  10城市
extern int wifi_addr;  //被写入数据的EEPROM地址编号  20wifi-ssid-psw

extern time_t prevDisplay;       //显示时间显示记录
extern unsigned long weaterTime; //天气更新时间记录
extern String SMOD;              //串口数据存储

/*** Component objects ***/
extern Number dig;
extern WeatherNum wrat;

extern uint32_t targetTime;

extern int tempnum; //温度百分比
extern int huminum; //湿度百分比
extern int tempcol; //温度显示颜色
extern int humicol; //湿度显示颜色

//Web网站服务器
extern ESP8266WebServer server; // 建立esp8266网站服务器对象

// //NTP服务器参数
// static const char ntpServerName[] = "ntp6.aliyun.com"; //NTP只是在NTP
// const int timeZone = 8; //东八区

//wifi连接UDP设置参数
extern WiFiUDP Udp;
extern WiFiClient wificlient;
extern unsigned int localPort;
extern float duty;

#endif // !_G_CONFIG_H