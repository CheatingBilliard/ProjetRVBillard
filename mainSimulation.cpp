/**
*
*   \file main.cpp
*   \brief fonction principale du bloc calcul de trajectoire du projet "Tricher au billard Français" pour l'ECN - remise au propre et en utilisant la bibliothèque openCV à partir du projet BoiteAOutilBillard
*   \author Valentin LIEVIN
*   \date 14 janvier 2015
*
Ce projet simule la trajectoire d'une boule de billard sur un plateau contenant d'autres boules

*   Mode d'emploi :
-un clic : changer la position du vecteur directeur (canne)
-dirriger le vecteur en bougeant la souris
- clic du milieu pour arrêter de commander la direction du vecteur
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

int w = 600;
/**
 * \fn void onMouse( int event, int x, int y, int, void* )
 * \brief gestion de la souris
 *
 */
void onMouse( int event, int x, int y, int, void* );

/** variables globales (utiles pour la gestion de la souris)**/
bool afficher; // vrai lorsqu'il y a une clic
vector<myVec> mouseVec; //sert à récupérer les commandes souris


int main(int argc, char **argv){

    bool bcontinue = true; // booléen utilisé pour quitter la boucle principale

    //initialisation du vecteur mouseVec (gestion de la souris)
    mouseVec.clear();
    mouseVec.push_back(myVec(w/2, w/2) );
    mouseVec.push_back(myVec(w/4, w/4) );
    myVec vSouris;
    myVec vSourisPos;

    /// Déclaration des structures de données utilisées pour la partie simulation et affichage

    vector<myVec> pv; // vecteur contenant les positions des coins du cadre
    cadre c;    // cadre : 4 bandes
    vector<boule> b; // vecteur contenant l'ensemble des boules
    jeu j;  // jeu : contient l'ensemble des boules(b)  et le cadre (c)
    trajectoire traj ; // trajectoire que l'on affiche

    while(bcontinue)
    {

        char nomAffichage[] = " Affichage du billard ";

          // on crée une image vide -> à remplacer par l'image de la webcam
        image =  Mat::zeros( w, w, CV_8UC3 );

///écriture des structures de données pour la partie simulation et affichage

    //creration du vecteur regroupant les points du cadre
            //vector<myVec> pv;
            pv.clear();
            int k = 60;
            pv.push_back(myVec(k,k));
            pv.push_back(myVec(w-k,k));
            pv.push_back(myVec(w-k,w-k));
            pv.push_back(myVec(k,w-k));
    //création du cadre
            //cadre c;
            c = cadre(pv);
    //creation des centres des boules
            vector<myVec> pCercles;
            pCercles.clear();
            pCercles.push_back(myVec(5*w/6,5*w/6));
            pCercles.push_back(myVec(2*w/3,2*w/3));
            pCercles.push_back(myVec(w/5,w/3));
    //création d'un vecteur de boule
            //vector<boule> b;
            b.clear();
            for ( int i = 0; i<pCercles.size(); i ++)
            {
                boule tmp = boule(pCercles.at(i), 30);
                b.push_back(tmp);
            }
    //creation du jeu
            //jeu j;
            j = jeu(c,b);
            j.GetSelected(vSouris,vSourisPos);
            j.Afficher(image);

    //création d'une trajectoire
            //trajectoire traj ;
            j.GetTrajectoire(vSouris, vSourisPos , 5 , traj);
            traj.Afficher(image);





/// écriture du vecteur souris, affichage et gestion des interruptions clavier

            //Construire et Afficher le vecteur souris
            if(mouseVec.size()==2)
            {
                vSouris = mouseVec.at(1) - mouseVec.at(0);
                vSourisPos = mouseVec.at(0);
                vSouris.Normalise();
            }

            vSouris.AfficherVecteur(image, vSourisPos);

            //écriture et affichage de la nouvelle image

            namedWindow(nomAffichage);
            setMouseCallback( nomAffichage, onMouse, 0 );
            imshow( nomAffichage, image);
            moveWindow( nomAffichage, 0, 0 );
            system("clear");

            int key = cvWaitKey(20); // capture des événements claviers - (20) -> on attend 20ms

            //gestion des événements clavier
            switch(key)
            {
                    case(27):
                    bcontinue = false;
                    break;
            }

    }


::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

// gérer la souris
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
