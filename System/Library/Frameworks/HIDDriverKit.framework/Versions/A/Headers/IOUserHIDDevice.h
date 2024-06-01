/* iig(DriverKit-73.0.1) generated from IOUserHIDDevice.iig */

/* IOUserHIDDevice.iig:1-37 */
/*
 * Copyright (c) 2018-2019 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _HIDDRIVERKIT_IOUSERHIDDEVICE_H
#define _HIDDRIVERKIT_IOUSERHIDDEVICE_H

#include <DriverKit/IOService.h>  /* .iig include */
#include <HIDDriverKit/IOHIDDevice.h>  /* .iig include */

class  OSData;
class  OSDictionary;

/* class IOUserHIDDevice IOUserHIDDevice.iig:38-106 */


#define IOUserHIDDevice_Start_Args \
        IOService * provider

#define IOUserHIDDevice_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUserHIDDevice * self, const IORPC rpc);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    Start_Impl(IOService_Start_Args);\
\
\
public:\
    /* _Invoke methods */\
\


#define IOUserHIDDevice_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define IOUserHIDDevice_VirtualMethods \
\
public:\
\
    virtual bool\
    handleStart(\
        IOService * provider) APPLE_KEXT_OVERRIDE;\
\
    virtual OSDictionary *\
    newDeviceDescription(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual OSData *\
    newReportDescriptor(\
) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOUserHIDDeviceMetaClass;
extern const OSClassLoadInformation IOUserHIDDevice_Class;

class IOUserHIDDeviceMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUserHIDDeviceInterface : public OSInterface
{
public:
    virtual bool
    handleStart(IOService * provider) = 0;

    virtual OSDictionary *
    newDeviceDescription() = 0;

    virtual OSData *
    newReportDescriptor() = 0;

};

struct IOUserHIDDevice_IVars;
struct IOUserHIDDevice_LocalIVars;

class IOUserHIDDevice : public IOHIDDevice, public IOUserHIDDeviceInterface
{
#if !KERNEL
    friend class IOUserHIDDeviceMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUserHIDDevice_IVars * ivars;
        IOUserHIDDevice_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOHIDDevice;

#if !KERNEL
    IOUserHIDDevice_Methods
    IOUserHIDDevice_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOUserHIDDevice.iig:108- */

#endif /* ! _HIDDRIVERKIT_IOUSERHIDDEVICE_H */
