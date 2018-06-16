#ifndef EXIBIRTXT_H
#define EXIBIRTXT_H
#include <string>
#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class ExibirTxt
{
    public:
        ExibirTxt();
        virtual ~ExibirTxt();
        void exibirT(std::string,cv::Mat &m,int);




    protected:

    private:
};

#endif // EXIBIRTXT_H
