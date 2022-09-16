#include "iWatch.h"

unsigned char sensor_status;

/*传感器状态枚举*/
enum sensor_sta {
  LSM6DSM_ISPRESENTED = 0x01,
  BMP390_ISPRESENTED = 0x02,
  QMC5883L_ISPRESENTED = 0x04,
  HDC2080_ISPRESENTED = 0x08,
  HDC1080_ISPRESENTED = 0x10,
  HTU21D_ISPRESENTED = 0x20
};

void iWatchInit() 
{

   sensor_status = 0;
   
      printf("%d\r\n", sensor_status |= LSM6DSM_ISPRESENTED);




}