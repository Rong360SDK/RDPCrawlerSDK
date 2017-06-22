//
//  RDPC_WebQueue.h
//  Pods
//
//  Created by whj on 17/2/7.
//
//

#import "RDPCrawlerQueue.h"
#import "RDPC_FecthCacheItem.h"

@interface RDPC_WebQueue : RDPCrawlerQueue

@property (nonatomic, strong) RDPC_FecthCacheItem *cacheItem;

@end
