#ifndef Edge_hpp
#define Edge_hpp

#include "Constants.hpp"
#include "Vertex.hpp"

class Edge {

    public :
    
        Edge(const Vertex*, const Vertex*);
        Edge(const Vertex*, const Vertex*, double, double);
        Edge(const Vertex*, const Vertex*, double, double, unsigned char, unsigned char, unsigned char);
        Edge(const Vertex*, const Vertex*, unsigned char, unsigned char, unsigned char);
        Edge(const Vertex*, const Vertex*, unsigned char, unsigned char, unsigned char, double, double);
        ~Edge() {}
        Edge& operator=(const Edge&);
    
        unsigned char   getColorR()         const { return color_r; }
        unsigned char   getColorG()         const { return color_g; }
        unsigned char   getColorB()         const { return color_b; }
        double          getCapacityV1ToV2() const { return capacity_v1_v2; }
        double          getCapacityV2ToV1() const { return capacity_v2_v1; }
        Vertex*         getV1()             const { return v1; }
        Vertex*         getV2()             const { return v2; }
    
        void setColor(unsigned char r, unsigned char g, unsigned char b) { color_r = r; color_g = g; color_b = b; }
        void setCapacityV1ToV2(double c)                                 { capacity_v1_v2 = c; }
        void setCapacityV2ToV1(double c)                                 { capacity_v2_v1 = c; }
        void switch_vertices();
    
    private :
    
        unsigned char  color_r;
        unsigned char  color_g;
        unsigned char  color_b;
        double         capacity_v1_v2;
        double         capacity_v2_v1;
        Vertex*        v1;
        Vertex*        v2;

};

#endif