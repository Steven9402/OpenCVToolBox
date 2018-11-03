#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include "MyMserRegionProposal.h"
#include "fileOperator.h"
using namespace myf;
int main(int argc,char** argv){

    vector<string> filenames =  readFileList("../images");
    MyMserRegionProposal myMserRegionProposal(0);

    for (auto filename:filenames){
        Mat srcImage = imread("../images/"+filename);
        //resize(srcImage,srcImage,Size(0,0),0.5,0.5,INTER_LINEAR);
        Mat srcImageGray;
        cvtColor(srcImage,srcImageGray,CV_BGR2GRAY);

        Mat maskimage(srcImageGray.rows,srcImageGray.cols,CV_8UC1);
        myMserRegionProposal.mserExtractor(srcImageGray,maskimage);


        imshow("srcImageGray",maskimage);
        waitKey(0);
    }

    return 1;
}