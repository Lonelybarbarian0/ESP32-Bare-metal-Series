#include <stdio.h>

#define GPIO_OUT_REG 0x3FF44004 //controlles the output of any 0-31 GPIO
#define GPIO_OUT_ENABLE 0x3FF44020 //Enbales any 1-31 GPIO as Output
#define GPIO_IN_REG 0x3FF4403C //helps to read the i/p of 1-31 GPIO
#define IO_MUX_GPIO5_REG 0x3FF4906C //helps to configure certain settings for GPIO
#define LED_PIN 2
#define BUTTON_PIN 5

void delay_ms(unsigned int ms);//function to create a delay
			       
void app_main(void)
{

volatile uint32_t* gpio_out = (volatile uint32_t*)GPIO_OUT_REG;
volatile uint32_t* gpio_out_en = (volatile uint32_t*)GPIO_OUT_ENABLE;
volatile uint32_t* gpio_in = (volatile uint32_t*)GPIO_IN_REG;
volatile uint32_t* gpio5 = (volatile uint32_t*)IO_MUX_GPIO5_REG;

*gpio_out_en |= (1<<LED_PIN);//enabled led pin as output

*gpio5 |= (1<<3);//sets 3rd bit high thereby activating pull up resistor to GPIO 5

	while(1)
	{
		if(!(*gpio_in & (1<<BUTTON_PIN)))//checks whether i/p becomes low or button is pressed
		{
			*gpio_out |= (1<<LED_PIN);//turns led on
			delay_ms(1000);//delay
		}
		else
		{
			*gpio_out &= ~(1<<LED_PIN);//turns of led
		}
	}


}

void delay_ms(unsigned int ms)
{
	while(ms--)
	{
		for(int i=0;i<18000;i++)
			__asm__ volatile ("nop");
	}
}
