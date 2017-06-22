//
//  MASConstraintBuilder.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "RDPCrawlerMASConstraint.h"
#import "RDPCrawlerMASUtilities.h"


typedef NS_OPTIONS(NSInteger, RDPCrawlerMASAttribute) {
    RDPCrawlerMASAttributeLeft = 1 << NSLayoutAttributeLeft,
    RDPCrawlerMASAttributeRight = 1 << NSLayoutAttributeRight,
    RDPCrawlerMASAttributeTop = 1 << NSLayoutAttributeTop,
    RDPCrawlerMASAttributeBottom = 1 << NSLayoutAttributeBottom,
    RDPCrawlerMASAttributeLeading = 1 << NSLayoutAttributeLeading,
    RDPCrawlerMASAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    RDPCrawlerMASAttributeWidth = 1 << NSLayoutAttributeWidth,
    RDPCrawlerMASAttributeHeight = 1 << NSLayoutAttributeHeight,
    RDPCrawlerMASAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    RDPCrawlerMASAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    RDPCrawlerMASAttributeBaseline = 1 << NSLayoutAttributeBaseline,
    
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)
    
    RDPCrawlerMASAttributeFirstBaseline = 1 << NSLayoutAttributeFirstBaseline,
    RDPCrawlerMASAttributeLastBaseline = 1 << NSLayoutAttributeLastBaseline,
    
#endif
    
#if TARGET_OS_IPHONE || TARGET_OS_TV
    
    RDPCrawlerMASAttributeLeftMargin = 1 << NSLayoutAttributeLeftMargin,
    RDPCrawlerMASAttributeRightMargin = 1 << NSLayoutAttributeRightMargin,
    RDPCrawlerMASAttributeTopMargin = 1 << NSLayoutAttributeTopMargin,
    RDPCrawlerMASAttributeBottomMargin = 1 << NSLayoutAttributeBottomMargin,
    RDPCrawlerMASAttributeLeadingMargin = 1 << NSLayoutAttributeLeadingMargin,
    RDPCrawlerMASAttributeTrailingMargin = 1 << NSLayoutAttributeTrailingMargin,
    RDPCrawlerMASAttributeCenterXWithinMargins = 1 << NSLayoutAttributeCenterXWithinMargins,
    RDPCrawlerMASAttributeCenterYWithinMargins = 1 << NSLayoutAttributeCenterYWithinMargins,

#endif
    
};

/**
 *  Provides factory methods for creating MASConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface RDPCrawlerMASConstraintMaker : NSObject

/**
 *	The following properties return a new MASViewConstraint
 *  with the first item set to the makers associated view and the appropriate MASViewAttribute
 */
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *left;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *top;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *right;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *bottom;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *leading;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *trailing;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *width;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *height;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *centerX;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *centerY;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *baseline;

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 9000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)

@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *firstBaseline;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *lastBaseline;

#endif

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *leftMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *rightMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *topMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *bottomMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *leadingMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *trailingMargin;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *centerXWithinMargins;
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *centerYWithinMargins;

#endif

/**
 *  Returns a block which creates a new MASCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  RDPCrawlerMASAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *(^attributes)(RDPCrawlerMASAttribute attrs);

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeEdges
 *  which generates the appropriate MASViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *edges;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeSize
 *  which generates the appropriate MASViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *size;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeCenter
 *  which generates the appropriate MASViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) RDPCrawlerMASConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any MASConstrait are created with this view as the first item
 *
 *	@return	a new MASConstraintMaker
 */
- (id)initWithView:(MAS_VIEW *)view;

/**
 *	Calls install method on any MASConstraints which have been created by this maker
 *
 *	@return	an array of all the installed MASConstraints
 */
- (NSArray *)install;

- (RDPCrawlerMASConstraint * (^)(dispatch_block_t))group;

@end
