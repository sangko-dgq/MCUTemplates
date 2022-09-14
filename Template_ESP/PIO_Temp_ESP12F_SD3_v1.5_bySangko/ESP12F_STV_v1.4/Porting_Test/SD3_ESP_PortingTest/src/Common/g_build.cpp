/***********************************
 *           
 *          @file 变量池 
 *       
 * *******************************/

#include "g_config.h"

#if WM_EN
#include "../lib/WiFiManager/WiFiManager.h"
//WiFiManager 参数
WiFiManager wm; // global wm instance
// WiFiManagerParameter custom_field; // global param ( for non blocking w params )
#endif


config_type wificonf = {{""}, {""}};



#if DHT_EN
#include "../lib/DHT_sensor_library/DHT.h"
DHT dht(DHTPIN, DHTTYPE);
#endif

#if imgAst_EN
int Anim = 0;      //太空人图标显示指针记录
int AprevTime = 0; //太空人更新时间记录
#endif

int updateweater_time = 10;    //天气更新时间  X 分钟
int LCD_Rotation = 0;          //LCD屏幕方向
int LCD_BL_PWM = 50;           //屏幕亮度0-100，默认50
String cityCode = "101250101"; //天气城市代码 长沙:101250101株洲:101250301衡阳:101250401

//LCD屏幕相关设置
TFT_eSPI tft = TFT_eSPI(); // 引脚请自行配置tft_espi库中的 User_Setup.h文件
TFT_eSprite clk = TFT_eSprite(&tft);
uint16_t bgColor = 0x0000;

//其余状态标志位
uint8_t Wifi_en = 1;         //wifi状态标志位  1：打开    0：关闭
uint8_t UpdateWeater_en = 0; //更新时间标志位
int prevTime = 0;            //滚动显示更新标志位
int DHT_img_flag = 0;        //DHT传感器使用标志位

time_t prevDisplay = 0;       //显示时间显示记录
unsigned long weaterTime = 0; //天气更新时间记录
String SMOD = "";             //串口数据存储

/*** Component objects ***/
Number dig;
WeatherNum wrat;

uint32_t targetTime = 0;

int tempnum = 0;      //温度百分比
int huminum = 0;      //湿度百分比
int tempcol = 0xffff; //温度显示颜色
int humicol = 0xffff; //湿度显示颜色

//Web网站服务器
ESP8266WebServer server(80); // 建立esp8266网站服务器对象

//wifi连接UDP设置参数
WiFiUDP Udp;
WiFiClient wificlient;
unsigned int localPort = 8000;
float duty = 0;
