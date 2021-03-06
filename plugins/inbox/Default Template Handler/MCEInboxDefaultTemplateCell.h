/*
 * Licensed Materials - Property of IBM
 *
 * 5725E28, 5725I03
 *
 * © Copyright IBM Corp. 2015, 2017
 * US Government Users Restricted Rights - Use, duplication or disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#if __has_feature(modules)
@import UIKit;
#else
#import <UIKit/UIKit.h>
#endif

#import <IBMMobilePush/IBMMobilePush.h>

@interface MCEInboxDefaultTemplateCell : UITableViewCell <MCETemplatePreview>
@property IBOutlet UILabel * subject;
@property IBOutlet UILabel * preview;
@property IBOutlet UILabel * date;
@end
