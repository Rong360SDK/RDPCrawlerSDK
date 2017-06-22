//
//  RDPCrawlerNavigationController.h
//  RB-CFT
//
//  Created by dicky on 15/5/18.
//  Copyright (c) 2015年 dicky duan. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    RDPViewControllerNavigationBarBlue = 1,
    RDPViewControllerNavigationBarWhite,
    RDPViewControllerNavigationBarCyan,
    RDPViewControllerNavigationBarCustom,
}RDPViewControllerNavigationBarType;

@interface RDPCrawlerNavigationController : UINavigationController<
UIGestureRecognizerDelegate,
UINavigationControllerDelegate>


/**
 *  是不是正在push
 */
@property (atomic,assign) BOOL isPushing;

/**
 *  是不是正在pop
 */
@property (atomic, assign) BOOL isPopping;
/**
 *  正在滑动返回的动画
 */
@property (atomic, assign) BOOL isPopAnimating;

/**
 *  是否正在present下个视图
 */
@property (nonatomic, assign) BOOL isPresenting;

/**
 *  navigation style 状态
 */
@property (nonatomic, assign) RDPViewControllerNavigationBarType barStyle;

/**
 *  是否能够present或push
 *
 *  @return
 */
- (BOOL)canDoAction;

/**
 *  设置变量全部可用
 */
- (void)enableLock;
@end
