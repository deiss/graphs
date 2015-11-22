#include <cmath>
#include <iostream>

#include "Graph.hpp"
#include "Vertex.hpp"
#include "Window.hpp"

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(NULL)));
    Window window;
    window.init();
    Graph::setWindow(&window);
    Graph *graph = new Graph(ADJACENCY_MATRIX, 30);
    
    graph->generate();
    graph->display();
    
    delete graph;
    return 0;
}

/*

C coloriage
P Prim
D Dijkstra
A A*
S traveling slesman

flipping

*/