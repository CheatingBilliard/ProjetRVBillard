/**
*
*   \file trajectoire.h
*   \brief header regroupant la déclaration de la classe trajectoire héritant de la classe cadre
*   \author Valentin LIEVIN
*   \date 16 janvier 2015
*
*   la classe trajectoire est constitué d'un ensemble de point : l'ensemble des intersection avec d'autres objets de la boule lors d'un lancé
*
**/

#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H

#include "boule.h"


class trajectoire : public cadre
{
    public :

    /*!
         *  \brief constructeur
         *
         *  \param boule et vecteur de vecteurs
         */

        trajectoire(boule bo, std::vector<myVec> s);
     /*!
         *  \brief afficher la trajectoire
         *
         *  \param image à modifier
         */
        void Afficher(cv::Mat image);

        boule GetBoule(boule b)const;

        void SetBoule(boule b);


    private :

    boule B; /// chaque trajectoire est associée à une boule


};

#endif // TRAJECTOIRE_H
