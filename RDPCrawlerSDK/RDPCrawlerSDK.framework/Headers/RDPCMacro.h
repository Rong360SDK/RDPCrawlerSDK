//
//  RDPCMacro.h
//  Pods
//
//  Created by whj on 16/10/11.
//
//

#ifndef RDPCMacro_h
#define RDPCMacro_h

#import "RDPCrawlerMacro.h"
#import "RDPCrawlerToast.h"
#import "RDPCrawlerDot.h"

#define  RDPC_TEST_BASE_URL          @"https://openapisandbox.rong360.com/gateway"
#define  RDPC_TEST_STAT_LOG_UPLOAD_URL  @"https://crawlersandbox.rong360.com/crawler/api/sdk/submitEventLog"
#define  RDPC_TEST_SOCKET_URL           @"wss://appws.rong360.com:8080"

#define  RDPC_BASE_URL          @"https://openapi.rong360.com/gateway"
#define  RDPC_STAT_LOG_UPLOAD_URL  @"https://crawler.rong360.com/crawler/api/sdk/submitEventLog"
#define  RDPC_SOCKET_URL           @"wss://appws.rong360.com:8080"

#define  RDPC_LOG_SCHEME              @"r360scheme://crawlerSdkLog"
#define  RDPC_ALIPAY_JUMP_SCHEME      @"r360scheme://crawlerSdkAlipayJump"
#define  RDPC_ALIPAY_DOWNLOAD_SCHEME  @"r360scheme://crawlerSdkAlipayDownload"
#define  RDPC_BASE_METHOD(method)    [NSString stringWithFormat:@"crawler.api.sdk.%@", method]
#define  RDPC_ITEM_KEY          @"RDPC_ITEM_KEY"
#define  RDPC_ADDTION_PARAMS    @"RDPC_ADDTION_PARAMS"
#define  RDPC_PHONE_CONFIG_KEY         @"RDPC_PHONE_CONFIG"
#define  RDPC_SDK_VERSION       @"1.3.3"
#define  RDPC_HAS_SHOW_GUIDE    @"RDPC_HAS_SHOW_GUIDE"
//#define  RDPC_XIAOHAO

#endif /* RDPCMacro_h */
