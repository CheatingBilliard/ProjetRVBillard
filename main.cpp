/**
*
*   \file main.cpp
*   \brief fonction principale du bloc calcul de trajectoire du projet "Tricher au billard Français" pour l'ECN - remise au propre et en utilisant la bibliothèque openCV à partir du projet BoiteAOutilBillard
*   \author Valentin LIEVIN
*   \date 14 janvier 2015
*
**/


#include<opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv.hpp>


#define w 600 /// défini la résolution de l'affichage

using namespace std;
using namespace cv;

void MyLine( Mat img, Point start, Point end );
void MyEllipse( Mat img, double angle );
void MyFilledCircle( Mat img, Point center );
void MyPolygon( Mat img, vector<Point> p ); ///tracer un polygon à partir d'un vecteur de points

int main(){

bool bcontinue = true;

char atom_window[] = "Drawing 1: Atom";


while(bcontinue){


    Mat atom_image = Mat::zeros( w, w, CV_8UC3 );


    MyLine( atom_image, Point( 0, 0 ), Point( w, 15*w/16 ) );

    line(atom_image, Point(0,0),Point(w-1,w-1), CV_RGB(255,0,0),3,8);
    vector<Point> p;
    p.push_back(Point(0,0));
    p.push_back(Point(w,0));
    p.push_back(Point(w,w));
    p.push_back(Point(0,w));
    MyPolygon(atom_image, p);



    MyEllipse( atom_image, 90 );
    MyEllipse( atom_image, 0 );
    MyEllipse( atom_image, 45 );
    MyEllipse( atom_image, -45 );

    MyFilledCircle( atom_image, Point( w/2, w/2) );

    imshow( atom_window, atom_image );
    moveWindow( atom_window, 0, 200 );

int key = cvWaitKey(0); // capture des événements claviers
if(key = 27){ //touche echap
bcontinue = false;
}
}

return 0;

}

void MyLine( Mat img, Point start, Point end )
{
int thickness = 5;
int lineType = 8;
line( img,
start,
end,
Scalar( 0, 0, 0 ),
thickness,
lineType );
}

void MyEllipse( Mat img, double angle )
{
int thickness = 2;
int lineType = 8;
ellipse( img,
Point( w/2, w/2 ),
Size( w/4, w/16 ),
angle,
0,
360,
Scalar( 255, 0, 0 ),
thickness,
lineType );
}

void MyFilledCircle( Mat img, Point center )
{
int thickness = -1;
int lineType = 8;
circle( img,
center,
w/32,
Scalar( 0, 0, 255 ),
thickness,
lineType );
}

void MyPolygon( Mat img, vector<Point> p )
{
  for (int i = 0; i<p.size(); i ++){
    int l = i+1;
    if (l == p.size())
        {l=0;}

    line(img, p[i],p[l], CV_RGB(255,0,255),3,8);
  }






 }
