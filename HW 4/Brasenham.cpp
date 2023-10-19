#include <GL/glut.h>
#include <iostream>
#include <cmath>

int x1, y1, x2, y2;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    int dx = x2 - x1;
    int dy = y2 - y1;

    glBegin(GL_POINTS);
    glVertex2i(x1, y1);

    if (std::abs(dx) > std::abs(dy)) {
        int steps = std::abs(dx);

        float xIncrement = static_cast<float>(dx) / steps;
        float yIncrement = static_cast<float>(dy) / steps;

        float x = x1, y = y1;

        for (int i = 0; i < steps; i++) {
            x += xIncrement;
            y += yIncrement;
            glVertex2i(static_cast<int>(x), static_cast<int>(y));
        }
    } else {
        int steps = std::abs(dy);

        float xIncrement = static_cast<float>(dx) / steps;
        float yIncrement = static_cast<float>(dy) / steps;

        float x = x1, y = y1;

        for (int i = 0; i < steps; i++) {
            x += xIncrement;
            y += yIncrement;
            glVertex2i(static_cast<int>(x), static_cast<int>(y));
        }
    }

    glEnd();
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

    std::cout << "Masukkan koordinat A (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Masukkan koordinat A (x2 y2): ";
    std::cin >> x2 >> y2;

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
