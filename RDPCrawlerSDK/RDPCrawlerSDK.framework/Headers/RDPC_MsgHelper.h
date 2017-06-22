//
//  RDPC_MsgHelper.h
//  Pods
//
//  Created by whj on 16/11/24.
//
//

#import <Foundation/Foundation.h>
#import "RDPCMacro.h"
#import "RDPSocket.h"

/**
 消息类型

 - kRDPC_MsgTypeSetHeartBeatTime: 设置心跳
 - kRDPC_MsgTypeCrawlerWebData:   抓取网页
 - kRDPC_MsgTypeCrawlerStatus:    抓取状态回调
 */
typedef NS_ENUM(NSUInteger, kRDPC_MsgType) {
    //1-20000公共服务消息
    kRDPC_MsgTypeSetHeartBeatTime = 1,
    
    //20000-30000抓取服务消息
    kRDPC_MsgTypeCrawlerWebData = 20001,
    kRDPC_MsgTypeCrawlerStatus = 20002,
    
};

typedef void(^RDPC_MsgCallBackBlock)(RDPSocketMsg *msg, NSError *error);

@interface RDPC_MsgHelper : NSObject

DEC_SINGLETON(RDPC_MsgHelper)

+ (void)addListener:(NSObject *)observer forMsgType:(kRDPC_MsgType)msgType callBack:(RDPC_MsgCallBackBlock)block;
+ (void)removeListener:(NSObject *)observer;
+ (void)removeListener:(NSObject *)observer forMsgType:(kRDPC_MsgType)msgType;


@end
