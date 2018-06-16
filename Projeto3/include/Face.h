#ifndef FACE_H
#define FACE_H
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <exception>
#include <unistd.h>
#include "ExibirTxt.h"

class Face
{
    public:
        Face();
        void detectarFace(cv::Mat &img, cv::CascadeClassifier &cascade, double scale);
        virtual ~Face();
        int getContador();
        void filtragem(int);
        ExibirTxt txt;
        void setFrame(int);
        int getFrame();

    private:
        int contador=0;
        int comparador1=0;
        int comparador2=0;
        int dif=0;
        int filtro=0;
        int frame;
};

#endif // FACE_H
