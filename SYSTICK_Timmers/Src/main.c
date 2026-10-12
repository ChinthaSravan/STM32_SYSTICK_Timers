
#include <stdint.h>
#include <stdio.h>
#include "stm32f407xx.h"
uint32_t tick=0;
void Delay_ms( uint32_t n ){


	while(n != tick){

	}
	tick=0;

}
void Systick_init()
{
	SysTick->CTRL = (7);
	SysTick->CTRL |= SysTick_CTRL_COUNTFLAG_Msk;
	SysTick->LOAD = (16000-1);

}

int main(void){



	RCC->AHB1ENR |=RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODE15_0;
	Systick_init();
while(1){
	GPIOD->ODR |= GPIO_ODR_OD15;
	printf("LED ON.\n");
	Delay_ms(1000);
	GPIOD->ODR &= ~ (GPIO_ODR_OD15);
	printf("LED OFF.\n");
	Delay_ms(1000);
}

    /* Loop forever */
	for(;;);
}

void SysTick_Handler(void){

	tick+=1;
}
