#include "GPIO_Initializations.h"
#include "LPC11xx.h"

void GPIO_Init()
{
	// Pulse outputs
	LPC_IOCON-> PIO0_9 &= ~(0x3); //port 1 set as output
	LPC_IOCON-> PIO0_8 &= ~(0x3); // port 2
	
	LPC_GPIO0->DIR |= (0x3 << 8); // GPIO at port 1 and 2
	
	// Interupt Initialization 
	LPC_IOCON->PIO0_6 |= ~(0x3); // port 5
	LPC_GPIO0->DIR &= ~(0x1 << 6); // 5th bit GPIO
	
	
	LPC_GPIO0->IS &= ~(1 << 6); //edge sensitive
	LPC_GPIO0->IE |= (1 << 6); //Interrupt Enable 

	LPC_GPIO0->IEV |= (1 << 6); // Interrupt active high 
	
	LPC_IOCON->PIO0_6 &= ~(0x3 << 3);
	LPC_IOCON->PIO0_6 |= (0x1 << 3); // Pull-down resistor enabled

	NVIC_EnableIRQ(EINT0_IRQn);

}
