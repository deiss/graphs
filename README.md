# Graphs

![Screenshot](media/Screenshot.png)

From left to right:  minimum spanning tree (Prim), maximum flow (Ford-Fulkerson), shortest path and visited vertices (A*)

Graphs is a toolbox for Graph Theory written in C++ with OpenGL and glut. It includes graph algorithms and an interface to visualize them. The project works with Gabriel graphs: these graphs look like road maps and are therefore nice for the study of lots of Graph algorithms.

***

### Install

##### Linux

You need to have glut installed on your platform. You can install it with:

	apt-get install freeglut3 freeglut3-dev

Then running `make linux` will compile *FFTOcean* in *bin*. You can run `make clean` to delete the build directory.

##### Mac

You need to have XCode installed on your system. Then running `make mac` will compile *FFTOcean* in *bin*. You can run `make clean` to delete the build directory.

***

### Use

Call `bin/graphs` to launch the application. You can manage graphs and windows with the following keys: 
* '+': add more vertices
* '-': remove vertices
* '1': new graph
* '2': create an oriented graph
* '3': add weights to the edges
* enter: dupplicate the graph
* escape: delete the current graph
* space: reset the current graph

You can call the different implemented algorithms with:
* 'a': A*
* 'b': Bron-Kerbosch
* 'd': Dijkstra
* 'e': Edmonds-Karp
* 'f': Ford-Fulkerson
* 'p': Prim
* 't': Traveling Salesman
