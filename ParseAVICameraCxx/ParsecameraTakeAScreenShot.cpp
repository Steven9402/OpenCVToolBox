#include <opencv2/opencv.hpp>
#include <sstream>

//#define LIVECAMERA

using namespace std;
using namespace cv;

int main()
{
    string outputimgpath="";

#ifdef LIVECAMERA
    VideoCapture capture(0);
#else
    VideoCapture capture("/home/cuizhou/projects/IntelligentCabinet/IntelligentCabinet_topview_python/test2.avi");
#endif

    if(!capture.isOpened())
    {
        cout<<"Failed to open camera!"<<endl;
        return -1;
    }

    double width=capture.get(CV_CAP_PROP_FRAME_WIDTH);
    double height=capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    //不可以简单的放大,opencv 可以处理的大小是固定的;
    // 笔记本摄像头可以设置为 1280 720
    width = 1280;
    height = 720;
//    width = 1920;
//    height = 1080;

    capture.set(CV_CAP_PROP_FRAME_WIDTH,width);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,height);

    int frame_idx = 0;

    Mat frame;
    while(capture.isOpened())
    {
        //读取下一帧
        if(!capture.read(frame))
        {
            cout<<"读取视频失败"<<endl;
            return -1;
        }

        if(frame.empty())
            continue;

        cv::imshow("result", frame);
        char c  = waitKey(10);
        if(c==12||c==10||c==32){
            stringstream oo;
            oo<<frame_idx<<".jpg";
            cv::imwrite(outputimgpath+oo.str(),frame);
        }

        frame_idx++;
    }

    capture.release();
}
