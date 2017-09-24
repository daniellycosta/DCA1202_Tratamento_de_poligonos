#ifndef POLYGON_H
#define POLYGON_H
#include "ponto.h"
#include<cmath>
#include<iostream>

using namespace std;

class Poligono{
protected:
    Ponto vertices[100];
    int nVertices;
public:
    Poligono();
    void operator+(Ponto _vertice);
    void addVert(Ponto _vertice);
    int numVertices();
    double area();
    void translada(float a, float b);
    void rotaciona(float theta, Ponto p0);
    void imprime();
};

#endif // POLYGON_H
