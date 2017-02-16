/* IBM Confidential
 * OCO Source Materials
 * 5725E28, 5725S01, 5725I03
 * © Copyright IBM Corp. 2014, 2014
 *
 * The source code for this program is not published or otherwise
 * divested of its trade secrets, irrespective of what has been
 * deposited with the U.S. Copyright Office.
 */

#import <Foundation/Foundation.h>
#import <IBMMobilePush/IBMMobilePush.h>

@interface DisplayWebViewPlugin : NSObject <MCEActionProtocol>
+ (instancetype)sharedInstance;
-(void)performAction:(NSDictionary*)action;
+(void)registerPlugin;
@end