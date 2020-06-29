//
//  OpenCVImageUtils.h
//  OpenCVTestDemo
//
//  Created by 刘李斌 on 2020/6/29.
//  Copyright © 2020 Brilliance. All rights reserved.
//

#import <UIKit/UIKit.h>


//#import <opencv2/core/core.hpp>
//#import <opencv2/imgcodecs.hpp>
//#import <opencv2/imgcodecs/ios.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//支持iOS平台图片转换
#include <opencv2/imgcodecs/ios.h>
using namespace cv;





@interface OpenCVImageUtils : NSObject

/// 图片叠加(加水印)
/// @param srcImage 原始图片
/// @param dstImage 叠加图片(水印图片)
+ (UIImage *)opencvImage:(UIImage *)srcImage dst:(UIImage *)dstImage;


/// 图片腐蚀处理
/// @param srcImage 原始图片
+ (UIImage *)opencvImageErode:(UIImage *)srcImage;


/// 图片模糊处理
/// @param srcImage 原始图片
+ (UIImage *)opencvImageBlur:(UIImage *)srcImage;

/// 图片边缘检测
/// @param srcImage 原始图片
+ (UIImage *)opencvImageEdge:(UIImage *)srcImage;
@end


