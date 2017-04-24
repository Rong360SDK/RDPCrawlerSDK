//
//  RDPC_FetchCell.h
//  Pods
//
//  Created by whj on 16/11/22.
//
//

#import "RDPCrawlerBaseCell.h"
#import "RDPC_FetchItem.h"
#import "RDPCMacro.h"

@interface RDPC_FetchCell : RDPCrawlerBaseCell

/**
 *  绑定的数据
 */
@property (nonatomic, strong) RDPC_FetchParamItem *item;

/**
 *  @return 根据当前item应该显示的高度
 */
- (CGFloat)showHeight;

/**
 *  根据当前cell的内容判断是否能提交
 *
 *  @return 当前的内容是否能提交
 */
- (BOOL)isValid;

/**
 *  根据内容提交的参数字典
 *
 *  @return 参数字典
 */
- (NSDictionary *)submitParam;

+ (RDPC_FetchCell *)cellByItem:(RDPC_FetchParamItem *)item;

@end
