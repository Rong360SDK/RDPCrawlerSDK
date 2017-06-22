//
//  UITableView+RDPCrawler.h
//  Pods
//
//  Created by whj on 16/11/24.
//
//

#import <UIKit/UIKit.h>

@interface UITableView (RDPCrawler)

/**
 *  @param cellClass cell的类别
 *
 *  @return  获取重用的cell
 */
- (id)rdpc_reuseCellWithClass:(Class)cellClass;

@end
