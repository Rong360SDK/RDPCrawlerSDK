//
//  UIView+RDPCrawlerMASAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "RDPCrawlerMASUtilities.h"
#import "RDPCrawlerMASConstraintMaker.h"
#import "RDPCrawlerMASViewAttribute.h"


/**
 *	Provides constraint maker block
 *  and convience methods for creating MASViewAttribute which are view + NSLayoutAttribute pairs
 */
@interface MAS_VIEW (RDPCrawlerMASAdditions)

/**
 *	following properties return a new MASViewAttribute with current view and appropriate NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_left;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_top;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_right;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_bottom;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_leading;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_trailing;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_width;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_height;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_centerX;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_centerY;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_baseline;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *(^RDPCmas_attribute)(NSLayoutAttribute attr);

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_firstBaseline;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_lastBaseline;

#endif

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_leftMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_rightMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_topMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_bottomMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_leadingMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_trailingMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_centerXWithinMargins;
@property (nonatomic, strong, readonly) RDPCrawlerMASViewAttribute *RDPCmas_centerYWithinMargins;

#endif

/**
 *	a key to associate with this view
 */
@property (nonatomic, strong) id rdpc_mas_key;

/**
 *	Finds the closest common superview between this view and another view
 *
 *	@param	view	other view
 *
 *	@return	returns nil if common superview could not be found
 */
- (instancetype)rdpc_mas_closestCommonSuperview:(MAS_VIEW *)view;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created MASConstraints
 */
- (NSArray *)rdpc_mas_makeConstraints:(void(^)(RDPCrawlerMASConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)rdpc_mas_updateConstraints:(void(^)(RDPCrawlerMASConstraintMaker *make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)rdpc_mas_remakeConstraints:(void(^)(RDPCrawlerMASConstraintMaker *make))block;

@end
