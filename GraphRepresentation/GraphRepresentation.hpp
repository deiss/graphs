#ifndef GraphRepresentation_h
#define GraphRepresentation_h

#include <vector>

#include "Constants.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

class GraphRepresentation {

    public :
    
        GraphRepresentation(int nb_vertices);
        GraphRepresentation(const GraphRepresentation&);
virtual ~GraphRepresentation();
virtual GraphRepresentation& operator=(const GraphRepresentation&) = 0;

        std::vector<Edge*>   *getEdges()    const { return edges; }
        std::vector<Vertex*> *getVertices() const { return vertices; }
    
virtual std::vector<Vertex*> get_all_neighbors(const Vertex*)                       const = 0;
virtual Edge*                get_edge_from_to(const Vertex*, const Vertex*)         const = 0;
virtual Edge*                get_edge_from_to(int, int)                             const = 0;
virtual std::vector<Vertex*> get_direct_neighbors(const Vertex*, GRAPH_ORIENTATION) const = 0;
virtual int                  get_capacity_from_to(const Vertex*, const Vertex*)     const = 0;
virtual int                  get_capacity_from_to(int, int)                         const = 0;
virtual void                 set_capacity_from_to(const Vertex*, const Vertex*, double) = 0;

virtual Edge*   add_edge(const Vertex*, const Vertex*);
virtual Edge*   add_edge(const Vertex*, const Vertex*, double, double);
virtual Edge*   add_edge(const Vertex*, const Vertex*, unsigned char, unsigned char, unsigned char);
virtual Edge*   add_edge(const Vertex*, const Vertex*, double, double, unsigned char, unsigned char, unsigned char);
virtual Edge*   add_edge(const Edge*);
virtual Vertex* add_vertex(double=0, double=0);

    protected :
    
        void copy(const GraphRepresentation&);
        
  const int                   nb_vertices;
        std::vector<Edge*>*   edges;
        std::vector<Vertex*>* vertices;
    
    private :
    
        int vertex_counter;

};

#endif
