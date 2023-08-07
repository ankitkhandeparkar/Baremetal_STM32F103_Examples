#include "LED.h"
#include "stm32f1xx.h"

int main(void)
{
    LED_init();

    while (1)
    {
        LED_set();
        for (volatile int i = 0; i < 100000; i++)
            ;
        LED_reset();
        for (volatile int i = 0; i < 100000; i++)
            ;
    }

    return 0;
}