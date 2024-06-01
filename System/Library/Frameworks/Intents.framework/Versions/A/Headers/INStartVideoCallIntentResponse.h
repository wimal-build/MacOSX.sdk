//
//  INStartVideoCallIntentResponse.h
//  Intents
//
//  Copyright (c) 2016-2019 Apple Inc. All rights reserved.
//

#import <Intents/INIntentResponse.h>

typedef NS_ENUM(NSInteger, INStartVideoCallIntentResponseCode) {
    INStartVideoCallIntentResponseCodeUnspecified = 0,
    INStartVideoCallIntentResponseCodeReady,
    INStartVideoCallIntentResponseCodeContinueInApp,
    INStartVideoCallIntentResponseCodeFailure,
    INStartVideoCallIntentResponseCodeFailureRequiringAppLaunch,
    INStartVideoCallIntentResponseCodeFailureAppConfigurationRequired,
    INStartVideoCallIntentResponseCodeFailureCallingServiceNotAvailable,
    INStartVideoCallIntentResponseCodeFailureContactNotSupportedByApp,
    INStartVideoCallIntentResponseCodeFailureInvalidNumber API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macosx),
} API_UNAVAILABLE(watchos) API_UNAVAILABLE(macosx) API_DEPRECATED("INStartVideoCallIntent is deprecated. Please adopt INStartCallIntent instead", ios(10.0, 13.0));

NS_ASSUME_NONNULL_BEGIN

API_UNAVAILABLE(watchos)
API_UNAVAILABLE(macosx)
API_DEPRECATED("INStartVideoCallIntent is deprecated. Please adopt INStartCallIntent instead", ios(10.0, 13.0))
@interface INStartVideoCallIntentResponse : INIntentResponse

- (id)init NS_UNAVAILABLE;

// The app extension has the option of capturing its private state as an NSUserActivity and returning it as the 'currentActivity'.
// If the the app is launched, an NSUserActivity will be passed in with the private state.  The NSUserActivity may also be used to query the app's UI extension (if provided) for a view controller representing the current intent handling state.
// In the case of app launch, the NSUserActivity will have its activityType set to the name of the intent. This intent object will also be available in the NSUserActivity.interaction property.
- (instancetype)initWithCode:(INStartVideoCallIntentResponseCode)code userActivity:(nullable NSUserActivity *)userActivity NS_DESIGNATED_INITIALIZER;

@property (readonly, NS_NONATOMIC_IOSONLY) INStartVideoCallIntentResponseCode code;

@end

NS_ASSUME_NONNULL_END
