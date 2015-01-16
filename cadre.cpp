/**
*
*   \file cadre.cpp
*   \brief fichier source de la classe cadre
*   \author Valentin LIEVIN
*   \date 16 janvier 2015
*
*
*
**/

#include "cadre.h"

using namespace std;
using namespace cv;

    cadre::cadre(){}

    cadre::cadre(std::vector<myVec> S) : Sommets(S) { }

    cadre::~cadre(){}

    std::vector<myVec> cadre::GetSommets()const{ return Sommets;}
    myVec cadre::GetSommets(int i)const
    {
        if(i < Sommets.size())
        {
            return Sommets.at(i);
        }
        else
        {
           std::cerr<< "in cadre::GetSommets : i dépasse la taille de Sommets"<<endl;
        }
    }
    void cadre::addSommets(myVec a)
    {
        Sommets.push_back(a);
    }


    void cadre::Afficher(cv::Mat image)
    {
        std::vector<cv::Point> p;
        for (int i = 0; i<Sommets.size() ; i++)
        {
        p.push_back(Point(Sommets[i].Getx(), Sommets[i].Gety()));
        }
        AfficherPolygon( image, p,Scalar(70,70,70));
    }
