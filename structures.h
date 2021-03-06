/**
 * \file structures.h
 * \brief définition des structures utilisées
 * \author Quentin.T
 * \version 0.1
 * \date 11 janvier 2015
 *
 * Définition des structures utilisées
 *
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


/**
 * \struct position
 * \brief structure décrivant la position dans l'espace
 */
struct position{
    int x;
    int y;
};

/**
 * \struct Boule
 * \brief structure décrivant une Boule
 */
struct Boule {
    double rayon_vu;
    cv::Point centre;
};


struct jeuBoules {
    Boule rouge;
    Boule jaune;
    Boule bleu;
    std::vector<std::vector<double> > infos;
};

/**
 * \struct Billard
 * \brief structure décrivant le billard
 * \todo affiner les paramètres présents
 */
struct Billard {
    // points vus à l'écran, on s'intéresse qu'à x et y
    cv::Point sommet0;
    cv::Point sommet1;
    cv::Point sommet2;
    cv::Point sommet3;

    position psommet0;
    position psommet1;
    position psommet2;
    position psommet3;

    // longueur vues par la caméra
    double longueur_gauche;
    double longueur_droite;
    double largeur_avant;
    double largeur_arriere;
};

#endif // STRUCTURES_H
