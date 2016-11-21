//
//  RDPCrawlerItem.h
//  Pods
//
//  Created by whj on 16/10/10.
//
//

#import <Foundation/Foundation.h>

/**
 爬虫抓取类型
 
 - kCrawlerTypeAlipay: 支付宝抓取
 - kCrawlerTypeTaobao: 淘宝抓取
 */
typedef NS_ENUM(NSUInteger, kRDPCrawlerType) {
    kRDPCrawlerTypeAlipay = 1,
    kRDPCrawlerTypeTaobao = 2,
};


/**
 爬虫抓取状态

 - kCrawlerStatusIdle:         初始状态
 - kRDPCrawlerStatusStart:     抓取开始状态(分配到serverId)
 - kCrawlerStatusLoginSuccess: 登陆成功状态
 - kCrawlerStatusFetchSuccess: 抓取成功状态
 - kCrawlerStatusFailed:       失败状态
 - kCrawlerStatusCancel:       手动取消
 */
typedef NS_ENUM(NSUInteger, kRDPCrawlerStatus) {
    kRDPCrawlerStatusIdle = 0,
    kRDPCrawlerStatusStart = 1,
    kRDPCrawlerStatusLoginSuccess = 2,
    kRDPCrawlerStatusFetchSuccess = 3,
    kRDPCrawlerStatusFailed = 4,
    kRDPCrawlerStatusCancel = 5,
};


/**
 错误号
 - kRDPCErrorCodeInitParamError:  初始化参数错误
 - kRDPCErrorCodeServerError:     服务器接口错误
 - kRDPCErrorCodeUninstallAlipay: 未安装支付宝
 - kRDPCErrorCodeCrawlerFailed:   抓取数据失败
 - kRDPCErrorCodeCrawlerOutTime:  抓取数据超时
 - kRDPCErrorCodeCrawlerOther:    其它错误
 */
typedef NS_ENUM(NSUInteger, kRDPCErrorCode) {
    kRDPCErrorCodeInitParamError = 1001,
    kRDPCErrorCodeServerError = 1002,
    kRDPCErrorCodeUninstallAlipay = 1003,
    kRDPCErrorCodeCrawlerFailed = 1004,
    kRDPCErrorCodeCrawlerOutTime = 1005,
    kRDPCErrorCodeCrawlerOther = 1006,
};

@interface RDPCrawlerItem : NSObject


/**
 抓取任务的唯一标志符
 */
@property (nonatomic, copy) NSString *taskId;

/**
 后端返回的唯一标志符
 */
@property (nonatomic, copy) NSString *serverId;

/**
 抓取类型
 */
@property (nonatomic, assign) kRDPCrawlerType type;

/**
 抓取状态
 */
@property (nonatomic, assign) kRDPCrawlerStatus status;

/**
 抓取失败的错误信息
 */
@property (nonatomic, strong) NSError *error;

/**
传入的附加参数
 */
@property (nonatomic, copy) NSDictionary *addtionParams;

@end
