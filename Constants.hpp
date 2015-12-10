#ifndef Constants_hpp
#define Constants_hpp

namespace Constants {

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
