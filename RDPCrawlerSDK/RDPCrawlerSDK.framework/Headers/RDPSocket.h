//
//  RDPSocket.h
//  Pods
//
//  Created by whj on 16/11/18.
//
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerMacro.h"
#import "RDPSocketMsg.h"

#define RDPC_SOCKET_MSG_SEND   @"RDPC_SOCKET_MSG_SEND"
#define RDPC_SOCKET_MSG        @"RDPC_SOCKET_MSG"
#define RDPC_SOCKET_MSG_TYPE   @"RDPC_SOCKET_MSG_TYPE"
#define RDPC_SOCKET_MSG_ERROR  @"RDPC_SOCKET_MSG_ERROR"

@interface RDPSocket : NSObject

DEC_SINGLETON(RDPSocket)

/**
 心跳间隔时间(单位为s)
 */
@property (nonatomic, assign) NSTimeInterval heartbeatInterval;

- (void)open;
- (void)close;
- (void)sendMsg:(RDPSocketMsg *)message;
- (BOOL)isOpening;

@end
