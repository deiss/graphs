#include <cmath>
#include <iostream>

#include "Vertex.hpp"

/* Vertex constructor. */
Vertex::Vertex(double x, double y, int id, unsigned char color_r, unsigned char color_g, unsigned char color_b)
     : x(x),
       y(y),
       id(id),
       color_r(color_r),
       color_g(color_g),
       color_b(color_b) {
}

/* Vertex copy constructor. */
Vertex::Vertex(const Vertex& v)
    : Vertex(v.getX(), v.getY(), v.getId()) {
    *this = v;
}

/* Vertex assignment operator. */
Vertex &Vertex::operator=(const Vertex& v) {
    if(this==&v) {
        return *this;
    }
    else {
        color_r = v.getColorR();
        color_g = v.getColorG();
        color_b = v.getColorB();
        return *this;
    }
}

/* Computes the distance between two vertices. */
double Vertex::distanceTo(const Vertex* v) const {
    return sqrt(pow(x-v->getX(), 2) + pow(y-v->getY(), 2));
}
double Vertex::distanceTo(double x, double y) const {
    return sqrt(pow(this->x-x, 2) + pow(this->y-y, 2));
}