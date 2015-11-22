#include <chrono>
#include <iostream>
#include <cmath>
#include <thread>

#ifdef __linux__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "Graph.hpp"

/* Main draw function. */
void Graph::draw() const {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    draw_edges();
    draw_vertices();
    glutSwapBuffers();
    glutPostRedisplay();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

/* Draws the edges, and the arc directions and capacities if set. */
void Graph::draw_edges() const {
    for(Edge *e : *graph_representation->getEdges()) {
        double v1x = e->getV1()->getX();
        double v1y = e->getV1()->getY();
        double v2x = e->getV2()->getX();
        double v2y = e->getV2()->getY();
        double c1 = e->getCapacityV1ToV2();
        double c2 = e->getCapacityV2ToV1();
        double c = c1>c2 ? c1 : c2;
        glLineWidth(static_cast<float>(c)*Constants::EDGE_MAXIMUM_CAPACITY/30);
        glColor3ub(e->getColorR(), e->getColorG(), e->getColorB());
        glBegin(GL_LINES);
        glVertex2d(v1x, v1y);
        glVertex2d(v2x, v2y);
        glEnd();
        glLineWidth(1);
        draw_edge_capacity(e);
        draw_edge_direction(e);
        
    }
}

/* Displays the edge's capacity */
void Graph::draw_edge_capacity(Edge *e) const {
    double v1x = e->getV1()->getX();
    double v1y = e->getV1()->getY();
    double v2x = e->getV2()->getX();
    double v2y = e->getV2()->getY();
    double c1 = e->getCapacityV1ToV2();
    double c2 = e->getCapacityV2ToV1();
    if(arc_integer_capacities_defined) {
        glPushMatrix();
        glLoadIdentity();
        float xoff = 0.015;
        float yoff = 0.017;
        if(orientation==ONE_WAY || orientation==NONE) {
            if(v1x!=v2x) {
                float slope = (v1y-v2y)/(v1x-v2x);
                if(slope>0) { glRasterPos2f(0.5*(v1x+v2x-4*xoff), 0.5*(v1y+v2y+yoff)); }
                else        { glRasterPos2f(0.5*(v1x+v2x+xoff), 0.5*(v1y+v2y+yoff)); }
            }
            else {
                glRasterPos2f(0.5*(v1x+v2x+xoff), 0.5*(v1y+v2y+yoff));
            }
            char       buf1[10];
            const char *p1(buf1);
            strcpy(buf1, std::to_string((c1*100)/100).c_str());
            int cpt = 0;
            do glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *p1); while(*(++p1) && cpt++<2+(int)log10(c1));
        }
        else if(orientation==TWO_WAYS) {
            double coeff = 7;
            if(v1x!=v2x) {
                float slope = (v1y-v2y)/(v1x-v2x);
                if(slope>0) { glRasterPos2f(0.5*(v1x+v2x-4*xoff), 0.5*(v1y+v2y+coeff*yoff)); }
                else        { glRasterPos2f(0.5*(v1x+v2x+xoff), 0.5*(v1y+v2y+coeff*yoff)); }
            }
            else {
                glRasterPos2f(0.5*(v1x+v2x+xoff), 0.5*(v1y+v2y+coeff*yoff));
            }
            char       buf2[10];
            const char *p2(buf2);
            strcpy(buf2, std::to_string((c2*100)/100).c_str());
            int cpt = 0;
            do glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *p2); while(*(++p2) && cpt++<2+(int)log10(c2));
        }
        glPopMatrix();
    }
}

void Graph::draw_edge_direction(Edge *e) const {
    double v1x = e->getV1()->getX();
    double v1y = e->getV1()->getY();
    double v2x = e->getV2()->getX();
    double v2y = e->getV2()->getY();
    if(orientation==ONE_WAY || orientation==TWO_WAYS) {
        if(orientation==ONE_WAY) {
            glPushMatrix();
            glLoadIdentity();
            glTranslatef(v2x, v2y, 0);
            if(v1x!=v2x) {
                float phase = v1x>v2x ? M_PI : 0;
                float slope = (v1y-v2y)/(v1x-v2x);
                float angle = atan(slope);
                glRotatef(180*(angle+phase)/M_PI, 0, 0, 1);
            }
            else {
                float phase = v2y>v1y ? 0 : M_PI;
                glRotatef(180*(M_PI*0.5+phase)/M_PI, 0, 0, 1);
            }
            float len  = 0.018;
            float xoff = 0.02;
            glBegin(GL_TRIANGLES);
            glVertex2d(-len-xoff, len);
            glVertex2d(-xoff, 0);
            glVertex2d(-len-xoff, -len);
            glEnd();
            glPopMatrix();
        }
        else if(orientation==TWO_WAYS) { ///////////////// A MODIFIER
            glPushMatrix();
            glLoadIdentity();
            glTranslatef(v1x, v1y, 0);
            if(v1x!=v2x) {
                float phase = v1x>v2x ? M_PI : 0;
                float slope = (v1y-v2y)/(v1x-v2x);
                float angle = atan(slope);
                glRotatef(180*(angle+phase)/M_PI, 0, 0, 1);
            }
            else {
                float phase = v2y>v1y ? 0 : M_PI;
                glRotatef(180*(M_PI*0.5+phase)/M_PI, 0, 0, 1);
            }
            float len  = 0.018;
            float xoff = 0.02;
            glColor3ub(255, 255, 255);
            glBegin(GL_TRIANGLES);
            glVertex2d(len+xoff, len);
            glVertex2d(0+xoff, 0);
            glVertex2d(len+xoff, -len);
            glEnd();
            glColor3ub(e->getColorR(), e->getColorG(), e->getColorB());
            glBegin(GL_LINE_LOOP);
            glVertex2d(len+xoff, len);
            glVertex2d(0+xoff, 0);
            glVertex2d(len+xoff, -len);
            glEnd();
            glPopMatrix();
        }
    }
}

/* Draws the vertices as circles. */
void Graph::draw_vertices() const {
    for(Vertex *v : *graph_representation->getVertices()) {
        glColor3ub(0, 0, 0);
        glPointSize(10);
        glBegin(GL_POINTS);
        glVertex2d(v->getX(), v->getY());
        glEnd();
        glColor3ub(v->getColorR(), v->getColorG(), v->getColorB());
        glPointSize(8);
        glBegin(GL_POINTS);
        glVertex2d(v->getX(), v->getY());
        glEnd();
    }
}
