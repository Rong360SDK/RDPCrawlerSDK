//
//  RDPCrawlerMacro.h
//  Pods
//
//  Created by whj on 15/5/14.
//
//

#ifndef Pods_R360Macro_h
#define Pods_R360Macro_h

#import "NSDictionary+RDPCrawler.h"
#import "NSArray+RDPCrawler.h"
#import "NSData+RDPCrawler.h"
#import "NSDate+RDPCrawler.h"
#import "NSString+RDPCrawler.h"
#import "RDPCrawlerMasonry.h"
#import "RDPCrawlerJson.h"

// 融360itunes connect url
#define R360_APP_ITUNES_CONNECT_URL [NSString stringWithFormat:@"https://itunes.apple.com/cn/app/id%@?mt=8",R360_ITUNES_ID]

/******************************配置******************************/

//#define R360_JSD

// 渠道
#define R360_CHANNLE [[[NSBundle mainBundle]infoDictionary] rdpc_stringAtPath:@"R360_CHANNLE"]
// api version
#define R360_API_VERSION @"2.0"

// 是否使用百度地图
#define R360_USE_BAIDU_MAP 1
// 贷款单独版本
//#define RL_SINGAL_LOAN_APP 1


//融360自定义Container
#define SHOWCUSTOMCONTAINER
// 融360免费版
#define R360F
// 融360收费版
//#define R360P


#ifdef R360F
//app名字
#define R360_APP_NAME @"R360F"
#define R360_APP_ID   @"1"
//appid
#define R360_ITUNES_ID @"1026689855"

// 百度地图key
#define R360_BAIDU_MAP_KEY @"WyBYEXn9nNLNQUlqxsatK5Io"
// 分享的key
#define kUMSocialKey    @"55b6eaebe0f55a5070002e56"
#define kWXAppId        @"wx9dd505db3698cd25"
#define kQQAppId        @"1104684190"
#define kBuglyAppKey    @"900010470"
#define kJPushAppKey    @"c836de6672ada95a66ecbfa1"

#endif


#ifdef R360P
// app名字
#define R360_APP_NAME @"R360PRO"
#define R360_APP_ID   @"11"
//appid
#define R360_ITUNES_ID @"1123934676"

// 百度地图key
#define R360_BAIDU_MAP_KEY @"TLYcZkBZ31nqr7s5zYkDSovQojhO9pt6"
// 分享的key
#define kUMSocialKey    @"574d3204e0f55a19ec0017d6"
#define kWXAppId        @"wxe8d25448f4919787"
#define kQQAppId        @"1105465480"
#define kBuglyAppKey    @"900031806"
#define kJPushAppKey    @"16f8ae661887f7dec39ca4df"

#endif

#define AB_TEST_KEY     @"abclass"

/******************************配置******************************/

#if 0
#define RDP_NULLABLE _Nullable
#define RDP_NULLABLE_S nullable
#define RDP_NONULLABLE  _Nonnull
#else
#define RDP_NULLABLE
#define RDP_NULLABLE_S
#define RDP_NONULLABLE
#endif

// view的顶部高度
#define RDP_VIEW_TOP_HEIGHT (64)
#define RDP_FAIL_VIEW_TAG (33255)
#define RDP_ACTION_SHEET_VIEW_TAG (2016101905)

/*
 * 快速申明一个属性, 默认为非原子的。如果想定义其它类型的此宏不可用
 * NSObject类型的assign, copy; Block的copy; 不可用下面的宏
 */
#define PropertyObject(type, name)  @property (nonatomic, strong) type *name
#define PropertyString(name)        @property (nonatomic, copy) NSString *name

#define PropertyEnum(type, name)    @property (nonatomic, assign) type name
#define PropertyInteger(name)       @property (nonatomic, assign) NSInteger name
#define PropertyFloat(name)         @property (nonatomic, assign) float name
#define PropertyDouble(name)        @property (nonatomic, assign) double name
#define PropertyShort(name)         @property (nonatomic, assign) short name
#define PropertyInt(name)           @property (nonatomic, assign) int name
#define PropertyLong(name)          @property (nonatomic, assign) long name
#define PropertySize(name)          @property (nonatomic, assign) CGSize name
#define PropertyRect(name)          @property (nonatomic, assign) CGRect name
#define PropertyPoint(name)         @property (nonatomic, assign) CGPoint name

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;
// 字体的乘数因子
#define R360_HOMEPAGE_FONE_MULTIPLIER (0.5f)

/******************************屏幕大小******************************/
//NavBar高度
#define NAV_BAR_HEIGHT       44
//statusBar高度
#define STATUS_BAR_HEIGHT    20
//section间距
#define GapBetweenSections 20
//默认间距 一般为左右边距
#define DefaultGap           15

