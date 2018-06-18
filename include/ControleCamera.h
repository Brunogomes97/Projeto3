#ifndef CONTROLECAMERA_H
#define CONTROLECAMERA_H
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

class ControleCamera
{
    public:
        ControleCamera();
        virtual ~ControleCamera();
        int Iniciar(VideoCapture, Mat, CascadeClassifier, string);

        Face f;

    private:
        double tempoC=0,tempoT=0;
        long frameCounter = 0;
        int tick = 0;
        clock_t ti, tf;
        double tempoGasto;
        double scale=2;
        int PM;

};

#endif // CONTROLECAMERA_H
