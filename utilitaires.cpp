/**
*
*   \file utilitaires.cpp
*   \brief fichier source regroupant des fonctions utiles ainsi que l'inclusion des bibliothèques nécessaires au projet
*   \author Valentin LIEVIN
*   \date 15 janvier 2015
*
*
*
**/

#include "utilitaires.h"

using namespace cv;
using namespace std;



cv::Point operator*(cv::Point const& v1, float const& alpha)
{
    return Point(v1.x*alpha, v1.y*alpha);
}

float operator*(cv::Point const& v1, cv::Point const& v2)
{
    float dot = v1.x*v2.x + v1.y*v2.y; // calcul le produit scalaire de deux vecteur
    return dot;
}


/*
int intersectionVecteurSurDroite(cv::Point v1, cv::Point orv1, cv::Point v2, cv::Point orv2, cv::Point& sol){




	if (produitVectoriel(v1, v2) == 0) // on exclut le cas où il n'y a pas de solution : vecteur colinéaires (inclus le vecteur nul)
		return 0;
	else
	{
		/*
		On pose l'égalité :
		|	Ax+t1*v1x = Bx+t2*v2x = xsol
		|	Ay+t1*v1y = By+t2*v2y = ysol
		*/
/*

		float t1 = 0;
		float t2 = 0;

		if (v1->getxdir() != 0 && v2->getxdir() != 0 && v1->getydir() != 0 && v2->getydir()) {

			float k = v2->getxdir() / v2->getydir();

			t1 = (1 / (v1->getxdir() - k * v1->getydir())) * (v2->getorigin().x - v1->getorigin().x + k * (v1->getorigin().y - v2->getorigin().y)); //le diviseur est différent de zéro car les droites sont non colinéraires
			t2 = 1 / (v2->getxdir())*(v1->getorigin().x + t1* v1->getxdir() - v2->getorigin().x);

			//debug
			//std::cout << "cas 1" << std::endl;

		}

		else if (v1->getxdir() == 0) //v2x !0 car ils seraient colinéaires (test OK)
		{
			t2 = 1 / v2->getxdir() * (v1->getorigin().x + t1 * v1->getxdir() - v2->getorigin().x);
			t1 = 1 / v1->getydir() * (v2->getorigin().y - v1->getorigin().y + t2* v2->getydir());
			//debug
			//std::cout << "cas 2" << std::endl;
			//std::cout << v2->getydir() << std::endl;
		}
		else if (v1->getydir() == 0) // par symmétrie (réaliser des tests)
		{
			t2 = 1 / v2->getydir() * (v1->getorigin().y + t1* v1->getydir() - v2->getorigin().y);
			t1 = 1 / v1->getxdir() * (v2->getorigin().x - v1->getorigin().x + t2*v2->getxdir());
			//debug
			//std::cout << "cas 3" << std::endl;

		}
		else if (v2->getydir() == 0) // par symmétrie (réaliser des tests)
		{
			t1 = 1 / v1->getydir() * (v1->getorigin().y + t2* v2->getxdir() - v2->getorigin().y);
			t2 = 1 / v2->getxdir() * (v2->getorigin().x - v1->getorigin().x + t1*v2->getxdir());
			//debug
			//std::cout << "cas 4" << std::endl;
		}
		else if (v2->getxdir() == 0) // par symmétrie (réaliser des tests)
		{
			t1 = 1 / v1->getxdir() * (v1->getorigin().x + t2* v2->getydir() - v2->getorigin().x);
			t2 = 1 / v2->getydir() * (v2->getorigin().y - v1->getorigin().y + t1*v2->getydir());
			//debug
			//std::cout << "cas 5" << std::endl;
		}


	// résultats
		sol.x = v1->getorigin().x + t1 * v1->getxdir();
		sol.y = v1->getorigin().y + t1 * v1->getydir();

	if (t1 >= 0)
		return 1;
	else
		return -1;
	}


}

*/
