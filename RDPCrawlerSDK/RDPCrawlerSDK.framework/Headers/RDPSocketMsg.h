//
//  RDPSocketMsg.h
//  Pods
//
//  Created by whj on 16/11/18.
//
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, kRDPS_ProtcolType) {
    kRDPS_ProtcolTypeJson = 0x0,
};

@interface RDPSocketMsg : NSObject

/**
 自定义的消息id
 */
@property (nonatomic, copy) NSString *msgId;

/**
 消息类型
 */
@property (nonatomic, assign) NSInteger msgType;

/**
 回复的消息id
 */
@property (nonatomic, assign) NSInteger feebackId;

/**
 是否加密
 */
@property (nonatomic, assign) BOOL isEncry;

/**
 是否压缩
 */
@property (nonatomic, assign) BOOL isCompress;

/**
 data协议类型
 */
@property (nonatomic, assign) kRDPS_ProtcolType protcolType;

/**
 消息内容(原始内容，未加密和压缩)
 */
@property (nonatomic, strong) NSData *data;

/**
 是否需要回复
 */
@property (nonatomic, assign) BOOL needFeedBack;

/**
 回复的超时时间(默认30秒)
 */
@property (nonatomic, assign) NSTimeInterval outTime;



/**
 自动设置的发送消息id
 */
@property (nonatomic, assign) NSInteger sendId;
/**
 自动设置的发送时间
 */
@property (nonatomic, assign) NSTimeInterval sendTime;





- (NSData *)toData;
- (instancetype)initByData:(NSData *)data;

@end
