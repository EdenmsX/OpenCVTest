//
//  ShowViewController.m
//  OpenCVTestDemo
//
//  Created by 刘李斌 on 2020/6/29.
//  Copyright © 2020 Brilliance. All rights reserved.
//

#import "ShowViewController.h"
#import "OpenCVImageUtils.h"

#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenheight [UIScreen mainScreen].bounds.size.height
@interface ShowViewController ()
/** imgView */
@property(nonatomic, strong) UIImageView *imgView;
@end

@implementation ShowViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self setupUI];
}

- (void)setupUI {
    self.view.backgroundColor = [UIColor whiteColor];
    self.imgView = [[UIImageView alloc] initWithFrame:CGRectMake(50, 100, kScreenWidth - 100, 400)];
    [self.view addSubview:self.imgView];
    self.imgView.image = [UIImage imageNamed:@"caomei"];
    
    UIButton *normalBtn = [[UIButton alloc] initWithFrame:CGRectMake(50, 550, 80, 50)];
    [normalBtn setTitle:@"普通图片" forState:UIControlStateNormal];
    [normalBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [self.view addSubview:normalBtn];
    [normalBtn addTarget:self action:@selector(normalBtnClick) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *newBtn = [[UIButton alloc] initWithFrame:CGRectMake(kScreenWidth - 50 - 80, 550, 80, 50)];
    [newBtn setTitle:@"处理图片" forState:UIControlStateNormal];
    [newBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [self.view addSubview:newBtn];
    [newBtn addTarget:self action:@selector(newBtnClick) forControlEvents:UIControlEventTouchUpInside];
}

- (void)normalBtnClick {
    self.imgView.image = [UIImage imageNamed:@"caomei"];
}

- (void)newBtnClick {
    switch (self.handleNum) {
        case 0: {
            UIImage *newImg = [OpenCVImageUtils opencvImage:[UIImage imageNamed:@"caomei.png"] dst:[UIImage imageNamed:@"chifan.jpeg"]];
            self.imgView.image = newImg;
            break;
        }
        case 1: {
            UIImage *newImg = [OpenCVImageUtils opencvImageErode:[UIImage imageNamed:@"caomei.png"]];
            self.imgView.image = newImg;
            break;
        }
        case 2: {
            UIImage *newImg = [OpenCVImageUtils opencvImageBlur:[UIImage imageNamed:@"caomei.png"]];
            self.imgView.image = newImg;
            break;
        }
        case 3: {
            UIImage *newImg = [OpenCVImageUtils opencvImageEdge:[UIImage imageNamed:@"caomei.png"]];
            self.imgView.image = newImg;
            break;
        }
        default:
            break;
    }
}
@end
