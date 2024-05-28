/*
     File:       HIToolbox/Controls.h
 
     Contains:   Control Manager interfaces
 
     Version:    HIToolbox-124.14~1
 
     Copyright:  © 1985-2002 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __CONTROLS__
#define __CONTROLS__

#ifndef __APPLICATIONSERVICES__
#include <ApplicationServices/ApplicationServices.h>
#endif

#ifndef __ICONS__
#include <HIServices/Icons.h>
#endif

#ifndef __HIOBJECT__
#include <HIToolbox/HIObject.h>
#endif

#ifndef __MENUS__
#include <HIToolbox/Menus.h>
#endif

#ifndef __TEXTEDIT__
#include <HIToolbox/TextEdit.h>
#endif

#ifndef __DRAG__
#include <HIToolbox/Drag.h>
#endif




#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Resource Types                                                                                    */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  kControlDefProcType           = 'CDEF',
  kControlTemplateResourceType  = 'CNTL',
  kControlColorTableResourceType = 'cctb',
  kControlDefProcResourceType   = 'CDEF'
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Format of a ΤCNTLΥ resource                                                                       */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlTemplate {
  Rect                controlRect;
  SInt16              controlValue;
  Boolean             controlVisible;
  UInt8               fill;
  SInt16              controlMaximum;
  SInt16              controlMinimum;
  SInt16              controlDefProcID;
  SInt32              controlReference;
  Str255              controlTitle;
};
typedef struct ControlTemplate          ControlTemplate;
typedef ControlTemplate *               ControlTemplatePtr;
typedef ControlTemplatePtr *            ControlTemplateHandle;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ ControlRef                                                                                        */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
#if !OPAQUE_TOOLBOX_STRUCTS
typedef struct ControlRecord            ControlRecord;
typedef ControlRecord *                 ControlPtr;
typedef ControlPtr *                    ControlRef;
#else
typedef struct OpaqueControlRef*        ControlRef;
#endif  /* !OPAQUE_TOOLBOX_STRUCTS */

/* ControlHandle is obsolete. Use ControlRef.*/
typedef ControlRef                      ControlHandle;
typedef SInt16                          ControlPartCode;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* ₯ Control ActionProcPtr                                                                              */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
typedef CALLBACK_API( void , ControlActionProcPtr )(ControlRef theControl, ControlPartCode partCode);
typedef STACK_UPP_TYPE(ControlActionProcPtr)                    ControlActionUPP;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ ControlRecord                                                                                     */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
#if !OPAQUE_TOOLBOX_STRUCTS
struct ControlRecord {
  ControlRef          nextControl;            /* in Carbon use embedding heirarchy functions*/
  WindowRef           contrlOwner;            /* in Carbon use GetControlOwner or EmbedControl*/
  Rect                contrlRect;             /* in Carbon use Get/SetControlBounds*/
  UInt8               contrlVis;              /* in Carbon use IsControlVisible, SetControlVisibility*/
  UInt8               contrlHilite;           /* in Carbon use GetControlHilite, HiliteControl*/
  SInt16              contrlValue;            /* in Carbon use Get/SetControlValue, Get/SetControl32BitValue*/
  SInt16              contrlMin;              /* in Carbon use Get/SetControlMinimum, Get/SetControl32BitMinimum*/
  SInt16              contrlMax;              /* in Carbon use Get/SetControlMaximum, Get/SetControl32BitMaximum*/
  Handle              contrlDefProc;          /* not supported in Carbon*/
  Handle              contrlData;             /* in Carbon use Get/SetControlDataHandle*/
  ControlActionUPP    contrlAction;           /* in Carbon use Get/SetControlAction*/
  SInt32              contrlRfCon;            /* in Carbon use Get/SetControlReference*/
  Str255              contrlTitle;            /* in Carbon use Get/SetControlTitle*/
};

#endif  /* !OPAQUE_TOOLBOX_STRUCTS */

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* ₯ Control ActionProcPtr : Epilogue                                                                   */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  NewControlActionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ControlActionUPP
NewControlActionUPP(ControlActionProcPtr userRoutine)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeControlActionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeControlActionUPP(ControlActionUPP userUPP)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeControlActionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeControlActionUPP(
  ControlRef        theControl,
  ControlPartCode   partCode,
  ControlActionUPP  userUPP)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Color Table                                                                               */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  cFrameColor                   = 0,
  cBodyColor                    = 1,
  cTextColor                    = 2,
  cThumbColor                   = 3,
  kNumberCtlCTabEntries         = 4
};

struct CtlCTab {
  SInt32              ccSeed;
  SInt16              ccRider;
  SInt16              ctSize;
  ColorSpec           ctTable[4];
};
typedef struct CtlCTab                  CtlCTab;
typedef CtlCTab *                       CCTabPtr;
typedef CCTabPtr *                      CCTabHandle;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Auxiliary Control Record                                                                          */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
#if !OPAQUE_TOOLBOX_STRUCTS
struct AuxCtlRec {
  Handle              acNext;                 /* not supported in Carbon*/
  ControlRef          acOwner;                /* not supported in Carbon*/
  CCTabHandle         acCTable;               /* not supported in Carbon*/
  SInt16              acFlags;                /* not supported in Carbon*/
  SInt32              acReserved;             /* not supported in Carbon*/
  SInt32              acRefCon;               /* in Carbon use Get/SetControlProperty if you need more refCons*/
};
typedef struct AuxCtlRec                AuxCtlRec;
typedef AuxCtlRec *                     AuxCtlPtr;
typedef AuxCtlPtr *                     AuxCtlHandle;
#endif  /* !OPAQUE_TOOLBOX_STRUCTS */

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Variants                                                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
typedef SInt16                          ControlVariant;
enum {
  kControlNoVariant             = 0,    /* No variant*/
  kControlUsesOwningWindowsFontVariant = 1 << 3 /* Control uses owning windows font to display text*/
};


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Part Codes                                                                */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* Basic part codes */
enum {
  kControlNoPart                = 0,
  kControlIndicatorPart         = 129,
  kControlDisabledPart          = 254,
  kControlInactivePart          = 255
};

/* Use this constant in Get/SetControlData when the data referred to is not         */
/* specific to a part, but rather the entire control, e.g. the list handle of a     */
/* list box control.                                                                */
enum {
  kControlEntireControl         = 0
};

/*  Meta-Parts                                                                          */
/*                                                                                      */
/*  If you haven't guessed from looking at other toolbox headers. We like the word      */
/*  'meta'. It's cool. So here's one more for you. A meta-part is a part used in a call */
/*  to the GetControlRegion API. These parts are parts that might be defined by a       */
/*  control, but should not be returned from calls like TestControl, et al. They define */
/*  a region of a control, presently the structure and the content region. The content  */
/*  region is only defined by controls that can embed other controls. It is the area    */
/*  that embedded content can live.                                                     */
/*                                                                                      */
/*  Along with these parts, you can also pass in normal part codes to get the regions   */
/*  of the parts. Not all controls fully support this at the time this was written.     */
enum {
  kControlStructureMetaPart     = -1,
  kControlContentMetaPart       = -2
};

/* focusing part codes */
enum {
  kControlFocusNoPart           = 0,    /* tells control to clear its focus*/
  kControlFocusNextPart         = -1,   /* tells control to focus on the next part*/
  kControlFocusPrevPart         = -2    /* tells control to focus on the previous part*/
};

typedef SInt16                          ControlFocusPart;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Collection Tags                                                                           */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  These are standard tags that you will find in the initial data Collection that is passed in the     */
/*  'param' parameter to the initCntl message (Carbon only).                                            */
/*                                                                                                      */
/*  All tags at ID zero in a Control's Collection are reserved for Control Manager use.                 */
/*  Custom control definitions should use other IDs.                                                    */
/*                                                                                                      */
/*  Most of these tags are interpreted when you call CreateCustomControl; the Control Manager will      */
/*  put value in the right place before calling the Control Definition with the initialization message. */
enum {
  kControlCollectionTagBounds   = 'boun', /* Rect - the bounding rectangle*/
  kControlCollectionTagValue    = 'valu', /* SInt32 - the value*/
  kControlCollectionTagMinimum  = 'min ', /* SInt32 - the minimum*/
  kControlCollectionTagMaximum  = 'max ', /* SInt32 - the maximum*/
  kControlCollectionTagViewSize = 'view', /* SInt32 - the view size*/
  kControlCollectionTagVisibility = 'visi', /* Boolean - the visible state*/
  kControlCollectionTagRefCon   = 'refc', /* SInt32 - the refCon*/
  kControlCollectionTagTitle    = 'titl', /* arbitrarily sized character array - the title*/
  kControlCollectionTagUnicodeTitle = 'uttl', /* bytes as received via CFStringCreateExternalRepresentation*/
  kControlCollectionTagIDSignature = 'idsi', /* OSType - the ControlID signature*/
  kControlCollectionTagIDID     = 'idid', /* SInt32 - the ControlID id*/
  kControlCollectionTagCommand  = 'cmd ', /* UInt32 - the command*/
  kControlCollectionTagVarCode  = 'varc' /* SInt16 - the variant*/
};

