#ifndef __BACNETTIMESTAMP_H__
#define __BACNETTIMESTAMP_H__
/**
 *	@file BACnetTimeStamp.h
 *	<TABLE>
 *	@brief Header file for BACnet time interface
 *
 *	@copy
 *	<TABLE>
 *	<TR><TD> Copyright </TD></TR>
 *	<TR>
 *	<TD>Schneider Electric India (Pvt) Ltd.                                         
 *	Copyright (c) 2009 - All rights reserved.                                   
 *	</TR>
 *	<TR>                                                                             
 *	<TD> No part of this document may be reproduced in any form without the express  
 * 	written consent of Schneider Electric India (Pvt) Ltd.</TD>
 *	</TR>
 *	</TABLE>
 *
 *	@par
 *	@author Shrikant and Chetan	 
 *	@par HISTORY
 *
 *	<TABLE>
 *	<TR>
 *	<TD>Author</TD>				<TD>Date</TD>			<TD>Description</TD>
 *	</TR>
 *	<TR>
 *	<TD>Shrikant and Chetan	</TD>		<TD>02-Nov-2009</TD>	<TD>First creation</TD>
 *  </TR>
 *	</TABLE>
 *	</TABLE>
 *
 */

#include "trTypes.h"


#define BACNET_DAYS_OF_WEEK_MONDAY	1
#define BACNET_DAYS_OF_WEEK_TUESDAY	2
#define BACNET_DAYS_OF_WEEK_WEDNESDAY	4
#define BACNET_DAYS_OF_WEEK_THURSDAY	8
#define BACNET_DAYS_OF_WEEK_FRIDAY	16
#define BACNET_DAYS_OF_WEEK_SATURDAY	32
#define BACNET_DAYS_OF_WEEK_SUNDAY	64

/**  @struct TR_BACnetTime
 *   @brief Time structure 
 */
typedef struct {
	Uint8	hour;		/**< 0..23 */
	Uint8	padding1;
	Uint8	minute;		/**< 0..59 */
	Uint8	padding2;
	Uint8	second;		/**< 0..59 */
	Uint8	padding3;
	Uint8	hundredths;	/**< 0..99 */
	Uint8	padding4;
} TR_BACnetTime;


    /**
* @typedef BACnetTimeValue
* @brief BACnetTimeValue type Data Structure
*/
 typedef struct
 {
    TR_BACnetTime time;
    Uint32 value;
 }TR_BACnetTimeValue;

/**  @struct TR_BACnetDate 
 *   @brief Date structure
 */
typedef struct {
	Uint16 year;		/**< Year 2XXX  */  		
	Uint8	month;		/**< 1..12, 1=Jan */			
	Uint8	padding2;
	Uint8	day;		/**< 1..31 */			
	Uint8	padding3;
	Uint8	dow;		/**< 1..7, 1=Monday, 7=Sunday */		
	Uint8	padding4;
} TR_BACnetDate;

 /**
* @typedef DateRange
* @brief DateRange type Data Structure
*/
typedef struct
 {
    TR_BACnetDate startDate;
    TR_BACnetDate endDate;
 }TR_BACnetDateRange;


/**  @struct TR_BACnetDateTime 
 *   @brief  date and time structure            
 */
typedef struct
{
	TR_BACnetDate date;
	TR_BACnetTime time;
}TR_BACnetDateTime;



/**  @struct TR_BACnetTimeStamp 
 *   @brief BACNet time stamp structure             
 */
typedef struct
{
	Uint16 timestampType; /**< (0 -Time, 1- Sequence, 2- DataTime) */
	Uint16 sequence;      /**< Used only if  "timestampType = 1" */ 
	TR_BACnetTime time;   /**< used if   "timestampType = 0 and 2" */ 
	TR_BACnetDate date;   /**< used if   "timestampType =  2" */  
}TR_BACnetTimeStamp;

/* Structures without padding use for Local vraible calculation*/
typedef struct {
	Uint8	hour;		/**< 0..23 */
	Uint8	minute;		/**< 0..59 */
	Uint8	second;		/**< 0..59 */
	Uint8	hundredths;	/**< 0..99 */
} TR_BACnetTime_No_Pad;

/**  @struct TR_BACnetDate
 *   @brief Date structure
 */
typedef struct {
	Uint16 year;		/**< Year 2XXX  */  		
	Uint8	month;		/**< 1..12, 1=Jan */
	Uint8	day;		/**< 1..31 */			
	Uint8	dow;		/**< 1..7, 1=Monday, 7=Sunday */
} TR_BACnetDate_No_Pad;

/**  @struct TR_BACnetDateTime 
 *   @brief  date and time structure            
 */
typedef struct
{
	TR_BACnetDate_No_Pad date;
	TR_BACnetTime_No_Pad time;
}TR_BACnetDateTime_No_Pad;

/**  @struct TR_BACnetTimeStamp 
 *   @brief BACNet time stamp structure             
 */
typedef struct
{
	Uint16 timestampType; /**< (0 -Time, 1- Sequence, 2- DataTime) */
	Uint16 sequence;      /**< Used only if  "timestampType = 1" */ 
	TR_BACnetTime_No_Pad time;   /**< used if   "timestampType = 0 and 2" */
	TR_BACnetDate_No_Pad date;   /**< used if   "timestampType =  2" */
}TR_BACnetTimeStamp_No_Pad;

typedef enum
{
	TR_TIME_STAMP_TYPE_TIME = 0,
	TR_TIME_STAMP_TYPE_SEQUENCE,
	TR_TIME_STAMP_TYPE_DATE_TIME
}TR_BACnetTimeStampType;


#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif /* __cplusplus */
	Sint16 BACnetInitDateAndTime(void);
	Sint16 BACnetReadDateTime(TR_BACnetDateTime *dateAndTime );
	Sint16 BACnetReadDateTimeInSeconds(Uint32 *timeStampSeconds );
	Sint16 BACnetUpdateDateTime(TR_BACnetDateTime *dateAndTime);
	void BACnetConvertFromSecondsSince01( Uint32 seconds, TR_BACnetDateTime  * dateAndTime);
	Uint32 BACnetConvertToSecondsSince01( TR_BACnetDateTime  * dateAndTime);
	Sint16 BACnetGetTimeStamp(TR_BACnetTimeStamp  * time);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif //__BACNETTIMESTAMP_H__