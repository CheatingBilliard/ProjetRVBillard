
/**
*
*   \file boule.cpp
*   \brief fichier source regroupant la déclaration de la classe boule
*   \author Valentin LIEVIN
*   \date 16 janvier 2015
*
*
*
**/

#include "boule.h"

using namespace std;
using namespace cv;

boule::boule(){}

boule::boule(myVec c, double r) : centre(c), rayon(r) {}

boule::~boule(){}

myVec boule::GetCentre()const{return centre;}

double boule::GetRayon()const{return rayon;}

void boule::SetCentre(myVec c){centre=c;}

void boule::SetRayon(double r){rayon = r;}

void boule::Afficher(cv::Mat image,Scalar color){

    AfficherCercle( image, Point(centre.Getx(),centre.Gety()), color, rayon, false );
}

void boule::Afficher(cv::Mat image){
    Scalar color = Scalar(150,30,100);
    Afficher(image, color);
}

bool boule::GetIntersectionSegment(myVec v, myVec A , myVec B, myVec &sol , myVec& solVec)
{
    bool sens = intersectionVecteurSurSegment(v, centre,  A,  B, sol, solVec);
    // on a la direction du vecteur rebond

    if (sens)
    {
        myVec v2 = (B-A);
        v2.Normalise();
        myVec dir = (centre - sol );
        dir.Normalise();

        double alpha = angleDirecte(v2, v);
        if (alpha<0)
        {alpha = - alpha;}


        double h = rayon/sin(alpha);
        sol = sol + dir*h;


        return true;
    }
    else {return false;}
}


