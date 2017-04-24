//
//  RDPC_SocketLoginQueue.h
//  Pods
//
//  Created by whj on 16/11/29.
//
//

#import <Foundation/Foundation.h>
#import "RDPCMacro.h"

@interface RDPC_WebDataSocketListener : NSObject

DEC_SINGLETON(RDPC_WebDataSocketListener)

- (void)startListen;

@end
