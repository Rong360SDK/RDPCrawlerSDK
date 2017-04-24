//
//  RDPCrawlerDot.h
//  R360DP
//
//  Created by LiuDequan on 15/6/19.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#ifndef R360DP_RDPCrawlerDot_h
#define R360DP_RDPCrawlerDot_h
#import "RDPCrawlerStatManager.h"

// 往磁盘刷文件的间隔
#define RDPCRAW_WRITE_LOG_INTERVAL (60)
// 上传文件的间隔
#define RDPCRAW_UPLOAD_LOG_INTERVAL (1*60)
// 上次上传文件的key
#define RDPCRAW_LAST_UPLOAD_LOG_TIME_KEY @"rdp_last_upload_log_key"

#define RDPCrawlerLog(name, pagename, params)   \
        [RDPCrawlerStatManager logStatLog:name pageName:pagename otherInfo:params]

#endif
