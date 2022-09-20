#include <U8g2lib.h>     //调用u8g2库
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ PB6, /* data=*/ PB7, /* reset=*/ U8X8_PIN_NONE);   // 使用软件IIC,SCL PB6,SDA PB7

void setup(void)
{
  Serial.begin(115200);  
  u8g2.begin();      // 初始化显示屏
}

long int t = 0;
void loop(void)
{
  u8g2.begin();               // 初始化显示屏
  u8g2.clearBuffer();         // 清屏
  u8g2.setFont(u8g2_font_ncenR12_tr); // 选择12*12字体（具体字体说明可以在git上搜索u8g2查看）
  u8g2.drawStr(0, 16, "Hello World!"); //注意这里是0,0开始显示Hello World
  u8g2.drawStr(0, 32, "Hello!"); // 注意这里是0,16开始显示Hello！
  u8g2.drawStr(0, 48, "Hi!"); // 注意这里是0,32开始显示Hello！
  u8g2.setCursor(0, 64);       // 设置打印起始地址（下面的t显示在什么地方）
  u8g2.print(t);          // 显示t
  //u8g2.drawStr(48, 64, "C"); // write something to the internal memory
  //u8g2.drawStr(112, 64, "%"); // write something to the internal memory
    
  u8g2.sendBuffer();          // 将以上所有的缓存内容显示
  Serial.println(t);       //串口输出t！
  delay(500);              //延时0.5秒
  t++;                     //为了区别,t自加1
}

