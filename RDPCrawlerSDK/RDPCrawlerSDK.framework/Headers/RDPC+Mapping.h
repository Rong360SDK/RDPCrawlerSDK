//
//  RDPC_Property+KeyMapping.h
//  RDPC_DBHelper
//
//  Created by LJH on 13-6-17.
//  Copyright (c) 2013年 ljh. All rights reserved.
//

#import "RDPC_Utils.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (RDPC_TableMapping)

/**
 *	@brief Overwrite in your models if your property names don't match your Table Column names.
 also use for set create table columns.
 
 @{ sql column name : ( model property name ) or RDPC_Inherit or RDPC_UserCalculate}
 
 */
+ (nullable NSDictionary *)rdpc_getTableMapping;

/***
 simple set a column as "RDPC_SQL_Mapping_UserCalculate"
 column name
*/
+ (void)setRDPC_UserCalculateForCN:(NSString *)columnName;

///property type name
+ (void)setRDPC_UserCalculateForPTN:(NSString *)propertyTypeName;

///binding columnName to PropertyName
+ (void)setRDPC_TableColumnName:(NSString *)columnName bindingPropertyName:(NSString *)propertyName;

///remove unwanted binding property
+ (void)rdpc_removePropertyWithColumnName:(NSString *)columnName;
+ (void)rdpc_removePropertyWithColumnNameArray:(NSArray *)columnNameArray;

@end

@interface RDPC_Property : NSObject

///保存的方式
@property (nonatomic, copy, readonly) NSString *type;

///保存到数据的  列名
@property (nonatomic, copy, readonly) NSString *sqlColumnName;
///保存到数据的类型
@property (nonatomic, copy, readonly) NSString *sqlColumnType;

///属性名
@property (nonatomic, copy, readonly) NSString *propertyName;
///属性的类型
@property (nonatomic, copy, readonly) NSString *propertyType;

///属性的Protocol
//@property(readonly,copy,nonatomic)NSString *propertyProtocol;

///creating table's column
@property (nonatomic, assign) BOOL isUnique;
@property (nonatomic, assign) BOOL isNotNull;
@property (nullable, nonatomic, copy) NSString *defaultValue;
@property (nullable, nonatomic, copy) NSString *checkValue;
@property (nonatomic, assign) NSInteger length;

- (BOOL)isUserCalculate;
@end

@interface RDPC_ModelInfos : NSObject

- (id)initWithKeyMapping:(nullable NSDictionary *)keyMapping
           propertyNames:(NSArray *)propertyNames
            propertyType:(NSArray *)propertyType
             primaryKeys:(nullable NSArray *)primaryKeys;

@property (nonatomic, readonly) NSUInteger count;
@property (nullable, nonatomic, readonly) NSArray *primaryKeys;

- (nullable RDPC_Property *)objectWithIndex:(NSInteger)index;
- (nullable RDPC_Property *)objectWithPropertyName:(NSString *)propertyName;
- (nullable RDPC_Property *)objectWithSqlColumnName:(NSString *)columnName;

@end

NS_ASSUME_NONNULL_END
