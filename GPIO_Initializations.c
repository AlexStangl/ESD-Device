#include "GPIO_Initializations.h"
#include "LPC11xx.h"

void GPIO_Init()
{
	// Pulse outputs
	LPC_IOCON-> PIO0_9 &= ~(0x1); //port 1
	LPC_IOCON-> PIO0_8 &= ~(0x1); // port 2
	
	LPC_GPIO0->DIR |= 0x300; // GPIO at port 1 and 2
	
	// Interupt Initialization 
	LPC_IOCON->PIO0_5 &= ~(0x1); // port 5
	LPC_GPIO0->DIR |=  (1 << 5); // 5th bit GPIO
	
	
	LPC_GPIO0->IS |= (0); //edge sensitive
	LPC_GPIO0->IE |= (1 << 5); //Interupt Enable 

	LPC_GPIO0->IEV &= (1 << 5); // Interupt active high 

	NVIC_EnableIRQ(EINT0_IRQn);

}
