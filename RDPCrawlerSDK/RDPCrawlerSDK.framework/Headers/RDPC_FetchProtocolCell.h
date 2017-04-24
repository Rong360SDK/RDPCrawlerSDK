//
//  RDPC_FetchProtocolCell.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import "RDPC_FetchInputCell.h"
#import "RDPC_FetchDelegate.h"

@interface RDPC_FetchProtocolCell : RDPC_FetchInputCell

@property (nonatomic, weak) id<RDPC_FetchProtocolDelegate> delegate;

@end
