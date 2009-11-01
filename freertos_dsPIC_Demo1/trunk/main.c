#include <p33FJ128GP708.h>

/* Standard includes. */
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "croutine.h"

/* Demo application includes. */
#include "BlockQ.h"
#include "LedTest.h"

/* Demo task priorities. */
#define mainBLOCK_Q_PRIORITY				( tskIDLE_PRIORITY + 2 )

#define mainDELAY_LOOP_COUNT	65535

/*
 * Setup the processor ready for the demo.
 */
static void prvSetupHardware( void );

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

// Configuration bit settings
_FOSCSEL(FNOSC_PRIPLL);
_FOSC(FCKSM_CSDCMD & OSCIOFNC_ON & POSCMD_XT);
_FWDT(FWDTEN_OFF);
_FPOR(FPWRT_PWR128);

#define FCY  7372800


int main(void)
{
 CLKDIV = 0x0000;			// Divide clock = 1
 PLLFBD = 0x0002;			// PLL feedback = N+2 i.e. PLLX4
unsigned int Led[4]={4,65534,5,30000};
/* Configure any hardware required for this demo. */
	prvSetupHardware();
/* Create the standard demo tasks. */
	//vStartBlockingQueueTasks( mainBLOCK_Q_PRIORITY );	


	
	xTaskCreate(vTask1,(signed portCHAR *)"Task1",105,&Led[0],2,NULL);
	//Led2=5;
	xTaskCreate(vTask1,(signed portCHAR *)"Task2",105,&Led[2],2,NULL);
	//xTaskCreate(vTask1,(signed portCHAR *)"Task2",1000,NULL,2,NULL);
	
/* Finally start the scheduler. */
	vTaskStartScheduler();
	
/* Will only reach here if there is insufficient heap available to start
	the scheduler. */
	return 0;
}
	
/*-----------------------------------------------------------*/

static void prvSetupHardware( void )
{
	vLedInitialise();
}

/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* Schedule the co-routines from within the idle task hook. */
	vCoRoutineSchedule();
}
/*-----------------------------------------------------------*/	
/*
crflah.c
comtest.c
*/

void vTask1(void *pvParameters)
{
	unsigned int *Led;
	volatile unsigned long u1;
	//fprintf(stdout, "Inicia Task1");
	Led = (int*)pvParameters;
	while(1)
	{
		//printf("Toggle led RD4");
		vTestToggleLED(*Led);
		for(u1=0; u1 <*(Led+1);u1++)
		{}
	}
		
}
void vTask2(void *pvParameters)
{
//	int *Led;
	volatile unsigned long u1;
	//Led = (int*)pvParameters;
	//printf("Inicia Task2");
	while(1)
	{
		//printf("Toggle led RD6");
		vTestToggleLED(RD6);
		for(u1=0; u1 <mainDELAY_LOOP_COUNT;u1++)
		{}
	}
		
}
		