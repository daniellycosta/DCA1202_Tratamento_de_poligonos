#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "poligono.h"

class Retangulo: public Poligono {
private:
    Poligono retangulo;
public:
    Retangulo(float _x, float _y, float largura, float altura);
};

#endif // RECTANGLE_H
