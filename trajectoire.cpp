/**
*
*   \file trajectoire.cpp
*   \brief fichier sourceregroupant la déclaration de la classe trajectoire héritant de la classe cadre
*   \author Valentin LIEVIN
*   \date 16 janvier 2015
*
*   la classe trajectoire est constitué d'un ensemble de point : l'ensemble des intersection avec d'autres objets de la boule lors d'un lancé
*
**/

#include "trajectoire.h"


using namespace std;
using namespace cv;


trajectoire::trajectoire(){}

trajectoire::trajectoire(boule bo, std::vector<myVec> s) : cadre(s) , B(bo)
{

}

boule trajectoire::GetBoule(boule b)const
{
    return B;
}

void trajectoire::SetBoule(boule b){
B = b;
}

void trajectoire::Afficher(cv::Mat image){
    if (Sommets.size() == 0)
    {
       // cerr << " in trajectoire::afficher : vecteur Sommet vide"<< endl;
    }
    else
    {
        boule btmp1 = boule(Sommets[0], M_ACTIVATION);
        btmp1.Afficher(image, Scalar(150/3,200/3));
        boule btmp = boule(Sommets[0], B.GetRayon());
        btmp.Afficher(image, Scalar(150,200,0));
        if (Sommets.size()>1)
        for ( int i = 1; i< Sommets.size(); i ++)
        {
            boule btmp = boule(Sommets[i], B.GetRayon());
            MyLine(image, Point(Sommets[i-1].Getx(),Sommets[i-1].Gety() ), Point(Sommets[i].Getx(),Sommets[i].Gety() ) , Scalar(0,200,0));
            btmp.Afficher(image, Scalar(0,200,0));
        }
    }
}
