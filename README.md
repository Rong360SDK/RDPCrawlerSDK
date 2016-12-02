# RDPCrawlerSDK
a crawler sdk of rong360

需要先申请appid, 配置好相应的证书和回调url
PS:(debug版本连的是测试环境，release版本连的正式环境)

接入步骤：

1.在Podfile文件里添加 pod 'RDPCrawlerSDK', 然后pod update(需更新下本地pod仓库，避免本地仓库不包含sdk的信息)



2.在工程中的info.plist中的添加LSApplicationQueriesSchemes数组,在数组里面添加一个支持的scheme:alipayqr




3.初始化sdk, 调用接口传入appid和对应的p12格式的私钥    


  NSString *keyPath = [[NSBundle mainBundle] pathForResource:@"private" ofType:@"p12"];

  NSData *keyData = [NSData dataWithContentsOfFile:keyPath];

  如私钥文件没有设置密码调用以下方法：

  [RDPCrawlerManager configAppId:@"申请的appid" delegate:self privateKey:keyData];
 
  如私钥文件设置了密码调用另一个方法:

  [RDPCrawlerManager configAppId:@"申请的appid" delegate:self privateKey:keyData password:@"私钥密码"];
  

4.调用所需类型的抓取服务

  支付宝抓取:

  [RDPCrawlerManager startCrawlerByType:kRDPCrawlerTypeAlipay identifier:@"自定义的任务id"];
  
  淘宝抓取:
  
  [RDPCrawlerManager startCrawlerByType:kRDPCrawlerTypeTaobao identifier:@"自定义的任务id"];
