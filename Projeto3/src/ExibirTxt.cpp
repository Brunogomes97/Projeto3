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


void ExibirTxt::exibirT(std::string texto,Mat &m, int posicao)
{
    putText(m,texto,            //Imagem e Texto
    Point2f(0, posicao),        // Posição x-y
    FONT_HERSHEY_COMPLEX, 0.5,  // Tipo da fonte e escala
    Scalar(0, 0, 255),          // Cor
    1, LINE_AA);                // Espessura e tipo da linha

}

