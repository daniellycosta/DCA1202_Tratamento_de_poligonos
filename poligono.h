#ifndef POLYGON_H
#define POLYGON_H
#include "ponto.h"
#include<cmath>
#include<iostream>

using namespace std;

class Poligono : public Ponto{
private:
    Ponto* vertices;
public:
    Poligono();
    ~Poligono();
    Poligono operator =(Poligono _poligono);
    Poligono operator+(Ponto _vertice);
    int numVertices();
    double area();
    void translada(float a, float b);
    void rotate(float theta, Ponto p0);
    void print();
};

#endif // POLYGON_H
