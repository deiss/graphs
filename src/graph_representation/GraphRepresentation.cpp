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

#include "GraphRepresentation.hpp"
#include "components/Vertex.hpp"

#include <iostream>

/* GraphRepresentation constructor. */
GraphRepresentation::GraphRepresentation(int nb_vertices)
     : nb_vertices(nb_vertices),
       vertex_counter(0) {
     vertices = new std::vector<Vertex*>;
     edges    = new std::vector<Edge*>;
}

/* GraphRepresentation copy constructor. */
GraphRepresentation::GraphRepresentation(const GraphRepresentation& g)
    : GraphRepresentation(g.nb_vertices) {
    *this = g;
}

/* GraphRepresentation destructor. */
GraphRepresentation::~GraphRepresentation() {
    for(Vertex* v : *vertices) delete v;
    for(Edge* e : *edges)      delete e;
    delete vertices;
    delete edges;
}

/* Copy function. */
void GraphRepresentation::copy(const GraphRepresentation& g) {
    if(this!=&g) {
        for(Vertex* v : *vertices) delete v; vertices->clear();
        for(Edge* e : *edges)      delete e; edges->clear();
        for(Vertex* v : *g.vertices) {
            Vertex* v_copy = new Vertex(v->getX(), v->getY(), v->getId());
            *v_copy = *v;
            vertices->push_back(v_copy);
        }
        for(Edge* e : *g.edges) {
            Vertex* v1 = vertices->at(e->getV1()->getId());
            Vertex* v2 = vertices->at(e->getV2()->getId());
            Edge* e_copy = new Edge(v1, v2);
            *e_copy = *e;
            edges->push_back(e_copy);
        }
    }
}

/* Creates a new Vertex. */
Vertex* GraphRepresentation::add_vertex(double x, double y) {
    Vertex* v = new Vertex(x, y, vertex_counter++);
    vertices->push_back(v);
    return v;
}

/* Creates an Edge. */
Edge* GraphRepresentation::add_edge(const Vertex* v1, const Vertex* v2) {
    Edge* e = new Edge(v1, v2);
    edges->push_back(e);
    return e;
}
Edge* GraphRepresentation::add_edge(const Vertex* v1, const Vertex* v2, double c1, double c2) {
    Edge* e = new Edge(v1, v2, c1, c2);
    edges->push_back(e);
    return e;
}
Edge* GraphRepresentation::add_edge(const Vertex* v1, const Vertex* v2, double c1, double c2, unsigned char cr, unsigned char cg, unsigned char cb) {
    Edge* e = new Edge(v1, v2, c1, c2, cr, cg, cb);
    edges->push_back(e);
    return e;
}
Edge* GraphRepresentation::add_edge(const Vertex* v1, const Vertex* v2, unsigned char cr, unsigned char cg, unsigned char cb) {
    Edge* e = new Edge(v1, v2, cr, cg, cb);
    edges->push_back(e);
    return e;
}
Edge* GraphRepresentation::add_edge(const Edge* edge) {
    edges->push_back(const_cast<Edge*>(edge));
    return const_cast<Edge*>(edge);
}
