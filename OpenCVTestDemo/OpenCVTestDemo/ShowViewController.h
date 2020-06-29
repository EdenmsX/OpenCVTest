//
//  ShowViewController.h
//  OpenCVTestDemo
//
//  Created by 刘李斌 on 2020/6/29.
//  Copyright © 2020 Brilliance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ShowViewController : UIViewController
/** 操作
 0 - 图像叠加
 1 - 图片腐蚀
 2 - 图片模糊
 3 - 边缘检查
 */
@property(nonatomic, assign) NSInteger handleNum;
@end

NS_ASSUME_NONNULL_END
