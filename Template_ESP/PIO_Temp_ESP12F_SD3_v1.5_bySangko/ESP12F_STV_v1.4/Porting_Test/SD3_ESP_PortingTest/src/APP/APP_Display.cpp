#include "APP.h"

//TFT屏幕输出函数
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
  if (y >= tft.height())
    return 0;
  tft.pushImage(x, y, w, h, bitmap);
  // Return 1 to decode next block
  return 1;
}

//进度条函数
byte loadNum = 6;
void loading(byte delayTime) //绘制进度条
{
  clk.setColorDepth(8);

  clk.createSprite(200, 100); //创建窗口
  clk.fillSprite(0x0000);     //填充率

  clk.drawRoundRect(0, 0, 200, 16, 8, 0xFFFF);     //空心圆角矩形
  clk.fillRoundRect(3, 3, loadNum, 10, 5, 0xFFFF); //实心圆角矩形
  clk.setTextDatum(CC_DATUM);                      //设置文本数据
  clk.setTextColor(TFT_GREEN, 0x0000);
  clk.drawString("Connecting to WiFi......", 100, 40, 2);
  clk.setTextColor(TFT_WHITE, 0x0000);
  clk.drawRightString(Version, 180, 60, 2);
  clk.pushSprite(20, 120); //窗口位置

  //clk.setTextDatum(CC_DATUM);
  //clk.setTextColor(TFT_WHITE, 0x0000);
  //clk.pushSprite(130,180);

  clk.deleteSprite();
  loadNum += 1;
  delay(delayTime);
}

//湿度图标显示函数
void humidityWin()
{
  clk.setColorDepth(8);

  huminum = huminum / 2;
  clk.createSprite(52, 6);                         //创建窗口
  clk.fillSprite(0x0000);                          //填充率
  clk.drawRoundRect(0, 0, 52, 6, 3, 0xFFFF);       //空心圆角矩形  起始位x,y,长度，宽度，圆弧半径，颜色
  clk.fillRoundRect(1, 1, huminum, 4, 2, humicol); //实心圆角矩形
  clk.pushSprite(45, 222);                         //窗口位置
  clk.deleteSprite();
}

//温度图标显示函数
void tempWin()
{
  clk.setColorDepth(8);

  clk.createSprite(52, 6);                         //创建窗口
  clk.fillSprite(0x0000);                          //填充率
  clk.drawRoundRect(0, 0, 52, 6, 3, 0xFFFF);       //空心圆角矩形  起始位x,y,长度，宽度，圆弧半径，颜色
  clk.fillRoundRect(1, 1, tempnum, 4, 2, tempcol); //实心圆角矩形
  clk.pushSprite(45, 192);                         //窗口位置
  clk.deleteSprite();
}


void LCD_reflash(int en)
{
  if (now() != prevDisplay || en == 1)
  {
    prevDisplay = now();
    digitalClockDisplay(en);
    prevTime = 0;
  }

  //两秒钟更新一次
  if (second() % 2 == 0 && prevTime == 0 || en == 1)
  {
#if DHT_EN
    if (DHT_img_flag != 0)
      IndoorTem();
#endif
    scrollBanner();
  }
#if imgAst_EN
  if (DHT_img_flag == 0)
    imgAnim();
#endif

  if (millis() - weaterTime > (60000 * updateweater_time) || en == 1 || UpdateWeater_en != 0)
  { //10分钟更新一次天气
    if (Wifi_en == 0)
    {
      WiFi.forceSleepWake(); //wifi on
      Serial.println("WIFI恢复......");
      Wifi_en = 1;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
      // Serial.println("WIFI已连接");
      getCityWeater();
      if (UpdateWeater_en != 0)
        UpdateWeater_en = 0;
      weaterTime = millis();
      // while(!getNtpTime());
      getNtpTime();
#if !WebSever_EN
      WiFi.forceSleepBegin(); // Wifi Off
      Serial.println("WIFI休眠......");
      Wifi_en = 0;
#endif
    }
  }
}



