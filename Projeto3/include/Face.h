#ifndef FACE_H
#define FACE_H

#include <iostream>
#include <exception>            //includes c/c++
#include <unistd.h>

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"  //includes opencv
#include "opencv2/imgproc.hpp"

#include "ExibirTxt.h"

class Face
{
    public:
        Face();
        virtual ~Face();
        void detectarFace(cv::Mat &img, cv::CascadeClassifier &cascade, double scale);
        void filtragem(int);
        ExibirTxt txt;

        int getContador();  //gets
        int getFrame();

        void setFrame(int); //sets

    private:
        int contador=0;
        int comparador1=0;
        int comparador2=0;
        int dif=0;
        int filtro=0;
        int frame;
};

#endif // FACE_H
