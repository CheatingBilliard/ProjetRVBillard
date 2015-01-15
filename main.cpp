/**
*
*   \file main.cpp
*   \brief fonction principale du bloc calcul de trajectoire du projet "Tricher au billard Français" pour l'ECN - remise au propre et en utilisant la bibliothèque openCV à partir du projet BoiteAOutilBillard
*   \author Valentin LIEVIN
*   \date 14 janvier 2015
*
*   La classe Point (@opencv) sera utilisé en tant que vecteur
*
**/


#include "utilitaires.h"
#include "affichage.h"

using namespace std;
using namespace cv;

void MyLine( Mat img, Point start, Point end );
void MyEllipse( Mat img, double angle );
void MyFilledCircle( Mat img, Point center );

int main(){

bool bcontinue = true;

char atom_window[] = "Drawing 1: Atom";


while(bcontinue){

    // on crée une image vide
    Mat atom_image = Mat::zeros( w, w, CV_8UC3 );


    MyLine( atom_image, Point( 0, 0 ), Point( w, 15*w/16 ) );
    AfficherPoint(atom_image, Point( w/6,w/2) );

    // tracer une ligne
    //line(atom_image, Point(0,0),Point(w-1,w-1), CV_RGB(255,0,0),3,8);

    AfficherCercle(atom_image, Point(w/2,w/2), CV_RGB(255,0,0), 50, false);

    //tracer un polygon
    vector<Point> p;
    p.push_back(Point(15,15));
    p.push_back(Point(w-15,15));
    p.push_back(Point(w-15,w-15));
    p.push_back(Point(15,w-15));
    AfficherPolygon(atom_image, p, Scalar(70,70,70));


    Point p1 = Point(1,1);
    Point p2 = p1;
    AfficherVecteur(atom_image, p1, Point(w/2,w/2));
    AfficherVecteur(atom_image, p2, Point(w/2,w/2));
    cout<<"test dot : "<< p1*p2 <<endl;

    imshow( atom_window, atom_image );
    moveWindow( atom_window, 0, 200 );

int key = cvWaitKey(0); // capture des événements claviers
if(key ==27){ //touche echap
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


