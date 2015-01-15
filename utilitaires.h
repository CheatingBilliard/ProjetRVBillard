/**
*
*   \file utilitaires.h
*   \brief header regroupant la déclaration des fonctions utiles ainsi que l'inclusion des bibliothèques nécessaires au projet
*   \author Valentin LIEVIN
*   \date 15 janvier 2015
*
*
*
**/

#ifndef UTILITAIRES_H
#define UTILITAIRES_H

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
#define M_LONG_VECTOR 30 /// définition de la longueur d'affichage d'un vecteur en pixel pour un vecteur normalisé

///Fonctions "Bas Niveau"


/**
 * \fn cv::Point operator*(cv::Point const& v1, float const& alpha)
 * \brief multiplication d'un vecteur par un facteur
 *
 * \param v1 : vecteur, alpha : coefficient
 * \return vecteur (cv::Point)
 */

cv::Point operator*(cv::Point const& v1, float const& alpha);


/**
 * \fn float operator*(cv::Point const& v1, cv::Point const& v2)
 * \brief dotProduct
 *
 * \param deux vecteurs
 * \return dotProduct
 */

float operator*(cv::Point const& v1, cv::Point const& v2);

/**
 * \fn void normalise(cv::Point& p)
 * \brief normaliser un vecteur ( cv::Point)
 *
 * \param un vecteur passé en paramètre
 * \return rien
 */

void normalise(cv::Point& p);

/**
 * \fn double distance(cv::Point  p1, cv::Point  p2)
 * \brief retourne la distance entre deux points
 *
 * \param deux points
 * \return la distance en "double"
 */

 double distancePoints(cv::Point const& p1, cv::Point const& p2);

 /**
 * \fn double crossProduct(cv::Point v1, cv::Point v2)
 * \brief retourne le produit crosé de deux vecteurs
 *
 * \param deux vecteurs
 * \return lle produit croisé en double flottant
 */

 double crossProduct(cv::Point v1, cv::Point v2);

 /**
 * \fn std::vector<double> solvePoly2(double a, double b, double c)
 * \brief calcul les solutions d'une équation polynomiale de second degré
 *
 * \param 3 paramètres (doubles flottants)
 * \return un vecteur de doubles flottants solutions de l'équation
 */

std::vector<double> solvePoly2(double a, double b, double c);

///Fonctions "Haut Niveau"

/**
 * \fn int intersectionVecteurSurDroite(cv::Point v1, cv::Point v1or, cv::Point v2, cv::Point v2or, cv::Point& sol)
 * \brief fonction détermine l'intersection de deux droites dirrigées par deux vecteurs directeurs : le sens est pris en compte car il s'agit d'une trajectoire
 *
 * \param v1 et v2 représentent des vecteurs, v1 et v2 représentent leur origine, sol est passé en paramètre, il s'agit du point d'intersection
 * \return 1 = intersection dans le sens du vecteur v1, -1 = intersection dans l'autre sens : 0 = pas d'intersection
 */

int intersectionVecteurSurDroite(cv::Point v1, cv::Point v1or, cv::Point v2, cv::Point v2or, cv::Point& sol);







#endif // UTILITAIRES_H
