#include "polygon.h"
#include<cmath>
#include<iostream>

using namespace std;

Polygon::Polygon(){

}
//Calcula a área do polígono usando suas coordenadas
double Polygon::area(Point *vertices, int nVert){
    double area = 0.5;
    double diagPrinc=0;
    double diagSec=0;

    for(int i=0, i<(nVert-2), i++){
        diagPrinc += (vertices[i].getX()*vertices[i+1].getY());
        diagSec += (vertices[i].getY()*vertices[i+1].getX());
    }

    diagPrinc += (vertices[nVert-1].getX()*vertices[0].getY());
    diagSec += (vertices[nVert-1].getY()*vertices[0].getX());

    area *= (diagPrinc-diagSec);

    if(area<0){
        return area*(-1);
    }
    else
    return area;
}
