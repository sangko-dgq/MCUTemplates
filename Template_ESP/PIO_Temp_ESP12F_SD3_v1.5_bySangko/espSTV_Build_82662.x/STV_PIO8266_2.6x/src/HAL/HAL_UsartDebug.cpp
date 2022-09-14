#include "HAL.h"


//串口调试设置函数
void Serial_set()
{
  String incomingByte = "";
  if (Serial.available() > 0)
  {

    while (Serial.available() > 0) //监测串口缓存，当有数据输入时，循环赋值给incomingByte
    {
      incomingByte += char(Serial.read()); //读取单个字符值，转换为字符，并按顺序一个个赋值给incomingByte
      delay(2);                            //不能省略，因为读取缓冲区数据需要时间
    }
    if (SMOD == "0x01") //设置1亮度设置
    {
      int LCDBL = atoi(incomingByte.c_str()); //int n = atoi(xxx.c_str());//String转int
      if (LCDBL >= 0 && LCDBL <= 100)
      {
        EEPROM.write(BL_addr, LCDBL); //亮度地址写入亮度值
        EEPROM.commit();              //保存更改的数据
        delay(5);
        LCD_BL_PWM = EEPROM.read(BL_addr);
        delay(5);
        SMOD = "";
        Serial.printf("亮度调整为：");
        analogWrite(LCD_BL_PIN, 1023 - (LCD_BL_PWM * 10));
        Serial.println(LCD_BL_PWM);
        Serial.println("");
      }
      else
        Serial.println("亮度调整错误，请输入0-100");
    }
    if (SMOD == "0x02") //设置2地址设置
    {
      int CityCODE = 0;
      int CityC = atoi(incomingByte.c_str()); //int n = atoi(xxx.c_str());//String转int
      if (CityC >= 101000000 && CityC <= 102000000 || CityC == 0)
      {
        save_CityCode_toEEP(&CityC);
        // for(int cnum=0;cnum<5;cnum++)
        // {
        //   EEPROM.write(CC_addr+cnum,CityC%100);//城市地址写入城市代码
        //   EEPROM.commit();//保存更改的数据
        //   CityC = CityC/100;
        //   delay(5);
        // }
        update_CityCode_fromEEP(&CityC);
        // for(int cnum=5;cnum>0;cnum--)
        // {
        //   CityCODE = CityCODE*100;
        //   CityCODE += EEPROM.read(CC_addr+cnum-1);
        //   delay(5);
        // }

        cityCode = CityCODE;

        if (cityCode == "0")
        {
          Serial.println("城市代码调整为：自动");
          getCityCode(); //获取城市代码
        }
        else
        {
          Serial.printf("城市代码调整为：");
          Serial.println(cityCode);
        }
        Serial.println("");
        buildCityWeater(); //更新城市天气
        SMOD = "";
      }
      else
        Serial.println("城市调整错误，请输入9位城市代码，自动获取请输入0");
    }
    if (SMOD == "0x03") //设置3屏幕显示方向
    {
      int RoSet = atoi(incomingByte.c_str());
      if (RoSet >= 0 && RoSet <= 3)
      {
        EEPROM.write(Ro_addr, RoSet); //屏幕方向地址写入方向值
        EEPROM.commit();              //保存更改的数据
        SMOD = "";
        //设置屏幕方向后重新刷屏并显示
        tft.setRotation(RoSet);
        tft.fillScreen(0x0000);
        LCD_reflash(1); //屏幕刷新程序
        UpdateWeater_en = 1;
        TJpgDec.drawJpg(15, 183, temperature, sizeof(temperature)); //温度图标
        TJpgDec.drawJpg(15, 213, humidity, sizeof(humidity));       //湿度图标

        Serial.print("屏幕方向设置为：");
        Serial.println(RoSet);
      }
      else
      {
        Serial.println("屏幕方向值错误，请输入0-3内的值");
      }
    }
    if (SMOD == "0x04") //设置天气更新时间
    {
      int wtup = atoi(incomingByte.c_str()); //int n = atoi(xxx.c_str());//String转int
      if (wtup >= 1 && wtup <= 60)
      {
        EEPROM.write(UpWeT_addr, wtup); //亮度地址写入亮度值
        EEPROM.commit();                //保存更改的数据
        delay(5);
        updateweater_time = wtup;
        SMOD = "";
        Serial.printf("天气更新时间更改为：");
        Serial.print(updateweater_time);
        Serial.println("分钟");
      }
      else
        Serial.println("更新时间太长，请重新设置（1-60）");
    }
    else
    {
      SMOD = incomingByte;
      delay(2);
      if (SMOD == "0x01")
        Serial.println("请输入亮度值，范围0-100");
      else if (SMOD == "0x02")
        Serial.println("请输入9位城市代码，自动获取请输入0");
      else if (SMOD == "0x03")
      {
        Serial.println("请输入屏幕方向值，");
        Serial.println("0-USB接口朝下");
        Serial.println("1-USB接口朝右");
        Serial.println("2-USB接口朝上");
        Serial.println("3-USB接口朝左");
      }
      else if (SMOD == "0x04")
      {
        Serial.print("当前天气更新时间：");
        Serial.print(updateweater_time);
        Serial.println("分钟");
        Serial.println("请输入天气更新时间（1-60）分钟");
      }
      else if (SMOD == "0x05")
      {
        Serial.println("重置WiFi设置中......");
        delay(10);
        #if WM_EN
        wm.resetSettings();
        #endif
        delete_WifiConfig_inEEP();
        delay(10);
        Serial.println("重置WiFi成功");
        SMOD = "";
        ESP.restart();
      }
      else
      {
        Serial.println("");
        Serial.println("请输入需要修改的代码：");
        Serial.println("亮度设置输入        0x01");
        Serial.println("地址设置输入        0x02");
        Serial.println("屏幕方向设置输入    0x03");
        Serial.println("更改天气更新时间    0x04");
        Serial.println("重置WiFi(会重启)    0x05");
        Serial.println("");
      }
    }
  }
}

