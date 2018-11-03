//
// Created by cuizhou on 18-2-23.
//
#include <stdio.h>
#include <sstream>
#include <glog/logging.h>
#include "MyMserRegionProposal.h"
#include "MyMatOperation.h"
#include "time.h"

namespace myf{
    const double MAX_HEIGHT_RATIO=0.2;
    const double MAX_WIDTH_RATIO=0.2;
    const int MIN_PIXEL=10;

    const double ASPECT_RATIO=1.0;

    MyMserRegionProposal::MyMserRegionProposal(int i){
        google::InitGoogleLogging("mytest"); //初始化 glog
        google::InstallFailureSignalHandler();
    }


    void MyMserRegionProposal::mserExtractor (Mat& image, Mat& mserOutMask) {

        clock_t start, finish;

        double duration;
        start = clock();

        // mser detection
        Ptr<MSER> mserExtractor = MSER::create();

        vector<vector<cv::Point> > mserContours;
        vector<cv::Rect> mserBbox;
        mserExtractor->detectRegions(image, mserContours, mserBbox);

        for (vector<cv::Point> v : mserContours){
            for (cv::Point p : v){
                mserOutMask.at<uchar>(p.y, p.x) = 255;
            }
        }


        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout<<"MSER duration: "<<duration<<endl;

        // visualize detection

        vector<Mat> matpool;
        for(int i=0;i<mserContours.size();i++){
            vector<Point> v=mserContours[i];
            Rect bbox = mserBbox[i];

            Mat candi_mat=Mat::zeros(bbox.size(),CV_8UC1);

            for (cv::Point p : v){
                candi_mat.at<uchar>(p.y-bbox.y, p.x-bbox.x) = 255;
            }
            matpool.push_back(candi_mat);
        }


        Mat vismat=composeGrayVisMat(matpool);
        imshow("vismat",vismat);

    }

}

