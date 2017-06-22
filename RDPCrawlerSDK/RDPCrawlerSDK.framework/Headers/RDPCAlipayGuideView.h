//
//  RDPCAlipayGuideView.h
//  Pods
//
//  Created by whj on 17/1/16.
//
//

#import <UIKit/UIKit.h>

@interface RDPCAlipayGuideView : UIView

+ (void)showGuideView:(CGPoint)anchorPoint cliclBlock:(void(^)())clickBlock;

+ (void)showGuideViewNoAnimationWithCliclBlock:(void (^)())clickBlock;
@end
