//
//  RDPStatServerApi.h
//  R360DP
//
//  Created by LiuDequan on 15/6/24.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import "RDPCrawlerServerapi.h"

@interface RDPCrawlerStatServerApi : RDPCrawlerServerapi

/**
 *  日志的名字
 */
@property (nonatomic, copy) NSString *logFileName;
@end
