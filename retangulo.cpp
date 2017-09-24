#include "retangulo.h"
#include "poligono.h"
#include "ponto.h"
#include<cmath>
#include<iostream>

using namespace std;

/**@brief Contrutor do polígono do tipo retangulo
 * @details Atribui as coordenadas dos vértices do retângulo criado utilizando os
 * parâmetros passados pelo usuário.
 *  A atribuição inicia-se com o ponto superior esquerdo, que recebe as coordenadas x e y passadas. Já
 * as demais, são definidas utilizando-se a largura e altura fornecida, lembrando que todos os vértices dos polígonos
 * são alocados considerando-se o sentido anti-horário.
 */
Retangulo::Retangulo(float _x, float _y, float largura, float altura){
    Ponto coords[4];

    coords[0].setXY(_x, _y);
    coords[1].setXY(_x,(_y-altura));
    coords[2].setXY((_x+largura),(_y-altura));
    coords[3].setXY((_x+largura), _y);

    for(int i=0;i<4;i++){
        addVert(coords[i]);
    }
}
