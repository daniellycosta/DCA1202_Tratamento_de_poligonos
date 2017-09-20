#include "poligono.h"
#include<cmath>
#include<iostream>

#define PI 3.14159265

using namespace std;

Poligono::Poligono(){

    vertices = nullptr;

    /*vertices = new Ponto[100];

    for(int i=0; i<100; i++){
        vertices[i].setXY(0.0,0.0);
    }*/
}

Poligono::~Poligono(){
    cout<<"[POL]Destruindo poligono...\n";
    delete[]vertices;
}

//Poligono Poligono::operator =(Poligono _poligono){
//    if(vertices != nullptr){
//        for(int i=0; i<numVertices(); i++){
//            _poligono[i]->setXY(vertices[i].getX(), vertices[i].getY());
//        }
//    }
//    return _poligono;
//}


//Poligono Poligono::operator+(Ponto _vertice){
//    Poligono ret;
//    int tamAntigo = numVertices();

//    //conferindo se ainda se pode add vertices

//    if(tamAntigo == 100){
//        cout << "[POL] Erro! Poligono com tamanho max\n";
//        return *this;
//    }

//    else{

//        //conferindo se o usuario estah repetindo vertices

//        for(int i=0; i<tamAntigo; i++){
//            if(vertices[i].getX() == _vertice.getX() && vertices[i].getY() == _vertice.getY()){
//                cout << "[POL] Erro! Poligono com vertices repetidos\n";
//                return *this;
//            }
//        }

//        //alocando novo array de vertices com tamanho novo

//        ret = new Poligono[tamAntigo+1];
//        memcpy(ret,vertices,tamAntigo*sizeof(Ponto));

//        for(int i=0; i<tamAntigo; i++){
//            ret[i].setXY(vertices[i].getX(), vertices[i].getY());
//        }
//        ret = vertices;
//        ret[tamAntigo].setXY(_vertice.getX(),_vertice.getY());
//        return ret;
//    }
//}


/**@brief Funcao testa se tem dois vertices na coordenada (0,0), ja que o construtor inicializa todo o array com 0s
*
*
*/

int Poligono::numVertices(){
    int i;

    for(i=0; i<100; i++){
        if(i<99 && !vertices[i].getX() && !vertices[i].getY()){
            if(!vertices[i+1].getX() && !vertices[i+1].getY()){
                return i;
            }
        }
    }
    return i+1;
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
    double area = 0.5;
    int nVert = numVertices();
    double diagPrinc=0;
    double diagSec=0;

    for(int i=0; i<(nVert-2); i++){
        diagPrinc += (vertices[i].getX()*vertices[i+1].getY());
        diagSec += (vertices[i].getY()*vertices[i+1].getX());
    }

    diagPrinc += (vertices[nVert-1].getX()*vertices[0].getY());
    diagSec += (vertices[nVert-1].getY()*vertices[0].getX());

    area *= (diagPrinc-diagSec);

    if(area<0){
        return area*(-1);
    }
    else
        return area;
}

void Poligono::translada(float a, float b){
    int nVert = numVertices();
    for(int i=0; i<nVert; i++){
        vertices[i].translada(a,b);
        //vertices[i].x += a;
        //vertices[i].y += b;
    }
}

//EM TORNO DA ORIGEM. TRANSLADA PARA O P0 FICAR NA ORIGEM, ROTACIONA E TRANSLADA
void Poligono::rotate(float theta, Ponto p0){
    int nVertices = numVertices();
    double anguloAnt, cosAngAnt;

    for(int i=0; i<nVertices; i++){

        vertices[i].translada(-p0.getX(), -p0.getY());

        if(!vertices[i].getX() && !vertices[i].getY()){
            cosAngAnt = (vertices[i].norma())/vertices[i].getX();
            anguloAnt = acos(cosAngAnt) * 180.0 / PI;

            vertices[i].setX((vertices[i].norma()) * cos(anguloAnt + theta));
            vertices[i].setY((vertices[i].norma()) * sin(anguloAnt + theta));
        }

        vertices[i].translada(p0.getX(), p0.getY());
    }
}

void Poligono::print(){
    int nVertices = numVertices();

    for(int i=0; i<nVertices; i++){
        vertices[i].imprime();
        if(i<nVertices-1){
            cout << " -> ";
        }
    }
}
