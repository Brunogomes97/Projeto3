#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <exception>
#include <unistd.h>
#include "Face.h"
#include <ctime>
#include <time.h>
#include "ExibirTxt.h"
using namespace std;
using namespace cv;





string cascadeName;
Face f;
int main( int argc, const char** argv )
{
    //OpenCV
    VideoCapture capture;
    Mat frame;
    CascadeClassifier cascade;


    //Escala
    double scale=2;

    //Frames por segundo
    long frameCounter = 0;//
    int tick = 0;

    //clock por segundo
    clock_t ti, tf;
    double tempoGasto;




    cascadeName       = "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";


    std::time_t timeBegin = std::time(0);
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
            //FPS da Webcam
            frameCounter++;
            ti=clock();

        std::time_t timeNow = std::time(0) - timeBegin;

        if (timeNow - tick >= 1)
        {
            tick++;
            f.setFrame(frameCounter);
            frameCounter = 0;
        }
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

        //Clock do Processador
        tf=clock();
        tempoGasto= ( (double) (tf - ti) ) / CLOCKS_PER_SEC;
        f.setClock(tempoGasto);




            char c = (char)waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }

    return 0;
}