/*  The following are additional tags which are only interpreted by UnflattenControl. */
enum {
  kControlCollectionTagSubControls = 'subc' /* data for all of a control's subcontrols*/
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Image Content                                                                             */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  kControlContentTextOnly       = 0,
  kControlNoContent             = 0,
  kControlContentIconSuiteRes   = 1,
  kControlContentCIconRes       = 2,
  kControlContentPictRes        = 3,
  kControlContentICONRes        = 4,
  kControlContentIconSuiteHandle = 129,
  kControlContentCIconHandle    = 130,
  kControlContentPictHandle     = 131,
  kControlContentIconRef        = 132,
  kControlContentICON           = 133
};

typedef SInt16                          ControlContentType;
struct ControlButtonContentInfo {
  ControlContentType  contentType;
  union {
    SInt16              resID;
    CIconHandle         cIconHandle;
    Handle              iconSuite;
    IconRef             iconRef;
    PicHandle           picture;
    Handle              ICONHandle;
  }                       u;
};
typedef struct ControlButtonContentInfo ControlButtonContentInfo;
typedef ControlButtonContentInfo *      ControlButtonContentInfoPtr;
typedef ControlButtonContentInfo        ControlImageContentInfo;
typedef ControlButtonContentInfo *      ControlImageContentInfoPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Key Script Behavior                                                                       */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  kControlKeyScriptBehaviorAllowAnyScript = 'any ', /* leaves the current keyboard alone and allows user to change the keyboard.*/
  kControlKeyScriptBehaviorPrefersRoman = 'prmn', /* switches the keyboard to roman, but allows them to change it as desired.*/
  kControlKeyScriptBehaviorRequiresRoman = 'rrmn' /* switches the keyboard to roman and prevents the user from changing it.*/
};

typedef UInt32                          ControlKeyScriptBehavior;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Font Style                                                                                */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*    SPECIAL FONT USAGE NOTES: You can specify the font to use for many control types.
    The constants below are meta-font numbers which you can use to set a particular
    control's font usage. There are essentially two modes you can use: 1) default,
    which is essentially the same as it always has been, i.e. it uses the system font, unless
    directed to use the window font via a control variant. 2) you can specify to use
    the big or small system font in a generic manner. The Big system font is the font
    used in menus, etc. Chicago has filled that role for some time now. Small system
    font is currently Geneva 10. The meta-font number implies the size and style.

    NOTE:       Not all font attributes are used by all controls. Most, in fact, ignore
                the fore and back color (Static Text is the only one that does, for
                backwards compatibility). Also size, face, and addFontSize are ignored
                when using the meta-font numbering.
*/
/* Meta-font numbering - see note above */
enum {
  kControlFontBigSystemFont     = -1,   /* force to big system font*/
  kControlFontSmallSystemFont   = -2,   /* force to small system font*/
  kControlFontSmallBoldSystemFont = -3, /* force to small bold system font*/
  kControlFontViewSystemFont    = -4    /* force to views system font (DataBrowser control only)*/
};

/* Add these masks together to set the flags field of a ControlFontStyleRec */
/* They specify which fields to apply to the text. It is important to make  */
/* sure that you specify only the fields that you wish to set.              */
enum {
  kControlUseFontMask           = 0x0001,
  kControlUseFaceMask           = 0x0002,
  kControlUseSizeMask           = 0x0004,
  kControlUseForeColorMask      = 0x0008,
  kControlUseBackColorMask      = 0x0010,
  kControlUseModeMask           = 0x0020,
  kControlUseJustMask           = 0x0040,
  kControlUseAllMask            = 0x00FF,
  kControlAddFontSizeMask       = 0x0100
};

/* AddToMetaFont indicates that we want to start with a standard system     */
/* font, but then we'd like to add the other attributes. Normally, the meta */
/* font ignores all other flags                                             */
enum {
  kControlAddToMetaFontMask     = 0x0200 /* Available in Appearance 1.1 or later*/
};

/* UseThemeFontID indicates that the font field of the ControlFontStyleRec  */
/* should be interpreted as a ThemeFontID (see Appearance.h). In all other  */
/* ways, specifying a ThemeFontID is just like using one of the control     */
/* meta-fonts IDs.                                                          */
enum {
  kControlUseThemeFontIDMask    = 0x0080 /* Available in Mac OS X or later*/
};

struct ControlFontStyleRec {
  SInt16              flags;
  SInt16              font;
  SInt16              size;
  SInt16              style;
  SInt16              mode;
  SInt16              just;
  RGBColor            foreColor;
  RGBColor            backColor;
};
typedef struct ControlFontStyleRec      ControlFontStyleRec;
typedef ControlFontStyleRec *           ControlFontStylePtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Click Activation Results                                                                          */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  These are for use with GetControlClickActivation. The enumerated values should be pretty            */
/*  self-explanatory, but just in case:                                                                 */
/*  ₯ Activate/DoNotActivate indicates whether or not to change the owning window's z-ordering before   */
/*      processing the click. If activation is requested, you may also want to immediately redraw the   */
/*      newly exposed portion of the window.                                                            */
/*  ₯ Ignore/Handle Click indicates whether or not to call an appropriate click handling API (like      */
/*      HandleControlClick) in respose to the event.                                                    */
enum {
  kDoNotActivateAndIgnoreClick  = 0,    /* probably never used. here for completeness.*/
  kDoNotActivateAndHandleClick  = 1,    /* let the control handle the click while the window is still in the background.*/
  kActivateAndIgnoreClick       = 2,    /* control doesn't want to respond directly to the click, but window should still be brought forward.*/
  kActivateAndHandleClick       = 3     /* control wants to respond to the click, but only after the window has been activated.*/
};

typedef UInt32                          ClickActivationResult;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Common data tags for Get/SetControlData                                                           */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/

/*
 *  Discussion:
 *    Get/SetControlData Common Tags
 */
enum {
  kControlFontStyleTag          = 'font',
  kControlKeyFilterTag          = 'fltr',

  /*
   * Sent with a pointer to a ControlKind record to be filled in.  Only
   * valid for GetControlData.
   */
  kControlKindTag               = 'kind',

