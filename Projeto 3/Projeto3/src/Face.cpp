#include "../include/Face.h"

using namespace std;
using namespace cv;
Face::Face(){}

void Face::detectarFace( Mat &img, CascadeClassifier &cascade, double scale)
{
    vector<Rect> faces;
    Scalar color = Scalar(250,250,250);
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY );
    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        |CASCADE_SCALE_IMAGE,
        Size(30, 30) );


    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Rect r = faces[i];
        Point center;


        rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),
                   cvPoint(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                   color, 3, 8, 0);
    }

        txt.exibirT("Faces na tela: " + to_string(faces.size()),img,15);
        txt.exibirT("                         Faces Capturadas: " + to_string(cont-1),img,15);

        filtragem(faces.size());

        imshow( "Face detector", img );
}

Face::~Face(){}

int Face::getCont(){


return cont;

}


void Face::setFrame(int f){
    frame=f;



}
int Face::getFrame(){
    return frame;

}

void Face::setClock(double clock){
    clock=clock;


}

double Face::getClock(){
    return clock;

}
void Face::setMed(double med){
   med=med;
}

double Face::getMed(){
return med;
}

void Face::filtragem(int nFace){
//Responsavel por filtrar bugs de captura(capturas das não-faces);
    if(cont==0){
            cont=nFace;
        }
    comparador1=nFace;


    if(comparador1==comparador2){
        filtro++;
        if(filtro==40){

            cont+=dif;
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
