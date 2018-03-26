/* 
 * Licensed Materials - Property of IBM 
 * 
 * 5725E28, 5725I03 
 * 
 * © Copyright IBM Corp. 2017, 2018
 * US Government Users Restricted Rights - Use, duplication or disclosure restricted by GSA ADP Schedule Contract with IBM Corp. 
 */


#if __has_feature(modules)
@import WatchKit;
@import Foundation;
#else
#import <WatchKit/WatchKit.h>
#import <Foundation/Foundation.h>
#endif

@interface AttributesController : WKInterfaceController
@property IBOutlet WKInterfaceLabel * updateAttributeStatus;
@property IBOutlet WKInterfaceLabel * deleteAttributeStatus;
-(IBAction)updateAttribute:(id)sender;
-(IBAction)deleteAttribute:(id)sender;
@end
