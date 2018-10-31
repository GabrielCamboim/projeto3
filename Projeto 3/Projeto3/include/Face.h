#ifndef FACE_H
#define FACE_H
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <exception>
#include <unistd.h>
#include "ExibirTxt.h"
using namespace std;
using namespace cv;
class Face
{
    protected:
        int cont=0;
        int comparador1=0;
        int comparador2=0;
        int dif=0;
        int filtro=0;
	double med;
        int frame;
        double clock;

    public:
        Face();
        void detectarFace(Mat &img, CascadeClassifier &cascade, double scale);
        virtual ~Face();

        void filtragem(int);

        void setFrame(int frame);
        void setClock(double clock);
	double getMed();
	void setMed(double med);
        double getClock();
        int getCont();
        int getFrame();
        ExibirTxt txt;

   
};

#endif // FACE_H
