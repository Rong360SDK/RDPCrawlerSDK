//
//  RDPC_TimelyCollectItem.h
//  Pods
//
//  Created by whj on 16/12/5.
//
//

#import "RDPCrawlerBaseItem.h"
#import "RDPC_DBHelper.h"

/**
 定位状态

 - kRDPC_GPSStatusNormal:         正常
 - kRDPC_GPSStatusNoLimit:        无权限
 - kRDPC_GPSStatusLocationFailed: 定位失败
 */
typedef NS_ENUM(NSInteger, kRDPC_GPSStatus) {
    kRDPC_GPSStatusNormal = 1,
    kRDPC_GPSStatusNoLimit = -1,
    kRDPC_GPSStatusLocationFailed = -2,
};

@class RDPC_GPSItem;
@interface RDPC_TimelyCollectItem : RDPCrawlerBaseItem

@property (nonatomic, strong) RDPC_GPSItem *loc;

@property (nonatomic, copy) NSString *wifi_name;

@property (nonatomic, copy) NSString *wifi_mac;

@property (nonatomic, assign) BOOL is_vpn;

@property (nonatomic, copy) NSString *timestamp;

@property (nonatomic, copy) NSString *platform;

+ (void)deleteUploadInfos:(NSArray <RDPC_TimelyCollectItem *> *)infos;

@end


@interface RDPC_GPSItem : RDPCrawlerBaseItem

@property (nonatomic, assign) kRDPC_GPSStatus status;

@property (nonatomic, assign) double longitude;

@property (nonatomic, assign) double latitude;

@end

@interface RDPC_TimelyCollectUploadItem : RDPCrawlerBaseItem

@property (nonatomic, strong) NSArray <RDPC_TimelyCollectItem *> *info;

+ (RDPC_TimelyCollectUploadItem *)getUploadItem;

@end
