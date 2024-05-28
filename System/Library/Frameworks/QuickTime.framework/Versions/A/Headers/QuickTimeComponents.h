/*
     File:       QuickTime/QuickTimeComponents.h
 
     Contains:   QuickTime Interfaces.
 
     Version:    QuickTime-174.20~22
 
     Copyright:  � 1990-2002 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __QUICKTIMECOMPONENTS__
#define __QUICKTIMECOMPONENTS__

#ifndef __CARBON__
#include <Carbon/Carbon.h>
#endif

#ifndef __IMAGECOMPRESSION__
#include <QuickTime/ImageCompression.h>
#endif

#ifndef __MOVIES__
#include <QuickTime/Movies.h>
#endif

#ifndef __QUICKTIMEMUSIC__
#include <QuickTime/QuickTimeMusic.h>
#endif



#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k

enum {
  clockComponentType            = 'clok',
  systemTickClock               = 'tick', /* subtype: 60ths since boot   */
  systemSecondClock             = 'seco', /* subtype: seconds since 1904       */
  systemMillisecondClock        = 'mill', /* subtype: 1000ths since boot       */
  systemMicrosecondClock        = 'micr' /* subtype: 1000000ths since boot */
};

enum {
  kClockRateIsLinear            = 1,
  kClockImplementsCallBacks     = 2,
  kClockCanHandleIntermittentSound = 4  /* sound clocks only */
};

#if OLDROUTINENAMES
#define GetClockTime(aClock, out) ClockGetTime(aClock, out)
#endif
/** These are Clock procedures **/
/*
 *  ClockGetTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockGetTime(
  ComponentInstance   aClock,
  TimeRecord *        out)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  ClockNewCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern QTCallBack 
ClockNewCallBack(
  ComponentInstance   aClock,
  TimeBase            tb,
  short               callBackType)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClockDisposeCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockDisposeCallBack(
  ComponentInstance   aClock,
  QTCallBack          cb)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClockCallMeWhen()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockCallMeWhen(
  ComponentInstance   aClock,
  QTCallBack          cb,
  long                param1,
  long                param2,
  long                param3)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClockCancelCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockCancelCallBack(
  ComponentInstance   aClock,
  QTCallBack          cb)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClockRateChanged()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockRateChanged(
  ComponentInstance   aClock,
  QTCallBack          cb)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClockTimeChanged()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockTimeChanged(
  ComponentInstance   aClock,
  QTCallBack          cb)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClockSetTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockSetTimeBase(
  ComponentInstance   aClock,
  TimeBase            tb)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClockStartStopChanged()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockStartStopChanged(
  ComponentInstance   aClock,
  QTCallBack          cb,
  Boolean             startChanged,
  Boolean             stopChanged)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClockGetRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
ClockGetRate(
  ComponentInstance   aClock,
  Fixed *             rate)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;





enum {
  StandardCompressionType       = 'scdi',
  StandardCompressionSubType    = 'imag',
  StandardCompressionSubTypeSound = 'soun'
};


typedef CALLBACK_API( Boolean , SCModalFilterProcPtr )(DialogRef theDialog, EventRecord *theEvent, short *itemHit, long refcon);
typedef CALLBACK_API( short , SCModalHookProcPtr )(DialogRef theDialog, short itemHit, void *params, long refcon);
typedef STACK_UPP_TYPE(SCModalFilterProcPtr)                    SCModalFilterUPP;
typedef STACK_UPP_TYPE(SCModalHookProcPtr)                      SCModalHookUPP;
/*  Preference flags.*/
enum {
  scListEveryCodec              = 1L << 1,
  scAllowZeroFrameRate          = 1L << 2,
  scAllowZeroKeyFrameRate       = 1L << 3,
  scShowBestDepth               = 1L << 4,
  scUseMovableModal             = 1L << 5,
  scDisableFrameRateItem        = 1L << 6,
  scShowDataRateAsKilobits      = 1L << 7
};


/*  Possible test flags for setting test image.*/
enum {
  scPreferCropping              = 1 << 0,
  scPreferScaling               = 1 << 1,
  scPreferScalingAndCropping    = scPreferScaling | scPreferCropping,
  scDontDetermineSettingsFromTestImage = 1 << 2
};


/*  Dimensions of the image preview box.*/
enum {
  scTestImageWidth              = 80,
  scTestImageHeight             = 80
};

/*  Possible items returned by hookProc.*/
enum {
  scOKItem                      = 1,
  scCancelItem                  = 2,
  scCustomItem                  = 3
};

/*  Result returned when user cancelled.*/
enum {
  scUserCancelled               = 1
};



/* Component selectors*/
enum {
  scPositionRect                = 2,
  scPositionDialog              = 3,
  scSetTestImagePictHandle      = 4,
  scSetTestImagePictFile        = 5,
  scSetTestImagePixMap          = 6,
  scGetBestDeviceRect           = 7,
  scRequestImageSettings        = 10,
  scCompressImage               = 11,
  scCompressPicture             = 12,
  scCompressPictureFile         = 13,
  scRequestSequenceSettings     = 14,
  scCompressSequenceBegin       = 15,
  scCompressSequenceFrame       = 16,
  scCompressSequenceEnd         = 17,
  scDefaultPictHandleSettings   = 18,
  scDefaultPictFileSettings     = 19,
  scDefaultPixMapSettings       = 20,
  scGetInfo                     = 21,
  scSetInfo                     = 22,
  scNewGWorld                   = 23
};

/*  Get/SetInfo structures.*/

struct SCSpatialSettings {
  CodecType           codecType;
  CodecComponent      codec;
  short               depth;
  CodecQ              spatialQuality;
};
typedef struct SCSpatialSettings        SCSpatialSettings;
struct SCTemporalSettings {
  CodecQ              temporalQuality;
  Fixed               frameRate;
  long                keyFrameRate;
};
typedef struct SCTemporalSettings       SCTemporalSettings;
struct SCDataRateSettings {
  long                dataRate;
  long                frameDuration;
  CodecQ              minSpatialQuality;
  CodecQ              minTemporalQuality;
};
typedef struct SCDataRateSettings       SCDataRateSettings;
struct SCExtendedProcs {
  SCModalFilterUPP    filterProc;
  SCModalHookUPP      hookProc;
  long                refcon;
  Str31               customName;
};
typedef struct SCExtendedProcs          SCExtendedProcs;
/*  Get/SetInfo selectors*/
enum {
  scSpatialSettingsType         = 'sptl', /* pointer to SCSpatialSettings struct*/
  scTemporalSettingsType        = 'tprl', /* pointer to SCTemporalSettings struct*/
  scDataRateSettingsType        = 'drat', /* pointer to SCDataRateSettings struct*/
  scColorTableType              = 'clut', /* pointer to CTabHandle*/
  scProgressProcType            = 'prog', /* pointer to ProgressRecord struct*/
  scExtendedProcsType           = 'xprc', /* pointer to SCExtendedProcs struct*/
  scPreferenceFlagsType         = 'pref', /* pointer to long*/
  scSettingsStateType           = 'ssta', /* pointer to Handle*/
  scSequenceIDType              = 'sequ', /* pointer to ImageSequence*/
  scWindowPositionType          = 'wndw', /* pointer to Point*/
  scCodecFlagsType              = 'cflg', /* pointer to CodecFlags*/
  scCodecSettingsType           = 'cdec', /* pointer to Handle*/
  scForceKeyValueType           = 'ksim', /* pointer to long*/
  scSoundSampleRateType         = 'ssrt', /* pointer to UnsignedFixed*/
  scSoundSampleSizeType         = 'ssss', /* pointer to short*/
  scSoundChannelCountType       = 'sscc', /* pointer to short*/
  scSoundCompressionType        = 'ssct', /* pointer to OSType*/
  scCompressionListType         = 'ctyl', /* pointer to OSType Handle*/
  scCodecManufacturerType       = 'cmfr', /* pointer to OSType*/
  scSoundVBRCompressionOK       = 'cvbr', /* pointer to Boolean*/
  scSoundInputSampleRateType    = 'ssir', /* pointer to UnsignedFixed*/
  scSoundSampleRateChangeOK     = 'rcok', /* pointer to Boolean*/
  scAvailableCompressionListType = 'avai' /* pointer to OSType Handle*/
};

/*  scTypeNotFoundErr returned by Get/SetInfo when type cannot be found.*/


struct SCParams {
  long                flags;
  CodecType           theCodecType;
  CodecComponent      theCodec;
  CodecQ              spatialQuality;
  CodecQ              temporalQuality;
  short               depth;
  Fixed               frameRate;
  long                keyFrameRate;
  long                reserved1;
  long                reserved2;
};
typedef struct SCParams                 SCParams;
enum {
  scGetCompression              = 1,
  scShowMotionSettings          = 1L << 0,
  scSettingsChangedItem         = -1
};

enum {
  scCompressFlagIgnoreIdenticalFrames = 1
};

/* QTAtomTypes for atoms found in settings atom containers*/
enum {
  kQTSettingsVideo              = 'vide', /* Container for video/image compression related atoms (Get/SetInfo selectors)*/
  kQTSettingsSound              = 'soun', /* Container for sound compression related atoms (Get/SetInfo selectors)*/
  kQTSettingsComponentVersion   = 'vers' /* . Version of component that wrote settings (QTSettingsVersionAtomRecord)*/
};

/* Format of 'vers' atom found in settings atom containers*/
struct QTSettingsVersionAtomRecord {
  long                componentVersion;       /* standard compression component version*/
  short               flags;                  /* low bit is 1 if little endian platform, 0 if big endian platform*/
  short               reserved;               /* should be 0*/
};
typedef struct QTSettingsVersionAtomRecord QTSettingsVersionAtomRecord;
#define SCGetCompression(ci, params, where) SCGetCompressionExtended(ci,params,where,0,0,0,0)
/** These are Progress procedures **/
/*
 *  SCGetCompressionExtended()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCGetCompressionExtended(
  ComponentInstance   ci,
  SCParams *          params,
  Point               where,
  SCModalFilterUPP    filterProc,
  SCModalHookUPP      hookProc,
  long                refcon,
  StringPtr           customName)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCPositionRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCPositionRect(
  ComponentInstance   ci,
  Rect *              rp,
  Point *             where)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCPositionDialog()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCPositionDialog(
  ComponentInstance   ci,
  short               id,
  Point *             where)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCSetTestImagePictHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCSetTestImagePictHandle(
  ComponentInstance   ci,
  PicHandle           testPict,
  Rect *              testRect,
  short               testFlags)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCSetTestImagePictFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCSetTestImagePictFile(
  ComponentInstance   ci,
  short               testFileRef,
  Rect *              testRect,
  short               testFlags)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCSetTestImagePixMap()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCSetTestImagePixMap(
  ComponentInstance   ci,
  PixMapHandle        testPixMap,
  Rect *              testRect,
  short               testFlags)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCGetBestDeviceRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCGetBestDeviceRect(
  ComponentInstance   ci,
  Rect *              r)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  SCRequestImageSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCRequestImageSettings(ComponentInstance ci)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCCompressImage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCCompressImage(
  ComponentInstance         ci,
  PixMapHandle              src,
  const Rect *              srcRect,
  ImageDescriptionHandle *  desc,
  Handle *                  data)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCCompressPicture()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCCompressPicture(
  ComponentInstance   ci,
  PicHandle           srcPicture,
  PicHandle           dstPicture)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCCompressPictureFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCCompressPictureFile(
  ComponentInstance   ci,
  short               srcRefNum,
  short               dstRefNum)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCRequestSequenceSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCRequestSequenceSettings(ComponentInstance ci)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCCompressSequenceBegin()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCCompressSequenceBegin(
  ComponentInstance         ci,
  PixMapHandle              src,
  const Rect *              srcRect,
  ImageDescriptionHandle *  desc)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCCompressSequenceFrame()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCCompressSequenceFrame(
  ComponentInstance   ci,
  PixMapHandle        src,
  const Rect *        srcRect,
  Handle *            data,
  long *              dataSize,
  short *             notSyncFlag)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCCompressSequenceEnd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCCompressSequenceEnd(ComponentInstance ci)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCDefaultPictHandleSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCDefaultPictHandleSettings(
  ComponentInstance   ci,
  PicHandle           srcPicture,
  short               motion)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCDefaultPictFileSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCDefaultPictFileSettings(
  ComponentInstance   ci,
  short               srcRef,
  short               motion)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCDefaultPixMapSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCDefaultPixMapSettings(
  ComponentInstance   ci,
  PixMapHandle        src,
  short               motion)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCGetInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCGetInfo(
  ComponentInstance   ci,
  OSType              infoType,
  void *              info)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCSetInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCSetInfo(
  ComponentInstance   ci,
  OSType              infoType,
  void *              info)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCNewGWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCNewGWorld(
  ComponentInstance   ci,
  GWorldPtr *         gwp,
  Rect *              rp,
  GWorldFlags         flags)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCSetCompressFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCSetCompressFlags(
  ComponentInstance   ci,
  long                flags)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCGetCompressFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCGetCompressFlags(
  ComponentInstance   ci,
  long *              flags)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCGetSettingsAsText()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCGetSettingsAsText(
  ComponentInstance   ci,
  Handle *            text)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCGetSettingsAsAtomContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCGetSettingsAsAtomContainer(
  ComponentInstance   ci,
  QTAtomContainer *   settings)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCSetSettingsFromAtomContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SCSetSettingsFromAtomContainer(
  ComponentInstance   ci,
  QTAtomContainer     settings)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Note: if you're using SCCompressSequenceFrameAsync with a scForceKeyValue setting, you must call SCAsyncIdle occasionally at main task time. */
/*
 *  SCCompressSequenceFrameAsync()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
SCCompressSequenceFrameAsync(
  ComponentInstance            ci,
  PixMapHandle                 src,
  const Rect *                 srcRect,
  Handle *                     data,
  long *                       dataSize,
  short *                      notSyncFlag,
  ICMCompletionProcRecordPtr   asyncCompletionProc)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SCAsyncIdle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
SCAsyncIdle(ComponentInstance ci)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;





enum {
  TweenComponentType            = 'twen'
};


typedef ComponentInstance               TweenerComponent;
/*
 *  TweenerInitialize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TweenerInitialize(
  TweenerComponent   tc,
  QTAtomContainer    container,
  QTAtom             tweenAtom,
  QTAtom             dataAtom)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TweenerDoTween()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TweenerDoTween(
  TweenerComponent   tc,
  TweenRecord *      tr)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TweenerReset()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TweenerReset(TweenerComponent tc)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




enum {
  TCSourceRefNameType           = 'name'
};

enum {
  tcDropFrame                   = 1 << 0,
  tc24HourMax                   = 1 << 1,
  tcNegTimesOK                  = 1 << 2,
  tcCounter                     = 1 << 3
};

struct TimeCodeDef {
  long                flags;                  /* drop-frame, etc.*/
  TimeScale           fTimeScale;             /* time scale of frameDuration (eg. 2997)*/
  TimeValue           frameDuration;          /* duration of each frame (eg. 100)*/
  UInt8               numFrames;              /* frames/sec for timecode (eg. 30) OR frames/tick for counter mode*/
  UInt8               padding;                /* unused padding byte*/
};
typedef struct TimeCodeDef              TimeCodeDef;
enum {
  tctNegFlag                    = 0x80  /* negative bit is in minutes*/
};

struct TimeCodeTime {
  UInt8               hours;
  UInt8               minutes;
  UInt8               seconds;
  UInt8               frames;
};
typedef struct TimeCodeTime             TimeCodeTime;
struct TimeCodeCounter {
  long                counter;
};
typedef struct TimeCodeCounter          TimeCodeCounter;
union TimeCodeRecord {
  TimeCodeTime        t;
  TimeCodeCounter     c;
};
typedef union TimeCodeRecord            TimeCodeRecord;
struct TimeCodeDescription {
  long                descSize;               /* standard sample description header*/
  long                dataFormat;
  long                resvd1;
  short               resvd2;
  short               dataRefIndex;
  long                flags;                  /* timecode specific stuff*/
  TimeCodeDef         timeCodeDef;
  long                srcRef[1];
};
typedef struct TimeCodeDescription      TimeCodeDescription;
typedef TimeCodeDescription *           TimeCodeDescriptionPtr;
typedef TimeCodeDescriptionPtr *        TimeCodeDescriptionHandle;
enum {
  tcdfShowTimeCode              = 1 << 0
};


struct TCTextOptions {
  short               txFont;
  short               txFace;
  short               txSize;
  short               pad;                    /* let's make it longword aligned - thanks.. */
  RGBColor            foreColor;
  RGBColor            backColor;
};
typedef struct TCTextOptions            TCTextOptions;
typedef TCTextOptions *                 TCTextOptionsPtr;
/*
 *  TCGetCurrentTimeCode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCGetCurrentTimeCode(
  MediaHandler      mh,
  long *            frameNum,
  TimeCodeDef *     tcdef,
  TimeCodeRecord *  tcrec,
  UserData *        srcRefH)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCGetTimeCodeAtTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCGetTimeCodeAtTime(
  MediaHandler      mh,
  TimeValue         mediaTime,
  long *            frameNum,
  TimeCodeDef *     tcdef,
  TimeCodeRecord *  tcdata,
  UserData *        srcRefH)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCTimeCodeToString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCTimeCodeToString(
  MediaHandler      mh,
  TimeCodeDef *     tcdef,
  TimeCodeRecord *  tcrec,
  StringPtr         tcStr)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCTimeCodeToFrameNumber()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCTimeCodeToFrameNumber(
  MediaHandler      mh,
  TimeCodeDef *     tcdef,
  TimeCodeRecord *  tcrec,
  long *            frameNumber)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCFrameNumberToTimeCode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCFrameNumberToTimeCode(
  MediaHandler      mh,
  long              frameNumber,
  TimeCodeDef *     tcdef,
  TimeCodeRecord *  tcrec)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCGetSourceRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCGetSourceRef(
  MediaHandler                mh,
  TimeCodeDescriptionHandle   tcdH,
  UserData *                  srefH)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCSetSourceRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCSetSourceRef(
  MediaHandler                mh,
  TimeCodeDescriptionHandle   tcdH,
  UserData                    srefH)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCSetTimeCodeFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCSetTimeCodeFlags(
  MediaHandler   mh,
  long           flags,
  long           flagsMask)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCGetTimeCodeFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCGetTimeCodeFlags(
  MediaHandler   mh,
  long *         flags)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCSetDisplayOptions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCSetDisplayOptions(
  MediaHandler       mh,
  TCTextOptionsPtr   textOptions)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TCGetDisplayOptions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern HandlerError 
TCGetDisplayOptions(
  MediaHandler       mh,
  TCTextOptionsPtr   textOptions)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




typedef ComponentInstance               MovieImportComponent;
typedef ComponentInstance               MovieExportComponent;
enum {
  MovieImportType               = 'eat ',
  MovieExportType               = 'spit'
};

enum {
  canMovieImportHandles         = 1 << 0,
  canMovieImportFiles           = 1 << 1,
  hasMovieImportUserInterface   = 1 << 2,
  canMovieExportHandles         = 1 << 3,
  canMovieExportFiles           = 1 << 4,
  hasMovieExportUserInterface   = 1 << 5,
  movieImporterIsXMLBased       = 1 << 5,
  dontAutoFileMovieImport       = 1 << 6,
  canMovieExportAuxDataHandle   = 1 << 7,
  canMovieImportValidateHandles = 1 << 8,
  canMovieImportValidateFile    = 1 << 9,
  dontRegisterWithEasyOpen      = 1 << 10,
  canMovieImportInPlace         = 1 << 11,
  movieImportSubTypeIsFileExtension = 1 << 12,
  canMovieImportPartial         = 1 << 13,
  hasMovieImportMIMEList        = 1 << 14,
  canMovieImportAvoidBlocking   = 1 << 15,
  canMovieExportFromProcedures  = 1 << 15,
  canMovieExportValidateMovie   = 1L << 16,
  movieImportMustGetDestinationMediaType = 1L << 16,
  movieExportNeedsResourceFork  = 1L << 17,
  canMovieImportDataReferences  = 1L << 18,
  movieExportMustGetSourceMediaType = 1L << 19,
  canMovieImportWithIdle        = 1L << 20,
  canMovieImportValidateDataReferences = 1L << 21,
  reservedForUseByGraphicsImporters = 1L << 23
};

enum {
  movieImportCreateTrack        = 1,
  movieImportInParallel         = 2,
  movieImportMustUseTrack       = 4,
  movieImportWithIdle           = 16
};

enum {
  movieImportResultUsedMultipleTracks = 8,
  movieImportResultNeedIdles    = 32,
  movieImportResultComplete     = 64
};

enum {
  kMovieExportTextOnly          = 0,
  kMovieExportAbsoluteTime      = 1,
  kMovieExportRelativeTime      = 2
};

enum {
  kMIDIImportSilenceBefore      = 1 << 0,
  kMIDIImportSilenceAfter       = 1 << 1,
  kMIDIImport20Playable         = 1 << 2,
  kMIDIImportWantLyrics         = 1 << 3
};


enum {
  kQTMediaConfigResourceType    = 'mcfg',
  kQTMediaConfigResourceVersion = 2,
  kQTMediaGroupResourceType     = 'mgrp',
  kQTMediaGroupResourceVersion  = 1,
  kQTBrowserInfoResourceType    = 'brws',
  kQTBrowserInfoResourceVersion = 1
};


enum {
  kQTMediaMIMEInfoHasChanged    = (1L << 1), /* the MIME type(s) is(are) new or has changed since the last time*/
                                        /*  someone asked about it*/
  kQTMediaFileInfoHasChanged    = (1L << 2), /* the file extension(s) is(are) new or has changed since the last time*/
                                        /*  anyone asked about it*/
  kQTMediaConfigCanUseApp       = (1L << 18), /* this MIME type can be configured to use app*/
  kQTMediaConfigCanUsePlugin    = (1L << 19), /* this MIME type can be configured to use plug-in*/
  kQTMediaConfigUNUSED          = (1L << 20), /* currently unused*/
  kQTMediaConfigBinaryFile      = (1L << 23), /* file should be transfered in binary mode*/
  kQTMediaConfigTextFile        = 0,    /* not a bit, defined for clarity*/
  kQTMediaConfigMacintoshFile   = (1L << 24), /* file's resource fork is significant*/
  kQTMediaConfigAssociateByDefault = (1L << 27), /* take this file association by default*/
  kQTMediaConfigUseAppByDefault = (1L << 28), /* use the app by default for this MIME type*/
  kQTMediaConfigUsePluginByDefault = (1L << 29), /* use the plug-in by default for this MIME type*/
  kQTMediaConfigDefaultsMask    = (kQTMediaConfigUseAppByDefault | kQTMediaConfigUsePluginByDefault),
  kQTMediaConfigDefaultsShift   = 12,   /* ((flags & kQTMediaConfigDefaultsMask) >> kQTMediaConfigDefaultsShift) to get default setting */
  kQTMediaConfigHasFileHasQTAtoms = (1L << 30) /* the file has a "QuickTime like" file format */
};


