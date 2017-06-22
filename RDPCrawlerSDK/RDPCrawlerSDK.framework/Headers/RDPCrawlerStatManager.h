//
//  RDPStatManager.h
//  R360DP
//
//  Created by LiuDequan on 15/6/18.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RDPCrawlerDot.h"
#import "RDPCrawlerMacro.h"

@interface RDPCrawlerStatManager : UIView
DEC_SINGLETON(RDPCrawlerStatManager)

/**
 *    写统计日志（实时上传的日志）
 *
 *    @param eventName
 *    @param isIODirectly
 */
+ (void)logStatLog:(NSString *)eventName
          pageName:(NSString *)pageName
         otherInfo:(NSDictionary *)userInfo;

@end
