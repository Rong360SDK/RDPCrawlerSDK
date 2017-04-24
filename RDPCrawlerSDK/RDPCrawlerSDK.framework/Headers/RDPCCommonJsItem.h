//
//  RDPCCommonJsItem.h
//  Pods
//
//  Created by whj on 16/10/11.
//
//

#import "RDPCrawlerBaseItem.h"

@interface RDPCCommonJsItem : RDPCrawlerBaseItem


/**
 js的版本号
 */
@property (nonatomic, assign) NSUInteger current_version;


/**
 是否需要更新
 */
@property (nonatomic, assign) BOOL need_update;


/**
 js的源码字符串
 */
@property (nonatomic, copy) NSString *js_source_code;

- (void)save;

+ (RDPCCommonJsItem *)cacheItem;

@end