/* mime type group constants for groupID field of 'mcfg' resource*/
enum {
  kQTMediaConfigStreamGroupID   = 'strm',
  kQTMediaConfigInteractiveGroupID = 'intr',
  kQTMediaConfigVideoGroupID    = 'eyes',
  kQTMediaConfigAudioGroupID    = 'ears',
  kQTMediaConfigMPEGGroupID     = 'mpeg',
  kQTMediaConfigMP3GroupID      = 'mp3 ',
  kQTMediaConfigImageGroupID    = 'ogle',
  kQTMediaConfigMiscGroupID     = 'misc'
};

/* file type group constants for groupID field of 'mcfg' resource*/
enum {
  kQTMediaInfoNetGroup          = 'net ',
  kQTMediaInfoWinGroup          = 'win ',
  kQTMediaInfoMacGroup          = 'mac ',
  kQTMediaInfoMiscGroup         = 0x3F3F3F3F /* '????'*/
};



enum {
  kMimeInfoMimeTypeTag          = 'mime',
  kMimeInfoFileExtensionTag     = 'ext ',
  kMimeInfoDescriptionTag       = 'desc',
  kMimeInfoGroupTag             = 'grop',
  kMimeInfoDoNotOverrideExistingFileTypeAssociation = 'nofa'
};

enum {
  kQTFileTypeAIFF               = 'AIFF',
  kQTFileTypeAIFC               = 'AIFC',
  kQTFileTypeDVC                = 'dvc!',
  kQTFileTypeMIDI               = 'Midi',
  kQTFileTypePicture            = 'PICT',
  kQTFileTypeMovie              = 'MooV',
  kQTFileTypeText               = 'TEXT',
  kQTFileTypeWave               = 'WAVE',
  kQTFileTypeSystemSevenSound   = 'sfil',
  kQTFileTypeMuLaw              = 'ULAW',
  kQTFileTypeAVI                = 'VfW ',
  kQTFileTypeSoundDesignerII    = 'Sd2f',
  kQTFileTypeAudioCDTrack       = 'trak',
  kQTFileTypePICS               = 'PICS',
  kQTFileTypeGIF                = 'GIFf',
  kQTFileTypePNG                = 'PNGf',
  kQTFileTypeTIFF               = 'TIFF',
  kQTFileTypePhotoShop          = '8BPS',
  kQTFileTypeSGIImage           = '.SGI',
  kQTFileTypeBMP                = 'BMPf',
  kQTFileTypeJPEG               = 'JPEG',
  kQTFileTypeJFIF               = 'JPEG',
  kQTFileTypeMacPaint           = 'PNTG',
  kQTFileTypeTargaImage         = 'TPIC',
  kQTFileTypeQuickDrawGXPicture = 'qdgx',
  kQTFileTypeQuickTimeImage     = 'qtif',
  kQTFileType3DMF               = '3DMF',
  kQTFileTypeFLC                = 'FLC ',
  kQTFileTypeFlash              = 'SWFL',
  kQTFileTypeFlashPix           = 'FPix',
  kQTFileTypeMP4                = 'mpg4'
};

/* QTAtomTypes for atoms in import/export settings containers*/
enum {
  kQTSettingsDVExportNTSC       = 'dvcv', /* True is export as NTSC, false is export as PAL. (Boolean)*/
  kQTSettingsDVExportLockedAudio = 'lock', /* True if audio locked to video. (Boolean)*/
  kQTSettingsEffect             = 'effe', /* Parent atom whose contents are atoms of an effects description*/
  kQTSettingsGraphicsFileImportSequence = 'sequ', /* Parent atom of graphic file movie import component*/
  kQTSettingsGraphicsFileImportSequenceEnabled = 'enab', /* . If true, import numbered image sequence (Boolean)*/
  kQTSettingsMovieExportEnableVideo = 'envi', /* Enable exporting of video track (Boolean)*/
  kQTSettingsMovieExportEnableSound = 'enso', /* Enable exporting of sound track (Boolean)*/
  kQTSettingsMovieExportSaveOptions = 'save', /* Parent atom of save options*/
  kQTSettingsMovieExportSaveForInternet = 'fast', /* . Save for Internet*/
  kQTSettingsMovieExportSaveCompressedMovie = 'cmpm', /* . Save compressed movie resource*/
  kQTSettingsMIDI               = 'MIDI', /* MIDI import related container*/
  kQTSettingsMIDISettingFlags   = 'sttg', /* . MIDI import settings (UInt32)*/
  kQTSettingsText               = 'text', /* Text related container*/
  kQTSettingsTextDescription    = 'desc', /* . Text import settings (TextDescription record)*/
  kQTSettingsTextSize           = 'size', /* . Width/height to create during import (FixedPoint)*/
  kQTSettingsTextSettingFlags   = 'sttg', /* . Text export settings (UInt32)*/
  kQTSettingsTextTimeFraction   = 'timf', /* . Movie time fraction for export (UInt32)*/
  kQTSettingsTime               = 'time', /* Time related container*/
  kQTSettingsTimeDuration       = 'dura', /* . Time related container*/
  kQTSettingsAudioCDTrack       = 'trak', /* Audio CD track related container*/
  kQTSettingsAudioCDTrackRateShift = 'rshf', /* . Rate shift to be performed (SInt16)*/
  kQTSettingsDVExportDVFormat   = 'dvcf' /* Exported DV Format, DV('dv  ') or DVCPRO('dvp '). (OSType)*/
};




struct MovieExportGetDataParams {
  long                recordSize;

  long                trackID;

  TimeScale           sourceTimeScale;
  TimeValue           requestedTime;
  TimeValue           actualTime;

  Ptr                 dataPtr;
  long                dataSize;

  SampleDescriptionHandle  desc;
  OSType              descType;
  long                descSeed;

  long                requestedSampleCount;
  long                actualSampleCount;
  TimeValue           durationPerSample;
  long                sampleFlags;
};
typedef struct MovieExportGetDataParams MovieExportGetDataParams;
typedef CALLBACK_API( OSErr , MovieExportGetDataProcPtr )(void *refCon, MovieExportGetDataParams *params);
typedef CALLBACK_API( OSErr , MovieExportGetPropertyProcPtr )(void *refcon, long trackID, OSType propertyType, void *propertyValue);
enum {
  kQTPresetsListResourceType    = 'stg#',
  kQTPresetsPlatformListResourceType = 'stgp'
};

enum {
  kQTPresetInfoIsDivider        = 1
};

struct QTPresetInfo {
  OSType              presetKey;              /* unique key for this preset in presetsArray */
  UInt32              presetFlags;            /* flags about this preset */
  OSType              settingsResourceType;   /* resource type of settings resource */
  SInt16              settingsResourceID;     /* resource id of settings resource */
  SInt16              padding1;
  SInt16              nameStringListID;       /* name string list resource id */
  SInt16              nameStringIndex;        /* name string index */
  SInt16              infoStringListID;       /* info string list resource id */
  SInt16              infoStringIndex;        /* info string index */
};
typedef struct QTPresetInfo             QTPresetInfo;
struct QTPresetListRecord {
  UInt32              flags;                  /* flags for whole list */
  UInt32              count;                  /* number of elements in presetsArray */
  UInt32              reserved;
  QTPresetInfo        presetsArray[1];        /* info about each preset */
};
typedef struct QTPresetListRecord       QTPresetListRecord;
enum {
  kQTMovieExportSourceInfoResourceType = 'src#',
  kQTMovieExportSourceInfoIsMediaType = 1L << 0,
  kQTMovieExportSourceInfoIsMediaCharacteristic = 1L << 1,
  kQTMovieExportSourceInfoIsSourceType = 1L << 2
};

struct QTMovieExportSourceInfo {
  OSType              mediaType;              /* Media type of source */
  UInt16              minCount;               /* min number of sources of this kind required, zero if none required */
  UInt16              maxCount;               /* max number of sources of this kind allowed, -1 if unlimited allowed */
  long                flags;                  /* reserved for flags */
};
typedef struct QTMovieExportSourceInfo  QTMovieExportSourceInfo;
struct QTMovieExportSourceRecord {
  long                count;
  long                reserved;
  QTMovieExportSourceInfo  sourceArray[1];
};
typedef struct QTMovieExportSourceRecord QTMovieExportSourceRecord;
typedef STACK_UPP_TYPE(MovieExportGetDataProcPtr)               MovieExportGetDataUPP;
typedef STACK_UPP_TYPE(MovieExportGetPropertyProcPtr)           MovieExportGetPropertyUPP;
/*
 *  NewSCModalFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SCModalFilterUPP
NewSCModalFilterUPP(SCModalFilterProcPtr userRoutine)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSCModalHookUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SCModalHookUPP
NewSCModalHookUPP(SCModalHookProcPtr userRoutine)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMovieExportGetDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MovieExportGetDataUPP
NewMovieExportGetDataUPP(MovieExportGetDataProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMovieExportGetPropertyUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MovieExportGetPropertyUPP
NewMovieExportGetPropertyUPP(MovieExportGetPropertyProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSCModalFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSCModalFilterUPP(SCModalFilterUPP userUPP)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSCModalHookUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSCModalHookUPP(SCModalHookUPP userUPP)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMovieExportGetDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMovieExportGetDataUPP(MovieExportGetDataUPP userUPP)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMovieExportGetPropertyUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMovieExportGetPropertyUPP(MovieExportGetPropertyUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSCModalFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern Boolean
InvokeSCModalFilterUPP(
  DialogRef         theDialog,
  EventRecord *     theEvent,
  short *           itemHit,
  long              refcon,
  SCModalFilterUPP  userUPP)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSCModalHookUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern short
InvokeSCModalHookUPP(
  DialogRef       theDialog,
  short           itemHit,
  void *          params,
  long            refcon,
  SCModalHookUPP  userUPP)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMovieExportGetDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeMovieExportGetDataUPP(
  void *                      refCon,
  MovieExportGetDataParams *  params,
  MovieExportGetDataUPP       userUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMovieExportGetPropertyUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeMovieExportGetPropertyUPP(
  void *                     refcon,
  long                       trackID,
  OSType                     propertyType,
  void *                     propertyValue,
  MovieExportGetPropertyUPP  userUPP)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  MovieImportHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportHandle(
  MovieImportComponent   ci,
  Handle                 dataH,
  Movie                  theMovie,
  Track                  targetTrack,
  Track *                usedTrack,
  TimeValue              atTime,
  TimeValue *            addedDuration,
  long                   inFlags,
  long *                 outFlags)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportFile(
  MovieImportComponent   ci,
  const FSSpec *         theFile,
  Movie                  theMovie,
  Track                  targetTrack,
  Track *                usedTrack,
  TimeValue              atTime,
  TimeValue *            addedDuration,
  long                   inFlags,
  long *                 outFlags)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetSampleDuration()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetSampleDuration(
  MovieImportComponent   ci,
  TimeValue              duration,
  TimeScale              scale)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetSampleDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetSampleDescription(
  MovieImportComponent      ci,
  SampleDescriptionHandle   desc,
  OSType                    mediaType)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetMediaFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetMediaFile(
  MovieImportComponent   ci,
  AliasHandle            alias)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetDimensions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetDimensions(
  MovieImportComponent   ci,
  Fixed                  width,
  Fixed                  height)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetChunkSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetChunkSize(
  MovieImportComponent   ci,
  long                   chunkSize)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetProgressProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetProgressProc(
  MovieImportComponent   ci,
  MovieProgressUPP       proc,
  long                   refcon)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetAuxiliaryData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetAuxiliaryData(
  MovieImportComponent   ci,
  Handle                 data,
  OSType                 handleType)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetFromScrap()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetFromScrap(
  MovieImportComponent   ci,
  Boolean                fromScrap)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportDoUserDialog()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportDoUserDialog(
  MovieImportComponent   ci,
  const FSSpec *         theFile,
  Handle                 theData,
  Boolean *              canceled)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetDuration()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetDuration(
  MovieImportComponent   ci,
  TimeValue              duration)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportGetAuxiliaryDataType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportGetAuxiliaryDataType(
  MovieImportComponent   ci,
  OSType *               auxType)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportValidate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportValidate(
  MovieImportComponent   ci,
  const FSSpec *         theFile,
  Handle                 theData,
  Boolean *              valid)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportGetFileType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportGetFileType(
  MovieImportComponent   ci,
  OSType *               fileType)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportDataRef(
  MovieImportComponent   ci,
  Handle                 dataRef,
  OSType                 dataRefType,
  Movie                  theMovie,
  Track                  targetTrack,
  Track *                usedTrack,
  TimeValue              atTime,
  TimeValue *            addedDuration,
  long                   inFlags,
  long *                 outFlags)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportGetSampleDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportGetSampleDescription(
  MovieImportComponent       ci,
  SampleDescriptionHandle *  desc,
  OSType *                   mediaType)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportGetMIMETypeList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportGetMIMETypeList(
  MovieImportComponent   ci,
  QTAtomContainer *      mimeInfo)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetOffsetAndLimit()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetOffsetAndLimit(
  MovieImportComponent   ci,
  unsigned long          offset,
  unsigned long          limit)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportGetSettingsAsAtomContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportGetSettingsAsAtomContainer(
  MovieImportComponent   ci,
  QTAtomContainer *      settings)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetSettingsFromAtomContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieImportSetSettingsFromAtomContainer(
  MovieImportComponent   ci,
  QTAtomContainer        settings)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetOffsetAndLimit64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
MovieImportSetOffsetAndLimit64(
  MovieImportComponent   ci,
  const wide *           offset,
  const wide *           limit)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportIdle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
MovieImportIdle(
  MovieImportComponent   ci,
  long                   inFlags,
  long *                 outFlags)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportValidateDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
MovieImportValidateDataRef(
  MovieImportComponent   ci,
  Handle                 dataRef,
  OSType                 dataRefType,
  UInt8 *                valid)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportGetLoadState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieImportGetLoadState(
  MovieImportComponent   ci,
  long *                 importerLoadState)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportGetMaxLoadedTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieImportGetMaxLoadedTime(
  MovieImportComponent   ci,
  TimeValue *            time)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportEstimateCompletionTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
MovieImportEstimateCompletionTime(
  MovieImportComponent   ci,
  TimeRecord *           time)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetDontBlock()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
MovieImportSetDontBlock(
  MovieImportComponent   ci,
  Boolean                dontBlock)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportGetDontBlock()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
MovieImportGetDontBlock(
  MovieImportComponent   ci,
  Boolean *              willBlock)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieImportSetIdleManager()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
MovieImportSetIdleManager(
  MovieImportComponent   ci,
  IdleManager            im)                                  AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  MovieImportSetNewMovieFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
MovieImportSetNewMovieFlags(
  MovieImportComponent   ci,
  long                   newMovieFlags)                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  MovieImportGetDestinationMediaType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
MovieImportGetDestinationMediaType(
  MovieImportComponent   ci,
  OSType *               mediaType)                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  MovieExportToHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportToHandle(
  MovieExportComponent   ci,
  Handle                 dataH,
  Movie                  theMovie,
  Track                  onlyThisTrack,
  TimeValue              startTime,
  TimeValue              duration)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportToFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportToFile(
  MovieExportComponent   ci,
  const FSSpec *         theFile,
  Movie                  theMovie,
  Track                  onlyThisTrack,
  TimeValue              startTime,
  TimeValue              duration)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportGetAuxiliaryData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportGetAuxiliaryData(
  MovieExportComponent   ci,
  Handle                 dataH,
  OSType *               handleType)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportSetProgressProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportSetProgressProc(
  MovieExportComponent   ci,
  MovieProgressUPP       proc,
  long                   refcon)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportSetSampleDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportSetSampleDescription(
  MovieExportComponent      ci,
  SampleDescriptionHandle   desc,
  OSType                    mediaType)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportDoUserDialog()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportDoUserDialog(
  MovieExportComponent   ci,
  Movie                  theMovie,
  Track                  onlyThisTrack,
  TimeValue              startTime,
  TimeValue              duration,
  Boolean *              canceled)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportGetCreatorType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportGetCreatorType(
  MovieExportComponent   ci,
  OSType *               creator)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportToDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportToDataRef(
  MovieExportComponent   ci,
  Handle                 dataRef,
  OSType                 dataRefType,
  Movie                  theMovie,
  Track                  onlyThisTrack,
  TimeValue              startTime,
  TimeValue              duration)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportFromProceduresToDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportFromProceduresToDataRef(
  MovieExportComponent   ci,
  Handle                 dataRef,
  OSType                 dataRefType)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportAddDataSource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportAddDataSource(
  MovieExportComponent        ci,
  OSType                      trackType,
  TimeScale                   scale,
  long *                      trackID,
  MovieExportGetPropertyUPP   getPropertyProc,
  MovieExportGetDataUPP       getDataProc,
  void *                      refCon)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportValidate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportValidate(
  MovieExportComponent   ci,
  Movie                  theMovie,
  Track                  onlyThisTrack,
  Boolean *              valid)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportGetSettingsAsAtomContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportGetSettingsAsAtomContainer(
  MovieExportComponent   ci,
  QTAtomContainer *      settings)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportSetSettingsFromAtomContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportSetSettingsFromAtomContainer(
  MovieExportComponent   ci,
  QTAtomContainer        settings)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportGetFileNameExtension()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportGetFileNameExtension(
  MovieExportComponent   ci,
  OSType *               extension)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportGetShortFileTypeString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportGetShortFileTypeString(
  MovieExportComponent   ci,
  Str255                 typeString)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportGetSourceMediaType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportGetSourceMediaType(
  MovieExportComponent   ci,
  OSType *               mediaType)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportSetGetMoviePropertyProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
MovieExportSetGetMoviePropertyProc(
  MovieExportComponent        ci,
  MovieExportGetPropertyUPP   getPropertyProc,
  void *                      refCon)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Text Export Display Info data structure*/
struct TextDisplayData {
  long                displayFlags;
  long                textJustification;
  RGBColor            bgColor;
  Rect                textBox;

  short               beginHilite;
  short               endHilite;
  RGBColor            hiliteColor;
  Boolean             doHiliteColor;
  SInt8               filler;
  TimeValue           scrollDelayDur;
  Point               dropShadowOffset;
  short               dropShadowTransparency;
};
typedef struct TextDisplayData          TextDisplayData;

typedef ComponentInstance               TextExportComponent;
typedef ComponentInstance               GraphicImageMovieImportComponent;
/*
 *  TextExportGetDisplayData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextExportGetDisplayData(
  TextExportComponent   ci,
  TextDisplayData *     textDisplay)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextExportGetTimeFraction()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextExportGetTimeFraction(
  TextExportComponent   ci,
  long *                movieTimeFraction)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextExportSetTimeFraction()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextExportSetTimeFraction(
  TextExportComponent   ci,
  long                  movieTimeFraction)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextExportGetSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextExportGetSettings(
  TextExportComponent   ci,
  long *                setting)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextExportSetSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextExportSetSettings(
  TextExportComponent   ci,
  long                  setting)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  MIDIImportGetSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MIDIImportGetSettings(
  TextExportComponent   ci,
  long *                setting)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MIDIImportSetSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MIDIImportSetSettings(
  TextExportComponent   ci,
  long                  setting)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportNewGetDataAndPropertiesProcs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportNewGetDataAndPropertiesProcs(
  MovieExportComponent         ci,
  OSType                       trackType,
  TimeScale *                  scale,
  Movie                        theMovie,
  Track                        theTrack,
  TimeValue                    startTime,
  TimeValue                    duration,
  MovieExportGetPropertyUPP *  getPropertyProc,
  MovieExportGetDataUPP *      getDataProc,
  void **                      refCon)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExportDisposeGetDataAndPropertiesProcs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MovieExportDisposeGetDataAndPropertiesProcs(
  MovieExportComponent        ci,
  MovieExportGetPropertyUPP   getPropertyProc,
  MovieExportGetDataUPP       getDataProc,
  void *                      refCon)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


enum {
  movieExportUseConfiguredSettings = 'ucfg', /* pointer to Boolean*/
  movieExportWidth              = 'wdth', /* pointer to Fixed*/
  movieExportHeight             = 'hegt', /* pointer to Fixed*/
  movieExportDuration           = 'dura', /* pointer to TimeRecord*/
  movieExportVideoFilter        = 'iflt', /* pointer to QTAtomContainer*/
  movieExportTimeScale          = 'tmsc' /* pointer to TimeScale*/
};

/*
 *  GraphicsImageImportSetSequenceEnabled()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
GraphicsImageImportSetSequenceEnabled(
  GraphicImageMovieImportComponent   ci,
  Boolean                            enable)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GraphicsImageImportGetSequenceEnabled()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
GraphicsImageImportGetSequenceEnabled(
  GraphicImageMovieImportComponent   ci,
  Boolean *                          enable)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;







/*----------------------------'brws' � browser prefs configuration info ------------------------*/
enum {
  kQTBrowserInfoCanUseSystemFolderPlugin = (1L << 0) /* Mac browser can use plug-in from System "Internet Plug-ins" folder */
};




enum {
  kQTPreFlightOpenComponent     = (1L << 1) /* Open component as preflight check*/
};

struct ComponentPreflightFlags {
  long                flags;
};
typedef struct ComponentPreflightFlags  ComponentPreflightFlags;





/***************

    File Preview Components

***************/

typedef ComponentInstance               pnotComponent;
enum {
  pnotComponentWantsEvents      = 1,
  pnotComponentNeedsNoCache     = 2
};

enum {
  ShowFilePreviewComponentType  = 'pnot',
  CreateFilePreviewComponentType = 'pmak'
};

