/**
 * \file main.cpp
 * \brief Programme principal
 * \author Quentin.T
 * \version 0.1
 * \date 10 janvier 2015
 *
 * Programme principal de reconnaissance du billard et de ses boules
 *
 */

#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "gtest/gtest.h"

#include "structures.h"
#include "cadre_detection.h"
#include "boules_detection.h"

using namespace cv;
using namespace std;


/**
*
* \todo
// - faire la projection: FAIL
// - faire les tests unitaire de la projection
// - faire la fonction de calcul de la position simplifiée
// - faire le parametrage de la detection : DONE
// - faire la détection de la canne
// - refaire la fonction de calcul de la distance non simplifiée (plus tard)
// - refaire la fonction de calcul de la position non simplifiée (plus tard)
// - faire le calibrage des couleurs (plus tard)
// - déttecter les boules mêmes à moitié occultées (bonus)
*
*/

Billard billard;
vector<vector<Point> > historiquedespositions;
jeuBoules _boules;


/// MAIN

int main( int argc, char** argv){

    VideoCapture cap(0); //capture the video from web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }
        Mat imgFlip;
        flip(imgOriginal,imgFlip,1);

        /// Detection des boules et du billard
        bouleDetection_callback(&imgFlip, &_boules);
        bouleDetection_createtrackbar();
        billard = cadreDetection(&imgFlip, historiquedespositions);

        /* cout << " Rouge " << _boules.rouge.centre << " Rayon: " << _boules.rouge.rayon_vu << endl;
        cout << " Bleu " << _boules.bleu.centre << " Rayon: " << _boules.bleu.rayon_vu << endl;
        cout << " Jaune " << _boules.jaune.centre << " Rayon: " << _boules.jaune.rayon_vu << endl;
        cout << "Billard: " << billard.psommet0.x << endl; */

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            imgFlip.release();
            imgOriginal.release();
            break;
        }
    }
    return(0);
}










