//
//  UIImage+RDPCrawler.h
//  Pods
//
//  Created by whj on 15/5/25.
//
//

#import <UIKit/UIKit.h>

@interface UIImage (RDPCrawler)

+ (UIImage *)rdpc_imgForColor:(UIColor *)color;
+ (UIImage *)rdpc_imgForColor:(UIColor *)color size:(CGSize)size;
- (UIImage *)rdpc_stretchImg;

@end
