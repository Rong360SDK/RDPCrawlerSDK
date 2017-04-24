//
//  NSObject+LKModel.h
//  RDPC_DBHelper
//
//  Created by LJH on 13-4-15.
//  Copyright (c) 2013年 ljh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>


NS_ASSUME_NONNULL_BEGIN

@class RDPC_Property;
@class RDPC_ModelInfos;
@class RDPC_DBHelper;

#pragma mark - 表结构
@interface NSObject (RDPC_TabelStructure)

/**
 *  overwrite in your models(option)
 *
 *  @return # table name #
 */
+ (NSString *)rdpc_getTableName;

/**
 *  if you set it will use it as a table name
 */
@property (nullable, nonatomic, copy) NSString *rdpc_db_tableName;

/**
 *  the model is inserting ..
 */
@property (nonatomic, readonly) BOOL rdpc_db_inserting;

/**
 *  sqlite comes with rowid
 */
@property (nonatomic, assign) NSInteger rowid;

/**
 *  overwrite in your models, if your table has primary key
 
 *  主键列名 如果rowid<0 则跟据此名称update 和delete
 
 *  @return # column name  #
 */
+ (nullable NSString *)rdpc_getPrimaryKey;

/**
 *  multi primary key
 *  联合主键
 *  @return
 */
+ (nullable  NSArray *)rdpc_getPrimaryKeyUnionArray;

/**
 *  overwrite in your models set column attribute
 *
 *  @param property infos
 */
+ (void)rdpc_columnAttributeWithProperty:(RDPC_Property *)property;

/**
 *	@brief   get saved pictures and data file path,can overwirte
 
    获取保存的 图片和数据的文件路径
 */
+ (NSString *)rdpc_getDBImagePathWithName:(NSString *)filename;
+ (NSString *)rdpc_getDBDataPathWithName:(NSString *)filename;

@end

#pragma mark - 表数据操作
@interface NSObject (RDPC_TableData)

/***
 *	@brief      overwrite in your models,return insert sqlite table data
 *
 *
 *	@return     property the data after conversion
 */
- (nullable  id)rdpc_userGetValueForModel:(RDPC_Property *)property;

/***
 *	@brief	overwrite in your models,return insert sqlite table data
 *
 *	@param 	property        will set property
 *	@param 	value           sqlite value (NSString(NSData UTF8 Coding) or NSData)
 */
- (void)rdpc_userSetValueForModel:(RDPC_Property *)property value:(nullable id)value;

///overwrite
+ (nullable NSDateFormatter *)rdpc_getModelDateFormatter;

//lkdbhelper use
- (nullable id)rdpc_modelGetValue:(RDPC_Property *)property;
- (void)rdpc_modelSetValue:(RDPC_Property *)property value:(nullable NSString *)value;

- (nullable id)rdpc_singlePrimaryKeyValue;
- (BOOL)rdpc_singlePrimaryKeyValueIsEmpty;
- (nullable RDPC_Property *)rdpc_singlePrimaryKeyProperty;
+ (nullable NSString *)db_rdpcrowidAliasName;

@end

@interface NSObject (RDPC_Model)

/**
 *  return model use RDPC_DBHelper , default return global RDPC_DBHelper;
 *
 *  @return RDPC_DBHelper
 */
+ (RDPC_DBHelper *)getUsingRDPC_DBHelper;

/**
 *  class attributes
 *
 *  @return RDPC_ModelInfos
 */
+ (RDPC_ModelInfos *)rdpc_getModelInfos;

/**
 *	@brief Containing the super class attributes	设置是否包含 父类 的属性
 */
+ (BOOL)rdpc_isContainParent;

/**
 *  当前表中的列是否包含自身的属性。
 *
 *  @return BOOL
 */
+ (BOOL)rdpc_isContainSelf;

/**
 *	@brief log all property 	打印所有的属性名称和数据
 */
- (NSString *)rdpc_printAllPropertys;
- (NSString *)rdpc_printAllPropertysIsContainParent:(BOOL)containParent;

- (NSMutableString *)rdpc_getAllPropertysString;

@end

NS_ASSUME_NONNULL_END
