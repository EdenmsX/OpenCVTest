//
//  main.cpp
//  OpenCVDemo_Mac
//
//  Created by 刘李斌 on 2020/6/30.
//  Copyright © 2020 Brilliance. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <opencv2/core/core.hpp>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

#define WINDOWS_WIDTH 240

//绘制椭圆
void drawEllipse(Mat &mat_image, double angle){
    //参数一：图片（画板）
    //参数二：中心点
    //参数三：轴大小（主轴大小）->半径
    //参数四：旋转角度
    //参数五：起始角度
    //参数六：结束角度
    //参数七：椭圆颜色
    //参数八：类型（如果小于表示实心圆、如果大于等于0表示空心圆, 大于0, 表示椭圆外围线大小）
    ellipse(mat_image,
            Point2i(WINDOWS_WIDTH/2, WINDOWS_WIDTH/2),
            Size2i(WINDOWS_WIDTH/4, WINDOWS_WIDTH/16),
            angle,
            0,
            360,
            Scalar(0, 0, 255),
            2);
}

//绘制圆
void drawCircle(Mat &mat_image, Point2i center, double radius){
    //参数一：图片（画板）
    //参数二：中心点
    //参数三：半径
    //参数四：圆的颜色
    //参数五：类型（如果小于表示实心圆、如果大于等于0表示空心圆, 大于0, 表示圆外围线大小）
    circle(mat_image, center, radius, Scalar(0, 0, 255), 5);
}


/// 指针访问
/// @param mat_image_in  输入图片
/// @param mat_image_out  输出图片
/// @param div 缩减级别
void colorSpaceReduce1(Mat &mat_image_in, Mat &mat_image_out, int div) {
    //拷贝图片
    mat_image_out = mat_image_in.clone();
    int rows = mat_image_out.rows;
    int cols = mat_image_out.cols;
    
    //通道数量(每一个像素点有多少个颜色)
    int channels = mat_image_out.channels();
    //每一行的元素个数
    int colsSize = cols * channels;
    
    //循环缩减颜色通道
    for (int i = 0; i< rows; i++) {
        //获取第i行(通过指针访问像素点)
        uchar *data = mat_image_out.ptr<uchar>(i);
        for (int j = 0 ; j< colsSize; j++) {
            //指针位移
            //data[j]表示一个颜色值(可能是R, G ,B中的任何一个)
            /**
             缩减公式根据实际需求自定义
             eg. data[j] = 100   div = 24
             data[j] = 100 / 24 * 24 = 96    (100 / 24 =  4)
             */
            data[j] = data[j] / div * div;
        }
        
    }
}

/// 迭代器访问
/// @param mat_image_in  输入图片
/// @param mat_image_out  输出图片
/// @param div 缩减级别
void colorSpaceReduce2(Mat &mat_image_in, Mat &mat_image_out, int div) {
    mat_image_out = mat_image_in.clone();
    //迭代器
    Mat_<Vec3b>::iterator it_start = mat_image_out.begin<Vec3b>();
    Mat_<Vec3b>::iterator it_end = mat_image_out.end<Vec3b>();
    
    //循环缩减颜色通道
    for (; it_start != it_end; it_start++) {
        //(*it_start): 表示获取像素点
        //(*it_start)[0]: 表示获取像素点值
        (*it_start)[0] = (*it_start)[0] / div * div; //B
        (*it_start)[1] = (*it_start)[1] / div * div; //G
        (*it_start)[2] = (*it_start)[2] / div * div; //R
    }
}


/// 动态地址计算
/// @param mat_image_in  输入图片
/// @param mat_image_out  输出图片
/// @param div 缩减级别
void colorSpaceReduce3(Mat &mat_image_in, Mat &mat_image_out, int div) {
    mat_image_out = mat_image_in.clone();
    int rows = mat_image_out.rows;
    int cols = mat_image_out.cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat_image_out.at<Vec3b>(i, j)[0] = mat_image_out.at<Vec3b>(i, j)[0] / div * div;
            mat_image_out.at<Vec3b>(i, j)[1] = mat_image_out.at<Vec3b>(i, j)[1] / div * div;
            mat_image_out.at<Vec3b>(i, j)[2] = mat_image_out.at<Vec3b>(i, j)[2] / div * div;
        }
    }
}



void roiDemo(){
    //第一步：创建一张图片,空白图片
    Mat mat_image_src = imread("/Users/liulibin/Desktop/image1.png");
    Mat mat_image_logo = imread("/Users/liulibin/Desktop/image2.jpeg");
    
    //第二步：灰度处理,加载一张灰度图片
    Mat mat_image_mask = imread("/Users/liulibin/Desktop/image2.jpeg");
    
    //第三步：定义ROI区域
    //根据原始图片,得到src图片一块内存地址(指针)
    Mat mat_image_roi = mat_image_src(Rect2i(0, 0, mat_image_logo.cols, mat_image_logo.rows));
    
    //第三步：拷贝到ROI区域
    //参数一：ROI区域
    //参数二：需要填充图片(水印)
    mat_image_logo.copyTo(mat_image_roi, mat_image_mask);
}



int main( int argc, char** argv ){
//    string imageName("/Users/liulibin/Desktop/12.png");
//    if( argc > 1) {
//        imageName = argv[1];
//    }
//    Mat image;
//    image = imread(imageName.c_str(), IMREAD_COLOR);
//    if( image.empty() ){
//        cout <<  "Could not open or find the image" << std::endl ;
//        return -1;
//    }
    //创建图片
    Mat image(WINDOWS_WIDTH, WINDOWS_WIDTH, CV_8UC3, Scalar(255, 255, 255));
    
    //绘制椭圆
//    drawEllipse(image, 0);
    //绘制圆
//    drawCircle(image, Point2i(WINDOWS_WIDTH/2, WINDOWS_WIDTH/2), WINDOWS_WIDTH/4);
    
    Mat mat_image_src = imread("/Users/liulibin/Desktop/12.png");
    //访问图像像素
    //1. 指针访问
    Mat mat_image_dst;
    mat_image_dst.create(mat_image_src.rows, mat_image_src.cols, mat_image_src.type());
    
    colorSpaceReduce3(mat_image_src, mat_image_dst, 24);
    
    namedWindow( "Display window" );
    imshow( "Display window", mat_image_dst );
    waitKey(0);
    
    return 0;
}




