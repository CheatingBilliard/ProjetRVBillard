/*!
 * \file myVec.h
 * \brief Classe Vec : vecteur gérant les flottants en paramètre
 * \author Valentin LIEVIN
 * \version 15/1/2015
 */


#ifndef VEC_H
#define VEC_H




#include "affichage.h"



/*! \class myVec
   * \brief classe représentant un vecteur (ou point)
   *
   *  cette classe reporduit les nomres et les méthodes de la classe cv::Point tout en gérant les nombres flottants
   */


class myVec
{
    public:

    /*!
     *  \brief Constructeur
     *  Constructeur de la classe myVec
     *  \param aucun
     */
        myVec();
         /*!
     *  \brief Constructeur
     *  Constructeur de la classe myVec
     *  \param les coordonnées en double flottant
     */
        myVec(double mx, double my);
         /*!
     *  \brief destructeur
     *  \param aucun
     */
        virtual ~myVec();
         /*!
     *  \brief getter x
     *  retourne x
     *  \param aucun
     */
        double Getx() const { return x; }
         /*!
     *  \brief setter x
     *  retourne x
     *  \param double flottant
     */
        void Setx(double val) { x = val; }
            /*!
     *  \brief getter y
     *
     *  \param aucun
     */
        double Gety() const { return y; }
            /*!
     *  \brief setter y
     *
     *  \param double flotant
     */
        void Sety(double val) { y = val; }
    /*!
     *  \brief afficher un point
     *
     *  \param aimage sur laquelle on dessine
     */
        void AfficherPoint(cv::Mat img)const;
            /*!
     *  \brief affiche le vecteur associé à un un point donné
     *
     *  \param image sur laquelle on dessine, origine du vecteur
     */
        void AfficherVecteur(cv::Mat image, myVec vorigine)const;
        double GetNorme()const;

        /**
 * \brief multiplication d'un vecteur par un facteur
 * \param v1 : vecteur, alpha : coefficient
 * \return vecteur (cv::Point)
 */
        void operator*=(double const& alpha);
                /**
 * \brief normalisation du vecteur
 * \param aucun
 * \return aucun
 */
        void Normalise();



    protected:
    private:
        double x; /*!< coordonnée selon x*/
        double y; /*!< coordonnée selon y*/
};


///Fonctions utiles pour myVec



/**
 * \fn myVec operator*(myVec const& v1, float const& alpha)
 * \brief test d'égalité
 *
 * \param v1 : vecteur, v2 : vecteur
 * \return booléen
 */

bool operator==(myVec const& v1, myVec const& v2);


/**
 * \fn myVec operator*(myVec const& v1, float const& alpha)
 * \brief multiplication d'un vecteur par un facteur
 *
 * \param v1 : vecteur, alpha : coefficient
 * \return vecteur
 */

myVec operator*(myVec const& v1, float const& alpha);


/**
 * \fn float operator*(myVec const& v1, myVec const& v2)
 * \brief dotProduct
 *
 * \param deux vecteurs
 * \return dotProduct
 */

double operator*(myVec const& v1, myVec const& v2);

/**
 * \fn myVec operator+(myVec const& v1, myVec const& v2)
 * \brief addition de vecteurs
 *
 * \param deux vecteurs
 * \return vecteur résultant
 */

myVec operator+(myVec const& v1, myVec const& v2);
/**
 * \fn myVec operator-(myVec const& v1, myVec const& v2)
 * \brief soustraction de vecteurs
 *
 * \param deux vecteurs
 * \return vecteur résultant
 */

myVec operator-(myVec const& v1, myVec const& v2);

/**
 * \fn void normalise(cv::Point& p)
 * \brief normaliser un vecteur ( cv::Point)
 *
 * \param un vecteur passé en paramètre
 * \return rien
 */


 double distancePoints(myVec const& p1, myVec const& p2);

 /**
 * \fn double crossProduct(myVec v1, myVec v2)
 * \brief retourne le produit crosé de deux vecteurs
 *
 * \param deux vecteurs
 * \return lle produit croisé en double flottant
 */

 double crossProduct(myVec v1, myVec v2);

  /**
 * \fn myVec vecteurOrtho(myVec v1, myVec v2)
 * \brief retourne le vecteur orthogonal direct au premier
 *
 * \param dun vecteur
 * \return vecteur orthogonal
 */

myVec vecteurOrtho(myVec v1);


#endif // VEC_H
