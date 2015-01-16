/**
*
*   \file affichage.h
*   \brief header regroupant la déclaration des fonctions d'affichage ainsi que l'inclusion des fichiers nécessaires
*   \author Valentin LIEVIN
*   \date 15 janvier 2015
*
*
*
**/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

//#include "utilitaires.h"
#include "gtest/gtest.h"
#include <cmath>
#include <time.h>

#include<opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv.hpp>


#define w 600 /// défini la taille de l'affichage
#define M_TAILLE_POINT 3 /// définition de la taille d'un point
#define M_THICKNESS 1 /// définition de l'épaisseur d'une ligne tracée
#define M_LONG_VECTOR 40 /// définition de la longueur d'affichage d'un vecteur en pixel pour un vecteur normalisé
# define M_PIl          3.141592653589793238462643383279502884L /* pi */


/**
 * \fn void AfficherCercle( cv::Mat img, cv::Point center, cv::Scalar color, float rayon, bool plein )
 * \brief trace un cercle (plein si plein = true)
 *
 * \param img : image modifiée, center : centre du cercle, color : couleur du tracé, rayon du cercle, plein : true = cercle plein
 * \return rien
 */

void AfficherCercle( cv::Mat img, cv::Point center, cv::Scalar color, float rayon, bool plein );


/**
 * \fn void AfficherPointcv(cv::Mat img, cv::Point p)
 * \brief trace un point en fonction de la constante M_TAILLE_POINT ( voir : utilitaires.h )
 *
 * \param img : image à modifer, p : point à tracer
 * \return rien
*  trace un point ROUGE
*/
 void AfficherPointcv(cv::Mat img, cv::Point p);


/**
 * \fn void AfficherPolygon( cv::Mat img, std::vector<cv::Point> p,cv::Scalar color )
 * \brief trace un polygon à partir d'un vecteur de points et une couleur donnée
 *
 * \param img : image à modifer, vecteur de points : sommets du polygone, color : couleur du tracé
 * \return rien
 *

*/
void AfficherPolygon( cv::Mat img, std::vector<cv::Point> p,cv::Scalar color); ///tracer un polygon à partir d'un vecteur de points


/**
 * \fn void AfficherVecteurcv(cv:Mat img, cv::Point direction, cv::Point origine)
 * \brief trace un vecteur en à un point d'origine donné
 *
 * \param img : image à modifer, direction : direction du vecteur, origine : origine du vecteur
 * \return rien

trace un vecteur BLEU
*/

void AfficherVecteurcv(cv::Mat img, cv::Point direction, cv::Point origine);

#endif // AFFICHAGE_H
