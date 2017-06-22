//
//  RDPCrawlerStatUploadManager.h
//  
//
//  Created by LiuDequan on 15/6/19.
//
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerMacro.h"
#import "RDPCrawlerStatBaseLog.h"

@interface RDPCrawlerStatUploadManager : NSObject
DEC_SINGLETON(RDPCrawlerStatUploadManager)

/**
 *    是否强制上传
 *
 *    @param log
 *    @param forceUpload
 */
- (void)startUploadFile:(RDPCrawlerStatBaseLog *)log force:(BOOL)forceUpload;


@end
