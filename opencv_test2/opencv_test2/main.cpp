//
//  main.cpp
//  opencv_test2
//
//  Created by ZHHJemotion on 2016/10/5.
//  Copyright ý 2016Äê Lukas_Zhang. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

bool ROI_AddImage();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //VideoCapture cap(0);
    //if(!cap.isOpened()){
    //    return -1;
    //}
    //Mat frame;
    
    //while(true){
    //    cap>>frame;
    //    imshow("µ±Ç°ÊÓÆµ", frame);
    //    if(waitKey(30) >= 0) break;
    //}
    
    
    
    
    return 0;
}

// ================================= ROI_AddImage() Function =============================
//   Describe: use ROI to realize the superimposition of images
// =======================================================================================
bool ROI_AddIamge()
{
    
    // 1st: read the image
    Mat scrImage1 = imread("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test2/opencv_test2/opencv_test2/dota.jpg");
    Mat logoImage = imread("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test2/opencv_test2/opencv_test2/dota_logo.jpg");
    // Exception Handling
    if(!scrImage1.data){printf("error: can't read the dota.jpg! \n"); return false;}
    if(!logoImage.data){printf("error: can't read the dota_logo.jpg! \n"); return false;}
    
    
    return true;

}



















