//
//  RDPC_FetchItem.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import "RDPCrawlerBaseItem.h"

/**
 *  参数类型
 */
typedef NS_ENUM(NSUInteger, kRDPC_FetchParamType) {
    /**
     *  普通文本输入框
     */
    kRDPC_FetchParamTypeInputNormalText = 1,
    /**
     *  身份证输入框
     */
    kRDPC_FetchParamTypeIDNO = 2,
    /**
     *  普通数字输入框
     */
    kRDPC_FetchParamTypeNormalNum = 3,
    /**
     *  小数输入框
     */
    kRDPC_FetchParamTypeDecimalNum = 4,
    /**
     *  手机号输入框
     */
    kRDPC_FetchParamTypeMobile = 5,
    /**
     *  卡号输入框
     */
    kRDPC_FetchParamTypeCardNo = 6,
    /**
     *  密码输入框
     */
    kRDPC_FetchParamTypeInputPassword = 7,
    /**
     *  图片验证码
     */
    kRDPC_FetchParamTypeImgCaptcha = 8,
    /**
     *  短信验证码
     */
    kRDPC_FetchParamTypeSMSCaptcha = 9,
    /**
     *  邮箱输入框
     */
    kRDPC_FetchParamTypeEmail = 10,
    /**
     *  多选列表
     */
    kRDPC_FetchParamTypeSelect = 11,
    /**
     *  服务协议
     */
    kRDPC_FetchParamTypeProtocol = 12,
    /**
     *  设置密码框
     */
    kRDPC_FetchParamTypeSetPassword = 13,
    /**
     *  重复密码框
     */
    kRDPC_FetchParamTypeRepeatPassword = 14,
    /**
     *  标题文本label
     */
    kRDPC_FetchParamTypeTextTitle = 15,
    /**
     *  提示文本label
     */
    kRDPC_FetchParamTypeTextPrompt = 16,
    /**
     *  选择有效期年月
     */
    kRDPC_FetchParamTypeChoosePeriodType = 17,
    /**
     *  不能编辑的输入框
     */
    kRDPC_FetchParamTypeCannotEditInputType = 18,
    /**
     *  回答问题
     */
    kRDPC_FetchParamTypeChooseQuestionType = 19,
    /**
     * 发送短信的短信验证码框
     */
    kRDPC_FetchParamTypeSendSms = 20,
};


@class RDPC_FetchParamItem;
@class RDPC_FetchRefreshParam;
@interface RDPC_FetchItem : RDPCrawlerBaseItem

/**
 *  提交的方法url
 */
@property (nonatomic, copy) NSString *method;

/**
 *  需要提交的显示参数
 */
@property (nonatomic, strong) NSArray<RDPC_FetchParamItem *> *param;

/**
 *  无需显示的提交参数
 */
@property (nonatomic, strong) NSArray<RDPC_FetchRefreshParam *> *hidden;

/**
 时间间隔
 */
@property (nonatomic, copy) NSString *interval;

/**
 轮询次数
 */
@property (nonatomic, copy) NSString *times;

/**
 *
 *  @return 无需显示的提交参数
 */
- (NSDictionary *)hiddenParam;

@end


@interface RDPC_FetchNextItem : RDPCrawlerBaseItem

@property (nonatomic, strong) RDPC_FetchItem *next;

@property (nonatomic, assign) NSInteger crawler_way;

@property (nonatomic, copy) NSString *status;

@property (nonatomic, copy) NSString *msg;

@end


@interface RDPC_FetchRefreshParam : RDPCrawlerBaseItem

/**
 *  上传的key
 */
@property (nonatomic, copy) NSString *key;
/**
 *  上传的值
 */
@property (nonatomic, copy) NSString *value;

@end

@interface RDPC_FetchChooseItem : RDPCrawlerBaseItem
/**
 *  显示的标题
 */
@property (nonatomic, copy) NSString *title;
/**
 *  上传的值
 */
@property (nonatomic, copy) NSString *value;

@end

@interface RDPC_FetchParamItem : RDPCrawlerBaseItem

/**
 *  参数的类型
 */
@property (nonatomic, assign) kRDPC_FetchParamType type;

/**
 *  显示的标题
 */
@property (nonatomic, copy) NSString *title;

/**
 *  输入框的提示文案
 */
@property (nonatomic, copy) NSString *hint;

/**
 *  提交的key
 */
@property (nonatomic, copy) NSString *key;

/**
 *  默认的输入值
 */
@property (nonatomic, copy) NSString *value;

/**
 *  图片验证码自动打码的值
 */
@property (nonatomic, copy) NSString *v_code;

/**
 *  多选的数组
 */
@property (nonatomic, strong) NSArray <RDPC_FetchChooseItem *> *options;

/**
 *  刷新的方法名称(只对短信验证码和手机验证码生效)
 */
@property (nonatomic, copy) NSString *refresh_method;

/**
 *  刷新的请求参数(只对短信验证码和手机验证码生效)
 */
@property (nonatomic, strong) NSArray <RDPC_FetchRefreshParam *> *refresh_param;

/**
 *  详细提示文本
 */
@property (nonatomic, copy) NSString *detail_hint;

/**
 *  是否已经发送过短信验证码
 */
@property (nonatomic, assign) BOOL need_write_back;

/**
 *  @return 刷新的提交参数
 */
- (NSDictionary *)refreshParam;

/**
 *  @return 需要输入的参数
 */
- (NSArray *)needInputParamKeys;

/**
 *  @return 无需输入的参数
 */
- (NSDictionary *)noNeedInputRefreshParams;

@end

@interface RDPC_FetchSyncPollItem : RDPCrawlerBaseItem

@property (nonatomic, assign) NSUInteger crawler_status;

@property (nonatomic, strong) RDPC_FetchItem *next;
@end
