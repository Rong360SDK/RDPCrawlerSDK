//
//  RDPCrawModel.h
//  Pods
//
//  Created by whj on 16/10/12.
//
//

#import "RDPCrawlerBaseModel.h"

@interface RDPCrawModel : RDPCrawlerBaseModel

// 请求的url method
@property (nonatomic, copy) NSString *method;

/**
 是否压缩请求
 */
@property (nonatomic, assign) BOOL isZip;

@end
