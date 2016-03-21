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

#ifndef Vertex_hpp
#define Vertex_hpp

#include "constants/Constants.hpp"

class Vertex {
    
    public:
    
        Vertex(double x, double y, int id, unsigned char=Constants::VERTEX_COLOR_R, unsigned char=Constants::VERTEX_COLOR_G, unsigned char=Constants::VERTEX_COLOR_B);
        Vertex(const Vertex&);
        ~Vertex() {}
    
        Vertex &operator=(const Vertex&);
    
        unsigned char getColorR()                const { return color_r; }
        unsigned char getColorG()                const { return color_g; }
        unsigned char getColorB()                const { return color_b; }
        double        distanceTo(const Vertex*)  const;
        double        distanceTo(double, double) const;
        int           getId()                    const { return id; }
        double        getX()                     const { return x; }
        double        getY()                     const { return y; }
    
        void setColor(unsigned char r, unsigned char g, unsigned char b) { color_r = r; color_g = g; color_b = b; }

    private:
    
  const int           id;        /* identifier of the vertex */
  const double        x;         /* x coordinate of the vertex */
  const double        y;         /* y coordinate of the vertex */
        unsigned char color_r;   /* red color of the vertex */
        unsigned char color_g;   /* green color of the vertex */
        unsigned char color_b;   /* blue color of the vertex */

};

#endif
