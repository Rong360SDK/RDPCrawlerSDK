//
//  RDPC_SectionCell.h
//  Pods
//
//  Created by whj on 16/11/24.
//
//

#import "RDPCrawlerBaseCell.h"

@interface RDPC_SectionData : NSObject

@property (nonatomic, strong) UIColor *color;
@property (nonatomic, assign) CGFloat height;

+ (RDPC_SectionData *)dataWith:(UIColor *)color height:(CGFloat)height;

@end

@interface RDPC_SectionCell : RDPCrawlerBaseCell

@end
