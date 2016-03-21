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

#include <iostream>

#include "constants/Constants.hpp"
#include "Edge.hpp"

/*
Initializes the variables.
*/
Edge::Edge(const Vertex* v1, const Vertex* v2) :
    color_r(Constants::EDGE_COLOR_R),
    color_g(Constants::EDGE_COLOR_G),
    color_b(Constants::EDGE_COLOR_B),
    capacity_v1_v2(Constants::EDGE_DEFAULT_CAPACITY),
    capacity_v2_v1(Constants::EDGE_DEFAULT_CAPACITY),
    v1(const_cast<Vertex*>(v1)),
    v2(const_cast<Vertex*>(v2)) {
}
Edge::Edge(const Vertex* v1, const Vertex* v2, double capacity_v1_v2, double capacity_v2_v1) :
    color_r(Constants::EDGE_COLOR_R),
    color_g(Constants::EDGE_COLOR_G),
    color_b(Constants::EDGE_COLOR_B),
    capacity_v1_v2(capacity_v1_v2),
    capacity_v2_v1(capacity_v2_v1),
    v1(const_cast<Vertex*>(v1)),
    v2(const_cast<Vertex*>(v2)) {
}
Edge::Edge(const Vertex* v1, const Vertex* v2, double capacity_v1_v2, double capacity_v2_v1, unsigned char color_r, unsigned char color_g, unsigned char color_b) :
    color_r(color_r),
    color_g(color_g),
    color_b(color_b),
    capacity_v1_v2(capacity_v1_v2),
    capacity_v2_v1(capacity_v2_v1),
    v1(const_cast<Vertex*>(v1)),
    v2(const_cast<Vertex*>(v2)){
}
Edge::Edge(const Vertex* v1, const Vertex* v2, unsigned char color_r, unsigned char color_g, unsigned char color_b) :
    color_r(color_r),
    color_g(color_g),
    color_b(color_b),
    capacity_v1_v2(Constants::EDGE_DEFAULT_CAPACITY),
    capacity_v2_v1(Constants::EDGE_DEFAULT_CAPACITY),
    v1(const_cast<Vertex*>(v1)),
    v2(const_cast<Vertex*>(v2)) {
}

/*
Assignment operator.
*/
Edge& Edge::operator=(const Edge& e) {
    if(this==&e) {
        return *this;
    }
    else {
        color_r        = e.color_r;
        color_g        = e.color_g;
        color_b        = e.color_b;
        capacity_v1_v2 = e.capacity_v1_v2;
        capacity_v2_v1 = e.capacity_v2_v1;
        return *this;
    }
}

/*
Switches v1 and v2.
*/
void Edge::switch_vertices() {
    Vertex* v = v1;
    v1 = v2;
    v2 = v;
}
