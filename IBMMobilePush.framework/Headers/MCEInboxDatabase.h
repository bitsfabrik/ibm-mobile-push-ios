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
#else
#import <UIKit/UIKit.h>
#endif

@class MCEInboxMessage;

/** The MCEInboxDatabase class owns and interacts with the inbox database. */
@interface MCEInboxDatabase : NSObject

/** This method returns the singleton object of this class. */
@property(class, nonatomic, readonly) MCEInboxDatabase * sharedInstance NS_SWIFT_NAME(shared);

/** The inboxMessagesAscending: method retrieves an NSArray of MCEInboxMessage objects from the inbox database.

 @param ascending A boolean value that toggles if the contents should be sorted ascending (TRUE) or descending (FALSE)
 @return Returns an NSArray of MCEInboxMessage objects or a nil value in the case of failure.
 */
-(NSMutableArray<MCEInboxMessage *> *)inboxMessagesAscending:(BOOL)ascending;

/** The inboxMessageWithInboxMessageId: method retrieves a single MCEInboxMessage object from the inbox database by inboxMessageId.
 
 @param inboxMessageId A unique identifier for the inbox message.
 @return Returns a single MCEInboxMessage object or a nil value in the case of failure.
 */
-(MCEInboxMessage*)inboxMessageWithInboxMessageId:(NSString*)inboxMessageId;

/** The inboxMessageWithRichContentId: method returns the latest inbox message for the specified richContentId.
 
 @param richContentId A unique identifier for the rich content.
 @return Returns the most recent MCEInboxMessage object or a nil value in the case of failure. 
 */
-(MCEInboxMessage*)inboxMessageWithRichContentId:(NSString*)richContentId;

/** Clears expired messages from the database. */
-(void)clearExpiredMessages;

/** Returns the number of unread messages in the inbox */
-(int) unreadMessageCount;

/** Returns the number of messages in the inbox */
-(int) messageCount;

@end
