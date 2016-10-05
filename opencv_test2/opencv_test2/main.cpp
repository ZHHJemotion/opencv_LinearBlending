//
//  main.cpp
//  opencv_test2
//
//  Created by ZHHJemotion on 2016/10/5.
//  Copyright ı 2016Äê Lukas_Zhang. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

#define PATH string("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test2/opencv_test2/opencv_test2/")

using namespace cv;
using namespace std;

bool ROI_AddImage();


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
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
    
    //system("color 5E"); ?????????????????????
    
    ROI_AddImage();
    
    waitKey(0);
    return 0;
}

// ================================= ROI_AddImage() Function =============================
//   Describe: using ROI to realize the superimposition of images
// =======================================================================================
bool ROI_AddImage()
{
    
    // ¶ÁÈëÍ¼Ïñ
    String doat = PATH + "dota.jpg";
    Mat srcImage1 = imread(string(PATH+"dota.jpg"));
    Mat logoImage = imread(string(PATH+"dota_logo.jpg"));
    // Exception Handling Òì³£´¦Àí
    if(!srcImage1.data){printf("error: can't read the dota.jpg! \n"); return false;}
    if(!logoImage.data){printf("error: can't read the dota_logo.jpg! \n"); return false;}
    
    // ¶¨ÒåÒ»¸öMatÀàĞÍ²¢ÎªÆäÉè¶¨ROIÇøÓò
    Mat imageROI = srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));
    
    // ¼ÓÔØÑÚÄ££¨±ØĞëÊÇ»Ò¶ÈÍ¼ Grayscale£©
    Mat mask = imread("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test2/opencv_test2/opencv_test2/dota_logo.jpg",0);
    
    // ½«ÑÚÄ£¿½±´µ½ROIÖĞ
    logoImage.copyTo(imageROI,mask);
    
    // ÏÔÊ¾½á¹û
    namedWindow("ÀûÓÃROIÊµÏÖÍ¼Ïñµş¼ÓÊ¾Àı´°¿Ú");
    imshow("ÀûÓÃROIÊµÏÖÍ¼Ïñµş¼ÓÊ¾Àı´°¿Ú", srcImage1);
    
    return true;

}

// ============================== LinearBlending() Function ===============================
//   Describe: using cv::addWeighted() realize the linear blend of images
//          dst = src1[I]*alpha+ src2[I]*beta + gamma
// ========================================================================================
bool LinearBleding()
{
    
    // ¶¨ÒåÒ»Ğ©¾Ö²¿±äÁ¿
    double alphaValue = 0.5;
    double betaValue;
    Mat srcImage2, srcImage3, dstImage;
    
    // ¶ÁÈ¡Í¼Ïñ£¨Á½·ùÍ¼ĞëÎªÍ¬ÑùµÄÀàĞÍºÍ³ß´ç£©
    srcImage2 = imread(PATH+string("mogu.jpg"));
    srcImage3 = imread(PATH+string("rain.jpg"));
    
    // Exception handling
    if(!srcImage2.data) { printf("error: can't read the mogu.jpg! \n"); return false;}
    if(!srcImage3.data) { printf("error: can't read the rain.jpg! \n"); return false;}
    
    // ×öÍ¼Ïñ»ìºÏ¼ÓÈ¨²Ù×÷
    betaValue = 1.0 - alphaValue;
    addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);
    
    //
    
    return true;
}
















