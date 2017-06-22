//
//  RDPC_SyncPollingQuene.h
//  Pods
//
//  Created by Liudequan on 2017/6/6.
//
//

#import <RDPCrawlerQueue.h>
#import "RDPC_FecthCacheItem.h"

@interface RDPC_SyncPollingQuene : RDPCrawlerQueue

@property (nonatomic, strong) RDPC_FecthCacheItem *cacheItem;
@end
