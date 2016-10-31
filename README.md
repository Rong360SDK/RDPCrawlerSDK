# RDPCrawlerSDK
a crawler sdk of rong360

接入步骤：


1.在Podfile文件里添加 pod 'RDPCrawlerSDK', '~> 1.0.0'




2.在工程中的info.plist中的添加LSApplicationQueriesSchemes数组,在数组里面添加一个支持的scheme:alipayqr




3.初始化sdk, 调用接口传入appid和对应的p12格式的私钥    


  NSString *keyPath = [[NSBundle mainBundle] pathForResource:@"private" ofType:@"p12"];

  NSData *keyData = [NSData dataWithContentsOfFile:keyPath];

  [RDPCrawlerManager configAppId:@"申请的appid" delegate:self privateKey:keyData];





4.调用所需类型的抓取服务

  支付宝抓取:

  [RDPCrawlerManager startCrawlerByType:kRDPCrawlerTypeAlipay identifier:@"自定义的任务id"];
  
  淘宝抓取:
  
  [RDPCrawlerManager startCrawlerByType:kRDPCrawlerTypeTaobao identifier:@"自定义的任务id"];
