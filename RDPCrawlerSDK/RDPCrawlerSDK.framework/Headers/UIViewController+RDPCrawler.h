//
//  UIViewController+RDPCrawler.h
//  Pods
//
//  Created by LiuDequan on 15/5/14.
//
//

#import <UIKit/UIKit.h>

@interface UIViewController (RDPCrawler)
/**
 *    设置左边的item
 *
 *    @param view
 */
- (void)rdpc_setLeftBarItem:(UIView*) view;

/**
 *    设置右边的item
 *
 *    @param view
 */
- (void)rdpc_setRightBarItem:(UIView*) view;

/**
 *    设置titleview
 *
 *    @param view
 */
- (void)rdpc_setTitleView:(UIView*)view;

/**
 *    设置返回button
 */
- (void)rdpc_setBackButton;

/**
 *  关闭本页面
 */
- (void)rdpc_closeView;

/**
 *  @return 是否是导航的rootController
 */
- (BOOL)rdpc_isRootOfNavigationController;

/**
 *    获取当前最前面的viewcontroller
 *
 *    @return
 */
+ (UIViewController *)rdpc_getCurrentVC;

@end
