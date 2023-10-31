/* ###################################################################
** 	Filename	: Events.h
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
** @file Events.h
** @version 01.00
** @brief
**     	This is user's event module.
**     	Put your event handler code here.
*/    	 
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/    	 

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Pins1.h"
#include "FX1.h"
#include "GI2C1.h"
#include "WAIT1.h"
#include "MCUC1.h"
#include "CI2C1.h"
#include "CsIO1.h"
#include "IO1.h"
#include "SM1.h"
#include "TU1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"

#ifdef __cplusplus
extern "C" {
#endif

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
void Cpu_OnNMI(void);


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
void SM1_OnBlockSent(LDD_TUserData *UserDataPtr);

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
void SM1_OnBlockReceived(LDD_TUserData *UserDataPtr);

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
void TI1_OnInterrupt(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __Events_H*/
/*!
** @}
*/
/