  /*
   * Sent with a pointer to a ControlSize.  Only valid with explicitly
   * sizeable controls.  Currently supported by the Check Box, Combo
   * Box, Progress Bar, Indeterminate Progress Bar, Radio Button, Round
   * Button, Scroll Bar, Slider and the Tab.  Check your return value!
   */
  kControlSizeTag               = 'size'
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Feature Bits                                                                              */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
                                        /* Control feature bits - returned by GetControlFeatures */
  kControlSupportsGhosting      = 1 << 0,
  kControlSupportsEmbedding     = 1 << 1,
  kControlSupportsFocus         = 1 << 2,
  kControlWantsIdle             = 1 << 3,
  kControlWantsActivate         = 1 << 4,
  kControlHandlesTracking       = 1 << 5,
  kControlSupportsDataAccess    = 1 << 6,
  kControlHasSpecialBackground  = 1 << 7,
  kControlGetsFocusOnClick      = 1 << 8,
  kControlSupportsCalcBestRect  = 1 << 9,
  kControlSupportsLiveFeedback  = 1 << 10,
  kControlHasRadioBehavior      = 1 << 11, /* Available in Appearance 1.0.1 or later*/
  kControlSupportsDragAndDrop   = 1 << 12, /* Available in Carbon*/
  kControlAutoToggles           = 1 << 14, /* Available in Appearance 1.1 or later*/
  kControlSupportsGetRegion     = 1 << 17, /* Available in Appearance 1.1 or later*/
  kControlSupportsFlattening    = 1 << 19, /* Available in Carbon*/
  kControlSupportsSetCursor     = 1 << 20, /* Available in Carbon*/
  kControlSupportsContextualMenus = 1 << 21, /* Available in Carbon*/
  kControlSupportsClickActivation = 1 << 22, /* Available in Carbon*/
  kControlIdlesWithTimer        = 1 << 23 /* Available in Carbon - this bit indicates that the control animates automatically*/
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Messages                                                                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  drawCntl                      = 0,
  testCntl                      = 1,
  calcCRgns                     = 2,
  initCntl                      = 3,    /* Param is Collection, result is OSStatus*/
  dispCntl                      = 4,
  posCntl                       = 5,
  thumbCntl                     = 6,
  dragCntl                      = 7,
  autoTrack                     = 8,
  calcCntlRgn                   = 10,
  calcThumbRgn                  = 11,
  drawThumbOutline              = 12,
  kControlMsgDrawGhost          = 13,
  kControlMsgCalcBestRect       = 14,   /* Calculate best fitting rectangle for control*/
  kControlMsgHandleTracking     = 15,
  kControlMsgFocus              = 16,   /* param indicates action.*/
  kControlMsgKeyDown            = 17,
  kControlMsgIdle               = 18,
  kControlMsgGetFeatures        = 19,
  kControlMsgSetData            = 20,
  kControlMsgGetData            = 21,
  kControlMsgActivate           = 22,
  kControlMsgSetUpBackground    = 23,
  kControlMsgCalcValueFromPos   = 26,
  kControlMsgTestNewMsgSupport  = 27,   /* See if this control supports new messaging*/
  kControlMsgSubValueChanged    = 25,   /* Available in Appearance 1.0.1 or later*/
  kControlMsgSubControlAdded    = 28,   /* Available in Appearance 1.0.1 or later*/
  kControlMsgSubControlRemoved  = 29,   /* Available in Appearance 1.0.1 or later*/
  kControlMsgApplyTextColor     = 30,   /* Available in Appearance 1.1 or later*/
  kControlMsgGetRegion          = 31,   /* Available in Appearance 1.1 or later*/
  kControlMsgFlatten            = 32,   /* Available in Carbon. Param is Collection.*/
  kControlMsgSetCursor          = 33,   /* Available in Carbon. Param is ControlSetCursorRec*/
  kControlMsgDragEnter          = 38,   /* Available in Carbon. Param is DragRef, result is boolean indicating acceptibility of drag.*/
  kControlMsgDragLeave          = 39,   /* Available in Carbon. As above.*/
  kControlMsgDragWithin         = 40,   /* Available in Carbon. As above.*/
  kControlMsgDragReceive        = 41,   /* Available in Carbon. Param is DragRef, result is OSStatus indicating success/failure.*/
  kControlMsgDisplayDebugInfo   = 46,   /* Available in Carbon on X.*/
  kControlMsgContextualMenuClick = 47,  /* Available in Carbon. Param is ControlContextualMenuClickRec*/
  kControlMsgGetClickActivation = 48    /* Available in Carbon. Param is ControlClickActivationRec*/
};

typedef SInt16                          ControlDefProcMessage;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Sizes                                                                     */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/

/*
 *  Discussion:
 *    ControlSize values to be used in conjunction with SetControlData
 *    and the kControlSizeTag.
 */
enum {

  /*
   * Use the control's default drawing variant.  This does not apply to
   * Scroll Bars, for which Normal is Large.
   */
  kControlSizeNormal            = 0,

  /*
   * Use the control's small drawing variant.  Currently supported by
   * the Check Box, Combo Box, Radio Button, Scroll Bar, Slider and Tab
   * controls.
   */
  kControlSizeSmall             = 1,

  /*
   * Use the control's small drawing variant.  Currently supported by
   * the Indeterminate Progress Bar, Progress Bar and Round Button
   * controls.
   */
  kControlSizeLarge             = 2,

  /*
   * Control drawing variant determined by the control's bounds.  This
   * ControlSize is only available with Scroll Bars to support their
   * legacy behavior of drawing differently within different bounds.
   */
  kControlSizeAuto              = 0xFFFF
};

typedef UInt16                          ControlSize;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Constants for drawCntl message (passed in param)                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  kDrawControlEntireControl     = 0,
  kDrawControlIndicatorOnly     = 129
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Constants for dragCntl message (passed in param)                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  kDragControlEntireControl     = 0,
  kDragControlIndicator         = 1
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Drag Constraint Structure for thumbCntl message (passed in param)                 */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct IndicatorDragConstraint {
  Rect                limitRect;
  Rect                slopRect;
  DragConstraint      axis;
};
typedef struct IndicatorDragConstraint  IndicatorDragConstraint;
typedef IndicatorDragConstraint *       IndicatorDragConstraintPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  CDEF should return as result of kControlMsgTestNewMsgSupport                        */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  kControlSupportsNewMessages   = ' ok '
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  This structure is passed into a CDEF when called with the kControlMsgHandleTracking */
/*  message                                                                             */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlTrackingRec {
  Point               startPt;
  EventModifiers      modifiers;
  ControlActionUPP    action;
};
typedef struct ControlTrackingRec       ControlTrackingRec;
typedef ControlTrackingRec *            ControlTrackingPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when called with the kControlMsgKeyDown message */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlKeyDownRec {
  EventModifiers      modifiers;
  SInt16              keyCode;
  SInt16              charCode;
};
typedef struct ControlKeyDownRec        ControlKeyDownRec;
typedef ControlKeyDownRec *             ControlKeyDownPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when called with the kControlMsgGetData or      */
/* kControlMsgSetData message                                                           */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlDataAccessRec {
  ResType             tag;
  ResType             part;
  Size                size;
  Ptr                 dataPtr;
};
typedef struct ControlDataAccessRec     ControlDataAccessRec;
typedef ControlDataAccessRec *          ControlDataAccessPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when called with the kControlCalcBestRect msg   */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlCalcSizeRec {
  SInt16              height;
  SInt16              width;
  SInt16              baseLine;
};
typedef struct ControlCalcSizeRec       ControlCalcSizeRec;
typedef ControlCalcSizeRec *            ControlCalcSizePtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when called with the kControlMsgSetUpBackground */
/* message is sent                                                                      */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlBackgroundRec {
  SInt16              depth;
  Boolean             colorDevice;
};
typedef struct ControlBackgroundRec     ControlBackgroundRec;
typedef ControlBackgroundRec *          ControlBackgroundPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when called with the kControlMsgApplyTextColor  */
/* message is sent                                                                      */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlApplyTextColorRec {
  SInt16              depth;
  Boolean             colorDevice;
  Boolean             active;
};
typedef struct ControlApplyTextColorRec ControlApplyTextColorRec;
typedef ControlApplyTextColorRec *      ControlApplyTextColorPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when called with the kControlMsgGetRegion       */
/* message is sent                                                                      */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlGetRegionRec {
  RgnHandle           region;
  ControlPartCode     part;
};
typedef struct ControlGetRegionRec      ControlGetRegionRec;
typedef ControlGetRegionRec *           ControlGetRegionPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when the kControlMsgSetCursor message is sent   */
/* Only sent on Carbon                                                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlSetCursorRec {
  Point               localPoint;
  EventModifiers      modifiers;
  Boolean             cursorWasSet;           /* your CDEF must set this to true if you set the cursor, or false otherwise*/
};
typedef struct ControlSetCursorRec      ControlSetCursorRec;
typedef ControlSetCursorRec *           ControlSetCursorPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when the kControlMsgContextualMenuClick message */
/* is sent                                                                              */
/* Only sent on Carbon                                                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlContextualMenuClickRec {
  Point               localPoint;
  Boolean             menuDisplayed;          /* your CDEF must set this to true if you displayed a menu, or false otherwise*/
};
typedef struct ControlContextualMenuClickRec ControlContextualMenuClickRec;
typedef ControlContextualMenuClickRec * ControlContextualMenuClickPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* This structure is passed into a CDEF when the kControlMsgGetClickActivation message  */
/* is sent                                                                              */
/* Only sent on Carbon                                                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlClickActivationRec {
  Point               localPoint;
  EventModifiers      modifiers;
  ClickActivationResult  result;              /* your CDEF must pass the desired result back*/
};
typedef struct ControlClickActivationRec ControlClickActivationRec;
typedef ControlClickActivationRec *     ControlClickActivationPtr;
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ ΤCDEFΥ entrypoint                                                                 */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
typedef CALLBACK_API( SInt32 , ControlDefProcPtr )(SInt16 varCode, ControlRef theControl, ControlDefProcMessage message, SInt32 param);
typedef STACK_UPP_TYPE(ControlDefProcPtr)                       ControlDefUPP;
/*
 *  NewControlDefUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ControlDefUPP
NewControlDefUPP(ControlDefProcPtr userRoutine)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeControlDefUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeControlDefUPP(ControlDefUPP userUPP)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeControlDefUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SInt32
InvokeControlDefUPP(
  SInt16                 varCode,
  ControlRef             theControl,
  ControlDefProcMessage  message,
  SInt32                 param,
  ControlDefUPP          userUPP)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  Control Key Filter                                                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* Certain controls can have a keyfilter attached to them.                              */