//天气信息写到屏幕上
String scrollText[7]; //天气信息存储
void weaterData(String *cityDZ, String *dataSK, String *dataFC)
{
  //解析第一段JSON
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, *dataSK);
  JsonObject sk = doc.as<JsonObject>();

  //TFT_eSprite clkb = TFT_eSprite(&tft);

  /***绘制相关文字***/
  clk.setColorDepth(8);
  clk.loadFont(ZdyLwFont_20);

  //温度
  clk.createSprite(58, 24);
  clk.fillSprite(bgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_WHITE, bgColor);
  clk.drawString(sk["temp"].as<String>() + "℃", 28, 13);
  clk.pushSprite(100, 184);
  clk.deleteSprite();
  tempnum = sk["temp"].as<int>();
  tempnum = tempnum + 10;
  if (tempnum < 10)
    tempcol = 0x00FF;
  else if (tempnum < 28)
    tempcol = 0x0AFF;
  else if (tempnum < 34)
    tempcol = 0x0F0F;
  else if (tempnum < 41)
    tempcol = 0xFF0F;
  else if (tempnum < 49)
    tempcol = 0xF00F;
  else
  {
    tempcol = 0xF00F;
    tempnum = 50;
  }
  tempWin();

  //湿度
  clk.createSprite(58, 24);
  clk.fillSprite(bgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_WHITE, bgColor);
  clk.drawString(sk["SD"].as<String>(), 28, 13);
  //clk.drawString("100%",28,13);
  clk.pushSprite(100, 214);
  clk.deleteSprite();
  //String A = sk["SD"].as<String>();
  huminum = atoi((sk["SD"].as<String>()).substring(0, 2).c_str());

  if (huminum > 90)
    humicol = 0x00FF;
  else if (huminum > 70)
    humicol = 0x0AFF;
  else if (huminum > 40)
    humicol = 0x0F0F;
  else if (huminum > 20)
    humicol = 0xFF0F;
  else
    humicol = 0xF00F;
  humidityWin();

  //城市名称
  clk.createSprite(94, 30);
  clk.fillSprite(bgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_WHITE, bgColor);
  clk.drawString(sk["cityname"].as<String>(), 44, 16);
  clk.pushSprite(15, 15);
  clk.deleteSprite();

  //PM2.5空气指数
  uint16_t pm25BgColor = tft.color565(156, 202, 127); //优
  String aqiTxt = "优";
  int pm25V = sk["aqi"];
  if (pm25V > 200)
  {
    pm25BgColor = tft.color565(136, 11, 32); //重度
    aqiTxt = "重度";
  }
  else if (pm25V > 150)
  {
    pm25BgColor = tft.color565(186, 55, 121); //中度
    aqiTxt = "中度";
  }
  else if (pm25V > 100)
  {
    pm25BgColor = tft.color565(242, 159, 57); //轻
    aqiTxt = "轻度";
  }
  else if (pm25V > 50)
  {
    pm25BgColor = tft.color565(247, 219, 100); //良
    aqiTxt = "良";
  }
  clk.createSprite(56, 24);
  clk.fillSprite(bgColor);
  clk.fillRoundRect(0, 0, 50, 24, 4, pm25BgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(0x0000);
  clk.drawString(aqiTxt, 25, 13);
  clk.pushSprite(104, 18);
  clk.deleteSprite();

  scrollText[0] = "实时天气 " + sk["weather"].as<String>();
  scrollText[1] = "空气质量 " + aqiTxt;
  scrollText[2] = "风向 " + sk["WD"].as<String>() + sk["WS"].as<String>();

  //scrollText[6] = atoi((sk["weathercode"].as<String>()).substring(1,3).c_str()) ;

  //天气图标
  wrat.printfweather(170, 15, atoi((sk["weathercode"].as<String>()).substring(1, 3).c_str()));

  //左上角滚动字幕
  //解析第二段JSON
  deserializeJson(doc, *cityDZ);
  JsonObject dz = doc.as<JsonObject>();
  //Serial.println(sk["ws"].as<String>());
  //横向滚动方式
  //String aa = "今日天气:" + dz["weather"].as<String>() + "，温度:最低" + dz["tempn"].as<String>() + "，最高" + dz["temp"].as<String>() + " 空气质量:" + aqiTxt + "，风向:" + dz["wd"].as<String>() + dz["ws"].as<String>();
  //scrollTextWidth = clk.textWidth(scrollText);
  //Serial.println(aa);
  scrollText[3] = "今日" + dz["weather"].as<String>();

  deserializeJson(doc, *dataFC);
  JsonObject fc = doc.as<JsonObject>();

  scrollText[4] = "最低温度" + fc["fd"].as<String>() + "℃";
  scrollText[5] = "最高温度" + fc["fc"].as<String>() + "℃";

  //Serial.println(scrollText[0]);

  clk.unloadFont();
}

