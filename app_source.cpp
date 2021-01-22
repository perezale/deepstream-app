#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

int main(void)
{
    cv::VideoCapture cap("uridecodebin uri=rtsp://184.72.239.149/vod/mp4:BigBuckBunny_115k.mov ! videoconvert ! videoscale ! appsink");

    if( !cap.isOpened() )
    {
        std::cout << "Not good, open camera failed" << std::endl;
        return 0;
    }

    cv::Mat frame;
    while(true)
    {
        cap >> frame;
        cv::imshow("Frame", frame);
        cv::waitKey(1);
    }
    return 0;
}
