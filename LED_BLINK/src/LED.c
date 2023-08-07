#include "LED.h"
#include "stm32f1xx.h"

void LED_init(void)
{
    // Enable clock for port C
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    // Set config register
    GPIOC->CRH |= GPIO_CRH_MODE13_0 | GPIO_CRH_MODE13_1;  // Output Mode max speed
    GPIOC->CRH &= ~(GPIO_CRH_CNF13_0 | GPIO_CRH_CNF13_1); // General purpose push-pull
}

void LED_set(void)
{
    // Set port C pin13
    GPIOC->BSRR = GPIO_BSRR_BS13;
}

void LED_reset(void)
{
    // Reset port C pin13
    GPIOC->BSRR = GPIO_BSRR_BR13;
}

void LED_toggle(void)
{
    // Toggle port C pin13
    GPIOC->ODR ^= GPIO_ODR_ODR13;
}
