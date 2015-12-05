#include <iostream>

#include "Constants.hpp"
#include "Edge.hpp"

/* Edge constructors. */
Edge::Edge(const Vertex* v1, const Vertex* v2)
    : v1(const_cast<Vertex*>(v1)),
      v2(const_cast<Vertex*>(v2)),
      capacity_v1_v2(Constants::EDGE_DEFAULT_CAPACITY),
      capacity_v2_v1(Constants::EDGE_DEFAULT_CAPACITY),
      color_r(Constants::EDGE_COLOR_R),
      color_g(Constants::EDGE_COLOR_G),
      color_b(Constants::EDGE_COLOR_B) {
}
Edge::Edge(const Vertex* v1, const Vertex* v2, double capacity_v1_v2, double capacity_v2_v1)
    : v1(const_cast<Vertex*>(v1)),
      v2(const_cast<Vertex*>(v2)),
      capacity_v1_v2(capacity_v1_v2),
      capacity_v2_v1(capacity_v2_v1),
      color_r(Constants::EDGE_COLOR_R),
      color_g(Constants::EDGE_COLOR_G),
      color_b(Constants::EDGE_COLOR_B) {
}
Edge::Edge(const Vertex* v1, const Vertex* v2, double capacity_v1_v2, double capacity_v2_v1, unsigned char color_r, unsigned char color_g, unsigned char color_b)
    : v1(const_cast<Vertex*>(v1)),
      v2(const_cast<Vertex*>(v2)),
      capacity_v1_v2(capacity_v1_v2),
      capacity_v2_v1(capacity_v2_v1),
      color_r(color_r),
      color_g(color_g),
      color_b(color_b) {
}
Edge::Edge(const Vertex* v1, const Vertex* v2, unsigned char color_r, unsigned char color_g, unsigned char color_b)
    : v1(const_cast<Vertex*>(v1)),
      v2(const_cast<Vertex*>(v2)),
      color_r(color_r),
      color_g(color_g),
      color_b(color_b),
      capacity_v1_v2(Constants::EDGE_DEFAULT_CAPACITY),
      capacity_v2_v1(Constants::EDGE_DEFAULT_CAPACITY) {
}

/* Edge assignment operator. */
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

/* Switches v1 to v2. */
void Edge::switch_vertices() {
    Vertex* v = v1;
    v1 = v2;
    v2 = v;
}