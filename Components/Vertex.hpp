#ifndef Vertex_hpp
#define Vertex_hpp

#include "Constants.hpp"

class Vertex {
    
    public :
    
        Vertex(double x, double y, int id, unsigned char=Constants::VERTEX_COLOR_R, unsigned char=Constants::VERTEX_COLOR_G, unsigned char=Constants::VERTEX_COLOR_B);
        Vertex(const Vertex&);
        ~Vertex() {}
        Vertex &operator=(const Vertex&);
    
        unsigned char  getColorR()                const { return color_r; }
        unsigned char  getColorG()                const { return color_g; }
        unsigned char  getColorB()                const { return color_b; }
        double         distanceTo(const Vertex*)  const;
        double         distanceTo(double, double) const;
        int            getId()                    const { return id; }
        double         getX()                     const { return x; }
        double         getY()                     const { return y; }
    
        void setColor(unsigned char r, unsigned char g, unsigned char b) { color_r = r; color_g = g; color_b = b; }

    private :
    
  const int    id;
  const double x;
  const double y;
        unsigned char color_r;
        unsigned char color_g;
        unsigned char color_b;

};

#endif