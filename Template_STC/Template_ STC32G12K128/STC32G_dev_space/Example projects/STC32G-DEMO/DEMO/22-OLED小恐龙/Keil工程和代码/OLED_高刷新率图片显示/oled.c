#include <oled.h>
#include <oledfont.h>  	//取模的字库 
	
unsigned char bdata bt=0; // 可位寻址的片内ram

sbit bt0=bt^0;
sbit bt1=bt^1;
sbit bt2=bt^2;
sbit bt3=bt^3;
sbit bt4=bt^4;
sbit bt5=bt^5;
sbit bt6=bt^6;
sbit bt7=bt^7;

void delay_ms(unsigned int ms)
{                         
	unsigned int a;
	while(ms)
	{
		a=1800;
		while(a--);
		ms--;
	}
}

/*
void  delay_ms(unsigned int ms)
{
     unsigned int i;
     do{
          i = MAIN_Fosc / 6000;
          while(--i);
     }while(--ms);
}
*/
/**********************************************
//IIC Start
**********************************************/
void IIC_Start()
{
	OLED_SCLK_Set() ;
	OLED_SDIN_Set();
	OLED_SDIN_Clr();
	OLED_SCLK_Clr();
}
 
/**********************************************
//IIC Stop
**********************************************/
void IIC_Stop()
{
OLED_SCLK_Set() ;
//	OLED_SCLK_Clr();
	OLED_SDIN_Clr();
	OLED_SDIN_Set();
	
}
 
void IIC_Wait_Ack()
{
 
	//GPIOB->CRH &= 0XFFF0FFFF;	//设置PB12为上拉输入模式
	//GPIOB->CRH |= 0x00080000;
//	OLED_SDA = 1;
//	delay_us(1);
	//OLED_SCL = 1;
	//delay_us(50000);
/*	while(1)
	{
		if(!OLED_SDA)				//判断是否接收到OLED 应答信号
		{
			//GPIOB->CRH &= 0XFFF0FFFF;	//设置PB12为通用推免输出模式
			//GPIOB->CRH |= 0x00030000;
			return;
		}
	}
*/
	OLED_SCLK_Set() ;
	OLED_SCLK_Clr();
}
/**********************************************
// IIC Write byte
**********************************************/
 
void Write_IIC_Byte(unsigned char IIC_Byte)
{
	unsigned char i;
	unsigned char m,da;
	da=IIC_Byte;
	OLED_SCLK_Clr();
	for(i=0;i<8;i++)		
	{
			m=da;
		//	OLED_SCLK_Clr();
		m=m&0x80;
		if(m==0x80)
		{OLED_SDIN_Set();}
		else OLED_SDIN_Clr();
			da=da<<1;
		OLED_SCLK_Set();
		OLED_SCLK_Clr();
		}
}
/**********************************************
// IIC Write Command
**********************************************/
void Write_IIC_Command(unsigned char IIC_Command)
{
   IIC_Start();
   Write_IIC_Byte(0x78);            //Slave address,SA0=0
	IIC_Wait_Ack();	
   Write_IIC_Byte(0x00);			//write command
	IIC_Wait_Ack();	
   Write_IIC_Byte(IIC_Command); 
	IIC_Wait_Ack();	
   IIC_Stop();
}
/**********************************************
// IIC Write Data
**********************************************/
void Write_IIC_Data(unsigned char IIC_Data)
{
   IIC_Start();
   Write_IIC_Byte(0x78);			//D/C#=0; R/W#=0
	IIC_Wait_Ack();	
   Write_IIC_Byte(0x40);			//write data
	IIC_Wait_Ack();	
   Write_IIC_Byte(IIC_Data);
	IIC_Wait_Ack();	
   IIC_Stop();
}
void OLED_WR_Byte(unsigned char dat,unsigned char cmd)
{
	if(cmd)
	{
			Write_IIC_Data(dat);
	}
	else 
		{
			Write_IIC_Command(dat);	
		}
}
 
/********************************************
// fill_Picture
********************************************/
void fill_picture(unsigned char fill_Data)
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		OLED_WR_Byte(0xb0+m,0);		//page0-page1
		OLED_WR_Byte(0x00,0);		//low column start address
		OLED_WR_Byte(0x10,0);		//high column start address
		for(n=0;n<128;n++)
			{
				OLED_WR_Byte(fill_Data,1);
			}
	}
}
 
 
/***********************Delay****************************************/
/*
void Delay_50ms(unsigned int Del_50ms)
{
	unsigned int m;
	for(;Del_50ms>0;Del_50ms--)
		for(m=6245;m>0;m--);
}
*/
 /*
void Delay_1ms(unsigned int Del_1ms)
{
	unsigned char j;
	while(Del_1ms--)
	{	
		for(j=0;j<123;j++);
	}
}
 */
