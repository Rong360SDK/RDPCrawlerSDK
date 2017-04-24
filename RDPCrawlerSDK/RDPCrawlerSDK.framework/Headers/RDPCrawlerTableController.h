//
//  RDPCrawlerTableController.h
//  Pods
//
//  Created by whj on 16/11/24.
//
//

#import "RDPCrawlerViewController.h"
#import "UIView+RDPCrawler.h"
#import "RDPC_TableView.h"
#import "RDPCMacro.h"
#import "RDPC_SectionCell.h"
#import "UITableView+RDPCrawler.h"

@interface RDPCrawlerTableController : RDPCrawlerViewController <UITableViewDelegate, UITableViewDataSource> {
    RDPC_TableView *_tblView;
    NSMutableArray *_sourcesArray;
}

@property (nonatomic, strong) RDPC_TableView *tblView;
@property (nonatomic, strong) NSMutableArray *sourcesArray;

- (void)configUI;

@end
