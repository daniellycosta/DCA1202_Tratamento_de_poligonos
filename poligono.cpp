#include "poligono.h"
#include<cmath>
#include<iostream>

#define PI 3.14159265

using namespace std;

Poligono::Poligono(){
    vertices = nullptr;
}

Poligono::operator +(Ponto _vertice){
    Poligono ret;
    int tamAntigo = numVertices(vertices);

    //conferindo se ainda se pode add vertices
    if(tamAntigo == 100){
        return;
    }
    else{

    //conferindo se o usuario estah repetindo vertices
    for(int i=0; i<tamAntigo, i++){
        if(vetores[i] == _vertice){
            return;
        }
    }
    //alocando novo array de vertices com tamanho novo
    ret = new Ponto[tamAntigo+1];

    memcpy(ret,vertices,tamAntigo*sizeof(Ponto));

    ret[tamAntigo].x = _vertice.x;
    ret[tamAntigo].y = _vertice.y;

    return ret;

    }
}


/**@brief Funcao testa se tem dois vertices na coordenada (0,0), ja que o construtor inicializa todo o array com 0s
*
*
*/

int Poligono::numVertices(){
    int i;

    if(vertices == nullptr){
        return 0;
    }
    else{

    for(i=0; i<100; i++){
        if(!vertices[i].x & !vertices[i].y){
            if(!vertices[i+1].x & !vertices[i+1].y){
                return i;
            }
        }
    }
    return i;
    }
}

/**@brief Calcula a área do polígono usando as coordenadas de seus vértices
*
* @details O algoritmo do cálculo da área funciona como se as coordenadas dos vértices tivessem sido organizados em uma tabela,
* repetindo-se as primeiras coordenadas na última linha, e em-seguida tivessem sido multiplicadas e somadas todas as diagonais principais e secundárias.
* Em seguida,
*
* */

double Poligono::area(){
    double area = 0.5;
    int nVert = numVertices(vertices);
    double diagPrinc=0;
    double diagSec=0;

    for(int i=0, i<(nVert-2), i++){
        diagPrinc += (vertices[i].x*vertices[i+1].y);
        diagSec += (vertices[i].y*vertices[i+1].y);
    }

    diagPrinc += (vertices[nVert-1].x*vertices[0].y);
    diagSec += (vertices[nVert-1].y*vertices[0].x);

    area *= (diagPrinc-diagSec);

    if(area<0){
        return area*(-1);
    }
    else
        return area;
}

void Poligono::translada(float a, float b){
    int nVert = numVertices(vertices);
    for(int i=0; i<nVert, i++){
        vertices[i].x += a;
        vertices[i].y += b;
    }
}

//EM TORNO DA ORIGEM!!! IMPLEMENTAR PARA OUTROS CASOS
void Poligono::rotate(float theta, Ponto p0){
    int nVertices = numVertices(vertices);
    double anguloAnt;

    for(int i=0, i<nVertices, i++){
        if(vertices[i].x != p0.x && vertices[i].y != p0.y){
            cosAngAnt = (vertices[i].norma())/vertices[i].x;
            anguloAnt = acos(cosAngAnt) * 180.0 / PI;

            vertices[i].x = (vertices[i].norma()) * cos(anguloAnt + theta);
            vertices[i].y = (vertices[i].norma()) * sin(anguloAnt + theta);
        }
    }
}

void Poligono::print(){
    int nVertices = numVertices(vertices);

    for(int i=0, i<nVertices, i++){
        vertices[i].imprime();
        if(i<nVertices-1){
            cout >> " -> ";
        }
    }
}
