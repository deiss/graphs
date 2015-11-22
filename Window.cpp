#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

#ifdef __linux__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "Graph.hpp"
#include "Window.hpp"

/* Static variables. */
std::vector<const Graph *> *Window::graphs;

/* Window constructor. */
Window::Window()
    : width(640), height(480) {
    graphs = new std::vector<const Graph *>;
}

/* Window destructor. */
Window::~Window() {
    delete graphs;
}

/* Initialization function. */
void Window::init() {
    int argc = 1;
    char *argv[1] = {(char *)"Graphs"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(width, height);
}

/* Creates a new window for a new Graph. */
int Window::add(const Graph *g) {
    graphs->push_back(g);
    return glutCreateWindow("");
}

/* Destroys the window. */
void Window::hide(int window_id) {
    for(std::vector<const Graph *>::iterator it=graphs->begin() ; it!=graphs->end() ; it++) {
        if((*it)->getWindowId()==window_id) {
            graphs->erase(it);
            break;
        }
    }
    glutDestroyWindow(window_id);
}

/* Calls the Graph draw() function. */
void Window::draw() {
    for(const Graph *graph : *graphs) {
        if(glutGetWindow()==graph->getWindowId()) {
            graph->draw();
        }
    }
}

/* Calls the Graph keyboard() function. */
void Window::keyboard(unsigned char key, int x, int y) {
    for(const Graph *graph : *graphs) {
        if(glutGetWindow()==graph->getWindowId()) {
            const_cast<Graph *>(graph)->keyboard(key, x, y);
            break;
        }
    }
}

/* Initializes new windows. */
void Window::launch(int window_id) const {
    glutSetWindow(window_id);
    glutSetWindowTitle(("Graph - " + std::to_string(window_id)).c_str());
    glClearColor(1, 1, 1, 1);
    glutReshapeFunc(reshape);
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

/* Reshape function. */
void Window::reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

/* Updates the Graph handler with the new Graph. */
void Window::replaceGraph(const Graph *old_graph, const Graph *new_graph) {
    for(std::vector<const Graph *>::iterator it=graphs->begin() ; it!=graphs->end() ; it++) {
        if(*it==old_graph) {
            graphs->erase(it);
            graphs->push_back(new_graph);
            break;
        }
    }
}

