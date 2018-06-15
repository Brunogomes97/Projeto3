#include "ExibirTxt.h"
using namespace cv;

ExibirTxt::ExibirTxt()
{
    //ctor
}

ExibirTxt::~ExibirTxt()
{
    //dtor
}
void ExibirTxt::exibirT(std::string texto,Mat m, int posicao)
{
    putText(m,texto,
    Point2f(0, posicao),
    FONT_HERSHEY_COMPLEX, 0.5, // font face and scale
    Scalar(0, 0, 255,255), // white
    1, LINE_AA); // line thickness and type

}

