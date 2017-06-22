//
//  UIView+RDPCrawler.h
//  Pods
//
//  Created by whj on 15/5/14.
//
//

#import <UIKit/UIKit.h>
#import "RDPC_SeperatorLine.h"

// 过期提醒
#define RDPDeprecated(instead)  NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

@interface UIView (RDPCrawler)

/**
 *  @return frame.origin.x
 */
- (CGFloat)rdpLeft;

/**
 *  @return CGRectGetMaxX(self.frame)
 */
- (CGFloat)rdpRight;

/**
 *  @return frame.origin.y
 */
- (CGFloat)rdpTop;

/**
 *  @return CGRectGetMaxY(self.frame)
 */
- (CGFloat)rdpBottom;

/**
 *  @return frame.size.width
 */
- (CGFloat)rdpWidth;

/**
 *  @return frame.size.height
 */
- (CGFloat)rdpHeight;

/**
 *  @return CGRectGetMidX(self.frame)
 */
- (CGFloat)rdpCenterX;

/**
 *  @return CGRectGetMidY(self.frame)
 */
- (CGFloat)rdpCenterY;

/**
 *  @return frame.size
 */
- (CGSize)rdpSize;

/**
 *  设置 frame.origin.x
 */
- (void)setRdpLeft:(CGFloat)left;

/**
 *  设置 frame.origin.y
 */
- (void)setRdpTop:(CGFloat)top;

/**
 *  设置 frame.size.width
 */
- (void)setRdpWidth:(CGFloat)width;

/**
 *  设置 frame.size.height
 */
- (void)setRdpHeight:(CGFloat)height;

/**
 *  设置view横向的中间坐标
 */
- (void)setRdpCenterX:(CGFloat)centerX;

/**
 *  设置view纵向的中间坐标
 */
- (void)setRdpCenterY:(CGFloat)centerY;

/**
 *  @param size 设置 frame.size
 */
- (void)setRdpSize:(CGSize)size;

/**
 *    设置右边距
 *
 *    @param right
 */
- (void)setRdpRight:(CGFloat)right;

/**
 *    设置底部边距
 *
 *    @param bottom 
 */
- (void)setRdpBottom:(CGFloat)bottom;

/**
 *  移除当前view的所有子view
 */
- (void)rdpRemoveAllSubViews;


/**
 *  添加默认cell的分隔线: 位于底部, 左边距15
 */
- (void)rdpc_addDefaultSeperator;

/**
 *  添加铺满的分割线
 *
 *  @param mask 分割线的位置类型
 */
- (void)rdpc_addLineByMask:(kRDPC_LineMarginMask)mask;

/**
 *  添加结束边距的分隔线
 *
 *  @param mask        分割线位置类型
 *  @param startMargin 起始边距
 */
- (void)rdpc_addLineByMask:(kRDPC_LineMarginMask)mask startMargin:(CGFloat)startMargin;

/**
 *  添加居中的分割线(起始边距和结束边距一样)
 *
 *  @param mask   分割线位置类型
 *  @param margin 起始边距和结束边距
 */
- (void)rdpc_addLineByMask:(kRDPC_LineMarginMask)mask margin:(CGFloat)margin;

/**
 *  添加默认高度和颜色的分割线
 *
 *  @param mask        分割线位置类型
 *  @param startMargin 起始边距
 *  @param endMargin   结束边距
 */
- (void)rdpc_addLineByMask:(kRDPC_LineMarginMask)mask startMargin:(CGFloat)startMargin endMargin:(CGFloat)endMargin;

/**
 *  添加高度自定义的分割线
 *
 *  @param mask        分割线位置类型
 *  @param startMargin 起始边距
 *  @param endMargin   结束边距
 *  @param color       分割线颜色
 *  @param showHeight  分割线高度
 */
- (void)rdpc_addLineByMask:(kRDPC_LineMarginMask)mask startMargin:(CGFloat)startMargin endMargin:(CGFloat)endMargin color:(UIColor *)color height:(CGFloat)showHeight;

/**
 *   移除所有的分割线
 */
- (void)rdpc_removeAllLine;

/**
 *  移除某类型的分割线
 *
 *  @param mask 需移除分割线的类型
 */
- (void)rdpc_removeLineByMask:(kRDPC_LineMarginMask)mask;

@end