/*
 *  PreviewShowData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
PreviewShowData(
  pnotComponent   p,
  OSType          dataType,
  Handle          data,
  const Rect *    inHere)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PreviewMakePreview()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
PreviewMakePreview(
  pnotComponent              p,
  OSType *                   previewType,
  Handle *                   previewResult,
  const FSSpec *             sourceFile,
  ICMProgressProcRecordPtr   progress)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PreviewMakePreviewReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
PreviewMakePreviewReference(
  pnotComponent   p,
  OSType *        previewType,
  short *         resID,
  const FSSpec *  sourceFile)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PreviewEvent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
PreviewEvent(
  pnotComponent   p,
  EventRecord *   e,
  Boolean *       handledEvent)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




typedef ComponentInstance               DataCompressorComponent;
typedef ComponentInstance               DataDecompressorComponent;
typedef ComponentInstance               DataCodecComponent;
enum {
  DataCompressorComponentType   = 'dcom',
  DataDecompressorComponentType = 'ddec',
  AppleDataCompressorSubType    = 'adec',
  zlibDataCompressorSubType     = 'zlib'
};


/** These are DataCodec procedures **/
/*
 *  DataCodecDecompress()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataCodecDecompress(
  DataCodecComponent   dc,
  void *               srcData,
  UInt32               srcSize,
  void *               dstData,
  UInt32               dstBufferSize)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataCodecGetCompressBufferSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataCodecGetCompressBufferSize(
  DataCodecComponent   dc,
  UInt32               srcSize,
  UInt32 *             dstSize)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataCodecCompress()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataCodecCompress(
  DataCodecComponent   dc,
  void *               srcData,
  UInt32               srcSize,
  void *               dstData,
  UInt32               dstBufferSize,
  UInt32 *             actualDstSize,
  UInt32 *             decompressSlop)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataCodecBeginInterruptSafe()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataCodecBeginInterruptSafe(
  DataCodecComponent   dc,
  unsigned long        maxSrcSize)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataCodecEndInterruptSafe()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataCodecEndInterruptSafe(DataCodecComponent dc)              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataCodecDecompressPartial()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataCodecDecompressPartial(
  DataCodecComponent   dc,
  void **              next_in,
  unsigned long *      avail_in,
  unsigned long *      total_in,
  void **              next_out,
  unsigned long *      avail_out,
  unsigned long *      total_out,
  Boolean *            didFinish)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataCodecCompressPartial()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataCodecCompressPartial(
  DataCodecComponent   dc,
  void **              next_in,
  unsigned long *      avail_in,
  unsigned long *      total_in,
  void **              next_out,
  unsigned long *      avail_out,
  unsigned long *      total_out,
  Boolean              tryToFinish,
  Boolean *            didFinish)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;





typedef CALLBACK_API( void , DataHCompletionProcPtr )(Ptr request, long refcon, OSErr err);
typedef STACK_UPP_TYPE(DataHCompletionProcPtr)                  DataHCompletionUPP;

enum {
  kDataHCanRead                 = 1L << 0,
  kDataHSpecialRead             = 1L << 1,
  kDataHSpecialReadFile         = 1L << 2,
  kDataHCanWrite                = 1L << 3,
  kDataHSpecialWrite            = 1 << 4,
  kDataHSpecialWriteFile        = 1 << 5,
  kDataHCanStreamingWrite       = 1 << 6,
  kDataHMustCheckDataRef        = 1 << 7
};

/* Data reference records for specific data ref types*/
struct HandleDataRefRecord {
  Handle              dataHndl;
};
typedef struct HandleDataRefRecord      HandleDataRefRecord;
typedef HandleDataRefRecord *           HandleDataRefPtr;
typedef HandleDataRefPtr *              HandleDataRef;
struct PointerDataRefRecord {
  void *              data;
  Size                dataLength;
};
typedef struct PointerDataRefRecord     PointerDataRefRecord;
typedef PointerDataRefRecord *          PointerDataRefPtr;
typedef PointerDataRefPtr *             PointerDataRef;
/* Data reference extensions*/
enum {
  kDataRefExtensionChokeSpeed   = 'chok',
  kDataRefExtensionFileName     = 'fnam',
  kDataRefExtensionMIMEType     = 'mime',
  kDataRefExtensionMacOSFileType = 'ftyp',
  kDataRefExtensionInitializationData = 'data',
  kDataRefExtensionQuickTimeMediaType = 'mtyp'
};

enum {
  kDataHChokeToMovieDataRate    = 1 << 0, /* param is 0*/
  kDataHChokeToParam            = 1 << 1 /* param is bytes per second*/
};

struct DataHChokeAtomRecord {
  long                flags;                  /* one of kDataHChokeTo constants*/
  long                param;
};
typedef struct DataHChokeAtomRecord     DataHChokeAtomRecord;

struct DataHVolumeListRecord {
  short               vRefNum;
  long                flags;
};
typedef struct DataHVolumeListRecord    DataHVolumeListRecord;
typedef DataHVolumeListRecord *         DataHVolumeListPtr;
typedef DataHVolumeListPtr *            DataHVolumeList;
enum {
  kDataHExtendedSchedule        = 'xtnd'
};

struct DataHScheduleRecord {
  TimeRecord          timeNeededBy;
  long                extendedID;             /* always is kDataHExtendedSchedule*/
  long                extendedVers;           /* always set to 0*/
  Fixed               priority;               /* 100.0 or more means must have. lower numbers�*/
};
typedef struct DataHScheduleRecord      DataHScheduleRecord;
typedef DataHScheduleRecord *           DataHSchedulePtr;
/* Flags for DataHGetInfoFlags*/
enum {
  kDataHInfoFlagNeverStreams    = 1 << 0, /* set if this data handler doesn't stream*/
  kDataHInfoFlagCanUpdateDataRefs = 1 << 1, /* set if this data handler might update data reference*/
  kDataHInfoFlagNeedsNetworkBandwidth = 1 << 2 /* set if this data handler may need to occupy the network*/
};


/* Types for DataHGetFileTypeOrdering*/
enum {
  kDataHFileTypeMacOSFileType   = 'ftyp',
  kDataHFileTypeExtension       = 'fext',
  kDataHFileTypeMIME            = 'mime'
};

typedef OSType *                        DataHFileTypeOrderingPtr;
typedef DataHFileTypeOrderingPtr *      DataHFileTypeOrderingHandle;

/*
 *  DataHGetData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetData(
  DataHandler   dh,
  Handle        h,
  long          hOffset,
  long          offset,
  long          size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHPutData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHPutData(
  DataHandler   dh,
  Handle        h,
  long          hOffset,
  long *        offset,
  long          size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHFlushData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHFlushData(DataHandler dh)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHOpenForWrite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHOpenForWrite(DataHandler dh)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHCloseForWrite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHCloseForWrite(DataHandler dh)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  DataHOpenForRead()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHOpenForRead(DataHandler dh)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHCloseForRead()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHCloseForRead(DataHandler dh)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHSetDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHSetDataRef(
  DataHandler   dh,
  Handle        dataRef)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetDataRef(
  DataHandler   dh,
  Handle *      dataRef)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHCompareDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHCompareDataRef(
  DataHandler   dh,
  Handle        dataRef,
  Boolean *     equal)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHTask()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHTask(DataHandler dh)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHScheduleData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHScheduleData(
  DataHandler          dh,
  Ptr                  PlaceToPutDataPtr,
  long                 FileOffset,
  long                 DataSize,
  long                 RefCon,
  DataHSchedulePtr     scheduleRec,
  DataHCompletionUPP   CompletionRtn)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHFinishData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHFinishData(
  DataHandler   dh,
  Ptr           PlaceToPutDataPtr,
  Boolean       Cancel)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHFlushCache()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHFlushCache(DataHandler dh)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHResolveDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHResolveDataRef(
  DataHandler   dh,
  Handle        theDataRef,
  Boolean *     wasChanged,
  Boolean       userInterfaceAllowed)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetFileSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetFileSize(
  DataHandler   dh,
  long *        fileSize)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHCanUseDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHCanUseDataRef(
  DataHandler   dh,
  Handle        dataRef,
  long *        useFlags)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetVolumeList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetVolumeList(
  DataHandler        dh,
  DataHVolumeList *  volumeList)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHWrite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHWrite(
  DataHandler          dh,
  Ptr                  data,
  long                 offset,
  long                 size,
  DataHCompletionUPP   completion,
  long                 refCon)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHPreextend()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHPreextend(
  DataHandler      dh,
  unsigned long    maxToAdd,
  unsigned long *  spaceAdded)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHSetFileSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHSetFileSize(
  DataHandler   dh,
  long          fileSize)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetFreeSpace()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetFreeSpace(
  DataHandler      dh,
  unsigned long *  freeSize)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHCreateFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHCreateFile(
  DataHandler   dh,
  OSType        creator,
  Boolean       deleteExisting)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetPreferredBlockSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetPreferredBlockSize(
  DataHandler   dh,
  long *        blockSize)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetDeviceIndex()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetDeviceIndex(
  DataHandler   dh,
  long *        deviceIndex)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHIsStreamingDataHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHIsStreamingDataHandler(
  DataHandler   dh,
  Boolean *     yes)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetDataInBuffer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetDataInBuffer(
  DataHandler   dh,
  long          startOffset,
  long *        size)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetScheduleAheadTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetScheduleAheadTime(
  DataHandler   dh,
  long *        millisecs)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHSetCacheSizeLimit()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHSetCacheSizeLimit(
  DataHandler   dh,
  Size          cacheSizeLimit)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetCacheSizeLimit()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetCacheSizeLimit(
  DataHandler   dh,
  Size *        cacheSizeLimit)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetMovie(
  DataHandler   dh,
  Movie *       theMovie,
  short *       id)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHAddMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHAddMovie(
  DataHandler   dh,
  Movie         theMovie,
  short *       id)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHUpdateMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHUpdateMovie(
  DataHandler   dh,
  Movie         theMovie,
  short         id)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHDoesBuffer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHDoesBuffer(
  DataHandler   dh,
  Boolean *     buffersReads,
  Boolean *     buffersWrites)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetFileName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetFileName(
  DataHandler   dh,
  Str255        str)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetAvailableFileSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetAvailableFileSize(
  DataHandler   dh,
  long *        fileSize)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetMacOSFileType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetMacOSFileType(
  DataHandler   dh,
  OSType *      fileType)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetMIMEType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetMIMEType(
  DataHandler   dh,
  Str255        mimeType)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHSetDataRefWithAnchor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHSetDataRefWithAnchor(
  DataHandler   dh,
  Handle        anchorDataRef,
  OSType        dataRefType,
  Handle        dataRef)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetDataRefWithAnchor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHGetDataRefWithAnchor(
  DataHandler   dh,
  Handle        anchorDataRef,
  OSType        dataRefType,
  Handle *      dataRef)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHSetMacOSFileType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHSetMacOSFileType(
  DataHandler   dh,
  OSType        fileType)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHSetTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHSetTimeBase(
  DataHandler   dh,
  TimeBase      tb)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetInfoFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHGetInfoFlags(
  DataHandler   dh,
  UInt32 *      flags)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHScheduleData64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHScheduleData64(
  DataHandler          dh,
  Ptr                  PlaceToPutDataPtr,
  const wide *         FileOffset,
  long                 DataSize,
  long                 RefCon,
  DataHSchedulePtr     scheduleRec,
  DataHCompletionUPP   CompletionRtn)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHWrite64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHWrite64(
  DataHandler          dh,
  Ptr                  data,
  const wide *         offset,
  long                 size,
  DataHCompletionUPP   completion,
  long                 refCon)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetFileSize64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHGetFileSize64(
  DataHandler   dh,
  wide *        fileSize)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHPreextend64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHPreextend64(
  DataHandler   dh,
  const wide *  maxToAdd,
  wide *        spaceAdded)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHSetFileSize64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHSetFileSize64(
  DataHandler   dh,
  const wide *  fileSize)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetFreeSpace64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHGetFreeSpace64(
  DataHandler   dh,
  wide *        freeSize)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHAppend64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHAppend64(
  DataHandler     dh,
  void *          data,
  wide *          fileOffset,
  unsigned long   size)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHReadAsync()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHReadAsync(
  DataHandler          dh,
  void *               dataPtr,
  UInt32               dataSize,
  const wide *         dataOffset,
  DataHCompletionUPP   completion,
  long                 refCon)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHPollRead()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHPollRead(
  DataHandler   dh,
  void *        dataPtr,
  UInt32 *      dataSizeSoFar)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetDataAvailability()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHGetDataAvailability(
  DataHandler   dh,
  long          offset,
  long          len,
  long *        missing_offset,
  long *        missing_len)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetFileSizeAsync()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
DataHGetFileSizeAsync(
  DataHandler          dh,
  wide *               fileSize,
  DataHCompletionUPP   completionRtn,
  long                 refCon)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetDataRefAsType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
DataHGetDataRefAsType(
  DataHandler   dh,
  OSType        requestedType,
  Handle *      dataRef)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHSetDataRefExtension()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
DataHSetDataRefExtension(
  DataHandler   dh,
  Handle        extension,
  OSType        idType)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetDataRefExtension()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
DataHGetDataRefExtension(
  DataHandler   dh,
  Handle *      extension,
  OSType        idType)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetMovieWithFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
DataHGetMovieWithFlags(
  DataHandler   dh,
  Movie *       theMovie,
  short *       id,
  short         flags)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  DataHGetFileTypeOrdering()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
DataHGetFileTypeOrdering(
  DataHandler                    dh,
  DataHFileTypeOrderingHandle *  orderingListHandle)          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* flags for DataHCreateFileWithFlags*/
enum {
  kDataHCreateFileButDontCreateResFile = (1L << 0)
};

/*
 *  DataHCreateFileWithFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
DataHCreateFileWithFlags(
  DataHandler   dh,
  OSType        creator,
  Boolean       deleteExisting,
  UInt32        flags)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetMIMETypeAsync()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
DataHGetMIMETypeAsync(
  DataHandler          dh,
  Str255               mimeType,
  DataHCompletionUPP   completionRtn,
  long                 refCon)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHGetInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0.1 and later
 *    Windows:          in qtmlClient.lib 5.0.1 and later
 */
extern ComponentResult 
DataHGetInfo(
  DataHandler   dh,
  OSType        what,
  void *        info)                                         AVAILABLE_MAC_OS_X_VERSION_10_1_AND_LATER;


/*
 *  DataHSetIdleManager()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
DataHSetIdleManager(
  DataHandler   dh,
  IdleManager   im)                                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  DataHDeleteFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
DataHDeleteFile(DataHandler dh)                               AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


enum {
  kDataHMovieUsageDoAppendMDAT  = 1L << 0 /* if set, datahandler should append wide and mdat atoms in append call*/
};

/*
 *  DataHSetMovieUsageFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
DataHSetMovieUsageFlags(
  DataHandler   dh,
  long          flags)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



enum {
  kDataHTempUseSameDirectory    = 1L << 0, /* temp data ref should be in same directory as current data ref (vs. in temporary directory)*/
  kDataHTempUseSameVolume       = 1L << 1, /* temp data ref should be on same volume as current data ref (vs. find "best" volume)*/
  kDataHTempCreateFile          = 1L << 2, /* create the file*/
  kDataHTempOpenFile            = 1L << 3 /* open temporary file for write (kDataHTempCreateFile must be passed, too)*/
};

/*
 *  DataHUseTemporaryDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
DataHUseTemporaryDataRef(
  DataHandler   dh,
  long          inFlags)                                      AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  DataHGetTemporaryDataRefCapabilities()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
DataHGetTemporaryDataRefCapabilities(
  DataHandler   dh,
  long *        outUnderstoodFlags)                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  DataHRenameFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
DataHRenameFile(
  DataHandler   dh,
  Handle        newDataRef)                                   AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  DataHPlaybackHints()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
DataHPlaybackHints(
  DataHandler     dh,
  long            flags,
  unsigned long   minFileOffset,
  unsigned long   maxFileOffset,
  long            bytesPerSecond)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DataHPlaybackHints64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
DataHPlaybackHints64(
  DataHandler   dh,
  long          flags,
  const wide *  minFileOffset,
  const wide *  maxFileOffset,
  long          bytesPerSecond)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Symbolic constants for DataHGetDataRate*/
enum {
  kDataHGetDataRateInfiniteRate = 0x7FFFFFFF /* all the data arrived instantaneously*/
};

/*
 *  DataHGetDataRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
DataHGetDataRate(
  DataHandler   dh,
  long          flags,
  long *        bytesPerSecond)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Flags for DataHSetTimeHints*/
enum {
  kDataHSetTimeHintsSkipBandwidthRequest = 1 << 0 /* set if this data handler should use the network without requesting bandwidth*/
};

/*
 *  DataHSetTimeHints()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
DataHSetTimeHints(
  DataHandler   dh,
  long          flags,
  long          bandwidthPriority,
  TimeScale     scale,
  TimeValue     minTime,
  TimeValue     maxTime)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;






/* Standard type for video digitizers */
enum {
  videoDigitizerComponentType   = 'vdig',
  vdigInterfaceRev              = 2
};

/* Input Format Standards */
enum {
  ntscIn                        = 0,    /* current input format */
  currentIn                     = 0,    /* ntsc input format */
  palIn                         = 1,    /* pal input format */
  secamIn                       = 2,    /* secam input format */
  ntscReallyIn                  = 3     /* ntsc input format */
};

/* Input Formats */
enum {
  compositeIn                   = 0,    /* input is composite format */
  sVideoIn                      = 1,    /* input is sVideo format */
  rgbComponentIn                = 2,    /* input is rgb component format */
  rgbComponentSyncIn            = 3,    /* input is rgb component format (sync on green?)*/
  yuvComponentIn                = 4,    /* input is yuv component format */
  yuvComponentSyncIn            = 5,    /* input is yuv component format (sync on green?) */
  tvTunerIn                     = 6,
  sdiIn                         = 7
};


/* Video Digitizer PlayThru States */
enum {
  vdPlayThruOff                 = 0,
  vdPlayThruOn                  = 1
};

/* Input Color Space Modes */
enum {
  vdDigitizerBW                 = 0,    /* black and white */
  vdDigitizerRGB                = 1     /* rgb color */
};

/* Phase Lock Loop Modes */
enum {
  vdBroadcastMode               = 0,    /* Broadcast / Laser Disk video mode */
  vdVTRMode                     = 1     /* VCR / Magnetic media mode */
};

/* Field Select Options */
enum {
  vdUseAnyField                 = 0,    /* Digitizers choice on field use */
  vdUseOddField                 = 1,    /* Use odd field for half size vert and smaller */
  vdUseEvenField                = 2     /* Use even field for half size vert and smaller */
};

/* vdig types */
enum {
  vdTypeBasic                   = 0,    /* basic, no clipping */
  vdTypeAlpha                   = 1,    /* supports clipping with alpha channel */
  vdTypeMask                    = 2,    /* supports clipping with mask plane */
  vdTypeKey                     = 3     /* supports clipping with key color(s) */
};



/* Digitizer Input Capability/Current Flags */
enum {
  digiInDoesNTSC                = 1L << 0, /* digitizer supports NTSC input format */
  digiInDoesPAL                 = 1L << 1, /* digitizer supports PAL input format */
  digiInDoesSECAM               = 1L << 2, /* digitizer supports SECAM input format */
  digiInDoesGenLock             = 1L << 7, /* digitizer does genlock */
  digiInDoesComposite           = 1L << 8, /* digitizer supports composite input type */
  digiInDoesSVideo              = 1L << 9, /* digitizer supports S-Video input type */
  digiInDoesComponent           = 1L << 10, /* digitizer supports component = rgb, input type */
  digiInVTR_Broadcast           = 1L << 11, /* digitizer can differentiate between the two */
  digiInDoesColor               = 1L << 12, /* digitizer supports color */
  digiInDoesBW                  = 1L << 13, /* digitizer supports black & white */
                                        /* Digitizer Input Current Flags = these are valid only during active operating conditions,   */
  digiInSignalLock              = 1L << 31 /* digitizer detects input signal is locked, this bit = horiz lock || vertical lock */
};


/* Digitizer Output Capability/Current Flags */
enum {
  digiOutDoes1                  = 1L << 0, /* digitizer supports 1 bit pixels */
  digiOutDoes2                  = 1L << 1, /* digitizer supports 2 bit pixels */
  digiOutDoes4                  = 1L << 2, /* digitizer supports 4 bit pixels */
  digiOutDoes8                  = 1L << 3, /* digitizer supports 8 bit pixels */
  digiOutDoes16                 = 1L << 4, /* digitizer supports 16 bit pixels */
  digiOutDoes32                 = 1L << 5, /* digitizer supports 32 bit pixels */
  digiOutDoesDither             = 1L << 6, /* digitizer dithers in indexed modes */
  digiOutDoesStretch            = 1L << 7, /* digitizer can arbitrarily stretch */
  digiOutDoesShrink             = 1L << 8, /* digitizer can arbitrarily shrink */
  digiOutDoesMask               = 1L << 9, /* digitizer can mask to clipping regions */
  digiOutDoesDouble             = 1L << 11, /* digitizer can stretch to exactly double size */
  digiOutDoesQuad               = 1L << 12, /* digitizer can stretch exactly quadruple size */
  digiOutDoesQuarter            = 1L << 13, /* digitizer can shrink to exactly quarter size */
  digiOutDoesSixteenth          = 1L << 14, /* digitizer can shrink to exactly sixteenth size */
  digiOutDoesRotate             = 1L << 15, /* digitizer supports rotate transformations */
  digiOutDoesHorizFlip          = 1L << 16, /* digitizer supports horizontal flips Sx < 0 */
  digiOutDoesVertFlip           = 1L << 17, /* digitizer supports vertical flips Sy < 0 */
  digiOutDoesSkew               = 1L << 18, /* digitizer supports skew = shear,twist, */
  digiOutDoesBlend              = 1L << 19,
  digiOutDoesWarp               = 1L << 20,
  digiOutDoesHW_DMA             = 1L << 21, /* digitizer not constrained to local device */
  digiOutDoesHWPlayThru         = 1L << 22, /* digitizer doesn't need time to play thru */
  digiOutDoesILUT               = 1L << 23, /* digitizer does inverse LUT for index modes */
  digiOutDoesKeyColor           = 1L << 24, /* digitizer does key color functions too */
  digiOutDoesAsyncGrabs         = 1L << 25, /* digitizer supports async grabs */
  digiOutDoesUnreadableScreenBits = 1L << 26, /* playthru doesn't generate readable bits on screen*/
  digiOutDoesCompress           = 1L << 27, /* supports alternate output data types */
  digiOutDoesCompressOnly       = 1L << 28, /* can't provide raw frames anywhere */
  digiOutDoesPlayThruDuringCompress = 1L << 29, /* digi can do playthru while providing compressed data */
  digiOutDoesCompressPartiallyVisible = 1L << 30, /* digi doesn't need all bits visible on screen to do hardware compress */
  digiOutDoesNotNeedCopyOfCompressData = 1L << 31 /* digi doesn't need any bufferization when providing compressed data */
};

