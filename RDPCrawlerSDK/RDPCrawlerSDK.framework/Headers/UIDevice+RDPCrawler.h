//
//  UIDevice+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/11/8.
//
//

#import <UIKit/UIKit.h>

@interface UIDevice (RDPCrawler)


/**
 @return 设备机型
 */
- (NSString *)rdpc_deviceModel;

/**
 @return 屏幕分辨率
 */
+ (NSString *)rdpc_getScreen;

/**
 @return WIFI名称
 */
+ (NSString *)rdpc_getSSID;

/**
 @return WIFI mac地址
 */
+ (NSString *)rdpc_getBSSID;

/**
 @return cpu型号
 */
+ (NSString *)rdpc_getCPU;

/**
 @return 总内存
 */
+ (NSUInteger)rdpc_totalMemory;

/**
 @return 可用内存
 */
+ (NSUInteger)rdpc_availableMemory;

/**
 @return 使用内存
 */
+ (NSUInteger)rdpc_usedMemory;

/**
 @return 运营商
 */
+ (NSString *)rdpc_voipInfo;

/**
 @return 是否开启VPN
 */
+ (BOOL)rdpc_isVPNConnect;

/**
 @return 获取广告标志符
 */
+ (NSString *)rdpc_idfa;

@end
