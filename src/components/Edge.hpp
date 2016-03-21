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

#ifndef Edge_hpp
#define Edge_hpp

#include "constants/Constants.hpp"
#include "Vertex.hpp"

class Edge {

    public:
    
        Edge(const Vertex*, const Vertex*);
        Edge(const Vertex*, const Vertex*, double, double);
        Edge(const Vertex*, const Vertex*, double, double, unsigned char, unsigned char, unsigned char);
        Edge(const Vertex*, const Vertex*, unsigned char, unsigned char, unsigned char);
        Edge(const Vertex*, const Vertex*, unsigned char, unsigned char, unsigned char, double, double);
        ~Edge() {}
    
        Edge& operator=(const Edge&);
    
        unsigned char getColorR()         const { return color_r; }
        unsigned char getColorG()         const { return color_g; }
        unsigned char getColorB()         const { return color_b; }
        double        getCapacityV1ToV2() const { return capacity_v1_v2; }
        double        getCapacityV2ToV1() const { return capacity_v2_v1; }
        Vertex*       getV1()             const { return v1; }
        Vertex*       getV2()             const { return v2; }
    
        void setColor(unsigned char r, unsigned char g, unsigned char b) { color_r = r; color_g = g; color_b = b; }
        void setCapacityV1ToV2(double c)                                 { capacity_v1_v2 = c; }
        void setCapacityV2ToV1(double c)                                 { capacity_v2_v1 = c; }
        void switch_vertices();
    
    private:
    
        unsigned char color_r;          /* red color of the edge */
        unsigned char color_g;          /* green color of the edge */
        unsigned char color_b;          /* blue color of the edge */
        double        capacity_v1_v2;   /* capacity of the arc from v1 to v2 */
        double        capacity_v2_v1;   /* capacity of the arc from v2 to v1 */
        Vertex*       v1;               /* vertex v1 */
        Vertex*       v2;               /* vertex v2 */

};

#endif
