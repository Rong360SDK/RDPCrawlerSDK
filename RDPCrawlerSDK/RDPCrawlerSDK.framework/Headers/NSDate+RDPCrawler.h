//
//  NSDate+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/10/20.
//
//

#import <Foundation/Foundation.h>

@interface NSDate (RDPCrawler)

/**
 *  初始化dateFormatter
 *
 *  @return
 */
+ (NSDateFormatter *)rdpc_sharedFormatter;

/**
 *  @return 当前的时间戳字符串
 */
+ (NSString *)rdpc_nowTimeUnixStr;

/**
 *  @return 当前的毫秒级时间戳字符串
 */
+ (NSString *)rdpc_nowTimeMillisecondStr;

/**
 *  @return 自1970年起的秒数字符串
 */
- (NSString *)rdpc_unixStrSince1970;

/**
 *  @return 格式化字符串"yyyy-MM-dd"
 */
- (NSString *)rdpc_formatYMD;

/**
 *
 *  @param format format字符串
 *
 *  @return 返回格式化后的字符串
 */
- (NSString *)rdpc_getFormatStr:(NSString *)format;

/**
 * 根据string和format获取date
 */
+ (NSDate *)rdpc_getDateTimeByString:(NSString *)strDate withFormat:(NSString*)format;

/**
 *  时间描述
 *
 *  @param timeStamp
 *
 *  @return
 */
+ (NSString *)rdpc_timeTailWithTimeStamp:(NSString *)timeStamp;

/**
 *  获取每月的天数
 *
 *  @param year
 *  @param month
 *
 *  @return
 */
+ (NSUInteger )rdpc_numOfDayInYear:(NSUInteger)year month:(NSUInteger)month;

@end
