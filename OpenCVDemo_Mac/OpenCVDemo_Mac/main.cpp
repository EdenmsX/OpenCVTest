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
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main( int argc, char** argv ){
    string imageName("/Users/liulibin/Desktop/12.png"); // by default
    if( argc > 1) {
        imageName = argv[1];
    }
    Mat image;
    image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file
    if( image.empty() ){
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    
    return 0;
}
