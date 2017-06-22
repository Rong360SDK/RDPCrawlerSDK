//
//  RDPCCrawlerWebDataItem.h
//  Pods
//
//  Created by whj on 16/10/12.
//
//

#import "RDPCrawlerBaseItem.h"
#import "RDPC_FetchItem.h"
#import "RDPC_MobileLoginRuleItem.h"

/**
 抓取方式
 
 - kRDPCrawlerWayServer:     服务端抓取
 - kRDPCrawlerWayAppRequest: app模拟请求
 - kRDPCrawlerWayAppWeb:     app浏览器抓取
 - kRDPCrawlerWaySocket:     长链接抓取
 - kRDPCrawlerWayWebAndServer: 服务端和app浏览器抓取共存
 - kRDPCrawlerWayServerPolling: 服务端抓取,app轮询状态
 - kRDPCrawlerWayServerSync: 服务端抓取，同步抓取
 */
typedef NS_ENUM(NSUInteger, kRDPCrawlerWay) {
    kRDPCrawlerWayServer = 1,
    kRDPCrawlerWayAppRequest = 2,
    kRDPCrawlerWayAppWeb = 3,
    kRDPCrawlerWaySocket = 4,
    kRDPCrawlerWayWebAndServer = 5,
    kRDPCrawlerWayServerPolling = 6,
    kRDPCrawlerWayServerSync=7,
};

/**
 数据抓取状态

 - kRDPCrawlerDataStatusDoing:    抓取中
 - kRDPCrawlerDataStatusFinished: 抓取完成
 - kRDPCrawlerDataStatusFailed:   抓取失败
 - kRDPCrawlerDataStatusPartFinished: 部分抓取成功
 */
typedef NS_ENUM(NSUInteger, kRDPCrawlerDataStatus) {
    kRDPCrawlerDataStatusDoing = 1,
    kRDPCrawlerDataStatusFinished = 2,
    kRDPCrawlerDataStatusFailed = 3,
    kRDPCrawlerDataStatusPartFinished = 4,
};


@class RDPCCrawlerUrlItem;
@interface RDPCCrawlerWebDataItem : RDPCrawlerBaseItem

/**
 抓取方式
 */
@property (nonatomic, assign) kRDPCrawlerWay crawler_way;

/**
 抓取状态
 */
@property (nonatomic, assign) kRDPCrawlerDataStatus crawler_status;

/**
 抓取请求数组
 */
@property (nonatomic, strong) NSArray<RDPCCrawlerUrlItem *> *crawler_pages;

/**
 抓取的js
 */
@property (nonatomic, copy) NSString *crawler_js;

/**
 抓取的下一步
 */
@property (nonatomic, strong) RDPC_FetchNextItem *nextItem;


@property (nonatomic, strong) RDPC_MobileLoginRuleItem *local_ruleItem;

@end



@interface RDPCCrawlerUrlItem : RDPCrawlerBaseItem


/**
 请求url
 */
@property (nonatomic, copy) NSString *url;


/**
 请求方法:POST或GET
 */
@property (nonatomic, copy) NSString *request_method;


/**
 请求headers
 */
@property (nonatomic, strong) NSDictionary *headers;

/**
 post请求的body的base64字符串
 */
@property (nonatomic, strong) NSString *body;

/**
 是否支持重定向
 */
@property (nonatomic, assign) BOOL supportRedirect;

@end


@class RDPCError;
@interface RDPCCrawlerUploadItem : RDPCrawlerBaseItem

/**
 响应头
 */
@property (nonatomic, strong) NSDictionary *headers;

/**
 响应流的base64字符串
 */
@property (nonatomic, copy) NSString *source_flow;

/**
 响应的状态码
 */
@property (nonatomic, assign) NSUInteger status_code;

@property (nonatomic, strong) RDPCError *error;

@end

@interface RDPCError : RDPCrawlerBaseItem

@property (nonatomic, assign) NSInteger code;

@property (nonatomic, copy) NSString *msg;

@end

@interface RDPC_SocketWebDataItem : RDPCrawlerBaseItem

/**
 抓取请求数组
 */
@property (nonatomic, strong) RDPCCrawlerUrlItem *page;

@end

@interface RDPC_SocketCrawStatusItem : RDPCrawlerBaseItem

/**
 抓取状态
 */
@property (nonatomic, assign) kRDPCrawlerDataStatus crawler_status;

/**
 抓取任务标志
 */
@property (nonatomic, copy) NSString *session;

@end


