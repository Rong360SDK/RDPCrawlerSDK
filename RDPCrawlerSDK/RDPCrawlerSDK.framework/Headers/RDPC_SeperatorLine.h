//
//  RDPC_SeperatorLine.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import <UIKit/UIKit.h>

typedef enum {
    kRDPC_BottomMask = 1,
    kRDPC_TopMask,
    kRDPC_LeftMask,
    kRDPC_RightMask,
} kRDPC_LineMarginMask;

@interface RDPC_SeperatorLine : UIView

- (void)setSeperatorMask:(kRDPC_LineMarginMask)mask color:(UIColor *)color height:(CGFloat)height;

@end
