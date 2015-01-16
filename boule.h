/**
*
*   \file boule.h
*   \brief header regroupant la déclaration de la classe boule
*   \author Valentin LIEVIN
*   \date 16 janvier 2015
*
*
*
**/

#include "utilitaires.h"


/*! \class boule
   * \brief classe représentant une boule du jeu
   *
   *
   */

class boule
{
    public:
    /*!
     *  \brief Constructeur
     *  Constructeur de la classe boule
     *  \param aucun
     */
    boule();
    /*!
     *  \brief Constructeur
     *  Constructeur de la classe boule
     *  \param aucun
     */
    boule(myVec c, double r);
    /*!
     *  \brief Destructeur
     *  Constructeur de la classe boule
     *  \param aucun
     */
    ~boule();
    /*!
     *  \brief Getter
     *  renvoi le centre
     *  \param aucun
     */

    myVec GetCentre()const;
     /*!
     *  \brief Getter
     *  renvoi le rayon
     *  \param aucun
     */
    double GetRayon() const;
     /*!
     *  \brief Setter
     *  défini le centre
     *  \param aucun
     */
    void SetCentre(myVec c);
    /*!
     *  \brief Setter
     *  défini le rayon
     *  \param vecteur
     */
    void SetRayon(double r);
    /*!
     *  \brief Afficher la boule
     *  affiche la boule
     *  \param rayon double flottant
     */
    void Afficher(cv::Mat image,cv::Scalar color);
    /*!
     *  \brief Afficher la boule avec une couleur par défaut
     *  affiche la boule
     *  \param image,et une couleur
     */

    void Afficher(cv::Mat image);

    /*!
     *  \brief retourne le vecteur rebond d'une boule sur une bande
     *  retourne le vecteur rebond ainsi que son origine (sol et myVec) / retourne faux s'il n'y a pas d'intersection, vrai sinon
     *  \param v : vecteur directeur de la boule, A : extrêmité du segment, B extrêmité du segment, sol : position du centre lors du rebond, solVec : direction du vecteur rebond lors du rebond
     */

    bool GetIntersectionSegment(myVec v, myVec A , myVec B, myVec &sol , myVec& solVec);

    /*!
     *  \brief retourne la position du centre pour une collision avec une boule
     *  retourne  le centre de la boule (sol ) lors de la collision avec une autre boule  / retourne faux s'il n'y a pas d'intersection, vrai sinon
     *  \param v : vecteur directeur de la boule, B : boule cible, sol : intersection
     */

    bool GetIntersectionBoule(myVec v, boule B, myVec &sol );

    /*!
     *  \brief retourne la position du centre pour une collision avec une boule et son vecteur directeur
     *  retourne  le centre de la boule (sol ) lors de la collision avec une autre boule  ainsi que le vecteur directeur du rebond/ retourne faux s'il n'y a pas d'intersection, vrai sinon
     *  \param v : vecteur directeur de la boule, B : boule cible, sol : intersection; solVec : vecteur directeur du rebond
     */

    bool GetIntersectionBoule(myVec v, boule B, myVec &sol , myVec & solVec);

    private:

    myVec centre;/*!< centre de la boule*/
    double rayon;/*!< rayon de la boule*/

};