/* Definition of a key filter for intercepting and possibly changing keystrokes         */
/* which are destined for a control.                                                    */
/* Key Filter Result Codes                                                          */
/* The filter proc should return one of the two constants below. If                 */
/* kKeyFilterBlockKey is returned, the key is blocked and never makes it to the     */
/* control. If kKeyFilterPassKey is returned, the control receives the keystroke.   */
enum {
  kControlKeyFilterBlockKey     = 0,
  kControlKeyFilterPassKey      = 1
};

typedef SInt16                          ControlKeyFilterResult;
typedef CALLBACK_API( ControlKeyFilterResult , ControlKeyFilterProcPtr )(ControlRef theControl, SInt16 *keyCode, SInt16 *charCode, EventModifiers *modifiers);
typedef STACK_UPP_TYPE(ControlKeyFilterProcPtr)                 ControlKeyFilterUPP;
/*
 *  NewControlKeyFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ControlKeyFilterUPP
NewControlKeyFilterUPP(ControlKeyFilterProcPtr userRoutine)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeControlKeyFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeControlKeyFilterUPP(ControlKeyFilterUPP userUPP)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeControlKeyFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ControlKeyFilterResult
InvokeControlKeyFilterUPP(
  ControlRef           theControl,
  SInt16 *             keyCode,
  SInt16 *             charCode,
  EventModifiers *     modifiers,
  ControlKeyFilterUPP  userUPP)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ DragGrayRgn Constatns                                                             */
/*                                                                                      */
/*   For DragGrayRgnUPP used in TrackControl()                                          */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  noConstraint                  = kNoConstraint,
  hAxisOnly                     = 1,
  vAxisOnly                     = 2
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Creation/Deletion/Persistence                                             */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  CreateCustomControl is only available as part of Carbon                             */
enum {
  kControlDefProcPtr            = 0,    /* raw proc-ptr based access*/
  kControlDefObjectClass        = 1     /* event-based definition (Mac OS X only)*/
};

typedef UInt32                          ControlDefType;
struct ControlDefSpec {
  ControlDefType      defType;
  union {
    ControlDefUPP       defProc;
    void *              classRef;
  }                       u;
};
typedef struct ControlDefSpec           ControlDefSpec;
/*
 *  CreateCustomControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
CreateCustomControl(
  WindowRef               owningWindow,
  const Rect *            contBounds,
  const ControlDefSpec *  def,
  Collection              initData,
  ControlRef *            outControl)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern ControlRef 
NewControl(
  WindowRef          owningWindow,
  const Rect *       boundsRect,
  ConstStr255Param   controlTitle,
  Boolean            initiallyVisible,
  SInt16             initialValue,
  SInt16             minimumValue,
  SInt16             maximumValue,
  SInt16             procID,
  SInt32             controlReference)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetNewControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern ControlRef 
GetNewControl(
  SInt16      resourceID,
  WindowRef   owningWindow)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
DisposeControl(ControlRef theControl)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  KillControls()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
KillControls(WindowRef theWindow)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlattenControl()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */


/*
 *  UnflattenControl()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Definition Registration                                                   */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
typedef CALLBACK_API( OSStatus , ControlCNTLToCollectionProcPtr )(const Rect *bounds, SInt16 value, Boolean visible, SInt16 max, SInt16 min, SInt16 procID, SInt32 refCon, ConstStr255Param title, Collection collection);
typedef STACK_UPP_TYPE(ControlCNTLToCollectionProcPtr)          ControlCNTLToCollectionUPP;
/*
 *  NewControlCNTLToCollectionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ControlCNTLToCollectionUPP
NewControlCNTLToCollectionUPP(ControlCNTLToCollectionProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeControlCNTLToCollectionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeControlCNTLToCollectionUPP(ControlCNTLToCollectionUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeControlCNTLToCollectionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSStatus
InvokeControlCNTLToCollectionUPP(
  const Rect *                bounds,
  SInt16                      value,
  Boolean                     visible,
  SInt16                      max,
  SInt16                      min,
  SInt16                      procID,
  SInt32                      refCon,
  ConstStr255Param            title,
  Collection                  collection,
  ControlCNTLToCollectionUPP  userUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  RegisterControlDefinition()
 *  
 *  Summary:
 *    Associates or dissociates a control definition with a virtual
 *    CDEF resource ID.
 *  
 *  Discussion:
 *    In GetNewControl or NewControl on Carbon, the Control Manager
 *    needs to know how to map the procID to a ControlDefSpec. With
 *    RegisterControlDefinition, your application can inform the
 *    Control Manager which ControlDefSpec to call when it sees a
 *    request to use a 'CDEF' of a particular resource ID. Since custom
 *    control definitions receive their initialization data in a
 *    Collection passed in the 'param' parameter, you must also provide
 *    a procedure to convert the bounds, min, max, and other parameters
 *    to NewControl into a Collection. If you don't provide a
 *    conversion proc, your control will receive an empty collection
 *    when it is sent the initialization message. If you want the
 *    value, min, visibility, etc. to be given to the control, you must
 *    add the appropriate tagged data to the collection. See the
 *    Control Collection Tags above. If you want to unregister a
 *    ControlDefSpec that you have already registered, call
 *    RegisterControlDefinition with the same CDEF resource ID, but
 *    pass NULL for the inControlDef parameter. In this situation,
 *    inConversionProc is effectively ignored.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inCDEFResID:
 *      The virtual CDEF resource ID to which you'd like to associate
 *      or dissociate the control definition.
 *    
 *    inControlDef:
 *      A pointer to a ControlDefSpec which represents the control
 *      definition you want to register, or NULL if you are attempting
 *      to unregister a control definition.
 *    
 *    inConversionProc:
 *      The conversion proc which will translate the NewControl
 *      parameters into a Collection.
 *  
 *  Result:
 *    An OSStatus code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
RegisterControlDefinition(
  SInt16                       inCDEFResID,
  const ControlDefSpec *       inControlDef,
  ControlCNTLToCollectionUPP   inConversionProc)              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Visible State                                                             */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  HiliteControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
HiliteControl(
  ControlRef        theControl,
  ControlPartCode   hiliteState)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ShowControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
ShowControl(ControlRef theControl)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HideControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
HideControl(ControlRef theControl)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/* following state routines available only with Appearance 1.0 and later*/
/*
 *  IsControlActive()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern Boolean 
IsControlActive(ControlRef inControl)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IsControlVisible()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern Boolean 
IsControlVisible(ControlRef inControl)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ActivateControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
ActivateControl(ControlRef inControl)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DeactivateControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
DeactivateControl(ControlRef inControl)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlVisibility()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
SetControlVisibility(
  ControlRef   inControl,
  Boolean      inIsVisible,
  Boolean      inDoDraw)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/* following state routines available only on Mac OS X and later*/
/*
 *  IsControlEnabled()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.0 and later
 *    Non-Carbon CFM:   not available
 */
extern Boolean 
IsControlEnabled(ControlRef inControl)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  EnableControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
EnableControl(ControlRef inControl)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisableControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
DisableControl(ControlRef inControl)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Imaging                                                                   */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  DrawControls()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
DrawControls(WindowRef theWindow)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Draw1Control()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
Draw1Control(ControlRef theControl)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


#define DrawOneControl(theControl) Draw1Control(theControl)

/*
 *  UpdateControls()
 *  
 *  Summary:
 *    Redraws the controls that intersect a specified region in a
 *    window.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window whose controls to redraw.
 *    
 *    inUpdateRegion:
 *      The region (in local coordinates) describing which controls to
 *      redraw. In Mac OS 10.1 and later, and in CarbonLib 1.5 and
 *      later, you may pass NULL for this parameter to redraw the
 *      controls intersecting the visible region of the window.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
UpdateControls(
  WindowRef   inWindow,
  RgnHandle   inUpdateRegion)       /* can be NULL */         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/* following imaging routines available only with Appearance 1.0 and later*/
