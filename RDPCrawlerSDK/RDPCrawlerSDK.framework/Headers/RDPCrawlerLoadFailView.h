//
//  RDPCrawlerLoadFailView.h
//  Pods
//
//  Created by zheng on 15/6/18.
//
//

#import <UIKit/UIKit.h>
@class RDPCrawlerLoadFailView;
@protocol RDPCrawlerLoadFailDelegate <NSObject>
@optional
//加载失败的描述字符串 默认是点击重新加载
- (NSString *)loadFailStringOf:(RDPCrawlerLoadFailView *)view;
//加载失败的图片名称 默认loading_fail
- (NSString *)loadFailImageNameOf:(RDPCrawlerLoadFailView *)view;
//点击失败视图的回调方法
- (void)tapedTheView:(RDPCrawlerLoadFailView *)view;
@end
@interface RDPCrawlerLoadFailView : UIView
@property (nonatomic, weak) id<RDPCrawlerLoadFailDelegate>delegate;
- (void)updateUI;
@end
