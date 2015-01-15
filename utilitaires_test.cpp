#include "utilitaires.h"


using namespace cv;
using namespace std;

///NB : EXPECT_DOUBLE_EQ (expected, actual)



/// test de std::vector<double> solvePoly2(double a, double b, double c)

/// \TODO : faire les tests de la fonction solvePoly2

/// test de bool appartientSegment(myVec pointCible, myVec A, myVec B)

TEST(appartientSegment, test)
{
     srand(time(NULL));
    myVec p1 = myVec(rand()%2000,rand()%2000);
    myVec p1m = p1 * 0.7;
    cout << "##### in TEST appartienSegment : p1 : " << p1.Getx() << " | "<<p1.Gety() << "  cross product : "  << crossProduct(p1 , p1m)<<endl<<endl;
    cout << "##### in TEST appartienSegment : normes  p1 : " << p1.GetNorme() << " | p1m"<<p1m.GetNorme() << endl<<endl;
    EXPECT_TRUE( appartientSegment(p1m, myVec(0,0) , p1));//bon sens et bonne taille de p1
    EXPECT_FALSE(appartientSegment(p1, myVec(0,0), p1m) );// bon sens et mauvaise taille de p1
    p1m *= (-1);
    EXPECT_FALSE(appartientSegment(p1m, myVec(0,0), p1) ); //mauvais sens


}

