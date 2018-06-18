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
#include <chrono>

using namespace std;
using namespace cv;
using namespace chrono;

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

    //Variaveis intermediarias
    double g,u;
    int x;

    //Frames por segundo
    long frameCounter = 0;//
    int tick = 0;

    //clock por segundo
    clock_t ti, tf;
    double tempoGasto;

    cascadeName = "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";

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
        cout << "Digite como voce quer medir o trafego(1-Para Minutos 2-Para Horas)." << endl;
        cin >> u;
        if(u==1){
            cout << "Digite o tempo em minutos." << endl;
            cin >> u;
            g=u*60;
        }else if(u==2){
            cout << "Digite o tempo em horas." << endl;
            cin >> u;
            g=u*60*60;
            cout << "Digite o tempo em minutos." << endl;
            cin >> u;
            g=g+(u*60);
        }

        steady_clock::time_point t1 = steady_clock::now();

        do
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

            steady_clock::time_point t2 = steady_clock::now();
            duration <double> tempo = duration_cast<duration<double>>(t2-t1);
            u = tempo.count();

            f.detectarFace(frame, cascade, scale, u);

            //Clock do Processador
            tf=clock();
            tempoGasto= ( (double) (tf - ti) ) / CLOCKS_PER_SEC;
            f.setClock(tempoGasto);

            char c = (char)waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;

            // cout << tempo.count() << endl;

        }while(u < g);
    }
    x=f.getContador()/(g/60);
    cout << "Passaram " << f.getContador() << " pessoas em " << g/60 << " minutos ficando " << x <<"P/M." << endl;

    return 0;
}
