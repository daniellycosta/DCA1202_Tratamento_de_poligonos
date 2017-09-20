#include <iostream>
#include<ponto.h>
#include<poligono.h>
#include<retangulo.h>

using namespace std;

int main(){
    Retangulo T(0,0,4,3);
    Ponto p0;

    p0.setXY(2,1.5);

    T.print();
    cout<<"\n";
    cout << "Area 1: " << T.area() << endl;
    T.translada(-3,4);
    cout << "Area 2: " << T.area() << endl;
    T.rotate(30,p0);
    cout << "Area 2: " << T.area() << endl;

    return 0;
}
