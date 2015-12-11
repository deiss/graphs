##### Project: Graph-Theory
##### Author: DEISS Olivier
##### Started: September 2015

This project is a toolbox for Graph Theory. It includes graph algorithms and an interface to visualize them, using OpengGL. The project comes with a function to generate random Gabriel graphs. These graph look like road maps and are therefore nice for the study of lots of Graph algorithms. Unfortunately, they are not relevant for every of the implemented algorithms: for instance, the Bron-Kerbosch algorithm, that computes the clique number of the graph, will always return a triangle as the maximum clique.

Language: C++<br/>
Libraries: OpenGL, Glut

-----------------------------------------------------------------------------------

![screenshot](Screenshot.png)

From left to right:  minimum spanning tree (Prim), maximum flow (Ford-Fulkerson), shortest path and visited vertices (A*)

-----------------------------------------------------------------------------------

Keys (graph management):
 - '+': add more vertices
 - '-': remove vertices
 - '1': new graph
 - '2': create an oriented graph
 - '3': add weights to the edges
 - enter: dupplicate the graph
 - escape: delete the current graph
 - space: reset the current graph

Keys (algorithms): 
 - 'a': A*
 - 'b': Bron-Kerbosch
 - 'd': Dijkstra
 - 'e': Edmonds-Karp
 - 'f': Ford-Fulkerson
 - 'p': Prim
 - 't': Traveling Salesman



