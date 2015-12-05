#ifndef Constants_hpp
#define Constants_hpp

namespace Constants {

    extern unsigned char EDGE_ALGO_RESULT_COLOR_R;
    extern unsigned char EDGE_ALGO_RESULT_COLOR_G;
    extern unsigned char EDGE_ALGO_RESULT_COLOR_B;
    extern unsigned char EDGE_ALGO_SOURCE_COLOR_R;
    extern unsigned char EDGE_ALGO_SOURCE_COLOR_G;
    extern unsigned char EDGE_ALGO_SOURCE_COLOR_B;
    extern unsigned char EDGE_ALGO_DESTINATION_COLOR_R;
    extern unsigned char EDGE_ALGO_DESTINATION_COLOR_G;
    extern unsigned char EDGE_ALGO_DESTINATION_COLOR_B;
    extern unsigned char EDGE_COLOR_R;
    extern unsigned char EDGE_COLOR_G;
    extern unsigned char EDGE_COLOR_B;
    extern int           EDGE_DEFAULT_CAPACITY;
    extern int           EDGE_MAXIMUM_CAPACITY;
    extern int           GRAPH_MINIMUM_VERTICES;
    extern int           GRAPH_VERTICES_INCREMENTATION;
    extern unsigned char VERTEX_COLOR_R;
    extern unsigned char VERTEX_COLOR_G;
    extern unsigned char VERTEX_COLOR_B;
    extern unsigned char VERTEX_VISITED_COLOR_R;
    extern unsigned char VERTEX_VISITED_COLOR_G;
    extern unsigned char VERTEX_VISITED_COLOR_B;

}

enum GRAPH_TYPE        {ADJACENCY_MATRIX}; //, ADJACENCY_LIST, INCIDENCE_MATRIX, INCIDENCE_LIST, };
enum GRAPH_ALGO        {FORD_FULKERSON};
enum GRAPH_ORIENTATION {ONE_WAY, TWO_WAYS, NONE};

#endif
