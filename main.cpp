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
#include "myVec.h"
#include "boule.h"
#include "cadre.h"
#include "trajectoire.h"
#include "jeu.h"

using namespace std;
using namespace cv;

cv::Mat image;


void onMouse( int event, int x, int y, int, void* );


bool afficher; // vrai lorsqu'il y a une click



vector<myVec> mouseVec; //sert à récupérer les commandes souris


int main(int argc, char **argv){

    bool bcontinue = true;

    double offset = 0.1;
    double t = 0;
    afficher = true;

    mouseVec.clear();
    mouseVec.push_back(myVec(w/2, w/2) );
    mouseVec.push_back(myVec(w/4, w/4) );
    myVec vSouris;
    myVec vSourisPos;

    while(bcontinue){

    char nomAffichage[] = " Affichage du billard ";
      // on crée une image vide
    image =  Mat::zeros( w, w, CV_8UC3 );



//
//        myVec p = myVec( w/2,w/2);
//        myVec v = myVec( cos(t),sin(t));
//        cout << " v : "<< v.Getx() << " | " << v.Gety()<< "  norme : "<< v.GetNorme() <<endl<<endl;
//        p.AfficherPoint(image);
//        //v.AfficherVecteur(image, p);
//        v.Normalise();
//        cout << " v : "<< v.Getx() << " | " << v.Gety()<< "  norme : "<< v.GetNorme() <<endl<<endl;
//        //v*=5;
//        v.AfficherVecteur(image, p);


//creration du cadre
        vector<myVec> pv;
        int k = 60;
        pv.push_back(myVec(k,k));
        pv.push_back(myVec(w-k,k));
        pv.push_back(myVec(w-k,w-k));
        pv.push_back(myVec(k,w-k));

        cadre c = cadre(pv);
//creation des boules
        vector<myVec> pCercles;
        pCercles.push_back(myVec(w/5,w/3));
        pCercles.push_back(myVec(4*w/5,5*w/6));
        pCercles.push_back(myVec(4*w/5,w/3));

        vector<boule> b;
        b.clear();
        for ( int i = 0; i<pCercles.size(); i ++)
        {
            boule tmp = boule(pCercles.at(i), 40);
            b.push_back(tmp);
        }
//creation du jeu
        jeu j;
        j = jeu(c,b);
        j.GetSelected(vSouris,vSourisPos);
        j.Afficher(image);






        //Afficher le vecteur souris
        if(mouseVec.size()==2)
        {
            vSouris = mouseVec.at(1) - mouseVec.at(0);
            vSourisPos = mouseVec.at(0);
            vSouris.Normalise();
        }

        vSouris.AfficherVecteur(image, vSourisPos);

        int key = cvWaitKey(30); // capture des événements claviers


        //écriture et affichage de la nouvelle image


        namedWindow(nomAffichage);
        setMouseCallback( nomAffichage, onMouse, 0 );
        imshow( nomAffichage, image);
        moveWindow( nomAffichage, 1000, 200 );
        system("clear");

          //gestion des événements clavier
        switch(key)
        {
                case(27):
                bcontinue = false;
                break;

                case(56):
                t =  t + offset;
                break;

                case(50):
                t = t - offset;
                break;

        }

    }


::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}


void onMouse( int event, int x, int y, int, void* )
{
    if  ( event == EVENT_LBUTTONDOWN )
    {

        mouseVec.at(0) = myVec(x,y);

    }
    else if  ( event == EVENT_RBUTTONDOWN )
    {

    }
    else if  ( event == EVENT_MBUTTONDOWN )
    {
        if (afficher)
        afficher = false;
        else
        afficher = true;
    }
    else if ( event == EVENT_MOUSEMOVE && afficher)
    {

        mouseVec.at(1) = myVec(x,y);
    }

}

