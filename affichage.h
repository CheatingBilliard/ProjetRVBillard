/**
*
*   \file affichage
*   \brief header regroupant la déclaration des fonctions d'affichage
*   \author Valentin LIEVIN
*   \date 15 janvier 2015
*
*
*
**/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "utilitaires.h"




/**
 * \fn void AfficherCercle( cv::Mat img, cv::Point center, cv::Scalar color, float rayon, bool plein )
 * \brief trace un cercle (plein si plein = true)
 *
 * \param img : image modifiée, center : centre du cercle, color : couleur du tracé, rayon du cercle, plein : true = cercle plein
 * \return rien
 */

void AfficherCercle( cv::Mat img, cv::Point center, cv::Scalar color, float rayon, bool plein );


/**
 * \fn void AfficherPoint(cv::Mat img, cv::Point p)
 * \brief trace un point en fonction de la constante M_TAILLE_POINT ( voir : utilitaires.h )
 *
 * \param img : image à modifer, p : point à tracer
 * \return rien
*  trace un point ROUGE
*/
 void AfficherPoint(cv::Mat img, cv::Point p);


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
 * \fn void AfficherVecteur(cv:Mat img, cv::Point direction, cv::Point origine)
 * \brief trace un vecteur en à un point d'origine donné
 *
 * \param img : image à modifer, direction : direction du vecteur, origine : origine du vecteur
 * \return rien

trace un vecteur BLEU
*/

void AfficherVecteur(cv::Mat img, cv::Point direction, cv::Point origine);

#endif // AFFICHAGE_H
