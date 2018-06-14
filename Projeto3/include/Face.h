#ifndef FACE_H
#define FACE_H
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <exception>
#include <unistd.h>
using namespace cv;
class Face
{
    public:
        Face();
        void detectarFace(Mat img, CascadeClassifier cascade, double scale);
        virtual ~Face();
        int getCont();
        int cont;

    private:
        int quantFaces;

};

#endif // FACE_H
