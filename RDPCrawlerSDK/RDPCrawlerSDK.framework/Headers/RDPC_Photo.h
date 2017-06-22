//
//  RDPC_Photo.h
//  Pods
//
//  Created by whj on 17/1/12.
//
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerMacro.h"

/**
 相册授权状态

 - kRDPC_PhotoNotDetermine: 未授权
 - kRDPC_PhotoAuthRefused:  拒绝授权
 - kRDPC_PhotoAuthAgreed:   同意授权
 */
typedef NS_ENUM(NSUInteger, kRDPC_PhotoAuthStatus) {
    kRDPC_PhotoNotDetermine = 0,
    kRDPC_PhotoAuthRefused,
    kRDPC_PhotoAuthAgreed,
};

@interface RDPC_Photo : NSObject

DEC_SINGLETON(RDPC_Photo)


/**
 删除相册中的所有相片

 @param albumName  相册名称
 @param completion 回调block
 */
- (void)deleteAllPhotoesInAlbum:(NSString *)albumName  Completion:(void(^)(BOOL success, kRDPC_PhotoAuthStatus authorizeStatus))completion;


/**
 保存图片到指定相册中

 @param image      保存的图片
 @param albumName  保存的相册名，如果不存在会自动创建
 @param completion 回调block
 */
- (void)saveImage:(UIImage *)image Album:(NSString *)albumName Completion:(void(^)(BOOL success, kRDPC_PhotoAuthStatus authorizeStatus))completion;

@end
