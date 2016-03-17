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

#ifndef Window_hpp
#define Window_hpp

class Graph;

class Window {

    public :
    
        Window();
        ~Window();

        int  add(const Graph*);
        void hide(int);
        void init();
        void launch(int)                        const;
 static void draw();
 static void keyboard(unsigned char, int, int);
 static void reshape(int, int);
        void replaceGraph(const Graph*, const Graph*);
    
    private :
    
 static std::vector<const Graph*>* graphs;
 
  const int width;
  const int height;

};

#endif
