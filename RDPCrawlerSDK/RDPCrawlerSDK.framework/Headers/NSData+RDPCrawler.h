//
//  NSData+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/10/20.
//
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>

@interface NSData (RDPCrawler)

- (NSData *)rdpc_AES128Operation:(CCOperation)operation key:(NSString *)key;

/**
 *  加密
 *
 *  @param key 加密的key
 *
 *  @return
 */
- (NSData *)rdpc_EncryptWithKey:(NSString *)key;

/**
 *  解密
 *
 *  @param key 解密的ky
 *
 *  @return
 */
- (NSData *)rdpc_deEncryptWithKey:(NSString *)key;

/**
 *    压缩
 *
 *    @return
 */
- (NSData*)rdpc_compressGZip;

/**
 *    解压缩
 *
 *    @return
 */
- (NSData*)rdpc_decompressGZip;

@end
