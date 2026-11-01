#include<stdint.h>     
#include"TIMER_UART.h"
 volatile uint8_t * DDR_A=(volatile uint8_t*)0X21;
 volatile uint8_t * PORT_A=(volatile uint8_t*)0X22;
 void start_transmission(void)
 {
    uint8_t data=0b01010110;
    *PORT_A &=~(1<<0);
    delay_micro(98);
    for(int i=0;i<=7;i++)
    {
        if(data&(1<<i))
        {
            *PORT_A|=(1<<0);
            
        }
        else
        {
            *PORT_A &=~(1<<0);
           
        }
         delay_micro(98);
    }
    
            *PORT_A|=(1<<0);
            delay_micro(98);

 }

 int main()
 {   
  
    *DDR_A|=(1<<0);
     
  
    while(1)
    {
     *PORT_A|=(1<<0); 
     start_transmission();
    *PORT_A|=(1<<0);
    delay_micro(98);

    }

 
 }

