#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <exception>
#include <unistd.h>
#include "Face.h"
using namespace std;
using namespace cv;

void detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale );

string cascadeName;
Face f;
int main( int argc, const char** argv )
{
    VideoCapture capture;
    Mat frame;
    CascadeClassifier cascade;
    double scale;

    cascadeName       = "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";
    scale = 1;

    if( !cascade.load( cascadeName ) )
    {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        return -1;
    }

    try {
        if(!capture.open(0))
            cout << "Capture from camera #0 didn't work" << endl;
    }
    catch(std::exception& e)
    {
        std::cout << " Excecao capturada open: " << e.what() << std::endl;
    }

    if( capture.isOpened() )
    {
        cout << "Video capturing has been started ..." << endl;

        for(;;)
        {
            try {
                capture >> frame;
            }
            catch (cv::Exception& e)
            {
                std::cout << " Excecao2 capturada frame: " << e.what() << std::endl;
                usleep(1000000);
                continue;
            }
            catch (std::exception& e)
            {
                std::cout << " Excecao3 capturada frame: " << e.what() << std::endl;
                usleep(1000000);
                continue;
            }

            if( frame.empty() )
                break;

           f.detectarFace( frame, cascade, scale );






            cout<<f.getCont()<<endl;

            char c = (char)waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }

    return 0;
}



