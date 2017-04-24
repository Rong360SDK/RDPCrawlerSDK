//
//  RDPC_TimerButton.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import <UIKit/UIKit.h>

@interface RDPC_TimerButton : UIButton

@property (nonatomic, assign) BOOL isRunning;

@property (nonatomic, copy) void (^actionBlock)(RDPC_TimerButton *button);

- (instancetype)initWithFrame:(CGRect)frame actionBlock:(void (^)(RDPC_TimerButton *button))block;

/**
 *  重置回正常状态(在点击之后如果还需要显示normal状态，请调用此方法,所处界面消失的时候也应该调用此方法)
 */
- (void)resetUI;
/**
 *  停止跑秒 停留在当前状态
 */
- (void)suspendRunning;
/**
 *  开始跑秒
 */
- (void)startOrResumeRunning;

@end
