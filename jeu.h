/**
*
*   \jeu.h
*   \brief header regroupant la déclaration de la classe jeu
*   \author Valentin LIEVIN
*   \date 16 janvier 2015
*
*
*
**/

#include "utilitaires.h"
#include "boule.h"
#include "trajectoire.h"

/*! \class jeu
   * \brief classe regroupant l'ensemble des éléments du : cadre + boules
   *
   *
   */

   class jeu
   {
    public:

    jeu();
    jeu(cadre cad, std::vector<boule> bou);
    ~jeu();
     /*!
     *  \brief renvoi l'indice de la boule selectionnée, -1 si c'est impossible
     *
     *  \param myVec : vecteur directeur, myVec vor : origine du vecteur
     */
    int GetSelected(myVec v, myVec vor);
        /*!
     *  \brief affiche le jeu en maintant en évidence la boule visée s'il y en a une
     *
     *  \param image sur laquelle la fonction écrit
     */
    void Afficher(cv::Mat image);

       /*!
     *  \brief retourne la trajectoire définie par v et la boule selectionnée (voir GetSelect)
     *
     *  \param myVec : Vecteur directeur, myVec vor: origine du vecteur
     */
    bool GetTrajectoire( myVec v, myVec vor,int nbRebond ,trajectoire & traj );

    private:
    cadre c;
    std::vector<boule> b;
    int selected;


   };
