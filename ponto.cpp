#include "ponto.h"
#include<math.h>
#include<iostream>

using namespace std;

Ponto::Ponto(){
    float x=0;
    float y=0;
}

Ponto::~Ponto(){
 cout << "[PON] Destruindo ponto...\n";
}

void Ponto::setX(float _x){
    x = _x;
}
void Ponto::setY(float _y){
    y = _y;
}

void Ponto::setXY(float _x, float _y){
    x = _x;
    y = _y;
}

float Ponto::getX(){
    return x;
}

float Ponto::getY(){
    return y;
}

Ponto Ponto::operator +(Ponto p1){
    Ponto ret;
    ret.x = x + p1.x;
    ret.y = y + p1.y;
    return ret;
}

Ponto Ponto::operator -(Ponto p1){
    Ponto ret;
    ret.x = x - p1.x;
    ret.y = y - p1.y;
    return ret;
}

//como add nova origem ao ponto?
double Ponto::norma(){
    return (sqrt((x*x) + (y*y)));
}

void Ponto::translada(float a, float b){
    x = x + a;
    y = y + b;
}

void Ponto::imprime(){
    cout << "(" << x << ", " << y << ")\n";
}
