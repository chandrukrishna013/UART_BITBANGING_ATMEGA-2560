#include"TIMER_UART.h"
#include <stdint.h>

volatile uint8_t *DDRF_reg   = (volatile uint8_t *)0x30;
volatile uint8_t *PORTF_reg  = (volatile uint8_t *)0x31;
volatile uint8_t *TCCR1A_reg = (volatile uint8_t *)0x80;
volatile uint8_t *TCCR1B_reg = (volatile uint8_t *)0x81;
volatile uint8_t *OCR1AL_reg = (volatile uint8_t *)0x88;
volatile uint8_t *OCR1AH_reg = (volatile uint8_t *)0x89;
volatile uint8_t *TCNT1L_reg = (volatile uint8_t *)0x84;
volatile uint8_t *TCNT1H_reg = (volatile uint8_t *)0x85;
volatile uint8_t *TIMSK1_reg = (volatile uint8_t *)0x6F;
volatile uint8_t *TIFR1_reg  = (volatile uint8_t *)0x36;

void delay_micro(uint8_t micro)
{
    int count;
    *TCCR1A_reg = 0x00;
    *TCCR1B_reg = 0x00;
    *TCCR1B_reg |= (0x01 << 3);
    *TIFR1_reg = 0x02;
    *TCNT1L_reg = 0;
    *TCNT1H_reg = 0;
    *OCR1AH_reg = 0x00;
    count = micro * 2;
    *OCR1AL_reg = count - 1;
    *TCCR1B_reg &= ~(0x07);
    *TCCR1B_reg |= (0x01 << 1);

    while (!(*TIFR1_reg & (1 << OCF1A_PIN)))
    {
    }
    *TIFR1_reg |= (1 << OCF1A_PIN);
    *TCCR1B_reg &= ~(0x07);
}