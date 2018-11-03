#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture capture(0);


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
//    width = 1920;
    height = 720;
//    height = 1080;
    capture.set(CV_CAP_PROP_FRAME_WIDTH,width);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,height);

    Size videoSize=Size(width,height);
    string outputpath="VideoTest.avi";
    double rate = 25.0;//视频的帧率
    float pausetime=1000/25.0;
    VideoWriter writer(outputpath, CV_FOURCC('M', 'J', 'P', 'G'), rate, videoSize);
    if(!writer.isOpened())
    {
        cout<<"Failed to open writer!"<<endl;
        return -1;
    }

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

        writer<<frame;
        imshow("result", frame);
        char c  = waitKey(20);
        if(c==27)break;
    }

    capture.release();
    writer.release();


}
