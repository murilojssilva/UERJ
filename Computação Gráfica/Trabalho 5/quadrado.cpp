/*
cd Desktop
gcc -o sist sistema.cpp -lglut -lGL -lGLU
./sist
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>


// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Inicializa (void)
{   
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}

