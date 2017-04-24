//
//  RDPCrawlerBaseModel.h
//  R360DP
//
//  Created by LiuDequan on 15/5/14.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import "RDPCrawlerRequest.h"
#import "RDPCrawlerServerapi.h"
#import "RDPCrawlerBaseItem.h"
#import "RDPCrawlerLoadFailView.h"
#import "RDPCrawlerNetLoadingView.h"

// 网络错误errorcode
#define R360_NET_ERROR_CODE (-10)


/**
 提示显示类型

 - kMsgShowTypeToast: toast显示
 - kMsgShowTypeAlert: alert显示
 */
typedef NS_ENUM(NSUInteger, kMsgShowType) {
    kMsgShowTypeToast = 1,
    kMsgShowTypeAlert = 2,
};

@class RDPCrawlerBaseModel;

typedef void(^RDPBaseCompletionBlock)(RDPCrawlerBaseModel *model);

@interface RDPCrawlerBaseModel : NSObject

// 请求的api类
@property (nonatomic, strong) RDPCrawlerServerapi *serverApi;
// 请求的参数
@property (nonatomic, strong) NSDictionary *params;
// 请求的url
@property (nonatomic, strong) NSString *requestUrl;
// 错误信息
@property (nonatomic, retain) NSError *error;
// 请求完成的block
@property (nonatomic, copy) void (^completionBlock)(RDPCrawlerBaseModel *model);
// 是否展示progress
@property (nonatomic, assign) BOOL needDisPlayProgress;
//显示的progress类型, 默认为kFullScreenProgress
@property (nonatomic, assign) kProgressType progressType;
// 是否显示出错视图
@property (nonatomic, assign) BOOL needFailView;
// 返回的数据
@property (nonatomic, strong) RDPCrawlerBaseItem *dataItem;
// 是否展示error信息
@property (nonatomic, assign) BOOL needDisPlayErrorMsg;
/**
 *  显示进度框的superView
 */
@property (nonatomic, weak) UIView *loadingView;

/**
 *  显示失败view的superView
 */
@property (nonatomic, weak) UIView *failedSuperview;

/**
 *  parser dic
 */
@property (nonatomic, strong) NSDictionary *parserDic;

/**
 提示显示类型
 */
@property (nonatomic, assign) kMsgShowType msgShowType;

@property (nonatomic, assign) BOOL isLoading;

@property (nonatomic, weak) UIViewController *failVC;

@property (nonatomic, assign) int netErrorNum;

/**
 *    是否在请求
 *
 *    @return
 */
- (BOOL)isLoading;

/**
 *    开发请求数据
 */
- (void)loadInner;

/**
 *    设置解析数据类型
 *
 *    @param classType 类
 */
- (void)setPaserDataClassType:(Class)classType;

/**
 *    实现者重载处理数据的逻辑
 *
 *    @param parsedData 解析完的数据
 */
-(void)handleParsedData:(RDPCrawlerBaseItem *)parsedData;

/**
 *    重载者实现处理未做parse的data
 *
 *    @param data 未解析的元数据
 */
-(void)handleUnParsedData:(id)data;

/**
 *    子类对象可以重载处理已做parse的data，即使没有设置处理类型
 *
 *    @param parsedData 返回的data字段，已解密
 */
-(void)handleOriginalData:(NSDictionary *) parsedData;

/**
 *    处理错误的情况下返回原数据
 *
 *    @param parsedData
 */
- (void)handleErrorOriginalData:(NSDictionary *)parsedData;

/**
 *  取消网络请求
 */
- (void)cancleRequest;

-(void)onParseData:(NSDictionary *)parsedData;

- (void)showFailView;

- (void)showProgress;

- (void)hideProgress;

- (void)showError;


@end

