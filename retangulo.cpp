#include "retangulo.h"
#include "poligono.h"

Retangulo::Retangulo(float _x, float _y, float largura, float altura){
    Poligono ret;

    Ponto coords[4];

    coords[0].setXY(_x,_y);
    coords[1].setXY(largura,_y);
    coords[2].setXY(largura,altura);
    coords[3].setXY(_x, altura);

//    for(int i=0; i<4; i++){
//        ret = ret + coords[i];
//    }
}
