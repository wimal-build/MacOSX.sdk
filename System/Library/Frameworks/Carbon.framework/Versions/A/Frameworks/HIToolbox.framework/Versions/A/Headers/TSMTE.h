/*
     File:       HIToolbox/TSMTE.h
 
     Contains:   Text Services Managerfor TextEdit Interfaces. All Textedit functions as well all functions in
 
     Version:    HIToolbox-211~1
 
     Copyright:  � 1991-2005 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
/*****************************************************************************************************************
    
    All Textedit functions as well all functions in this file are deprecated for Mac OS 10.4. The Multilingual Text 
    Engine (MLTE) API is recommended instead. MLTE support for inline input is built-in so there is no need for an 
    API parallel to TSMTE on Mac OS X. Please see MacTextEditor.h file for a description of the MLTE API.

******************************************************************************************************************/
#ifndef __TSMTE__
#define __TSMTE__

#ifndef __TEXTEDIT__
#include <HIToolbox/TextEdit.h>
#endif

#ifndef __DIALOGS__
#include <HIToolbox/Dialogs.h>
#endif

#ifndef __TEXTSERVICES__
#include <HIToolbox/TextServices.h>
#endif




#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k

/* signature, interface types*/
enum {
  kTSMTESignature               = 'tmTE',
  kTSMTEInterfaceType           = kTSMTEDocumentInterfaceType
};

/*
    In Carbon, since DialogRef is opaque, the TSMDialogRecord is removed.
    Only one kind of TSMTE dialog remains, with extended data managed by TSMTE.
    Use kTSMTESignature for the dialog refCon, and use the accessors below,
    i.e. GetTSMTEDialogTSMTERecHandle, to get at the old TSMDialogRecord info.
*/
#if CALL_NOT_IN_CARBON
enum {
  kTSMTEDialog                  = 'tmDI'
};

#endif  /* CALL_NOT_IN_CARBON */

/* update flag for TSMTERec*/
enum {
  kTSMTEAutoScroll              = 1
};


/* callback procedure definitions*/

typedef CALLBACK_API( void , TSMTEPreUpdateProcPtr )(TEHandle textH, long refCon);
typedef CALLBACK_API( void , TSMTEPostUpdateProcPtr )(TEHandle textH, long fixLen, long inputAreaStart, long inputAreaEnd, long pinStart, long pinEnd, long refCon);
typedef STACK_UPP_TYPE(TSMTEPreUpdateProcPtr)                   TSMTEPreUpdateUPP;
typedef STACK_UPP_TYPE(TSMTEPostUpdateProcPtr)                  TSMTEPostUpdateUPP;


/* data types*/
struct TSMTERec {
  TEHandle            textH;
  TSMTEPreUpdateUPP   preUpdateProc;
  TSMTEPostUpdateUPP  postUpdateProc;
  long                updateFlag;
  long                refCon;
};
typedef struct TSMTERec                 TSMTERec;
typedef TSMTERec *                      TSMTERecPtr;
typedef TSMTERecPtr *                   TSMTERecHandle;
#if !OPAQUE_TOOLBOX_STRUCTS
struct TSMDialogRecord {
  DialogRecord        fDialog;
  TSMDocumentID       fDocID;
  TSMTERecHandle      fTSMTERecH;
  long                fTSMTERsvd[3];          /* reserved*/
};
typedef struct TSMDialogRecord          TSMDialogRecord;
typedef TSMDialogRecord *               TSMDialogPtr;
typedef TSMDialogPtr                    TSMDialogPeek;
#endif  /* !OPAQUE_TOOLBOX_STRUCTS */

/*
 *  NewTSMTEPreUpdateUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern TSMTEPreUpdateUPP
NewTSMTEPreUpdateUPP(TSMTEPreUpdateProcPtr userRoutine)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;

/*
 *  NewTSMTEPostUpdateUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern TSMTEPostUpdateUPP
NewTSMTEPostUpdateUPP(TSMTEPostUpdateProcPtr userRoutine)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;

/*
 *  DisposeTSMTEPreUpdateUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeTSMTEPreUpdateUPP(TSMTEPreUpdateUPP userUPP)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;

/*
 *  DisposeTSMTEPostUpdateUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeTSMTEPostUpdateUPP(TSMTEPostUpdateUPP userUPP)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;

/*
 *  InvokeTSMTEPreUpdateUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeTSMTEPreUpdateUPP(
  TEHandle           textH,
  long               refCon,
  TSMTEPreUpdateUPP  userUPP)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;

/*
 *  InvokeTSMTEPostUpdateUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeTSMTEPostUpdateUPP(
  TEHandle            textH,
  long                fixLen,
  long                inputAreaStart,
  long                inputAreaEnd,
  long                pinStart,
  long                pinEnd,
  long                refCon,
  TSMTEPostUpdateUPP  userUPP)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;

/*
 *  IsTSMTEDialog()   *** DEPRECATED ***
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework but deprecated in 10.4
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0.2 and later
 */
extern Boolean 
IsTSMTEDialog(DialogRef dialog)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;


/* Getters */
/*
 *  GetTSMTEDialogDocumentID()   *** DEPRECATED ***
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework but deprecated in 10.4
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0.2 and later
 */
extern TSMDocumentID 
GetTSMTEDialogDocumentID(DialogRef dialog)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;


/*
 *  GetTSMTEDialogTSMTERecHandle()   *** DEPRECATED ***
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework but deprecated in 10.4
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0.2 and later
 */
extern TSMTERecHandle 
GetTSMTEDialogTSMTERecHandle(DialogRef dialog)                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;


/* Setters */
/*
 *  SetTSMTEDialogDocumentID()   *** DEPRECATED ***
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework but deprecated in 10.4
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0.2 and later
 */
extern void 
SetTSMTEDialogDocumentID(
  DialogRef       dialog,
  TSMDocumentID   documentID)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;


/*
 *  SetTSMTEDialogTSMTERecHandle()   *** DEPRECATED ***
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework but deprecated in 10.4
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0.2 and later
 */
extern void 
SetTSMTEDialogTSMTERecHandle(
  DialogRef        dialog,
  TSMTERecHandle   tsmteRecHandle)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER_BUT_DEPRECATED_IN_MAC_OS_X_VERSION_10_4;



#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __TSMTE__ */

