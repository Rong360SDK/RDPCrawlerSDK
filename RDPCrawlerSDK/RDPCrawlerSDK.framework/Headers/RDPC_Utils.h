//
//  NSObject+LKUtils.h
//  RDPC_DBHelper
//
//  Created by LJH on 13-4-15.
//  Copyright (c) 2013年 ljh. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RDPC_Utils : NSObject
///返回根目录路径 "document"
+ (NSString *)getDocumentPath;
///返回 "document/dir/" 文件夹路径
+ (NSString *)getDirectoryForDocuments:(NSString *)dir;
///返回 "document/filename" 路径
+ (NSString *)getPathForDocuments:(NSString *)filename;
///返回 "document/dir/filename" 路径
+ (NSString *)getPathForDocuments:(NSString *)filename inDir:(NSString *)dir;
///文件是否存在
+ (BOOL)isFileExists:(NSString *)filepath;
///删除文件
+ (BOOL)deleteWithFilepath:(nullable NSString *)filepath;
///返回该文件目录下 所有文件名
+ (nullable NSArray *)getFilenamesWithDir:(nullable NSString *)dir;

///检测字符串是否为空
+ (BOOL)checkStringIsEmpty:(nullable NSString *)string;
+ (nullable NSString *)getTrimStringWithString:(nullable NSString *)string;

///把Date 转换成String
+ (NSString *)stringWithDate:(NSDate *)date;
///把String 转换成Date
+ (NSDate *)dateWithString:(NSString *)str;
///单例formatter
+ (NSNumberFormatter *)numberFormatter;

@end

#ifdef DEBUG
#ifdef NSLog
#define RDPC_ErrorLog(fmt, ...) NSLog(@"#RDPC_DBHelper ERROR:\n" fmt, ##__VA_ARGS__);
#else
#define RDPC_ErrorLog(fmt, ...) NSLog(@"\n#RDPC_DBHelper ERROR: %s  [Line %d] \n" fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#endif
#else
#define RDPC_ErrorLog(...)
#endif

#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_5_0 || __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_7
#define RDPC_Weak weak
#define __RDPC_Weak __weak
#else
#define RDPC_Weak unsafe_unretained
#define __RDPC_Weak
#endif

static NSString * const RDPC_SQL_Type_Text = @"text";
static NSString * const RDPC_SQL_Type_Int = @"integer";
static NSString * const RDPC_SQL_Type_Double = @"double";
static NSString * const RDPC_SQL_Type_Blob = @"blob";

static NSString * const RDPC_SQL_Attribute_NotNull = @"NOT NULL";
static NSString * const RDPC_SQL_Attribute_PrimaryKey = @"PRIMARY KEY";
static NSString * const RDPC_SQL_Attribute_Default = @"DEFAULT";
static NSString * const RDPC_SQL_Attribute_Unique = @"UNIQUE";
static NSString * const RDPC_SQL_Attribute_Check = @"CHECK";
static NSString * const RDPC_SQL_Attribute_ForeignKey = @"FOREIGN KEY";

static NSString * const RDPC_SQL_Convert_FloatType = @"float_double_decimal";
static NSString * const RDPC_SQL_Convert_IntType = @"int_char_short_long";
static NSString * const RDPC_SQL_Convert_BlobType = @"";

static NSString * const RDPC_SQL_Mapping_Inherit = @"RDPC_Inherit";
static NSString * const RDPC_SQL_Mapping_Binding = @"RDPC_Binding";
static NSString * const RDPC_SQL_Mapping_UserCalculate = @"RDPC_UserCalculate";

static NSString * const RDPC__TypeKey = @"DB_Type";

static NSString * const RDPC__TypeKey_Model = @"DB_Type_Model";
static NSString * const RDPC__TypeKey_JSON = @"DB_Type_JSON";
static NSString * const RDPC__TypeKey_Combo = @"DB_Type_Combo";
static NSString * const RDPC__TypeKey_Date = @"DB_Type_Date";

static NSString * const RDPC__ValueKey = @"DB_Value";

static NSString * const RDPC__TableNameKey = @"DB_TableName";
static NSString * const RDPC__ClassKey = @"DB_Class";
static NSString * const RDPC__RowIdKey = @"DB_RowId";
static NSString * const RDPC__PValueKey = @"DB_PKeyValue";

///Object-c type converted to SQLite type  把Object-c 类型 转换为sqlite 类型
extern NSString *RDPC_SQLTypeFromObjcType(NSString *objcType);

@interface RDPC_QueryParams : NSObject

///columns or array
@property (nullable, nonatomic, copy) NSString *columns;
@property (nullable, nonatomic, copy) NSArray *columnArray;

@property (nullable, nonatomic, copy) NSString *tableName;

///where or dic
@property (nullable, nonatomic, copy) NSString *where;
@property (nullable, nonatomic, copy) NSDictionary *whereDic;

@property (nullable, nonatomic, copy) NSString *groupBy;
@property (nullable, nonatomic, copy) NSString *orderBy;

@property (nonatomic, assign) NSInteger offset;
@property (nonatomic, assign) NSInteger count;

@property (nullable, nonatomic, assign) Class toClass;

@property (nullable, nonatomic, copy) void (^callback)(NSMutableArray * _Nullable results);

@end

NS_ASSUME_NONNULL_END
