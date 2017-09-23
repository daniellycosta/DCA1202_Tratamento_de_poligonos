#include <iostream>
#include<cmath>
#include<ponto.h>
#include<poligono.h>
#include<retangulo.h>

using namespace std;

int main(){
//Poligono P;
//Ponto coords[4];

//coords[0].setXY(0.0,0.0);
//coords[1].setXY(4.0,0.0);
//coords[2].setXY(4.0,3.0);
//coords[3].setXY(0.0, 3.0);

//for(int i=0;i<4;i++){
//    //retangulo.addVertice(coords[i]);
//    P+coords[i];
//}

/*cout<<"qtd de vertices: " << P.numVertices() << "\n" << "area: " << P.area()<<"\n";
P.imprime()*/;


    Retangulo T(0.0,0.0,4.0,3.0);
    Ponto p0;
    p0.setXY(2,1.5);

    cout<<"Num de vertices: " << T.numVertices() << endl;
    T.imprime();

    cout<<"\n";
    cout << "Area 1: " << T.area() << endl;

    T.translada(-3,4);
    cout << "Area 2: " << T.area() << endl;

    T.rotaciona(30,p0);
    cout << "Area 2: " << T.area() << endl;

    return 0;
}
