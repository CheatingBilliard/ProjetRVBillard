/**
*
*   \file main.cpp
*   \brief fonction principale du bloc calcul de trajectoire du projet "Tricher au billard Français" pour l'ECN - remise au propre et en utilisant la bibliothèque openCV à partir du projet BoiteAOutilBillard
*   \author Valentin LIEVIN Quentin TRESONTANI
*   \date 14 janvier 2015
*
Ce projet simule la trajectoire d'une boule de billard sur un plateau contenant d'autres boules
La position des boules ainsi que le cadre du billard est détecté à l'aide d'une caméra.

*   Mode d'emploi :
- un clic : changer la position du vecteur directeur (canne)
- dirriger le vecteur en bougeant la souris
- clic du milieu pour arrêter de commander la direction du vecteur
*
**/

#include <string>
#include <vector>
#include "utilitaires.h"
#include "affichage.h"
#include "myVec.h"
#include "boule.h"
#include "cadre.h"
#include "trajectoire.h"
#include "jeu.h"
#include "structures.h"
#include "cadre_detection.h"
#include "boules_detection.h"


using namespace std;
using namespace cv;

cv::Mat image;

/**
 * \fn void onMouse( int event, int x, int y, int, void* )
 * \brief gestion de la souris
 *
 */
void onMouse( int event, int x, int y, int, void* );

/** variables globales (utiles pour la gestion de la souris)**/
bool afficher; // vrai lorsqu'il y a une click
vector<myVec> mouseVec; //sert à récupérer les commandes souris
int w = 900;

Billard billard;
vector<vector<Point> > historiquedespositions;
jeuBoules _boules;



int main(int argc, char **argv){

    //bool bcontinue = true; // booléen utilisé pour quitter la boucle principale

    VideoCapture cap(0); //capture the video from web cam
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 1080);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }

    //initialisation de du vecteur mouseVec (gestion de la souris)
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
    char nomAffichage[] = " Affichage du billard ";

    while(true)
    {
        Mat image;

        bool bSuccess = cap.read(image); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

        //Mat image;
        //flip(imgOriginal,image,1);
         b.clear();
        /// Detection des boules et du billard
        bouleDetection_callback(&image, &b);
        bouleDetection_createtrackbar();
        billard = cadreDetection(&image, historiquedespositions);
        cadreDetection_createtrackbar();

        // on crée une image vide -> à remplacer par l'image de la webcam
        //image =  Mat::zeros( w, w, CV_8UC3 );
        if (parametrageCadreDone(historiquedespositions)){

            cout << "On est entrés dans la boucle" << endl;

            ///écriture des structures de données pour la partie simulation et affichage
            //creration du vecteur regroupant les points du cadre

            //vector<myVec> pv;
            pv.clear();
            pv.push_back(myVec(billard.psommet0.x,billard.psommet0.y));
            pv.push_back(myVec(billard.psommet1.x,billard.psommet1.y));
            pv.push_back(myVec(billard.psommet2.x,billard.psommet2.y));
            pv.push_back(myVec(billard.psommet3.x,billard.psommet3.y));

            //création du cadre
            //cadre c;
            c = cadre(pv);

            // VECTOR : _boules.infos
            /*
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
            */

            //creation du jeu
            //jeu j;
            cout << " Taille " << b.size() << endl;
            j = jeu(c,b);
            j.GetSelected(vSouris,vSourisPos);
            j.Afficher(image);

            //création d'une trajectoire
            //trajectoire traj ;
            j.GetTrajectoire(vSouris, vSourisPos , 5 , traj);
            traj.Afficher(image);

        }

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

        namedWindow(nomAffichage, CV_WINDOW_AUTOSIZE);
        setMouseCallback( nomAffichage, onMouse, 0 );
        imshow( nomAffichage, image);
        //moveWindow( nomAffichage, 0, 0 );
        //system("clear");

        //int key = cvWaitKey(20); // capture des événements claviers - (20) -> on attend 20ms

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            image.release();
            //imgOriginal.release();
            break;
        }

    }

::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

// gérer la souris
void onMouse( int event, int x, int y, int, void* )
{
    if  ( event == EVENT_LBUTTONDOWN ){
        mouseVec.at(0) = myVec(x,y);
    }
    else if  ( event == EVENT_RBUTTONDOWN ){
    }
    else if  ( event == EVENT_MBUTTONDOWN ){
        if (afficher)
            afficher = false;
        else
            afficher = true;
    }
    else if ( event == EVENT_MOUSEMOVE && afficher){
        mouseVec.at(1) = myVec(x,y);
    }
}