/* Types */
typedef ComponentInstance               VideoDigitizerComponent;
typedef ComponentResult                 VideoDigitizerError;
struct DigitizerInfo {
  short               vdigType;
  long                inputCapabilityFlags;
  long                outputCapabilityFlags;
  long                inputCurrentFlags;
  long                outputCurrentFlags;
  short               slot;                   /* temporary for connection purposes */
  GDHandle            gdh;                    /* temporary for digitizers that have preferred screen */
  GDHandle            maskgdh;                /* temporary for digitizers that have mask planes */
  short               minDestHeight;          /* Smallest resizable height */
  short               minDestWidth;           /* Smallest resizable width */
  short               maxDestHeight;          /* Largest resizable height */
  short               maxDestWidth;           /* Largest resizable width */
  short               blendLevels;            /* Number of blend levels supported (2 if 1 bit mask) */
  long                reserved;               /* reserved */
};
typedef struct DigitizerInfo            DigitizerInfo;
struct VdigType {
  long                digType;
  long                reserved;
};
typedef struct VdigType                 VdigType;
struct VdigTypeList {
  short               count;
  VdigType            list[1];
};
typedef struct VdigTypeList             VdigTypeList;
struct VdigBufferRec {
  PixMapHandle        dest;
  Point               location;
  long                reserved;
};
typedef struct VdigBufferRec            VdigBufferRec;
struct VdigBufferRecList {
  short               count;
  MatrixRecordPtr     matrix;
  RgnHandle           mask;
  VdigBufferRec       list[1];
};
typedef struct VdigBufferRecList        VdigBufferRecList;
typedef VdigBufferRecList *             VdigBufferRecListPtr;
typedef VdigBufferRecListPtr *          VdigBufferRecListHandle;
typedef CALLBACK_API( void , VdigIntProcPtr )(long flags, long refcon);
typedef STACK_UPP_TYPE(VdigIntProcPtr)                          VdigIntUPP;
struct VDCompressionList {
  CodecComponent      codec;
  CodecType           cType;
  Str63               typeName;
  Str63               name;
  long                formatFlags;
  long                compressFlags;
  long                reserved;
};
typedef struct VDCompressionList        VDCompressionList;
typedef VDCompressionList *             VDCompressionListPtr;
typedef VDCompressionListPtr *          VDCompressionListHandle;
enum {
  dmaDepth1                     = 1,
  dmaDepth2                     = 2,
  dmaDepth4                     = 4,
  dmaDepth8                     = 8,
  dmaDepth16                    = 16,
  dmaDepth32                    = 32,
  dmaDepth2Gray                 = 64,
  dmaDepth4Gray                 = 128,
  dmaDepth8Gray                 = 256
};

enum {
  kVDIGControlledFrameRate      = -1
};


/*
 *  VDGetMaxSrcRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetMaxSrcRect(
  VideoDigitizerComponent   ci,
  short                     inputStd,
  Rect *                    maxSrcRect)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetActiveSrcRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetActiveSrcRect(
  VideoDigitizerComponent   ci,
  short                     inputStd,
  Rect *                    activeSrcRect)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetDigitizerRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetDigitizerRect(
  VideoDigitizerComponent   ci,
  Rect *                    digitizerRect)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetDigitizerRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetDigitizerRect(
  VideoDigitizerComponent   ci,
  Rect *                    digitizerRect)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetVBlankRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetVBlankRect(
  VideoDigitizerComponent   ci,
  short                     inputStd,
  Rect *                    vBlankRect)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetMaskPixMap()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetMaskPixMap(
  VideoDigitizerComponent   ci,
  PixMapHandle              maskPixMap)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetPlayThruDestination()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetPlayThruDestination(
  VideoDigitizerComponent   ci,
  PixMapHandle *            dest,
  Rect *                    destRect,
  MatrixRecord *            m,
  RgnHandle *               mask)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDUseThisCLUT()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDUseThisCLUT(
  VideoDigitizerComponent   ci,
  CTabHandle                colorTableHandle)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetInputGammaValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetInputGammaValue(
  VideoDigitizerComponent   ci,
  Fixed                     channel1,
  Fixed                     channel2,
  Fixed                     channel3)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetInputGammaValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetInputGammaValue(
  VideoDigitizerComponent   ci,
  Fixed *                   channel1,
  Fixed *                   channel2,
  Fixed *                   channel3)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetBrightness()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetBrightness(
  VideoDigitizerComponent   ci,
  unsigned short *          brightness)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetBrightness()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetBrightness(
  VideoDigitizerComponent   ci,
  unsigned short *          brightness)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetContrast()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetContrast(
  VideoDigitizerComponent   ci,
  unsigned short *          contrast)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetHue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetHue(
  VideoDigitizerComponent   ci,
  unsigned short *          hue)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetSharpness()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetSharpness(
  VideoDigitizerComponent   ci,
  unsigned short *          sharpness)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetSaturation()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetSaturation(
  VideoDigitizerComponent   ci,
  unsigned short *          saturation)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetContrast()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetContrast(
  VideoDigitizerComponent   ci,
  unsigned short *          contrast)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetHue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetHue(
  VideoDigitizerComponent   ci,
  unsigned short *          hue)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetSharpness()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetSharpness(
  VideoDigitizerComponent   ci,
  unsigned short *          sharpness)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetSaturation()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetSaturation(
  VideoDigitizerComponent   ci,
  unsigned short *          saturation)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGrabOneFrame()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGrabOneFrame(VideoDigitizerComponent ci)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetMaxAuxBuffer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetMaxAuxBuffer(
  VideoDigitizerComponent   ci,
  PixMapHandle *            pm,
  Rect *                    r)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetDigitizerInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetDigitizerInfo(
  VideoDigitizerComponent   ci,
  DigitizerInfo *           info)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetCurrentFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetCurrentFlags(
  VideoDigitizerComponent   ci,
  long *                    inputCurrentFlag,
  long *                    outputCurrentFlag)                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetKeyColor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetKeyColor(
  VideoDigitizerComponent   ci,
  long                      index)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetKeyColor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetKeyColor(
  VideoDigitizerComponent   ci,
  long *                    index)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDAddKeyColor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDAddKeyColor(
  VideoDigitizerComponent   ci,
  long *                    index)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetNextKeyColor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetNextKeyColor(
  VideoDigitizerComponent   ci,
  long                      index)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetKeyColorRange()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetKeyColorRange(
  VideoDigitizerComponent   ci,
  RGBColor *                minRGB,
  RGBColor *                maxRGB)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetKeyColorRange()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetKeyColorRange(
  VideoDigitizerComponent   ci,
  RGBColor *                minRGB,
  RGBColor *                maxRGB)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetDigitizerUserInterrupt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetDigitizerUserInterrupt(
  VideoDigitizerComponent   ci,
  long                      flags,
  VdigIntUPP                userInterruptProc,
  long                      refcon)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetInputColorSpaceMode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetInputColorSpaceMode(
  VideoDigitizerComponent   ci,
  short                     colorSpaceMode)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetInputColorSpaceMode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetInputColorSpaceMode(
  VideoDigitizerComponent   ci,
  short *                   colorSpaceMode)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetClipState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetClipState(
  VideoDigitizerComponent   ci,
  short                     clipEnable)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetClipState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetClipState(
  VideoDigitizerComponent   ci,
  short *                   clipEnable)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetClipRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetClipRgn(
  VideoDigitizerComponent   ci,
  RgnHandle                 clipRegion)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDClearClipRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDClearClipRgn(
  VideoDigitizerComponent   ci,
  RgnHandle                 clipRegion)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetCLUTInUse()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetCLUTInUse(
  VideoDigitizerComponent   ci,
  CTabHandle *              colorTableHandle)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetPLLFilterType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetPLLFilterType(
  VideoDigitizerComponent   ci,
  short                     pllType)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetPLLFilterType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetPLLFilterType(
  VideoDigitizerComponent   ci,
  short *                   pllType)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetMaskandValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetMaskandValue(
  VideoDigitizerComponent   ci,
  unsigned short            blendLevel,
  long *                    mask,
  long *                    value)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetMasterBlendLevel()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetMasterBlendLevel(
  VideoDigitizerComponent   ci,
  unsigned short *          blendLevel)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetPlayThruDestination()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetPlayThruDestination(
  VideoDigitizerComponent   ci,
  PixMapHandle              dest,
  RectPtr                   destRect,
  MatrixRecordPtr           m,
  RgnHandle                 mask)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetPlayThruOnOff()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetPlayThruOnOff(
  VideoDigitizerComponent   ci,
  short                     state)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetFieldPreference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetFieldPreference(
  VideoDigitizerComponent   ci,
  short                     fieldFlag)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetFieldPreference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetFieldPreference(
  VideoDigitizerComponent   ci,
  short *                   fieldFlag)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDPreflightDestination()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDPreflightDestination(
  VideoDigitizerComponent   ci,
  Rect *                    digitizerRect,
  PixMap **                 dest,
  RectPtr                   destRect,
  MatrixRecordPtr           m)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDPreflightGlobalRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDPreflightGlobalRect(
  VideoDigitizerComponent   ci,
  GrafPtr                   theWindow,
  Rect *                    globalRect)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetPlayThruGlobalRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetPlayThruGlobalRect(
  VideoDigitizerComponent   ci,
  GrafPtr                   theWindow,
  Rect *                    globalRect)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetInputGammaRecord()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetInputGammaRecord(
  VideoDigitizerComponent   ci,
  VDGamRecPtr               inputGammaPtr)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetInputGammaRecord()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetInputGammaRecord(
  VideoDigitizerComponent   ci,
  VDGamRecPtr *             inputGammaPtr)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetBlackLevelValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetBlackLevelValue(
  VideoDigitizerComponent   ci,
  unsigned short *          blackLevel)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetBlackLevelValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetBlackLevelValue(
  VideoDigitizerComponent   ci,
  unsigned short *          blackLevel)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetWhiteLevelValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetWhiteLevelValue(
  VideoDigitizerComponent   ci,
  unsigned short *          whiteLevel)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetWhiteLevelValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetWhiteLevelValue(
  VideoDigitizerComponent   ci,
  unsigned short *          whiteLevel)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetVideoDefaults()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetVideoDefaults(
  VideoDigitizerComponent   ci,
  unsigned short *          blackLevel,
  unsigned short *          whiteLevel,
  unsigned short *          brightness,
  unsigned short *          hue,
  unsigned short *          saturation,
  unsigned short *          contrast,
  unsigned short *          sharpness)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetNumberOfInputs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetNumberOfInputs(
  VideoDigitizerComponent   ci,
  short *                   inputs)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetInputFormat()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetInputFormat(
  VideoDigitizerComponent   ci,
  short                     input,
  short *                   format)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetInput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetInput(
  VideoDigitizerComponent   ci,
  short                     input)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetInput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetInput(
  VideoDigitizerComponent   ci,
  short *                   input)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetInputStandard()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetInputStandard(
  VideoDigitizerComponent   ci,
  short                     inputStandard)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetupBuffers()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetupBuffers(
  VideoDigitizerComponent   ci,
  VdigBufferRecListHandle   bufferList)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGrabOneFrameAsync()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGrabOneFrameAsync(
  VideoDigitizerComponent   ci,
  short                     buffer)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDDone()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDDone(
  VideoDigitizerComponent   ci,
  short                     buffer)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetCompression()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetCompression(
  VideoDigitizerComponent   ci,
  OSType                    compressType,
  short                     depth,
  Rect *                    bounds,
  CodecQ                    spatialQuality,
  CodecQ                    temporalQuality,
  long                      keyFrameRate)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDCompressOneFrameAsync()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDCompressOneFrameAsync(VideoDigitizerComponent ci)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*    Note that UInt8* queuedFrameCount replaces Boolean* done. 0(==false) still means no frames, and 1(==true) one, 
    but if more than one are available the number should be returned here. The value 2 previously meant more than one frame,
    so some VDIGs may return 2 even if more than 2 are available, and some will still return 1 as they are using the original definition */
/*
 *  VDCompressDone()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDCompressDone(
  VideoDigitizerComponent   ci,
  UInt8 *                   queuedFrameCount,
  Ptr *                     theData,
  long *                    dataSize,
  UInt8 *                   similarity,
  TimeRecord *              t)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDReleaseCompressBuffer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDReleaseCompressBuffer(
  VideoDigitizerComponent   ci,
  Ptr                       bufferAddr)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetImageDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetImageDescription(
  VideoDigitizerComponent   ci,
  ImageDescriptionHandle    desc)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDResetCompressSequence()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDResetCompressSequence(VideoDigitizerComponent ci)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetCompressionOnOff()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetCompressionOnOff(
  VideoDigitizerComponent   ci,
  Boolean                   state)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetCompressionTypes()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetCompressionTypes(
  VideoDigitizerComponent   ci,
  VDCompressionListHandle   h)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetTimeBase(
  VideoDigitizerComponent   ci,
  TimeBase                  t)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetFrameRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetFrameRate(
  VideoDigitizerComponent   ci,
  Fixed                     framesPerSecond)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetDataRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetDataRate(
  VideoDigitizerComponent   ci,
  long *                    milliSecPerFrame,
  Fixed *                   framesPerSecond,
  long *                    bytesPerSecond)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetSoundInputDriver()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetSoundInputDriver(
  VideoDigitizerComponent   ci,
  Str255                    soundDriverName)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetDMADepths()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetDMADepths(
  VideoDigitizerComponent   ci,
  long *                    depthArray,
  long *                    preferredDepth)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetPreferredTimeScale()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetPreferredTimeScale(
  VideoDigitizerComponent   ci,
  TimeScale *               preferred)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDReleaseAsyncBuffers()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDReleaseAsyncBuffers(VideoDigitizerComponent ci)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* 83 is reserved for compatibility reasons */
/*
 *  VDSetDataRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetDataRate(
  VideoDigitizerComponent   ci,
  long                      bytesPerSecond)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetTimeCode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetTimeCode(
  VideoDigitizerComponent   ci,
  TimeRecord *              atTime,
  void *                    timeCodeFormat,
  void *                    timeCodeTime)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDUseSafeBuffers()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDUseSafeBuffers(
  VideoDigitizerComponent   ci,
  Boolean                   useSafeBuffers)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetSoundInputSource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetSoundInputSource(
  VideoDigitizerComponent   ci,
  long                      videoInput,
  long *                    soundInput)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetCompressionTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetCompressionTime(
  VideoDigitizerComponent   ci,
  OSType                    compressionType,
  short                     depth,
  Rect *                    srcRect,
  CodecQ *                  spatialQuality,
  CodecQ *                  temporalQuality,
  unsigned long *           compressTime)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetPreferredPacketSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetPreferredPacketSize(
  VideoDigitizerComponent   ci,
  long                      preferredPacketSizeInBytes)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetPreferredImageDimensions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetPreferredImageDimensions(
  VideoDigitizerComponent   ci,
  long                      width,
  long                      height)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetPreferredImageDimensions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetPreferredImageDimensions(
  VideoDigitizerComponent   ci,
  long *                    width,
  long *                    height)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDGetInputName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDGetInputName(
  VideoDigitizerComponent   ci,
  long                      videoInput,
  Str255                    name)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VDSetDestinationPort()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern VideoDigitizerError 
VDSetDestinationPort(
  VideoDigitizerComponent   ci,
  CGrafPtr                  destPort)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
   The following call is designed to give the VDIG a little more control over how it is presented to the User, to clarify the 
   distinction between Devices and Inputs. Historically, the assumption has been that there is one component registered per device
   and the component name is displayed. This change lets a component choose its name after registration.
   vdDeviceFlagShowInputsAsDevices is meant for components that register once and support multiple devices 
   The UI is clearer if these are presented as device rather than inputs, 
   and this allows a VDIG to present itself this way without huge restructuring
   vdDeviceFlagHideDevice is for the kind of VDIG that registers itself, and then can register a further VDIG for each device. 
   If no hardware is available, returning this flag will omit it from the list. 
   This call being made is also a good time to check for hardware and register further VDIG components if needed, 
   allowing for lazy initialization when the Application needs to find a VDIG rather than on every launch or replug.
*/

enum {
  vdDeviceFlagShowInputsAsDevices = (1 << 0), /* Tell the Panel to promote Inputs to Devices*/
  vdDeviceFlagHideDevice        = (1 << 1) /* Omit this Device entirely from the list*/
};

/*
 *  VDGetDeviceNameAndFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern VideoDigitizerError 
VDGetDeviceNameAndFlags(
  VideoDigitizerComponent   ci,
  Str255                    outName,
  UInt32 *                  outNameFlags)                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


enum {
  vdFlagCaptureStarting         = (1 << 0), /* Capture is about to start; allocate bandwidth */
  vdFlagCaptureStopping         = (1 << 1), /* Capture is about to stop; stop queuing frames*/
  vdFlagCaptureIsForPreview     = (1 << 2), /* Capture is just to screen for preview purposes*/
  vdFlagCaptureIsForRecord      = (1 << 3), /* Capture is going to be recorded*/
  vdFlagCaptureLowLatency       = (1 << 4), /* Fresh frames are more important than delivering every frame - don't queue too much*/
  vdFlagCaptureAlwaysUseTimeBase = (1 << 5), /* Use the timebase for every frame; don't worry about making durations uniform*/
  vdFlagCaptureSetSettingsBegin = (1 << 6), /* A series of calls are about to be made to restore settings.*/
  vdFlagCaptureSetSettingsEnd   = (1 << 7) /* Finished restoring settings; any set calls after this are from the app or UI*/
};

/*
 *  VDCaptureStateChanging()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern VideoDigitizerError 
VDCaptureStateChanging(
  VideoDigitizerComponent   ci,
  UInt32                    inStateFlags)                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
   These UniqueID calls are so that the VDIG can give the SG information enabling it to restore a particular
   configuration - choose a particular device and input from those available.
   For example, restoring the specific camera for a set of several hot-plugged FireWire cameras 
   the caller can pass nil if it is not interested in one of the IDs
   returning 0 in an ID means you don't have one
*/

/*
 *  VDGetUniqueIDs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern VideoDigitizerError 
VDGetUniqueIDs(
  VideoDigitizerComponent   ci,
  UInt64 *                  outDeviceID,
  UInt64 *                  outInputID)                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
   Note this is a 'Select' not a 'Set' - the assumption is that the Unique ID is a function of the hardware
   and not modifiable by the calling application. Either a nil pointer or 0 an the ID means don't care.
   return vdDontHaveThatUniqueIDErr if your device doesn't have a match.
*/

/*
 *  VDSelectUniqueIDs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern VideoDigitizerError 
VDSelectUniqueIDs(
  VideoDigitizerComponent   ci,
  const UInt64 *            inDeviceID,
  const UInt64 *            inInputID)                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;





enum {
  xmlParseComponentType         = 'pars',
  xmlParseComponentSubType      = 'xml '
};

enum {
  xmlIdentifierInvalid          = 0,
  xmlIdentifierUnrecognized     = (long)0xFFFFFFFF,
  xmlContentTypeInvalid         = 0,
  xmlContentTypeElement         = 1,
  xmlContentTypeCharData        = 2
};

enum {
  elementFlagAlwaysSelfContained = 1L << 0, /*    Element doesn't have contents or closing tag even if it doesn't end with />, as in the HTML <img> tag*/
  elementFlagPreserveWhiteSpace = 1L << 1, /*  Preserve whitespace in content, default is to remove it */
  xmlParseFlagAllowUppercase    = 1L << 0, /*    Entities and attributes do not have to be lowercase (strict XML), but can be upper or mixed case as in HTML*/
  xmlParseFlagAllowUnquotedAttributeValues = 1L << 1, /*    Attributes values do not have to be enclosed in quotes (strict XML), but can be left unquoted if they contain no spaces*/
  xmlParseFlagEventParseOnly    = 1L << 2 /*    Do event parsing only*/
};

enum {
  attributeValueKindCharString  = 0,
  attributeValueKindInteger     = 1L << 0, /*    Number*/
  attributeValueKindPercent     = 1L << 1, /*    Number or percent*/
  attributeValueKindBoolean     = 1L << 2, /*    "true" or "false"*/
  attributeValueKindOnOff       = 1L << 3, /*    "on" or "off"*/
  attributeValueKindColor       = 1L << 4, /*    Either "#rrggbb" or a color name*/
  attributeValueKindEnum        = 1L << 5, /*    one of a number of strings; the enum strings are passed as a zero-separated, double-zero-terminated C string in the attributeKindValueInfo param*/
  attributeValueKindCaseSensEnum = 1L << 6, /*    one of a number of strings; the enum strings are passed as for attributeValueKindEnum, but the values are case-sensitive*/
  MAX_ATTRIBUTE_VALUE_KIND      = attributeValueKindCaseSensEnum
};

enum {
  nameSpaceIDNone               = 0
};

/*  A Parsed XML attribute value, one of number/percent, boolean/on-off, color, or enumerated type*/
union XMLAttributeValue {
  SInt32              number;                 /*    The value when valueKind is attributeValueKindInteger or attributeValueKindPercent*/
  Boolean             boolean;                /*    The value when valueKind is attributeValueKindBoolean or attributeValueKindOnOff*/
  RGBColor            color;                  /*    The value when valueKind is attributeValueKindColor*/
  UInt32              enumType;               /*    The value when valueKind is attributeValueKindEnum*/
};
typedef union XMLAttributeValue         XMLAttributeValue;
/*  An XML attribute-value pair*/
struct XMLAttribute {
  UInt32              identifier;             /*    Tokenized identifier, if the attribute name was recognized by the parser*/
  char *              name;                   /*    Attribute name, Only present if identifier == xmlIdentifierUnrecognized*/
  long                valueKind;              /*    Type of parsed value, if the value was recognized and parsed; otherwise, attributeValueKindCharString*/
  XMLAttributeValue   value;                  /*    Parsed attribute value*/
  char *              valueStr;               /*    Always present*/
};
typedef struct XMLAttribute             XMLAttribute;
typedef XMLAttribute *                  XMLAttributePtr;
/*  Forward struct declarations for recursively-defined tree structure*/
typedef struct XMLContent               XMLContent;
typedef XMLContent *                    XMLContentPtr;
/*
    An XML Element, i.e.
        <element attr="value" attr="value" ...> [contents] </element>
    or
        <element attr="value" attr="value" .../>
*/
struct XMLElement {
  UInt32              identifier;             /*    Tokenized identifier, if the element name was recognized by the parser*/
  char *              name;                   /*    Element name, only present if identifier == xmlIdentifierUnrecognized*/
  XMLAttributePtr     attributes;             /*    Array of attributes, terminated with an attribute with identifier == xmlIdentifierInvalid*/
  XMLContentPtr       contents;               /*    Array of contents, terminated with a content with kind == xmlIdentifierInvalid*/
};
typedef struct XMLElement               XMLElement;
typedef XMLElement *                    XMLElementPtr;
/*
    The content of an XML element is a series of parts, each of which may be either another element
    or simply character data.
*/
union XMLElementContent {
  XMLElement          element;                /*    The contents when the content kind is xmlContentTypeElement*/
  char *              charData;               /*    The contents when the content kind is xmlContentTypeCharData*/
};
typedef union XMLElementContent         XMLElementContent;
struct XMLContent {
  UInt32              kind;
  XMLElementContent   actualContent;
};

