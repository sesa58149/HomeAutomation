#ifndef BACNET_PROFILE_DEF_H
#define BACNET_PROFILE_DEF_H
// Schneider Electric, Inc., 1 High Street, North Andover, MA 01845, USA  *

// * Copyright (c) 2009 - All rights reserved.                              
 /*============================================================================
 *
 * File:       BacNetProfileDef.h
 *
 *				These Structures define the BACnet Profile Definition
 *              for the EtherBrick
 *
 * Author:  Ron Naismith
 * Modified: Surya Nair
 * Modification Date: 27/05/2013
 * History: 30 Dec 2008 Initial Creation RNaismith
 *
*/
//
// This is the header for Host Profile to ensure that the profile is for the correct host & 
//
#include "trTypes.h"


#ifndef MAX_BACNET_STRING_LEN
#define MAX_BACNET_STRING_LEN 32
#define NO_DAYS_IN_THE_WEEK 7
#define MAX_NO_OF_EXCEPTIONS_LOGGED 16
#define MAX_NO_OF_REFERENCES 16
#endif
//
#define MAX_BACNET_CALANDER_ENTRY		10
//
//
START_STRUCT_PACK
   typedef struct
{
	Uint16  profileRevision STRUCT_ELEMENT_PACK(1);
	Uint16  minIOCVersion STRUCT_ELEMENT_PACK(1);
	Uint16  fieldbusType STRUCT_ELEMENT_PACK(1);
	Uint16  minFieldBusVersion STRUCT_ELEMENT_PACK(1);
	Uint16  hostType STRUCT_ELEMENT_PACK(1);
	Uint16  profileCRC STRUCT_ELEMENT_PACK(1);
} HOST_PROFILE_HEADER STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK 

//
// This Header provides the number of each Fieldbus object type
//
START_STRUCT_PACK 
typedef struct
{
	Uint16   numTotalParameters STRUCT_ELEMENT_PACK(1);			// Total # of Fieldbus Objects supported in this host
	Uint32   bacNetObjectsSupported STRUCT_ELEMENT_PACK(1);		// Bit Mask of Fieldbus Object types Supported
	Uint16 	numBinaryInputObjects STRUCT_ELEMENT_PACK(1);		// # of each BACnet Object Type in the current Profile
	Uint16 	numBinaryOutputObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numBinaryValudeObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numAnalogInputObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numAnalogOutputObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numAnalogValueObjects STRUCT_ELEMENT_PACK(1);	
	Uint16 	numAveragingObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numLifeSafetyZoneObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numMultiStateInputObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numMultiStateOutputObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numMultiStateValueObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numLoopObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numCalendarObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numNotificationClassObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numCommandObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numLifeSafetyPointObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numFileObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numProgramObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numScheduleObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numTrendLogObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numGroupObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numEventEnrollmentObjects STRUCT_ELEMENT_PACK(1);
	Uint16 	numDeviceObjects STRUCT_ELEMENT_PACK(1);
} BACNET_PARAMETER_HEADER STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK 

//
//  BACnet Object Structure Definitions
START_STRUCT_PACK
typedef struct
{
	Uint32 bacNetObjIdent;
	char  bacNetObjName [MAX_BACNET_STRING_LEN];
	Uint8 bacNetObjType;
} BACNET_OBJ_SPECIFIER  STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK


//
// BACnet Date Structure Definition
START_STRUCT_PACK
typedef struct
{
	byte day;
	byte month;
	Uint16 year;
}BACNET_DATE STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK

//
//  BACnet Date Range Definition
START_STRUCT_PACK
typedef struct
{
	BACNET_DATE startDate;
	BACNET_DATE endDate;
} BACNET_DATE_RANGE  STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK

//
// BACNet WeekNDay Structure Definition
START_STRUCT_PACK
typedef struct
{
	byte dayOfWeek;
	byte weekOfMonth;
	byte monthOfYear;
}BACNET_WEEKNDAY STRCUT_ELEMENT_PACK(1);
END_STRUCT_PACK

//
// BACNet CalendarEntry Structure Definition

START_STRUCT_PACK
typedef struct
{
	byte itemType;
	union item
	{
		BACNET_DATE date;
		BACNET_DATE_RANGE dateRange;
		BACNET_WEEKNDAY weekNday;
	};
}BACNET_CALENDAR_ENTRY STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK

//
//  BACnet Time Value Definition


//
//  BACnet Daily Schedule Definition
START_STRUCT_PACK
typedef struct
{
	byte BACNET_TIME[4];
	Uint32 value;
} BACNET_DAILY_SCHEDULE  STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK

//
//  BACnet Special Event Definition
START_STRUCT_PACK
typedef struct
{
	byte periodType;
	union Period
	{
		Uint32 calendarReference;
		BACNET_CALENDAR_ENTRY calendarEntry;
	}
	BACNET_TIME_VALUE[] time;
	Uint16 EventPriority;
} BACNET_SPECIAL_EVENT  STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK

//
// BACNet List_Of_Property_Reference structure definition
START_STRUCT_PACK
typedef struct
{
	uint32 objectIdentifier;
	uint32 propertyIdentifier;
	uint32 propertyArrayIndex;
	uint32 deviceIdentifier;
}BACNET_OBJECT_PROPERTY_REFERENCE STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK


//
//
//	Device Object (1 per Device) used as "Identity" for Device:  Mfg, Model #, Revision, ...
//
START_STRUCT_PACK 
typedef struct
{
	BACNET_OBJ_SPECIFIER bnObjectSpecifier;
	char vendorName[MAX_BACNET_STRING_LEN] ;
	Uint16 vendorIdentifier;
	char modelName[MAX_BACNET_STRING_LEN] ;
	char firmwareRevision[MAX_BACNET_STRING_LEN] ;
	char applicationRevision[MAX_BACNET_STRING_LEN] ;
	char location[MAX_BACNET_STRING_LEN] ;
	char description[MAX_BACNET_STRING_LEN] ;
	// Other items in Device Object(see spec. section 12.11) are needed in this Profile struct since they are not settable via Profile
} DEVICE_OBJECT STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK 

