//
//  RDPC_SendSmsCell.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import "RDPC_FetchInputCell.h"
#import "RDPC_FetchDelegate.h"

@interface RDPC_SendSmsCell : RDPC_FetchInputCell

@property (nonatomic, weak) id<RDPC_FetchSendSMSDelegate> delegate;

@end
