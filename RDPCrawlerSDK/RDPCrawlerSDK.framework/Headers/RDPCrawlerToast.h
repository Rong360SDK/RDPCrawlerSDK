//
//  RDPCrawlerToast.h
//  RToast
//
//  Created by 郑明星 on 15/5/24.
//  Copyright (c) 2015年 郑明星. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    RToastTypeNormal = 1,
    RToastTypeError,
} RToastType;

@interface RDPCrawlerToast : UIView

- (void)showin:(UIView *)view withDuration:(CGFloat)duration;
+ (void)showToast:(NSString *)msg;
+ (void)showToast:(NSString *)msg toastType:(RToastType)type;

@end
