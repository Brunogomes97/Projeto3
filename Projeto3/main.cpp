#include <iostream>
#include <exception>            //includes c/c++
#include <unistd.h>
#include <ctime>

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"  //includes opencv
#include "opencv2/imgproc.hpp"

#include "Face.h"
#include "ExibirTxt.h"          //classes

using namespace std;
using namespace cv;

string cascadeName;             //variaveis globais
Face f;

int main(int argc, const char** argv)
{
    VideoCapture capture;
    Mat frame;                  //variaveis opencv
    CascadeClassifier cascade;

    int tick = 0, i=0;
    double scale=2;
    long frameCounter = 0;

    cascadeName = "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";

    time_t timeBegin = time(0);

    if(!cascade.load( cascadeName ))
    {
        cerr << "ERROR: Nao foi possivel carregar CascadeClassifier" << endl;
        return -1;
    }

    try {
        if(!capture.open(0))
            cout << "Captura da camera #0 Nao Funcionou" << endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Excecao capturada: " << e.what() << std::endl;
    }

    if(capture.isOpened())
    {
        cout << "A captura de vídeo foi iniciada ..." << endl;

        for(;;)
        {
            frameCounter++;
            i++;
            cout<<i<<endl;

            time_t timeNow = time(0) - timeBegin;

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
                std::cout << " Excecao 2 captura de frame: " << e.what() << std::endl;
                usleep(1000000);
                continue;
            }
            catch (std::exception& e)
            {
                std::cout << " Excecao 3 captura de frame: " << e.what() << std::endl;
                usleep(1000000);
                continue;
            }

            if( frame.empty() )
                break;

            f.detectarFace(frame, cascade, scale);

            char c = (char)waitKey(10);
            if(c == 27 || c == 'q' || c == 'Q')
                break;

        }
    }
    return 0;
}
