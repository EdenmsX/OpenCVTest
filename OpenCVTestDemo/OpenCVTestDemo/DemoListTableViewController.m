//
//  DemoListTableViewController.m
//  OpenCVTestDemo
//
//  Created by 刘李斌 on 2020/6/29.
//  Copyright © 2020 Brilliance. All rights reserved.
//

#import "DemoListTableViewController.h"

#import "ShowViewController.h"

@interface DemoListTableViewController ()

/** listArr */
@property(nonatomic, strong) NSArray *listArr;

@end

@implementation DemoListTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.listArr = @[@"图片叠加(水印)", @"图片腐蚀", @"图片模糊", @"边缘检测"];
}

#pragma mark - Table view data source
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return self.listArr.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString *indentify = @"mainCellIndentify";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:indentify];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:indentify];
    }
    
    cell.textLabel.text = self.listArr[indexPath.row];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    ShowViewController *showVC = [[ShowViewController alloc] init];
    showVC.handleNum = indexPath.row;
    [self.navigationController pushViewController:showVC animated:YES];

}



@end