struct XMLDocRecord {
  void *              xmlDataStorage;         /*    opaque storage*/
  XMLElement          rootElement;
};
typedef struct XMLDocRecord             XMLDocRecord;
typedef XMLDocRecord *                  XMLDoc;
/*callback routines for event parsing*/
typedef CALLBACK_API( ComponentResult , StartDocumentHandler )(long refcon);
typedef CALLBACK_API( ComponentResult , EndDocumentHandler )(long refcon);
typedef CALLBACK_API( ComponentResult , StartElementHandler )(const char *name, const char **atts, long refcon);
typedef CALLBACK_API( ComponentResult , EndElementHandler )(const char *name, long refcon);
typedef CALLBACK_API( ComponentResult , CharDataHandler )(const char *charData, long refcon);
typedef CALLBACK_API( ComponentResult , PreprocessInstructionHandler )(const char *name, const char *const atts[], long refcon);
typedef CALLBACK_API( ComponentResult , CommentHandler )(const char *comment, long refcon);
typedef CALLBACK_API( ComponentResult , CDataHandler )(const char *cdata, long refcon);
typedef STACK_UPP_TYPE(StartDocumentHandler)                    StartDocumentHandlerUPP;
typedef STACK_UPP_TYPE(EndDocumentHandler)                      EndDocumentHandlerUPP;
typedef STACK_UPP_TYPE(StartElementHandler)                     StartElementHandlerUPP;
typedef STACK_UPP_TYPE(EndElementHandler)                       EndElementHandlerUPP;
typedef STACK_UPP_TYPE(CharDataHandler)                         CharDataHandlerUPP;
typedef STACK_UPP_TYPE(PreprocessInstructionHandler)            PreprocessInstructionHandlerUPP;
typedef STACK_UPP_TYPE(CommentHandler)                          CommentHandlerUPP;
typedef STACK_UPP_TYPE(CDataHandler)                            CDataHandlerUPP;
/*  Parses the XML file pointed to by dataRef, returning a XMLDoc parse tree*/
/*
 *  XMLParseDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseDataRef(
  ComponentInstance   aParser,
  Handle              dataRef,
  OSType              dataRefType,
  long                parseFlags,
  XMLDoc *            document)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Parses the XML file pointed to by fileSpec, returning a XMLDoc parse tree*/
/*
 *  XMLParseFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseFile(
  ComponentInstance   aParser,
  ConstFSSpecPtr      fileSpec,
  long                parseFlags,
  XMLDoc *            document)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Disposes of a XMLDoc parse tree*/
/*
 *  XMLParseDisposeXMLDoc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseDisposeXMLDoc(
  ComponentInstance   aParser,
  XMLDoc              document)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Returns a more detailed description of the error and the line in which it occurred, if a
    file failed to parse properly.
*/
/*
 *  XMLParseGetDetailedParseError()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseGetDetailedParseError(
  ComponentInstance   aParser,
  long *              errorLine,
  StringPtr           errDesc)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Tell the parser of an element to be recognized. The tokenized element unique identifier is
    passed in *elementID, unless *elementID is zero, whereupon a unique ID is generated and returned.
    Thus, a valid element identifier can never be zero.
*/
/*
 *  XMLParseAddElement()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseAddElement(
  ComponentInstance   aParser,
  char *              elementName,
  UInt32              nameSpaceID,
  UInt32 *            elementID,
  long                elementFlags)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Tells the parser of an attribute for the specified element. The tokenized attribute unique
    ID is passed in *attributeID, unless *attributeID is zero, whereupon a unique ID is generated and
    returned. Thus, a valid attribute identifier can never be zero.
*/
/*
 *  XMLParseAddAttribute()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseAddAttribute(
  ComponentInstance   aParser,
  UInt32              elementID,
  UInt32              nameSpaceID,
  char *              attributeName,
  UInt32 *            attributeID)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Tells the parser of several attributes for the specified element. The attributes are passed
    as a zero-delimited, double-zero-terminated C string in attributeNames, and the attribute
    IDs are passed in on attributeIDs as an array; if any attributeIDs are zero, unique IDs
    are generated for those and returned
*/
/*
 *  XMLParseAddMultipleAttributes()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseAddMultipleAttributes(
  ComponentInstance   aParser,
  UInt32              elementID,
  UInt32 *            nameSpaceIDs,
  char *              attributeNames,
  UInt32 *            attributeIDs)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Tells the parser of an attribute, which may have a particular type of value, for the
    specified element. Params are as in XMLParseAddAttribute, plus all the kinds of values
    the attribute may have are passed in attributeValueKind, and optional additional information
    required to tokenize the particular kind of attribute is passed in attributeValueKindInfo
*/
/*
 *  XMLParseAddAttributeAndValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseAddAttributeAndValue(
  ComponentInstance   aParser,
  UInt32              elementID,
  UInt32              nameSpaceID,
  char *              attributeName,
  UInt32 *            attributeID,
  UInt32              attributeValueKind,
  void *              attributeValueKindInfo)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Tells the parser of several attributes, which may have a particular type of value, for the
    specified element. Params are as in XMLParseAddMultipleAttributes, plus all the kinds of values
    the attributes may have are passed in attributeValueKinds, and optional additional information
    required to tokenize the particular kind of attributes is passed in attributeValueKindInfos
*/
/*
 *  XMLParseAddMultipleAttributesAndValues()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseAddMultipleAttributesAndValues(
  ComponentInstance   aParser,
  UInt32              elementID,
  UInt32 *            nameSpaceIDs,
  char *              attributeNames,
  UInt32 *            attributeIDs,
  UInt32 *            attributeValueKinds,
  void **             attributeValueKindInfos)                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Tells the parser that the particular attribute may have an additional kind of
    value, as specified by attributeValueKind and attributeValueKindInfo
*/
/*
 *  XMLParseAddAttributeValueKind()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseAddAttributeValueKind(
  ComponentInstance   aParser,
  UInt32              elementID,
  UInt32              attributeID,
  UInt32              attributeValueKind,
  void *              attributeValueKindInfo)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Tell the parser of a namespace to be recognized. The tokenized namespace unique identifier is
    passed in *nameSpaceID, unless *nameSpaceID is zero, whereupon a unique ID is generated and returned.
    Thus, a valid nameSpaceID identifier can never be zero.
*/
/*
 *  XMLParseAddNameSpace()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseAddNameSpace(
  ComponentInstance   aParser,
  char *              nameSpaceURL,
  UInt32 *            nameSpaceID)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Specifies the offset and limit for reading from the dataref to be used when parsing*/
/*
 *  XMLParseSetOffsetAndLimit()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetOffsetAndLimit(
  ComponentInstance   aParser,
  UInt32              offset,
  UInt32              limit)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the event parse refcon*/
/*
 *  XMLParseSetEventParseRefCon()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetEventParseRefCon(
  ComponentInstance   aParser,
  long                refcon)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the start document handler UPP for event parsing*/
/*
 *  XMLParseSetStartDocumentHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetStartDocumentHandler(
  ComponentInstance         aParser,
  StartDocumentHandlerUPP   startDocument)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the end document handler UPP for event parsing*/
/*
 *  XMLParseSetEndDocumentHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetEndDocumentHandler(
  ComponentInstance       aParser,
  EndDocumentHandlerUPP   endDocument)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the start element handler UPP for event parsing*/
/*
 *  XMLParseSetStartElementHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetStartElementHandler(
  ComponentInstance        aParser,
  StartElementHandlerUPP   startElement)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the end element handler UPP for event parsing*/
/*
 *  XMLParseSetEndElementHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetEndElementHandler(
  ComponentInstance      aParser,
  EndElementHandlerUPP   endElement)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the character data handler UPP for event parsing*/
/*
 *  XMLParseSetCharDataHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetCharDataHandler(
  ComponentInstance    aParser,
  CharDataHandlerUPP   charData)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the preprocess instruction handler UPP for event parsing*/
/*
 *  XMLParseSetPreprocessInstructionHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetPreprocessInstructionHandler(
  ComponentInstance                 aParser,
  PreprocessInstructionHandlerUPP   preprocessInstruction)    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the comment handler UPP for event parsing*/
/*
 *  XMLParseSetCommentHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
XMLParseSetCommentHandler(
  ComponentInstance   aParser,
  CommentHandlerUPP   comment)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*  Set the cdata handler UPP for event parsing*/
/*
 *  XMLParseSetCDataHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
XMLParseSetCDataHandler(
  ComponentInstance   aParser,
  CDataHandlerUPP     cdata)                                  AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
    Helper Macros
    
        These macros allow you to easily add entities and attributes to the parser
        in an error free manner when the identifiers are defined in a particular manner.
        For these to work, you must define the identifiers as follows:
        
        For entities, they must be defined as element_elementName, as in:
        
            enum
            {
                element_xml =   1,      //  "xml"
                element_head,           //  "head"
                element_body            //  "body"
            };
            
        If the element name has characters that are illegal in an identifier,
        some of the macros support that, but the identifier must not contain
        the illegal characters:
        
            enum
            {
                element_rootlayout      //  "root-layout"
            }
            
        For attribute names, similar rules apply except that they must be defined
        as attr_attributeName, as in:
            
            enum
            {
                attr_src    =   1,      //  "src"
                attr_href,
                attr_width,
                attr_height
            }
            
        Finally, the existence of local variables elementID and attributeID is required.
*/
/*
    Adds the specified element to the parser, i.e. XML_ADD_ELEMENT(head) adds the element "head" with
    a unique identifier of element_head
*/

#define XML_ADD_ELEMENT_NS(elementName,nameSpaceID)        elementID   =   GLUE2(element_,elementName);    XMLParseAddElement(xmlParser, #elementName, nameSpaceID, &elementID, 0)
#define XML_ADD_ELEMENT(elementName)                    XML_ADD_ELEMENT_NS(elementName,nameSpaceIDNone)

/*
    Adds the specified element to the parser, not using the same string to generate the identifier and
    the element name. Use for element names that contain characters which are illegal in identifiers,
    i.e XML_ADD_COMPLEX_ELEMENT("root-layout",rootlayout) adds the element "root-layout" with a unique
    identifier of element_rootlayout
*/

#define XML_ADD_COMPLEX_ELEMENT_NS(elementName,elemID,nameSpaceID)     elementID   =   GLUE2(element_,elemID);     XMLParseAddElement(xmlParser, #elementName, nameSpaceID, &elementID, 0)
#define XML_ADD_COMPLEX_ELEMENT(elementName,elemID)                     XML_ADD_COMPLEX_ELEMENT_NS(elementName,elemID,nameSpaceIDNone)

/*
    Adds the specified attribute to the current element in the parser, i.e. XML_ADD_ATTRIBUTE(src)
    adds the attribute "src" to the current element, and identifies it by attr_src
*/

#define XML_ADD_ATTRIBUTE_NS(attrName,nameSpaceID)     attributeID =   GLUE2(attr_,attrName);      XMLParseAddAttribute(xmlParser, elementID, nameSpaceID, #attrName, &attributeID);
#define XML_ADD_ATTRIBUTE(attrName)                       XML_ADD_ATTRIBUTE_NS(attrName,nameSpaceIDNone)

/*
    Adds the specified attribute to the current element in the parser, i.e. XML_ADD_ATTRIBUTE(element_img, src)
    adds the attribute "src" to the element_img element, and identifies it by attr_src
    Adds the specified attribute to the current element in the parser, not using the same string to
    generate the identifier and the element name. Use for attribute names that contain characters which
    are illegal in identifiers, i.e XML_ADD_COMPLEX_ATTRIBUTE("http-equiv",httpequiv) adds the element
    "http-equiv" with a unique identifier of attr_httpequiv
*/

#define XML_ADD_COMPLEX_ATTRIBUTE_NS(attrName,attrID,nameSpaceID)  attributeID =   GLUE2(attr_,attrID);        XMLParseAddAttribute(xmlParser, elementID, nameSpaceID, #attrName, &attributeID);
#define XML_ADD_COMPLEX_ATTRIBUTE(attrName,attrID)                    XML_ADD_COMPLEX_ATTRIBUTE_NS(attrName,attrID,nameSpaceIDNone)


#define XML_ADD_ATTRIBUTE_AND_VALUE_NS(attrName,valueKind,valueKindInfo,nameSpaceID)   attributeID =   GLUE2(attr_,attrName);      XMLParseAddAttributeAndValue(xmlParser, elementID, nameSpaceID, #attrName, &attributeID, valueKind, valueKindInfo);
#define XML_ADD_ATTRIBUTE_AND_VALUE(attrName,valueKind,valueKindInfo)                   XML_ADD_ATTRIBUTE_AND_VALUE_NS(attrName,valueKind,valueKindInfo,nameSpaceIDNone)


#define XML_ADD_COMPLEX_ATTRIBUTE_AND_VALUE_NS(attrName,attrID,valueKind,valueKindInfo,nameSpaceID)        attributeID =   GLUE2(attr_,attrID);        XMLParseAddAttributeAndValue(xmlParser, elementID, nameSpaceID, #attrName, &attributeID, valueKind, valueKindInfo);
#define XML_ADD_COMPLEX_ATTRIBUTE_AND_VALUE(attrName,attrID,valueKind,valueKindInfo)                    XML_ADD_COMPLEX_ATTRIBUTE_AND_VALUE_NS(attrName,attrID,valueKind,valueKindInfo,nameSpaceIDNone)



/*
    General Sequence Grab stuff
*/
typedef ComponentInstance               SeqGrabComponent;
typedef ComponentInstance               SGChannel;
enum {
  SeqGrabComponentType          = 'barg',
  SeqGrabChannelType            = 'sgch',
  SeqGrabPanelType              = 'sgpn',
  SeqGrabCompressionPanelType   = 'cmpr',
  SeqGrabSourcePanelType        = 'sour'
};

enum {
  seqGrabToDisk                 = 1,
  seqGrabToMemory               = 2,
  seqGrabDontUseTempMemory      = 4,
  seqGrabAppendToFile           = 8,
  seqGrabDontAddMovieResource   = 16,
  seqGrabDontMakeMovie          = 32,
  seqGrabPreExtendFile          = 64,
  seqGrabDataProcIsInterruptSafe = 128,
  seqGrabDataProcDoesOverlappingReads = 256
};

typedef unsigned long                   SeqGrabDataOutputEnum;
enum {
  seqGrabRecord                 = 1,
  seqGrabPreview                = 2,
  seqGrabPlayDuringRecord       = 4,
  seqGrabLowLatencyCapture      = 8,    /* return the freshest frame possible, for live work (videoconferencing, live broadcast, live image processing) */
  seqGrabAlwaysUseTimeBase      = 16    /* Tell VDIGs to use TimebaseTime always, rather than creating uniform frame durations, for more accurate live sync with audio */
};

typedef unsigned long                   SeqGrabUsageEnum;
enum {
  seqGrabHasBounds              = 1,
  seqGrabHasVolume              = 2,
  seqGrabHasDiscreteSamples     = 4,
  seqGrabDoNotBufferizeData     = 8,
  seqGrabCanMoveWindowWhileRecording = 16
};

typedef unsigned long                   SeqGrabChannelInfoEnum;
struct SGOutputRecord {
  long                data[1];
};
typedef struct SGOutputRecord           SGOutputRecord;
typedef SGOutputRecord *                SGOutput;
struct SeqGrabFrameInfo {
  long                frameOffset;
  long                frameTime;
  long                frameSize;
  SGChannel           frameChannel;
  long                frameRefCon;
};
typedef struct SeqGrabFrameInfo         SeqGrabFrameInfo;
typedef SeqGrabFrameInfo *              SeqGrabFrameInfoPtr;
struct SeqGrabExtendedFrameInfo {
  wide                frameOffset;
  long                frameTime;
  long                frameSize;
  SGChannel           frameChannel;
  long                frameRefCon;
  SGOutput            frameOutput;
};
typedef struct SeqGrabExtendedFrameInfo SeqGrabExtendedFrameInfo;
typedef SeqGrabExtendedFrameInfo *      SeqGrabExtendedFrameInfoPtr;
enum {
  grabPictOffScreen             = 1,
  grabPictIgnoreClip            = 2,
  grabPictCurrentImage          = 4
};

enum {
  sgFlagControlledGrab          = (1 << 0),
  sgFlagAllowNonRGBPixMaps      = (1 << 1)
};

typedef CALLBACK_API( OSErr , SGDataProcPtr )(SGChannel c, Ptr p, long len, long *offset, long chRefCon, TimeValue time, short writeType, long refCon);
typedef STACK_UPP_TYPE(SGDataProcPtr)                           SGDataUPP;
struct SGDeviceInputName {
  Str63               name;
  Handle              icon;
  long                flags;
  long                reserved;               /* zero*/
};
typedef struct SGDeviceInputName        SGDeviceInputName;
enum {
  sgDeviceInputNameFlagInputUnavailable = (1 << 0)
};

struct SGDeviceInputListRecord {
  short               count;
  short               selectedIndex;
  long                reserved;               /* zero*/
  SGDeviceInputName   entry[1];
};
typedef struct SGDeviceInputListRecord  SGDeviceInputListRecord;
typedef SGDeviceInputListRecord *       SGDeviceInputListPtr;
typedef SGDeviceInputListPtr *          SGDeviceInputList;
struct SGDeviceName {
  Str63               name;
  Handle              icon;
  long                flags;
  long                refCon;
  SGDeviceInputList   inputs;                 /* list of inputs; formerly reserved to 0*/
};
typedef struct SGDeviceName             SGDeviceName;
enum {
  sgDeviceNameFlagDeviceUnavailable = (1 << 0),
  sgDeviceNameFlagShowInputsAsDevices = (1 << 1)
};

struct SGDeviceListRecord {
  short               count;
  short               selectedIndex;
  long                reserved;               /* zero*/
  SGDeviceName        entry[1];
};
typedef struct SGDeviceListRecord       SGDeviceListRecord;
typedef SGDeviceListRecord *            SGDeviceListPtr;
typedef SGDeviceListPtr *               SGDeviceList;
enum {
  sgDeviceListWithIcons         = (1 << 0),
  sgDeviceListDontCheckAvailability = (1 << 1),
  sgDeviceListIncludeInputs     = (1 << 2)
};

enum {
  seqGrabWriteAppend            = 0,
  seqGrabWriteReserve           = 1,
  seqGrabWriteFill              = 2
};

enum {
  seqGrabUnpause                = 0,
  seqGrabPause                  = 1,
  seqGrabPauseForMenu           = 3
};

enum {
  channelFlagDontOpenResFile    = 2,
  channelFlagHasDependency      = 4
};

typedef CALLBACK_API( Boolean , SGModalFilterProcPtr )(DialogRef theDialog, const EventRecord *theEvent, short *itemHit, long refCon);
typedef STACK_UPP_TYPE(SGModalFilterProcPtr)                    SGModalFilterUPP;
enum {
  sgPanelFlagForPanel           = 1
};

enum {
  seqGrabSettingsPreviewOnly    = 1
};

enum {
  channelPlayNormal             = 0,
  channelPlayFast               = 1,
  channelPlayHighQuality        = 2,
  channelPlayAllData            = 4
};


