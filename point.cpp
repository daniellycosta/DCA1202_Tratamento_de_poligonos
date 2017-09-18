#include "point.h"
#include<math.h>
#include<iostream>

using namespace std;

void Point::setX(float _x){
    x = _x;
}
void Point::setY(float _y){
    y = _y;
}

void Point::setXY(float _x, float _y){
    x = _x;
    y = _y;
}

float Point::getX(){
    return x;
}

float Point::getY(){
    return y;
}

Point Point::operator +(Point p1){
    Point ret;
    ret.x = x + p1.x;
    ret.y = y + p1.y;
    return ret;
}

Point Point::operator -(Point p1){
    Point ret;
    ret.x = x - p1.x;
    ret.y = y - p1.y;
    return ret;
}

double Point::norma(){
    return (sqrt((x*x) + (y*y)));
}

void Point::translada(float a, float b){
    x = x + a;
    y = y + b;
}

void Point::imprime(){
    cout << "(" << x << ", " << y << ")\n";
}
