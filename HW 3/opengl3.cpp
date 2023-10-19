#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

float x1, x2, y1, y2;

void display() {
    float dx, dy, step, x, y, k, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;

    if (std::abs(dx) > std::abs(dy)) {
        step = std::abs(dx);
    } else {
        step = std::abs(dy);
    }

    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;

    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan tampilan

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0); // Warna merah (R, G, B)
    glPointSize(3.0); // Ukuran titik
    glVertex2f(x, y);
    glEnd();

    for (k = 1; k <= step; k++) {
        x = x + Xin;
        y = y + Yin;

        glBegin(GL_POINTS);
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2f(x, y);
        glEnd();
    }

    glFlush();
}

void init() {
    glClearColor(0.7, 0.7, 0.7, 0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv) {
    printf("Enter the value of x1 : ");
    scanf("%f", &x1);
    printf("Enter the value of y1 : ");
    scanf("%f", &y1);
    printf("Enter the value of x2 : ");
    scanf("%f", &x2);
    printf("Enter the value of y2 : ");
    scanf("%f", &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800); // Ukuran jendela
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

