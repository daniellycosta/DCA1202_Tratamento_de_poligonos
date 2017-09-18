#ifndef POLYGON_H
#define POLYGON_H
#include "point.h"

class Polygon : public Point{
private:
    Point *vertices;
    int nVertices;
public:
    Polygon();
    operator + (Point _vertice);
    int numVertices(Point *arrayVertices);
    double area(Point *vertices, int nVert);
    void translada(float a, float b);
    void rotate(float theta, Point p0);
    void print();
};

#endif // POLYGON_H
