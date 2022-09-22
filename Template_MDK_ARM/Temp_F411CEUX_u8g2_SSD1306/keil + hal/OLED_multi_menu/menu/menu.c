#include "menu.h"

pageIndex_TypeDef pageIndex[30]=
{
	//0
	{0,0,0,1,(*fun_0)},
	
    //1
	{1,4,2, 5,(*fun_a1)},
	{2,1,3, 9,(*fun_b1)},
	{3,2,4,13,(*fun_c1)},		
	{4,3,1, 0,(*fun_d1)},
	
    //2
	{5,8,6,17,(*fun_a21)},					
	{6,5,7,18,(*fun_a22)},
	{7,6,8,19,(*fun_a23)},						                	
	{8,7,5, 1,(*fun_a24)},
	
	{ 9,12,10,20,(*fun_b21)},					
	{10, 9,11,21,(*fun_b22)},
	{11,10,12,22,(*fun_b23)},						                	
	{12,11, 9, 2,(*fun_b24)},
	
	{13,16,14,23,(*fun_c21)},					
	{14,13,15,24,(*fun_c22)},				                	
	{15,14,16,25,(*fun_c23)},				                	
	{16,15,13, 3,(*fun_c24)},
	
    //3
	{17,17,17,5,(*fun_a31)},			                	
	{18,18,18,6,(*fun_a32)},		                	
	{19,19,19,7,(*fun_a33)},
	
	{20,20,20, 9,(*fun_b31)},				                	
	{21,21,21,10,(*fun_b32)},			                	
	{22,22,22,11,(*fun_b33)},
	
	{23,23,23,13,(*fun_c31)},			                	
	{24,24,24,14,(*fun_c32)},			                	
	{25,25,25,15,(*fun_c33)},								
};

/*********1***********/
void fun_a1()   
{	
	u8g2_DrawStr(&u8g2,0,16,">");
	u8g2_DrawStr(&u8g2,16,16,"Weather");
	u8g2_DrawStr(&u8g2,16,32,"Music");
	u8g2_DrawStr(&u8g2,16,48,"Device Info");
	u8g2_DrawStr(&u8g2,16,64,"return");																					
}

void fun_b1()   
{	
	u8g2_DrawStr(&u8g2,0,32,">");
	u8g2_DrawStr(&u8g2,16,16,"Weather");
	u8g2_DrawStr(&u8g2,16,32,"Music");
	u8g2_DrawStr(&u8g2,16,48,"Device Info");
	u8g2_DrawStr(&u8g2,16,64,"return");																						
}

void fun_c1()     
{	
	u8g2_DrawStr(&u8g2,0,48,">");
	u8g2_DrawStr(&u8g2,16,16,"Weather");
	u8g2_DrawStr(&u8g2,16,32,"Music");
	u8g2_DrawStr(&u8g2,16,48,"Device Info");
	u8g2_DrawStr(&u8g2,16,64,"return");																					
}

void fun_d1()     
{	
	u8g2_DrawStr(&u8g2,0,64,">");
	u8g2_DrawStr(&u8g2,16,16,"Weather");
	u8g2_DrawStr(&u8g2,16,32,"Music");
	u8g2_DrawStr(&u8g2,16,48,"Device Info");
	u8g2_DrawStr(&u8g2,16,64,"return");																						
}

/*********2***********/
void fun_a21()     
{	
	u8g2_DrawStr(&u8g2,0,16,">");
	u8g2_DrawStr(&u8g2,16,16,"HangZhou");
	u8g2_DrawStr(&u8g2,16,32,"BeiJing");
	u8g2_DrawStr(&u8g2,16,48,"ShangHai");
	u8g2_DrawStr(&u8g2,16,64,"return");																						
}

void fun_a22()      
{	
	u8g2_DrawStr(&u8g2,0,32,">");
	u8g2_DrawStr(&u8g2,16,16,"HangZhou");
	u8g2_DrawStr(&u8g2,16,32,"BeiJing");
	u8g2_DrawStr(&u8g2,16,48,"ShangHai");
	u8g2_DrawStr(&u8g2,16,64,"return");																							
}

void fun_a23()    
{	
	u8g2_DrawStr(&u8g2,0,48,">");
	u8g2_DrawStr(&u8g2,16,16,"HangZhou");
	u8g2_DrawStr(&u8g2,16,32,"BeiJing");
	u8g2_DrawStr(&u8g2,16,48,"ShangHai");
	u8g2_DrawStr(&u8g2,16,64,"return");																							
}

void fun_a24()    
{	
	u8g2_DrawStr(&u8g2,0,64,">");
	u8g2_DrawStr(&u8g2,16,16,"HangZhou");
	u8g2_DrawStr(&u8g2,16,32,"BeiJing");
	u8g2_DrawStr(&u8g2,16,48,"ShangHai");
	u8g2_DrawStr(&u8g2,16,64,"return");																								
}

void fun_b21()    
{	
    u8g2_DrawStr(&u8g2,0,16,">");
	u8g2_DrawStr(&u8g2,16,16,"WindyHill");
	u8g2_DrawStr(&u8g2,16,32,"New Boy");
	u8g2_DrawStr(&u8g2,16,48,"Kiss The Rain");
	u8g2_DrawStr(&u8g2,16,64,"return");																								
}

