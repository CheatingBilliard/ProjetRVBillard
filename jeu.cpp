/**
*
*   \jeu.cpp
*   \brief fichier source regroupant les méthodes de jla classe jeu
*   \author Valentin LIEVIN
*   \date 16 janvier 2015
*
*
*
**/

#include "jeu.h"

using namespace std;
using namespace cv;


jeu::jeu(){}

jeu::jeu(cadre cad, std::vector<boule> bou) : c(cad), b(bou), selected(-1){}

jeu::~jeu(){}


int jeu::GetSelected(myVec v, myVec vor)
{
    double d ;
    double tmp= 100000000000000; // nombre très grand
    int ind = -1;
    if(b.size() == 0)
    {
        return -1;
        selected = -1;
    }

    else
    {
        for (int i = 0; i<b.size(); i ++  ) //on parcourt le vecteur de boules
        {
            if( (vor - b.at(i).GetCentre()).GetNorme() < M_ACTIVATION ) // si le sommet de la canne est à bonne distance
            {
                d = distancePointSurDroite(v, vor, b.at(i).GetCentre());
                if( d > 0 )
                {
                    cout << "in jeu::GetSelected : d | tmp  : " << d << " | " <<tmp <<endl<<endl;
                    if (d<tmp)
                    {
                        tmp = d;
                        ind = i;
                    }
                }
            }
        }
        selected = ind;
        return  ind;
    }
}

void jeu::Afficher(cv::Mat image)
{
    c.Afficher(image);
    for(int i = 0 ; i<b.size() ; i ++)
    {
        if(i != selected)
        {
            b.at(i).Afficher(image);
        }
        else
        {
            b.at(i).Afficher(image , Scalar(0,0,255));
        }
    }

}
