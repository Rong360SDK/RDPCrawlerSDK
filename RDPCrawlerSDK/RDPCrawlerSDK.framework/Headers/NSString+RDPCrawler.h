//
//  NSString+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/10/20.
//
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>


@interface NSString (RDPCrawler)

+(CGRect)rdpc_heightForString:(NSString *)str Size:(CGSize)size Font:(UIFont *)font;
+(CGRect)rdpc_heightForString:(NSString *)str Size:(CGSize)size Font:(UIFont *)font Lines:(NSInteger)lines;
/**
 *  根据字体和行间距获得文本高度
 *
 *  @param font  字体
 *  @param width 文本框宽度
 *  @param space 行间距 space <= 0 表示使用默认行间距
 *
 *  @return 文本所需高度
 */
- (CGFloat)rdpc_getHeightWithFont:(UIFont *)font width:(CGFloat)width andLineSpacing:(CGFloat)space;

- (CGFloat)rdpc_getHeightWithFont:(UIFont *)font width:(CGFloat)width;
/**
 *  单行文本所需宽度
 *
 *  @param font   字体
 *  @param height 限高
 *
 *  @return 单行文本所需宽度
 */
- (CGFloat)rdpc_getWidthWithFont:(UIFont *)font height:(CGFloat)height;
/**
 *  根据字体和行间距生成attributedString
 *
 *  @param font  字体
 *  @param space 行间距
 *
 *  @return 属性字符串
 */
- (NSMutableAttributedString *)rdpc_getAttributedStringWithFont:(UIFont *)font andLineSpacing:(CGFloat)space;

//获取AES加密后的串
+ (NSString *)rdpc_aesEncode:(NSString *)str withAESKey:(NSString *)key;
- (NSString *)rdpc_aesEncodeWithAESKey:(NSString *)key;

//获取AES解密后的串
+ (NSString *)rdpc_aesDecode:(NSString *)str withAESKey:(NSString *)key;
+ (NSString *)rdpc_aesDecodeData:(NSData *)data withAESKey:(NSString *)key;
- (NSString *)rdpc_aesDecodeWithAESKey:(NSString *)key;

//获取MD5解码后的串
+ (NSString *)rdpc_md5Decode:(NSString *)str;
- (NSString *)rdpc_md5Decode;

//获取MD5加密后的串
+ (NSString *)rdpc_md5Encode:(NSString *)str;
- (NSString *)rdpc_md5Encode;

//对NSData进行Base64编码，返回编码后的串
+ (NSString *)rdpc_base64Encode:(NSData *)data;
- (NSString *)rdpc_base64Encode;

//对NSString进行Base64解码，返回解码后的串
+ (NSData *)rdpc_base64Decode:(NSString *)string;
- (NSString *)rdpc_base64Decode;

// url编码
- (NSString *)rdpc_URLEncoding;
- (NSString *)rdpc_URLDecoding;

// utf8编码
- (NSString *)rdpc_UTF8Encoding;

- (NSString *)rdpc_UnicodeDecoding;

// 将json字符串转成转义
- (NSString *)rdpc_convertToEscapedJSONString;

/**
 *  去除字符串中收尾空格和换行
 *
 *  @return 去掉空格后的字符串
 */
- (NSString *)rdpc_trimString;

/**
 *  @param pattern 正则式
 *
 *  @return 是否匹配正则式
 */
- (BOOL)rdpc_isMatchedPattern:(NSString *)pattern;

/**
 *
 *  @param splitStr 插入的字符串
 *  @param eachLen  每隔几个字符插入
 *
 *  @return 返回插入新字符后的字符串
 */
- (NSString*)rdpc_splitWithString:(NSString*)splitStr each:(NSUInteger)eachLen;

/**
 *  从后面添加分割符号
 *
 *  @param splitStr 插入的字符串
 *  @param eachLen  每隔几个字符插入
 *
 *  @return
 */
- (NSString*)rdpc_endSplitWithString:(NSString*)splitStr each:(NSUInteger)eachLen;

/**
 *  用*对字符串加密
 *
 *  @return 加密后的字符串
 */
- (NSString *)rdpc_secretString;

/**
 *  @param pattern 正则式
 *
 *  @return 匹配正则式的第一个字符串
 */
- (NSString *)rdpc_matchStringWith:(NSString *)pattern;

/**
 *
 *  @param length 尾号长度
 *
 *  @return 长度为length的尾部字符串
 */
- (NSString *)rdpc_tailByLength:(NSUInteger)length;

/**
 *  分割url字符串去字典
 *
 *  @return
 */
- (NSDictionary *)rdpc_divisionStr;

/**
 *  @return 是否是合法的邮箱
 */
- (BOOL)rdpc_isValidEmail;
/**
 *  @return 是否全是数字(不含小数)
 */
- (BOOL)rdpc_isValidNumber;

/**
 *  @return 是否是数字(包含小数)
 */
- (BOOL)rdpc_isValidDigit;

/**
 *  @return 是否是有效的金额
 */
- (BOOL)rdpc_isValidAmount;

/**
 *  @return 是否是有效身份证号码
 */
- (BOOL)rdpc_isValidIDNO;

/**
 *  @return 是否有效的银行卡号
 */
- (BOOL)rdpc_isValidCardNO;

/**
 *  @return 是否有效的手机号码
 */
- (BOOL)rdpc_isValidPhone;

/**
 *  @return 是否有效的交易密码 规则8-16位, 数字和字母组合
 */
- (BOOL)rdpc_isValidTradePwd;

/**
 *  @return 是否是有效的邮编
 */
- (BOOL)rdpc_isValidZipCode;

/**
 *  @return 是否是有效的固定电话 格式：区号-电话号码-分机号码
 */
- (BOOL)rdpc_isValidLandlineTelephone;

@end
