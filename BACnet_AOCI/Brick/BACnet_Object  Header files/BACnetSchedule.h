#ifndef BACNETSCHEDULE_H__
#define BACNETSCHEDULE_H__

/**   @file BACnetSchedule.h
*     @brief Header file for BACnetSchedule.c i.e. definition of Schedule Object Data Structures for Bacnet.
*     <TABLE>
*		<TR> <TD> Copyright </TD> </TR>
*     <TR>
*     <TD> AOCI, 88 Sahashra Shree, EPIP Industrial Area,
*     Whitefield, Bangalore, India Copyright (c) 2013 - All rights
*     reserved. </TD>
*     </TR>
*     <TR>
*     <TD> No part of this document may be reproduced in any
*       form without the express written consent of Schneider
*       Electric, Inc. </TD>
*     </TR>
*     </TABLE>
* 
*     @par
*     @author Lakshmana Kulala
*     @par HISTORY
*     
*     <TABLE>
*     <TR>
*     <TD>Lakshmana Kulala</TD>	<TD>12-Sep-2013</TD> <TD>Created </TD>
*		</TR>
*     </TABLE>
*/


/******************************************************************************/
/** include files **/
#include "trTypes.h"
#include "BACnetAppDefines.h"
#include "BACnetTimeStamp.h"
#include "BACnetCalender.h"


  /**
* @typedef BACnetDailySchedule
* @brief BACnetDailySchedule type Data Structure
*/
 typedef struct
 {
  TR_BACnetTimeValue timeValue[MAX_DAILY_TIME_VALUES];
 }BACnetDailySchedule;

 /**
* @typedef BACnetSpecialEvent
* @brief BACnetSpecialEvent type Data Structure
*/
typedef struct
 {
    //Uint8  periodType;  // Always have the object reference 
	Uint32 calendarReference; // Calander Object/Instance ID	
    TR_BACnetTimeValue timeValue[MAX_SPECIAL_EVENT_TIME_VALUES];
    Uint16 EventPriority;
 }BACnetSpecialEvent;

 /**
* @typedef DeviceObjectPropertyReference
* @brief DeviceObjectPropertyReference type Data Structure
*/
typedef struct
 {
	Uint32 object_id;
	Uint32 property_id;   
    Uint32 device_id; // do we need this in future ?
 }BACnetDeviceObjectPropertyReference;

/**
* @typedef BACnetSchedule
* @brief BACnet Schedule Object Data Structure
*/
typedef struct
{
   Uint32 object_id;
	Int8  object_name[MAX_STR_LEN];
	Uint8 object_type;
   Uint32 present_value;
	Int8 description[MAX_STR_LEN];
	TR_BACnetDateRange effective_period;
	BACnetDailySchedule weekly_schedule[NO_DAYS_IN_THE_WEEK];
	BACnetSpecialEvent exception_schedule[MAX_NO_OF_EXCEPTIONS_LOGGED];
	Uint32 schedule_default;
   BACnetDeviceObjectPropertyReference listofObjectPropertyReference[MAX_NO_OF_REFERENCES];
	Uint16 priority_for_writing;
	Uint8 status_flags;
	Uint8 reliability;
	BOOL out_of_service;
	int8 ProfileName[MAX_STR_LEN];
}BACnetSchedule_Flash;

typedef struct
{  
    Uint32 present_value;	
	Uint32 schedule_default;   
	Uint16 priority_for_writing;
	Uint8 status_flags;
	Uint8 reliability;
	BOOL out_of_service;
	BACnetSchedule_Flash *Schedule_Flash;
}BACnetSchedule;


#endif //BACNETSCHEDULE_H__
