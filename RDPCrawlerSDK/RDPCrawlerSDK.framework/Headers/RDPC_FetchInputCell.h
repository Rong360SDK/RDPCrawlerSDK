//
//  RDPC_FetchInputCell.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import "RDPC_FetchCell.h"
#import "RDPC_SeperatorLine.h"
#import "RDPC_AttributedLabel.h"

@interface RDPC_FetchInputCell : RDPC_FetchCell

/**
 *  标题文本
 */
@property (nonatomic, strong) UILabel *titleLabel;

/**
 *  输入框
 */
@property (nonatomic, strong) UITextField *inputField;

/**
 *  底部提示的分割线
 */
@property (nonatomic, strong) RDPC_SeperatorLine *seperatorLine;

/**
 *  底部提示的view
 */
@property (nonatomic, strong) UIView *promptView;

/**
 *  底部文本提示的label
 */
@property (nonatomic, strong) RDPC_AttributedLabel *promptLab;

@end
