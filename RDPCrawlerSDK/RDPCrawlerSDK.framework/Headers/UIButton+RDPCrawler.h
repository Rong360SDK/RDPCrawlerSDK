//
//  UIButton+RDPCrawler.h
//  Pods
//
//  Created by whj on 15/10/16.
//
//

#import <UIKit/UIKit.h>
/**
 *  按钮类型
 */
typedef NS_ENUM(NSInteger, kRDPCrawlerButtonType) {
    /**
     *  红色背景按钮
     */
    kRDPC_RedBgType = 1,
    /**
     *  蓝色背景按钮
     */
    kRDPC_BlueBgType,
};

@interface UIButton (RDPCrawler)

+ (instancetype)rdpc_customButtonWithType:(kRDPCrawlerButtonType)type;


- (void)rdpc_setCustomType:(kRDPCrawlerButtonType)type;

@end
