//
//  RDPCrawlerManager.h
//  Pods
//
//  Created by whj on 16/10/10.
//
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerItem.h"

@protocol RDPCrawlerDelegate <NSObject>


/**
 抓取状态改变的回调

 @param statusItem 抓取状态的item
 */
- (void)crawlerChangeStatus:(RDPCrawlerItem *)statusItem;

@end

@interface RDPCrawlerManager : NSObject


/**
 配置sdk必需信息

 @param appId    appId
 @param delegate delegate
 @param key      私钥证书(.p12文件转成的NSData)
 */
+ (void)configAppId:(NSString *)appId delegate:(id<RDPCrawlerDelegate>)delegate privateKey:(NSData *)key;


/**
 配置sdk必需信息

 @param appId    appId
 @param delegate delegate
 @param key      私钥证书(.p12文件转成的NSData)
 @param password 私钥证书密码
 */
+ (void)configAppId:(NSString *)appId delegate:(id<RDPCrawlerDelegate>)delegate privateKey:(NSData *)key password:(NSString *)password;

/**
 启动抓取服务
 
 @param type   抓取服务类型
 @param taskId 抓取服务的唯一标志符(可选)
 */
+ (void)startCrawlerByType:(kRDPCrawlerType)type identifier:(NSString *)taskId;

/**
 启动(支付宝\淘宝)抓取服务

 @param type   抓取服务类型
 @param taskId 抓取服务的唯一标志符(可选)
 @param addtionalParams  附加参数(可选, 业务机构的一些自定义参数，会回传给业务机构服务器)
 */
+ (void)startCrawlerByType:(kRDPCrawlerType)type identifier:(NSString *)taskId addtionalParams:(NSDictionary *)addtionalParams;


/**
 启动运营商抓取服务

 @param config          运营商抓取配置
 @param taskId          抓取服务的唯一标志符(可选)
 @param addtionalParams 附加参数(可选, 业务机构的一些自定义参数，会回传给业务机构服务器)
 */
+ (void)startCrawlerOperatorByConfig:(RDPC_OperatorConfig *)config identifier:(NSString *)taskId addtionalParams:(NSDictionary *)addtionalParams;

/**
 配置可选信息
 
 @param appName app名称
 */
+ (void)configOptionalAppName:(NSString *)appName;


/**
 设置抓取过程的超时时间（默认为1800S）

 @param second 超时时间(单位为秒)
 */
+ (void)setTimeoutSecond:(NSInteger)second;


/**
 设置是否使用测试环境
 
 @param isDebug isDebug
 */
+ (void)setIsDebug:(BOOL)isDebug;

@end
