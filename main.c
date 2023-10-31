/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "FX1.h"
#include "GI2C1.h"
#include "WAIT1.h"
#include "CI2C1.h"
#include "CsIO1.h"
#include "IO1.h"
#include "SM1.h"
#include "TU1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "MCUC1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */

/*library to configure GPIO*/
#include "MK64F12.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')


unsigned long delay = 300000;
void software_delay(unsigned long delay)
{
    while (delay > 0) delay--;
}

extern unsigned char write[512];
extern int len;
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
    /* Write your local variable definition here */
    /*Enable Clock Gating for PORTS A, B, C, D*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK; /*Enable Port A Clock Gate Control*/
    SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /*Enable Port B Clock Gate Control*/
    SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; /*Enable Port C Clock Gate Control*/
    SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK; /*Enable Port D Clock Gate Control*/

    /*Configure PORTS for GPIO*/
    PORTB_GPCLR = 0x00040100; /*Configure PORTB[2] for GPIO*/
    PORTC_GPCLR = 0x0FFF0100; /*Configure PORTC[11:0] for GPIO*/
    PORTD_GPCLR = 0x00FF0100; /*Configure PORTD[7:0] for GPIO*/

    PORTA_PCR1 = 0xA0100; /*Configures PORTA[1] for GPIO and to trigger interrupt on falling edge */
    PORTB_PCR10 = 0x100; /*Configure PORTB[10] for GPIO and to generate clock*/

    /*PDDR: configures direction of PORT PINS for INPUT/OUTPUT     */
    GPIOA_PDDR = (0 << 1); /*Set PORTA[1] as INPUT*/
    GPIOB_PDDR = 0x0; /*Set PORTB[2] as INPUTS*/
    GPIOB_PDDR |= (1 << 10); /*Set PORTB[10] as OUTPUT*/
    GPIOC_PDDR = 0x00; /*Set PORTC[3:0] as INPUTS*/
    GPIOD_PDDR = 0xFF; /*Set PORTD[7:0] as OUTPUTS*/

    /*Initialize PORTS*/
    GPIOD_PDOR = 0x00; /*Initialize PORT D to 0*/

    /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
    PE_low_level_init();
    /*** End of Processor Expert internal initialization.                	***/

    //PORTA_ISFR = (1 << 1); /* Clear interrupt status flag register for PORTA[1]*/
    //NVIC_EnableIRQ(INT_PORTA);

    /*Initialization to send SPI message*/
    LDD_TDeviceData *SM1_DeviceData;
    SM1_DeviceData = SM1_Init(NULL);

    /* Write your code here */

    while(1)
    {
   	 software_delay(delay);
    }


    /* For example: for(;;) { } */

    /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
	PEX_RTOS_START();              	/* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 ** 	This file was created by Processor Expert 10.4 [05.11]
 ** 	for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
