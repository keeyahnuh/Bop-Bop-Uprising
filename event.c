/* ###################################################################
** 	Filename	: Events.c
** 	Project 	: SPI
** 	Processor   : MK64FN1M0VLL12
** 	Component   : Events
** 	Version 	: Driver 01.00
** 	Compiler	: GNU C Compiler
** 	Date/Time   : 2022-11-19, 17:28, # CodeGen: 0
** 	Abstract	:
**     	This is user's event module.
**     	Put your event handler code here.
** 	Contents	:
**     	Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**     	This is user's event module.
**     	Put your event handler code here.
*/    	 
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/    	 
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
** 	Event   	:  Cpu_OnNMI (module Events)
**
** 	Component   :  Cpu [MK64FN1M0LL12]
*/
/*!
** 	@brief
**     	This event is called when the Non maskable interrupt had
**     	occurred. This event is automatically enabled when the [NMI
**     	interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
** 	Event   	:  SM1_OnBlockSent (module Events)
**
** 	Component   :  SM1 [SPIMaster_LDD]
*/
/*!
** 	@brief
**     	This event is called after the last character from the
**     	output buffer is moved to the transmitter. This event is
**     	available only if the SendBlock method is enabled.
** 	@param
**     	UserDataPtr 	- Pointer to the user or
**                       	RTOS specific data. The pointer is passed
**                       	as the parameter of Init method.
*/
/* ===================================================================*/
void SM1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
** 	Event   	:  SM1_OnBlockReceived (module Events)
**
** 	Component   :  SM1 [SPIMaster_LDD]
*/
/*!
** 	@brief
**     	This event is called when the requested number of data is
**     	moved to the input buffer. This method is available only if
**     	the ReceiveBlock method is enabled.
** 	@param
**     	UserDataPtr 	- Pointer to the user or
**                       	RTOS specific data. The pointer is passed
**                       	as the parameter of Init method.
*/
/* ===================================================================*/
void SM1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}


/*
** ===================================================================
** 	Event   	:  TI1_OnInterrupt (module Events)
**
** 	Component   :  TI1 [TimerInt]
** 	Description :
**     	When a timer interrupt occurs this event is called (only
**     	when the component is enabled - <Enable> and the events are
**     	enabled - <EnableEvent>). This event is enabled only if a
**     	<interrupt service/event> is enabled.
** 	Parameters  : None
** 	Returns 	: Nothing
** ===================================================================
*/

unsigned char write[512];
int len;
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
    /*Initialization to send SPI message*/


   	 LDD_TDeviceData *SM1_DeviceData;
   	 SM1_DeviceData = SM1_Init(NULL);

   	 unsigned short LEFT = ~GPIOC_PDIR & 0x08;
   	 unsigned short UP = ~GPIOC_PDIR & 0x04;
   	 unsigned short DOWN = ~GPIOC_PDIR & 0x02;
   	 unsigned short RIGHT = ~GPIOC_PDIR & 0x01;

   	 unsigned short START = ~GPIOB_PDIR & 0x04;

   	 unsigned short LED_OUTPUT = 0x00;
   	 unsigned short SEND_MESSAGE = 0x00;

   	 //printf("Hello Arduino! \n");
   	 //len = sprintf(write, "Hello Arduino! Sending from K64F\n");
   	 //SM1_SendBlock(SM1_DeviceData, &write, len);

   	 if (LEFT == 0x08) {
   		 LED_OUTPUT |= 0x80;
   		 SEND_MESSAGE |= 0x80;
   	 }
   	 else {
   		 LED_OUTPUT &= ~(0x80);
   		 SEND_MESSAGE &= ~(0x80);
   	 }

   	 if (UP == 0x04) {
   		 LED_OUTPUT |= 0x40;
   		 SEND_MESSAGE |= 0x40;

   	 }
   	 else {
   		 LED_OUTPUT &= ~(0x40);
   		 SEND_MESSAGE &= ~(0x40);
   	 }

   	 if (DOWN == 0x02) {
   		 LED_OUTPUT |= 0x02;
   		 SEND_MESSAGE |= 0x20;

   	 }
   	 else {
   		 LED_OUTPUT &= ~(0x02);
   		 SEND_MESSAGE &= ~(0x20);
   	 }

   	 if (RIGHT == 0x01) {
   		 LED_OUTPUT |= 0x10;
   		 SEND_MESSAGE |= 0x10;

   	 }
   	 else {
   		 LED_OUTPUT &= ~(0x10);
   		 SEND_MESSAGE &= ~(0x10);
   	 }

   	 if (START == 0x04) {
   		 LED_OUTPUT |= 0x01;
   		 SEND_MESSAGE |= 0x08;

   	 }
   	 else {
   		 LED_OUTPUT &= ~(0x01);
   		 SEND_MESSAGE &= ~(0x08);
   	 }

   	 //printf("SEND MESSAGE\n");
   	 len = sprintf(write, ""BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(SEND_MESSAGE));
   	 SM1_SendBlock(SM1_DeviceData, &write, len);



   	 //PORT D OUTPUT
   	 GPIOD_PDOR = LED_OUTPUT;


   	 //PORTA_ISFR = (1 << 1); /* Clear ISFR*/

}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif
