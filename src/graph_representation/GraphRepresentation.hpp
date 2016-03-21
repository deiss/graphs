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

#ifndef GraphRepresentation_h
#define GraphRepresentation_h

#include <set>
#include <vector>

#include "constants/Constants.hpp"
#include "components/Edge.hpp"
#include "components/Vertex.hpp"

class GraphRepresentation {

    public:
    
        GraphRepresentation(int nb_vertices);
        GraphRepresentation(const GraphRepresentation&);
virtual ~GraphRepresentation();
virtual GraphRepresentation& operator=(const GraphRepresentation&) = 0;

        std::vector<Edge*>   *getEdges()    const { return edges; }
        std::vector<Vertex*> *getVertices() const { return vertices; }
    
virtual std::vector<Vertex*> get_all_neighbors(const Vertex*)                           const = 0;
virtual std::set<Vertex*>    get_all_neighbors_set(const Vertex*)                       const = 0;
virtual Edge*                get_edge_from_to(const Vertex*, const Vertex*)             const = 0;
virtual Edge*                get_edge_from_to(int, int)                                 const = 0;
virtual std::vector<Vertex*> get_direct_neighbors(const Vertex*, GRAPH_ORIENTATION)     const = 0;
virtual int                  get_capacity_from_to(const Vertex*, const Vertex*)         const = 0;
virtual int                  get_capacity_from_to(int, int)                             const = 0;
virtual void                 set_capacity_from_to(const Vertex*, const Vertex*, double)       = 0;

virtual Edge*   add_edge(const Vertex*, const Vertex*);
virtual Edge*   add_edge(const Vertex*, const Vertex*, double, double);
virtual Edge*   add_edge(const Vertex*, const Vertex*, unsigned char, unsigned char, unsigned char);
virtual Edge*   add_edge(const Vertex*, const Vertex*, double, double, unsigned char, unsigned char, unsigned char);
virtual Edge*   add_edge(const Edge*);
virtual Vertex* add_vertex(double=0, double=0);

    protected:
    
        void copy(const GraphRepresentation&);
        
  const int                   nb_vertices;   /* target number of vertices */
        std::vector<Edge*>*   edges;         /* list of edges */
        std::vector<Vertex*>* vertices;      /* list of vertices */
    
    private:
    
        int vertex_counter;   /* keeps the total number of vertices */

};

#endif
