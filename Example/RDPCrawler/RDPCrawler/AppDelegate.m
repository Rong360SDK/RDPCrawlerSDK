//
//  AppDelegate.m
//  RDPCrawler
//
//  Created by whj on 16/10/31.
//  Copyright © 2016年 rong360. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <RDPCrawlerSDK/RDPCrawlerManager.h>

@interface AppDelegate () <RDPCrawlerDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    ViewController *vc = [ViewController new];
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    UINavigationController *nvc = [[UINavigationController alloc] initWithRootViewController:vc];
    self.window.rootViewController = nvc;
    [self.window makeKeyAndVisible];
    
    NSString *keyPath = [[NSBundle mainBundle] pathForResource:@"申请的appid对应的私钥证书" ofType:@"p12"];
    NSData *keyData = [NSData dataWithContentsOfFile:keyPath];
    [RDPCrawlerManager configAppId:@"申请的appid" delegate:self privateKey:keyData];
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark -RDPCrawlerDelegate
- (void)crawlerChangeStatus:(RDPCrawlerItem *)statusItem {
    switch (statusItem.status) {
        case kRDPCrawlerStatusStart:
            NSLog(@"获取到服务器任务id:%@", statusItem.serverId);
            break;
        case kRDPCrawlerStatusLoginSuccess:
            NSLog(@"登录成功");
            break;
        case kRDPCrawlerStatusFetchSuccess:
            NSLog(@"抓取数据成功");
            break;
        case kRDPCrawlerStatusFailed:
            NSLog(@"抓取失败, error = %@", statusItem.error.domain);
            break;
        case kRDPCrawlerStatusCancel:
            NSLog(@"用户手动取消");
            break;
        default:
            break;
    }
}


@end
