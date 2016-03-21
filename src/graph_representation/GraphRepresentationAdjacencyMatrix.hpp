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

#ifndef GraphRepresentationAdjacencyMatrix_hpp
#define GraphRepresentationAdjacencyMatrix_hpp

#include "GraphRepresentation.hpp"
#include "components/Vertex.hpp"

class GraphRepresentationAdjacencyMatrix : public GraphRepresentation {

    public:
    
        GraphRepresentation& operator=(const GraphRepresentation&);
    
        GraphRepresentationAdjacencyMatrix(int nb_vertices);
        GraphRepresentationAdjacencyMatrix(const GraphRepresentationAdjacencyMatrix&);
        ~GraphRepresentationAdjacencyMatrix();
        GraphRepresentationAdjacencyMatrix& operator=(const GraphRepresentationAdjacencyMatrix&);
    
        Edge*                add_edge(const Vertex*, const Vertex*);
        Edge*                add_edge(const Vertex*, const Vertex*, double, double);
        Edge*                add_edge(const Vertex*, const Vertex*, unsigned char, unsigned char, unsigned char);
        Edge*                add_edge(const Vertex*, const Vertex*, double, double, unsigned char, unsigned char, unsigned char);
        Edge*                add_edge(const Edge*);
        Edge*                get_edge_from_to(int, int)                                  const;
        Edge*                get_edge_from_to(const Vertex*, const Vertex*)              const;
        int                  get_capacity_from_to(const Vertex*, const Vertex*)          const;
        int                  get_capacity_from_to(int, int)                              const;
        std::vector<Vertex*> get_all_neighbors(const Vertex*)                            const;
        std::set<Vertex*>    get_all_neighbors_set(const Vertex*)                        const;
        std::vector<Vertex*> get_direct_neighbors(const Vertex*, GRAPH_ORIENTATION)      const;
        void                 set_capacity_from_to(const Vertex*, const Vertex*, double);
    
    private:
    
        Edge*** matrix;   /* adjacency matrix */

};

#endif
