#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
#include<stdlib.h>
using  std::cin;
int xcircle, ycircle,radius;

void BresenhamCircle(int xc, int yc, int r)
{
    int x, y, d;
    x = 0;
    y = r;
    d = 3 - 2 * r;
    glVertex2i(x + xc, y + yc);
    while (x < y)
    {
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
        glVertex2i(x + xc, y + yc);
        glVertex2i(y + xc, x + yc);
        glVertex2i(y + xc, -x + yc);
        glVertex2i(x + xc, -y + yc);
        glVertex2i(-x + xc, -y + yc);
        glVertex2i(-y + xc, -x + yc);
        glVertex2i(-x + xc, y + yc);
        glVertex2i(-y + xc, x + yc);
    }
}

void circleSegment() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    BresenhamCircle(xcircle, ycircle, radius);
    glEnd();
    glFlush();
}

void main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    printf("请输入圆的x中心、y中心点以及半径:");
    cin >>xcircle>>ycircle>>radius;
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham画圆算法");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutDisplayFunc(circleSegment);
    glutMainLoop();
}
