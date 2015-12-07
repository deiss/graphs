#include <iostream>

#include "Graph.hpp"

/* Generates random integer capacities for each arc in the graph. If orientation is ONE_WAY or NONE, capacity_v1_v2 is used and capacity_v2_v1 is set to zero. Otherwise both are given a random capacity. */
void Graph::generate_random_arc_integer_capacities() {
    for(Edge* e : *graph_representation->getEdges()) {
                                  e->setCapacityV1ToV2(rand()%Constants::EDGE_MAXIMUM_CAPACITY + 1);
        if(orientation==TWO_WAYS) e->setCapacityV2ToV1(rand()%Constants::EDGE_MAXIMUM_CAPACITY + 1);
        else                      e->setCapacityV2ToV1(0);
    }
}

/* Randomly switches vertices v1 and v2 of each edge of the graph. */
void Graph::generate_random_arc_directions() {
    for(Edge* e : *graph_representation->getEdges()) {
        if(rand()%2) e->switch_vertices();
    }
}

/* Generates the random vertices. It is guaranted that each vertex has unique (x, y). */
void Graph::generate_random_vertices() {
    std::set<std::pair<double, double>> s;
    for(int i=0 ; i<nb_vertices ; i++) {
        double x, y;
        do {
            x = static_cast<double>(rand() % 1900 - 950)/1000;
            y = static_cast<double>(rand() % 1900 - 950)/1000;
        } while(s.count(std::make_pair(x, y)));
        s.insert(std::make_pair(x, y));
        graph_representation->add_vertex(x, y);
    }
}