/*
 *  GetBestControlRect()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
GetBestControlRect(
  ControlRef   inControl,
  Rect *       outRect,
  SInt16 *     outBaseLineOffset)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlFontStyle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
SetControlFontStyle(
  ControlRef                   inControl,
  const ControlFontStyleRec *  inStyle)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawControlInCurrentPort()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern void 
DrawControlInCurrentPort(ControlRef inControl)                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetUpControlBackground()
 *  
 *  Summary:
 *    Applies the proper background color for the given control to the
 *    current port.
 *  
 *  Discussion:
 *    An embedding-savvy control which erases before drawing must
 *    ensure that its background color properly matches the body color
 *    of any parent controls on top of which it draws. This routine
 *    asks the Control Manager to determine and apply the proper
 *    background color to the current port. If a ControlColorProc has
 *    been provided for the given control, the proc will be called to
 *    set up the background color. If no proc exists, or if the proc
 *    returns a value other than noErr, the Control Manager ascends the
 *    parent chain for the given control looking for a control which
 *    has a special background (see the kControlHasSpecialBackground
 *    feature bit). The first such parent is asked to set up the
 *    background color (see the kControlMsgSetUpBackground message). If
 *    no such parent exists, the Control Manager applies any ThemeBrush
 *    which has been associated with the owning window (see
 *    SetThemeWindowBackground). Available in Appearance 1.0 (Mac OS
 *    8), CarbonLib 1.0, Mac OS X, and later.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The ControlRef that wants to erase.
 *    
 *    inDepth:
 *      A short integer indicating the color depth of the device onto
 *      which drawing will take place.
 *    
 *    inIsColorDevice:
 *      A Boolean indicating whether the draw device is a color device.
 *  
 *  Result:
 *    An OSStatus code indicating success or failure. The most likely
 *    error is a controlHandleInvalidErr, resulting from a bad
 *    ControlRef. Any non-noErr result indicates that the color set up
 *    failed, and that the caller should probably give up its attempt
 *    to draw.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
SetUpControlBackground(
  ControlRef   inControl,
  SInt16       inDepth,
  Boolean      inIsColorDevice)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetUpControlTextColor()
 *  
 *  Summary:
 *    Applies the proper text color for the given control to the
 *    current port.
 *  
 *  Discussion:
 *    An embedding-savvy control which draws text must ensure that its
 *    text color properly contrasts the background on which it draws.
 *    This routine asks the Control Manager to determine and apply the
 *    proper text color to the current port. If a ControlColorProc has
 *    been provided for the given control, the proc will be called to
 *    set up the text color. If no proc exists, or if the proc returns
 *    a value other than noErr, the Control Manager ascends the parent
 *    chain for the given control looking for a control which has a
 *    special background (see the kControlHasSpecialBackground feature
 *    bit). The first such parent is asked to set up the text color
 *    (see the kControlMsgApplyTextColor message). If no such parent
 *    exists, the Control Manager chooses a text color which contrasts
 *    any ThemeBrush which has been associated with the owning window
 *    (see SetThemeWindowBackground). Available in Appearance 1.1 (Mac
 *    OS 8.5), CarbonLib 1.0, Mac OS X, and later.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The ControlRef that wants to draw text.
 *    
 *    inDepth:
 *      A short integer indicating the color depth of the device onto
 *      which drawing will take place.
 *    
 *    inIsColorDevice:
 *      A Boolean indicating whether the draw device is a color device.
 *  
 *  Result:
 *    An OSStatus code indicating success or failure. The most likely
 *    error is a controlHandleInvalidErr, resulting from a bad
 *    ControlRef. Any non-noErr result indicates that the color set up
 *    failed, and that the caller should probably give up its attempt
 *    to draw.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern OSErr 
SetUpControlTextColor(
  ControlRef   inControl,
  SInt16       inDepth,
  Boolean      inIsColorDevice)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*
 *  ControlColorProcPtr
 *  
 *  Discussion:
 *    Callback allowing clients to specify/override the background
 *    color and text color that a Control will use during drawing. Your
 *    procedure should make the color changes to the current port. See
 *    SetControlColorProc, SetUpControlBackground, and
 *    SetUpControlTextColor for more information. Available on Mac OS
 *    8.5, CarbonLib 1.1, Mac OS X, and later.
 *  
 *  Parameters:
 *    
 *    inControl:
 *      A reference to the Control for whom your proc is setting up
 *      colors.
 *    
 *    inMessage:
 *      A ControlDefProcMessage indicating what sort of color your
 *      procedure should set up. It will be either
 *      kControlMsgApplyTextColor or kControlMsgSetUpBackground.
 *      kControlMsgApplyTextColor is a request to set up the
 *      appropriate text color (by setting the current port's
 *      foreground color, pen information, etc.).
 *      kControlMsgSetUpBackground is a request to set up the
 *      appropriate background color (the current port's background
 *      color, pattern, etc.).
 *    
 *    inDrawDepth:
 *      A short integer indicating the bit depth of the device into
 *      which the Control is drawing. The bit depth is typically passed
 *      in as a result of someone someone trying to draw properly
 *      across multiple monitors with different bit depths. If your
 *      procedure wants to handle proper color set up based on bit
 *      depth, it should use this parameter to help decide what color
 *      to apply.
 *    
 *    inDrawInColor:
 *      A Boolean indicating whether or not the device that the Control
 *      is drawing into is a color device. The value is typically
 *      passed in as a result of someone trying to draw properly across
 *      multiple monitors which may or may not be color devices. If
 *      your procedure wants to handle proper color set up for both
 *      color and grayscale devices, it should use this parameter to
 *      help decide what color to apply.
 *  
 *  Result:
 *    An OSStatus code indicating success or failure. Returning noErr
 *    is an indication that your proc completely handled the color set
 *    up. If you return any other value, the Control Manager will fall
 *    back to the normal color set up mechanism.
 */
typedef CALLBACK_API( OSStatus , ControlColorProcPtr )(ControlRef inControl, SInt16 inMessage, SInt16 inDrawDepth, Boolean inDrawInColor);
typedef STACK_UPP_TYPE(ControlColorProcPtr)                     ControlColorUPP;
/*
 *  NewControlColorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ControlColorUPP
NewControlColorUPP(ControlColorProcPtr userRoutine)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeControlColorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeControlColorUPP(ControlColorUPP userUPP)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeControlColorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSStatus
InvokeControlColorUPP(
  ControlRef       inControl,
  SInt16           inMessage,
  SInt16           inDrawDepth,
  Boolean          inDrawInColor,
  ControlColorUPP  userUPP)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  SetControlColorProc()
 *  
 *  Summary:
 *    Associates a ControlColorUPP with a given Control, thereby
 *    allowing you to bypass the embedding hierarchy-based color setup
 *    of SetUpControlBackground/SetUpControlTextColor and replace it
 *    with your own.
 *  
 *  Discussion:
 *    Before an embedded Control can erase, it calls
 *    SetUpControlBackground to have its background color set up by any
 *    parent controls. Similarly, any Control which draws text calls
 *    SetUpControlTextColor to have the appropriate text color set up.
 *    This allows certain controls (such as Tabs and Placards) to offer
 *    special backgrounds and text colors for any child controls. By
 *    default, the SetUp routines only move up the Control Manager
 *    embedding hierarchy looking for a parent which has a special
 *    background. This is fine in a plain vanilla embedding case, but
 *    many application frameworks find it troublesome; if there are
 *    interesting views between two Controls in the embedding
 *    hierarchy, the framework needs to be in charge of the background
 *    and text colors, otherwise drawing defects will occur. You can
 *    only associate a single color proc with a given ControlRef.
 *    Available on Mac OS 8.5, CarbonLib 1.1, Mac OS X, and later.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The ControlRef with whom the color proc should be associated.
 *    
 *    inProc:
 *      The color proc to associate with the ControlRef. If you pass
 *      NULL, the ControlRef will be dissociated from any previously
 *      installed color proc.
 *  
 *  Result:
 *    An OSStatus code indicating success or failure. The most likely
 *    error is a controlHandleInvalidErr resulting from a bad
 *    ControlRef.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern OSStatus 
SetControlColorProc(
  ControlRef        inControl,
  ControlColorUPP   inProc)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Mousing                                                                   */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
    NOTE ON CONTROL ACTION PROCS

    When using the TrackControl() call when tracking an indicator, the actionProc parameter
    (type ControlActionUPP) should be replaced by a parameter of type DragGrayRgnUPP
    (see Quickdraw.h).

    If, however, you are using the live feedback variants of scroll bars or sliders, you
    must pass a ControlActionUPP in when tracking the indicator as well. This functionality
    is available in Appearance 1.0 or later.
*/
/*
 *  TrackControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern ControlPartCode 
TrackControl(
  ControlRef         theControl,
  Point              startPoint,
  ControlActionUPP   actionProc)       /* can be NULL */      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DragControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
DragControl(
  ControlRef       theControl,
  Point            startPoint,
  const Rect *     limitRect,
  const Rect *     slopRect,
  DragConstraint   axis)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TestControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern ControlPartCode 
TestControl(
  ControlRef   theControl,
  Point        testPoint)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FindControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern ControlPartCode 
