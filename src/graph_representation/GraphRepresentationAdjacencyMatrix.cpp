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

#include "graph/Graph.hpp"
#include "GraphRepresentationAdjacencyMatrix.hpp"

#include <iostream>

/*
Creates the Edge matrix.
*/
GraphRepresentationAdjacencyMatrix::GraphRepresentationAdjacencyMatrix(int nb_vertices) :
    GraphRepresentation(nb_vertices) {
    matrix = new Edge**[nb_vertices];
    for(int i=0 ; i<nb_vertices ; i++) {
        matrix[i] = new Edge*[nb_vertices];
        for(int j=0 ; j<nb_vertices ; j++) {
            matrix[i][j] = 0;
        }
    }
}

/*
Copy constructor.
*/
GraphRepresentationAdjacencyMatrix::GraphRepresentationAdjacencyMatrix(const GraphRepresentationAdjacencyMatrix& g) :
    GraphRepresentation(g) {
    matrix = new Edge**[nb_vertices];
    for(int i=0 ; i<nb_vertices ; i++) {
        matrix[i] = new Edge *[nb_vertices];
        for(int j=0 ; j<nb_vertices ; j++) {
            matrix[i][j] = 0;
        }
    }
    *this = g;
}

/*
Deletes the Edge matrix.
*/
GraphRepresentationAdjacencyMatrix::~GraphRepresentationAdjacencyMatrix() {
    for(int i=0 ; i<nb_vertices ; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/*
Overloaded assignment operator. Updates the list of edges and vertices.
*/
GraphRepresentation &GraphRepresentationAdjacencyMatrix::operator=(const GraphRepresentation& g) {
    copy(g);
    return operator=(dynamic_cast<const GraphRepresentationAdjacencyMatrix&>(g));
}

/*
Assignment operator. Has to be called after the copy() function.
Updates Edge the matrix.
*/
GraphRepresentationAdjacencyMatrix& GraphRepresentationAdjacencyMatrix::operator=(const GraphRepresentationAdjacencyMatrix& g) {
    if(this==&g) {
        return *this;
    }
    else {
        for(Edge* e : *edges) {
            if(e) {
                matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
                matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
            }
        }
        return *this;
    }
}

/* Creates an Edge. */
Edge* GraphRepresentationAdjacencyMatrix::add_edge(const Vertex* v1, const Vertex* v2) {
    Edge* e = GraphRepresentation::add_edge(v1, v2);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
    matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
    return e;
}
Edge* GraphRepresentationAdjacencyMatrix::add_edge(const Vertex* v1, const Vertex* v2, double c1, double c2) {
    Edge* e = GraphRepresentation::add_edge(v1, v2, c1, c2);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
    matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
    return e;
}
Edge* GraphRepresentationAdjacencyMatrix::add_edge(const Vertex* v1, const Vertex* v2, unsigned char cr, unsigned char cg, unsigned char cb) {
    Edge* e = GraphRepresentation::add_edge(v1, v2, cr, cg, cb);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
    matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
    return e;
}
Edge* GraphRepresentationAdjacencyMatrix::add_edge(const Vertex* v1, const Vertex* v2, double c1, double c2, unsigned char cr, unsigned char cg, unsigned char cb) {
    Edge* e = GraphRepresentation::add_edge(v1, v2, c1, c2, cr, cg, cb);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
    matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
    return e;
}
Edge* GraphRepresentationAdjacencyMatrix::add_edge(const Edge* e) {
    GraphRepresentation::add_edge(e);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = const_cast<Edge*>(e);
    matrix[e->getV2()->getId()][e->getV1()->getId()] = const_cast<Edge*>(e);
    return const_cast<Edge*>(e);
}

/*
Finds the path that links v1 to v2 and returns the edge.
*/
Edge* GraphRepresentationAdjacencyMatrix::get_edge_from_to(const Vertex* v1, const Vertex* v2) const {
    return matrix[v1->getId()][v2->getId()];
}
Edge* GraphRepresentationAdjacencyMatrix::get_edge_from_to(int id1, int id2) const {
    return matrix[id1][id2];
}

/*
Finds the path that links v1 to v2 and returns its capacity (and not v2 to v1).
*/
int GraphRepresentationAdjacencyMatrix::get_capacity_from_to(const Vertex* v1, const Vertex* v2) const {
    Edge* e = matrix[v1->getId()][v2->getId()];
    if(e) {
        if(v1==e->getV1() && v2==e->getV2())      return e->getCapacityV1ToV2();
        else if(v1==e->getV2() && v2==e->getV1()) return e->getCapacityV2ToV1();
        else return 0;
    }
    else {
        return 0;
    }
}
int GraphRepresentationAdjacencyMatrix::get_capacity_from_to(int id1, int id2) const {
    Edge* e = matrix[id1][id2];
    if(e) {
        if(id1==e->getV1()->getId() && id2==e->getV2()->getId())      return e->getCapacityV1ToV2();
        else if(id1==e->getV2()->getId() && id2==e->getV1()->getId()) return e->getCapacityV2ToV1();
        else return 0;
    }
    else {
        return 0;
    }
}

/*
Returns the vertices connected to v or to which v is connected (both ways).
Returns a vector.
*/
std::vector<Vertex*> GraphRepresentationAdjacencyMatrix::get_all_neighbors(const Vertex* v) const {
    std::vector<Vertex*> neighbors;
    for(int i=0 ; i<nb_vertices ; i++) {
        if(matrix[v->getId()][i]) {
            neighbors.push_back(vertices->at(i));
        }
    }
    return neighbors;
}

/* Returns the vertices connected to v or to which v is connected (both ways).
Returns a set.
*/
std::set<Vertex*> GraphRepresentationAdjacencyMatrix::get_all_neighbors_set(const Vertex* v) const {
    std::set<Vertex*> neighbors;
    for(int i=0 ; i<nb_vertices ; i++) {
        if(matrix[v->getId()][i]) {
            neighbors.insert(vertices->at(i));
        }
    }
    return neighbors;
}

/*
Returns the vertices to which v is connected (one way).
*/
std::vector<Vertex*> GraphRepresentationAdjacencyMatrix::get_direct_neighbors(const Vertex* v, GRAPH_ORIENTATION orientation) const {
    std::vector<Vertex*> neighbors;
    for(int i=0 ; i<nb_vertices ; i++) {
        Edge* e = matrix[v->getId()][i];
        if(e) {
            Vertex* v2 = vertices->at(i);
            if((orientation==GRAPH_ORIENTATION::ONE_WAY && v==e->getV1() && v2==e->getV2()) || orientation==GRAPH_ORIENTATION::NONE || orientation==GRAPH_ORIENTATION::TWO_WAYS) neighbors.push_back(v2);
        }
    }
    return neighbors;
}

/*
Sets the capacity from a Vertex to another one.
*/
void GraphRepresentationAdjacencyMatrix::set_capacity_from_to(const Vertex* v1, const Vertex* v2, double c) {
    Edge* e = matrix[v1->getId()][v2->getId()];
    if(e) {
        if(v1==e->getV1() && v2==e->getV2())      e->setCapacityV1ToV2(c);
        else if(v1==e->getV2() && v2==e->getV1()) e->setCapacityV2ToV1(c);
    }
}
