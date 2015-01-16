#include "affichage.h"

using namespace std;
using namespace cv;


void MyLine( Mat img, Point start, Point end, Scalar color )
{
    int lineType = 8;
    line( img,
    start,
    end,
    color,
    M_THICKNESS ,
    lineType );
}


void AfficherCercle( cv::Mat img, cv::Point center, cv::Scalar color, float rayon, bool plein )
{
    int thickness;
    if(plein)
    { thickness= -1;} // figure pleine}
    else
    {thickness = M_THICKNESS;}
    int lineType = 8;


    circle( img,center,rayon,color,thickness,lineType );
}


void AfficherPointcv(cv::Mat img, cv::Point p){
//utilisation de la fonction affichercercle

AfficherCercle( img, p , CV_RGB(255,80, 0), M_TAILLE_POINT, true);

}


void AfficherPolygon( cv::Mat img, std::vector<cv::Point> p, cv::Scalar color)
{
      for (int i = 0; i<p.size(); i ++){

            int l = i+1; //permet de prendre en compte la fermeture du polygone sans sortir du vecteur
            if (l == p.size())
                {l=0;}

            line(img, p[i],p[l], color ,M_THICKNESS,8); // utilisation de la fonction cv::Line
      }

 }

 void AfficherVecteurcv(cv::Mat img, cv::Point direction, cv::Point origine){

     Scalar bleu = Scalar(200, 35, 0); // définit la couleur d'un vecteur : bleu

     // on trace la ligne représentant le corps du vecteur

     line(img, origine,origine+ M_LONG_VECTOR * direction, bleu ,M_THICKNESS,8);

     //on trace la tête du vecteur à l'aide d'un polygone plein

     Point directionOrtho(- direction.y ,direction.x );
     //taille de la tête de la flèche : longueur : L en pixel
     float L = 5;
     vector<Point> tete;
     tete.push_back(origine+ M_LONG_VECTOR *direction);// on rentre l'extrêmité de la flèche
     tete.push_back( origine+M_LONG_VECTOR * direction - (L * direction) + (L/4) * directionOrtho);
     tete.push_back( tete[1] - (L/2)* directionOrtho);

     AfficherPolygon(img, tete, bleu);

 }
