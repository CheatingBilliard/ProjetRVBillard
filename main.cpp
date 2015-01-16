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
#include "boule.h"

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

//tracer un polygon
        vector<Point> pv;
        int k = 60;
        pv.push_back(Point(k,k));
        pv.push_back(Point(w-k,k));
        pv.push_back(Point(w-k,w-k));
        pv.push_back(Point(k,w-k));

        for(int j=0; j<pv.size(); j++)
        {   int l = j+1;
            if (l == pv.size())
            {l = 0;}
            myVec inter;
            myVec interVec;

            boule b = boule(myVec(w/2,w/2), 30);
            b.Afficher(image);
            bool bbool = b.GetIntersectionSegment(v, myVec(pv[j].x,pv[j].y) ,myVec(pv[l].x,pv[l].y), inter, interVec);
            cout << " bbol : "<< bbool <<endl;

            if(bbool)
            {
                inter.AfficherPoint(image);
                interVec.AfficherVecteur(image, inter);
                boule br = boule(inter,30);
                br.Afficher(image);
            }
        }

        AfficherPolygon(image, pv, Scalar(70,70,70));
        //test projete
        myVec pt1 = myVec(9*w/12, 1*w/5);
        myVec pt2 = myVec(9*w/13, 4*w/5);
        myVec vt;
        vt = pt2 - pt1;
        //vt.AfficherVecteur(image, pt1);
//        myVec inter;
//        myVec interVec;
//        bool sens =intersectionVecteurSurSegment(v, p , pt2 , pt1, inter, interVec);
//        inter.AfficherPoint(image);
//         MyLine( image,  Point(p.Getx(),p.Gety()),   Point(inter.Getx(), inter.Gety()));
//        cout << " sens : "<< sens <<endl;
//        pt1.AfficherPoint(image);
//        pt2.AfficherPoint(image);
//        interVec.AfficherVecteur(image, inter);
//        myVec vOrtho = vecteurOrtho(vt);
        //vOrtho.AfficherVecteur(image, inter);

        //Affichage d'une boule
//        boule b = boule(myVec(w/2,w/2), 30);
//        b.Afficher(image);
//        int bbool = b.GetIntersectionSegment(v, pt2,pt1, inter, interVec);
//        cout << " bbol : "<< bbool <<endl;
//        inter.AfficherPoint(image);
//        interVec.AfficherVecteur(image, inter);
//        if(bbool)
//        {
//            boule br = boule(inter,30);
//            br.Afficher(image);
//        }



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