/*
 *  SGInitialize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGInitialize(SeqGrabComponent s)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetDataOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetDataOutput(
  SeqGrabComponent   s,
  const FSSpec *     movieFile,
  long               whereFlags)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetDataOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetDataOutput(
  SeqGrabComponent   s,
  FSSpec *           movieFile,
  long *             whereFlags)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetGWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetGWorld(
  SeqGrabComponent   s,
  CGrafPtr           gp,
  GDHandle           gd)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetGWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetGWorld(
  SeqGrabComponent   s,
  CGrafPtr *         gp,
  GDHandle *         gd)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGNewChannel()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGNewChannel(
  SeqGrabComponent   s,
  OSType             channelType,
  SGChannel *        ref)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGDisposeChannel()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGDisposeChannel(
  SeqGrabComponent   s,
  SGChannel          c)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGStartPreview()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGStartPreview(SeqGrabComponent s)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGStartRecord()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGStartRecord(SeqGrabComponent s)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGIdle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGIdle(SeqGrabComponent s)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGStop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGStop(SeqGrabComponent s)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPause()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPause(
  SeqGrabComponent   s,
  Byte               pause)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPrepare()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPrepare(
  SeqGrabComponent   s,
  Boolean            prepareForPreview,
  Boolean            prepareForRecord)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGRelease()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGRelease(SeqGrabComponent s)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
SGGetMovie(SeqGrabComponent s)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetMaximumRecordTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetMaximumRecordTime(
  SeqGrabComponent   s,
  unsigned long      ticks)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetMaximumRecordTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetMaximumRecordTime(
  SeqGrabComponent   s,
  unsigned long *    ticks)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetStorageSpaceRemaining()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetStorageSpaceRemaining(
  SeqGrabComponent   s,
  unsigned long *    bytes)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetTimeRemaining()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetTimeRemaining(
  SeqGrabComponent   s,
  long *             ticksLeft)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGrabPict()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGrabPict(
  SeqGrabComponent   s,
  PicHandle *        p,
  const Rect *       bounds,
  short              offscreenDepth,
  long               grabPictFlags)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetLastMovieResID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetLastMovieResID(
  SeqGrabComponent   s,
  short *            resID)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetFlags(
  SeqGrabComponent   s,
  long               sgFlags)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetFlags(
  SeqGrabComponent   s,
  long *             sgFlags)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetDataProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetDataProc(
  SeqGrabComponent   s,
  SGDataUPP          proc,
  long               refCon)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGNewChannelFromComponent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGNewChannelFromComponent(
  SeqGrabComponent   s,
  SGChannel *        newChannel,
  Component          sgChannelComponent)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGDisposeDeviceList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGDisposeDeviceList(
  SeqGrabComponent   s,
  SGDeviceList       list)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGAppendDeviceListToMenu()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGAppendDeviceListToMenu(
  SeqGrabComponent   s,
  SGDeviceList       list,
  MenuRef            mh)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetSettings(
  SeqGrabComponent   s,
  UserData           ud,
  long               flags)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetSettings(
  SeqGrabComponent   s,
  UserData *         ud,
  long               flags)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetIndChannel()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetIndChannel(
  SeqGrabComponent   s,
  short              index,
  SGChannel *        ref,
  OSType *           chanType)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGUpdate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGUpdate(
  SeqGrabComponent   s,
  RgnHandle          updateRgn)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetPause()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetPause(
  SeqGrabComponent   s,
  Byte *             paused)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


typedef const Component *               ConstComponentListPtr;
/*
 *  SGSettingsDialog()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSettingsDialog(
  SeqGrabComponent        s,
  SGChannel               c,
  short                   numPanels,
  ConstComponentListPtr   panelList,
  long                    flags,
  SGModalFilterUPP        proc,
  long                    procRefNum)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetAlignmentProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetAlignmentProc(
  SeqGrabComponent            s,
  ICMAlignmentProcRecordPtr   alignmentProc)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelSettings(
  SeqGrabComponent   s,
  SGChannel          c,
  UserData           ud,
  long               flags)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelSettings(
  SeqGrabComponent   s,
  SGChannel          c,
  UserData *         ud,
  long               flags)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetMode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetMode(
  SeqGrabComponent   s,
  Boolean *          previewMode,
  Boolean *          recordMode)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetDataRef(
  SeqGrabComponent   s,
  Handle             dataRef,
  OSType             dataRefType,
  long               whereFlags)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetDataRef(
  SeqGrabComponent   s,
  Handle *           dataRef,
  OSType *           dataRefType,
  long *             whereFlags)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGNewOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGNewOutput(
  SeqGrabComponent   s,
  Handle             dataRef,
  OSType             dataRefType,
  long               whereFlags,
  SGOutput *         sgOut)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGDisposeOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGDisposeOutput(
  SeqGrabComponent   s,
  SGOutput           sgOut)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetOutputFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetOutputFlags(
  SeqGrabComponent   s,
  SGOutput           sgOut,
  long               whereFlags)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelOutput(
  SeqGrabComponent   s,
  SGChannel          c,
  SGOutput           sgOut)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetDataOutputStorageSpaceRemaining()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetDataOutputStorageSpaceRemaining(
  SeqGrabComponent   s,
  SGOutput           sgOut,
  unsigned long *    space)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGHandleUpdateEvent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGHandleUpdateEvent(
  SeqGrabComponent     s,
  const EventRecord *  event,
  Boolean *            handled)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetOutputNextOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetOutputNextOutput(
  SeqGrabComponent   s,
  SGOutput           sgOut,
  SGOutput           nextOut)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetOutputNextOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetOutputNextOutput(
  SeqGrabComponent   s,
  SGOutput           sgOut,
  SGOutput *         nextOut)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetOutputMaximumOffset()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetOutputMaximumOffset(
  SeqGrabComponent   s,
  SGOutput           sgOut,
  const wide *       maxOffset)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetOutputMaximumOffset()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetOutputMaximumOffset(
  SeqGrabComponent   s,
  SGOutput           sgOut,
  wide *             maxOffset)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetOutputDataReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetOutputDataReference(
  SeqGrabComponent   s,
  SGOutput           sgOut,
  Handle *           dataRef,
  OSType *           dataRefType)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGWriteExtendedMovieData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGWriteExtendedMovieData(
  SeqGrabComponent   s,
  SGChannel          c,
  Ptr                p,
  long               len,
  wide *             offset,
  SGOutput *         sgOut)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetStorageSpaceRemaining64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
SGGetStorageSpaceRemaining64(
  SeqGrabComponent   s,
  wide *             bytes)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetDataOutputStorageSpaceRemaining64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
SGGetDataOutputStorageSpaceRemaining64(
  SeqGrabComponent   s,
  SGOutput           sgOut,
  wide *             space)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    calls from Channel to seqGrab
*/
/*
 *  SGWriteMovieData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGWriteMovieData(
  SeqGrabComponent   s,
  SGChannel          c,
  Ptr                p,
  long               len,
  long *             offset)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGAddFrameReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGAddFrameReference(
  SeqGrabComponent      s,
  SeqGrabFrameInfoPtr   frameInfo)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetNextFrameReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetNextFrameReference(
  SeqGrabComponent      s,
  SeqGrabFrameInfoPtr   frameInfo,
  TimeValue *           frameDuration,
  long *                frameNumber)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetTimeBase(
  SeqGrabComponent   s,
  TimeBase *         tb)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSortDeviceList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSortDeviceList(
  SeqGrabComponent   s,
  SGDeviceList       list)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGAddMovieData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGAddMovieData(
  SeqGrabComponent   s,
  SGChannel          c,
  Ptr                p,
  long               len,
  long *             offset,
  long               chRefCon,
  TimeValue          time,
  short              writeType)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGChangedSource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGChangedSource(
  SeqGrabComponent   s,
  SGChannel          c)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGAddExtendedFrameReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGAddExtendedFrameReference(
  SeqGrabComponent              s,
  SeqGrabExtendedFrameInfoPtr   frameInfo)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetNextExtendedFrameReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetNextExtendedFrameReference(
  SeqGrabComponent              s,
  SeqGrabExtendedFrameInfoPtr   frameInfo,
  TimeValue *                   frameDuration,
  long *                        frameNumber)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGAddExtendedMovieData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGAddExtendedMovieData(
  SeqGrabComponent   s,
  SGChannel          c,
  Ptr                p,
  long               len,
  wide *             offset,
  long               chRefCon,
  TimeValue          time,
  short              writeType,
  SGOutput *         whichOutput)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGAddOutputDataRefToMedia()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGAddOutputDataRefToMedia(
  SeqGrabComponent          s,
  SGOutput                  sgOut,
  Media                     theMedia,
  SampleDescriptionHandle   desc)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetSettingsSummary()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SGSetSettingsSummary(
  SeqGrabComponent   s,
  Handle             summaryText)                             AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;




/*** Sequence Grab CHANNEL Component Stuff ***/

/*
 *  SGSetChannelUsage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelUsage(
  SGChannel   c,
  long        usage)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelUsage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelUsage(
  SGChannel   c,
  long *      usage)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelBounds()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelBounds(
  SGChannel     c,
  const Rect *  bounds)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelBounds()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelBounds(
  SGChannel   c,
  Rect *      bounds)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelVolume()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelVolume(
  SGChannel   c,
  short       volume)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelVolume()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelVolume(
  SGChannel   c,
  short *     volume)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelInfo(
  SGChannel   c,
  long *      channelInfo)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelPlayFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelPlayFlags(
  SGChannel   c,
  long        playFlags)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelPlayFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelPlayFlags(
  SGChannel   c,
  long *      playFlags)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelMaxFrames()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelMaxFrames(
  SGChannel   c,
  long        frameCount)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelMaxFrames()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelMaxFrames(
  SGChannel   c,
  long *      frameCount)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelRefCon()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelRefCon(
  SGChannel   c,
  long        refCon)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelClip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelClip(
  SGChannel   c,
  RgnHandle   theClip)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelClip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelClip(
  SGChannel    c,
  RgnHandle *  theClip)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelSampleDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelSampleDescription(
  SGChannel   c,
  Handle      sampleDesc)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelDeviceList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelDeviceList(
  SGChannel       c,
  long            selectionFlags,
  SGDeviceList *  list)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelDevice()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelDevice(
  SGChannel   c,
  StringPtr   name)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetChannelMatrix()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetChannelMatrix(
  SGChannel             c,
  const MatrixRecord *  m)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelMatrix()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelMatrix(
  SGChannel       c,
  MatrixRecord *  m)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelTimeScale()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetChannelTimeScale(
  SGChannel    c,
  TimeScale *  scale)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGChannelPutPicture()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGChannelPutPicture(SGChannel c)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGChannelSetRequestedDataRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGChannelSetRequestedDataRate(
  SGChannel   c,
  long        bytesPerSecond)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGChannelGetRequestedDataRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGChannelGetRequestedDataRate(
  SGChannel   c,
  long *      bytesPerSecond)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGChannelSetDataSourceName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGChannelSetDataSourceName(
  SGChannel          c,
  ConstStr255Param   name,
  ScriptCode         scriptTag)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGChannelGetDataSourceName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGChannelGetDataSourceName(
  SGChannel     c,
  Str255        name,
  ScriptCode *  scriptTag)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGChannelSetCodecSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
SGChannelSetCodecSettings(
  SGChannel   c,
  Handle      settings)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGChannelGetCodecSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
SGChannelGetCodecSettings(
  SGChannel   c,
  Handle *    settings)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
SGGetChannelTimeBase(
  SGChannel   c,
  TimeBase *  tb)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetChannelRefCon()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SGGetChannelRefCon(
  SGChannel   c,
  long *      refCon)                                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/* A utility call to find out the current device and input names, instead of having to call GetDeviceList and walk it yourself */
/*
 *  SGGetChannelDeviceAndInputNames()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SGGetChannelDeviceAndInputNames(
  SGChannel   c,
  Str255      outDeviceName,
  Str255      outInputName,
  short *     outInputNumber)                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/* A media format independent call for this. Inputs start at 0 here (Sound starts at 1, VDIGs at 0 in direct calls) */
/*
 *  SGSetChannelDeviceInput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SGSetChannelDeviceInput(
  SGChannel   c,
  short       inInputNumber)                                  AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/* A call to bracket SetSettings related calls, to give downstream components an opportunity to deal with the entire 
    settings change in one go */
enum {
  sgSetSettingsBegin            = (1 << 0), /* SGSetSettings related set calls about to start*/
  sgSetSettingsEnd              = (1 << 1) /* Finished SGSetSettings calls. Get ready to use the new settings*/
};

/*
 *  SGSetChannelSettingsStateChanging()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SGSetChannelSettingsStateChanging(
  SGChannel   c,
  UInt32      inFlags)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
    calls from seqGrab to Channel
*/
/*
 *  SGInitChannel()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGInitChannel(
  SGChannel          c,
  SeqGrabComponent   owner)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGWriteSamples()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGWriteSamples(
  SGChannel     c,
  Movie         m,
  AliasHandle   theFile)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetDataRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetDataRate(
  SGChannel   c,
  long *      bytesPerSecond)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGAlignChannelRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGAlignChannelRect(
  SGChannel   c,
  Rect *      r)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Dorky dialog panel calls
*/
/*
 *  SGPanelGetDitl()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelGetDitl(
  SeqGrabComponent   s,
  Handle *           ditl)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelGetTitle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelGetTitle(
  SeqGrabComponent   s,
  Str255             title)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelCanRun()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelCanRun(
  SeqGrabComponent   s,
  SGChannel          c)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelInstall()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelInstall(
  SeqGrabComponent   s,
  SGChannel          c,
  DialogRef          d,
  short              itemOffset)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelEvent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelEvent(
  SeqGrabComponent     s,
  SGChannel            c,
  DialogRef            d,
  short                itemOffset,
  const EventRecord *  theEvent,
  short *              itemHit,
  Boolean *            handled)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelItem()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelItem(
  SeqGrabComponent   s,
  SGChannel          c,
  DialogRef          d,
  short              itemOffset,
  short              itemNum)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelRemove()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelRemove(
  SeqGrabComponent   s,
  SGChannel          c,
  DialogRef          d,
  short              itemOffset)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelSetGrabber()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelSetGrabber(
  SeqGrabComponent   s,
  SeqGrabComponent   sg)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelSetResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelSetResFile(
  SeqGrabComponent   s,
  short              resRef)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelGetSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelGetSettings(
  SeqGrabComponent   s,
  SGChannel          c,
  UserData *         ud,
  long               flags)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelSetSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelSetSettings(
  SeqGrabComponent   s,
  SGChannel          c,
  UserData           ud,
  long               flags)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelValidateInput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelValidateInput(
  SeqGrabComponent   s,
  Boolean *          ok)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGPanelSetEventFilter()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGPanelSetEventFilter(
  SeqGrabComponent   s,
  SGModalFilterUPP   proc,
  long               refCon)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    SGPanelGetDITLForSize is used to retrieve user interface elements that fit within a specified size
    panel.  The component should return badComponentSelector for sizes it does not support.  The component
    is required to support kSGSmallestDITLSize, and it is recommended to support kSGLargestDITLSize.
    
    If SGPanelGetDITLForSize is unimplemented entirely, the panel is assumed to not have resizable UI elements.
*/
enum {
  kSGSmallestDITLSize           = -1,   /* requestedSize h and v set to this to retrieve small size*/
  kSGLargestDITLSize            = -2    /* requestedSize h and v set to this to retrieve large size*/
};

/*
 *  SGPanelGetDITLForSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SGPanelGetDITLForSize(
  SeqGrabComponent   s,
  Handle *           ditl,
  Point *            requestedSize)                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*** Sequence Grab VIDEO CHANNEL Component Stuff ***/
/*
    Video stuff
*/
struct SGCompressInfo {
  Ptr                 buffer;
  unsigned long       bufferSize;
  UInt8               similarity;
  UInt8               reserved;
};
typedef struct SGCompressInfo           SGCompressInfo;
typedef CALLBACK_API( ComponentResult , SGGrabBottleProcPtr )(SGChannel c, short bufferNum, long refCon);
typedef CALLBACK_API( ComponentResult , SGGrabCompleteBottleProcPtr )(SGChannel c, short bufferNum, Boolean *done, long refCon);
typedef CALLBACK_API( ComponentResult , SGDisplayBottleProcPtr )(SGChannel c, short bufferNum, MatrixRecord *mp, RgnHandle clipRgn, long refCon);
typedef CALLBACK_API( ComponentResult , SGCompressBottleProcPtr )(SGChannel c, short bufferNum, long refCon);
typedef CALLBACK_API( ComponentResult , SGCompressCompleteBottleProcPtr )(SGChannel c, short bufferNum, Boolean *done, SGCompressInfo *ci, long refCon);
typedef CALLBACK_API( ComponentResult , SGAddFrameBottleProcPtr )(SGChannel c, short bufferNum, TimeValue atTime, TimeScale scale, const SGCompressInfo *ci, long refCon);
typedef CALLBACK_API( ComponentResult , SGTransferFrameBottleProcPtr )(SGChannel c, short bufferNum, MatrixRecord *mp, RgnHandle clipRgn, long refCon);
/*    Note that UInt8 *queuedFrameCount replaces Boolean *done. 0(==false) still means no frames, and 1(==true) one, 
    but if more than one are available the number should be returned here. The value 2 previously meant more than one frame,
    so some VDIGs may return 2 even if more than 2 are available, and some will still return 1 as they are using the original definition. */
typedef CALLBACK_API( ComponentResult , SGGrabCompressCompleteBottleProcPtr )(SGChannel c, UInt8 *queuedFrameCount, SGCompressInfo *ci, TimeRecord *t, long refCon);
typedef CALLBACK_API( ComponentResult , SGDisplayCompressBottleProcPtr )(SGChannel c, Ptr dataPtr, ImageDescriptionHandle desc, MatrixRecord *mp, RgnHandle clipRgn, long refCon);
typedef STACK_UPP_TYPE(SGGrabBottleProcPtr)                     SGGrabBottleUPP;
typedef STACK_UPP_TYPE(SGGrabCompleteBottleProcPtr)             SGGrabCompleteBottleUPP;
typedef STACK_UPP_TYPE(SGDisplayBottleProcPtr)                  SGDisplayBottleUPP;
typedef STACK_UPP_TYPE(SGCompressBottleProcPtr)                 SGCompressBottleUPP;
typedef STACK_UPP_TYPE(SGCompressCompleteBottleProcPtr)         SGCompressCompleteBottleUPP;
typedef STACK_UPP_TYPE(SGAddFrameBottleProcPtr)                 SGAddFrameBottleUPP;
typedef STACK_UPP_TYPE(SGTransferFrameBottleProcPtr)            SGTransferFrameBottleUPP;
typedef STACK_UPP_TYPE(SGGrabCompressCompleteBottleProcPtr)     SGGrabCompressCompleteBottleUPP;
typedef STACK_UPP_TYPE(SGDisplayCompressBottleProcPtr)          SGDisplayCompressBottleUPP;
struct VideoBottles {
  short               procCount;
  SGGrabBottleUPP     grabProc;
  SGGrabCompleteBottleUPP  grabCompleteProc;
  SGDisplayBottleUPP  displayProc;
  SGCompressBottleUPP  compressProc;
  SGCompressCompleteBottleUPP  compressCompleteProc;
  SGAddFrameBottleUPP  addFrameProc;
  SGTransferFrameBottleUPP  transferFrameProc;
  SGGrabCompressCompleteBottleUPP  grabCompressCompleteProc;
  SGDisplayCompressBottleUPP  displayCompressProc;
};
typedef struct VideoBottles             VideoBottles;
/*
 *  SGGetSrcVideoBounds()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetSrcVideoBounds(
  SGChannel   c,
  Rect *      r)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetVideoRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetVideoRect(
  SGChannel     c,
  const Rect *  r)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetVideoRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetVideoRect(
  SGChannel   c,
  Rect *      r)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetVideoCompressorType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetVideoCompressorType(
  SGChannel   c,
  OSType *    compressorType)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetVideoCompressorType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetVideoCompressorType(
  SGChannel   c,
  OSType      compressorType)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetVideoCompressor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetVideoCompressor(
  SGChannel             c,
  short                 depth,
  CompressorComponent   compressor,
  CodecQ                spatialQuality,
  CodecQ                temporalQuality,
  long                  keyFrameRate)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetVideoCompressor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetVideoCompressor(
  SGChannel              c,
  short *                depth,
  CompressorComponent *  compressor,
  CodecQ *               spatialQuality,
  CodecQ *               temporalQuality,
  long *                 keyFrameRate)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetVideoDigitizerComponent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentInstance 
SGGetVideoDigitizerComponent(SGChannel c)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetVideoDigitizerComponent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetVideoDigitizerComponent(
  SGChannel           c,
  ComponentInstance   vdig)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGVideoDigitizerChanged()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGVideoDigitizerChanged(SGChannel c)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetVideoBottlenecks()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetVideoBottlenecks(
  SGChannel       c,
  VideoBottles *  vb)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetVideoBottlenecks()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetVideoBottlenecks(
  SGChannel       c,
  VideoBottles *  vb)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGrabFrame()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGrabFrame(
  SGChannel   c,
  short       bufferNum)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGrabFrameComplete()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGrabFrameComplete(
  SGChannel   c,
  short       bufferNum,
  Boolean *   done)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGDisplayFrame()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGDisplayFrame(
  SGChannel             c,
  short                 bufferNum,
  const MatrixRecord *  mp,
  RgnHandle             clipRgn)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGCompressFrame()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGCompressFrame(
  SGChannel   c,
  short       bufferNum)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGCompressFrameComplete()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGCompressFrameComplete(
  SGChannel         c,
  short             bufferNum,
  Boolean *         done,
  SGCompressInfo *  ci)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGAddFrame()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGAddFrame(
  SGChannel               c,
  short                   bufferNum,
  TimeValue               atTime,
  TimeScale               scale,
  const SGCompressInfo *  ci)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGTransferFrameForCompress()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGTransferFrameForCompress(
  SGChannel             c,
  short                 bufferNum,
  const MatrixRecord *  mp,
  RgnHandle             clipRgn)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetCompressBuffer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetCompressBuffer(
  SGChannel     c,
  short         depth,
  const Rect *  compressSize)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetCompressBuffer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetCompressBuffer(
  SGChannel   c,
  short *     depth,
  Rect *      compressSize)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetBufferInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetBufferInfo(
  SGChannel       c,
  short           bufferNum,
  PixMapHandle *  bufferPM,
  Rect *          bufferRect,
  GWorldPtr *     compressBuffer,
  Rect *          compressBufferRect)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetUseScreenBuffer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetUseScreenBuffer(
  SGChannel   c,
  Boolean     useScreenBuffer)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetUseScreenBuffer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetUseScreenBuffer(
  SGChannel   c,
  Boolean *   useScreenBuffer)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*    Note that UInt8 *queuedFrameCount replaces Boolean *done. 0(==false) still means no frames, and 1(==true) one, 
    but if more than one are available the number should be returned here. The value 2 previously meant more than one frame,
    so some VDIGs may return 2 even if more than 2 are available, and some will still return 1 as they are using the original definition. */
/*
 *  SGGrabCompressComplete()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGrabCompressComplete(
  SGChannel         c,
  UInt8 *           queuedFrameCount,
  SGCompressInfo *  ci,
  TimeRecord *      tr)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGDisplayCompress()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGDisplayCompress(
  SGChannel                c,
  Ptr                      dataPtr,
  ImageDescriptionHandle   desc,
  MatrixRecord *           mp,
  RgnHandle                clipRgn)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetFrameRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetFrameRate(
  SGChannel   c,
  Fixed       frameRate)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetFrameRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetFrameRate(
  SGChannel   c,
  Fixed *     frameRate)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  SGSetPreferredPacketSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetPreferredPacketSize(
  SGChannel   c,
  long        preferredPacketSizeInBytes)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetPreferredPacketSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetPreferredPacketSize(
  SGChannel   c,
  long *      preferredPacketSizeInBytes)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetUserVideoCompressorList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetUserVideoCompressorList(
  SGChannel   c,
  Handle      compressorTypes)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetUserVideoCompressorList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetUserVideoCompressorList(
  SGChannel   c,
  Handle *    compressorTypes)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*** Sequence Grab SOUND CHANNEL Component Stuff ***/

/*
    Sound stuff
*/
/*
 *  SGSetSoundInputDriver()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetSoundInputDriver(
  SGChannel          c,
  ConstStr255Param   driverName)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetSoundInputDriver()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
SGGetSoundInputDriver(SGChannel c)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSoundInputDriverChanged()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSoundInputDriverChanged(SGChannel c)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetSoundRecordChunkSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetSoundRecordChunkSize(
  SGChannel   c,
  long        seconds)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetSoundRecordChunkSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
SGGetSoundRecordChunkSize(SGChannel c)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetSoundInputRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetSoundInputRate(
  SGChannel   c,
  Fixed       rate)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetSoundInputRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Fixed 
SGGetSoundInputRate(SGChannel c)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetSoundInputParameters()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetSoundInputParameters(
  SGChannel   c,
  short       sampleSize,
  short       numChannels,
  OSType      compressionType)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetSoundInputParameters()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetSoundInputParameters(
  SGChannel   c,
  short *     sampleSize,
  short *     numChannels,
  OSType *    compressionType)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetAdditionalSoundRates()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetAdditionalSoundRates(
  SGChannel   c,
  Handle      rates)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetAdditionalSoundRates()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetAdditionalSoundRates(
  SGChannel   c,
  Handle *    rates)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Text stuff
*/
/*
 *  SGSetFontName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetFontName(
  SGChannel   c,
  StringPtr   pstr)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetFontSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetFontSize(
  SGChannel   c,
  short       fontSize)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetTextForeColor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetTextForeColor(
  SGChannel   c,
  RGBColor *  theColor)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetTextBackColor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetTextBackColor(
  SGChannel   c,
  RGBColor *  theColor)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetJustification()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetJustification(
  SGChannel   c,
  short       just)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGGetTextReturnToSpaceValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetTextReturnToSpaceValue(
  SGChannel   c,
  short *     rettospace)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetTextReturnToSpaceValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetTextReturnToSpaceValue(
  SGChannel   c,
  short       rettospace)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    Music stuff
*/
/*
 *  SGGetInstrument()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGGetInstrument(
  SGChannel          c,
  ToneDescription *  td)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SGSetInstrument()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SGSetInstrument(
  SGChannel          c,
  ToneDescription *  td)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



enum {
  sgChannelAtom                 = 'chan',
  sgChannelSettingsAtom         = 'ctom',
  sgChannelDescription          = 'cdsc',
  sgChannelSettings             = 'cset'
};

enum {
  sgDeviceNameType              = 'name',
  sgDeviceDisplayNameType       = 'dnam',
  sgDeviceUIDType               = 'duid',
  sgInputUIDType                = 'iuid',
  sgUsageType                   = 'use ',
  sgPlayFlagsType               = 'plyf',
  sgClipType                    = 'clip',
  sgMatrixType                  = 'mtrx',
  sgVolumeType                  = 'volu'
};

enum {
  sgPanelSettingsAtom           = 'ptom',
  sgPanelDescription            = 'pdsc',
  sgPanelSettings               = 'pset'
};

enum {
  sgcSoundCompressionType       = 'scmp',
  sgcSoundCodecSettingsType     = 'cdec',
  sgcSoundSampleRateType        = 'srat',
  sgcSoundChannelCountType      = 'schn',
  sgcSoundSampleSizeType        = 'ssiz',
  sgcSoundInputType             = 'sinp',
  sgcSoundGainType              = 'gain'
};

enum {
  sgcVideoHueType               = 'hue ',
  sgcVideoSaturationType        = 'satr',
  sgcVideoContrastType          = 'trst',
  sgcVideoSharpnessType         = 'shrp',
  sgcVideoBrigtnessType         = 'brit',
  sgcVideoBlackLevelType        = 'blkl',
  sgcVideoWhiteLevelType        = 'whtl',
  sgcVideoInputType             = 'vinp',
  sgcVideoFormatType            = 'vstd',
  sgcVideoFilterType            = 'vflt',
  sgcVideoRectType              = 'vrct',
  sgcVideoDigitizerType         = 'vdig'
};





typedef ComponentInstance               QTVideoOutputComponent;
/* Component type and subtype enumerations*/
enum {
  QTVideoOutputComponentType    = 'vout',
  QTVideoOutputComponentBaseSubType = 'base'
};


