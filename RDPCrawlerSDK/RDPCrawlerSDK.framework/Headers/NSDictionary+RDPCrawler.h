//
//  NSDictionary+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/10/20.
//
//

#import <Foundation/Foundation.h>

@interface NSDictionary (RDPCrawler)

//根据路径获取obj  例如：test/xxx/value   会从dict中找到key 为test的dict  在test的dict中找到key为xxx的dict 在xxx的dict中找到key为value的对象
- (id)rdpc_objectAtPath:(NSString *)path;
//根据路径获取obj 如果获取不到返回other
- (id)rdpc_objectAtPath:(NSString *)path otherwise:(NSObject *)other;
//有类型检查的获取bool类型
- (BOOL)rdpc_boolAtPath:(NSString *)path;
//有类型检查的获取bool类型 否则返回other
- (BOOL)rdpc_boolAtPath:(NSString *)path otherwise:(BOOL)other;

//有类型检查的获取number类型
- (NSNumber *)rdpc_numberAtPath:(NSString *)path;
//有类型检查的获取number类型 否则返回other
- (NSNumber *)rdpc_numberAtPath:(NSString *)path otherwise:(NSNumber *)other;

//有类型检查的获取string类型
- (NSString *)rdpc_stringAtPath:(NSString *)path;
//有类型检查的获取string类型 否则返回other
- (NSString *)rdpc_stringAtPath:(NSString *)path otherwise:(NSString *)other;

//有类型检查的获取NSArray类型 否则返回other
- (NSArray *)rdpc_arrayAtPath:(NSString *)path;
//有类型检查的获取NSArray类型 否则返回other
- (NSArray *)rdpc_arrayAtPath:(NSString *)path otherwise:(NSArray *)other;

//有类型检查的获取NSMutableArray类型 否则返回other
- (NSMutableArray *)rdpc_mutableArrayAtPath:(NSString *)path;
//有类型检查的获取NSMutableArray类型 否则返回other
- (NSMutableArray *)rdpc_mutableArrayAtPath:(NSString *)path otherwise:(NSMutableArray *)other;

//有类型检查的获取NSDictionary类型 否则返回other
- (NSDictionary *)rdpc_dictAtPath:(NSString *)path;
//有类型检查的获取NSDictionary类型 否则返回other
- (NSDictionary *)rdpc_dictAtPath:(NSString *)path otherwise:(NSDictionary *)other;

//有类型检查的获取NSMutableDictionary类型 否则返回other
- (NSMutableDictionary *)rdpc_mutableDictAtPath:(NSString *)path;
//有类型检查的获取NSMutableDictionary类型 否则返回other
- (NSMutableDictionary *)rdpc_mutableDictAtPath:(NSString *)path otherwise:(NSMutableDictionary *)other;

@end


@interface NSMutableDictionary (RDPCrawler)
// 安全添加键值对
- (void)rdpc_safeSetObject:(id)anObject forKey:(id<NSCopying>)aKey;

- (void)rdpc_safeSetObject:(id)object forKeyedSubscript:(id < NSCopying >)aKey;

- (void)rdpc_safeRemoveObjectForKey:(id)aKey;

@end
