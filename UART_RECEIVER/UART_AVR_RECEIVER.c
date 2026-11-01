#include <stdint.h>
#include "TIMER_UART.h"

volatile uint8_t *PIN_A  = (volatile uint8_t *)0x20;
volatile uint8_t *DDR_F  = (volatile uint8_t *)0x30;
volatile uint8_t *PORT_F = (volatile uint8_t *)0x31;

uint8_t receive_uart(void)
{
    uint8_t data = 0;

    while (*PIN_A & (1 << 1))
    {
    }
    delay_micro(69);
    delay_micro(69);

    for (uint8_t i = 0; i < 8; i++)
    {
        if (*PIN_A & (1 << 1))
        {
            data |= (1U << i);
        }

        if (i < 7)
        {
            delay_micro(97);
        }
    }

    delay_micro(97);

    return data;
}

int main(void)
{
    *DDR_F = 0xFF;

     while(1){
    
        uint8_t data = receive_uart();
        *PORT_F = data;
     }
    
}