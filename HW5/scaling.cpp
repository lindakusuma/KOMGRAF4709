#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>

float xAwal, yAwal, xEnd, yEnd;

void tampilan(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-20, 30, -20, 30, -20, 30);
}

void aturPixel(GLint xCoordinate, GLint yCoordinate) {
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void scalar(GLint x0, GLint y0, GLint sx, GLint sy) {
    aturPixel(x0, y0);
    GLint xAkhir = x0 * sx;
    GLint yAkhir = y0 * sy;
    GLint xtemp = x0;
    GLint ytemp = y0;
    while (xtemp < xAkhir || ytemp < yAkhir) {
        if (xtemp < xAkhir) {
            xtemp++;
        } else if (ytemp < yAkhir) {
            ytemp++;
        }
        aturPixel(xtemp, ytemp);
    }
    aturPixel(xAkhir, yAkhir);
}

void gambarScalar(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    scalar(xAwal, yAwal, xEnd, yEnd);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Scaling 2D NIM 13033");
    tampilan();

    printf("Masukkan koordinat titik awal (x0 y0): ");
    scanf("%f %f", &xAwal, &yAwal);
    printf("Masukkan titik skala (sx sy): ");
    scanf("%f %f", &xEnd, &yEnd);
    glutDisplayFunc(gambarScalar);
    glutMainLoop();

    return 0;
}