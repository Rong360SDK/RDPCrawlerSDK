//
//  R360BaseItem.h
//  Pods
//
//  Created by LiuDequan on 15/5/13.
//
//

#import <Foundation/Foundation.h>

@interface RDPCrawlerBaseItem : NSObject<NSCoding>

/**
 *    初始化
 *
 *    @param data 要解析的数据
 *
 *    @return
 */
- (id)initWithData:(id)data;

/**
 *    设置数据
 *
 *    @param data 要解析的数据
 *
 *    @return
 */
- (id)setPaserData:(id)data;


/**
 *    所有需要映射的property都需要设定此规则
 */
+ (NSDictionary *)jsonRulePropertyMap;


/* Property-JSON映射规则，须在子类Init函数中设定 */

/**
 *    property中如有包含RDPBaseListItem对象的数组，需要设定此规则
 *
 */
+ (NSDictionary *)jsonRuleArrayRuleMap;

/**
 *    所有需要映射的property都需要设定此规则
 */
+ (NSDictionary *)jsonRulePropertyMapOption;


/**
 *    获得数据的
 *
 *    @param aKey 对应的Path
 *
 *    @return 返回数据路径
 */
- (NSString *)getPahtForDataMapWithKey:(NSString *)aKey;

/**
 *    获取key
 *
 *    @param aKey 类名
 *
 *    @return 
 */
- (NSString *)mappingRuleWithKey:(NSString *)aKey;

/**
 *    转化为字典
 *
 *    @return
 */
- (NSDictionary *)toDictionary;

/**
 *    转化为字段
 *
 *    @return
 */
- (NSString *)toJson;

@end
