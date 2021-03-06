/*
 * Licensed Materials - Property of IBM
 *
 * 5725E28, 5725I03
 *
 * © Copyright IBM Corp. 2014, 2018
 * US Government Users Restricted Rights - Use, duplication or disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#if __has_feature(modules)
@import UIKit;
@import IBMMobilePush;
#else
#import <UIKit/UIKit.h>
#import <IBMMobilePush/IBMMobilePush.h>
#endif

@interface InAppVC : UITableViewController <MCEActionProtocol>
@end
