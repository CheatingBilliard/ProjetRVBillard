/**
*
*   \file main.cpp
*   \brief fonction principale du bloc calcul de trajectoire du projet "Tricher au billard Français" pour l'ECN - remise au propre et en utilisant la bibliothèque openCV à partir du projet BoiteAOutilBillard
*   \author Valentin LIEVIN
*   \date 14 janvier 2015
*
*   La classe Point (@opencv) sera utilisé en tant que vecteur
*
**/


#include "utilitaires.h"
#include "affichage.h"
#include "myVec.h"

using namespace std;
using namespace cv;

void MyLine( Mat img, Point start, Point end );
void MyEllipse( Mat img, double angle );
void MyFilledCircle( Mat img, Point center );



int main(int argc, char **argv){

    bool bcontinue = true;

    double offset = 0.1;
    double t = 0;



    while(bcontinue){

    char nomAffichage[] = " Affichage du billard ";

        // on crée une image vide
        Mat image = Mat::zeros( w, w, CV_8UC3 );

//        Point v = Point ( 5.2 , 1 );
//        cout << " v : "<< v.x << " | " << v.y <<endl<<endl;
//
//        AfficherVecteur(image, v , Point(w/2,w/2));

        myVec p = myVec( w/2,w/2);
        myVec v = myVec( cos(t),sin(t));
        cout << " v : "<< v.Getx() << " | " << v.Gety()<< "  norme : "<< v.GetNorme() <<endl<<endl;
        p.AfficherPoint(image);
        //v.AfficherVecteur(image, p);
        v.Normalise();
        cout << " v : "<< v.Getx() << " | " << v.Gety()<< "  norme : "<< v.GetNorme() <<endl<<endl;
        //v*=5;
        v.AfficherVecteur(image, p);
        v*=M_LONG_VECTOR;
        myVec p1 = p+v;
        //p1.AfficherPoint(image);
        myVec v1 = myVec( 5,5);
        v1.Normalise();
        v1.AfficherVecteur(image, p);
        cout << " cross product : " << crossProduct(v,v1) <<endl<<endl;
        cout << " angle : " << angleDirecte(v1,v) <<endl<<endl;

        //test projete
        myVec pt1 = myVec(9*w/12, 3*w/4);
        myVec pt2 = myVec(9*w/13, -3*w/5);
        myVec vt;
        vt = pt2 - pt1;
        vt.AfficherVecteur(image, pt1);
        myVec inter;
        int sens =intersectionVecteurSurDroite(v, p , vt , pt1, inter);
        inter.AfficherPoint(image);
         MyLine( image,  Point(p.Getx(),p.Gety()),   Point(inter.Getx(), inter.Gety()));
        cout << " sens : "<< sens <<endl;




//
//
//        MyLine( atom_image, Point( 0, 0 ), Point( w, 15*w/16 ) );
//        AfficherPoint(atom_image, Point( w/6,w/2) );
//
//        // tracer une ligne
//        //line(atom_image, Point(0,0),Point(w-1,w-1), CV_RGB(255,0,0),3,8);
//
//        AfficherCercle(atom_image, Point(w/2,w/2), CV_RGB(255,0,0), 7, false);
//
        //tracer un polygon
        vector<Point> pv;
        pv.push_back(Point(15,15));
        pv.push_back(Point(w-15,15));
        pv.push_back(Point(w-15,w-15));
        pv.push_back(Point(15,w-15));
        AfficherPolygon(image, pv, Scalar(70,70,70));
//
//        double x1 = cos(t);
//        double y1 = sin(t);
//        Point p1 = Point(x1,y1);
//        cout<< "in main : p1 : " << p1.x<< " | " << p1.y<< " t :  "<<t << " cos & sin  : " << x1 << " | " <<y1 <<endl<<endl;
//        normalise(p1);
//        AfficherVecteur(atom_image, p1, Point(w/2,w/2));
//        cout<< "in main : p1 normalized : " << p1.x<< " | " << p1.y<<endl<<endl;
//        Point p2 = Point(-0.2,-1);
//        normalise(p2);
//        Point p3 = p1-p2;
//        Point inter;
//        int sens = intersectionVecteurSurDroite(p1, Point(w/2,w/2), p2 , Point(4*w/5,3*w/5), inter);
//        AfficherPoint(atom_image, inter);
//
//
//
//        AfficherVecteur(atom_image, p2, Point(4*w/5,3*w/5));
//


        int key = cvWaitKey(0); // capture des événements claviers

        //gestion des événements clavier
        switch(key)
        {
                case(27):
                bcontinue = false;
                break;

                case(56):
                t =  t + offset;
                cout << "in main : interruption clavier : 8 ok" <<endl;
                break;

                case(50):
                t = t - offset;
                break;

        }
        //écriture et affichage de la nouvelle image
        imshow( nomAffichage, image);
        moveWindow( nomAffichage, 1000, 200 );
        system("clear");

    }


::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

void MyLine( Mat img, Point start, Point end )
{
    int thickness = 1;
    int lineType = 8;
    line( img,
    start,
    end,
    Scalar( 0, 255, 0 ),
    thickness,
    lineType );
}

void MyEllipse( Mat img, double angle )
{
    int thickness = 2;
    int lineType = 8;
    ellipse( img,
    Point( w/2, w/2 ),
    Size( w/4, w/16 ),
    angle,
    0,
    360,
    Scalar( 255, 0, 0 ),
    thickness,
    lineType );
}


