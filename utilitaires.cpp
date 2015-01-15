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





myVec operator*(myVec const& v1, float const& alpha)
{
    return myVec(v1.Getx()*alpha, v1.Gety()*alpha);
}

double operator*(myVec const& v1,myVec const& v2)
{
    double dot = v1.Getx() *v2.Getx() + v1.Gety()*v2.Gety(); // calcul le produit scalaire de deux vecteur
    return dot;
}

myVec operator+(myVec const& v1, myVec const& v2)
{
    myVec result = myVec( v1.Getx() + v2.Getx() , v1.Gety() + v2.Gety() );
    return result;
}

myVec operator-(myVec const& v1, myVec const& v2)
{
    myVec result = myVec( v1.Getx() - v2.Getx() , v1.Gety() - v2.Gety() );
    return result;
}

void normalise(cv::Point& p){ ///T \TOTO : surveiller la fonction normaliser : retourne une norme supérieur à 1 dans des cas inexpliqués..


        double norme = norm(p); //utilisation de la fonction norm() de OpenCV
        if (norme!=0)
        {
            p.x = (1/norme)*p.x;
            p.y = (1/norme)*p.y;
        }
        else
        cerr<< "###in normalise : division par zero"<<endl<<endl;
}

 double distancePoints(myVec const& p1, myVec const& p2)
 {
    myVec result ;
    result = p1-p2;
    return result.GetNorme();
 }

 double crossProduct(myVec v1, myVec v2)
 {
    return v1.Getx()*v2.Gety() - v1.Gety()*v2.Getx();
 }


std::vector<double> solvePoly2(double a, double b, double c){

	std::vector<double> result;
	result.clear();

	double delta = b*b - 4 * a*c;

	if (a != 0) // si le polynome est de degré 2
	{

		if (delta < 0)
		{
			return result; // retourne un vecteur nul (pas de solutions)
		}
		else if (delta == 0)
		{
			double tmp = -b / ( 2 * a);
			result.push_back(tmp);
			return result;
		}
		else
		{
			double tmp = (-b + sqrt(delta)) / (2 * a);
			result.push_back(tmp);
			tmp = (- b - sqrt(delta)) / (2 * a);
			result.push_back(tmp);

			return result;
		}

	}
	else // a = 0
		if (b == 0)
			return result;
		else
		{
			result.push_back((-c) / b);
			return result ;
		}
}

/*
int intersectionVecteurSurDroite(cv::Point v1, cv::Point v1or, cv::Point v2, cv::Point v2or, cv::Point& sol){


    if(v1 == Point(0,0) || v2 == Point(0,0))
    {cout<< " intersectionVecteurSurDroite : vecteur nul "<<endl<<endl;}

	if (crossProduct(v1, v2) == 0) // on exclut le cas où il n'y a pas de solution : vecteur colinéaires (inclus le vecteur nul)
		return 0;
	else
	{
		/*
		On pose l'égalité :
		|	Ax+t1*v1x = Bx+t2*v2x = xsol
		|	Ay+t1*v1y = By+t2*v2y = ysol
		*/
/*
        ///on normalise v1 et v2
        normalise(v1);
        normalise(v2);

		float t1 = 0;
		float t2 = 0;


		if (v1.x != 0 && v1.y!=0 && v2.x != 0 && v2.y !=0)
		{
			float k = v2.x / v2.y;

			t1 = 1 / (v1.x - k * v1.y) * (v2.x - v1.x + k * (v1.y - v2.y)); //le diviseur est différent de zéro car les droites sont non colinéraires
			t2 = (1 / v2.x)*(v1or.x + t1* v1.x - v2or.x);
		}

		else if (v1.x == 0) //v2x !0 car ils seraient colinéaires (test OK)
		{
			t2 = 1 / v2.x * (v1or.x + t1 * v1.x - v2or.x);
			t1 = 1 / v1.y * (v2or.y - v1or.y + t2* v2.y);
			//debug
			//std::cout << "cas 2" << std::endl;
			//std::cout << v2->getydir() << std::endl;
		}
		else if (v1.y == 0) // par symmétrie (réaliser des tests)
		{
			t2 = 1 / v2.y * (v1or.y + t1* v1.y - v2or.y);
			t1 = 1 / v1.x * (v2or.x - v1or.x + t2*v2.x);
			//debug
			//std::cout << "cas 3" << std::endl;

		}
		else if (v2.y == 0) // par symmétrie (réaliser des tests)
		{
			t1 = 1 / v1.y * (v1or.y + t2* v2.x - v2or.y);
			t2 = 1 / v2.x * (v2or.x - v1or.x + t1*v2.x);
			//debug
			//std::cout << "cas 4" << std::endl;
		}
		else if (v2.x == 0) // par symmétrie (réaliser des tests)
		{
			t1 = 1 / v1.x * (v1or.x + t2* v2.y - v2or.x);
			t2 = 1 / v2.y * (v2or.y - v1or.y + t1*v2.y);
			//debug
			//std::cout << "cas 5" << std::endl;
		}


	// résultats
		sol.x = v1or.x + t1 * v1.x;
		sol.y = v1or.y + t1 * v1.y;

	if (t1 >= 0)
		return 1;
	else
		return -1;
	}


}
*/

