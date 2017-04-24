//
//  NSURLSessionTask+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/12/15.
//
//

#import <Foundation/Foundation.h>

/**
 这个扩展本来是为了添加nsurlsessiontask的，但是nsurlsessiontask在某些系统中不存在，为了兼容才使用nsobject
 */
@interface NSObject (RDPCrawler)

- (void)rdpc_setNeedRedirect:(BOOL)needRedirect;

- (BOOL)rdpc_needRedirect;


@end