void fun_b22()    
{	
    u8g2_DrawStr(&u8g2,0,32,">");
	u8g2_DrawStr(&u8g2,16,16,"WindyHill");
	u8g2_DrawStr(&u8g2,16,32,"New Boy");
	u8g2_DrawStr(&u8g2,16,48,"Kiss The Rain");
	u8g2_DrawStr(&u8g2,16,64,"return");																							
}

void fun_b23()    
{	
    u8g2_DrawStr(&u8g2,0,48,">");
	u8g2_DrawStr(&u8g2,16,16,"WindyHill");
	u8g2_DrawStr(&u8g2,16,32,"New Boy");
	u8g2_DrawStr(&u8g2,16,48,"Kiss The Rain");
	u8g2_DrawStr(&u8g2,16,64,"return");																							
}

void fun_b24()    
{	
    u8g2_DrawStr(&u8g2,0,64,">");
	u8g2_DrawStr(&u8g2,16,16,"WindyHill");
	u8g2_DrawStr(&u8g2,16,32,"New Boy");
	u8g2_DrawStr(&u8g2,16,48,"Kiss The Rain");
	u8g2_DrawStr(&u8g2,16,64,"return");																					
}

void fun_c21()    
{	
	u8g2_DrawStr(&u8g2,0,16,">");
	u8g2_DrawStr(&u8g2,16,16,"WiFi Info");
	u8g2_DrawStr(&u8g2,16,32,"Volume");
	u8g2_DrawStr(&u8g2,16,48,"Version");
	u8g2_DrawStr(&u8g2,16,64,"return");																						
}

void fun_c22()    
{	
	u8g2_DrawStr(&u8g2,0,32,">");
	u8g2_DrawStr(&u8g2,16,16,"WiFi Info");
	u8g2_DrawStr(&u8g2,16,32,"Volume");
	u8g2_DrawStr(&u8g2,16,48,"Version");
	u8g2_DrawStr(&u8g2,16,64,"return");																						
}

void fun_c23()    
{	
	u8g2_DrawStr(&u8g2,0,48,">");
	u8g2_DrawStr(&u8g2,16,16,"WiFi Info");
	u8g2_DrawStr(&u8g2,16,32,"Volume");
	u8g2_DrawStr(&u8g2,16,48,"Version");
	u8g2_DrawStr(&u8g2,16,64,"return");																						
}

void fun_c24()    
{	
	u8g2_DrawStr(&u8g2,0,64,">");
	u8g2_DrawStr(&u8g2,16,16,"WiFi Info");
	u8g2_DrawStr(&u8g2,16,32,"Volume");
	u8g2_DrawStr(&u8g2,16,48,"Version");
	u8g2_DrawStr(&u8g2,16,64,"return");																				
}

/*********3***********/
void fun_a31()    
{	
	u8g2_DrawStr(&u8g2,0,16,"HangZhou Weather");
	u8g2_DrawStr(&u8g2,0,32,"Sunny");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																						
}

void fun_a32()    
{	
	u8g2_DrawStr(&u8g2,0,16,"BeiJing Weather");
	u8g2_DrawStr(&u8g2,0,32,"Sunny");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																					
}

void fun_a33()    
{	
	u8g2_DrawStr(&u8g2,0,16,"ShangHai Weather");
	u8g2_DrawStr(&u8g2,0,32,"Sunny");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																						
}

void fun_b31()    
{	
	u8g2_DrawStr(&u8g2,0,16,"*** Music ***");
	u8g2_DrawStr(&u8g2,0,32,"WindyHill");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																						
}

void fun_b32()    
{	
	u8g2_DrawStr(&u8g2,0,16,"*** Music ***");
	u8g2_DrawStr(&u8g2,0,32,"New Boy");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																						
}

void fun_b33()    
{	
	u8g2_DrawStr(&u8g2,0,16,"*** Music ***");
	u8g2_DrawStr(&u8g2,0,32,"Kill The Rain");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																							
}

void fun_c31()    
{	
	u8g2_DrawStr(&u8g2,0,16,"WiFI info");
	u8g2_DrawStr(&u8g2,0,32,"ssid:xxx");
	u8g2_DrawStr(&u8g2,0,48,"passwd:xxx");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																						
}

void fun_c32()    
{	
	u8g2_DrawStr(&u8g2,0,16,"Volume info");
	u8g2_DrawStr(&u8g2,0,32,"volume:xx");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																						
}

void fun_c33()    
{	
	u8g2_DrawStr(&u8g2,0,16,"Version info");
	u8g2_DrawStr(&u8g2,0,32,"version:V1.0.0");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Return");																					
}

/*********0***********/
void fun_0()
{
	u8g2_DrawStr(&u8g2,0,16,"STM32");
	u8g2_DrawStr(&u8g2,0,32,"Multi Menu Test");
	u8g2_DrawStr(&u8g2,0,48,"");
	u8g2_DrawStr(&u8g2,0,64,"Enter to Test");		
}