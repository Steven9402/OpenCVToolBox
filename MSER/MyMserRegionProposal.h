//
// Created by cuizhou on 18-2-23.
//

#ifndef MYF_MYMSERREGIONPROPOSAL_H
#define MYF_MYMSERREGIONPROPOSAL_H

#include <vector>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
namespace myf{

    class MyMserRegionProposal {

    public:
        MyMserRegionProposal(int);

        void mserExtractor (Mat& image, Mat& mserOutMask);
    };
}


#endif //MYF_MYMSERREGIONPROPOSAL_H
