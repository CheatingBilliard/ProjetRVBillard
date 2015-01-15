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


#include"myVec.h"


///Fonctions "Bas Niveau"


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
 * \fn appartientSegment(myVec pointCible, myVec A, myVec B)
 * \brief déterminer si le point appartien au segment
 *
 * \param v1 et v2 représentent des vecteurs, v1 et v2 représentent leur origine, sol est passé en paramètre, il s'agit du point d'intersection
 * \return 1 = intersection dans le sens du vecteur v1, -1 = intersection dans l'autre sens : 0 = pas d'intersection
 */

bool appartientSegment(myVec pointCible, myVec A, myVec B);

/**
 * \fn int intersectionVecteurSurDroite(cv::Point v1, cv::Point v1or, cv::Point v2, cv::Point v2or, cv::Point& sol)
 * \brief fonction détermine l'intersection de deux droites dirrigées par deux vecteurs directeurs : le sens est pris en compte car il s'agit d'une trajectoire
 *
 * \param v1 et v2 représentent des vecteurs, v1 et v2 représentent leur origine, sol est passé en paramètre, il s'agit du point d'intersection
 * \return 1 = intersection dans le sens du vecteur v1, -1 = intersection dans l'autre sens : 0 = pas d'intersection
 */

int intersectionVecteurSurDroite(cv::Point v1, cv::Point v1or, cv::Point v2, cv::Point v2or, cv::Point& sol);







#endif // UTILITAIRES_H