int currentIndex = 0;
TFT_eSprite clkb = TFT_eSprite(&tft);

void scrollBanner()
{
  //if(millis() - prevTime > 2333) //3秒切换一次
  //  if(second()%2 ==0&& prevTime == 0)
  //  {
  if (scrollText[currentIndex])
  {
    clkb.setColorDepth(8);
    clkb.loadFont(ZdyLwFont_20);
    clkb.createSprite(150, 30);
    clkb.fillSprite(bgColor);
    clkb.setTextWrap(false);
    clkb.setTextDatum(CC_DATUM);
    clkb.setTextColor(TFT_WHITE, bgColor);
    clkb.drawString(scrollText[currentIndex], 74, 16);
    clkb.pushSprite(10, 45);

    clkb.deleteSprite();
    clkb.unloadFont();

    if (currentIndex >= 5)
      currentIndex = 0; //回第一个
    else
      currentIndex += 1; //准备切换到下一个
  }
  prevTime = 1;
  //  }
}

#if imgAst_EN
void imgAnim()
{
  int x = 160, y = 160;
  if (millis() - AprevTime > 37) //x ms切换一次
  {
    Anim++;
    AprevTime = millis();
  }
  if (Anim == 10)
    Anim = 0;

  switch (Anim)
  {
  case 0:
    TJpgDec.drawJpg(x, y, i0, sizeof(i0));
    break;
  case 1:
    TJpgDec.drawJpg(x, y, i1, sizeof(i1));
    break;
  case 2:
    TJpgDec.drawJpg(x, y, i2, sizeof(i2));
    break;
  case 3:
    TJpgDec.drawJpg(x, y, i3, sizeof(i3));
    break;
  case 4:
    TJpgDec.drawJpg(x, y, i4, sizeof(i4));
    break;
  case 5:
    TJpgDec.drawJpg(x, y, i5, sizeof(i5));
    break;
  case 6:
    TJpgDec.drawJpg(x, y, i6, sizeof(i6));
    break;
  case 7:
    TJpgDec.drawJpg(x, y, i7, sizeof(i7));
    break;
  case 8:
    TJpgDec.drawJpg(x, y, i8, sizeof(i8));
    break;
  case 9:
    TJpgDec.drawJpg(x, y, i9, sizeof(i9));
    break;
  default:
    Serial.println("显示Anim错误");
    break;
  }
}
#endif

unsigned char Hour_sign = 60;
unsigned char Minute_sign = 60;
unsigned char Second_sign = 60;
void digitalClockDisplay(int reflash_en)
{
  int timey = 82;
  if (hour() != Hour_sign || reflash_en == 1) //时钟刷新
  {
    dig.printfW3660(20, timey, hour() / 10);
    dig.printfW3660(60, timey, hour() % 10);
    Hour_sign = hour();
  }
  if (minute() != Minute_sign || reflash_en == 1) //分钟刷新
  {
    dig.printfO3660(101, timey, minute() / 10);
    dig.printfO3660(141, timey, minute() % 10);
    Minute_sign = minute();
  }
  if (second() != Second_sign || reflash_en == 1) //分钟刷新
  {
    dig.printfW1830(182, timey + 30, second() / 10);
    dig.printfW1830(202, timey + 30, second() % 10);
    Second_sign = second();
  }

  if (reflash_en == 1)
    reflash_en = 0;
  /***日期****/
  clk.setColorDepth(8);
  clk.loadFont(ZdyLwFont_20);

  //星期
  clk.createSprite(58, 30);
  clk.fillSprite(bgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_WHITE, bgColor);
  clk.drawString(week(), 29, 16);
  clk.pushSprite(102, 150);
  clk.deleteSprite();

  //月日
  clk.createSprite(95, 30);
  clk.fillSprite(bgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_WHITE, bgColor);
  clk.drawString(monthDay(), 49, 16);
  clk.pushSprite(5, 150);
  clk.deleteSprite();

  clk.unloadFont();
  /***日期****/
}

//星期
String week()
{
  String wk[7] = {"日", "一", "二", "三", "四", "五", "六"};
  String s = "周" + wk[weekday() - 1];
  return s;
}


//月日
String monthDay()
{
  String s = String(month());
  s = s + "月" + day() + "日";
  return s;
}
