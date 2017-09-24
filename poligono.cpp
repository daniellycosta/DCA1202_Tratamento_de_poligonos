#include "poligono.h"
#include<cmath>
#include<iostream>

#define PI 3.14159265

using namespace std;

Poligono::Poligono(){
    nVertices = 0;
    for(int i=0; i<100; i++){
        vertices[i].setXY(0.0,0.0);
    }
}

void Poligono::operator+(Ponto _vertice){

    int tamAntigo = nVertices;

    if(tamAntigo == 100){
        cout << "[POL] Erro! Poligono com tamanho max\n";
        return;
    }
    else{
        for(int i=0;i<tamAntigo;i++){
            if(vertices[i].getX() == _vertice.getX() && vertices[i].getY() == _vertice.getY()){
                cout << "[POL] Erro! Poligono jah possui esse ponto\n";
                return;
            }
        }
        vertices[tamAntigo].setXY(_vertice.getX(),_vertice.getY());
        nVertices++;
    }
}

void Poligono::addVert(Ponto _vertice){
    int tamAntigo = nVertices;

    if(tamAntigo == 100){
        cout << "[POL] Erro! Poligono com tamanho max\n";
        return;
    }
    else{
        for(int i=0;i<tamAntigo;i++){
            if(vertices[i].getX() == _vertice.getX() && vertices[i].getY() == _vertice.getY()){
                cout << "[POL] Erro! Poligono jah possui esse ponto\n";
                return;
            }
        }
        vertices[tamAntigo].setXY(_vertice.getX(),_vertice.getY());
        nVertices++;
    }
}



/**@brief Funcao retorna o numero de vertices
*
*
*/

int Poligono::numVertices(){

    return nVertices;

}

/**@brief Calcula a área do polígono usando as coordenadas de seus vértices
*
* @details O algoritmo do cálculo da área funciona como se as coordenadas dos vértices tivessem sido organizados em uma tabela (Tabela 1)
* repetindo-se as primeiras coordenadas na última linha, e em-seguida tivessem sido multiplicadas e somadas todas as diagonais principais e secundárias.
* Em seguida,
* @htmlonly
* <script type="text/javascript" async
* src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.2/MathJax.js?config=TeX-MML-AM_CHTML">
* </script>
* <body>
* TESTE DE ADIÇÃO DE FUNÇÃO: When $a \ne 0$, there are two solutions to \(ax^2 + bx + c = 0\) and they are
* $$x = {-b \pm \sqrt{b^2-4ac} \over 2a}.$$
</body>
* @endhtmlonly
*
* */

double Poligono::area(){
    double area;
    double diagPrinc=0;
    double diagSec=0;

    for(int i=0; i<(nVertices-1); i++){
        diagPrinc += (vertices[i].getX()*vertices[i+1].getY());
        diagSec += (vertices[i].getY()*vertices[i+1].getX());
    }
    diagPrinc += (vertices[nVertices-1].getX()*vertices[0].getY());
    diagSec += (vertices[nVertices-1].getY()*vertices[0].getX());

    area = 0.5*(diagPrinc-diagSec);

    return abs(area);
}

void Poligono::translada(float a, float b){
    for(int i=0; i<nVertices; i++){
        vertices[i].translada(a,b);
    }
}

//EM TORNO DA ORIGEM. TRANSLADA PARA O P0 FICAR NA ORIGEM, ROTACIONA E TRANSLADA
void Poligono::rotaciona(float theta, Ponto p0){
    float angRad = theta * 180.0 / PI;
    float novoX,novoY;

    for(int i=0;i<nVertices;i++){
        vertices[i].translada(-p0.getX(),-p0.getY());

        novoX = vertices[i].getX()*cos(angRad) - vertices[i].getY()*sin(angRad);
        novoY = vertices[i].getX()*sin(angRad) + vertices[i].getY()*cos(angRad);

        vertices[i].setXY(novoX,novoY);

        vertices[i].translada(p0.getX(),p0.getY());
    }
}

void Poligono::imprime(){
    if(nVertices<3){
        cout<<"[POL] Erro! Poligono com numero de vertices invalido\n";
        return;
    }

    for(int i=0; i<nVertices; i++){
        vertices[i].imprime();
        if(i<nVertices){
            cout << " -> ";
        }
    }
    vertices[0].imprime();
    cout<<endl;
}


