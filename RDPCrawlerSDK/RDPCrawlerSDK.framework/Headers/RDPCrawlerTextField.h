//
//  UITextField+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import <UIKit/UIKit.h>
#import "RDPC_NumKeyboard.h"

typedef void(^RDPC_TextFinishBlock)(UITextField *field);

@interface RDPCrawlerTextField: UITextField

/**
 *  @param newString 新输入的字符串
 *
 *  @return 是否能继续输入金额
 */
- (BOOL)rdpc_canInputAmount:(NSString *)newString;

/**
 *  @param newString 新输入的字符串
 *
 *  @return 能否继续输入卡号
 */
- (BOOL)rdpc_canInputCardNo:(NSString *)newString;

/**
 *  @param newString 新输入的字符串
 *
 *  @return 能否继续输入身份证号
 */
- (BOOL)rdpc_canInputIDNo:(NSString *)newString;

/**
 *  @param newString 新输入的字符串
 *
 *  @return 能否继续输入手机号
 */
- (BOOL)rdpc_canInputMobileNo:(NSString *)newString;

/**
 *  @param newString 新输入的字符串
 *
 *  @return 能否继续输入邮箱
 */
- (BOOL)rdpc_canInputEmail:(NSString *)newString;

/**
 *  @param newString 新输入的字符串
 *
 *  @return 能否继续输入交易密码
 */
- (BOOL)rdpc_canInputTradePwd:(NSString *)newString;

/**
 *  @param newString 新输入的字符串
 *
 *  @return 能否继续输入邮编
 */
- (BOOL)rdpc_canInputZipCode:(NSString *)newString;

/**
 *  @param newString 新输入的字符串
 *
 *  @return 能否继续输入文字
 */
- (BOOL)rdpc_canInputNormal:(NSString *)newString;

/**
 *  控制是否隐藏默认的InputAccessoryView
 *
 *  @param isHide 是否隐藏, 默认不隐藏
 */
- (void)rdpc_setHideInputAccessoryView:(BOOL)isHide;
/**
 *  控制是否使用不带小数点的纯数字键盘
 *
 *  @param use 是否使用
 */
- (void)rdpc_setUseNumberPad:(BOOL)use;
/**
 *  设置点击完成按钮的block
 *
 *  @param block 完成的回调
 */
- (void)rdpc_setFinishBlock:(RDPC_TextFinishBlock)block;

/**
 *  设置自定义键盘类型
 *
 *  @param type 自定义键盘类型
 */
- (void)rdpc_setCustomKeyboardType:(kRDPC_CustomKeyboardType)type;

@end
