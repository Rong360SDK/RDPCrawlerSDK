//
//  RDPCrawlerStatBaseLog.h
//  R360DP
//
//  Created by LiuDequan on 15/6/19.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerStatItem.h"
#import "RDPCrawlerDot.h"

@interface RDPCrawlerStatBaseLog : NSObject

// 内存大小
@property (nonatomic, strong) NSMutableString  *memoryCache;
// 内存
@property (nonatomic, assign) NSInteger mMemoryCacheCount;
// 文件大小
@property (nonatomic, assign) unsigned long long fileSize;
// 文件名字
@property (nonatomic, strong) NSString *fileName;
// 上次写文件的时间
@property (nonatomic, assign) double lastWriteLogTime;
// 最大内存大小
@property (nonatomic, assign) NSInteger maxMemoryCount;
// 文件最大大小
@property (nonatomic, assign) unsigned long long maxFileSize;
// 是不是只有wifi下上传
@property (nonatomic, assign) BOOL isWifiUpload;
// 是不是上传
@property (nonatomic, assign) BOOL isUpload;
// 是不是写
@property (nonatomic, assign) BOOL isWrite;
// 上次日志文件上传的时间
@property (nonatomic, assign) CFAbsoluteTime lastUploadTimer;

/**
 *    添加日志
 *
 *    @param item
 *    @param needRename
 */
- (void)addStatItem:(RDPCrawlerStatItem *)item needRename:(BOOL)needRename;

/**
 *    获取上传文件的名字
 *
 *    @return
 */
- (NSString *)getWirteFileName;

/**
 *    获取上传文件的名字
 *
 *    @return
 */
- (NSString *)getUploadFileName;

/**
 *    获取zip文件名
 *
 *    @return 
 */
- (NSString *)getZipFileName;

/**
 *    重置内存日志
 */
- (void)resetMemoryLog;

/**
 *    存储上传日志的时间
 */
- (void)storyUploadTimer;

@end
