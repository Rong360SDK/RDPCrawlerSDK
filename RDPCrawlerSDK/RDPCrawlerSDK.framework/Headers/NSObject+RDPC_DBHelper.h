//
//  NSObject+RDPC_DBHelper.h
//  RDPC_DBHelper
//
//  Created by LJH on 13-6-8.
//  Copyright (c) 2013年 ljh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RDPC_DBHelper.h"

NS_ASSUME_NONNULL_BEGIN

@class RDPC_DBHelper;

@interface NSObject (RDPC_DBHelper_Delegate)

+ (void)rdpc_dbDidCreateTable:(RDPC_DBHelper *)helper tableName:(NSString *)tableName;
+ (void)rdpc_dbDidAlterTable:(RDPC_DBHelper *)helper tableName:(NSString *)tableName addColumns:(NSArray *)columns;

+ (BOOL)rdpc_dbWillInsert:(NSObject *)entity;
+ (void)rdpc_dbDidInserted:(NSObject *)entity result:(BOOL)result;

+ (BOOL)rdpc_dbWillUpdate:(NSObject *)entity;
+ (void)rdpc_dbDidUpdated:(NSObject *)entity result:(BOOL)result;

+ (BOOL)rdpc_dbWillDelete:(NSObject *)entity;
+ (void)rdpc_dbDidDeleted:(NSObject *)entity result:(BOOL)result;

///data read finish
+ (void)rdpc_dbDidSeleted:(NSObject *)entity;

@end

//only simplify synchronous function
@interface NSObject (RDPC_DBHelper_Execute)

/**
 *  返回行数
 *
 *  @param where type can NSDictionary or NSString
 *
 *  @return  row count
 */
+ (NSInteger)rdpc_rowCountWithWhere:(nullable id)where, ...;
+ (NSInteger)rdpc_rowCountWithWhereFormat:(nullable id)where, ...;

/**
 *  搜索
 *
 *  @param columns type can NSArray or NSString(Search for a specific column.  Search only one, only to return the contents of the column collection)
 
 *  @param where   where type can NSDictionary or NSString
 *  @param orderBy
 *  @param offset
 *  @param count
 *
 *  @return model collection  or   contents of the columns collection
 */
+ (nullable NSMutableArray *)rdpc_searchColumn:(nullable id)columns
                                    where:(nullable id)where
                                  orderBy:(nullable NSString *)orderBy
                                   offset:(NSInteger)offset
                                    count:(NSInteger)count;

+ (nullable NSMutableArray *)rdpc_searchWithWhere:(nullable id)where
                                     orderBy:(nullable NSString *)orderBy
                                      offset:(NSInteger)offset
                                       count:(NSInteger)count;

+ (nullable NSMutableArray *)rdpc_searchWithWhere:(nullable id)where;

+ (nullable NSMutableArray *)rdpc_searchWithSQL:(NSString *)sql;

+ (nullable id)rdpc_searchSingleWithWhere:(nullable id)where
                             orderBy:(nullable NSString *)orderBy;

+ (BOOL)rdpc_insertToDB:(NSObject *)model;
+ (BOOL)rdpc_insertWhenNotExists:(NSObject *)model;

+ (BOOL)rdpc_updateToDB:(NSObject *)model
             where:(nullable id)where, ...;
+ (BOOL)rdpc_updateToDBWithSet:(NSString *)sets
                    where:(nullable id)where, ...;

+ (BOOL)rdpc_deleteToDB:(NSObject *)model;
+ (BOOL)rdpc_deleteWithWhere:(nullable id)where, ...;

+ (BOOL)rdpc_isExistsWithModel:(NSObject *)model;

- (BOOL)rdpc_updateToDB;
- (BOOL)rdpc_saveToDB;
- (BOOL)rdpc_deleteToDB;
- (BOOL)rdpc_isExistsFromDB;

///异步插入数据 async insert array ， completed 也是在子线程直接回调的
+ (void)rdpc_insertArrayByAsyncToDB:(NSArray *)models;
+ (void)rdpc_insertArrayByAsyncToDB:(NSArray *)models completed:(nullable void (^)(BOOL allInserted))completedBlock;

///begin translate for insert models  开始事务插入数组
+ (void)rdpc_insertToDBWithArray:(NSArray *)models
                     filter:(nullable void (^)(id model, BOOL inserted, BOOL * _Nullable rollback))filter;

+ (void)rdpc_insertToDBWithArray:(NSArray *)models
                     filter:(nullable void (^)(id model, BOOL inserted, BOOL * _Nullable rollback))filter
                  completed:(nullable void (^)(BOOL allInserted))completedBlock;

@end

NS_ASSUME_NONNULL_END
