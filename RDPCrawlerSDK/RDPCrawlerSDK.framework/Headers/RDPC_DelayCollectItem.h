//
//  RDPC_DelayCollectItem.h
//  Pods
//
//  Created by whj on 16/12/5.
//
//

#import "RDPCrawlerBaseItem.h"
#import "RDPC_DBHelper.h"


/**
 获取联系人状态

 - kRDPC_Contacts_Status_Normal:  正常
 - kRDPC_Contacts_Status_NoLimit: 无权限
 - kRDPC_Contacts_Status_Failed:  获取出错
 */
typedef NS_ENUM(NSInteger, kRDPC_Contacts_Status) {
    kRDPC_Contacts_Status_Normal = 1,
    kRDPC_Contacts_Status_NoLimit = -1,
    kRDPC_Contacts_Status_Failed = -2,
};


@class RDPC_ContactListItem;
@interface RDPC_DelayCollectItem : RDPCrawlerBaseItem

/**
 app版本号
 */
@property (nonatomic, copy) NSString *app_version;

/**
 cpu 信息
 */
@property (nonatomic, copy) NSString *cpu_Info;

/**
 分辨率信息
 */
@property (nonatomic, copy) NSString *dpi;

/**
 联系人列表
 */
@property (nonatomic, strong) RDPC_ContactListItem *phone_list;

/**
 运营商信息
 */
@property (nonatomic, copy) NSString *operators;

/**
 广告标志符
 */
@property (nonatomic, copy) NSString *idfa;

/**
 系统版本号
 */
@property (nonatomic, copy) NSString *sys_version;

/**
 bundle identifier
 */
@property (nonatomic, copy) NSString *bundle_id;

/**
 时间戳
 */
@property (nonatomic, copy) NSString *timestamp;

/**
 平台
 */
@property (nonatomic, copy) NSString *platform;


/**
 @param infos 需删除的信息数组
 */
+ (void)deleteInfos:(NSArray <RDPC_DelayCollectItem *>*)infos;

@end


@interface RDPC_ContacterItem : RDPCrawlerBaseItem

/**
 姓名
 */
@property (nonatomic, copy) NSString *user_name;

/**
 手机号
 */
@property (nonatomic, strong) NSArray<NSString *> *phone_num;

@end

@interface RDPC_ContactListItem : RDPCrawlerBaseItem

@property (nonatomic, strong) NSArray <RDPC_ContacterItem *> *content;

@property (nonatomic, assign) kRDPC_Contacts_Status status;

@end

@interface RDPC_DelayCollectUploadItem : RDPCrawlerBaseItem

@property (nonatomic, strong) NSArray <RDPC_DelayCollectItem *> *info;

+ (RDPC_DelayCollectUploadItem *)getUploadItem;

@end
