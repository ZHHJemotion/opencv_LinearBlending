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
bool LinearBlending();
bool ROI_LinearBlending();

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
    LinearBlending();
    ROI_LinearBlending();

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
    
    // ½«ÑÚÄ£¿½±´µ½ROI
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
bool LinearBlending()
{
    
    // ¶¨ÒåÒ»Ğ©¾Ö²¿±äÁ¿
    double alphaValue = 0.5;
    double betaValue;
    Mat srcImage2, srcImage3, dstImage;
    
    // ¶ÁÈ¡Í¼Ïñ£¨Á½·ùÍ¼ĞëÎªÍ¬ÑùµÄÀàĞÍºÍ³ß´ç£©
    srcImage2 = imread(PATH+string("mogu.jpg"));
    srcImage3 = imread(PATH+string("rain.jpg"));
    // Exception Handling
    if(!srcImage2.data) { printf("error: can't read the mogu.jpg! \n"); return false;}
    if(!srcImage3.data) { printf("error: can't read the rain.jpg! \n"); return false;}
    
    // ×öÍ¼Ïñ»ìºÏ¼ÓÈ¨²Ù×÷
    betaValue = 1.0 - alphaValue;
    addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);
    
    // ´´½¨²¢ÏÔÊ¾Ô­Í¼´°¿Ú
    namedWindow("ÏßĞÔ»ìºÏÊ¾Àı´°¿Ú_Ô­Í¼",1);
    imshow("ÏßĞÔ»ìºÏÊ¾Àı´°¿Ú_Ô­Í¼",srcImage2);
    
    namedWindow("ÏßĞÔ»ìºÏÊ¾Àı´°¿Ú_Ğ§¹ûÍ¼",1);
    imshow("ÏßĞÔ»ìºÏÊ¾Àı´°¿Ú_Ğ§¹ûÍ¼", dstImage);
    
    return true;
}

// ================================ ROI_LinearBlending() Function ===========================
//  Describe: Linear blend makes the linear blend of image come true. Using cv::addWeighted()
//   with ROI(region of interest) to realize the linear blend in the custom region
// ==========================================================================================
bool ROI_LinearBlending()
{
    // ¶ÁÈ¡Í¼Ïñ
    Mat srcImage4 = imread(PATH+string("dota_pa.jpg"),1);
    Mat logoImage = imread(PATH+string("dota_logo.jpg"));
    // Exception handling
    if(!srcImage4.data) { printf("error: can't read the dota_pa.jpg! \n"); return false;}
    if(!logoImage.data) { printf("error: can't read the dota_logo.jpg! \n"); return false;}
   
    // ¶¨ÒåÒ»¸öMatÀàĞÍ²¢ÎªÆäÉè¶¨ROIÇøÓò
    Mat imageROI;
    imageROI = srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));
    // another Methode
    //imageROI = srcImage4(Range(250, 250+logoImage.cols),Range(200, 200+logoImage.rows));
    
    // ½«logo¼Óµ½Ô­Í¼ÉÏ
    addWeighted(imageROI, 0.5, logoImage, 0.3, 0., imageROI);
    
    // ÏÔÊ¾½á¹û
    namedWindow("ÇøÓòÏßĞÔÍ¼Ïñ»ìºÏÊ¾Àı´°¿Ú");
    imshow("ÇøÓòÏßĞÔÍ¼Ïñ»ìºÏÊ¾Àı´°¿Ú",srcImage4);
    
    return true;
}












