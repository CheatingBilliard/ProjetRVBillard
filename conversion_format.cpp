/**
 * \file conversion_format.cpp
 * \brief programmes de conversion des types
 * \author Quentin.T
 * \version 0.1
 * \date 13 janvier 2015
 *
 * Partie dédiée aux différentes fonctions de conversions des types de données utilisés par le reste des programmes
 *
 */

#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "conversion_format.h"
#include "structures.h"

using namespace std;
using namespace cv;

string int2string(int a){
    string s;
    ostringstream convert;
    convert << a;
    s = convert.str();
    return s;
}

string point2string(Point point){
    string s;
    int a = point.x;
    int b = point.y;
    string sa = int2string(a);
    string sb = int2string(b);
    ostringstream convert;
    convert << " (" << sa << ";"<< sb<< ") ";
    s = convert.str();
    return s;
}

position point2position(Point point){
    position _position;
    _position.x = point.x;
    _position.y = point.y;
    return _position;
}

