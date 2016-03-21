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

#include "graph/Graph.hpp"
#include "components/Vertex.hpp"
#include "rendering/Window.hpp"

int main(int argc, const char * argv[]) {

    /* rand initialization */
    srand(static_cast<unsigned int>(time(NULL)));
    
    /* rendering */
    Window window;
    window.init();
    Graph::setWindow(&window);
    
    /* grpah creation */
    Graph *graph = new Graph(ADJACENCY_MATRIX, 60);
    graph->generate();
    graph->display();

    delete graph;
    return 0;

}
