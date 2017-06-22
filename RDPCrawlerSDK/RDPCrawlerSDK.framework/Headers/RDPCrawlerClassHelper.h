//
//  RDPClassHelper.h
//  R360DP
//
//  Created by LiuDequan on 15/5/13.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerMacro.h"

@interface RDPCrawlerClassHelper : NSObject
DEC_SINGLETON(RDPCrawlerClassHelper)

// 属性列表
@property (nonatomic, strong) NSMutableDictionary *propertyListCache;


/**
 *    获取类的属性列表
 *
 *    @param cls 类
 *
 *    @return 返回属性列表
 */
- (NSDictionary *)propertyList:(Class)cls;


/**
 *  获取类的json映射表
 *
 *  @param cls cls 类
 *
 *  @return 返回类的json映射表
 */
- (NSDictionary *)jsonMapBy:(Class)cls;

/**
 *  获取类中属性数组对应的类的映射表
 *
 *  @param cls cls 类
 *
 *  @return 根据class返回属性和类的映射表
 */
- (NSDictionary *)propertyArrayMapBy:(Class)cls;

@end