/* QTVideoOutput Component flags*/

enum {
  kQTVideoOutputDontDisplayToUser = 1L << 0
};

/* Display mode atom types*/

enum {
  kQTVODisplayModeItem          = 'qdmi',
  kQTVODimensions               = 'dimn', /* atom contains two longs - pixel count - width, height*/
  kQTVOResolution               = 'resl', /* atom contains two Fixed - hRes, vRes in dpi*/
  kQTVORefreshRate              = 'refr', /* atom contains one Fixed - refresh rate in Hz*/
  kQTVOPixelType                = 'pixl', /* atom contains one OSType - pixel format of mode*/
  kQTVOName                     = 'name', /* atom contains string (no length byte) - name of mode for display to user*/
  kQTVODecompressors            = 'deco', /* atom contains other atoms indicating supported decompressors*/
                                        /* kQTVODecompressors sub-atoms*/
  kQTVODecompressorType         = 'dety', /* atom contains one OSType - decompressor type code*/
  kQTVODecompressorContinuous   = 'cont', /* atom contains one Boolean - true if this type is displayed continuously*/
  kQTVODecompressorComponent    = 'cmpt' /* atom contains one Component - component id of decompressor*/
};

/** These are QTVideoOutput procedures **/
/*
 *  QTVideoOutputGetDisplayModeList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputGetDisplayModeList(
  QTVideoOutputComponent   vo,
  QTAtomContainer *        outputs)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputGetCurrentClientName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputGetCurrentClientName(
  QTVideoOutputComponent   vo,
  Str255                   str)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputSetClientName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputSetClientName(
  QTVideoOutputComponent   vo,
  ConstStr255Param         str)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputGetClientName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputGetClientName(
  QTVideoOutputComponent   vo,
  Str255                   str)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputBegin()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputBegin(QTVideoOutputComponent vo)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputEnd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputEnd(QTVideoOutputComponent vo)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputSetDisplayMode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputSetDisplayMode(
  QTVideoOutputComponent   vo,
  long                     displayModeID)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputGetDisplayMode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputGetDisplayMode(
  QTVideoOutputComponent   vo,
  long *                   displayModeID)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputCustomConfigureDisplay()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputCustomConfigureDisplay(
  QTVideoOutputComponent   vo,
  ModalFilterUPP           filter)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputSaveState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputSaveState(
  QTVideoOutputComponent   vo,
  QTAtomContainer *        state)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputRestoreState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputRestoreState(
  QTVideoOutputComponent   vo,
  QTAtomContainer          state)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputGetGWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputGetGWorld(
  QTVideoOutputComponent   vo,
  GWorldPtr *              gw)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputGetGWorldParameters()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputGetGWorldParameters(
  QTVideoOutputComponent   vo,
  Ptr *                    baseAddr,
  long *                   rowBytes,
  CTabHandle *             colorTable)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputGetIndSoundOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputGetIndSoundOutput(
  QTVideoOutputComponent   vo,
  long                     index,
  Component *              outputComponent)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputGetClock()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputGetClock(
  QTVideoOutputComponent   vo,
  ComponentInstance *      clock)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputSetEchoPort()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
QTVideoOutputSetEchoPort(
  QTVideoOutputComponent   vo,
  CGrafPtr                 echoPort)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputGetIndImageDecompressor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
QTVideoOutputGetIndImageDecompressor(
  QTVideoOutputComponent   vo,
  long                     index,
  Component *              codec)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTVideoOutputBaseSetEchoPort()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
QTVideoOutputBaseSetEchoPort(
  QTVideoOutputComponent   vo,
  CGrafPtr                 echoPort)                          AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/* UPP call backs */
/*
 *  NewDataHCompletionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern DataHCompletionUPP
NewDataHCompletionUPP(DataHCompletionProcPtr userRoutine)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewVdigIntUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern VdigIntUPP
NewVdigIntUPP(VdigIntProcPtr userRoutine)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewStartDocumentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern StartDocumentHandlerUPP
NewStartDocumentHandlerUPP(StartDocumentHandler userRoutine)  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewEndDocumentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern EndDocumentHandlerUPP
NewEndDocumentHandlerUPP(EndDocumentHandler userRoutine)      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewStartElementHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern StartElementHandlerUPP
NewStartElementHandlerUPP(StartElementHandler userRoutine)    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewEndElementHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern EndElementHandlerUPP
NewEndElementHandlerUPP(EndElementHandler userRoutine)        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewCharDataHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern CharDataHandlerUPP
NewCharDataHandlerUPP(CharDataHandler userRoutine)            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewPreprocessInstructionHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern PreprocessInstructionHandlerUPP
NewPreprocessInstructionHandlerUPP(PreprocessInstructionHandler userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewCommentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern CommentHandlerUPP
NewCommentHandlerUPP(CommentHandler userRoutine)              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewCDataHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern CDataHandlerUPP
NewCDataHandlerUPP(CDataHandler userRoutine)                  AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  NewSGDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGDataUPP
NewSGDataUPP(SGDataProcPtr userRoutine)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGModalFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGModalFilterUPP
NewSGModalFilterUPP(SGModalFilterProcPtr userRoutine)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGGrabBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGGrabBottleUPP
NewSGGrabBottleUPP(SGGrabBottleProcPtr userRoutine)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGGrabCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGGrabCompleteBottleUPP
NewSGGrabCompleteBottleUPP(SGGrabCompleteBottleProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGDisplayBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGDisplayBottleUPP
NewSGDisplayBottleUPP(SGDisplayBottleProcPtr userRoutine)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGCompressBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGCompressBottleUPP
NewSGCompressBottleUPP(SGCompressBottleProcPtr userRoutine)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGCompressCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGCompressCompleteBottleUPP
NewSGCompressCompleteBottleUPP(SGCompressCompleteBottleProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGAddFrameBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGAddFrameBottleUPP
NewSGAddFrameBottleUPP(SGAddFrameBottleProcPtr userRoutine)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGTransferFrameBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGTransferFrameBottleUPP
NewSGTransferFrameBottleUPP(SGTransferFrameBottleProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGGrabCompressCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGGrabCompressCompleteBottleUPP
NewSGGrabCompressCompleteBottleUPP(SGGrabCompressCompleteBottleProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewSGDisplayCompressBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern SGDisplayCompressBottleUPP
NewSGDisplayCompressBottleUPP(SGDisplayCompressBottleProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeDataHCompletionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeDataHCompletionUPP(DataHCompletionUPP userUPP)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeVdigIntUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeVdigIntUPP(VdigIntUPP userUPP)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeStartDocumentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeStartDocumentHandlerUPP(StartDocumentHandlerUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeEndDocumentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeEndDocumentHandlerUPP(EndDocumentHandlerUPP userUPP)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeStartElementHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeStartElementHandlerUPP(StartElementHandlerUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeEndElementHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeEndElementHandlerUPP(EndElementHandlerUPP userUPP)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeCharDataHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeCharDataHandlerUPP(CharDataHandlerUPP userUPP)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposePreprocessInstructionHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposePreprocessInstructionHandlerUPP(PreprocessInstructionHandlerUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeCommentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeCommentHandlerUPP(CommentHandlerUPP userUPP)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeCDataHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeCDataHandlerUPP(CDataHandlerUPP userUPP)               AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  DisposeSGDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGDataUPP(SGDataUPP userUPP)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGModalFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGModalFilterUPP(SGModalFilterUPP userUPP)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGGrabBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGGrabBottleUPP(SGGrabBottleUPP userUPP)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGGrabCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGGrabCompleteBottleUPP(SGGrabCompleteBottleUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGDisplayBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGDisplayBottleUPP(SGDisplayBottleUPP userUPP)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGCompressBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGCompressBottleUPP(SGCompressBottleUPP userUPP)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGCompressCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGCompressCompleteBottleUPP(SGCompressCompleteBottleUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGAddFrameBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGAddFrameBottleUPP(SGAddFrameBottleUPP userUPP)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGTransferFrameBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGTransferFrameBottleUPP(SGTransferFrameBottleUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGGrabCompressCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGGrabCompressCompleteBottleUPP(SGGrabCompressCompleteBottleUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeSGDisplayCompressBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeSGDisplayCompressBottleUPP(SGDisplayCompressBottleUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeDataHCompletionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeDataHCompletionUPP(
  Ptr                 request,
  long                refcon,
  OSErr               err,
  DataHCompletionUPP  userUPP)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeVdigIntUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeVdigIntUPP(
  long        flags,
  long        refcon,
  VdigIntUPP  userUPP)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeStartDocumentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeStartDocumentHandlerUPP(
  long                     refcon,
  StartDocumentHandlerUPP  userUPP)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeEndDocumentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeEndDocumentHandlerUPP(
  long                   refcon,
  EndDocumentHandlerUPP  userUPP)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeStartElementHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeStartElementHandlerUPP(
  const char *            name,
  const char **           atts,
  long                    refcon,
  StartElementHandlerUPP  userUPP)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeEndElementHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeEndElementHandlerUPP(
  const char *          name,
  long                  refcon,
  EndElementHandlerUPP  userUPP)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeCharDataHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeCharDataHandlerUPP(
  const char *        charData,
  long                refcon,
  CharDataHandlerUPP  userUPP)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokePreprocessInstructionHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokePreprocessInstructionHandlerUPP(
  const char *                     name,
  const char *const                atts[],
  long                             refcon,
  PreprocessInstructionHandlerUPP  userUPP)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeCommentHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeCommentHandlerUPP(
  const char *       comment,
  long               refcon,
  CommentHandlerUPP  userUPP)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeCDataHandlerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeCDataHandlerUPP(
  const char *     cdata,
  long             refcon,
  CDataHandlerUPP  userUPP)                                   AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  InvokeSGDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeSGDataUPP(
  SGChannel  c,
  Ptr        p,
  long       len,
  long *     offset,
  long       chRefCon,
  TimeValue  time,
  short      writeType,
  long       refCon,
  SGDataUPP  userUPP)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGModalFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern Boolean
InvokeSGModalFilterUPP(
  DialogRef            theDialog,
  const EventRecord *  theEvent,
  short *              itemHit,
  long                 refCon,
  SGModalFilterUPP     userUPP)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGGrabBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGGrabBottleUPP(
  SGChannel        c,
  short            bufferNum,
  long             refCon,
  SGGrabBottleUPP  userUPP)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGGrabCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGGrabCompleteBottleUPP(
  SGChannel                c,
  short                    bufferNum,
  Boolean *                done,
  long                     refCon,
  SGGrabCompleteBottleUPP  userUPP)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGDisplayBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGDisplayBottleUPP(
  SGChannel           c,
  short               bufferNum,
  MatrixRecord *      mp,
  RgnHandle           clipRgn,
  long                refCon,
  SGDisplayBottleUPP  userUPP)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGCompressBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGCompressBottleUPP(
  SGChannel            c,
  short                bufferNum,
  long                 refCon,
  SGCompressBottleUPP  userUPP)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGCompressCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGCompressCompleteBottleUPP(
  SGChannel                    c,
  short                        bufferNum,
  Boolean *                    done,
  SGCompressInfo *             ci,
  long                         refCon,
  SGCompressCompleteBottleUPP  userUPP)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGAddFrameBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGAddFrameBottleUPP(
  SGChannel               c,
  short                   bufferNum,
  TimeValue               atTime,
  TimeScale               scale,
  const SGCompressInfo *  ci,
  long                    refCon,
  SGAddFrameBottleUPP     userUPP)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGTransferFrameBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGTransferFrameBottleUPP(
  SGChannel                 c,
  short                     bufferNum,
  MatrixRecord *            mp,
  RgnHandle                 clipRgn,
  long                      refCon,
  SGTransferFrameBottleUPP  userUPP)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGGrabCompressCompleteBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGGrabCompressCompleteBottleUPP(
  SGChannel                        c,
  UInt8 *                          queuedFrameCount,
  SGCompressInfo *                 ci,
  TimeRecord *                     t,
  long                             refCon,
  SGGrabCompressCompleteBottleUPP  userUPP)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeSGDisplayCompressBottleUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeSGDisplayCompressBottleUPP(
  SGChannel                   c,
  Ptr                         dataPtr,
  ImageDescriptionHandle      desc,
  MatrixRecord *              mp,
  RgnHandle                   clipRgn,
  long                        refCon,
  SGDisplayCompressBottleUPP  userUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* selectors for component calls */
