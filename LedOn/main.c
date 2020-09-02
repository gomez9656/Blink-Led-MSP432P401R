#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Binary. Set P1.0 as OUTPUT
	P1DIR = 0b00000001;

	//Set P1.0 as HIGH
	P1OUT = 0b00000001; //Se inicializa el pin0 del puerto 1 en HIGH

	//MSP doesn't have a delay function. Use i variable to create a for loop
	unsigned int i;

	//Create a while loop to see the LED toggle forever
	while(1){

	    //Toggle P1.0 between HIGH or LOW using ^(XOR)
	    P1OUT = P1OUT  ^ 0b00000001;

	    //Without a delay, human eyes can't see the LED toggling.
	    for(i = 0; i < 20000; i++);
	}

}
