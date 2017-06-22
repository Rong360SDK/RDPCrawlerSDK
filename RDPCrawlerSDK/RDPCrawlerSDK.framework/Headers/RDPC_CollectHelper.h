//
//  RDPC_CollectHelper.h
//  Pods
//
//  Created by whj on 16/12/5.
//
//

#import <Foundation/Foundation.h>
#import "RDPCMacro.h"

@interface RDPC_CollectHelper : NSObject

DEC_SINGLETON(RDPC_CollectHelper)

- (void)startCollectDelayInfo;


- (void)uploadCollectionInfo;
@end
