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

#ifndef Constants_hpp
#define Constants_hpp

namespace Constants {

    extern const int           AREA_HEIGHT;
    extern const int           AREA_WIDTH;
    extern const int           AREA_SPACING;
    extern const unsigned char EDGE_ALGO_RESULT_COLOR_R;
    extern const unsigned char EDGE_ALGO_RESULT_COLOR_G;
    extern const unsigned char EDGE_ALGO_RESULT_COLOR_B;
    extern const unsigned char EDGE_ALGO_SOURCE_COLOR_R;
    extern const unsigned char EDGE_ALGO_SOURCE_COLOR_G;
    extern const unsigned char EDGE_ALGO_SOURCE_COLOR_B;
    extern const unsigned char EDGE_ALGO_DESTINATION_COLOR_R;
    extern const unsigned char EDGE_ALGO_DESTINATION_COLOR_G;
    extern const unsigned char EDGE_ALGO_DESTINATION_COLOR_B;
    extern const unsigned char EDGE_COLOR_R;
    extern const unsigned char EDGE_COLOR_G;
    extern const unsigned char EDGE_COLOR_B;
    extern const int           EDGE_DEFAULT_CAPACITY;
    extern const int           EDGE_MAXIMUM_CAPACITY;
    extern const int           GRAPH_MINIMUM_VERTICES;
    extern const int           GRAPH_NB_VERTICES_TRAVELING_SALESMAN;
    extern const int           GRAPH_VERTICES_INCREMENTATION;
    extern const unsigned char VERTEX_COLOR_R;
    extern const unsigned char VERTEX_COLOR_G;
    extern const unsigned char VERTEX_COLOR_B;
    extern const unsigned char VERTEX_PATH_COLOR_R;
    extern const unsigned char VERTEX_PATH_COLOR_G;
    extern const unsigned char VERTEX_PATH_COLOR_B;
    extern const unsigned char VERTEX_VISITED_COLOR_R;
    extern const unsigned char VERTEX_VISITED_COLOR_G;
    extern const unsigned char VERTEX_VISITED_COLOR_B;

}

enum GRAPH_TYPE        {ADJACENCY_MATRIX}; //, ADJACENCY_LIST, INCIDENCE_MATRIX, INCIDENCE_LIST, };
enum GRAPH_ALGO        {FORD_FULKERSON};
enum GRAPH_ORIENTATION {ONE_WAY, TWO_WAYS, NONE};

#endif
