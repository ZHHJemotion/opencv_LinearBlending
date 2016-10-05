//
//  main.cpp
//  opencv_test2
//
//  Created by ZHHJemotion on 2016/10/5.
//  Copyright � 2016�� Lukas_Zhang. All rights reserved.
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
    //    imshow("��ǰ��Ƶ", frame);
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
    
    // ����ͼ��
    String doat = PATH + "dota.jpg";
    Mat srcImage1 = imread(string(PATH+"dota.jpg"));
    Mat logoImage = imread(string(PATH+"dota_logo.jpg"));
    // Exception Handling �쳣����
    if(!srcImage1.data){printf("error: can't read the dota.jpg! \n"); return false;}
    if(!logoImage.data){printf("error: can't read the dota_logo.jpg! \n"); return false;}
    
    // ����һ��Mat���Ͳ�Ϊ���趨ROI����
    Mat imageROI = srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));
    
    // ������ģ�������ǻҶ�ͼ Grayscale��
    Mat mask = imread("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test2/opencv_test2/opencv_test2/dota_logo.jpg",0);
    
    // ����ģ������ROI��
    logoImage.copyTo(imageROI,mask);
    
    // ��ʾ���
    namedWindow("����ROIʵ��ͼ�����ʾ������");
    imshow("����ROIʵ��ͼ�����ʾ������", srcImage1);
    
    return true;

}

// ============================== LinearBlending() Function ===============================
//   Describe: using cv::addWeighted() realize the linear blend of images
//          dst = src1[I]*alpha+ src2[I]*beta + gamma
// ========================================================================================
bool LinearBleding()
{
    
    // ����һЩ�ֲ�����
    double alphaValue = 0.5;
    double betaValue;
    Mat srcImage2, srcImage3, dstImage;
    
    // ��ȡͼ������ͼ��Ϊͬ�������ͺͳߴ磩
    srcImage2 = imread(PATH+string("mogu.jpg"));
    srcImage3 = imread(PATH+string("rain.jpg"));
    
    // Exception handling
    if(!srcImage2.data) { printf("error: can't read the mogu.jpg! \n"); return false;}
    if(!srcImage3.data) { printf("error: can't read the rain.jpg! \n"); return false;}
    
    // ��ͼ���ϼ�Ȩ����
    betaValue = 1.0 - alphaValue;
    addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);
    
    //
    
    return true;
}
















