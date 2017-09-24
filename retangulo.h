#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "poligono.h"
#include<cmath>
#include<iostream>

using namespace std;

class Retangulo: public Poligono {

public:
    Retangulo(float _x, float _y, float largura, float altura);
};

#endif // RECTANGLE_H
