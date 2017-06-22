//
//  RDPCrawlerStatFileHelper.h
//  R360DP
//
//  Created by LiuDequan on 15/6/23.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerMacro.h"


#define FILE_MANAGER                  [NSFileManager defaultManager]
#define DOCPATH_HOME                  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES) objectAtIndex:0]
#define DOCPATH_LOGHOME               [NSString stringWithFormat:@"%@/%@",DOCPATH_HOME,@"RDPCrawlerLog"]

@class RDPCrawlerStatFileInfo;

@interface RDPCrawlerStatFileHelper : NSObject
DEC_SINGLETON(RDPCrawlerStatFileHelper)

/**
 *    获取文件属性
 *
 *    @param fileName 文件名
 *
 *    @return
 */
+ (RDPCrawlerStatFileInfo *)getFileInfoWithFileName:(NSString *)fileName;

/**
 *    创建日志目录
 *
 *    @return 返回是否创建成功
 */
+ (BOOL)createLogHome;

/**
 *    文件是否存在
 *
 *    @param fileName 文件名
 *
 *    @return
 */
+ (BOOL)isExistFileInLogHome:(NSString *)fileName;

/**
 *    写文件
 *
 *    @param bufferData 要写的数据
 *    @param fileName   文件名
 *    @param isNewFile  是否是新文件
 */
+ (void)persistData:(NSData *)bufferData
           fileName:(NSString *)fileName
          isNewFile:(BOOL)isNewFile;

/**
 *    bga
 *
 *    @param fileName 文件名字
 *    @param toName   要修改的文件名
 */
+ (void)renameFileName:(NSString *)fileName toName:(NSString *)toName;

/**
 *    获取上传文件的路径
 *
 *    @return
 */
+ (NSArray *)getUploadingFile;

/**
 *    读日志文件
 *
 *    @param filePath 文件路径
 *
 *    @return
 */
+ (NSData *)readLogFile:(NSString *)filePath;

/**
 *    删除文件名
 *
 *    @param fileName
 */
+ (void)deleteFileWithName:(NSString *)fileName;
@end

@interface RDPCrawlerStatFileInfo : NSObject
// 文件大小
@property (nonatomic, assign) unsigned long long fileSize;
// 最后一次修改时间
@property (nonatomic, strong) NSDate *lastModifyDate;
@end
