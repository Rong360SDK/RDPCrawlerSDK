//
//  RDPCrawlerProtocl.h
//  Pods
//
//  Created by whj on 16/10/12.
//
//

#import <Foundation/Foundation.h>
#import "RDPCWebLoginRuleItem.h"

#define RDPC_INTERCEPT_CMD     (20161012)

@interface RDPCrawlerProtocl : NSURLProtocol

+ (void)startInterceptUrls:(NSArray <RDPCWebInterceptorItem *>*)rules;
+ (void)cancelIntercept;

@end
