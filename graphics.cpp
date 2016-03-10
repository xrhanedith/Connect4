/*
 * Copyright (c) 2009, 2014 University of Michigan, Ann Arbor.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of Michigan, Ann Arbor. The name of the University 
 * may not be used to endorse or promote products derived from this 
 * software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include "graphics.h"
#include "connect4.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// window width and height
GLdouble width, height;

// mouse x and y coordinates
int mouseX, mouseY;

// GLUT window handle
int wd;

// Connect4 Board and Result
Board board;
Result r;

void init(void)
{
    // initial window width and height,
    // within which we draw. (0,0) is the lower left corner
    width  = 600.0;
    height = 600.0;

    mouseX = 0;
    mouseY = 0;
    
    r = NoResult;

    return;
}

void drawCircle(int x, int y, int radius) {
    double theta = M_PI/20.0;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(x, y);
    for (double i = 0; i < 2*M_PI+theta; i += theta) {
        glVertex2i(x+radius*cos(i), y+radius*sin(i));
    }
    glEnd();
}

void display(void)
{
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.f, 1.f);
    
    
    int side_border = 25;
    int bottom_border = 50;
    int top_border = 75;
    // clear the screen */
    glClear(GL_COLOR_BUFFER_BIT);
  
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(side_border,bottom_border);
    glVertex2i(width-side_border,bottom_border);
    glVertex2i(width-side_border,height-top_border);
    glVertex2i(side_border,height-top_border);
    glEnd();
    
    // Your code here...
    // What do you want to display in the window?
    
    // force drawing to start
    glutSwapBuffers();

    return;
}

void reshape(int w, int h)
{
    glutPostRedisplay();
    
    return;
}

void refresh(void)
{
    glutPostRedisplay();

    return;
}

void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    
    glutPostRedisplay();

    return;
}

void cursor(int x, int y)
{
    glutPostRedisplay();

    return;
}

void drag(int x, int y)
{
    glutPostRedisplay();

    return;
}

void mouse(int button, int state, int x, int y)
{
    glutPostRedisplay();

    return;
}

int graphicsPlay(int argc, char *argv[])
{
    // perform initialization NOT OpenGL/GLUT dependent,
    // as we haven't created a GLUT window yet
    init();
    
    // initialize GLUT, let it extract command-line
    // GLUT options that you may provide
    // - NOTE THE '&' BEFORE argc
    glutInit(&argc, argv);
    
    // specify the display to be single
    // buffered and color as RGBA values
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    
    // set the initial window size
    glutInitWindowSize((int) width, (int) height);
  
    // create the window and store the handle to it
    wd = glutCreateWindow("Connect 4");
    
    // --- register callbacks with GLUT ---

    // register function that draws in the window
    glutDisplayFunc(display);

    // register function to handle window resizes
    glutReshapeFunc(reshape);

    // register the provided refresh()
    // function to call when system is idle
    glutIdleFunc(refresh);
    
    // register keyboard press event processing function
    glutKeyboardFunc(kbd);

    // register cursor moved event callback
    glutPassiveMotionFunc(cursor);

    // register mouse clicked event callback
    glutMouseFunc(mouse);

    // register mouse dragged event callback
    glutMotionFunc(drag);

    // Set up initial OpenGL context
    // clear color buffer to white
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // start the GLUT main loop
    glutMainLoop();

    return 0;
}
