#ifndef POLYGON_H
#define POLYGON_H
#include "point.h"

class Polygon : public Point{
private:
    Point vertices[100];
public:
    void addVertex(Point _vertex);
    int numVertices(Point *v);
    double area(Point *vertices, int nVert);
    void translada(float a, float b);
    void rotate(float theta);
    void print();
};

#endif // POLYGON_H
