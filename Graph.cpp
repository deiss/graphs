#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <vector>

#include "Constants.hpp"
#include "Graph.hpp"
#include "GraphRepresentation.hpp"
#include "GraphRepresentationAdjacencyMatrix.hpp"
#include "Vertex.hpp"

/* Static variables. */
Window* Graph::window(0);
int     Graph::graph_counter(0);

/* Graph constructor. */
Graph::Graph(GRAPH_TYPE type, int nb_vertices)
    : type(type),
      nb_vertices(nb_vertices),
      is_displayed(false),
      arc_integer_capacities_defined(false),
      orientation(NONE),
      window_id(-1) {
    graph_counter++;
    switch(type) {
        /*case INCIDENCE_MATRIX :
            break;
        case INCIDENCE_LIST :
            break;
        case ADJACENCY_LIST :
            break;*/
        case ADJACENCY_MATRIX :
            graph_representation = new GraphRepresentationAdjacencyMatrix(nb_vertices);
            break;
    }
}

/* Graph copy constructor. */
Graph::Graph(const Graph &g)
    : Graph(g.type, g.nb_vertices) {
    *this = g;
}

/* Graph desctructor. */
Graph::~Graph() {
    graph_counter--;
    delete graph_representation;
}

/* Graph assignment operator. It is only possible to copy graphs with same number of vertices. All the parameters are copied expect the window handling that has to be manually set. */
Graph &Graph::operator=(const Graph &g) {
    if(this==&g) {
        return *this;
    }
    else {
        arc_integer_capacities_defined = g.arc_integer_capacities_defined;
        is_displayed                   = g.is_displayed;
        orientation                    = g.orientation;
        *graph_representation          = *g.graph_representation;
        return *this;
    }
}

/* Creates an Edge that binds two vertices. */
Edge* Graph::add_edge(const Vertex* v1, const Vertex* v2, double capacity) {
    return graph_representation->add_edge(v1, v2, capacity, 0);
}

/* Creates a Vertex with optional 2D coordinates. */
Vertex* Graph::add_vertex(double x, double y) {
    return graph_representation->add_vertex(x, y);
}

/* Generates random vertices and build edges to form a Gabriel graph. */
void Graph::generate() {
    generate_random_vertices();
    generate_gabriel_naive();
}

/* Returns the graph's total weight. */
double Graph::get_total_weight() {
    std::vector<Edge*>::iterator it_begin = graph_representation->getEdges()->begin();
    std::vector<Edge*>::iterator it_end   = graph_representation->getEdges()->end();
    if(orientation==NONE || orientation==ONE_WAY) {
        return std::accumulate(it_begin, it_end, 0, [](double sum, const Edge* v) { return sum + v->getCapacityV1ToV2(); });
    }
    else {
        return std::accumulate(it_begin, it_end, 0, [](double sum, const Edge* v) { return sum + v->getCapacityV1ToV2()+v->getCapacityV2ToV1(); });
    }
}

/* Naive algorithm to obtain a Gabriel graph from a set of vertices. */
void Graph::generate_gabriel_naive() {
    for(int i=0 ; i<nb_vertices ; i++) {
        for(int j=i+1 ; j<nb_vertices ; j++) {
            bool valid_edge = true;
            Vertex* v1 = graph_representation->getVertices()->at(i);
            Vertex* v2 = graph_representation->getVertices()->at(j);
            double diameter = v1->distanceTo(v2);
            for(Vertex* v : *graph_representation->getVertices()) {
                if(v!=v1 && v!=v2 && pow(v1->distanceTo(v), 2)+pow(v2->distanceTo(v), 2)<diameter*diameter) {
                    valid_edge = false;
                    break;
                }
            }
            if(valid_edge) graph_representation->add_edge(v1, v2);
        }
    }
}

/* Deletes the current graph. If the graph was displayed, the associated window is destroyed. If the graph was displayed and was the only one, the program terminates. If the current graph is not displayed, the function is equivalent to a call to 'delete graph;' */
void Graph::delete_graph() {
    if(is_displayed) {
        window->hide(window_id);
        delete this;
        if(graph_counter==0) exit(0);
    }
    else {
        delete this;
    }
}

/* Adds a Graph handler to the Window object which subsequently creates a new window. */
bool Graph::display() {
    if(window) {
        is_displayed = true;
        window_id = window->add(this);
        window->launch(window_id);
        return true;
    }
    else {
        return false;
    }
}

/* Keyboard function. */
void Graph::keyboard(unsigned char key, int x, int y) {
    bool this_deleted = false;
    switch(key) {
        case '+' : rebuild_graph(nb_vertices+Constants::GRAPH_VERTICES_INCREMENTATION);
                   this_deleted = true;
                   break;
        case '-' : if(nb_vertices-Constants::GRAPH_VERTICES_INCREMENTATION>Constants::GRAPH_MINIMUM_VERTICES) {
                       rebuild_graph(nb_vertices-Constants::GRAPH_VERTICES_INCREMENTATION);
                       this_deleted = true;
                   }
                   break;
        case '1' : rebuild_graph(nb_vertices);
                   this_deleted = true;
                   break;
        case '2' : keyboard_directions();
                   break;
        case '3' : keyboard_capacities();
                   break;
        case 'a' : delete handler_astar();
                   break;
        case 'd' : delete handler_dijkstra();
                   break;
        case 'e' : handler_edmonds_karp();
                   break;
        case 'f' : handler_ford_fulkerson();
                   break;
        case 'p' : delete handler_prim();
                   break;
        case 't' : delete handler_traveling_salesman();
                   break;
        case 13  : keyboard_dupplicate();           // enter
                   break;
        case 27  : delete_graph();                  // escape
                   this_deleted = true;
                   break;
        case 32  : clear();                         // space
                   break;
    }
    if(!this_deleted) draw();
}

