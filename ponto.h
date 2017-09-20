#ifndef POINT_H
#define POINT_H


class Ponto{
private:
    float x,y;
public:
    Ponto();
    Ponto(float _x ,float _y);
    ~Ponto();
    void setX(float _x);
    void setY(float _y);
    void setXY(float _x,float _y);
    float getX();
    float getY();
    Ponto operator +(Ponto p1);
    Ponto operator -(Ponto p1);
    double norma();
    void translada(float a=0, float b=0);
    void imprime();
};


#endif // POINT_H
