#ifndef GraphRepresentationAdjacencyMatrix_hpp
#define GraphRepresentationAdjacencyMatrix_hpp

#include "GraphRepresentation.hpp"
#include "Vertex.hpp"

class GraphRepresentationAdjacencyMatrix : public GraphRepresentation {

    public :
    
        GraphRepresentation& operator=(const GraphRepresentation&);
    
        GraphRepresentationAdjacencyMatrix(int nb_vertices);
        GraphRepresentationAdjacencyMatrix(const GraphRepresentationAdjacencyMatrix&);
        ~GraphRepresentationAdjacencyMatrix();
        GraphRepresentationAdjacencyMatrix& operator=(const GraphRepresentationAdjacencyMatrix&);
    
        Edge*                  add_edge(const Vertex*, const Vertex*);
        Edge*                  add_edge(const Vertex*, const Vertex*, double, double);
        Edge*                  add_edge(const Vertex*, const Vertex*, unsigned char, unsigned char, unsigned char);
        Edge*                  add_edge(const Vertex*, const Vertex*, double, double, unsigned char, unsigned char, unsigned char);
        Edge*                  add_edge(const Edge*);
        Edge*                  get_edge_from_to(int, int)                             const;
        Edge*                  get_edge_from_to(const Vertex*, const Vertex*)         const;
        int                    get_capacity_from_to(const Vertex*, const Vertex*)     const;
        int                    get_capacity_from_to(int, int)                         const;
        std::vector<Vertex*>   get_all_neighbors(const Vertex*)                       const;
        std::set<Vertex*>      get_all_neighbors_set(const Vertex*)                   const;
        std::vector<Vertex*>   get_direct_neighbors(const Vertex*, GRAPH_ORIENTATION) const;
        void                   set_capacity_from_to(const Vertex*, const Vertex*, double);
    
    private :
    
        Edge*** matrix;

};

#endif