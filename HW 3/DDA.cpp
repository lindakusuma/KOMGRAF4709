#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

int x1, y1, x2, y2;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    int dx = x2 - x1;
    int dy = y2 - y1;

    if (dx == 0) { // Menangani kasus garis vertikal
        int y = y1;
        int y_end = y2;
        glBegin(GL_POINTS);
        while (y <= y_end) {
            glVertex2i(x1, y);
            y++;
        }
        glEnd();
    } else {
        float m = static_cast<float>(dy) / dx;

        int langkah = abs(dx) > abs(dy) ? abs(dx) : abs(dy;

        glBegin(GL_POINTS);

        for (int i = 0; i <= langkah; i++) {
            // Hitung titik berikutnya
            int x = x1 + i;
            int y = y1 + m * i;

            glVertex2i(x, y);
        }

        glEnd();
    }

    glFlush();
}

void init() {
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Garis Koordinat");

    init();

    std::cout << "Masukkan koordinat garis pertama (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Masukkan koordinat garis kedua (x2 y2): ";
    std::cin >> x2 >> y2;

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
