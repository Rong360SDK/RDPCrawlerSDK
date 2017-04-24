//
//  RDPC_FecthCacheItem.h
//  Pods
//
//  Created by whj on 17/3/29.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface RDPC_FecthCacheItem : NSObject

@property (nonatomic, copy) NSString *old_agent;

@property (nonatomic, weak) UIViewController *controller;

@property (nonatomic, weak) UIWebView *webView;

@end
