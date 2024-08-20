#include <stdio.h>

#define GPIO_OUT_REG 0x3FF44004
#define GPIO_OUT_ENABLE 0x3FF44020
#define LED_PIN 2 //pin no: to which built in led of esp32 is connected to

void delay_ms(unsigned int ms)
{

	while(ms--)
	{
	for(int count=0;count<24000;count++)
		__asm__ volatile ("nop");//assembly code for giving a free cpu cycle to create a delay - NO OPERATION
	}
}	

void app_main(void)
{

	volatile uint32_t* gpio_out = (volatile uint32_t*)GPIO_OUT_REG;
	volatile uint32_t* gpio_enable = (volatile uint32_t*)GPIO_OUT_ENABLE;

	*gpio_enable |= (1<<LED_PIN);//enables LED pin as output
	
	while(1)
	{

		*gpio_out ^= (1<<LED_PIN);//toggles led pin high and low using XOR operation
		delay_ms(1000);//gives delay of 1 second
	}
}
