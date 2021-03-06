/*
 * Licensed Materials - Property of IBM
 *
 * 5725E28, 5725I03
 *
 * © Copyright IBM Corp. 2016, 2017
 * US Government Users Restricted Rights - Use, duplication or disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#if __has_feature(modules)
@import UIKit;
#else
#import <UIKit/UIKit.h>
#endif

#import <IBMMobilePush/IBMMobilePush.h>
#import "MCEInboxPostTemplateView.h"

@interface MCEInboxPostTemplateDisplay : UIViewController <MCETemplateDisplay>
@property IBOutlet NSLayoutConstraint * topConstraint;
@property IBOutlet NSLayoutConstraint * toolbarHeightConstraint;
@property IBOutlet UIToolbar * toolbar;
@property IBOutlet MCEInboxPostTemplateView * contentView;
@property MCEInboxMessage * inboxMessage;
@end