enum {
    kClockGetTimeSelect                        = 0x0001,
    kClockNewCallBackSelect                    = 0x0002,
    kClockDisposeCallBackSelect                = 0x0003,
    kClockCallMeWhenSelect                     = 0x0004,
    kClockCancelCallBackSelect                 = 0x0005,
    kClockRateChangedSelect                    = 0x0006,
    kClockTimeChangedSelect                    = 0x0007,
    kClockSetTimeBaseSelect                    = 0x0008,
    kClockStartStopChangedSelect               = 0x0009,
    kClockGetRateSelect                        = 0x000A,
    kSCGetCompressionExtendedSelect            = 0x0001,
    kSCPositionRectSelect                      = 0x0002,
    kSCPositionDialogSelect                    = 0x0003,
    kSCSetTestImagePictHandleSelect            = 0x0004,
    kSCSetTestImagePictFileSelect              = 0x0005,
    kSCSetTestImagePixMapSelect                = 0x0006,
    kSCGetBestDeviceRectSelect                 = 0x0007,
    kSCRequestImageSettingsSelect              = 0x000A,
    kSCCompressImageSelect                     = 0x000B,
    kSCCompressPictureSelect                   = 0x000C,
    kSCCompressPictureFileSelect               = 0x000D,
    kSCRequestSequenceSettingsSelect           = 0x000E,
    kSCCompressSequenceBeginSelect             = 0x000F,
    kSCCompressSequenceFrameSelect             = 0x0010,
    kSCCompressSequenceEndSelect               = 0x0011,
    kSCDefaultPictHandleSettingsSelect         = 0x0012,
    kSCDefaultPictFileSettingsSelect           = 0x0013,
    kSCDefaultPixMapSettingsSelect             = 0x0014,
    kSCGetInfoSelect                           = 0x0015,
    kSCSetInfoSelect                           = 0x0016,
    kSCNewGWorldSelect                         = 0x0017,
    kSCSetCompressFlagsSelect                  = 0x0018,
    kSCGetCompressFlagsSelect                  = 0x0019,
    kSCGetSettingsAsTextSelect                 = 0x001A,
    kSCGetSettingsAsAtomContainerSelect        = 0x001B,
    kSCSetSettingsFromAtomContainerSelect      = 0x001C,
    kSCCompressSequenceFrameAsyncSelect        = 0x001D,
    kSCAsyncIdleSelect                         = 0x001E,
    kTweenerInitializeSelect                   = 0x0001,
    kTweenerDoTweenSelect                      = 0x0002,
    kTweenerResetSelect                        = 0x0003,
    kTCGetCurrentTimeCodeSelect                = 0x0101,
    kTCGetTimeCodeAtTimeSelect                 = 0x0102,
    kTCTimeCodeToStringSelect                  = 0x0103,
    kTCTimeCodeToFrameNumberSelect             = 0x0104,
    kTCFrameNumberToTimeCodeSelect             = 0x0105,
    kTCGetSourceRefSelect                      = 0x0106,
    kTCSetSourceRefSelect                      = 0x0107,
    kTCSetTimeCodeFlagsSelect                  = 0x0108,
    kTCGetTimeCodeFlagsSelect                  = 0x0109,
    kTCSetDisplayOptionsSelect                 = 0x010A,
    kTCGetDisplayOptionsSelect                 = 0x010B,
    kMovieImportHandleSelect                   = 0x0001,
    kMovieImportFileSelect                     = 0x0002,
    kMovieImportSetSampleDurationSelect        = 0x0003,
    kMovieImportSetSampleDescriptionSelect     = 0x0004,
    kMovieImportSetMediaFileSelect             = 0x0005,
    kMovieImportSetDimensionsSelect            = 0x0006,
    kMovieImportSetChunkSizeSelect             = 0x0007,
    kMovieImportSetProgressProcSelect          = 0x0008,
    kMovieImportSetAuxiliaryDataSelect         = 0x0009,
    kMovieImportSetFromScrapSelect             = 0x000A,
    kMovieImportDoUserDialogSelect             = 0x000B,
    kMovieImportSetDurationSelect              = 0x000C,
    kMovieImportGetAuxiliaryDataTypeSelect     = 0x000D,
    kMovieImportValidateSelect                 = 0x000E,
    kMovieImportGetFileTypeSelect              = 0x000F,
    kMovieImportDataRefSelect                  = 0x0010,
    kMovieImportGetSampleDescriptionSelect     = 0x0011,
    kMovieImportGetMIMETypeListSelect          = 0x0012,
    kMovieImportSetOffsetAndLimitSelect        = 0x0013,
    kMovieImportGetSettingsAsAtomContainerSelect = 0x0014,
    kMovieImportSetSettingsFromAtomContainerSelect = 0x0015,
    kMovieImportSetOffsetAndLimit64Select      = 0x0016,
    kMovieImportIdleSelect                     = 0x0017,
    kMovieImportValidateDataRefSelect          = 0x0018,
    kMovieImportGetLoadStateSelect             = 0x0019,
    kMovieImportGetMaxLoadedTimeSelect         = 0x001A,
    kMovieImportEstimateCompletionTimeSelect   = 0x001B,
    kMovieImportSetDontBlockSelect             = 0x001C,
    kMovieImportGetDontBlockSelect             = 0x001D,
    kMovieImportSetIdleManagerSelect           = 0x001E,
    kMovieImportSetNewMovieFlagsSelect         = 0x001F,
    kMovieImportGetDestinationMediaTypeSelect  = 0x0020,
    kMovieExportToHandleSelect                 = 0x0080,
    kMovieExportToFileSelect                   = 0x0081,
    kMovieExportGetAuxiliaryDataSelect         = 0x0083,
    kMovieExportSetProgressProcSelect          = 0x0084,
    kMovieExportSetSampleDescriptionSelect     = 0x0085,
    kMovieExportDoUserDialogSelect             = 0x0086,
    kMovieExportGetCreatorTypeSelect           = 0x0087,
    kMovieExportToDataRefSelect                = 0x0088,
    kMovieExportFromProceduresToDataRefSelect  = 0x0089,
    kMovieExportAddDataSourceSelect            = 0x008A,
    kMovieExportValidateSelect                 = 0x008B,
    kMovieExportGetSettingsAsAtomContainerSelect = 0x008C,
    kMovieExportSetSettingsFromAtomContainerSelect = 0x008D,
    kMovieExportGetFileNameExtensionSelect     = 0x008E,
    kMovieExportGetShortFileTypeStringSelect   = 0x008F,
    kMovieExportGetSourceMediaTypeSelect       = 0x0090,
    kMovieExportSetGetMoviePropertyProcSelect  = 0x0091,
    kTextExportGetDisplayDataSelect            = 0x0100,
    kTextExportGetTimeFractionSelect           = 0x0101,
    kTextExportSetTimeFractionSelect           = 0x0102,
    kTextExportGetSettingsSelect               = 0x0103,
    kTextExportSetSettingsSelect               = 0x0104,
    kMIDIImportGetSettingsSelect               = 0x0100,
    kMIDIImportSetSettingsSelect               = 0x0101,
    kMovieExportNewGetDataAndPropertiesProcsSelect = 0x0100,
    kMovieExportDisposeGetDataAndPropertiesProcsSelect = 0x0101,
    kGraphicsImageImportSetSequenceEnabledSelect = 0x0100,
    kGraphicsImageImportGetSequenceEnabledSelect = 0x0101,
    kPreviewShowDataSelect                     = 0x0001,
    kPreviewMakePreviewSelect                  = 0x0002,
    kPreviewMakePreviewReferenceSelect         = 0x0003,
    kPreviewEventSelect                        = 0x0004,
    kDataCodecDecompressSelect                 = 0x0001,
    kDataCodecGetCompressBufferSizeSelect      = 0x0002,
    kDataCodecCompressSelect                   = 0x0003,
    kDataCodecBeginInterruptSafeSelect         = 0x0004,
    kDataCodecEndInterruptSafeSelect           = 0x0005,
    kDataCodecDecompressPartialSelect          = 0x0006,
    kDataCodecCompressPartialSelect            = 0x0007,
    kDataHGetDataSelect                        = 0x0002,
    kDataHPutDataSelect                        = 0x0003,
    kDataHFlushDataSelect                      = 0x0004,
    kDataHOpenForWriteSelect                   = 0x0005,
    kDataHCloseForWriteSelect                  = 0x0006,
    kDataHOpenForReadSelect                    = 0x0008,
    kDataHCloseForReadSelect                   = 0x0009,
    kDataHSetDataRefSelect                     = 0x000A,
    kDataHGetDataRefSelect                     = 0x000B,
    kDataHCompareDataRefSelect                 = 0x000C,
    kDataHTaskSelect                           = 0x000D,
    kDataHScheduleDataSelect                   = 0x000E,
    kDataHFinishDataSelect                     = 0x000F,
    kDataHFlushCacheSelect                     = 0x0010,
    kDataHResolveDataRefSelect                 = 0x0011,
    kDataHGetFileSizeSelect                    = 0x0012,
    kDataHCanUseDataRefSelect                  = 0x0013,
    kDataHGetVolumeListSelect                  = 0x0014,
    kDataHWriteSelect                          = 0x0015,
    kDataHPreextendSelect                      = 0x0016,
    kDataHSetFileSizeSelect                    = 0x0017,
    kDataHGetFreeSpaceSelect                   = 0x0018,
    kDataHCreateFileSelect                     = 0x0019,
    kDataHGetPreferredBlockSizeSelect          = 0x001A,
    kDataHGetDeviceIndexSelect                 = 0x001B,
    kDataHIsStreamingDataHandlerSelect         = 0x001C,
    kDataHGetDataInBufferSelect                = 0x001D,
    kDataHGetScheduleAheadTimeSelect           = 0x001E,
    kDataHSetCacheSizeLimitSelect              = 0x001F,
    kDataHGetCacheSizeLimitSelect              = 0x0020,
    kDataHGetMovieSelect                       = 0x0021,
    kDataHAddMovieSelect                       = 0x0022,
    kDataHUpdateMovieSelect                    = 0x0023,
    kDataHDoesBufferSelect                     = 0x0024,
    kDataHGetFileNameSelect                    = 0x0025,
    kDataHGetAvailableFileSizeSelect           = 0x0026,
    kDataHGetMacOSFileTypeSelect               = 0x0027,
    kDataHGetMIMETypeSelect                    = 0x0028,
    kDataHSetDataRefWithAnchorSelect           = 0x0029,
    kDataHGetDataRefWithAnchorSelect           = 0x002A,
    kDataHSetMacOSFileTypeSelect               = 0x002B,
    kDataHSetTimeBaseSelect                    = 0x002C,
    kDataHGetInfoFlagsSelect                   = 0x002D,
    kDataHScheduleData64Select                 = 0x002E,
    kDataHWrite64Select                        = 0x002F,
    kDataHGetFileSize64Select                  = 0x0030,
    kDataHPreextend64Select                    = 0x0031,
    kDataHSetFileSize64Select                  = 0x0032,
    kDataHGetFreeSpace64Select                 = 0x0033,
    kDataHAppend64Select                       = 0x0034,
    kDataHReadAsyncSelect                      = 0x0035,
    kDataHPollReadSelect                       = 0x0036,
    kDataHGetDataAvailabilitySelect            = 0x0037,
    kDataHGetFileSizeAsyncSelect               = 0x003A,
    kDataHGetDataRefAsTypeSelect               = 0x003B,
    kDataHSetDataRefExtensionSelect            = 0x003C,
    kDataHGetDataRefExtensionSelect            = 0x003D,
    kDataHGetMovieWithFlagsSelect              = 0x003E,
    kDataHGetFileTypeOrderingSelect            = 0x0040,
    kDataHCreateFileWithFlagsSelect            = 0x0041,
    kDataHGetMIMETypeAsyncSelect               = 0x0042,
    kDataHGetInfoSelect                        = 0x0043,
    kDataHSetIdleManagerSelect                 = 0x0044,
    kDataHDeleteFileSelect                     = 0x0045,
    kDataHSetMovieUsageFlagsSelect             = 0x0046,
    kDataHUseTemporaryDataRefSelect            = 0x0047,
    kDataHGetTemporaryDataRefCapabilitiesSelect = 0x0048,
    kDataHRenameFileSelect                     = 0x0049,
    kDataHPlaybackHintsSelect                  = 0x0103,
    kDataHPlaybackHints64Select                = 0x010E,
    kDataHGetDataRateSelect                    = 0x0110,
    kDataHSetTimeHintsSelect                   = 0x0111,
    kVDGetMaxSrcRectSelect                     = 0x0001,
    kVDGetActiveSrcRectSelect                  = 0x0002,
    kVDSetDigitizerRectSelect                  = 0x0003,
    kVDGetDigitizerRectSelect                  = 0x0004,
    kVDGetVBlankRectSelect                     = 0x0005,
    kVDGetMaskPixMapSelect                     = 0x0006,
    kVDGetPlayThruDestinationSelect            = 0x0008,
    kVDUseThisCLUTSelect                       = 0x0009,
    kVDSetInputGammaValueSelect                = 0x000A,
    kVDGetInputGammaValueSelect                = 0x000B,
    kVDSetBrightnessSelect                     = 0x000C,
    kVDGetBrightnessSelect                     = 0x000D,
    kVDSetContrastSelect                       = 0x000E,
    kVDSetHueSelect                            = 0x000F,
    kVDSetSharpnessSelect                      = 0x0010,
    kVDSetSaturationSelect                     = 0x0011,
    kVDGetContrastSelect                       = 0x0012,
    kVDGetHueSelect                            = 0x0013,
    kVDGetSharpnessSelect                      = 0x0014,
    kVDGetSaturationSelect                     = 0x0015,
    kVDGrabOneFrameSelect                      = 0x0016,
    kVDGetMaxAuxBufferSelect                   = 0x0017,
    kVDGetDigitizerInfoSelect                  = 0x0019,
    kVDGetCurrentFlagsSelect                   = 0x001A,
    kVDSetKeyColorSelect                       = 0x001B,
    kVDGetKeyColorSelect                       = 0x001C,
    kVDAddKeyColorSelect                       = 0x001D,
    kVDGetNextKeyColorSelect                   = 0x001E,
    kVDSetKeyColorRangeSelect                  = 0x001F,
    kVDGetKeyColorRangeSelect                  = 0x0020,
    kVDSetDigitizerUserInterruptSelect         = 0x0021,
    kVDSetInputColorSpaceModeSelect            = 0x0022,
    kVDGetInputColorSpaceModeSelect            = 0x0023,
    kVDSetClipStateSelect                      = 0x0024,
    kVDGetClipStateSelect                      = 0x0025,
    kVDSetClipRgnSelect                        = 0x0026,
    kVDClearClipRgnSelect                      = 0x0027,
    kVDGetCLUTInUseSelect                      = 0x0028,
    kVDSetPLLFilterTypeSelect                  = 0x0029,
    kVDGetPLLFilterTypeSelect                  = 0x002A,
    kVDGetMaskandValueSelect                   = 0x002B,
    kVDSetMasterBlendLevelSelect               = 0x002C,
    kVDSetPlayThruDestinationSelect            = 0x002D,
    kVDSetPlayThruOnOffSelect                  = 0x002E,
    kVDSetFieldPreferenceSelect                = 0x002F,
    kVDGetFieldPreferenceSelect                = 0x0030,
    kVDPreflightDestinationSelect              = 0x0032,
    kVDPreflightGlobalRectSelect               = 0x0033,
    kVDSetPlayThruGlobalRectSelect             = 0x0034,
    kVDSetInputGammaRecordSelect               = 0x0035,
    kVDGetInputGammaRecordSelect               = 0x0036,
    kVDSetBlackLevelValueSelect                = 0x0037,
    kVDGetBlackLevelValueSelect                = 0x0038,
    kVDSetWhiteLevelValueSelect                = 0x0039,
    kVDGetWhiteLevelValueSelect                = 0x003A,
    kVDGetVideoDefaultsSelect                  = 0x003B,
    kVDGetNumberOfInputsSelect                 = 0x003C,
    kVDGetInputFormatSelect                    = 0x003D,
    kVDSetInputSelect                          = 0x003E,
    kVDGetInputSelect                          = 0x003F,
    kVDSetInputStandardSelect                  = 0x0040,
    kVDSetupBuffersSelect                      = 0x0041,
    kVDGrabOneFrameAsyncSelect                 = 0x0042,
    kVDDoneSelect                              = 0x0043,
    kVDSetCompressionSelect                    = 0x0044,
    kVDCompressOneFrameAsyncSelect             = 0x0045,
    kVDCompressDoneSelect                      = 0x0046,
    kVDReleaseCompressBufferSelect             = 0x0047,
    kVDGetImageDescriptionSelect               = 0x0048,
    kVDResetCompressSequenceSelect             = 0x0049,
    kVDSetCompressionOnOffSelect               = 0x004A,
    kVDGetCompressionTypesSelect               = 0x004B,
    kVDSetTimeBaseSelect                       = 0x004C,
    kVDSetFrameRateSelect                      = 0x004D,
    kVDGetDataRateSelect                       = 0x004E,
    kVDGetSoundInputDriverSelect               = 0x004F,
    kVDGetDMADepthsSelect                      = 0x0050,
    kVDGetPreferredTimeScaleSelect             = 0x0051,
    kVDReleaseAsyncBuffersSelect               = 0x0052,
    kVDSetDataRateSelect                       = 0x0054,
    kVDGetTimeCodeSelect                       = 0x0055,
    kVDUseSafeBuffersSelect                    = 0x0056,
    kVDGetSoundInputSourceSelect               = 0x0057,
    kVDGetCompressionTimeSelect                = 0x0058,
    kVDSetPreferredPacketSizeSelect            = 0x0059,
    kVDSetPreferredImageDimensionsSelect       = 0x005A,
    kVDGetPreferredImageDimensionsSelect       = 0x005B,
    kVDGetInputNameSelect                      = 0x005C,
    kVDSetDestinationPortSelect                = 0x005D,
    kVDGetDeviceNameAndFlagsSelect             = 0x005E,
    kVDCaptureStateChangingSelect              = 0x005F,
    kVDGetUniqueIDsSelect                      = 0x0060,
    kVDSelectUniqueIDsSelect                   = 0x0061,
    kXMLParseDataRefSelect                     = 0x0001,
    kXMLParseFileSelect                        = 0x0002,
    kXMLParseDisposeXMLDocSelect               = 0x0003,
    kXMLParseGetDetailedParseErrorSelect       = 0x0004,
    kXMLParseAddElementSelect                  = 0x0005,
    kXMLParseAddAttributeSelect                = 0x0006,
    kXMLParseAddMultipleAttributesSelect       = 0x0007,
    kXMLParseAddAttributeAndValueSelect        = 0x0008,
    kXMLParseAddMultipleAttributesAndValuesSelect = 0x0009,
    kXMLParseAddAttributeValueKindSelect       = 0x000A,
    kXMLParseAddNameSpaceSelect                = 0x000B,
    kXMLParseSetOffsetAndLimitSelect           = 0x000C,
    kXMLParseSetEventParseRefConSelect         = 0x000D,
    kXMLParseSetStartDocumentHandlerSelect     = 0x000E,
    kXMLParseSetEndDocumentHandlerSelect       = 0x000F,
    kXMLParseSetStartElementHandlerSelect      = 0x0010,
    kXMLParseSetEndElementHandlerSelect        = 0x0011,
    kXMLParseSetCharDataHandlerSelect          = 0x0012,
    kXMLParseSetPreprocessInstructionHandlerSelect = 0x0013,
    kXMLParseSetCommentHandlerSelect           = 0x0014,
    kXMLParseSetCDataHandlerSelect             = 0x0015,
    kSGInitializeSelect                        = 0x0001,
    kSGSetDataOutputSelect                     = 0x0002,
    kSGGetDataOutputSelect                     = 0x0003,
    kSGSetGWorldSelect                         = 0x0004,
    kSGGetGWorldSelect                         = 0x0005,
    kSGNewChannelSelect                        = 0x0006,
    kSGDisposeChannelSelect                    = 0x0007,
    kSGStartPreviewSelect                      = 0x0010,
    kSGStartRecordSelect                       = 0x0011,
    kSGIdleSelect                              = 0x0012,
    kSGStopSelect                              = 0x0013,
    kSGPauseSelect                             = 0x0014,
    kSGPrepareSelect                           = 0x0015,
    kSGReleaseSelect                           = 0x0016,
    kSGGetMovieSelect                          = 0x0017,
    kSGSetMaximumRecordTimeSelect              = 0x0018,
    kSGGetMaximumRecordTimeSelect              = 0x0019,
    kSGGetStorageSpaceRemainingSelect          = 0x001A,
    kSGGetTimeRemainingSelect                  = 0x001B,
    kSGGrabPictSelect                          = 0x001C,
    kSGGetLastMovieResIDSelect                 = 0x001D,
    kSGSetFlagsSelect                          = 0x001E,
    kSGGetFlagsSelect                          = 0x001F,
    kSGSetDataProcSelect                       = 0x0020,
    kSGNewChannelFromComponentSelect           = 0x0021,
    kSGDisposeDeviceListSelect                 = 0x0022,
    kSGAppendDeviceListToMenuSelect            = 0x0023,
    kSGSetSettingsSelect                       = 0x0024,
    kSGGetSettingsSelect                       = 0x0025,
    kSGGetIndChannelSelect                     = 0x0026,
    kSGUpdateSelect                            = 0x0027,
    kSGGetPauseSelect                          = 0x0028,
    kSGSettingsDialogSelect                    = 0x0029,
    kSGGetAlignmentProcSelect                  = 0x002A,
    kSGSetChannelSettingsSelect                = 0x002B,
    kSGGetChannelSettingsSelect                = 0x002C,
    kSGGetModeSelect                           = 0x002D,
    kSGSetDataRefSelect                        = 0x002E,
    kSGGetDataRefSelect                        = 0x002F,
    kSGNewOutputSelect                         = 0x0030,
    kSGDisposeOutputSelect                     = 0x0031,
    kSGSetOutputFlagsSelect                    = 0x0032,
    kSGSetChannelOutputSelect                  = 0x0033,
    kSGGetDataOutputStorageSpaceRemainingSelect = 0x0034,
    kSGHandleUpdateEventSelect                 = 0x0035,
    kSGSetOutputNextOutputSelect               = 0x0036,
    kSGGetOutputNextOutputSelect               = 0x0037,
    kSGSetOutputMaximumOffsetSelect            = 0x0038,
    kSGGetOutputMaximumOffsetSelect            = 0x0039,
    kSGGetOutputDataReferenceSelect            = 0x003A,
    kSGWriteExtendedMovieDataSelect            = 0x003B,
    kSGGetStorageSpaceRemaining64Select        = 0x003C,
    kSGGetDataOutputStorageSpaceRemaining64Select = 0x003D,
    kSGWriteMovieDataSelect                    = 0x0100,
    kSGAddFrameReferenceSelect                 = 0x0101,
    kSGGetNextFrameReferenceSelect             = 0x0102,
    kSGGetTimeBaseSelect                       = 0x0103,
    kSGSortDeviceListSelect                    = 0x0104,
    kSGAddMovieDataSelect                      = 0x0105,
    kSGChangedSourceSelect                     = 0x0106,
    kSGAddExtendedFrameReferenceSelect         = 0x0107,
    kSGGetNextExtendedFrameReferenceSelect     = 0x0108,
    kSGAddExtendedMovieDataSelect              = 0x0109,
    kSGAddOutputDataRefToMediaSelect           = 0x010A,
    kSGSetSettingsSummarySelect                = 0x010B,
    kSGSetChannelUsageSelect                   = 0x0080,
    kSGGetChannelUsageSelect                   = 0x0081,
    kSGSetChannelBoundsSelect                  = 0x0082,
    kSGGetChannelBoundsSelect                  = 0x0083,
    kSGSetChannelVolumeSelect                  = 0x0084,
    kSGGetChannelVolumeSelect                  = 0x0085,
    kSGGetChannelInfoSelect                    = 0x0086,
    kSGSetChannelPlayFlagsSelect               = 0x0087,
    kSGGetChannelPlayFlagsSelect               = 0x0088,
    kSGSetChannelMaxFramesSelect               = 0x0089,
    kSGGetChannelMaxFramesSelect               = 0x008A,
    kSGSetChannelRefConSelect                  = 0x008B,
    kSGSetChannelClipSelect                    = 0x008C,
    kSGGetChannelClipSelect                    = 0x008D,
    kSGGetChannelSampleDescriptionSelect       = 0x008E,
    kSGGetChannelDeviceListSelect              = 0x008F,
    kSGSetChannelDeviceSelect                  = 0x0090,
    kSGSetChannelMatrixSelect                  = 0x0091,
    kSGGetChannelMatrixSelect                  = 0x0092,
    kSGGetChannelTimeScaleSelect               = 0x0093,
    kSGChannelPutPictureSelect                 = 0x0094,
    kSGChannelSetRequestedDataRateSelect       = 0x0095,
    kSGChannelGetRequestedDataRateSelect       = 0x0096,
    kSGChannelSetDataSourceNameSelect          = 0x0097,
    kSGChannelGetDataSourceNameSelect          = 0x0098,
    kSGChannelSetCodecSettingsSelect           = 0x0099,
    kSGChannelGetCodecSettingsSelect           = 0x009A,
    kSGGetChannelTimeBaseSelect                = 0x009B,
    kSGGetChannelRefConSelect                  = 0x009C,
    kSGGetChannelDeviceAndInputNamesSelect     = 0x009D,
    kSGSetChannelDeviceInputSelect             = 0x009E,
    kSGSetChannelSettingsStateChangingSelect   = 0x009F,
    kSGInitChannelSelect                       = 0x0180,
    kSGWriteSamplesSelect                      = 0x0181,
    kSGGetDataRateSelect                       = 0x0182,
    kSGAlignChannelRectSelect                  = 0x0183,
    kSGPanelGetDitlSelect                      = 0x0200,
    kSGPanelGetTitleSelect                     = 0x0201,
    kSGPanelCanRunSelect                       = 0x0202,
    kSGPanelInstallSelect                      = 0x0203,
    kSGPanelEventSelect                        = 0x0204,
    kSGPanelItemSelect                         = 0x0205,
    kSGPanelRemoveSelect                       = 0x0206,
    kSGPanelSetGrabberSelect                   = 0x0207,
    kSGPanelSetResFileSelect                   = 0x0208,
    kSGPanelGetSettingsSelect                  = 0x0209,
    kSGPanelSetSettingsSelect                  = 0x020A,
    kSGPanelValidateInputSelect                = 0x020B,
    kSGPanelSetEventFilterSelect               = 0x020C,
    kSGPanelGetDITLForSizeSelect               = 0x020D,
    kSGGetSrcVideoBoundsSelect                 = 0x0100,
    kSGSetVideoRectSelect                      = 0x0101,
    kSGGetVideoRectSelect                      = 0x0102,
    kSGGetVideoCompressorTypeSelect            = 0x0103,
    kSGSetVideoCompressorTypeSelect            = 0x0104,
    kSGSetVideoCompressorSelect                = 0x0105,
    kSGGetVideoCompressorSelect                = 0x0106,
    kSGGetVideoDigitizerComponentSelect        = 0x0107,
    kSGSetVideoDigitizerComponentSelect        = 0x0108,
    kSGVideoDigitizerChangedSelect             = 0x0109,
    kSGSetVideoBottlenecksSelect               = 0x010A,
    kSGGetVideoBottlenecksSelect               = 0x010B,
    kSGGrabFrameSelect                         = 0x010C,
    kSGGrabFrameCompleteSelect                 = 0x010D,
    kSGDisplayFrameSelect                      = 0x010E,
    kSGCompressFrameSelect                     = 0x010F,
    kSGCompressFrameCompleteSelect             = 0x0110,
    kSGAddFrameSelect                          = 0x0111,
    kSGTransferFrameForCompressSelect          = 0x0112,
    kSGSetCompressBufferSelect                 = 0x0113,
    kSGGetCompressBufferSelect                 = 0x0114,
    kSGGetBufferInfoSelect                     = 0x0115,
    kSGSetUseScreenBufferSelect                = 0x0116,
    kSGGetUseScreenBufferSelect                = 0x0117,
    kSGGrabCompressCompleteSelect              = 0x0118,
    kSGDisplayCompressSelect                   = 0x0119,
    kSGSetFrameRateSelect                      = 0x011A,
    kSGGetFrameRateSelect                      = 0x011B,
    kSGSetPreferredPacketSizeSelect            = 0x0121,
    kSGGetPreferredPacketSizeSelect            = 0x0122,
    kSGSetUserVideoCompressorListSelect        = 0x0123,
    kSGGetUserVideoCompressorListSelect        = 0x0124,
    kSGSetSoundInputDriverSelect               = 0x0100,
    kSGGetSoundInputDriverSelect               = 0x0101,
    kSGSoundInputDriverChangedSelect           = 0x0102,
    kSGSetSoundRecordChunkSizeSelect           = 0x0103,
    kSGGetSoundRecordChunkSizeSelect           = 0x0104,
    kSGSetSoundInputRateSelect                 = 0x0105,
    kSGGetSoundInputRateSelect                 = 0x0106,
    kSGSetSoundInputParametersSelect           = 0x0107,
    kSGGetSoundInputParametersSelect           = 0x0108,
    kSGSetAdditionalSoundRatesSelect           = 0x0109,
    kSGGetAdditionalSoundRatesSelect           = 0x010A,
    kSGSetFontNameSelect                       = 0x0100,
    kSGSetFontSizeSelect                       = 0x0101,
    kSGSetTextForeColorSelect                  = 0x0102,
    kSGSetTextBackColorSelect                  = 0x0103,
    kSGSetJustificationSelect                  = 0x0104,
    kSGGetTextReturnToSpaceValueSelect         = 0x0105,
    kSGSetTextReturnToSpaceValueSelect         = 0x0106,
    kSGGetInstrumentSelect                     = 0x0100,
    kSGSetInstrumentSelect                     = 0x0101,
    kQTVideoOutputGetDisplayModeListSelect     = 0x0001,
    kQTVideoOutputGetCurrentClientNameSelect   = 0x0002,
    kQTVideoOutputSetClientNameSelect          = 0x0003,
    kQTVideoOutputGetClientNameSelect          = 0x0004,
    kQTVideoOutputBeginSelect                  = 0x0005,
    kQTVideoOutputEndSelect                    = 0x0006,
    kQTVideoOutputSetDisplayModeSelect         = 0x0007,
    kQTVideoOutputGetDisplayModeSelect         = 0x0008,
    kQTVideoOutputCustomConfigureDisplaySelect = 0x0009,
    kQTVideoOutputSaveStateSelect              = 0x000A,
    kQTVideoOutputRestoreStateSelect           = 0x000B,
    kQTVideoOutputGetGWorldSelect              = 0x000C,
    kQTVideoOutputGetGWorldParametersSelect    = 0x000D,
    kQTVideoOutputGetIndSoundOutputSelect      = 0x000E,
    kQTVideoOutputGetClockSelect               = 0x000F,
    kQTVideoOutputSetEchoPortSelect            = 0x0010,
    kQTVideoOutputGetIndImageDecompressorSelect = 0x0011,
    kQTVideoOutputBaseSetEchoPortSelect        = 0x0012
};


#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __QUICKTIMECOMPONENTS__ */

