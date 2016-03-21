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

#include "Graph.hpp"

/*
Generates random integer capacities for each arc in the graph. If orientation
is ONE_WAY or NONE, capacity_v1_v2 is used and capacity_v2_v1 is set to zero.
Otherwise both are given a random capacity.
*/
void Graph::generate_random_arc_integer_capacities() {
    for(Edge* e : *graph_representation->getEdges()) {
                                  e->setCapacityV1ToV2(rand()%Constants::EDGE_MAXIMUM_CAPACITY + 1);
        if(orientation==TWO_WAYS) e->setCapacityV2ToV1(rand()%Constants::EDGE_MAXIMUM_CAPACITY + 1);
        else                      e->setCapacityV2ToV1(0);
    }
}

/*
Randomly switches vertices v1 and v2 of each edge of the graph.
*/
void Graph::generate_random_arc_directions() {
    for(Edge* e : *graph_representation->getEdges()) {
        if(rand()%2) e->switch_vertices();
    }
}

/*
Generates the random vertices. It is guaranted that each vertex has unique (x, y).
*/
void Graph::generate_random_vertices() {
    std::set<std::pair<double, double>> s;
    for(int i=0 ; i<nb_vertices ; i++) {
        double x, y;
        do {
            x = static_cast<double>(rand() % Constants::AREA_WIDTH - Constants::AREA_WIDTH/2)/1000;
            y = static_cast<double>(rand() % Constants::AREA_HEIGHT - Constants::AREA_HEIGHT/2)/1000;
        } while(s.count(std::make_pair(x, y)));
        s.insert(std::make_pair(x, y));
        graph_representation->add_vertex(x, y);
    }
}

/*
Generates the random vertices. It is guaranted that each vertex has unique (x, y).
*/
void Graph::generate_random_vertices_spacing() {
    std::vector<std::pair<int, int>> empty_cells;
    int                              nb_x_cells = ceil(Constants::AREA_WIDTH/Constants::AREA_SPACING);
    int                              nb_y_cells = ceil(Constants::AREA_HEIGHT/Constants::AREA_SPACING);
    Vertex**                         full_cells = new Vertex*[nb_x_cells*nb_y_cells];
    for(int j=0 ; j<nb_y_cells ; j++) {
        for(int i=0 ; i<nb_x_cells ; i++) {
            full_cells[i+j*nb_x_cells] = 0;
            empty_cells.push_back(std::make_pair(i, j));
        }
    }
    for(int i=0 ; i<nb_vertices ; i++) {
        float x, y;
        bool  retry;
        int   index, index_x, index_y;
        do {
            retry   = false;
            index   = rand() % empty_cells.size();
            index_x = empty_cells[index].first;
            index_y = empty_cells[index].second;
            if(full_cells[index_x + index_y*nb_x_cells]!=0) {
                retry = true;
            }
            else {
                std::vector<Vertex*> neighbors;
                if(index_x<nb_x_cells-1) {
                    if(full_cells[index_x+1 + index_y*nb_x_cells]!=0) neighbors.push_back(full_cells[index_x+1 + index_y*nb_x_cells]);
                    if(index_y<nb_y_cells-1) { if(full_cells[index_x+1 + (index_y+1)*nb_x_cells]!=0) neighbors.push_back(full_cells[index_x+1 + (index_y+1)*nb_x_cells]); }
                    if(index_y>0)            { if(full_cells[index_x+1 + (index_y-1)*nb_x_cells]!=0) neighbors.push_back(full_cells[index_x+1 + (index_y-1)*nb_x_cells]); }
                }
                if(index_x>0) {
                    if(full_cells[index_x-1 + index_y*nb_x_cells]!=0) neighbors.push_back(full_cells[index_x-1 + index_y*nb_x_cells]);
                    if(index_y<nb_y_cells-1) { if(full_cells[index_x-1 + (index_y+1)*nb_x_cells]!=0) neighbors.push_back(full_cells[index_x-1 + (index_y+1)*nb_x_cells]); }
                    if(index_y>0)            { if(full_cells[index_x-1 + (index_y-1)*nb_x_cells]!=0) neighbors.push_back(full_cells[index_x-1 + (index_y-1)*nb_x_cells]); }
                }
                if(index_y>0)            { if(full_cells[index_x + (index_y-1)*nb_x_cells]!=0) neighbors.push_back(full_cells[index_x + (index_y-1)*nb_x_cells]); }
                if(index_y<nb_y_cells-1) { if(full_cells[index_x + (index_y+1)*nb_x_cells]!=0) neighbors.push_back(full_cells[index_x + (index_y+1)*nb_x_cells]); }
                x = index_x*Constants::AREA_SPACING + static_cast<float>(rand() % (Constants::AREA_SPACING*100)) / 100.0;
                y = index_y*Constants::AREA_SPACING + static_cast<float>(rand() % (Constants::AREA_SPACING*100)) / 100.0;
                for(Vertex* v : neighbors) {
                    if(v->distanceTo(x, y)<Constants::AREA_SPACING) {
                        retry = true;
                        break;
                    }
                }
            }
            if(!retry) empty_cells.erase(empty_cells.begin()+index);
        } while(retry);
        Vertex* v = graph_representation->add_vertex(x, y);
        full_cells[index_x + index_y*nb_x_cells] = v;
    }
    delete [] full_cells;
}