FindControl(
  Point         testPoint,
  WindowRef     theWindow,
  ControlRef *  theControl)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* The following mousing routines available only with Appearance 1.0 and later  */
/*                                                                              */
/* HandleControlClick is preferable to TrackControl when running under          */
/* Appearance 1.0 as you can pass in modifiers, which some of the new controls  */
/* use, such as edit text and list boxes.                                       */
/* NOTE: Passing NULL for the outPart parameter of FindControlUnderMouse is only*/
/*       supported in systems later than 10.1.x                                 */
/*
 *  FindControlUnderMouse()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern ControlRef 
FindControlUnderMouse(
  Point              inWhere,
  WindowRef          inWindow,
  ControlPartCode *  outPart)        /* can be NULL */        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HandleControlClick()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern ControlPartCode 
HandleControlClick(
  ControlRef         inControl,
  Point              inWhere,
  EventModifiers     inModifiers,
  ControlActionUPP   inAction)          /* can be NULL */     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Contextual Menu support in the Control Manager is only available on Carbon.  */
/* If the control didn't display a contextual menu (possibly because the point  */
/* was in a non-interesting part), the menuDisplayed output parameter will be   */
/* false. If the control did display a menu, menuDisplayed will be true.        */
/* This in on Carbon only                                                       */
/*
 *  HandleControlContextualMenuClick()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
HandleControlContextualMenuClick(
  ControlRef   inControl,
  Point        inWhere,
  Boolean *    menuDisplayed)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Some complex controls (like Data Browser) require proper sequencing of       */
/* window activation and click processing. In some cases, the control might     */
/* want the window to be left inactive yet still handle the click, or vice-     */
/* versa. The GetControlClickActivation routine lets a control client ask the   */
/* control how it wishes to behave for a particular click.                      */
/* This in on Carbon only.                                                      */
/*
 *  GetControlClickActivation()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
GetControlClickActivation(
  ControlRef               inControl,
  Point                    inWhere,
  EventModifiers           inModifiers,
  ClickActivationResult *  outResult)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Events (available only with Appearance 1.0 and later)                     */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  HandleControlKey()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern ControlPartCode 
HandleControlKey(
  ControlRef       inControl,
  SInt16           inKeyCode,
  SInt16           inCharCode,
  EventModifiers   inModifiers)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IdleControls()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern void 
IdleControls(WindowRef inWindow)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* ₯ Control Mouse Tracking (available with Carbon)                                     */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* The HandleControlSetCursor routine requests that a given control set the cursor to   */
/* something appropriate based on the mouse location.                                   */
/* If the control didn't want to set the cursor (because the point was in a             */
/* non-interesting part), the cursorWasSet output parameter will be false. If the       */
/* control did set the cursor, cursorWasSet will be true.                               */
/* Carbon only.                                                                         */
/*
 *  HandleControlSetCursor()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
HandleControlSetCursor(
  ControlRef       control,
  Point            localPoint,
  EventModifiers   modifiers,
  Boolean *        cursorWasSet)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Positioning                                                               */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  MoveControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
MoveControl(
  ControlRef   theControl,
  SInt16       h,
  SInt16       v)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SizeControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SizeControl(
  ControlRef   theControl,
  SInt16       w,
  SInt16       h)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Title                                                                     */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SetControlTitle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetControlTitle(
  ControlRef         theControl,
  ConstStr255Param   title)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlTitle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
GetControlTitle(
  ControlRef   theControl,
  Str255       title)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlTitleWithCFString()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetControlTitleWithCFString(
  ControlRef    inControl,
  CFStringRef   inString)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CopyControlTitleAsCFString()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
CopyControlTitleAsCFString(
  ControlRef     inControl,
  CFStringRef *  outString)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Value                                                                     */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  GetControlValue()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern SInt16 
GetControlValue(ControlRef theControl)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlValue()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetControlValue(
  ControlRef   theControl,
  SInt16       newValue)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlMinimum()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern SInt16 
GetControlMinimum(ControlRef theControl)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlMinimum()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetControlMinimum(
  ControlRef   theControl,
  SInt16       newMinimum)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlMaximum()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern SInt16 
GetControlMaximum(ControlRef theControl)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlMaximum()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetControlMaximum(
  ControlRef   theControl,
  SInt16       newMaximum)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/* proportional scrolling/32-bit value support is new with Appearance 1.1*/

/*
 *  GetControlViewSize()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern SInt32 
GetControlViewSize(ControlRef theControl)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlViewSize()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern void 
SetControlViewSize(
  ControlRef   theControl,
  SInt32       newViewSize)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControl32BitValue()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern SInt32 
GetControl32BitValue(ControlRef theControl)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControl32BitValue()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern void 
SetControl32BitValue(
  ControlRef   theControl,
  SInt32       newValue)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControl32BitMaximum()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern SInt32 
GetControl32BitMaximum(ControlRef theControl)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControl32BitMaximum()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern void 
SetControl32BitMaximum(
  ControlRef   theControl,
  SInt32       newMaximum)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControl32BitMinimum()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern SInt32 
GetControl32BitMinimum(ControlRef theControl)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControl32BitMinimum()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern void 
SetControl32BitMinimum(
  ControlRef   theControl,
  SInt32       newMinimum)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    IsValidControlHandle will tell you if the handle you pass in belongs to a control
    the Control Manager knows about. It does not sanity check the data in the control.
*/

/*
 *  IsValidControlHandle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern Boolean 
IsValidControlHandle(ControlRef theControl)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* ₯ Control IDs                                                                        */
/* Carbon only.                                                                         */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlID {
  OSType              signature;
  SInt32              id;
};
typedef struct ControlID                ControlID;
/*
 *  SetControlID()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetControlID(
  ControlRef         inControl,
  const ControlID *  inID)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlID()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetControlID(
  ControlRef   inControl,
  ControlID *  outID)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlByID()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetControlByID(
  WindowRef          inWindow,
  const ControlID *  inID,
  ControlRef *       outControl)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* ₯ Control Command IDs                                                                    */
/* Carbon only.                                                                         */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SetControlCommandID()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetControlCommandID(
  ControlRef   inControl,
  UInt32       inCommandID)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlCommandID()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetControlCommandID(
  ControlRef   inControl,
  UInt32 *     outCommandID)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* ₯ Control Identification                                                             */
/* Carbon only.                                                                         */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct ControlKind {
  OSType              signature;
  OSType              kind;
};
typedef struct ControlKind              ControlKind;

/*
 *  Discussion:
 *    Control signature kind
 */
enum {

  /*
   * Signature of all system controls.
   */
  kControlKindSignatureApple    = 'appl'
};

/*
 *  GetControlKind()
 *  
 *  Summary:
 *    Returns the kind of the given control.
 *  
 *  Discussion:
 *    GetControlKind allows you to query the kind of any control. This
 *    function is only available in Mac OS X.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The ControlRef to find the kind of.
 *    
 *    outControlKind:
 *      On successful exit, this will contain the control signature and
 *      kind. See ControlDefinitions.h for the kinds of each system
 *      control.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.5 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetControlKind(
  ControlRef     inControl,
  ControlKind *  outControlKind)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* ₯ Properties                                                                         */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  kControlPropertyPersistent    = 0x00000001 /* whether this property gets saved when flattening the control*/
};

/*
 *  GetControlProperty()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern OSStatus 
GetControlProperty(
  ControlRef   control,
  OSType       propertyCreator,
  OSType       propertyTag,
  UInt32       bufferSize,
  UInt32 *     actualSize,            /* can be NULL */
  void *       propertyBuffer)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlPropertySize()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern OSStatus 
GetControlPropertySize(
  ControlRef   control,
  OSType       propertyCreator,
  OSType       propertyTag,
  UInt32 *     size)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlProperty()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern OSStatus 
SetControlProperty(
  ControlRef    control,
  OSType        propertyCreator,
  OSType        propertyTag,
  UInt32        propertySize,
  const void *  propertyData)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  RemoveControlProperty()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern OSStatus 
RemoveControlProperty(
  ControlRef   control,
  OSType       propertyCreator,
  OSType       propertyTag)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlPropertyAttributes()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetControlPropertyAttributes(
  ControlRef   control,
  OSType       propertyCreator,
  OSType       propertyTag,
  UInt32 *     attributes)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ChangeControlPropertyAttributes()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
ChangeControlPropertyAttributes(
  ControlRef   control,
  OSType       propertyCreator,
  OSType       propertyTag,
  UInt32       attributesToSet,
  UInt32       attributesToClear)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Regions (Appearance 1.1 or later)                                         */
