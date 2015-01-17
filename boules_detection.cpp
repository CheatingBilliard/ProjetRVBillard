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

int sigmaX = 2;
int sigmaY = 2;
int minRayon = 30;
int maxRayon = 90;

void bouleDetection_callback(Mat *img, vector<boule> *boules){

    // Concersion du gris en image binaire
    Mat imgG;
    cvtColor( *img, imgG, CV_BGR2GRAY );
    Mat imgB;
    Canny(imgG, imgB, 0, 50, 5 );

    // Find contours
    vector<vector<cv::Point> > contours;
    findContours(imgB, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    // The array for storing the approximation curve
    vector<Point> approx;

    // We'll put the labels in this destination image
    Mat *dst = img;

    // écriture sur les images
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 1;

    GaussianBlur( imgG, imgG, Size(9, 9), sigmaX, sigmaY );
    vector<Vec3f> circles;
    HoughCircles(imgG, circles, CV_HOUGH_GRADIENT,2, imgG.rows/4, 200, 100 );

    for( size_t i = 0; i < circles.size(); i++ )
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        if (radius < maxRayon || radius < minRayon) { // enlever les grands cercles qui sont des erreurs en général

            // draw the circle center
            circle( *dst, center, 3, Scalar(0,255,0), -1, 8, 0 );

            boule boulecourrante(myVec(center.x, center.y), radius);
            boules->push_back(boulecourrante);

            /*vector<double> boulecourante;
            boulecourante.push_back((double)center.x);
            boulecourante.push_back((double)center.y);
            boulecourante.push_back((double)radius);

            _boules->infos.push_back(boulecourante);

            if (i==0){
                _boules->rouge.centre = center;
                _boules->rouge.rayon_vu = radius;

            }
            if (i==1){
                _boules->bleu.centre = center;
                _boules->bleu.rayon_vu = radius;
            }
            if (i==2){
                _boules->jaune.centre = center;
                _boules->jaune.rayon_vu = radius;
            }*/


            // draw the circle outline
            circle( *dst, center, radius, Scalar(0,0,255), 1, 8, 0 );

            // give further informations
            string s = int2string(radius);
            putText(*dst, s, center, fontFace, fontScale, Scalar::all(0), 1,8);

            string s1 = "Nombre cercles : "+ int2string(circles.size());
            Point _point(100,100);
            putText(*dst,s1, _point, fontFace, fontScale, Scalar::all(0),1,0 );
            /*
            if (radius != 0) {
                int distance = calculDistanceSimplifie(radius);
                string s2 = "Distance : " +int2string(distance)+ "cm";
                Point _point1; _point1.x =center.x; _point1.y = center.y-50;
                putText(dst,s2, _point1, fontFace, fontScale, Scalar::all(255),1,0);
            }
            */
        }
    }
    //namedWindow( "Boules", CV_WINDOW_AUTOSIZE );
    //imshow("Boules", *dst);
}


void bouleDetection_createtrackbar(){

    //Create trackbars in "Formes" window
    //createTrackbar("Sigma X", "Boules", &sigmaX, 10);
    //createTrackbar("Sigma Y", "Boules", &sigmaY, 10);
    //createTrackbar("Rayon min", " Affichage du billard ", &minRayon, 150);
    //createTrackbar("Rayon max", " Affichage du billard ", &maxRayon, 150);
}

