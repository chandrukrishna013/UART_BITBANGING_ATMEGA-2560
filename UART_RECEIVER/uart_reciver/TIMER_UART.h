#ifndef TIMER_UART_H
#define TIMER_UART_H
#include <stdint.h>
#define OCF1A_PIN 1

extern volatile uint8_t *DDRF_reg;
extern volatile uint8_t *PORTF_reg;
extern volatile uint8_t *TCCR1A_reg;
extern volatile uint8_t *TCCR1B_reg;
extern volatile uint8_t *OCR1AL_reg;
extern volatile uint8_t *OCR1AH_reg;
extern volatile uint8_t *TCNT1L_reg;
extern volatile uint8_t *TCNT1H_reg;
extern volatile uint8_t *TIMSK1_reg;
extern volatile uint8_t *TIFR1_reg;

void delay_micro(uint8_t micro);
#endif