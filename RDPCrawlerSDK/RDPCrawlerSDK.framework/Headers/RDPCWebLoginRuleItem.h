//
//  RDPCWebLoginRuleItem.h
//  Pods
//
//  Created by whj on 16/10/11.
//
//

#import "RDPCrawlerBaseItem.h"


/**
 成功条件类型

 - kRDPCSuccessTypeRegixHtml:    html匹配正则式
 - kRDPCSuccessTypeRedirctUrl:   重定向url正则式
 */
typedef NS_ENUM(NSUInteger, kRDPCSuccessType) {
    kRDPCSuccessTypeRegixHtml = 1,
    kRDPCSuccessTypeRedirctUrl = 2,
};


/**
 提交数据类型

 - kRDPCSuccessSubmitRegixHtml: 正则式匹配文本
 - kRDPCSuccessSubmitInput:     web输入框信息
 - kRDPCSuccessSubmitCookie:    指定域名下的cookie
 - kRDPCSuccessSubmitAllHtml:   登录成功页面的html源码
 */
typedef NS_ENUM(NSUInteger, kRDPCSuccessSubmitType) {
    kRDPCSuccessSubmitRegixHtml = 1,
    kRDPCSuccessSubmitInput = 2,
    kRDPCSuccessSubmitCookie = 3,
    kRDPCSuccessSubmitAllHtml = 4,
};


@class RDPCWebLoginSuccessItem;
@class RDPCWebLoginSubmitItem;
@class RDPCWebInterceptorItem;
@interface RDPCWebLoginRuleItem : RDPCrawlerBaseItem

/**
 登录页面url
 */
@property (nonatomic, copy) NSString *entrance_url;

/**
 抓取端的任务id
 */
@property (nonatomic, copy) NSString *session;

/**
 提示语
 */
@property (nonatomic, copy) NSString *tips;

/**
 修改页面元素的js:{"urlBase64":"jsBase64"}
 */
@property (nonatomic, strong) NSDictionary *js;

/**
 服务协议的url
 */
@property (nonatomic, copy) NSString *protocol_url;

/**
 模拟的user-agent
 */
@property (nonatomic, copy) NSString *js_ua_value;

/**
 登录成功条件数组
 */
@property (nonatomic, strong) NSArray<RDPCWebLoginSuccessItem *> *success_login_rule;

/**
 提交的数据数组
 */
@property (nonatomic, strong) NSArray <RDPCWebLoginSubmitItem *> *success_submit_data;

/**
 需拦截的url数组
 */
@property (nonatomic, strong) NSArray <RDPCWebInterceptorItem *> *additional_rule;


- (NSString *)evaluatingJsForUrl:(NSString *)url;

@end





@interface RDPCWebLoginSuccessItem : RDPCrawlerBaseItem


/**
 成功条件类型
 */
@property (nonatomic, assign) kRDPCSuccessType type;


/**
 正则式或者重定向url
 */
@property (nonatomic, copy) NSString *value;

@end





@interface RDPCWebLoginSubmitItem : RDPCrawlerBaseItem


/**
 提交类型
 */
@property (nonatomic, assign) kRDPCSuccessSubmitType type;

/**
 获取提交值的条件，type=1为正则式，type=2无视， type=3为域名
 */
@property (nonatomic, copy) NSString *match_value;

/**
 提交时的key
 */
@property (nonatomic, copy) NSString *submit_key;

- (NSDictionary *)domainCookies;

@end




/**
 拦截类型

 - kRDPCInterceptorTypeAlipayAuthQrcode: 支付宝验证二维码
 - kRDPCInterceptorTypeAlipayLoginQrcode: 支付宝登录二维码
 - kRDPCInterceptorTypeAlipayTransitionPage: 支付宝二维码登录中间页面
 */
typedef NS_ENUM(NSUInteger, kRDPCInterceptorType) {
    kRDPCInterceptorTypeAlipayAuthQrcode = 1,
    kRDPCInterceptorTypeAlipayLoginQrcode = 2,
    kRDPCInterceptorTypeAlipayTransitionPage = 3,
};


@interface RDPCWebInterceptorItem : RDPCrawlerBaseItem

/**
 拦截类型
 */
@property (nonatomic, assign) kRDPCInterceptorType type;

/**
 二维码页面的url正则式
 */
@property (nonatomic, copy) NSString *container_url_regex;

/**
 取二维码正则式
 */
@property (nonatomic, copy) NSString *url_regex;

/**
 取正则式的哪个group
 */
@property (nonatomic, assign) NSInteger regex_group;


- (BOOL)shouldInterceptorUrl:(NSString *)url;

- (NSString *)regexResultByContent:(NSString *)content;

@end