//坐标设置
 
void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 	
	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f),OLED_CMD); 
}   	  
//开启OLED显示    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	} //更新显示
}
void OLED_On(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(1,OLED_DATA); 
	} //更新显示
}
//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//mode:0,反白显示;1,正常显示				 
//size:选择字体 16/8
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size)
{      	
	unsigned char c=0,i=0;	
		c=chr-' ';//得到偏移后的值			
		if(x>Max_Column-1){x=0;y=y+2;}
		if(Char_Size ==16)
			{
			OLED_Set_Pos(x,y);	
			for(i=0;i<8;i++)
			OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
			}
			else {	
				OLED_Set_Pos(x,y);
				for(i=0;i<6;i++)
				OLED_WR_Byte(F6x8[c][i],OLED_DATA);
			}
}
//m^n函数
u16 oled_pow(u8 m,u8 n)
{
	u16 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//显示2个数字
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//num:数值(0~4294967295);	 		  
void OLED_ShowNum(u8 x,u8 y,u16 num,u8 len,u8 size2)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
			//	OLED_ShowChar(x+(size2/2)*t,y,' ',size2);//此句为原句，多位数据有重叠(size2 = 8 时，size/2 = 4,字符宽度为6像素，会重叠)
				if(size2 == 8) OLED_ShowChar(x+(size2/2+2)*t,y,' ',size2);//此句为修改句,消除变量长度大于1重叠问题				@布丁橘长	
				else if(size2 == 16) OLED_ShowChar(x+(size2/2)*t,y,' ',size2);//此句为修改句,消除变量长度大于1重叠问题 		@布丁橘长
				continue;
			}else enshow=1; 
		 	 
		}
	// 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2); //此句为原句，多位数据有重叠(size2 = 8 时，size/2 = 4,字符宽度为6像素，会重叠)
			if(size2 == 8) 	OLED_ShowChar(x+(size2/2+2)*t,y,temp+'0',size2);//此句为修改句,消除变量长度大于1重叠问题		 		@布丁橘长	
			else if(size2 == 16) 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2);//此句为修改句,消除变量长度大于1重叠问题		@布丁橘长
		
	}
} 
//显示一个字符串
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 Char_Size)
{
	unsigned char j=0;
	while (chr[j]!='\0')
	{		OLED_ShowChar(x,y,chr[j],Char_Size);
			x+=8;
		if(x>120){x=0;y+=2;}
			j++;
	}
}
//显示汉字
void OLED_ShowCHinese(u8 x,u8 y,u8 no)
{      			    
	u8 t,adder=0;
	OLED_Set_Pos(x,y);	
    for(t=0;t<16;t++)
		{
				OLED_WR_Byte(Hzk[2*no][t],OLED_DATA);
				adder+=1;
     }	
		OLED_Set_Pos(x,y+1);	
    for(t=0;t<16;t++)
			{	
				OLED_WR_Byte(Hzk[2*no+1][t],OLED_DATA);
				adder+=1;
      }					
}
/***********功能描述：显示BMP图片128×64,起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{ 	
 unsigned int j=0;
 unsigned char x,y;
  
  if(y1%8==0) y=y1/8;      
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {      
	    	OLED_WR_Byte(BMP[j++],OLED_DATA);	    	
	    }
	}
} 
//-----------------------------------快速刷新画图函数---------------- 
void OLED_DrawBMP_Fast(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{ 	
 unsigned int j=0;
 unsigned char x,y;
  
  if(y1%8==0) y=y1/8;      
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
		IIC_Start();
		Write_IIC_Byte(0x78);			//D/C#=0; R/W#=0
		IIC_Wait_Ack();
		Write_IIC_Byte(0x40);			//write data
		IIC_Wait_Ack();
    for(x=x0;x<x1;x++)
	   {  
			Write_IIC_Byte(BMP[j++]);	
			IIC_Wait_Ack();
		//	IIC_Stop();
	   }
		IIC_Stop();
		
	}
} 
//----------------------------更快的画图函数-----------------------
void OLED_DrawBMP_Faster(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{ 	
 unsigned int j=0;
 unsigned char x,y,*p;
	p=BMP;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
		IIC_Start();
		Write_IIC_Byte(0x78);			//D/C#=0; R/W#=0
		IIC_Wait_Ack();
		Write_IIC_Byte(0x40);			//write data
		IIC_Wait_Ack();
    for(x=x0;x<x1;x++)
	   {  
			bt = *p;
			OLED_SDIN = bt7;
			OLED_SCL = 1;
			OLED_SCL = 0;			
			OLED_SDIN = bt6;
			OLED_SCL = 1;
			OLED_SCL = 0;
			OLED_SDIN = bt5;
			OLED_SCL = 1;
			OLED_SCL = 0;
			OLED_SDIN = bt4;
			OLED_SCL = 1;
			OLED_SCL = 0;
			OLED_SDIN = bt3;
			OLED_SCL = 1;
			OLED_SCL = 0;
			OLED_SDIN = bt2;
			OLED_SCL = 1;
			OLED_SCL = 0;
			OLED_SDIN = bt1;
			OLED_SCL = 1;
			OLED_SCL = 0;
			OLED_SDIN = bt0;
			OLED_SCL = 1;
			OLED_SCL = 0;			
			p++;	
			IIC_Wait_Ack();
	   }
		IIC_Stop();
	}
} 

void BMPmove(unsigned char BMPx1,unsigned char BMPy1,unsigned char BMPx2,unsigned char BMPy2,unsigned char *BMPn,unsigned char BMPfx,unsigned int sudu)//图片循环移动函数
{//参数：图片起始列坐标， 行坐标（页），结束列坐标，结束行坐标，  图片名，  移动方向， 移动速度
	unsigned char  bmx;
	if(BMPfx == LEFT)																											//方向：左
	{
		if(bmx <= 0) bmx = 128;
		if(bmx >= 8)																												//128列范围
		{	
			OLED_DrawBMP_Faster((unsigned char)(bmx+BMPx1),BMPy1,(unsigned char)(bmx+BMPx2),BMPy2,BMPn);								//按当前坐标更新图形
			OLED_DrawBMP_Faster((unsigned char)(bmx+BMPx2),BMPy1,(unsigned char)(bmx+BMPx2+BMPx2-BMPx1),BMPy2,BMPclr);	//擦除右侧残影
			bmx -= 8;																													//左移8列像素
		}
	}
	if(BMPfx == RIGHT)																										//方向：右
	{
		if(bmx >= 128) bmx = 0;
		if(bmx <= 128)																											//128列范围
		{
			OLED_DrawBMP_Faster((unsigned char)(bmx+BMPx1),BMPy1,(unsigned char)(bmx+BMPx2),BMPy2,BMPn);								//按当前坐标更新图形
			OLED_DrawBMP_Faster((unsigned char)(bmx+BMPx1),BMPy1,(unsigned char)(bmx+BMPx2+BMPx2-BMPx1),BMPy2,BMPclr);	//擦除左侧残影
			bmx +=8;																													//右移8列像素
		}
	}	
	delay_ms(sudu*10);																										//速度10毫秒*sudu
}

//初始化SSD1306					    
void OLED_Init(void)
{ 	
	delay_ms(100);
	OLED_WR_Byte(0xAE,OLED_CMD);//--display off
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address  
	OLED_WR_Byte(0xB0,OLED_CMD);//--set page address
	OLED_WR_Byte(0x81,OLED_CMD); // contract control
	OLED_WR_Byte(0xFF,OLED_CMD);//--128   
	OLED_WR_Byte(0xA1,OLED_CMD);//set segment remap 
	OLED_WR_Byte(0xA6,OLED_CMD);//--normal / reverse
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3F,OLED_CMD);//--1/32 duty
	OLED_WR_Byte(0xC8,OLED_CMD);//Com scan direction
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset
	OLED_WR_Byte(0x00,OLED_CMD);//
	
	OLED_WR_Byte(0xD5,OLED_CMD);//set osc division
	OLED_WR_Byte(0x80,OLED_CMD);//
	
	OLED_WR_Byte(0xD8,OLED_CMD);//set area color mode off
	OLED_WR_Byte(0x05,OLED_CMD);//
	
	OLED_WR_Byte(0xD9,OLED_CMD);//Set Pre-Charge Period
	OLED_WR_Byte(0xF1,OLED_CMD);//
	
	OLED_WR_Byte(0xDA,OLED_CMD);//set com pin configuartion
	OLED_WR_Byte(0x12,OLED_CMD);//
	
	OLED_WR_Byte(0xDB,OLED_CMD);//set Vcomh
	OLED_WR_Byte(0x30,OLED_CMD);//
	
	OLED_WR_Byte(0x8D,OLED_CMD);//set charge pump enable
	OLED_WR_Byte(0x14,OLED_CMD);//
	
	OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel
}  
 