#ifndef POINT_H
#define POINT_H


class Point{
private:
    float x,y;
public:
    void setX(float _x=0);
    void setY(float _y=0);
    void setXY(float _x=0,float _y=0);
    float getX();
    float getY();
    Point operator +(Point p1);
    Point operator -(Point p1);
    float norma();
    void translada(float a, float b);
    void imprime();
};

#endif // POINT_H
