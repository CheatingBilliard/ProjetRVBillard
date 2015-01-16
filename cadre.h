

/**
*
*   \file cadre.h
*   \brief header regroupant la déclaration de la classe cadre
*   \author Valentin LIEVIN
*   \date 16 janvier 2015
*
*
*
**/

#ifndef CADRE_H
#define CADRE_H

#include "myVec.h"

/*! \class cadre
   * \brief classe représentant le cadre du jeu (les bandes)
   *
   *
   */


class cadre
{

    private:

        std::vector<myVec> Sommets;/*!< vecteur de sommets définissant le cadre*/

    public:
        /*!
         *  \brief Constructeur
         *  Constructeur de la classe cadre
         *  \param aucun
         */
        cadre();
        /*!
         *  \brief Constructeur
         *  Constructeur de la classe cadre
         *  \param vecteur de sommets
         */
        cadre(std::vector<myVec> S);
        /*!
         *  \brief Destructeur
         *  Destructeur de la classe cadre
         *  \param aucun
         */
        ~cadre();
        /*!
         *  \brief Getter Sommets
         *
         *  \param aucun
         */
        std::vector<myVec> GetSommets()const;
        /*!
         *  \brief Get sommet i
         *
         *  \param numéro du sommet
         */
        myVec GetSommets(int i)const;
        /*!
         *  \brief add sommet
         *
         *  \param vecteur à ajouter
         */
        void addSommets(myVec a);

        /*!
         *  \brief afficher le cadre
         *
         *  \param image à modifier
         */
        void Afficher(cv::Mat image);


};

#endif //CADRE_H
