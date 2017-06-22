//
//  RDPC_ActionSheet.h
//  Pods
//
//  Created by whj on 16/11/23.
//
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, kRPDC_ActionSheetType) {
    // 列表
    kRPDC_ActionSheetTypeTable = 0,
    // 日期 年月日
    kRPDC_ActionSheetTypeDate,
    // 年月
    kRPDC_ActionSheetTypeYearAndMonth,
};

@class RDPC_ActionSheet;
@protocol RDPC_ActionSheetDelegate <NSObject>

@optional
- (void)actionSheet:(RDPC_ActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)actionSheet:(RDPC_ActionSheet *)actionSheet selectedDate:(NSDate *)selectedDate;
- (void)actionSheet:(RDPC_ActionSheet *)actionSheet yearAndMonth:(NSString *)yearAndMonth;
- (void)actionSheetDidCancel:(RDPC_ActionSheet *)actionSheet;

@end

@interface RDPC_ActionSheet : UIView <UIPickerViewDataSource, UIPickerViewDelegate>

@property (nonatomic, weak) id <RDPC_ActionSheetDelegate> delegate;

@property (nonatomic, strong) NSString *mTitle;
@property (nonatomic, strong) NSMutableArray *mRows;
@property (nonatomic, strong) UIFont *mFont;

@property (nonatomic, assign) kRPDC_ActionSheetType actionSheetType;

// item的高度，默认50
@property (nonatomic, assign) CGFloat mItemHeight;
// 数据中将要展示的字段
@property (nonatomic, strong) NSString *mShowKey;
// 默认选择
@property (nonatomic, assign) NSInteger mSelectedIndex;


/**
 *  当前选择的日期
 */
@property (nonatomic, strong) NSDate *selectedDate;

+ (RDPC_ActionSheet *)actionSheetWithTitle:(NSString *)title
                                 delegate:(id<RDPC_ActionSheetDelegate>)delegate
                                     rows:(NSArray *)rows;
+ (RDPC_ActionSheet *)actionSheetWithTitle:(NSString *)title
                                 delegate:(id<RDPC_ActionSheetDelegate>)delegate
                                     rows:(NSArray *)rows
                                  showKey:(NSString *)showKey;
+ (RDPC_ActionSheet *)actionSheetWithActionType:(kRPDC_ActionSheetType)actionType
                                         title:(NSString *)title
                                      delegate:(id<RDPC_ActionSheetDelegate>)delegate
                                          rows:(NSArray *)rows
                                       showKey:(NSString *)showKey;

- (void)showActionSheetInView:(UIView *)targetView;

@end
