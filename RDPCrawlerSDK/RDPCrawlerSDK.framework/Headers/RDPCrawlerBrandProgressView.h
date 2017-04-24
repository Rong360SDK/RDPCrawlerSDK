//
//  RDPCrawlerBrandProgressView.h
//  Pods
//
//  Created by rong360 on 16/9/20.
//
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, kNewBrandProgressSizeType) {
    kNewBrandSmallProgress = 0,
    kNewBrandMiddleProgress,
    kNewBrandBigProgress,
};


@interface RDPCrawlerBrandProgressView : UIView
- (RDPCrawlerBrandProgressView *)initWithType:(kNewBrandProgressSizeType)type;
- (void)beginAnimation;
- (void)endAnimation;

@end
