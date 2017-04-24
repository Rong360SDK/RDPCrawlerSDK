//
//  RDPCrawlerImage.h
//  R360DP
//
//  Created by LiuDequan on 15/5/18.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface RDPCrawlerImage : UIImage

/**
 *    获取image
 *
 *    @param path 图片名字
 *
 *    @return
 */
+ (UIImage *)imageForName:(NSString *)name;

/**
 *     获取image
 *
 *    @param path   图片名字
 *    @param bundle 图片的bundle
 *
 *    @return 
 */
+ (UIImage *)imageForName:(NSString *)name bundle:(NSString *)bundle;

/**
 *  获取图片 缓存 底层【UIImage imageWithNamed】
 *
 *  @param name 图片名字
 *
 *  @return
 */
+ (UIImage *)cacheImageForName:(NSString *)name;

/**
 *  获取图片
 *
 *  @param name   图片名字
 *  @param bundle bundle
 *
 *  @return
 */
+ (UIImage *)cacheImageForName:(NSString *)name bundle:(NSString *)bundle;
@end
