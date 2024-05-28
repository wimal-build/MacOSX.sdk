/*	CFSocket.h
	Copyright 1999-2001, Apple, Inc. All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFSOCKET__)
#define __COREFOUNDATION_CFSOCKET__ 1

#if !defined(__MACOS8__)

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFData.h>
#include <CoreFoundation/CFPropertyList.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFRunLoop.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

typedef int CFSocketNativeHandle;
typedef struct __CFSocket * CFSocketRef;

/* A CFSocket contains a native socket within a structure that can 
be used to read from the socket in the background and make the data
thus read available using a runloop source.  The callback used for
this may be of three types, as specified by the callBackTypes
argument when creating the CFSocket.

If kCFSocketReadCallBack is used, then data will not be
automatically read, but the callback will be called when data
is available to be read, or a new child socket is waiting to be
accepted.
    
If kCFSocketAcceptCallBack is used, then new child sockets will be
accepted and passed to the callback, with the data argument being
a pointer to a CFSocketNativeHandle.  This is usable only with
connection rendezvous sockets.

If kCFSocketDataCallBack is used, then data will be read in chunks
in the background and passed to the callback, with the data argument
being a CFDataRef.

These three types are mutually exclusive, but any one of them may
have kCFSocketConnectCallBack added to it, if the socket will be
used to connect in the background.  Connect in the background occurs
if CFSocketConnectToAddress is called with a negative timeout
value, in which case the call returns immediately, and a
kCFSocketConnectCallBack is generated when the connect finishes.
In this case the data argument is either NULL, or a pointer to
an SInt32 error code if the connect failed.

Addresses are stored as CFDatas containing a struct sockaddr
appropriate for the protocol family; make sure that all fields are
filled in properly when passing in an address.  Also, do not close
the underlying native socket directly; instead, invalidate the CFSocket.
*/

typedef enum {
    kCFSocketSuccess = 0,
    kCFSocketError = -1,
    kCFSocketTimeout = -2
} CFSocketError;

typedef struct {
    SInt32	protocolFamily;
    SInt32	socketType;
    SInt32	protocol;
    CFDataRef	address;
} CFSocketSignature;

typedef enum {
    kCFSocketNoCallBack = 0,
    kCFSocketReadCallBack = 1,
    kCFSocketAcceptCallBack = 2,
    kCFSocketDataCallBack = 3,
    kCFSocketConnectCallBack = 4
} CFSocketCallBackType;

typedef void (*CFSocketCallBack)(CFSocketRef s, CFSocketCallBackType type, CFDataRef address, const void *data, void *info);
/* If the callback wishes to keep hold of address or data after the point that it returns, then it must copy them. */

typedef struct {
    CFIndex	version;
    void *	info;
    const void *(*retain)(const void *info);
    void	(*release)(const void *info);
    CFStringRef	(*copyDescription)(const void *info);
} CFSocketContext;

CF_EXPORT CFTypeID	CFSocketGetTypeID(void);

CF_EXPORT CFSocketRef	CFSocketCreate(CFAllocatorRef allocator, SInt32 protocolFamily, SInt32 socketType, SInt32 protocol, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);
CF_EXPORT CFSocketRef	CFSocketCreateWithNative(CFAllocatorRef allocator, CFSocketNativeHandle sock, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);
CF_EXPORT CFSocketRef	CFSocketCreateWithSocketSignature(CFAllocatorRef allocator, const CFSocketSignature *signature, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);
CF_EXPORT CFSocketRef	CFSocketCreateConnectedToSocketSignature(CFAllocatorRef allocator, const CFSocketSignature *signature, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context, CFTimeInterval timeout);
/* CFSocketCreateWithSignature creates a socket of the requested type and binds its address (using CFSocketSetAddress) to the requested address.  If this fails, it returns NULL.  CFSocketCreateConnectedToSignature creates a socket suitable for connecting to the requested type and address, and connects it (using CFSocketConnectToAddress).  If this fails, it returns NULL. */

CF_EXPORT CFSocketError	CFSocketSetAddress(CFSocketRef s, CFDataRef address);
CF_EXPORT CFSocketError	CFSocketConnectToAddress(CFSocketRef s, CFDataRef address, CFTimeInterval timeout);
CF_EXPORT void		CFSocketInvalidate(CFSocketRef s);

CF_EXPORT Boolean	CFSocketIsValid(CFSocketRef s);
CF_EXPORT CFDataRef	CFSocketCopyAddress(CFSocketRef s);
CF_EXPORT CFDataRef	CFSocketCopyPeerAddress(CFSocketRef s);
CF_EXPORT void		CFSocketGetContext(CFSocketRef s, CFSocketContext *context);
CF_EXPORT CFSocketNativeHandle	CFSocketGetNative(CFSocketRef s);

CF_EXPORT CFRunLoopSourceRef	CFSocketCreateRunLoopSource(CFAllocatorRef allocator, CFSocketRef s, CFIndex order);

/* For convenience, a function is provided to send data using the socket with a timeout.  The timeout will be used only if the specified value is positive.  The address should be left NULL if the socket is already connected. */
CF_EXPORT CFSocketError	CFSocketSendData(CFSocketRef s, CFDataRef address, CFDataRef data, CFTimeInterval timeout);

/* Generic name registry functionality (CFSocketRegisterValue, 
CFSocketCopyRegisteredValue) allows the registration of any property
list type.  Functions specific to CFSockets (CFSocketRegisterSocketData,
CFSocketCopyRegisteredSocketData) register a CFData containing the
components of a socket signature (protocol family, socket type,
protocol, and address).  In each function the nameServerSignature
may be NULL, or any component of it may be 0, to use default values
(TCP, INADDR_LOOPBACK, port as set).  Name registration servers might
not allow registration with other than TCP and INADDR_LOOPBACK.
The actual address of the server responding to a query may be obtained
by using the nameServerAddress argument.  This address, the address
returned by CFSocketCopyRegisteredSocketSignature, and the value
returned by CFSocketCopyRegisteredValue must (if non-null) be released
by the caller.  CFSocketUnregister removes any registration associated
with the specified name.
*/

CF_EXPORT CFSocketError	CFSocketRegisterValue(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFPropertyListRef value);
CF_EXPORT CFSocketError	CFSocketCopyRegisteredValue(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFPropertyListRef *value, CFDataRef *nameServerAddress);

CF_EXPORT CFSocketError	CFSocketRegisterSocketSignature(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, const CFSocketSignature *signature);
CF_EXPORT CFSocketError	CFSocketCopyRegisteredSocketSignature(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFSocketSignature *signature, CFDataRef *nameServerAddress);

CF_EXPORT CFSocketError	CFSocketUnregister(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name);

CF_EXPORT void		CFSocketSetDefaultNameRegistryPortNumber(UInt16 port);
CF_EXPORT UInt16	CFSocketGetDefaultNameRegistryPortNumber(void);

/* Constants used in name registry server communications */
CF_EXPORT const CFStringRef kCFSocketCommandKey;
CF_EXPORT const CFStringRef kCFSocketNameKey;
CF_EXPORT const CFStringRef kCFSocketValueKey;
CF_EXPORT const CFStringRef kCFSocketResultKey;
CF_EXPORT const CFStringRef kCFSocketErrorKey;
CF_EXPORT const CFStringRef kCFSocketRegisterCommand;
CF_EXPORT const CFStringRef kCFSocketRetrieveCommand;

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* ! __MACOS8__ */

#endif /* ! __COREFOUNDATION_CFSOCKET__ */