/*                                                                                      */
/*  See the discussion on meta-parts in this header for more information                */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  GetControlRegion()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 8.5 and later
 */
extern OSStatus 
GetControlRegion(
  ControlRef        inControl,
  ControlPartCode   inPart,
  RgnHandle         outRegion)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Variant                                                                   */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  GetControlVariant()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern ControlVariant 
GetControlVariant(ControlRef theControl)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Action                                                                    */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SetControlAction()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetControlAction(
  ControlRef         theControl,
  ControlActionUPP   actionProc)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlAction()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern ControlActionUPP 
GetControlAction(ControlRef theControl)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/* ₯ Control Accessors                                                                  */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SetControlReference()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetControlReference(
  ControlRef   theControl,
  SInt32       data)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlReference()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern SInt32 
GetControlReference(ControlRef theControl)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


#if !OPAQUE_TOOLBOX_STRUCTS
/*
 *  GetAuxiliaryControlRecord()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


#endif  /* !OPAQUE_TOOLBOX_STRUCTS */

/*
 *  SetControlColor()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Hierarchy (Appearance 1.0 and later only)                                 */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SendControlMessage()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern SInt32 
SendControlMessage(
  ControlRef   inControl,
  SInt16       inMessage,
  void *       inParam)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DumpControlHierarchy()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
DumpControlHierarchy(
  WindowRef       inWindow,
  const FSSpec *  inDumpFile)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CreateRootControl()
 *  
 *  Summary:
 *    Creates a new root control for a window.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window for which to create a root control.
 *    
 *    outControl:
 *      On exit, contains the window's root control. In Mac OS 10.1 and
 *      CarbonLib 1.5 and later, this parameter may be NULL if you
 *      don't need the ControlRef.
 *  
 *  Result:
 *    A result code indicating success or failure. errRootAlreadyExists
 *    is returned if the window already has a root control.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
CreateRootControl(
  WindowRef     inWindow,
  ControlRef *  outControl)       /* can be NULL */           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetRootControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
GetRootControl(
  WindowRef     inWindow,
  ControlRef *  outControl)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  EmbedControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
EmbedControl(
  ControlRef   inControl,
  ControlRef   inContainer)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AutoEmbedControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
AutoEmbedControl(
  ControlRef   inControl,
  WindowRef    inWindow)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetSuperControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
GetSuperControl(
  ControlRef    inControl,
  ControlRef *  outParent)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CountSubControls()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
CountSubControls(
  ControlRef   inControl,
  UInt16 *     outNumChildren)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetIndexedSubControl()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
GetIndexedSubControl(
  ControlRef    inControl,
  UInt16        inIndex,
  ControlRef *  outSubControl)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlSupervisor()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
SetControlSupervisor(
  ControlRef   inControl,
  ControlRef   inBoss)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Keyboard Focus (available only with Appearance 1.0 and later)                     */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  GetKeyboardFocus()
 *  
 *  Discussion:
 *    Passes back the currently focused control within the given window.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window to get the focus of.
 *    
 *    outControl:
 *      On output, this will contain the ControlRef that is currently
 *      focused in the given window. If there is no currently focused
 *      control, outControl will contain NULL.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
GetKeyboardFocus(
  WindowRef     inWindow,
  ControlRef *  outControl)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetKeyboardFocus()
 *  
 *  Discussion:
 *    Focuses the given part of the given control in a particular
 *    window. If another control is currently focused in the window,
 *    focus will be removed from the other control before focus is
 *    given to the desired control. SetKeyboardFocus respects the full
 *    keyboard navigation mode.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window which contains the control you want to focus. If the
 *      window does not contain the control, an error will be returned.
 *    
 *    inControl:
 *      The control you want to focus.
 *    
 *    inPart:
 *      The part of the control you wish to focus. You may pass
 *      kControlFocusNoPart to clear the focus in the given control.
 *      You may pass kControlFocusNextPart or kControlFocusPrevPart to
 *      move the focus within the given control.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
SetKeyboardFocus(
  WindowRef          inWindow,
  ControlRef         inControl,
  ControlFocusPart   inPart)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AdvanceKeyboardFocus()
 *  
 *  Discussion:
 *    Advances the focus to the next most appropriate control. Unless
 *    overriden in some fashion (either by overriding certain carbon
 *    events or using the HIViewSetNextFocus API), the Toolbox will use
 *    a spacially determinant method of focusing, attempting to focus
 *    left to right, top to bottom in a window, taking groups of
 *    controls into account. AdvanceKeyboardFocus does not respect the
 *    full keyboard navigation mode. It will only advance the focus
 *    between traditionally focusable controls. If you want to advance
 *    the focus in a way that respects the full keyboard navigation
 *    mode, use the HIViewAdvanceFocus API.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window to advance the focus in.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
AdvanceKeyboardFocus(WindowRef inWindow)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ReverseKeyboardFocus()
 *  
 *  Discussion:
 *    Reverses the focus to the next most appropriate control. Unless
 *    overriden in some fashion (either by overriding certain carbon
 *    events or using the HIViewSetNextFocus API), the Toolbox will use
 *    a spacially determinant method of focusing, attempting to focus
 *    left to right, top to bottom in a window, taking groups of
 *    controls into account. ReverseKeyboardFocus does not respect the
 *    full keyboard navigation mode. It will only reverse the focus
 *    between traditionally focusable controls. If you want to reverse
 *    the focus in a way that respects the full keyboard navigation
 *    mode, use the HIViewAdvanceFocus API.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window to reverse the focus in.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
ReverseKeyboardFocus(WindowRef inWindow)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClearKeyboardFocus()
 *  
 *  Discussion:
 *    Clears focus from the currently focused control in a given
 *    window. The window will be left such that no control is focused
 *    within it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window that you want to clear the focus in.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
ClearKeyboardFocus(WindowRef inWindow)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Data (available only with Appearance 1.0 and later)                       */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/

/*
 *  GetControlFeatures()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
GetControlFeatures(
  ControlRef   inControl,
  UInt32 *     outFeatures)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlData()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
SetControlData(
  ControlRef        inControl,
  ControlPartCode   inPart,
  ResType           inTagName,
  Size              inSize,
  const void *      inData)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlData()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
GetControlData(
  ControlRef        inControl,
  ControlPartCode   inPart,
  ResType           inTagName,
  Size              inBufferSize,
  void *            inBuffer,
  Size *            outActualSize)       /* can be NULL */    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlDataSize()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSErr 
GetControlDataSize(
  ControlRef        inControl,
  ControlPartCode   inPart,
  ResType           inTagName,
  Size *            outMaxSize)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ Control Drag & Drop                                                               */
/*      Carbon only.                                                                    */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/

/*
 *  Discussion:
 *    DragTrackingMessage values for use with HandleControlDragTracking.
 */
enum {

  /*
   * The drag was previously outside the control and it just now
   * entered the control.
   */
  kDragTrackingEnterControl     = 2,

  /*
   * The drag was previously inside the control and it is still inside
   * the control.
   */
  kDragTrackingInControl        = 3,

  /*
   * The drag was previously inside the control and it just now left
   * the control.
   */
  kDragTrackingLeaveControl     = 4
};


