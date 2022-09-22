#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include "u8g2.h"

typedef struct
{
	/*
      Current: Index number of the current page; 
      Last: Index number of the Last page;
      Next: Index number of the Next page;
      ENTER: Enter the page by Index;
      Current_operation: The index number of the current page to execute the display function, 
	                     which is a function pointer;
	*/
	uint8_t current;
	uint8_t last;
	uint8_t next;
	uint8_t enter;	
	void (*current_operation)();
} pageIndex_TypeDef;


extern pageIndex_TypeDef pageIndex[30];
extern u8g2_t u8g2;
	
extern void fun_a1(); 
extern void fun_b1();  
extern void fun_c1();  
extern void fun_d1();  

extern void fun_a21(); 
extern void fun_a22();  
extern void fun_a23();  
extern void fun_a24();  

extern void fun_b21(); 
extern void fun_b22();  
extern void fun_b23();  
extern void fun_b24(); 

extern void fun_c21(); 
extern void fun_c22();  
extern void fun_c23();  
extern void fun_c24();  

extern void fun_a31(); 
extern void fun_a32();  
extern void fun_a33();  

extern void fun_b31(); 
extern void fun_b32();  
extern void fun_b33(); 

extern void fun_c31(); 
extern void fun_c32();  
extern void fun_c33(); 
  
extern void fun_0();   

#endif
