//
//  RDPC_ScrollView.h
//  RDPC
//
//  Created by Michael Tyson on 30/09/2013.
//  Copyright 2015 A Tasty Pixel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIScrollView+RDPCrawler.h"

@interface RDPC_ScrollView : UIScrollView <UITextFieldDelegate, UITextViewDelegate>

- (void)contentSizeToFit;
- (BOOL)focusNextTextField;
- (void)scrollToActiveTextField;

@end
