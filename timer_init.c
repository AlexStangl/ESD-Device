#include "timer_init.h"
#include "LPC11xx.h"

void init_timer0_16bit()
{
	// Enable clocking to 16 bit timer 0
	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 7);
	
	// Set to timer mode
	LPC_TMR16B0->CTCR = 0;
	
	// Set prescale to 47 so with 48MHz clock, 1 tick is equal to 1us
	// Timer speed effectively slowed to 1MHz
	LPC_TMR16B0->PR = 47;
	LPC_TMR16B0->PC = 47;
	
	// MR3 will be used for the interrupt with 1ms pulses
	LPC_TMR16B0->MR3 = 1000;
	
	// Interrupt and stop after 1ms
	LPC_TMR16B0->MCR |= (0x5 << 9);
	
	// Enable the interrupt in the NVIC and set its priority to the lowest priority
	NVIC_EnableIRQ(TIMER_16_0_IRQn);
	NVIC_SetPriority(TIMER_16_0_IRQn, 3);
	
	// Reset counter and keep stopped
	LPC_TMR16B0->TCR = 0x2;
}

/**********************************************************************************/

void start_timer0_16bit()
{
	// Reset and reenable the timer
	LPC_TMR16B0->TCR = 0x2;
	LPC_TMR16B0->TCR = 0x1;
}

/**********************************************************************************/

void init_timer1_16bit()
{
	// Enable clocking to 16 bit timer 1
	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 8);
	
	// Set to timer mode
	LPC_TMR16B1->CTCR = 0;
	
	// Set prescale to 47 so with 48MHz clock, 1 tick is equal to 1us
	// Timer speed effectively slowed to 1MHz
	LPC_TMR16B1->PR = 47;
	LPC_TMR16B1->PC = 47;
	
	// MR3 will be used for the interrupt with 1ms pulses
	LPC_TMR16B1->MR3 = 1000;
	
	// Interrupt and stop after 1ms
	LPC_TMR16B1->MCR |= (0x5 << 9);
	
	// Enable the interrupt in the NVIC and set its priority to the lowest priority
	NVIC_EnableIRQ(TIMER_16_1_IRQn);
	NVIC_SetPriority(TIMER_16_1_IRQn, 3);
	
	// Reset counter and keep stopped
	LPC_TMR16B1->TCR = 0x2;
}

/**********************************************************************************/

void start_timer1_16bit()
{
	// Reset and reenable the timer
	LPC_TMR16B1->TCR = 0x2;
	LPC_TMR16B1->TCR = 0x1;
}
