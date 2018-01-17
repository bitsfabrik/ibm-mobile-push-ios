/* IBM Confidential
 * OCO Source Materials
 * 5725E28, 5725S01, 5725I03
 * © Copyright IBM Corp. 2017, 2017
 *
 * The source code for this program is not published or otherwise
 * divested of its trade secrets, irrespective of what has been
 * deposited with the U.S. Copyright Office.
 */

#if __has_feature(modules)
@import WatchKit;
@import Foundation;
@import WatchConnectivity;
#else
#import <WatchKit/WatchKit.h>
#import <Foundation/Foundation.h>
#import <WatchConnectivity/WatchConnectivity.h>
#endif

/** The MCEWatchSdk class is the central integration point for the Watch SDK as a whole. */
@interface MCEWatchSdk: NSObject <WCSessionDelegate>

/** This method returns the singleton object of this class. */
+ (instancetype)sharedInstance;

/** Get the current SDK Version number as a string. */
-(NSString*)sdkVersion;

/** This method should be called from the watch extension delegate's applicationWillResignActive method */
- (void)applicationWillResignActive;

/** This method should be called from the watch extension delegate's applicationDidBecomeActive method */
- (void)applicationDidBecomeActive;

/** This method should be called from the watch extension delegate's applicationDidFinishLaunching method */
- (void)applicationDidFinishLaunching;

/** This property can be used to override if a notification is delivered to the device when the app is running. */
@property (nonatomic, assign) BOOL (^presentNotification)(NSDictionary * userInfo);

/** This method will execute the category action referenced by the identified notification action. */
-(void) performNotificationAction: (NSDictionary*) userInfo identifier: (NSString*) identifier;

/** This method will execute the notification action in the userInfo dictionary */
-(void) performNotificationAction: (NSDictionary*) userInfo;
@end
