//
//  RDKTipView.h
//  Pods
//
//  Created by whj on 16/9/21.
//
//

#import <UIKit/UIKit.h>

@interface RDPCrawlerAuthTipView : UIView

- (void)updateByTip:(NSString *)tips;

+ (CGFloat)heightByTips:(NSString *)tips;

@end
