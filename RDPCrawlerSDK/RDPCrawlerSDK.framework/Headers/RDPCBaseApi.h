//
//  RDPCBaseApi.h
//  Pods
//
//  Created by whj on 16/10/13.
//
//

#import "RDPCrawlerServerapi.h"

#define RDPC_GIZP_MASK      @"xsdkgzip"

@interface RDPCBaseApi : RDPCrawlerServerapi

@property (nonatomic, copy) NSString *serverMethod;


/**
 是否压缩
 */
@property (nonatomic, assign) BOOL isZip;


/**
 @return 业务公共参数
 */
- (NSDictionary *)commonBusinessParams;

@end