/* Generates or disables arc capacities. */
void Graph::keyboard_capacities() {
    if(!arc_integer_capacities_defined) {
        generate_random_arc_integer_capacities();
        arc_integer_capacities_defined = true;
    }
    else {
        for(Edge* e : *graph_representation->getEdges()) {
            e->setCapacityV1ToV2(Constants::EDGE_DEFAULT_CAPACITY);
            e->setCapacityV2ToV1(Constants::EDGE_DEFAULT_CAPACITY);
        }
        arc_integer_capacities_defined = false;
    }
}

/* Generates or disables arc directions. */
void Graph::keyboard_directions() {
    if(orientation==NONE) {
        orientation = ONE_WAY;
        generate_random_arc_directions();
    }
    else {
        orientation = NONE;
    }
}

/* Creates a dupplicate of the current graph and displays it. Returns true if the graph can be displayed. */
bool Graph::keyboard_dupplicate() {
    Graph* graph_duplicate = new Graph(type, nb_vertices);
    *graph_duplicate       = *this;
    return graph_duplicate->display();
}

/* Reset the graph to the initial parameters of color, arc capacity and direction. */
void Graph::clear() {
    arc_integer_capacities_defined = false;
    orientation                    = NONE;
    for(Edge* e : *graph_representation->getEdges()) {
        e->setCapacityV1ToV2(Constants::EDGE_DEFAULT_CAPACITY);
        e->setCapacityV2ToV1(Constants::EDGE_DEFAULT_CAPACITY);
        e->setColor(Constants::EDGE_COLOR_R, Constants::EDGE_COLOR_G, Constants::EDGE_COLOR_B);
    }
    clear_color_vertices();
}

/* Reset the graph to the initial parameters of color. */
void Graph::clear_color() {
    clear_color_edges();
    clear_color_vertices();
}

/* Reset the vertices to the initial parameters of color. */
void Graph::clear_color_vertices() {
    for(Edge* e : *graph_representation->getEdges()) {
        e->setColor(Constants::EDGE_COLOR_R, Constants::EDGE_COLOR_G, Constants::EDGE_COLOR_B);
    }
    for(Vertex* v : *graph_representation->getVertices()) {
        v->setColor(Constants::VERTEX_COLOR_R, Constants::VERTEX_COLOR_G, Constants::VERTEX_COLOR_B);
    }
}

/* Reset the edges to the initial parameters of color. */
void Graph::clear_color_edges() {
    for(Edge* e : *graph_representation->getEdges()) {
        e->setColor(Constants::EDGE_COLOR_R, Constants::EDGE_COLOR_G, Constants::EDGE_COLOR_B);
    }
}

/* Creates a new graph with the given number of vertices. The actual graph (this) is deleted. If the previous graph was being displayed, the new graph is automatically displayed in the same window. */
Graph* Graph::rebuild_graph(int new_nb_vertices) {
    Graph* new_graph = new Graph(type, new_nb_vertices);
    new_graph->generate();
    if(is_displayed) {
        new_graph->setDisplayed(is_displayed);
        new_graph->setWindowId(window_id);
        window->replaceGraph(this, new_graph);
        new_graph->draw();
    }
    delete this;
    return new_graph;
}

/* Selects two random vertices from the graph. If the graph has at least two vertices, the two selected vertices are different. */
void Graph::select_two_random_vertices(const Vertex** v1, const Vertex** v2) const {
    *v1 = graph_representation->getVertices()->at(rand() % nb_vertices);
    if(nb_vertices>=2) { do { *v2 = graph_representation->getVertices()->at(rand() % nb_vertices); } while(*v1==*v2); }
    else               { *v2 = *v1; }
}

/* Selects oen random vertices from the graph. */
void Graph::select_one_random_vertices(const Vertex** v) const {
    *v = graph_representation->getVertices()->at(rand() % nb_vertices);
}

/* Selects n random vertices from the graph. If the graph has at least two vertices, the two selected vertices are different. */
void Graph::select_n_random_vertices(std::vector<const Vertex*>** vertices, int n, const Vertex* except) const {
    std::set<const Vertex*> included_vertices;
    for(int i=0 ; i<n ; i++) {
        const Vertex* v;
        do {
            v = graph_representation->getVertices()->at(rand() % nb_vertices);
        } while(included_vertices.count(v) || v==except);
        included_vertices.insert(v);
        (*vertices)->push_back(v);
    }
}

/* Disables the checks before an algorithm's execution and trusts the user. For example, assumes that all capacities and arc directions are correctly set before executing the Ford Fulkerson algorithm. Good behavior cannot be guaranted if those conditions are in fact not applied. */
void Graph::set_ready_for_algo(GRAPH_ALGO algo) {
    switch(algo) {
        case FORD_FULKERSON : orientation                    = ONE_WAY;
                              arc_integer_capacities_defined = true;
                              break;
    }
}
