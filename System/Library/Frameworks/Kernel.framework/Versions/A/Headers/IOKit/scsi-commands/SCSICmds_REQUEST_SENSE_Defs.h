/*
 * Copyright (c) 1998-2001 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

// This file contains all definitions for the data returned from
// the REQUEST SENSE (0x03) command and from auto sense on protocols
// that support it.

#ifndef _IOKIT_SCSI_CMDS_REQUEST_SENSE_H_
#define _IOKIT_SCSI_CMDS_REQUEST_SENSE_H_

enum
{
	kSenseDefaultSize	= 18
};

struct SCSI_Sense_Data
{
	UInt8		VALID_RESPONSE_CODE;				// 7 = Valid. 6-0 = Response Code.
	UInt8		SEGMENT_NUMBER;						// Segment number
	UInt8		SENSE_KEY;							// 7 = FILEMARK, 6 = EOM, 5 = ILI, 3-0 = SENSE KEY.
	UInt8		INFORMATION_1;						// INFORMATION.
	UInt8		INFORMATION_2;						// INFORMATION.
	UInt8		INFORMATION_3;						// INFORMATION.
	UInt8		INFORMATION_4;						// INFORMATION.
	UInt8		ADDITIONAL_SENSE_LENGTH;			// Number of additional bytes available in sense data
	UInt8		COMMAND_SPECIFIC_INFORMATION_1;		// Command Specific Information
	UInt8		COMMAND_SPECIFIC_INFORMATION_2;		// Command Specific Information
	UInt8		COMMAND_SPECIFIC_INFORMATION_3;		// Command Specific Information
	UInt8		COMMAND_SPECIFIC_INFORMATION_4;		// Command Specific Information
	UInt8		ADDITIONAL_SENSE_CODE;				// Additional Sense Code
	UInt8		ADDITIONAL_SENSE_CODE_QUALIFIER;	// Additional Sense Code Qualifier
	UInt8		FIELD_REPLACEABLE_UNIT_CODE;		// Field Replaceable Unit Code
	UInt8		SKSV_SENSE_KEY_SPECIFIC_MSB;		// 7 = Sense Key Specific Valid bit, 6-0 Sense Key Specific MSB
	UInt8		SENSE_KEY_SPECIFIC_MID;				// Sense Key Specific Middle
	UInt8		SENSE_KEY_SPECIFIC_LSB;				// Sense Key Specific LSB
};

typedef struct SCSI_Sense_Data SCSI_Sense_Data;

// Sense Valid
enum
{
	kSENSE_DATA_VALID										= 0x80,
	kSENSE_NOT_DATA_VALID									= 0x00,
	kSENSE_DATA_VALID_Mask									= 0x80
};

// Sense Response Codes
enum
{
	kSENSE_RESPONSE_CODE_Current_Errors						= 0x70,
	kSENSE_RESPONSE_CODE_Deferred_Errors					= 0x71,
	kSENSE_RESPONSE_CODE_Mask								= 0x7F
};

// Sense FileMark Bit field definitions
enum
{
	kSENSE_FILEMARK_Set										= 0x80,
	kSENSE_FILEMARK_Not_Set 								= 0x00,
	kSENSE_FILEMARK_Mask 									= 0x80
};

// Sense End Of Medium (EOM) Bit field definitions
enum
{
	kSENSE_EOM_Set											= 0x40,
	kSENSE_EOM_Not_Set 										= 0x00,
	kSENSE_EOM_Mask 										= 0x40
};

// Sense Incorrect Length Indicator (ILI) Bit field definitions
enum
{
	kSENSE_ILI_Set											= 0x20,
	kSENSE_ILI_Not_Set 										= 0x00,
	kSENSE_ILI_Mask 										= 0x20
};

// Sense Key definitions
enum
{
	kSENSE_KEY_NO_SENSE										= 0x00,
	kSENSE_KEY_RECOVERED_ERROR								= 0x01,
	kSENSE_KEY_NOT_READY									= 0x02,
	kSENSE_KEY_MEDIUM_ERROR									= 0x03,
	kSENSE_KEY_HARDWARE_ERROR								= 0x04,
	kSENSE_KEY_ILLEGAL_REQUEST								= 0x05,
	kSENSE_KEY_UNIT_ATTENTION								= 0x06,
	kSENSE_KEY_DATA_PROTECT									= 0x07,
	kSENSE_KEY_BLANK_CHECK									= 0x08,
	kSENSE_KEY_VENDOR_SPECIFIC								= 0x09,
	kSENSE_KEY_COPY_ABORTED									= 0x0A,
	kSENSE_KEY_ABORTED_COMMAND								= 0x0B,
	/* SENSE KEY 0x0C is obsoleted */
	kSENSE_KEY_VOLUME_OVERFLOW								= 0x0D,
	kSENSE_KEY_MISCOMPARE									= 0x0E,
	/* SENSE KEY 0x0F is reserved */
	kSENSE_KEY_Mask 										= 0x0F
};


#endif	/* _IOKIT_SCSI_CMDS_REQUEST_SENSE_H_ */