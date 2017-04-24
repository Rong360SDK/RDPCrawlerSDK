//
//  RDPCLoginWayItem.h
//  Pods
//
//  Created by whj on 16/10/11.
//
//

#import "RDPCrawlerBaseItem.h"


/**
 登录方式

 - kRDPCLoginWayService:  后端模拟登录
 - kRDPCLoginWayAppWeb:   app webview模拟登录
 - kRDPCLoginWayAppLocal: app 模拟请求登录
 - kRDPCLoginWayNotDefined: 未知登录方式,待后续接口确认
 - kRDPCLoginWayQrCode:  扫码登录
 */
typedef NS_ENUM(NSUInteger, kRDPCLoginWay) {
    kRDPCLoginWayService = 1,
    kRDPCLoginWayAppWeb = 2,
    kRDPCLoginWayAppLocal = 3,
    kRDPCLoginWayNotDefined = 4,
    kRDPCLoginWayQrCode = 5,
};

@interface RDPCLoginWayItem : RDPCrawlerBaseItem

@property (nonatomic, copy) NSString *rule_url;

@property (nonatomic, assign) kRDPCLoginWay login_way;

@end
