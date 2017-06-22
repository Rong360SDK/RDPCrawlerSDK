//
//  NSArray+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/10/20.
//
//

#import <Foundation/Foundation.h>

@interface NSArray (RDPCrawler)

//加了安全保护，如果index大于总数会返回nil
- (id)rdpc_safeObjectAtIndex:(NSUInteger)index;

/**
 *  @param index 元素下标
 *  @return 返回安全的NSString类型
 */
- (NSString *)rdpc_strAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的int类型
 */
- (int)rdpc_intAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的BOOL类型
 */
- (BOOL)rdpc_boolAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的long类型
 */
- (long)rdpc_longAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的long long类型
 */
- (long long)rdpc_llongAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的double类型
 */
- (double)rdpc_doubleAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的float类型
 */
- (float)rdpc_floatAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的NSNumber类型
 */
- (NSNumber *)rdpc_numAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的NSArray类型
 */
- (NSArray *)rdpc_arrAt:(NSUInteger)index;
/**
 *  @param index 元素下标
 *  @return 返回安全的NSDictionary类型
 */
- (NSDictionary *)rdpc_dicAt:(NSUInteger)index;

/**
 *  @return 返回数组最后下标
 */
- (NSUInteger)rdpc_lastIndex;

@end



@interface NSMutableArray (RDPCrawler)

//安全add函数
- (void)rdpc_safeAddObject:(id)anObject;
//安全插入函数
-(bool)rdpc_safeInsertObject:(id)anObject atIndex:(NSUInteger)index;
//安全移除函数
-(bool)rdpc_safeRemoveObjectAtIndex:(NSUInteger)index;
//安全替换函数
-(bool)rdpc_safeReplaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;

@end
