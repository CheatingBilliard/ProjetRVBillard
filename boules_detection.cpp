/**
 * \file boules_detection.cpp
 * \brief programme de detection des boules
 * \author Quentin.T
 * \version 0.1
 * \date 11 janvier 2015
 *
 * Partie dédiée à la reconnaissance des boules de billard
 *
 */

#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv/highgui.h"
#include "opencv/cv.h"

#include "structures.h"
#include "conversion_format.h"
#include "cadre_detection.h"
#include "boules_detection.h"
#include "myVec.h"
#include "boule.h"

using namespace cv;
using namespace std;

int sigmaX = 3;
int sigmaY = 3;
int minRayon = 20;
int maxRayon = 100;
int canny_1 = 2;
int canny_2 = 200;
int canny_3 = 5;
int size_blur = 9;

void bouleDetection_callback(Mat *img, vector<boule> *boules){

    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 1;

    /// Conversion de l'image en gris puis en binaire
    Mat imgG;
    cvtColor( *img, imgG, CV_BGR2GRAY );
    Mat imgB;
    GaussianBlur( imgG, imgG, Size(size_blur, size_blur), sigmaX, sigmaY );
    Canny(imgG, imgB, canny_1, canny_2, canny_3);

    /// Detection des contours
    vector<vector<cv::Point> > contours;
    findContours(imgB, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
    //GaussianBlur( imgG, imgG, Size(9, 9), sigmaX, sigmaY );
    vector<Vec3f> circles;
    HoughCircles(imgG, circles, CV_HOUGH_GRADIENT,2, imgG.rows/4, 200, 100 );

    for( size_t i = 0; i < circles.size(); i++ )
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        if (radius < maxRayon || radius < minRayon) { // enlever les grands cercles qui sont des erreurs en général

            /// Enregistrement dans le vecteur contenant les boules
            boule boulecourrante(myVec(center.x, center.y), radius);
            boules->push_back(boulecourrante);

            /// Dessin de la boule à l'écran
            circle( *img, center, 3, Scalar(0,255,0), -1, 8, 0 );
            circle( *img, center, radius, Scalar(0,0,255), 1, 8, 0 );
            //string s = int2string(radius);
            //putText(*img, s, center, fontFace, fontScale, Scalar::all(0), 1,8);
            //string s1 = "Nombre cercles : "+ int2string(circles.size());
            //Point _point(100,100);
            //putText(*img,s1, _point, fontFace, fontScale, Scalar::all(0),1,0 );
        }
    }
    namedWindow( "Boules", CV_WINDOW_AUTOSIZE );
    imshow("Boules", imgB);
}


void bouleDetection_createtrackbar(){

    //Create trackbars in "Formes" window
    createTrackbar("Sigma X", "Boules", &sigmaX, 20);
    createTrackbar("Sigma Y", "Boules", &sigmaY, 20);
    createTrackbar("Rayon min", "Booules", &minRayon, 150);
    createTrackbar("Rayon max", "Boules", &maxRayon, 150);
    createTrackbar("Canny_1", "Boules", &canny_1, 10);
    createTrackbar("Canny_2", "Boules", &canny_2, 300);
}

