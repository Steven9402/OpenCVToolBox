#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

    /**
     * 从图片序列拼接视频
     * 1.设置 图片序列路径
     * 2.设置 初始帧
     * 3.设置 设置保存路劲
     * 4.按esc退出录制视屏
     */
    string imgseqdir = "/home/cuizhou/projects/YinJiangNew/data/result/frames";
    int frameidx = 1;
    string outputpath="yingjiangdemo.avi";

    // 读取一张图片
    stringstream ii;
    ii<<frameidx;
    string image_dir = imgseqdir+"/"+ii.str()+".jpg";
    Mat frame = imread(image_dir);

    Size videoSize=Size(frame.cols,frame.rows);
    double rate = 25.0;//视频的帧率
    float pausetime=1000/25.0;
    VideoWriter writer(outputpath, CV_FOURCC('M', 'J', 'P', 'G'), rate, videoSize);
    if(!writer.isOpened())
    {
        cout<<"Failed to open writer!"<<endl;
        return -1;
    }


    while(true){
        stringstream iii;
        iii<<frameidx;
        string image_dir = imgseqdir+"/"+iii.str()+".jpg";
        frame = imread(image_dir);

        if(frame.empty()==true){
            break;
        }

        writer<<frame;
        imshow("view",frame);
        char c=waitKey(33);
        if(c==27)break;
        frameidx++;
    }

    writer.release();

    return 1;

}
