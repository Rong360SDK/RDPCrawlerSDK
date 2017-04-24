//
//  RDPCrawlerNetLoadingView.h
//  Pods
//
//  Created by whj on 15/6/11.
//
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, kProgressType) {
    kFullScreenProgress = 0,
    kCenterProgress,
};

@interface RDPCrawlerNetLoadingView : UIView

- (instancetype)initWithFrame:(CGRect)frame type:(kProgressType)type;
- (void)showInView:(UIView *)view isAnimation:(BOOL)isAnimation;
- (void)hide:(BOOL)isAnimation;
- (void)updateByAttributeString:(NSAttributedString *)prompt;

+ (void)showLoadingInView:(UIView *)view;
+ (void)showLoadingInView:(UIView *)view animation:(BOOL)isAnimation;
+ (void)showLoadingInView:(UIView *)view animation:(BOOL)isAnimation type:(kProgressType)type;
+ (void)showLoadingInView:(UIView *)view animation:(BOOL)isAnimation type:(kProgressType)type tag:(NSUInteger)baseTag;
+ (void)showLoadingInView:(UIView *)view animation:(BOOL)isAnimation type:(kProgressType)type prompt:(NSAttributedString *)prompt tag:(NSUInteger)tag;

+ (void)hideLoadingInView:(UIView *)view;
+ (void)hideLoadingInView:(UIView *)view animation:(BOOL)isAnimation;
+ (void)hideLoadingInView:(UIView *)view animation:(BOOL)isAnimation type:(kProgressType)type;
+ (void)hideLoadingInView:(UIView *)view animation:(BOOL)isAnimation type:(kProgressType)type tag:(NSUInteger)baseTag;

@end
