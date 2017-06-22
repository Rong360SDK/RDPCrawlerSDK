//
//  RDPC_SMSCaptchaCell.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import "RDPC_FetchInputCell.h"
#import "RDPC_FetchDelegate.h"

@interface RDPC_SMSCaptchaCell : RDPC_FetchInputCell

@property (nonatomic, weak) id<RDPC_FetchRefreshDelegate> delegate;

@end
