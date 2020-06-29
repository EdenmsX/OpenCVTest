//
//  OpenCVImageUtils.m
//  OpenCVTestDemo
//
//  Created by 刘李斌 on 2020/6/29.
//  Copyright © 2020 Brilliance. All rights reserved.
//

#import "OpenCVImageUtils.h"

@implementation OpenCVImageUtils

/// 图片叠加(加水印)
/// @param srcImage 原始图片
/// @param dstImage 叠加图片(水印图片)
+ (UIImage *)opencvImage:(UIImage *)srcImage dst:(UIImage *)dstImage {
    //第一步：准备两种图片
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);
    Mat mat_image_dst;
    UIImageToMat(dstImage, mat_image_dst);
    
    //第二步：创建叠加区域->开辟了一块内存空间
    Mat mat_roi = mat_image_src(Rect2i(0, 0, mat_image_dst.cols, mat_image_dst.rows));
    
    //第三步：图片叠加->加水印->合并之后覆盖原来的图片
    //参数一：第一个图片数组
    //参数二：第一个图片数组->权重
    //参数三：第二个图片数组
    //参数四：第二个图片数组->权重
    //参数五：权重和基础之上标量值
    //参数六：输出数组->输出目标
    //dst = src1*alpha + src2*beta + gamma;
    //伪代码：mat_roi * 0 + mat_image_dst * 1 + 0
    addWeighted(mat_roi, 0, mat_image_dst, 1, 0, mat_roi);
    
    //第四步：将Mat图片->iOS图片
    return MatToUIImage(mat_image_src);
}

/// 图片腐蚀处理
/// @param srcImage 原始图片
+ (UIImage *)opencvImageErode:(UIImage *)srcImage {
    //第一步：准备图片
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);
    
    //第二步: 进行腐蚀操作
    //参数1: 腐蚀类型(矩形方式)
    //参数2: 腐蚀程度(腐蚀单位越大, 腐蚀程度越明显)
    Mat mat_element = getStructuringElement(MORPH_RECT, Size2i(5, 5));
    
    //第三步: 开始腐蚀
    Mat mat_image_dst;
    //参数1: 原始图片
    //参数2: 腐蚀之后的图片
    //参数3: 腐蚀操作
    erode(mat_image_src, mat_image_dst, mat_element);
    
    //第四步: 将Mat图片转为iOS图片
    return MatToUIImage(mat_image_dst);
}

/// 图片模糊处理
/// @param srcImage 原始图片
+ (UIImage *)opencvImageBlur:(UIImage *)srcImage {
    //准备图片
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);
    
    Mat mat_image_dst;
    blur(mat_image_src, mat_image_dst, Size2i(15, 15));
    
    //将Mat图片转为iOS图片
    return MatToUIImage(mat_image_dst);
}


/// 图片边缘检测
/// @param srcImage 原始图片
+ (UIImage *)opencvImageEdge:(UIImage *)srcImage {
    //加载图片
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);
    
    //创建和mat_image_src同样大小的OpenCV图片(Mat)
    Mat mat_image_dst;
    mat_image_dst.create(mat_image_src.size(), mat_image_src.type());
    
    //将图片进行灰度处理(图片变为灰色)
    Mat mat_image_gray;
    cvtColor(mat_image_src, mat_image_gray, COLOR_BGR2GRAY);
    
    //使用3*3内核来降噪处理
    Mat mat_image_edge;
    blur(mat_image_gray, mat_image_edge, Size2i(3, 3));
    
    //进行Canny算子处理
    Canny(mat_image_edge, mat_image_edge, 3, 9, 3);
    
    //将OpenCV图片->转成iOS图片
    return MatToUIImage(mat_image_edge);
}
@end
