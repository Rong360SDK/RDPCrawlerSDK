#import <Foundation/Foundation.h>
#import "RDPCrawlerAFNetworking.h"

typedef NS_ENUM(NSInteger , RDPCrawlerRequestMethod) {
    RDPCrawlerRequestMethodGet = 0,
    RDPCrawlerRequestMethodPost,
    RDPCrawlerRequestMethodHead,
    RDPCrawlerRequestMethodPut,
    RDPCrawlerRequestMethodDelete,
    RDPCrawlerRequestMethodPatch
};

typedef NS_ENUM(NSInteger , RDPCrawlerRequestSerializerType) {
    RDPCrawlerRequestSerializerTypeHTTP = 0,
    RDPCrawlerRequestSerializerTypeJSON,
};

typedef NS_ENUM(NSInteger , RDPCrawlerResponseSerializerType) {
    RDPCrawlerResponseSerializerTypeHTTP = 0,
    RDPCrawlerResponseSerializerTypeJSON,
};

typedef void (^RDPCrawlerAFConstructingBlock)(id<RDPCrawlerAFMultipartFormData> formData);
typedef void (^RDPCrawlerAFURLSessionTaskProgressBlock)(NSProgress *);

@class RDPCrawlerBaseRequest;

@protocol RDPCrawlerRequestDelegate <NSObject>

- (void)requestFinished:(RDPCrawlerBaseRequest *)request;
- (void)requestFailed:(RDPCrawlerBaseRequest *)request;

@optional
- (void)clearRequest;

@end

@protocol RDPCrawlerRequestAccessory <NSObject>

@optional

- (void)requestWillStart:(id)request;
- (void)requestWillStop:(id)request;
- (void)requestDidStop:(id)request;

@end

@interface RDPCrawlerBaseRequest : NSObject

/// Tag
@property (nonatomic) NSInteger tag;

/// User info
@property (nonatomic, strong) NSDictionary *userInfo;

@property (nonatomic, strong) NSURLSessionTask *sessionTask;

/// request delegate object
@property (nonatomic, weak) id<RDPCrawlerRequestDelegate> delegate;


@property (nonatomic, strong, readonly) NSDictionary *responseHeaders;

@property (nonatomic, strong, readonly) NSString *responseString;

@property (nonatomic, strong) id responseJSONObject;

@property (nonatomic, readonly) NSInteger responseStatusCode;

@property (nonatomic, copy) void (^successCompletionBlock)(RDPCrawlerBaseRequest *);

@property (nonatomic, copy) void (^failureCompletionBlock)(RDPCrawlerBaseRequest *);

@property (nonatomic, strong) NSMutableArray *requestAccessories;

@property (nonatomic, assign) BOOL needCleanBlock;

@property (nonatomic, strong) NSError *error;

@property (nonatomic, assign) RDPCrawlerResponseSerializerType responseSerializerType;

/// append self to request queue
- (void)start;

/// remove self from request queue
- (void)stop;

/// block回调
- (void)startWithCompletionBlockWithSuccess:(void (^)(RDPCrawlerBaseRequest *request))success
                                    failure:(void (^)(RDPCrawlerBaseRequest *request))failure;

- (void)setCompletionBlockWithSuccess:(void (^)(RDPCrawlerBaseRequest *request))success
                              failure:(void (^)(RDPCrawlerBaseRequest *request))failure;

/// 把block置nil来打破循环引用
- (void)clearCompletionBlock;

/// Request Accessory，可以hook Request的start和stop
- (void)addAccessory:(id<RDPCrawlerRequestAccessory>)accessory;

/// 以下方法由子类继承来覆盖默认值

/// 请求成功的回调
- (void)requestCompleteFilter;

/// 请求失败的回调
- (void)requestFailedFilter;

/// 请求的URL
- (NSString *)requestUrl;

/// 请求的CdnURL
- (NSString *)cdnUrl;

/// 请求的BaseURL
- (NSString *)baseUrl;

/// 请求的连接超时时间，默认为60秒
- (NSTimeInterval)requestTimeoutInterval;

/// 请求的参数列表
- (id)requestArgument;

/// 用于在cache结果，计算cache文件名时，忽略掉一些指定的参数
- (id)cacheFileNameFilterForRequestArgument:(id)argument;

/// Http请求的方法
- (RDPCrawlerRequestMethod)requestMethod;

/// 请求的SerializerType
- (RDPCrawlerRequestSerializerType)requestSerializerType;

/// 请求的Server用户名和密码
- (NSArray *)requestAuthorizationHeaderFieldArray;

/// 在HTTP报头添加的自定义参数
- (NSDictionary *)requestHeaderFieldValueDictionary;

/// 构建自定义的UrlRequest，
/// 若这个方法返回非nil对象，会忽略requestUrl, requestArgument, requestMethod, requestSerializerType
- (NSURLRequest *)buildCustomUrlRequest;

/// 是否使用CDN的host地址
- (BOOL)useCDN;

/// 用于检查JSON是否合法的对象
- (id)jsonValidator;

/// 用于检查Status Code是否正常的方法
- (BOOL)statusCodeValidator;

/// 当POST的内容带有文件等富文本时使用
- (RDPCrawlerAFConstructingBlock)constructingBodyBlock;

/// 文件需要存储的位置
- (NSString *)resumableDownloadPath;

/// 数据请求的下载的进度
- (RDPCrawlerAFURLSessionTaskProgressBlock)downloadProgressBlock;

/// 数据上传的进度
- (RDPCrawlerAFURLSessionTaskProgressBlock)uploadProgressBlock;
@end
