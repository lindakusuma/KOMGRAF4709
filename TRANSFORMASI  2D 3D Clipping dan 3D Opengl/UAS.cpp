#include <GL/glut.h>
#include <cmath>


float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float translateX = 0.0f;
float translateY = 0.0f;
float translateZ = -5.0f;
float scaleValue = 1.0f;

void init() {
    glEnable(GL_DEPTH_TEST);
}

void drawCube() {
    glPushMatrix();

    glColor3f(1.0f, 0.5f, 0.5f); // Warna pink

    // Gambar kubus di sini
    glutSolidCube(1.0);
    //glutWireCube(1.0);

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    
    glTranslatef(translateX, translateY, translateZ); // Pergeseran ke belakang
    
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotasi terhadap sumbu X
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotasi terhadap sumbu Y
    glRotatef(angleZ, 0.0f, 0.0f, 2.0f); // Rotasi terhadap sumbu Z

    glScalef(scaleValue, scaleValue, scaleValue);
    
    glColor3f(0.7f, 0.2f, 0.2f); // Warna objek
    
    drawCube();
    
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            angleX += 5.0f;
            break;
        case 's':
            angleX -= 5.0f;
            break;
        case 'a':
            angleY -= 5.0f;
            break;
        case 'd':
            angleY += 5.0f;
            break;
        case 'f':
            angleZ += 5.0f;
            break;
        case 'g':
            angleZ -= 5.0f;
            break;
        case 'r':
            translateX += 0.1f;
            break;
        case 'e':
            translateX -= 0.1f;
            break;
        case 't':
            translateY += 0.1f;
            break;
        case 'y':
            translateY -= 0.1f;
            break;
        case 'h':
            translateZ += 1.0f;
            break;
        case 'u':
            translateZ -= 1.0f;
            break;
        case 'i':
            scaleValue -= 1.0f;
            break;
        case 'k':
            scaleValue += 1.0f;
            break;
        case 'x':
    		angleX = 0.0f;
    		angleY = 0.0f;
    		angleZ = 0.0f;
    		translateX = 0.0f;
    		translateY = 0.0f;
    		translateZ = -3.0f;
    		scaleValue = 1.0f;
    		break;


        
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("3D Transformation By Linda");

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    init();
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
}
