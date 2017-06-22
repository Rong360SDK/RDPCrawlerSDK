//
//  RDPC_FetchDelegate.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import <Foundation/Foundation.h>

@protocol RDPC_FetchDelegate <NSObject>

@end

@class RDPC_FetchCell;
@protocol RDPC_FetchRefreshDelegate <NSObject>

@required
/**
 *  根据需要输入的参数判断是否能够刷新
 *
 *  @param needInputKeys 需要输入的参数的key的数组
 *
 *  @return 是否能够刷新
 */
- (BOOL)canRefreshCaptch:(NSArray *)needInputKeys;

/**
 *  根据需要输入的参数的key返回输入的参数字典
 *
 *  @param needInputKeys 需要输入的参数的key的数组
 *
 *  @return 输入的参数字典
 */
- (NSDictionary *)inputParams:(NSArray *)needInputKeys;

@optional

/**
 *  点击刷新按钮
 *  @param cell 刷新的cell
 */
- (void)beginRefreshAction:(RDPC_FetchCell *)cell;

/**
 *  处理错误信息
 *
 *  @param error 错误信息
 */
- (void)handleError:(NSError *)error;


@end



@protocol RDPC_FetchSendSMSDelegate <NSObject>

/**
 *  点击发送短信
 *
 *  @param cell 发送短信的cell
 */
- (void)beginSendSMS:(RDPC_FetchCell *)cell;

@end

@protocol RDPC_FetchProtocolDelegate <NSObject>

- (void)didClickProtocol:(RDPC_FetchCell *)cell;

@end
