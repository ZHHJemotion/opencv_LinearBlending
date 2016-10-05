//
//  main.cpp
//  opencv_test2
//
//  Created by 张行剑 on 2016/10/5.
//  Copyright © 2016年 Lukas_Zhang. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    VideoCapture cap(0);
    if(!cap.isOpened()){
        return -1;
    }
    Mat frame;
    
    while(true){
        cap>>frame;
        imshow("当前视频", frame);
        if(waitKey(30) >= 0) break;
    }
    
    return 0;
}
