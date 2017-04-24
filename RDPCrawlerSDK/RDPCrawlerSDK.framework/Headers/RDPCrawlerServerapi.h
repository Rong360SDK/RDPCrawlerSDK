//
//  RDPCrawlerServerapi.h
//  R360DP
//
//  Created by LiuDequan on 15/5/13.
//  Copyright (c) 2015年 liudequan. All rights reserved.
//

#import "RDPCrawlerRequest.h"

@interface RDPCrawlerServerapi : RDPCrawlerRequest

// 自动解析的数据类型 可能在不同线程访问  因此设置为 atomic
@property (assign,atomic) Class parseDataClassType;
// 返回结果的key
@property (nonatomic, weak) NSString *resultKey;
// 文件上传block
@property (nonatomic, copy) RDPCrawlerAFConstructingBlock afConstructBlock;
// 请求的参数
@property (nonatomic, strong) NSDictionary *reqParams;
// 请求的url
@property (nonatomic, strong) NSString *url;
// 上传进度
@property (nonatomic, copy) RDPCrawlerAFURLSessionTaskProgressBlock afUploadProgressBlock;
// 下载进度
@property (nonatomic, copy) RDPCrawlerAFURLSessionTaskProgressBlock afDownLodProgressBlock;

/**
 *    初始化
 *
 *    @param url 访问的url，也可以是后面的路径，是路径的时候，url必须为统一url
 *
 *    @return
 */
- (id)initWithUrl:(NSString *)url;

/**
 *    设置请求的url
 *
 *    @param url 请求的url
 */
- (void)setRequestUrl:(NSString *)url;

/**
 *    设置超时时间
 *
 *    @param timeOut
 */
- (void)setTimeOut:(int)timeOut;

/**
 *    设置请求参数
 *
 *    @param param
 */
- (void)setRequestParams:(NSDictionary *)param;

/**
 *    设置请求的方法 默认post
 *
 *    @param method
 */
- (void)setRequestMethod:(RDPCrawlerRequestMethod)method;

@end
