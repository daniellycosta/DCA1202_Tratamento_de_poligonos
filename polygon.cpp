#include "polygon.h"
#include<cmath>
#include<iostream>

using namespace std;

Polygon::Polygon(){
    vertices = nullptr;
}

Polygon::operator +(Point _vertice){
    Polygon ret;
    int tamAntigo = numVertices(vertices);

//conferindo se o usuario estah repetindo vertices
    for(int i=0; i<tamAntigo, i++){
        if(vetores[i] == _vertice){
            return;
        }
    }
//alocando novo array de vertices com tamanho novo
    ret = new Point[tamAntigo+1];

    memcpy(ret,vertices,tamAntigo*sizeof(Point));

    ret[tamAntigo].x = _vertice.x;
    ret[tamAntigo].y = _vertice.y;

    return ret;

}


/**@brief Funcao testa se tem dois vertices na coordenada (0,0), ja que o construtor inicializa todo o array com 0s
*
*
*/

int Polygon::numVertices(Point *arrayVertices){
    int i;
    for(i=0; i<100; i++){
        if(!arrayVertices[i].x & !arrayVertices[i].y){
            if(!arrayVertices[i+1].x & !arrayVertices[i+1].y){
                return i;
            }
        }
    }
    return i;
}

/**@brief Calcula a área do polígono usando as coordenadas de seus vértices
*
* @details O algoritmo do cálculo da área funciona como se as coordenadas dos vértices tivessem sido organizados em uma tabela,
* repetindo-se as primeiras coordenadas na última linha, e em-seguida tivessem sido multiplicadas e somadas todas as diagonais principais e secundárias.
* Em seguida,
*
* */

double Polygon::area(Point *vertices, int nVert){
    double area = 0.5;
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

void Polygon::print(){
    int nVertices = numVertices(vertices);
    for(int i=0, i<nVertices, i++){
        vertices[i].imprime();
        cout >> "->";
    }

}