//
//	Binary Value Object (Variable # per Device) used for Binary Entities:  LEDs, buzzers, push buttons, ...
//
START_STRUCT_PACK
typedef struct
{
	BACNET_OBJ_SPECIFIER bnObjectSpecifier; // Not settable from Profile?
	Uint16 hostAddress;						// IOC Parameter Address or MB Address of Parameter
	char description [MAX_BACNET_STRING_LEN] ;
	char InactiveText[MAX_BACNET_STRING_LEN] ;
	char ActiveText[MAX_BACNET_STRING_LEN] ;
  // Copy Details from Bacnet Profile Spec
} BINARY_VALUE_OBJECT STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK

//
//	Analog Value Object (Variable # per Device) used for Analog Entities:  Temperature Sensors, ...
//
START_STRUCT_PACK 
typedef struct
{
	BACNET_OBJ_SPECIFIER bnObjectSpecifier;	// Not settable from Profile?  Instance # can be set by firmware when creating objects
	Uint16 hostAddress;						// IOC Parameter Address or MB Address of Parameter
	char description[MAX_BACNET_STRING_LEN] ;
	// Status Flags not settable from profile
	// Event state not settable from profile
	// Reliability not settable from profile
	// out-of-service not settable from profile
	// units not settable from profile
	//
	// Other items not settable from profile - Not mandatory fields
} ANALOG_VALUE_OBJECT STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK    

//
//	MultiState Value Object (Variable # per Device) used for Discrete Entities:  Registers, ...
//
START_STRUCT_PACK 
typedef struct
{
	BACNET_OBJ_SPECIFIER bnObjectSpecifier;
	Uint16 hostAddress;						// IOC Parameter Address or MB Address of Parameter
	char description[MAX_BACNET_STRING_LEN] ;
	Uint16 numberOfStates;
	// Other items not settable from Profile, handled locally
} MULTISTATE_VALUE_OBJECT STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK


//
//	Schedule Object
//
START_STRUCT_PACK 
typedef struct
{
	BACNET_OBJ_SPECIFIER bnObjectSpecifier;	// Not settable from Profile?  Instance # can be set by firmware when creating objects
	Uint32 PresentValue
	char description[MAX_BACNET_STRING_LEN];
	BACNET_DATE_RANGE EffectivePeriod;
	BACNET_DAILY_SCHEDULE WeeklySchedule[NO_DAYS_IN_THE_WEEK];
	BACNET_SPECIAL_EVENT ExceptionSchedule[MAX_NO_OF_EXCEPTIONS_LOGGED];
	Uint32 ScheduleDefault;
	BACNET_OBJECT_PROPERTY_REFERENCE []listofObjectPropertyReference;
	Uint16 PriorityForWriting;
	Uint8 StatusFlags;
	Uint8 Reliability;
	bool OutOfService;
	int8 ProfileName[MAX_BACNET_STRING_LEN];	
} SCHEDULE_OBJECT STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK  

//
//	Calendar Object
//
START_STRUCT_PACK 
typedef struct
{
	BACNET_OBJ_SPECIFIER bnObjectSpecifier;	// Not settable from Profile?  Instance # can be set by firmware when creating objects
	char description[MAX_BACNET_STRING_LEN];
	Uint32 PresentValue
	BACNET_CALENDAR_ENTRY DateList[MAX_BACNET_CALANDER_ENTRY];
	int8 ProfileName[MAX_BACNET_STRING_LEN] ;	
} CALENDAR_OBJECT STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK  

//
//	Notification Class Object (Fixed # per Device) used to generate Network Events of COS, COV, ...
//  Note: May not be necessary in profile since programmed via network (by BMS)
//
START_STRUCT_PACK 
typedef struct
{
	BACNET_OBJ_SPECIFIER bnObjectSpecifier;
	// Maybe no profile entry needed for Notification Object since they are configured via network (BMS)
	
} NOTIFICATION_CLASS_OBJECT STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK
//
// Data Structure for Complete Profile
//
START_STRUCT_PACK 
typedef struct
{
	HOST_PROFILE_HEADER			hostParamHeader STRUCT_ELEMENT_PACK(1);				// Host Profile Header
	BACNET_PARAMETER_HEADER		bacNetParamHeader STRUCT_ELEMENT_PACK(1);			// Fieldbus Parameter Header
	DEVICE_OBJECT				   deviceObject STRUCT_ELEMENT_PACK(1);
	BINARY_VALUE_OBJECT			binaryValueObject[] STRUCT_ELEMENT_PACK(1);			// Array of BV Objects
	ANALOG_VALUE_OBJECT			analogValueObject[] STRUCT_ELEMENT_PACK(1);			// Array of AV Objects
	MULTISTATE_VALUE_OBJECT		multiStateValueObject[] STRUCT_ELEMENT_PACK(1);		// Array of MSVObjects
	SCHEDULE_OBJECT				scheduleObject[] STRUCT_ELEMENT_PACK(1);			// Array of ScheduleObjects
	CALENDAR_OBJECT				calendarObject[] STRUCT_ELEMENT_PACK(1);			// Array of CalendarObjects
  //	NOTIFICATION_CLASS_OBJECT	notificationClassObject[] STRUCT_ELEMENT_PACK(1);	//Array of Notification Class Obj
} BACNET_HOST_PROFILE STRUCT_ELEMENT_PACK(1);
END_STRUCT_PACK 
	

 #endif
   