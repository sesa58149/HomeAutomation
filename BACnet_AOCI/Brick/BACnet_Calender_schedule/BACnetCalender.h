#ifndef BACNETCALENDER_H__
#define BACNETCALENDER_H__

/**   @file BACnetCalender.h
*     @brief Header file for BACnetCalender.c i.e. definition of Schedule Object Data Structures for Bacnet.
*     <TABLE>
*     <TR> <TD> Copyright </TD> </TR>
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


/**
* @typedef BACnetWeekNday
* @brief BACnet week and Day type Data Structure
*/
 typedef struct
 {
	Int8 day_of_week;
	Int8 week_of_month;
	Int8 month_of_year;
 }BACnetWeekNday;

 /**
* @typedef BACnetCalenderEntryType
* @brief BACnet Calender entry type enum
*/
 typedef enum
 {
    BACNET_CALENDER_ENTRY_DATE=0,
    BACNET_CALENDER_ENTRY_DATE_RANGE,
    BACNET_CALENDER_ENTRY_WEEK_N_DAY,
    BACNET_CALENDER_ENTRY_INVALID = 0xFF
 }BACnetCalenderEntryType;

/**
* @typedef BACnetCalenderEntry
* @brief BACnet Calender Entry type Data Structure
*/
 typedef struct
 {
   BACnetCalenderEntryType type;
   union Entry {
    TR_BACnetDate date;
    TR_BACnetDateRange dateRange;
    BACnetWeekNday  weekNday;
    };
 }BACnetCalenderEntry;

/**
* @typedef BACnetCalender
* @brief BACnet Calender Object Data Structure
*/
 typedef struct
 {
   Uint32 object_id;
   Int8  object_name[MAX_STR_LEN];
   Uint32 object_type; // 32 bit
   BOOL present_value; // 1 byte 
   BACnetCalenderEntry date_list[MAX_BACNET_CALANDER_ENTRY];
 Int8 ProfileName[MAX_STR_LEN];
 }BACnetCalender_Flash;

 /**
* @typedef BACnetCalender
* @brief BACnet Calender Object Data Structure
*/
 typedef struct
 {   
   BOOL present_value; 
   BACnetCalenderEntry *date_list;
  // BACnetCalender_Flash	*Calander_Flash;
 }BACnetCalender;

#endif //BACNETCALENDER_H__
