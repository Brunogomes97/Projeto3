#include "Face.h"


using namespace std;
using namespace cv;
Face::Face()
{
    //ctor
}

void Face::detectarFace( Mat &img, CascadeClassifier &cascade, double scale)
{

    vector<Rect> faces;
    Scalar color = Scalar(0,0,255);
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY );
    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        |CASCADE_SCALE_IMAGE,
        Size(30, 30) );


    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Rect r = faces[i];
        Point center;

        //cout<<"o valor de y= "<<y<<endl;

        //cout<<"numero de faces na tela "<<quantFaces<<endl;
       // printf("xy face = %d x %d\n", r.x, r.y);

        rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),
                   cvPoint(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                   color, 3, 8, 0);
    }

        txt.exibirT("Faces na tela: " + to_string(faces.size()),img,15);
        txt.exibirT("Faces Capturadas: " + to_string(contador-1),img,30);
        txt.exibirT("Frames por Segundo:" + to_string(frame),img,45);
        filtragem(faces.size());

    imshow( "Rastreador de Faces", img );
}

Face::~Face()
{
    //dtor
}

int Face::getContador(){


return (contador);

}


void Face::setFrame(int frame){
    this->frame=frame;



}
int Face::getFrame(){
    return frame;

}


void Face::filtragem(int nFace){
//Responsavel por filtrar bugs de captura(capturas das não-faces);
    if(contador==0){
            contador=nFace;

        }
    comparador1=nFace;


    if(comparador1==comparador2){
        filtro++;
        if(filtro==50){

            contador+=dif;
            dif=0;
            filtro=0;
        }
    }

    if(comparador1>comparador2){

        dif=comparador1-comparador2;
    }else if(comparador1<comparador2){
        dif=0;

    }

    comparador2=nFace;

}
