//
//  RDPCWebviewVc.h
//  Pods
//
//  Created by whj on 16/10/17.
//
//

#import "RDPCrawlerViewController.h"

@interface RDPCWebviewVc : RDPCrawlerViewController<UIWebViewDelegate>

@property (nonatomic, strong) UIWebView *innerWebView;

@end
