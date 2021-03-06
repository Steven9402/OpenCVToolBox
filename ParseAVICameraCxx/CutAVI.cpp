#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream>
using namespace std;
using namespace cv;

int main(int argc,char* argv[])
{
    if (argc!=5)
    {
        cout<<"Usage:"<< endl
            <<"   ./cutavi "<<endl
            << "  path to video"<<endl
            <<"   path to save video"<<endl
            <<"   start frame"<<endl
            <<"   end frame"<<endl;
        return -1;
    }
    VideoCapture capture(argv[1]);
    if(!capture.isOpened())
        cout<<"fail to open!"<<endl;


    double width=capture.get(CV_CAP_PROP_FRAME_WIDTH);
    double height=capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    Size videoSize=Size(width,height);
    //获取帧率
    double rate = capture.get(CV_CAP_PROP_FPS);
    cout<<"帧率为:"<<rate<<endl;
    VideoWriter writer(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), rate, videoSize);
    if(!writer.isOpened())
    {
        cout<<"Failed to open writer!"<<endl;
        return -1;
    }

    //获取整个帧数
    long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
    cout<<"整个视频共"<<totalFrameNumber<<"帧"<<endl;

    //设置开始帧()
    long frameToStart = atoi(argv[3]);
    capture.set( CV_CAP_PROP_POS_FRAMES,frameToStart);
    cout<<"从第"<<frameToStart<<"帧开始读"<<endl;

    //设置结束帧
    int frameToStop = atoi(argv[4]);

    if(frameToStop < frameToStart) {
        cout<<"结束帧小于开始帧，程序错误，即将退出！"<<endl;
        return -1;
    } else {
        cout<<"结束帧为：第"<<frameToStop<<"帧"<<endl;
    }


    //承载每一帧的图像
    Mat frame;
    //显示每一帧的窗口
    namedWindow("Extracted frame");
    //两帧间的间隔时间:
    int delay = 1000/rate;

    //利用while循环读取帧
    //currentFrame是在循环体中控制读取到指定的帧后循环结束的变量
    long currentFrame = frameToStart;


    //滤波器的核
    int kernel_size = 3;
    Mat kernel = Mat::ones(kernel_size,kernel_size,CV_32F)/(float)(kernel_size*kernel_size);

    while(capture.isOpened())
    {
        //读取下一帧
        if(!capture.read(frame))
        {
            cout<<"读取视频失败"<<endl;
            return -1;
        }

        //Size size(1280,720);
        //resize(frame,frame,size);
//        cv::Mat rotateMat;
//        cv::Point center(frame.cols/2,frame.rows/2);
//        rotateMat = cv::getRotationMatrix2D(center,180,1);
//        cv::warpAffine(frame,frame,rotateMat,frame.size());

        writer<<frame;
        cout<<"正在读取第"<<currentFrame<<"帧"<<endl;
        //waitKey(int delay=0)当delay ≤ 0时会永远等待；当delay>0时会等待delay毫秒
        //当时间结束前没有按键按下时，返回值为-1；否则返回按键

        if(currentFrame > frameToStop)break;
//        imshow("after filter",frame);
//        int c = waitKey(delay);
//        //按下ESC或者到达指定的结束帧后退出读取视频
//        if((char) c == 27 || currentFrame > frameToStop)
//        {
//            stop = true;
//        }
//        //按下按键后会停留在当前帧，等待下一次按键
//        if( c >= 0)
//        {
//            waitKey(0);
//        }
        currentFrame++;

    }
    //关闭视频文件
    capture.release();
    writer.release();
    return 0;
}

