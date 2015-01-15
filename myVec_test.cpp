#include "myVec.h"

/// test de void normalise(cv::Point& p)

TEST(myVec, normalise)
{
   for(int i = 0;i<10; i++)
   {
   // test d'égalité à 1
        srand(time(NULL));
        float x = rand();
        float y = rand();
        myVec p = myVec(x,y);
        p.Normalise();
        EXPECT_DOUBLE_EQ(1,p.GetNorme()); //permet de préciser qu'il s'agit de nombres flottants
    }
}



/// Test de cv::Point operator*(cv::Point const& v1, float const& alpha)

TEST(MultiplicationFacteurVecteur, simpleTest){

    srand(time(NULL));
    float x = rand();
    float y = rand();
    myVec p = myVec(x,y);

    EXPECT_TRUE( myVec(0,0) == p*0);
    float k = rand()%1;
    EXPECT_TRUE( myVec(k, k) ==  myVec(1,1) *k );

}


///Test de float operator*(cv::Point const& v1, cv::Point const& v2)

TEST(dotProduct, orthogonalite) {

    float ps = myVec(0,1)*myVec(1,0);

    srand(time(NULL));

  EXPECT_EQ(0, ps);
  EXPECT_EQ(0, myVec(0,1)*myVec(-1,0));
  EXPECT_EQ(0, myVec(sqrt(2)/2,sqrt(2)/2)*myVec(- sqrt(2)/2,sqrt(2)/2));

  double x = rand();
  double y = rand();
  myVec p = myVec(x,y);
  EXPECT_EQ(0, p*myVec(-p.Gety() ,p.Getx() ));
}

TEST(dotProduct, symmetrie)
{
    srand(time(NULL));

    myVec p1 = myVec(rand(),rand());
    myVec p2 = myVec(rand(),rand());
    EXPECT_EQ(p1*p2, p2*p1);
}

TEST(dotProduct, definiPositif)
{
    srand(time(NULL));

    myVec p1 = myVec(rand()%2000,rand()%2000);
    myVec p2;
    p2 *= (rand()%1);
    EXPECT_TRUE(p1*p2>=0);
    p2 *= -1;
    EXPECT_TRUE(p1*p2<=0);
    EXPECT_TRUE(p1*myVec(0,0) == 0);
}




///test de double distance(cv::Point const p1, cv::Point const p2)

TEST(distancePoints, symetrie){
    srand(time(NULL));

    myVec p1 = myVec(rand(),rand());
    myVec p2 = myVec(rand(),rand());
    double d1 = distancePoints(p1,p2);
    double d2 = distancePoints(p2,p1);

    EXPECT_DOUBLE_EQ(d1,d2);

}

TEST(distancePoints, definiPositif){
    srand(time(NULL));

    myVec  p1 = myVec(rand(),rand());
    myVec p2 = myVec(rand(),rand());
    double d1 = distancePoints(p1,p2);
    double d2 = distancePoints(p2,p1);
    double d = distancePoints(p1,p1);
    EXPECT_TRUE(d1>=0);
    EXPECT_DOUBLE_EQ(0,d);

}

TEST(crossProduct , zero)
{
    srand(time(NULL));

    myVec p1 = myVec(rand()%2000,rand()%2000);
    EXPECT_DOUBLE_EQ(0, crossProduct(p1, p1*45));
    EXPECT_DOUBLE_EQ(0, crossProduct(p1, p1*(-45)));
    myVec p2 = myVec(rand(),rand()+1);

    if(crossProduct(p1,p2)!=0)
    EXPECT_TRUE(0 != crossProduct(p1, p2));

}

TEST(vecteurOrtho, orthogonal )
{
    srand(time(NULL));
    myVec p1 = myVec(rand()%2000,rand()%2000);
    myVec p2 = vecteurOrtho(p1);
    EXPECT_DOUBLE_EQ(0, p1*p2);
}



