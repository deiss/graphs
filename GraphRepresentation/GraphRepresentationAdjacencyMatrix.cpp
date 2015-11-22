#include "Graph.hpp"
#include "GraphRepresentationAdjacencyMatrix.hpp"

#include <iostream>

/* GraphRepresentationAdjacencyMatrix constructor. */
GraphRepresentationAdjacencyMatrix::GraphRepresentationAdjacencyMatrix(int nb_vertices)
     : GraphRepresentation(nb_vertices) {
    matrix = new Edge **[nb_vertices];
    for(int i=0 ; i<nb_vertices ; i++) {
        matrix[i] = new Edge *[nb_vertices];
        for(int j=0 ; j<nb_vertices ; j++) {
            matrix[i][j] = 0;
        }
    }
}

/* GraphRepresentationAdjacencyMatrix copy constructor. */
GraphRepresentationAdjacencyMatrix::GraphRepresentationAdjacencyMatrix(const GraphRepresentationAdjacencyMatrix &g)
    : GraphRepresentation(g) {
    matrix = new Edge **[nb_vertices];
    for(int i=0 ; i<nb_vertices ; i++) {
        matrix[i] = new Edge *[nb_vertices];
        for(int j=0 ; j<nb_vertices ; j++) {
            matrix[i][j] = 0;
        }
    }
    *this = g;
}

/* GraphRepresentationAdjacencyMatrix destructor. */
GraphRepresentationAdjacencyMatrix::~GraphRepresentationAdjacencyMatrix() {
    for(int i=0 ; i<nb_vertices ; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/* GraphRepresentation overloaded assignment operator. */
GraphRepresentation &GraphRepresentationAdjacencyMatrix::operator=(const GraphRepresentation &g) {
    copy(g);
    return operator=(dynamic_cast<const GraphRepresentationAdjacencyMatrix&>(g));
}

/* GraphRepresentationAdjacencyMatrix assignment operator. */
GraphRepresentationAdjacencyMatrix &GraphRepresentationAdjacencyMatrix::operator=(const GraphRepresentationAdjacencyMatrix &g) {
    if(this==&g) {
        return *this;
    }
    else {
        for(Edge *e : *edges) {
            if(e) {
                matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
                matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
            }
        }
        return *this;
    }
}

/* Creates an Edge. */
Edge *GraphRepresentationAdjacencyMatrix::add_edge(const Vertex *v1, const Vertex *v2) {
    Edge *e = GraphRepresentation::add_edge(v1, v2);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
    matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
    return e;
}
Edge *GraphRepresentationAdjacencyMatrix::add_edge(const Vertex *v1, const Vertex *v2, double c1, double c2) {
    Edge *e = GraphRepresentation::add_edge(v1, v2, c1, c2);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
    matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
    return e;
}
Edge *GraphRepresentationAdjacencyMatrix::add_edge(const Vertex *v1, const Vertex *v2, unsigned char cr, unsigned char cg, unsigned char cb) {
    Edge *e = GraphRepresentation::add_edge(v1, v2, cr, cg, cb);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
    matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
    return e;
}
Edge *GraphRepresentationAdjacencyMatrix::add_edge(const Vertex *v1, const Vertex *v2, double c1, double c2, unsigned char cr, unsigned char cg, unsigned char cb) {
    Edge *e = GraphRepresentation::add_edge(v1, v2, c1, c2, cr, cg, cb);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = e;
    matrix[e->getV2()->getId()][e->getV1()->getId()] = e;
    return e;
}
Edge *GraphRepresentationAdjacencyMatrix::add_edge(const Edge *e) {
    GraphRepresentation::add_edge(e);
    matrix[e->getV1()->getId()][e->getV2()->getId()] = const_cast<Edge *>(e);
    matrix[e->getV2()->getId()][e->getV1()->getId()] = const_cast<Edge *>(e);
    return const_cast<Edge *>(e);
}

/* Finds the path that links v1 to v2 and returns the edge */
Edge *GraphRepresentationAdjacencyMatrix::get_edge_from_to(const Vertex *v1, const Vertex *v2) const {
    return matrix[v1->getId()][v2->getId()];
}
Edge *GraphRepresentationAdjacencyMatrix::get_edge_from_to(int id1, int id2) const {
    return matrix[id1][id2];
}

/* Finds the path that links v1 to v2 and returns its capacity (one way). */
int GraphRepresentationAdjacencyMatrix::get_capacity_from_to(const Vertex *v1, const Vertex *v2) const {
    Edge *e = matrix[v1->getId()][v2->getId()];
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
    Edge *e = matrix[id1][id2];
    if(e) {
        if(id1==e->getV1()->getId() && id2==e->getV2()->getId())      return e->getCapacityV1ToV2();
        else if(id1==e->getV2()->getId() && id2==e->getV1()->getId()) return e->getCapacityV2ToV1();
        else return 0;
    }
    else {
        return 0;
    }
}

/* Returns the vertices connected to v or to which v is connected (both ways). */
std::vector<Vertex *> GraphRepresentationAdjacencyMatrix::get_all_neighbors(const Vertex *v) const {
    std::vector<Vertex *> neighbors;
    for(int i=0 ; i<nb_vertices ; i++) {
        if(matrix[v->getId()][i]) {
            neighbors.push_back(vertices->at(i));
        }
    }
    return neighbors;
}

/* Returns the vertices to which v is connected (one way). */
std::vector<Vertex *> GraphRepresentationAdjacencyMatrix::get_direct_neighbors(const Vertex *v, GRAPH_ORIENTATION orientation) const {
    std::vector<Vertex *> neighbors;
    for(int i=0 ; i<nb_vertices ; i++) {
        Edge *e = matrix[v->getId()][i];
        if(e) {
            Vertex *v2 = vertices->at(i);
            if((orientation==GRAPH_ORIENTATION::ONE_WAY && v==e->getV1() && v2==e->getV2()) || orientation==GRAPH_ORIENTATION::NONE || orientation==GRAPH_ORIENTATION::TWO_WAYS) neighbors.push_back(vertices->at(i));
        }
    }
    return neighbors;
}

/* Sets the capacity from a Vertex to another one. */
void GraphRepresentationAdjacencyMatrix::set_capacity_from_to(const Vertex *v1, const Vertex *v2, double c) {
    Edge *e = matrix[v1->getId()][v2->getId()];
    if(e) {
        if(v1==e->getV1() && v2==e->getV2())      e->setCapacityV1ToV2(c);
        else if(v1==e->getV2() && v2==e->getV1()) e->setCapacityV2ToV1(c);
    }
}
