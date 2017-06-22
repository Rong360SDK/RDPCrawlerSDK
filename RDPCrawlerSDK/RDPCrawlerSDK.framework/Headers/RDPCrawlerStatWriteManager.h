//
//  RDPCrawlerStatWriteManager.h
//  R360DP
//
//  Created by LiuDequan on 15/6/19.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerMacro.h"
#import "RDPCrawlerStatItem.h"
#import "RDPCrawlerStatBaseLog.h"

@interface RDPCrawlerStatWriteManager : NSObject
DEC_SINGLETON(RDPCrawlerStatWriteManager)

/**
 *    写统计日志（实时上传的日志）
 *
 *    @param logStr
 *    @param isIODirectly
 */
- (void)writeStatLog:(RDPCrawlerStatItem *)logItem isIODirectly:(BOOL)isIODirectly;

/**
 *    上传左右文件
 */
- (void)uploadAllFile;

@end
