//
//  RDPC_MobileLoginRuleItem.h
//  Pods
//
//  Created by whj on 16/8/17.
//
//

#import "RDPCrawlerBaseItem.h"
#import "RDPC_FetchItem.h"
#import "RDPCLoginWayItem.h"

@interface RDPC_MobileLoginRuleItem : RDPCrawlerBaseItem

/**
 提示文案
 */
@property (nonatomic, copy) NSString *tips;

/**
 底部温馨提示
 */
@property (nonatomic, copy) NSString *prompt;

/**
 *  下一步需要输入的参数
 */
@property (nonatomic, strong) RDPC_FetchItem *next;

/**
 *  是否能找回密码
 */
@property (nonatomic, assign) BOOL can_find_passsword;

/**
 *  忘记密码的url
 */
@property (nonatomic, copy) NSString *find_password_url;

/**
 *  服务协议url
 */
@property (nonatomic, copy) NSString *user_protocol_url;

/**
 *  无法验证的url
 */
@property (nonatomic, copy) NSString *unauthorable_url;

/**
 抓取任务的服务器唯一标识
 */
@property (nonatomic, copy) NSString *session;

/**
 登录方式
 */
@property (nonatomic, assign) kRDPCLoginWay login_way;

@end

