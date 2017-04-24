//
//  RDPCrawlerRSA.h
//  Pods
//
//  Created by whj on 16/10/25.
//
//

#import <Foundation/Foundation.h>
#import <RDPCrawlerMacro.h>

@interface RDPCrawlerRSA : NSObject

DEC_SINGLETON(RDPCrawlerRSA)

-(SecKeyRef)getPrivateKey;

- (void)loadPublicKeyFromData:(NSData *)derData;
- (void)loadPrivateKeyFromData:(NSData *)p12Data password:(NSString *)p12Password;

- (NSString*)rsaEncryptString:(NSString *)string;
- (NSData*)rsaEncryptData:(NSData *)data ;

- (NSString*)rsaDecryptString:(NSString *)string;
- (NSData*)rsaDecryptData:(NSData *)data;

- (NSData *)signSHA1Data:(NSData *)plainData;
- (BOOL)rsaSHA1VerifyData:(NSData *)plainData withSignature:(NSData *)signature;

@end
