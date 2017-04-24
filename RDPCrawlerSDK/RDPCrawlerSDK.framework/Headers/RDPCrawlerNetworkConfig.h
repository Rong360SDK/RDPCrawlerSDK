#import <Foundation/Foundation.h>
#import "RDPCrawlerBaseRequest.h"

@protocol RDPUrlFilterProtocol <NSObject>
- (NSString *)filterUrl:(NSString *)originUrl withRequest:(RDPCrawlerBaseRequest *)request;
@end

@protocol RDPCacheDirPathFilterProtocol <NSObject>
- (NSString *)filterCacheDirPath:(NSString *)originPath withRequest:(RDPCrawlerBaseRequest *)request;
@end

@interface RDPCrawlerNetworkConfig : NSObject

+ (RDPCrawlerNetworkConfig *)sharedInstance;

@property (strong, nonatomic) NSString *baseUrl;
@property (strong, nonatomic) NSString *cdnUrl;
@property (strong, nonatomic, readonly) NSArray *urlFilters;
@property (strong, nonatomic, readonly) NSArray *cacheDirPathFilters;

- (void)addUrlFilter:(id<RDPUrlFilterProtocol>)filter;
- (void)addCacheDirPathFilter:(id <RDPCacheDirPathFilterProtocol>)filter;

@end
