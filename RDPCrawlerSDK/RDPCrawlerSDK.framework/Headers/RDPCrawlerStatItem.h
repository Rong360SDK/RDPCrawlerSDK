//
//  RDPCrawlerStatItem.h
//  R360DP
//
//  Created by LiuDequan on 15/6/19.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RDPCrawlerStatItem : NSObject

//类型
@property (nonatomic, copy) NSString *type;
// 是不是立即写日志
@property (nonatomic, assign) BOOL isDirect;

/**
 *    添加要打日志的字段
 *
 *    @param key
 *    @param value 不支持
 */
- (void)addKey:(NSString *)key value:(id)value;

/**
 *    生成日志字符串
 *
 *    @return
 */
- (NSString *)toString;
@end
