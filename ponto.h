#ifndef POINT_H
#define POINT_H


class Ponto{
private:
    float x,y;
public:
    Ponto();
    void setX(float _x=0);
    void setY(float _y=0);
    void setXY(float _x=0,float _y=0);
    float getX();
    float getY();
    Ponto operator +(Ponto p1);
    Ponto operator -(Ponto p1);
    double norma();
    void translada(float a=0, float b=0);
    void imprime();
};

#endif // POINT_H
