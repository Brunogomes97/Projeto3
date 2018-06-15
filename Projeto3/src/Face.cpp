#include "Face.h"

   int x=0, y=0,dif=0,c=0;
using namespace std;
using namespace cv;
Face::Face()
{
    //ctor
}

void Face::detectarFace( Mat img, CascadeClassifier cascade, double scale)
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
        printf("xy face = %d x %d\n", r.x, r.y);

        rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),
                   cvPoint(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                   color, 3, 8, 0);
    }

        txt.exibirT("Numero de Faces: " + to_string(faces.size()),img,15);
        txt.exibirT("Pessoas Capturadas: " + to_string(cont),img,30);

        algoritimo(faces.size());

    imshow( "Trafego de Pessoas", img );
}

Face::~Face()
{
    //dtor
}

int Face::getCont(){


return cont;

}

void Face::algoritimo(int nFace){

    if(cont==0){

            cont=nFace;

        }
        x=nFace;
        //cout<<"o valor de x= "<<x<<endl;

        if(x==y){
        c+=1;

            if(c==50){

            cont+=dif;
            dif=0;
            c=0;
            }

        }

        if(x>y){

            dif=x-y;

        }else if(x<y){

        dif=0;

        }

        y=nFace;

}
