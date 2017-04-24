//
//  RDPCrawlerQueue.h
//  Pods
//
//  Created by whj on 16/10/12.
//
//

#import <Foundation/Foundation.h>
#import "RDPCCrawlerWebDataItem.h"
#import "RDPCrawlerItem.h"
#import "RDPCMacro.h"


@interface RDPCrawlerQueue : NSObject

/**
 是否是同步抓取
 */
@property (nonatomic, assign) BOOL isSync;

@property (nonatomic, strong) RDPCrawlerItem *item;

- (void)startCrawlerBy:(RDPCrawlerItem *)item data:(RDPCCrawlerWebDataItem *)data;

- (void)beginCrawlerData:(RDPCCrawlerWebDataItem *)data;
- (void)cancel;

@end
