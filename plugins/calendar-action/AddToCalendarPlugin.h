/*
 * Licensed Materials - Property of IBM
 *
 * 5725E28, 5725I03
 *
 * © Copyright IBM Corp. 2015, 2016
 * US Government Users Restricted Rights - Use, duplication or disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>
#import <IBMMobilePush/IBMMobilePush.h>
@import EventKit;
@import EventKitUI;

@interface AddToCalendarPlugin : NSObject <EKEventEditViewDelegate, MCEActionProtocol>
+ (instancetype)sharedInstance;
+(void)registerPlugin;
-(void)performAction:(NSDictionary*)action;
@end