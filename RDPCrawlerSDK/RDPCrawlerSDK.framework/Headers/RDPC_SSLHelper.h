//
//  RDPC_SSLHelper.h
//  Pods
//
//  Created by whj on 17/1/11.
//
//

#import <Foundation/Foundation.h>
#import "RDPCMacro.h"

@interface RDPC_SSLHelper : NSObject

DEC_SINGLETON(RDPC_SSLHelper)

+ (NSSet *)defaultPinnedCertificates;

@end
