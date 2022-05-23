#define GL_SILENCE_DEPRECATION
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void Desenha(void) {

    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);

    glVertex2f(-0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.5, -0.5);

    glEnd();
    glFlush();
}

void Inicializa(void) {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Segundo Programa");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutMainLoop();
    return 0;
}