#include <iostream>
#include <numeric>

#include "Graph.hpp"

/* A* algorithm handler. Finds the shortest path between two randomly selected vertices, display it. It works on single oriented and non oriented graphs. */
std::vector<const Edge *> *Graph::handler_astar(Vertex *source, Vertex *destination) {
    clear_color();
    if(!source || !destination) { select_two_random_vertices(const_cast<const Vertex **>(&source), const_cast<const Vertex **>(&destination)); }
    source->setColor(Constants::EDGE_ALGO_SOURCE_COLOR_R, Constants::EDGE_ALGO_SOURCE_COLOR_G, Constants::EDGE_ALGO_SOURCE_COLOR_B);
    destination->setColor(Constants::EDGE_ALGO_DESTINATION_COLOR_R, Constants::EDGE_ALGO_DESTINATION_COLOR_G, Constants::EDGE_ALGO_DESTINATION_COLOR_B);
    return algo_astar(source, destination);
}

/* Dijkstra algorithm handler. Finds the shortest path between two randomly selected vertices, display it. It works on single oriented and non oriented graphs. */
std::vector<const Edge *> *Graph::handler_dijkstra(Vertex *source, Vertex *destination) {
    clear_color();
    if(!source || !destination) { select_two_random_vertices(const_cast<const Vertex **>(&source), const_cast<const Vertex **>(&destination)); }
    source->setColor(Constants::EDGE_ALGO_SOURCE_COLOR_R, Constants::EDGE_ALGO_SOURCE_COLOR_G, Constants::EDGE_ALGO_SOURCE_COLOR_B);
    destination->setColor(Constants::EDGE_ALGO_DESTINATION_COLOR_R, Constants::EDGE_ALGO_DESTINATION_COLOR_G, Constants::EDGE_ALGO_DESTINATION_COLOR_B);
    return algo_dijkstra(source, destination);
}

/* Fulkerson algorithm handler. It returns and prints the value of the maximum flow in the console and leave the current graph unchanged. The algorithm needs a single-oriented graph with integer flows. If the current graph already has this properties, the algorithm is made on the graph, otherwise directions and capacities are randomly set. */
int Graph::handler_ford_fulkerson(Vertex *source, Vertex *sink) {
    clear_color();
    if(orientation==NONE || orientation==TWO_WAYS) { generate_random_arc_directions();         orientation                    = ONE_WAY; }
    if(!arc_integer_capacities_defined)            { generate_random_arc_integer_capacities(); arc_integer_capacities_defined = true; }
    if(!source || !sink) { select_two_random_vertices(const_cast<const Vertex **>(&source), const_cast<const Vertex **>(&sink)); }
    source->setColor(Constants::EDGE_ALGO_SOURCE_COLOR_R, Constants::EDGE_ALGO_SOURCE_COLOR_G, Constants::EDGE_ALGO_SOURCE_COLOR_B);
    sink->setColor(Constants::EDGE_ALGO_DESTINATION_COLOR_R, Constants::EDGE_ALGO_DESTINATION_COLOR_G, Constants::EDGE_ALGO_DESTINATION_COLOR_B);
    int res = algo_ford_fulkerson(source, sink);
    std::cout << "maximum flow: " << res << std::endl;
    return res;
}

/* Prim algorithm handler. The algorithm needs a non oriented graph with capacities. The method returns a vector of all the edges in the subgraph. */
std::vector<const Edge *> *Graph::handler_prim() {
    clear_color();
    if(orientation==ONE_WAY || orientation==TWO_WAYS) { orientation = NONE; }
    if(!arc_integer_capacities_defined)               { generate_random_arc_integer_capacities(); arc_integer_capacities_defined = true; }
    std::vector<const Edge *> *sub_graph = algo_prim();
    double w1 = get_total_weight();
    double w2 = std::accumulate(sub_graph->begin(), sub_graph->end(), 0, [] (double sum, const Edge *v) { return sum + v->getCapacityV1ToV2(); });
    std::cout << "initial graph weight: " << w1 << std::endl << "prim graph weight: " << w2 << " (" << 100*w2/w1 << "%)" << std::endl;
    return sub_graph;
}