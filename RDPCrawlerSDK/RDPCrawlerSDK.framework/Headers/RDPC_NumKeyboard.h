//
//  RDPNumKeyboard.h
//  Pods
//
//  Created by whj on 15/7/9.
//
//

#import <UIKit/UIKit.h>
/**
 *  自定义键盘类型
 */
typedef NS_ENUM(NSInteger, kRDPC_CustomKeyboardType){
    /**
     *  带小数点的数字键盘
     */
    kRDPC_TypeNumKeyboard = 0,
    /**
     *  身份证键盘
     */
    kRDPC_TypeIDNoKeyboard,
    /**
     *  自动布局的小数点键盘
     */
    kRDPC_TypeNumKeyboardRandom,
    /**
     *  自动布局的身份证键盘
     */
    kRDPC_TypeIDNoKeyboardRandom,
    /**
     *  纯数字键盘不带小数点
     */
    kRDPC_TypeNumberPad,
    
};

#define CUSTOM_HIDE_KEYBOARD_NOTIFICATION       @"rdpsdk_hide_keyboard"

@interface RDPC_NumKeyboard : UIView

+ (void)addKeyboardTo:(UITextField *)field type:(kRDPC_CustomKeyboardType)type;

@end
