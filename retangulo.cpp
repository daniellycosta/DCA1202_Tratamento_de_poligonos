#include "retangulo.h"
#include "poligono.h"

Retangulo::Retangulo(float _x, float _y, float largura, float altura){
    Retangulo ret;

    Ponto coords[4];

    coords[0].x = _x;
    coords[0].y = _y;

    coords[1].x = largura;
    coords[1].y = _y;

    coords[2].x = largura;
    coords[2].y = altura;

    coords[3].x = _x;
    coords[3].y = altura;

    for(int i=0, i<4, i++){
        ret += coords[i];
    }
}
