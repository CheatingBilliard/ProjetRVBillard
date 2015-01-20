/**
 * \file boules_detection.h
 * \brief programme de detection des boules
 * \author Quentin.T
 * \version 0.1
 * \date 11 janvier 2015
 *
 * Partie dédiée à la reconnaissance des boules de billard
 *
 **/

 #ifndef BOULES_DETECTION_H
 #define BOULES_DETECTION_H

#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "conversion_format.h"
#include "structures.h"
#include "boule.h"

extern int sigmaX;
extern int sigmaY;
extern int minRayon;
extern int maxRayon;
extern int canny_1;
extern int canny_2;
extern int canny_3;


/**
 * \fn void bouleDetection_callback(Mat *img, vector<boule> *boules)
 * \brief Fonction de détection des boules de billard
 *
 * \param Mat img en entrée, vecteur de boules
 * \return On affiche ajoute la position des boules sur l'image et on actualise le vecteur contenant les boules.
 */
void bouleDetection_callback(cv::Mat *img, std::vector<boule> *_boules);


/**
 * \fn void bouleDetection_createtrackbar()
 * \brief Fonction de création des trackbars de bouleDetection()
 *
 * \param
 * \return création d'une trackbar sur la fenêtre "Boules" de bouleDetection()
 */
void bouleDetection_createtrackbar();



#endif // BOULES_DETECTION_H