//1像素, 一般为分割线的宽度
#define RDP_ONE_PIXELS       (1.f / [UIScreen mainScreen].scale)
//1像素的起点坐标偏移值
#define RDP_ONE_PIXEL_LINE_ADJUST_OFFSET   ((1.f / [UIScreen mainScreen].scale) / 2)

//获取屏幕 宽度、高度
#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)
#define scaleBy320(x) ((int)(SCREEN_WIDTH)*(x)/320)
#define DRAW_LINE_WIDTH (1/[[UIScreen mainScreen] scale])
/******************************屏幕大小******************************/


/******************************日志******************************/

// 控制是否打印对象释放dealloc
//#define R360_DEALLOC_LOG

//DEBUG  模式下打印日志,当前行
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

// 控制NSLog打印
#ifndef DEBUG
#undef NSLog
#define NSLog(args, ...)
#endif

/******************************日志******************************/


/******************************系统版本******************************/
//应用版本
#define APP_VERSION    [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
//获取系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

//检查系统版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#ifndef kCFCoreFoundationVersionNumber_iOS_8_0
#define kCFCoreFoundationVersionNumber_iOS_8_0 1129.150000
#endif

#ifdef __IPHONE_8_0
#define IASK_IF_IOS8_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_8_0) \
{ \
__VA_ARGS__ \
}
#else
#define IASK_IF_IOS8_OR_GREATER(...)
#endif

/******************************系统版本******************************/



/******************************图片******************************/

//读取本地图片
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:file ofType:ext]]
//定义UIImage对象
#define ImageNamed(name) [UIImage imageNamed:name]

/******************************图片******************************/




/******************************颜色类******************************/
// 16进制颜色
#define HEXCOLOR(rgbValue) HEXACOLOR(rgbValue, 1.f)
#define HEXACOLOR(rgbValue, a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]

// RGB颜色
#define RGBCOLOR(r,g,b)    RGBACOLOR(r, g, b, 1.f)
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define RDP_SEPARATOR_COLOR  HEXCOLOR(0xd8d9dc)
/******************************颜色类******************************/



/******************************类型转换******************************/
//转成NSString
#define LONGSTR(a)    [NSString stringWithFormat:@"%ld", a]
#define INTSTR(a)     [NSString stringWithFormat:@"%d", a]
#define LLONGSTR(a)   [NSString stringWithFormat:@"%lld", a]
#define BOOLSTR(a)    [NSString stringWithFormat:@"%d", a ? 1 : 0]
#define FLOATSTR(a)   [NSString stringWithFormat:@"%f", a]
#define DOUBLESTR(a)  [NSString stringWithFormat:@"%lf", a]
#if __LP64__ || (TARGET_OS_EMBEDDED && !TARGET_OS_IPHONE) || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
#define INTEGERSTR(a)  LONGSTR(a)
#else
#define INTEGERSTR(a)  INTSTR(a)
#endif

//转成NSNumber
#define BOOLNUM(a)    [NSNumber numberWithBool:a]
#define INTNUM(a)     [NSNumber numberWithInt:a]
#define LONGNUM(a)    [NSNumber numberWithLong:a]
#define LLONGNUM(a)   [NSNumber numberWithLongLong:a]
#define FLOATNUM(a)   [NSNumber numberWithFloat:a]
#define DOUBLENUM(a)  [NSNumber numberWithDouble:a]
/******************************类型转换******************************/

/******************************gcd******************************/
#define BACKGCD(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAINGCD(block) dispatch_async(dispatch_get_main_queue(),block)
/******************************gcd*******************************/

/******************************安全*******************************/
#define SAFE_DIVISION(a,b)  (b == 0 ? (a) : ((a) / (b)))
#define SAFE_STRING(x) (x ?: @"")
/******************************安全*******************************/

/******************************其它*******************************/
//字体
#define SYSTEMFONT(x)       [UIFont systemFontOfSize:(x)*1.0f]
//语言本地化
#define LOCALSTR(x)         NSLocalizedString(x, nil)
#define LOCALTABSTR(x, tab) NSLocalizedStringFromTable(x, tab, nil)
//NSUserDefaults 实例化
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]
//获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])
//金额字符串
#define MONEYSTR(x)      [NSString stringWithFormat:@"%.2f", x]
/******************************其它*******************************/

/******************************performSelector 去掉警告*******************************/
#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)
/******************************performSelector 去掉警告*******************************/

/******************************单例模式*******************************/
#undef	DEC_SINGLETON
#define DEC_SINGLETON( __class ) \
+ (__class *)sharedInstance;

#undef	DEF_SINGLETON
#define DEF_SINGLETON( __class ) \
+ (__class *)sharedInstance \
{ \
static dispatch_once_t once; \
static __class * __singleton__; \
dispatch_once( &once, ^{ __singleton__ = [[__class alloc] init]; } ); \
return __singleton__; \
}
/******************************单例模式*******************************/

#endif
