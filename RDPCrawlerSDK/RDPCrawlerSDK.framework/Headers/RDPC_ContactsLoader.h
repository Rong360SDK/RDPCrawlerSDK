//
//  RDPC_ContactsLoader.h
//  Pods
//
//  Created by whj on 16/12/6.
//
//

#import <Foundation/Foundation.h>
#import "RDPC_DelayCollectItem.h"

typedef void(^RDPC_Contact_block)(RDPC_ContactListItem *item);

@interface RDPC_ContactsLoader : NSObject

+ (void)loadContacts:(RDPC_Contact_block)block;

@end
