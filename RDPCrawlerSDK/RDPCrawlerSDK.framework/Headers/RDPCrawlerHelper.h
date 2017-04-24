//
//  RDPCrawlerHelper.h
//  Pods
//
//  Created by whj on 16/10/10.
//
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerManager.h"
#import "RDPCrawlerMacro.h"
#import "RDPCrawlerItem.h"
#import "RDPCrawlerQueue.h"
#import "RDPCCrawlerWebDataItem.h"
#import "RDPC_FecthCacheItem.h"

@interface RDPCrawlerHelper : NSObject

DEC_SINGLETON(RDPCrawlerHelper)

@property (nonatomic, copy) NSString *appId;

@property (nonatomic, copy) NSString *appName;

@property (nonatomic, copy) NSString *appVersion;

@property (nonatomic, copy) NSString *bundleId;

@property (nonatomic, copy) NSString *platform;

@property (nonatomic, copy) NSString *deviceId;

@property (nonatomic, copy) NSString *systemVersion;

@property (nonatomic, copy) NSString *deviceModel;

@property (nonatomic, copy) NSString *sdkVersion;

@property (nonatomic, weak) id<RDPCrawlerDelegate> delegate;

@property (nonatomic, assign) NSInteger timeout;

@property (nonatomic, copy) NSString *socketId;

@property (nonatomic, copy) NSString *openApiDomain;

@property (nonatomic, copy) NSString *dotDomain;

@property (nonatomic, copy) NSString *socketUrl;

- (BOOL)isValidParam;

- (void)downLoadCommonJs:(void (^)(void))compleBlock;

- (void)callBackTaskItem:(RDPCrawlerItem *)item;

- (void)callBackDismiss:(RDPCrawlerItem *)item;

- (RDPCrawlerQueue *)beginFetch:(RDPCrawlerItem *)item data:(RDPCCrawlerWebDataItem *)data cacheItem:(RDPC_FecthCacheItem *)cache;
- (void)removeTask:(RDPCrawlerQueue *)task;

+ (NSString *)modelNameByType:(kRDPCrawlerType)type;

+ (void)logSSLError:(NSError *)error;

@end
