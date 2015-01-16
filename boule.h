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
     *  \param aucun
     */
    void SetRayon(double r);
    /*!
     *  \brief Afficher la boule
     *  affiche la boule
     *  \param aucun
     */
    void Afficher(cv::Mat image,cv::Scalar color);
    /*!
     *  \brief Afficher la boule avec une couleur par défaut
     *  affiche la boule
     *  \param aucun
     */

    void Afficher(cv::Mat image);

    bool GetIntersectionSegment(myVec v, myVec A , myVec B, myVec &sol , myVec& solVec);

    private:

    myVec centre;/*!< centre de la boule*/
    double rayon;/*!< rayon de la boule*/

};
