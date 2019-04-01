#include "system_LPC11xx.h"
#include "LPC11xx.h"
#include "timer_init.h"
#include "GPIO_Initializations.h"

void TIMER16_0_IRQHandler()
{
	 //turn on the pulse 
	LPC_GPIO0->DATA &= ~(1 << 9);
	start_timer1_16bit();
}

void TIMER16_1_IRQHandler()
{
	start_timer2_32bit();
	LPC_GPIO0->DATA |= (1 << 8);
}

void TIMER32_0_IRQHandler()
{
	LPC_GPIO0->DATA &= ~(1 << 8);
}

void PIOINT0_IRQHandler()
{
	for (int i = 0; i < 1000; i++);
	LPC_GPIO0->IC = (1 << 5);
	
	LPC_GPIO0->DATA |= (1 << 9);
	start_timer0_16bit();
	
}


int main()
{
	GPIO_Init();
	init_timer1_16bit();
	init_timer0_16bit();
	init_timer2_32bit();
	LPC_GPIO0->DATA &= ~(3 << 8); // set as zero to start
	while(1)
	{
	}
}
