//
//  RDPCrawlerNetHelper.h
//  Pods
//
//  Created by whj on 15/5/14.
//
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerMacro.h"

typedef enum{
    RDPCrawlerDetailNetTypeEnumUnReachable,
    RDPCrawlerDetailNetTypeEnumWifi,
    RDPCrawlerDetailNetTypeEnum2G,
    RDPCrawlerDetailNetTypeEnum3G,
    RDPCrawlerDetailNetTypeEnum4G,
} RDPCrawlerDetailNetTypeEnum;

// 网络改变的通知
extern NSString * const RDPCrawlerNetworkingReachabilityDidChangeNotification;
// 网络改变通知中网络状态的kye
extern NSString * const RDPCrawlerNetworkingReachabilityNetTypeStatusKey;

@interface RDPCrawlerNetHelper : NSObject

@property (nonatomic, assign) RDPCrawlerDetailNetTypeEnum netType;

DEC_SINGLETON(RDPCrawlerNetHelper)

/**
 *    获取网络类型
 *
 *    @return
 */
- (RDPCrawlerDetailNetTypeEnum )getCurrentNetTypeDetail;


- (NSString *)getNetTypeStr;

/**
 *    开始网络监控
 */
- (void)startNetMonitor;

/**
 *    是不是wifi
 *
 *    @return
 */
- (BOOL)isWifi;

@end
