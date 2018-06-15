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
        void detectarFace(cv::Mat img, cv::CascadeClassifier cascade, double scale);
        virtual ~Face();
        int getCont();
        void algoritimo(int);
        ExibirTxt txt;

    private:
        int cont;
        int quantFaces;


};

#endif // FACE_H
