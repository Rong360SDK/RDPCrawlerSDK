#import <Foundation/Foundation.h>
#import "RDPCrawlerBaseRequest.h"
#import "RDPCrawlerAFNetworking.h"

@interface RDPCrawlerNetworkAgent : NSObject

+ (RDPCrawlerNetworkAgent *)sharedInstance;

- (void)addRequest:(RDPCrawlerBaseRequest *)request;

- (void)cancelRequest:(RDPCrawlerBaseRequest *)request;

- (void)cancelAllRequests;

/// 根据request和networkConfig构建url
- (NSString *)buildRequestUrl:(RDPCrawlerBaseRequest *)request;

- (void)setProtocolClass:(Class)protocolClass;
- (void)clearProtocl;

- (void)addNewCerData:(NSData *)data;

@end
