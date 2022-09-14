## 目录结构

```
 X-Track
    ├─ArduinoAPI                -- 通用 Arduino API 抽象层
    ├─Doc                       -- 芯片相关文档
    ├─Libraries                 -- 硬件驱动程序
    │  ├─Adafruit_GFX_Library   -- Adafruit_GFX轻量级图形库
    │  ├─Adafruit_ST7789        -- ST7789屏幕驱动
    │  ├─ButtonEvent            -- 按键事件库
    │  ├─cm_backtrace           -- ARM Cortex-M 系列 MCU 错误追踪库
    │  ├─LIS3MDL                -- LIS3MDL地磁计驱动
    │  ├─LSM6DSM                -- LSM6DSM陀螺仪加速度计驱动
    │  ├─MillisTaskManager      -- 合作式任务调度器
    │  ├─SdFat                  -- 文件系统
    │  ├─StackInfo              -- 栈空间使用统计库
    │  └─TinyGPSPlus            -- NMEA协议解析器
    ├─MDK-ARM_F403A             -- AT32F403A Keil工程
    ├─MDK-ARM_F435              -- AT32F435  Keil工程
    ├─Simulator                 -- Visual Studio LVGL PC模拟器
    ├─Tools                     -- 实用工具
    └─USER                      -- 用户程序
        ├─App                   -- 应用层
        │  ├─Common             -- 通用程序
        │  │  ├─DataProc        -- 应用后台数据处理
        │  │  ├─HAL             -- 硬件抽象层定义/Mock实现
        │  │  └─Music           -- 操作音管理
        │  ├─Config             -- 应用配置文件
        │  ├─Pages              -- 页面
        │  │  ├─Dialplate       -- 表盘页面
        │  │  ├─LiveMap         -- 地图页面
        │  │  ├─Startup         -- 开机页面
        │  │  ├─StatusBar       -- 状态栏
        │  │  ├─SystemInfos     -- 系统信息页面
        │  │  └─_Template       -- 页面模板
        │  ├─Resource           -- 资源池
        │  │  ├─Font            -- 字体
        │  │  └─Image           -- 图片
        │  └─Utils              -- 通用应用层组件
        │      ├─ArduinoJson    -- JSON库
        │      ├─DataCenter     -- 消息发布订阅框架
        │      ├─Filters        -- 常用滤波算法库
        │      ├─GPX            -- GPX生成器
        │      ├─GPX_Parser     -- GPX解析器
        │      ├─lv_allocator   -- 自定义allocator
        │      ├─lv_anim_label  -- 文本动画组件
        │      ├─lv_ext         -- lvgl功能扩展
        │      ├─lv_img_png     -- PNG显示组件
        │      ├─lv_poly_line   -- 多段线控件
        │      ├─MapConv        -- WGS84/GCJ02 地图坐标转换器
        │      ├─new            -- new/delete 重载
        │      ├─PageManager    -- 页面调度器
        │      ├─PointContainer -- 坐标压缩容器
        │      ├─ResourceManager-- 资源管理器
        │      ├─StorageService -- KV储存服务
        │      ├─Stream         -- Arduino Stream 流式库
        │      ├─TileConv       -- 瓦片坐标转换器
        │      ├─Time           -- 时间转换算法库
        │      ├─TonePlayer     -- 异步方波音乐播放器
        │      ├─TrackFilter    -- 流式轨迹坐标拐点/线段提取器
        │      └─WString        -- Arduino WString 字符串库
        ├─HAL                   -- 硬件抽象层
        └─lv_port               -- lvgl与硬件的接口
```





## APP   应用层



## HAL  硬件抽象层

## 

## PORT  lvgl与硬件的接口

## 
