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

    extern const int           AREA_HEIGHT;                            /*  */
    extern const int           AREA_WIDTH;                             /*  */
    extern const int           AREA_SPACING;                           /*  */
    extern const unsigned char EDGE_ALGO_RESULT_COLOR_R;               /* red color of the edges that are the result of an algorithm */
    extern const unsigned char EDGE_ALGO_RESULT_COLOR_G;               /* green color of the edges that are the result of an algorithm */
    extern const unsigned char EDGE_ALGO_RESULT_COLOR_B;               /* blue color of the edges that are the result of an algorithm */
    extern const unsigned char EDGE_ALGO_SOURCE_COLOR_R;               /* in direction algorithms like shortest path, red color of the source */
    extern const unsigned char EDGE_ALGO_SOURCE_COLOR_G;               /* in direction algorithms like shortest path, green color of the source */
    extern const unsigned char EDGE_ALGO_SOURCE_COLOR_B;               /* in direction algorithms like shortest path, blue color of the source */
    extern const unsigned char EDGE_ALGO_DESTINATION_COLOR_R;          /* in direction algorithms like shortest path, red color of the destination */
    extern const unsigned char EDGE_ALGO_DESTINATION_COLOR_G;          /* in direction algorithms like shortest path, green color of the destination */
    extern const unsigned char EDGE_ALGO_DESTINATION_COLOR_B;          /* in direction algorithms like shortest path, blue color of the destination */
    extern const unsigned char EDGE_COLOR_R;                           /* default red color of the edges */
    extern const unsigned char EDGE_COLOR_G;                           /* default green color of the edges */
    extern const unsigned char EDGE_COLOR_B;                           /* default blue color of the edges */
    extern const int           EDGE_DEFAULT_CAPACITY;                  /* default capacity of an edge */
    extern const int           EDGE_MAXIMUM_CAPACITY;                  /* maximum capacity of an edge */
    extern const int           GRAPH_MINIMUM_VERTICES;                 /* minimum number of vertices for a graph */
    extern const int           GRAPH_NB_VERTICES_TRAVELING_SALESMAN;   /* defines the number of customers for the traveling salesman problem */
    extern const int           GRAPH_VERTICES_INCREMENTATION;          /* vertices added/deleted when changing the number of vertices of the graph */
    extern const unsigned char VERTEX_COLOR_R;                         /* default red color of vertices */
    extern const unsigned char VERTEX_COLOR_G;                         /* default green color of vertices */
    extern const unsigned char VERTEX_COLOR_B;                         /* default blue color of vertices */
    extern const unsigned char VERTEX_PATH_COLOR_R;                    /* red color for vertices that are on a path */
    extern const unsigned char VERTEX_PATH_COLOR_G;                    /* green color for vertices that are on a path */
    extern const unsigned char VERTEX_PATH_COLOR_B;                    /* blue color for vertices that are on a path */
    extern const unsigned char VERTEX_VISITED_COLOR_R;                 /* red color for vertices that were visited by an algorithm (when relevant) */
    extern const unsigned char VERTEX_VISITED_COLOR_G;                 /* green color for vertices that were visited by an algorithm (when relevant) */
    extern const unsigned char VERTEX_VISITED_COLOR_B;                 /* blue color for vertices that were visited by an algorithm (when relevant) */

}

enum GRAPH_TYPE        {ADJACENCY_MATRIX};          /* INCOMPLETE graph type enum - defines how the vertices and edges are stored */
enum GRAPH_ALGO        {FORD_FULKERSON};            /* INCOMPLETE algo enum - used for set_ready_for_algo() function */
enum GRAPH_ORIENTATION {ONE_WAY, TWO_WAYS, NONE};   /* if the graph is oriented, doubly oriented, or not oriented */

#endif
