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
    drawCircle(image, Point2i(WINDOWS_WIDTH/2, WINDOWS_WIDTH/2), WINDOWS_WIDTH/4);
    
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );
    waitKey(0);
    
    return 0;
}




