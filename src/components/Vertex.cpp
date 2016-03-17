/*
Graphs - Copyright (C) 2016 - Olivier Deiss - olivier.deiss@gmail.com

Graphs is a toolbox for graph theory. It includes graph algorithms
and an interface to visualize them, using OpengGL. The project
comes with a function to generate random Gabriel graphs. These
graphs look like road maps and are therefore nice for the study of
lots of graph algorithms.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cmath>
#include <iostream>

#include "Vertex.hpp"

/* Vertex constructor. */
Vertex::Vertex(double x, double y, int id, unsigned char color_r, unsigned char color_g, unsigned char color_b) :
    id(id),
    x(x),
    y(y),
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
