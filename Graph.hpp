/* possible de copier que des graphes de meme nb vertices
ce nombre de ne peut pas changer */

#ifndef Graph_hpp
#define Graph_hpp

#include <map>
#include <vector>
#include <set>

#include "Edge.hpp"
#include "GraphRepresentation.hpp"
#include "Vertex.hpp"
#include "Window.hpp"

class Graph {

    public :

        Graph(GRAPH_TYPE, int);
        Graph(const Graph&);
        ~Graph();
        Graph& operator=(const Graph&);
    
 static void setWindow(Window* w) { window = w; }
    
        int        getNbVertices() const { return nb_vertices; }
        GRAPH_TYPE getType()       const { return type; }
        int        getWindowId()   const { return window_id; }
    
        void setDisplayed(bool displayed)        { is_displayed = displayed; }
        void setOrientation(GRAPH_ORIENTATION o) { orientation = o; }
        void setWindowId(int id)                 { window_id = id; }
    
        Edge*                       add_edge(const Vertex*, const Vertex*, double=Constants::EDGE_DEFAULT_CAPACITY);
        Vertex*                     add_vertex(double=0, double=0);
        void                        clear();
        void                        clear_color();
        void                        clear_color_edges();
        void                        clear_color_vertices();
        void                        delete_graph();
        bool                        display();
        void                        draw() const;
        void                        generate();
        void                        generate_gabriel_naive();
        void                        generate_random_arc_integer_capacities();
        void                        generate_random_arc_directions();
        void                        generate_random_vertices();
        void                        generate_random_vertices_spacing();
        double                      get_total_weight();
        std::vector<const Edge*>*   handler_astar(Vertex* =0, Vertex* =0);
        std::set<const Vertex*>*    handler_bron_kerbosch();
        std::vector<const Edge*>*   handler_dijkstra(Vertex* =0, Vertex* =0);
        int                         handler_edmonds_karp(Vertex* =0, Vertex* =0);
        int                         handler_ford_fulkerson(Vertex* =0, Vertex* =0);
        std::vector<const Edge*>*   handler_prim();
        std::vector<const Vertex*>* handler_traveling_salesman(Vertex* =0, std::vector<const Vertex*>* =0);
        void                        keyboard(unsigned char, int, int);
        Graph*                      rebuild_graph(int);
        void                        set_ready_for_algo(GRAPH_ALGO algo);
 
    private :
    
        class IncidenceMatrix;
        class IncidenceList;
        class AdjacencyMatrix;
        class AdjacencyList;
    
 static int     graph_counter;
 static Window* window;

        std::vector<const Edge*>*   algo_astar(const Vertex*, const Vertex*, bool=false);
        std::set<const Vertex*>*    algo_bron_kerbosch();
        bool                        algo_bron_kerbosch_callback(std::vector<std::set<const Vertex*>>*, std::set<const Vertex*>, std::set<const Vertex*>, std::set<const Vertex*>);
        std::vector<const Edge*>*   algo_dijkstra(const Vertex*, const Vertex*);
        int                         algo_edmonds_karp(const Vertex*, const Vertex*);
        bool                        algo_edmonds_karp_bfs(const Graph*, std::map<const Vertex*, double>*, std::map<const Vertex*, const Vertex*>*, const Vertex*, const Vertex*);
        int                         algo_ford_fulkerson(const Vertex*, const Vertex*);
        bool                        algo_ford_fulkerson_dfs(const Graph*, std::vector<const Vertex*>*, std::set<const Vertex*>*, const Vertex*, const Vertex*);
        std::vector<const Edge*>*   algo_prim();
        std::vector<const Vertex*>* algo_traveling_salesman(const Vertex*, std::vector<const Vertex*>*);
        void                        algo_traveling_salesman_callback(double**, std::map<const Vertex*, int>, const Vertex*, std::vector<const Vertex*>*, std::vector<const Vertex*>*, std::vector<const Vertex*>*, std::set<const Vertex*>*, double, double*);
        double**                    algo_traveling_salesman_cost_matrix(const Vertex*, std::vector<const Vertex*>*);
        void                        draw_edges()               const;
        void                        draw_edge_capacity(Edge*)  const;
        void                        draw_edge_direction(Edge*) const;
        void                        draw_vertices()            const;
        void                        keyboard_capacities();
        void                        keyboard_directions();
        bool                        keyboard_dupplicate();
        void                        select_one_random_vertices(const Vertex**)                                 const;
        void                        select_two_random_vertices(const Vertex**, const Vertex**)                 const;
        void                        select_n_random_vertices(std::vector<const Vertex*>**, int, const Vertex*) const;

  const int                  nb_vertices;
  const GRAPH_TYPE           type;
        bool                 arc_integer_capacities_defined;
        GraphRepresentation* graph_representation;
        bool                 is_displayed;
        GRAPH_ORIENTATION    orientation;
        int                  window_id;

};

#endif