
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

bool boule::GetIntersectionBoule(myVec v, boule B, myVec &sol )
{
    double r = rayon + B.GetRayon() ;
	bool result = false;

	if ( v.Getx() == 0 && v.Gety() == 0)
	{
        return false;
	}
	else
	{
        if (v.Gety()!= 0)
        {
            double l = v.Getx()/v.Gety();
            double Q = centre.Getx() - l * centre.Gety();
            double K = r*r - ( B.GetCentre().Getx()*B.GetCentre().Getx() + B.GetCentre().Gety()*B.GetCentre().Gety());

            double da = (l*l +1);
            double db = 2 * ( ( Q - B.GetCentre().Getx() ) * l - B.GetCentre().Gety() );
            double dc = Q*Q - 2* Q * B.GetCentre().Getx() - K;

            vector<double> vsol = solvePoly2(da,db,dc);

            if (vsol.size() == 0)
                {return false;}
            else if (vsol.size() == 1 )
            {
                sol = myVec( Q + l * vsol.at(0) , vsol.at(0) );
                return true;
            }
            else if (vsol.size() == 2)
            {
                myVec sol1 = myVec( Q+ l*vsol.at(0) , vsol.at(0) );
                myVec sol2 = myVec( Q+ l * vsol.at(1) ,vsol.at(1) );

                if ( (sol1-centre).GetNorme() < (sol2-centre).GetNorme()  )
                { sol = sol1;}
                else
                {sol = sol2;}

                return true;
            }
            else // if v.Gety() ==0
            {
                double K = r*r + pow(B.GetCentre().Getx(),2) + pow( centre.Gety() - B.GetCentre().Gety(),2) ;
                da = 1;
                db = -2 * B.GetCentre().Getx();
                dc = -K;

                vector<double> vsol = solvePoly2(da,db,dc);

            if (vsol.size() == 0)
                {return false;}
            else if (vsol.size() == 1 )
            {
                sol = myVec( vsol.at(0) , centre.Gety() );
                return true;
            }
            else if (vsol.size() == 2)
            {
                myVec sol1 = myVec( vsol.at(0) , centre.Gety());
                myVec sol2 = myVec( vsol.at(1) , centre.Gety());

                if ( (sol1-centre).GetNorme() < (sol2-centre).GetNorme()  )
                { sol = sol1;}
                else
                {sol = sol2;}

                return true;
            }
        }
	}
    }
}

