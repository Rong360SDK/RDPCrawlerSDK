//
//  UIScrollView+RDPCrawler.h
//  RDPC
//
//  Created by Michael Tyson on 30/09/2013.
//  Copyright 2015 A Tasty Pixel. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIScrollView (RDPCrawler)
- (BOOL)RDPC_focusNextTextField;
- (void)RDPC_scrollToActiveTextField;

- (void)RDPC_keyboardWillShow:(NSNotification*)notification;
- (void)RDPC_keyboardWillHide:(NSNotification*)notification;
- (void)RDPC_updateContentInset;
- (void)RDPC_updateFromContentSizeChange;
- (void)RDPC_assignTextDelegateForViewsBeneathView:(UIView*)view;
- (UIView*)RDPC_findFirstResponderBeneathView:(UIView*)view;
- (CGSize)RDPC_calculatedContentSizeFromSubviewFrames;
@end
