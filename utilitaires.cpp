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

double angleDirecte(myVec v1, myVec v2 )
{
    v1.Normalise();
    v2.Normalise();

    double alpha = acos(v1*v2);

    if(crossProduct(v1,v2)<0){ alpha = -alpha; }

    return alpha;

}

double distancePointSurDroite(myVec v1, myVec v1or, myVec point)
{
    v1.Normalise();
    myVec Projete = v1or +   v1 * ( ( point - v1or ) * v1 );


    double dist = (Projete - point).GetNorme();

    if ((point - v1or)*v1 < 0) //valeur négative si mauvais sens
    {
    dist = - dist;;
    }
    return dist;
}

///fonctions "haut niveau"

bool appartientSegment(myVec pointCible, myVec A, myVec B){

    myVec v1 ; // vecteur AM
    v1 = pointCible-A;
    myVec v2 ;
    v2 = B-A; //  vecteur AB

    if (crossProduct(v1,v2) ==0 ) // si les vecteur ne sont pas alignés
    {
        if (v1.GetNorme()<v2.GetNorme() && v1*v2 > 0) // si AM < AB et si M est dans le bon sens
        {
            return true;
        }
        else
        {return false;}
    }
    else
    {
    return false;
    }


}

bool intersectionVecteurSurSegment(myVec v1, myVec v1or, myVec A, myVec B, myVec & sol)
{
    myVec v2 = ( B - A);
    myVec v2or = A;
    v1.Normalise();
    v2.Normalise();

    //on détermine le projeté de v1or sur la droite v2
    myVec projete = v2or +   v2 * ( ( v1or - v2or ) * v2 );//projete testé graphiquement

    // on détermine l'angle entre les deux vecteurs
    double alpha = - angleDirecte(v1,v2);

    //calcul de distance entre v1or et le projete

    double dist = (projete - v1or).GetNorme();


    //on place l'intersection

    sol = projete + v2* (dist* tan(alpha+ (M_PI/2))); // testé graphiquement

   //test d'inclusion
  // if(appartientSegment(sol,A,B))
    /// \TODO : corriger la fonction appartienSegment : cette fonction n'est pas stable
    myVec d1 = (sol-A);
    myVec d2 = (B-A);

   if((d1.GetNorme() < d2.GetNorme()) && ((sol-A)*(B-A)) > 0 && ((sol - v1or)*v1)>0)
   {
    return true;
    }
   else
   {return false;}

}


bool intersectionVecteurSurSegment(myVec v1, myVec v1or, myVec A, myVec B, myVec & sol, myVec& solvec)
{
   bool result = intersectionVecteurSurSegment(v1,v1or,A,B,sol);


    myVec v2ortho = vecteurOrtho( (B - A)); // on crée le vecteur orthogonal à v2
    v2ortho.Normalise();




   if(v2ortho * v1 > 0) // on le dirrige vers v1or
   {v2ortho = v2ortho * (-1) ;}


  myVec v2 = (vecteurOrtho(v2ortho));
  v2.Normalise();

   //double alpha = angleDirecte(v1,v2ortho);

  solvec = ( (  ( v2ortho*(v2ortho*v1))*(-1) )+ (v2*(v2*v1)  ) );
   solvec.Normalise();
   return result;

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

