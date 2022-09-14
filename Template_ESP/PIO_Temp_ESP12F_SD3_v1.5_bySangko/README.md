## SD3项目问题总结

1. 从 WEB网页配网切换到微信扫码配网，需要将MCU擦除后，再上传对应的程序。

2. 程序能运行，但屏幕无法点亮，原因在于TFT_eSPI和该屏幕，在较新的ESP8266 SDK下有兼容问题。解决方法：将ESP8266 SDK版本降到2.7.4等低版本一些。

3. 解决PlatformIO移植版项目屏幕兼容问题（同第2条）

    降低Platform中esp8266-platform版本到2.x.

    步骤如下：

    - 1. 卸载版本：uninstall  esp8266-platform 

            安装2.x版本 

        ![image-20211112090421281](https://i.loli.net/2021/11/12/zV1A9CRlg8W6HLy.png)

        ![image-20211112091115202](https://i.loli.net/2021/11/12/b7HI6Jx4cMvShnz.png)

        2. 删除C:\Users\Administrator\.platformio\packages 目录下

            framework-arduinoespressif8266...开头的文件夹

    - 3. 新建一个基于NodeMCU空项目(会自动基于重新安装的ESP8266 2.x版本)
        4. 将原来的项目移植到新项目里重新编译。（因为需要使用新生成的c_cpp_pro...库包含文件）
        5. 编译上传

        

        

​         