//
//  ViewController.m
//  RDPCrawler
//
//  Created by whj on 16/10/31.
//  Copyright © 2016年 rong360. All rights reserved.
//

#import "ViewController.h"
#import <RDPCrawlerSDK/RDPCrawlerManager.h>

@interface ViewController () <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) NSMutableArray *sourceArray;
@property (nonatomic, strong) UITableView *tblView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self.view setBackgroundColor:[UIColor whiteColor]];
    self.title = @"抓取demo";
    _tblView = [UITableView new];
    _tblView.dataSource = self;
    _tblView.delegate = self;
    [self.view addSubview:_tblView];
    [_tblView setTableFooterView:[UIView new]];
    _tblView.frame = self.view.bounds;
    _tblView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    [self configData];
}

- (void)configData {
    _sourceArray = [NSMutableArray arrayWithObjects:@(kRDPCrawlerTypeAlipay), @(kRDPCrawlerTypeTaobao), @(kRDPCrawlerTypeOperator), nil];
    [_tblView reloadData];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)authAlipay {
    [RDPCrawlerManager startCrawlerByType:kRDPCrawlerTypeAlipay identifier:@"1111" addtionalParams:nil];
}

#pragma mark -UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [_sourceArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSString *reuseIndentifier = @"cellIndentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:reuseIndentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIndentifier];
    }
    
    
    NSString *title = @"";
    NSNumber *number = [_sourceArray objectAtIndex:indexPath.row];
    switch (number.integerValue) {
            case kRDPCrawlerTypeAlipay:
            title = @"支付宝抓取";
            break;
            case kRDPCrawlerTypeTaobao:
            title = @"淘宝抓取";
            break;
            case kRDPCrawlerTypeOperator:
            title = @"运营商抓取";
            break;
        default:
            break;
    }
    
    [cell.textLabel setText:title];
    return cell;
}

#pragma mark -UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    NSNumber *number = [_sourceArray objectAtIndex:indexPath.row];
    NSString *taskId = [NSString stringWithFormat:@"%ld", indexPath.row];
    switch (number.integerValue) {
        case kRDPCrawlerTypeAlipay:
        case kRDPCrawlerTypeTaobao:
        {
            [RDPCrawlerManager startCrawlerByType:number.integerValue identifier:taskId addtionalParams:nil];
            break;
        }
        case kRDPCrawlerTypeOperator:
        {
            RDPC_OperatorConfig *config = [RDPC_OperatorConfig new];
            config.phone = @"13738061365";
            config.canEditPhone = YES;
            [RDPCrawlerManager startCrawlerOperatorByConfig:config identifier:taskId addtionalParams:nil];
            break;
        }
        default:
            break;
    }
   
}

@end
