//
//  RDPC_QRCode.h
//  Pods
//
//  Created by whj on 17/1/9.
//
//

#import <Foundation/Foundation.h>

@interface RDPC_QRCode : NSObject

+ (UIImage *)rdpc_generateQrCodeByString:(NSString *)code size:(CGFloat)size;

+ (UIImage *)rdpc_generateQrCodeByString:(NSString *)code size:(CGFloat)size logoImg:(UIImage *)logo logoSize:(CGFloat)logoSize;

+ (UIImage *)rdpc_generateAlipayQrCodeByString:(NSString *)code;
+ (UIImage *)rdpc_genSaveAlipayImgByQrImg:(UIImage *)img;

@end