/*
 *  HandleControlDragTracking()
 *  
 *  Summary:
 *    Tells a control to respond visually to a drag.
 *  
 *  Discussion:
 *    Call HandleControlDragTracking when a drag is above a control in
 *    your window and you want to give that control a chance to draw
 *    appropriately in response to the drag. Note that in order for a
 *    control to have any chance of responding to this API, you must
 *    enable the control's drag and drop support with
 *    SetControlDragTrackingEnabled.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The control the drag is over. Most controls won't track drags
 *      unless you enable drag tracking on it with
 *      SetControlDragTrackingEnabled.
 *    
 *    inMessage:
 *      A drag message indicating the state of the drag above the
 *      control. The meaning of the value you pass in must be relative
 *      to the control, not the whole window. For when the drag first
 *      enters the control, you should pass kDragTrackingEnterControl.
 *      While the drag stays within the control, pass
 *      kDragTrackingInControl. When the drag leaves the control, pass
 *      kDragTrackingLeaveControl.
 *    
 *    inDrag:
 *      The drag reference that is over the control.
 *    
 *    outLikesDrag:
 *      On output, this will be a boolean indicating whether the
 *      control "likes" the drag. A control "likes" the drag if the
 *      data in the drag ref can be accepted by the control. If the
 *      control does not like the drag, don't bother calling
 *      HandleControlDragReceive if the user drops the dragged object
 *      onto the control.
 *  
 *  Result:
 *    A result code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
HandleControlDragTracking(
  ControlRef            inControl,
  DragTrackingMessage   inMessage,
  DragReference         inDrag,
  Boolean *             outLikesDrag)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  HandleControlDragReceive()
 *  
 *  Summary:
 *    Tells a control to accept the data in drag reference.
 *  
 *  Discussion:
 *    Call HandleControlDragReceive when the user dropped a drag on a
 *    control in your window. This gives the control the opportunity to
 *    pull any interesting data out of the drag and insert the data
 *    into itself. Note that in order for a control to have any chance
 *    of responding to this API, you must enable the control's drag and
 *    drop support with SetControlDragTrackingEnabled.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The control who should accept the data. Most controls won't
 *      accept drags unless you enable drag tracking on it with
 *      SetControlDragTrackingEnabled.
 *    
 *    inDrag:
 *      The drag reference that was dropped on the control.
 *  
 *  Result:
 *    A result code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
HandleControlDragReceive(
  ControlRef      inControl,
  DragReference   inDrag)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  SetControlDragTrackingEnabled()
 *  
 *  Summary:
 *    Tells a control that it should track and receive drags.
 *  
 *  Discussion:
 *    Call SetControlDragTrackingEnabled to turn enable a control's
 *    support for drag and drop. Controls won't track drags unless you
 *    first turn on drag and drop support with this API. Some controls
 *    don't support drag and drop at all; these controls won't track or
 *    receive drags even if you call this API with true.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The control whose drag tracking enabled state you'd like to set.
 *    
 *    inTracks:
 *      A Boolean indicating whether you want this control to track and
 *      receive drags.
 *  
 *  Result:
 *    A result code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
SetControlDragTrackingEnabled(
  ControlRef   inControl,
  Boolean      inTracks)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  IsControlDragTrackingEnabled()
 *  
 *  Summary:
 *    Tells you whether a control's drag track and receive support is
 *    enabled.
 *  
 *  Discussion:
 *    Call IsControlDragTrackingEnabled to query a whether a control's
 *    drag and drop support is enabled. Some controls don't support
 *    drag and drop at all; these controls won't track or receive drags
 *    even if you call this API and see a true output value.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The control whose drag tracking enabled state you'd like to
 *      query.
 *    
 *    outTracks:
 *      On output, this will contain a Boolean value whether the
 *      control's drag and drop support is enabled.
 *  
 *  Result:
 *    A result code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
IsControlDragTrackingEnabled(
  ControlRef   inControl,
  Boolean *    outTracks)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  SetAutomaticControlDragTrackingEnabledForWindow()
 *  
 *  Summary:
 *    Enables or disables the Control Manager's automatic drag tracking
 *    for a given window.
 *  
 *  Discussion:
 *    Call SetAutomaticControlDragTrackingEnabledForWindow to turn on
 *    or off the Control Manager's automatic drag tracking support for
 *    a given window. By default, your application code is responsible
 *    for installing drag tracking and receive handlers on a given
 *    window. The Control Manager, however, has support for
 *    automatically tracking and receiving drags over controls. The
 *    Control Manager will detect the control the drag is over and call
 *    HandleControlDragTracking and HandleControlDragReceive
 *    appropriately. By default, this automatic support is turned off.
 *    You can turn on this support by calling
 *    SetAutomaticControlDragTrackingEnabledForWindow with true. Note
 *    that earlier versions of system software incorrectly enable this
 *    support by default; do not rely on this buggy behavior. As of Mac
 *    OS 10.1.3, Mac OS 9.2, and CarbonLib 1.4, the buggy behavior is
 *    fixed, and you must call this routine with true to enable
 *    automatic drag tracking.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window for which you'd like to enable or disable the
 *      Control Manager's automatic drag tracking support.
 *    
 *    inTracks:
 *      A Boolean value indicating whether you want to enable the
 *      Control Manager's automatic drag tracking support.
 *  
 *  Result:
 *    A result code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
SetAutomaticControlDragTrackingEnabledForWindow(
  WindowRef   inWindow,
  Boolean     inTracks)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  IsAutomaticControlDragTrackingEnabledForWindow()
 *  
 *  Summary:
 *    Tells you whether the Control Manager's automatic drag tracking
 *    is enabled for a given window.
 *  
 *  Discussion:
 *    Call IsAutomaticControlDragTrackingEnabledForWindow to query the
 *    enabled state of the Control Manager's automatic drag tracking
 *    support for a given window. See the information on
 *    SetAutomaticControlDragTrackingEnabledForWindow for more details.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window whose Control Manager automatic drag tracking enable
 *      state you'd like to query.
 *    
 *    outTracks:
 *      On output, this will contain a Boolean value whether the
 *      Control Manager's automatic drag tracking is enabled.
 *  
 *  Result:
 *    A result code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in ControlsLib 9.0 and later
 */
extern OSStatus 
IsAutomaticControlDragTrackingEnabledForWindow(
  WindowRef   inWindow,
  Boolean *   outTracks)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ C Glue                                                                            */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
#if CALL_NOT_IN_CARBON
/*
 *  dragcontrol()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  newcontrol()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  findcontrol()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  getcontroltitle()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  setcontroltitle()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  trackcontrol()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  testcontrol()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


#endif  /* CALL_NOT_IN_CARBON */

#if OLDROUTINENAMES
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*  ₯ OLDROUTINENAMES                                                                   */
/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  useWFont                      = kControlUsesOwningWindowsFontVariant
};

enum {
  inThumb                       = kControlIndicatorPart,
  kNoHiliteControlPart          = kControlNoPart,
  kInIndicatorControlPart       = kControlIndicatorPart,
  kReservedControlPart          = kControlDisabledPart,
  kControlInactiveControlPart   = kControlInactivePart
};


#define SetCTitle(theControl, title) SetControlTitle(theControl, title)
#define GetCTitle(theControl, title) GetControlTitle(theControl, title)
#define UpdtControl(theWindow, updateRgn) UpdateControls(theWindow, updateRgn)
#define SetCtlValue(theControl, theValue) SetControlValue(theControl, theValue)
#define GetCtlValue(theControl) GetControlValue(theControl)
#define SetCtlMin(theControl, minValue) SetControlMinimum(theControl, minValue)
#define GetCtlMin(theControl) GetControlMinimum(theControl)
#define SetCtlMax(theControl, maxValue) SetControlMaximum(theControl, maxValue)
#define GetCtlMax(theControl) GetControlMaximum(theControl)
#define GetAuxCtl(theControl, acHndl) GetAuxiliaryControlRecord(theControl, acHndl)
#define SetCRefCon(theControl, data) SetControlReference(theControl, data)
#define GetCRefCon(theControl) GetControlReference(theControl)
#define SetCtlAction(theControl, actionProc) SetControlAction(theControl, actionProc)
#define GetCtlAction(theControl) GetControlAction(theControl)
#define SetCtlColor(theControl, newColorTable) SetControlColor(theControl, newColorTable)
#define GetCVariant(theControl) GetControlVariant(theControl)
#define getctitle(theControl, title) getcontroltitle(theControl, title)
#define setctitle(theControl, title) setcontroltitle(theControl, title)
#endif  /* OLDROUTINENAMES */

/* Getters */
/*
 *  GetControlBounds()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern Rect * 
GetControlBounds(
  ControlRef   control,
  Rect *       bounds)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IsControlHilited()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern Boolean 
IsControlHilited(ControlRef control)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlHilite()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern UInt16 
GetControlHilite(ControlRef control)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlOwner()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern WindowRef 
GetControlOwner(ControlRef control)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlDataHandle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern Handle 
GetControlDataHandle(ControlRef control)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlPopupMenuHandle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern MenuRef 
GetControlPopupMenuHandle(ControlRef control)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


#define GetControlPopupMenuRef GetControlPopupMenuHandle
/*
 *  GetControlPopupMenuID()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern short 
GetControlPopupMenuID(ControlRef control)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Setters */
/*
 *  SetControlDataHandle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern void 
SetControlDataHandle(
  ControlRef   control,
  Handle       dataHandle)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlBounds()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern void 
SetControlBounds(
  ControlRef    control,
  const Rect *  bounds)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetControlPopupMenuHandle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern void 
SetControlPopupMenuHandle(
  ControlRef   control,
  MenuRef      popupMenu)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


#define SetControlPopupMenuRef SetControlPopupMenuHandle
/*
 *  SetControlPopupMenuID()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in CarbonAccessors.o 1.0 and later
 */
extern void 
SetControlPopupMenuID(
  ControlRef   control,
  short        menuID)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __CONTROLS__ */

