

#ifndef LEDTEST_H
#define LEDTEST_H

#define RD4	4	//PORTDbits.RD4		// LED connected to RD4
#define RD5	5	//PORTDbits.RD5		// LED connected to RD5
#define RD6	6	//PORTDbits.RD6		// LED connected to RD6
#define RD7	7	//PORTDbits.RD7		// LED connected to RD7

#define partstDEFAULT_PORT_ADDRESS		( ( unsigned portSHORT ) 0x378 )

void vLedInitialise( void );
void vTestSetLED( unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue );
void vTestToggleLED( unsigned portBASE_TYPE uxLED );

#endif

