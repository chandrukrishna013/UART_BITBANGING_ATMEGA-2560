#include <stdint.h>

#define DDRF  (*(volatile uint8_t *)0x30)
#define PORTF (*(volatile uint8_t *)0x31)

int main(void)
{
    DDRF |= (1 << 0);

    while (1)
    {
        PORTF ^= (1 << 0);

        for (volatile uint32_t i = 0; i < 500000UL; i++)
        {
        }
    }
}