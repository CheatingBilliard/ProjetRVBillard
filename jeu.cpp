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
                if( d > 0 ) // si le point est dans le sens de parcours du vecteur (voir distancePointSurDroite
                {
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

 bool jeu::GetTrajectoire( myVec v, myVec vor ,int nb, trajectoire& traj){

    int selected = GetSelected(v, vor); // on choisie la boule sectionnée
    if (selected >= 0)
    {
        vector<boule> CopieBoules ;
        boule bCible = b.at(selected); // on copie la boule cible

        for (int j = 0 ; j<b.size(); j++) // reconstruction de la copie sans la boule cible
        {
            if(j!= selected)
            {
            CopieBoules.push_back(b.at(j));
            }
        }

        vector<myVec> result;
        result.clear();
        myVec sol;
        myVec solVec;

        myVec tmpinter = bCible.GetCentre();
        myVec tmpinterVec = v;
        bool ok = true;
        result.push_back( tmpinter);

        for( int k = 0; k<nb ; k++)
        {
                //
                if (ok = true) //on vérifie qu'il y a bien eu une intersection
                {
                ok = bCible.GetIntersectionCadreBoules(tmpinterVec, c, CopieBoules, sol, solVec );
                    result.push_back( sol);
                    tmpinterVec = solVec;
                    bCible = boule(sol, bCible.GetRayon());
                }





        }
        traj = trajectoire(bCible, result);

    }
    else
    {
    return false;
    }
}
