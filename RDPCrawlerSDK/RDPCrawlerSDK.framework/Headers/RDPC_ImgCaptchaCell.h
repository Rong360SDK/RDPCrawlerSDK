//
//  RDPC_ImgCaptchaCell.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import "RDPC_FetchInputCell.h"
#import "RDPC_FetchDelegate.h"

@interface RDPC_ImgCaptchaCell : RDPC_FetchInputCell

@property (nonatomic, weak) id<RDPC_FetchRefreshDelegate> delegate;

/**
 *  刷新验证码
 */
- (void)refreshCaptcha;

/**
 *  替换验证码图片
 *
 *  @param img  替换的图片
 *  @param code 自动识别的验证码
 */
- (void)updateCaptcha:(UIImage *)img code:(NSString *)code;

@end
