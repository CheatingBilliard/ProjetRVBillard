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



 /**
 * \fn double angleDirecte(myVec v1, myVec v2 )
 * \brief retourne l'angle direct entre deux vecteurs
 *
 * \param 2 vecteurs
 * \return un angle double
 */

double angleDirecte(myVec v1, myVec v2 );

/**
 * \fn double distancePointSurDroite(myVec v1, myVec v1or, myVec point)
 * \brief retourne la distance d'un point par rapport à une droite
 * négatif si le point est derrière l'origine du vecteur
 * \param myVec v1, myVec v1or, myVec point
 * \return double ( distance )
 */

double distancePointSurDroite(myVec v1, myVec v1or, myVec point);

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
 * \fn bool intersectionVecteurSurSegment(myVec v1, myVec v1or, myVec v2, myVec v2or, myVec & sol)
 * \brief fonction détermine l'intersection de deux droites dirrigées par deux vecteurs directeurs : le sens est pris en compte car il s'agit d'une trajectoire
 *
 * \param v1 et v2 représentent des vecteurs, v1 et v2 représentent leur origine, sol est passé en paramètre, il s'agit du point d'intersection
 * \return vrai : intersection, faux :pas d'intersection
 */

bool intersectionVecteurSurSegment(myVec v1, myVec v1or, myVec v2, myVec v2or, myVec & sol);

/**
 * \fn bool intersectionVecteurSurSegment(myVec v1, myVec v1or, myVec A, myVec B, myVec & solor, myVec& sol)
 * \brief fonction détermine l'intersection de deux droites dirrigées par deux vecteurs directeurs et donne le vecteur directeur du rebond: le sens est pris en compte car il s'agit d'une trajectoire
 *
 * \param v1 et v2 représentent des vecteurs, v1 et v2 représentent leur origine, sol est passé en paramètre, il s'agit du point d'intersection, solvec est le vecteur rebond
 * \return vrai : intersection, faux :pas d'intersection
 */
bool intersectionVecteurSurSegment(myVec v1, myVec v1or, myVec A, myVec B, myVec & sol, myVec& solvec);





#endif // UTILITAIRES_H
