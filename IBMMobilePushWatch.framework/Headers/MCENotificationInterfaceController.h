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
#else
#import <WatchKit/WatchKit.h>
#endif

@interface MCENotificationInterfaceController : WKUserNotificationInterfaceController

@property (weak, nonatomic) IBOutlet WKInterfaceImage *headerImage;
@property (weak, nonatomic) IBOutlet WKInterfaceLabel *titleLabel;
@property (weak, nonatomic) IBOutlet WKInterfaceMap *mapView;
@property (weak, nonatomic) IBOutlet WKInterfaceGroup *backgroundGroup;
@property (weak, nonatomic) IBOutlet WKInterfaceLabel *bodyLabel;

@end
