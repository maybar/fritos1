

/* Scheduler includes. */
#include "FreeRTOS.h"

/* Demo app includes. */
#include "LedTest.h"

#define ptOUTPUT 	0
#define ptALL_OFF	0



unsigned portBASE_TYPE uxOutput;

/*-----------------------------------------------------------
 * Simple  port IO routines.
 *-----------------------------------------------------------*/

void vLedInitialise( void )
{
	/* The DSPICDEM has LED's on port D.  All bits are set as output
	so PORTD is read-modified-written directly.  Two pins have change 
	notification pullups that need disabling. */
	//CNPU2bits.CN22PUE = 0;
	//CNPU2bits.CN23PUE = 0;
	TRISD = ptOUTPUT;
	PORTD = ptALL_OFF;
	uxOutput = ptALL_OFF;
}
/*-----------------------------------------------------------*/

void vTestSetLED( unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue )
{
unsigned portBASE_TYPE uxLEDBit;

	/* Which port D bit is being modified? */
	uxLEDBit = 1 << uxLED;

	if( xValue )
	{
		/* Turn the LED on. */
		portENTER_CRITICAL();
		{
			uxOutput |= uxLEDBit;
			PORTD = uxOutput;
		}
		portEXIT_CRITICAL();
	}
	else
	{
		/* Turn the LED off. */
		portENTER_CRITICAL();
		{
			uxOutput &= ~uxLEDBit;
			PORTD = uxOutput;
		}
		portEXIT_CRITICAL();
	}
}
/*-----------------------------------------------------------*/

void vTestToggleLED( unsigned portBASE_TYPE uxLED )
{
unsigned portBASE_TYPE uxLEDBit;


	uxLEDBit = 1 << uxLED;
	portENTER_CRITICAL();
	{
		/* If the LED is already on - turn it off.  If the LED is already
		off, turn it on. */
		if( uxOutput & uxLEDBit )
		{
			uxOutput &= ~uxLEDBit;
			PORTD = uxOutput;
		}
		else
		{
			uxOutput |= uxLEDBit;
			PORTD = uxOutput;
		}
	}
	portEXIT_CRITICAL();
}

