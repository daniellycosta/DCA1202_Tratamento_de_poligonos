#include <iostream>
#include<cmath>
#include<ponto.h>
#include<poligono.h>
#include<retangulo.h>

using namespace std;

int main(){
    Retangulo T(0.0,0.0,4.0,3.0);
    Ponto p0;
    p0.setXY(2,1.5);

    cout<<"Num de vertices: " << T.numVertices() << endl;
    T.imprime();

    cout<<"\n";
    cout << "Area: " << T.area() << endl;

    T.translada(-3,4);
    cout << "Area do retangulo transladada: " << T.area() << endl;

    T.rotaciona(30,p0);
    cout << "Area do retangulo rotacionado: " << T.area() << endl;

    return 0;
}
