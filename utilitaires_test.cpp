#include "utilitaires.h"


using namespace cv;
using namespace std;

///NB : EXPECT_DOUBLE_EQ (expected, actual)



/// Test de cv::Point operator*(cv::Point const& v1, float const& alpha)

TEST(MultiplicationFacteurVecteur, simpleTest){

    srand(time(NULL));
    float x = rand();
    float y = rand();
    Point p = Point(x,y);

    EXPECT_TRUE( Point(0,0) == 0*p);
    float k = rand()%1;
    EXPECT_TRUE( Point(k, k) == k* Point(1,1) );

}


///Test de float operator*(cv::Point const& v1, cv::Point const& v2)

TEST(dotProduct, orthogonalite) {

    float ps = Point(0,1)*Point(1,0);

    srand(time(NULL));

  EXPECT_EQ(0, ps);
  EXPECT_EQ(0, Point(0,1)*Point(-1,0));
  EXPECT_EQ(0, Point(sqrt(2)/2,sqrt(2)/2)*Point(- sqrt(2)/2,sqrt(2)/2));

  float x = rand();
  float y = rand();
  Point p = Point(x,y);
  EXPECT_EQ(0, p*Point(-p.y,p.x));
}

TEST(dotProduct, symmetrie)
{
    srand(time(NULL));

    Point p1 = Point(rand(),rand());
    Point p2 = Point(rand(),rand());
    EXPECT_EQ(p1*p2, p2*p1);
}

TEST(dotProduct, definiPositif)
{
    srand(time(NULL));

    Point p1 = Point(rand(),rand());
    Point p2 = (rand()%1)*p2;
    EXPECT_TRUE(p1*p2>=0);
    p2 = -p2;
    EXPECT_TRUE(p1*p2<=0);
    EXPECT_TRUE(p1*Point(0,0) == 0);
}


/// test de void normalise(cv::Point& p)

TEST(normalise, egalUn){
   for(int i = 0;i<10; i++)
   {
        srand(time(NULL));
        float x = rand();
        float y = rand();
        Point p = Point(x,y);
        normalise(p);
        EXPECT_DOUBLE_EQ(1,norm(p)); //permet de préciser qu'il s'agit de nombres flottants
    }
}

///test de double distance(cv::Point const p1, cv::Point const p2)

TEST(distancePoints, symetrie){
    srand(time(NULL));

    Point p1 = Point(rand(),rand());
    Point p2 = Point(rand(),rand());
    double d1 = distancePoints(p1,p2);
    double d2 = distancePoints(p2,p1);

    EXPECT_DOUBLE_EQ(d1,d2);

}

TEST(distancePoints, definiPositif){
    srand(time(NULL));

    Point p1 = Point(rand(),rand());
    Point p2 = Point(rand(),rand());
    double d1 = distancePoints(p1,p2);
    double d2 = distancePoints(p2,p1);
    double d = distancePoints(p1,p1);
    EXPECT_TRUE(d1>=0);
    EXPECT_DOUBLE_EQ(0,d);

}

/// test de std::vector<double> solvePoly2(double a, double b, double c)

/// \TODO : faire les tests de la fonction solvePoly2


/// test de double crossProduct(cv::Point v1, cv::Point v2)

TEST(crossProduct , zero)
{
    srand(time(NULL));

    Point p1 = Point(rand(),rand());
    EXPECT_DOUBLE_EQ(0, crossProduct(p1, 45*p1));

}

