#include "retangulo.h"
#include "poligono.h"
#include "ponto.h"
#include<cmath>
#include<iostream>

using namespace std;

Retangulo::Retangulo(float _x, float _y, float largura, float altura){

    Ponto coords[4];

    coords[0].setXY(_x, _y);
    coords[1].setXY(_x,(_y-altura));
    coords[2].setXY((_x+largura),(_y-altura));
    coords[3].setXY((_x+largura), _y);

    for(int i=0;i<4;i++){
        retangulo+coords[i];
    }
    retangulo.imprime();
    cout <<"eh pra aparecer 4: " << retangulo.numVertices() <<"\n\n"<<retangulo.area()<<"\n";

}
