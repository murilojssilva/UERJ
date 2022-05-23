/*
cd Desktop
gcc -o sist sistema.cpp -lglut -lGL -lGLU
./sist
*/

#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

GLfloat raioSol = 0.45f;
GLfloat raioTerra = 0.1f;
GLfloat raioLua = 0.03f;
GLfloat raioRosa = 0.07f;
GLfloat orbitaTerra = 0.8f;
GLfloat orbitaLua = 0.2f;
GLfloat orbitaRosa = 1.2f;
GLfloat velocidade = 0.9f;
GLfloat anoRosa = 0.0f;
GLfloat anoTerra = 0.0f;
GLfloat diaRosa = 0.0f;
GLfloat diaTerra = 0.0f;
GLfloat cicloLunar = 0.0f;
GLfloat rotacaoTerra = 0.0f;
GLfloat rotacaoRosa = 0.0f;

GLfloat cicloLunarTransl = 15*velocidade;
GLfloat anoTerraTransl = ((365/360)*velocidade);
GLfloat anoRosaTransl = ((365/360)*5*velocidade);
GLfloat diaRosaRotac = 1*velocidade;
GLfloat diaTerraRotac = 10*velocidade;

void Desenha(void);
void AlteraTamanhoJanela(GLsizei larg, GLsizei alt);
void Inicializa (void);
void sistemaPlanetario(void);
void Movimenta(void);
void Rotaciona(int value);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("Sistema Planetário");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	Inicializa();
//	glutTimerFunc(25, Rotaciona, 0);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutDisplayFunc(Desenha);
	glutIdleFunc(Movimenta);
	glutMainLoop();
	return 0;
}

void sistemaPlanetario(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0,0.0,4.0,
		  0.0,0.0,3.0,
		  0.0,2.0,0.0);
	// Sol
	glColor3f(1.0,0.8,0.3);
	glutSolidSphere(raioSol,50,50);

	// Planeta Cor-de-Rosa
	glPushMatrix();
	    glRotatef(anoRosa,0.0,0.0,1.0);
	    glTranslatef((-1)*orbitaRosa,0.0,0.0);
	   
	    glPushMatrix();
		glRotatef(diaRosa,0.0,0.0,1.0);
		glColor3f(0.9,0.0,0.7);
		glutSolidSphere(raioRosa,50,50);
	    glPopMatrix();
	glPopMatrix();

	glPushMatrix();

	    // Terra
	    glRotatef(anoTerra,0.0,0.0,1.0);
	    glTranslatef((-1)*orbitaTerra,0.0,0.0);

	    glPushMatrix();
		glRotatef(diaTerra,0.0,0.0,1.0);
		glColor3f(0.2,0.2,1.0);
		glutSolidSphere(raioTerra,50,50);  
	    glPopMatrix();		
              
	    // Lua
	    glRotatef(cicloLunar,0.0,0.0,1.0);
	    glTranslatef((-1)*orbitaLua,0.0,0.0);
	    glColor3f(0.5,0.5,0.5);
	    glutSolidSphere(raioLua,50,50);
	glPopMatrix(); 

	glFlush();
	glutSwapBuffers(); 
	
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	sistemaPlanetario();
	glFlush();
	glutSwapBuffers();
}

void Inicializa(void)
{   
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void AlteraTamanhoJanela(GLsizei larg, GLsizei alt)
{
	if ((larg == 0) || (alt == 0))
	     return;   
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity(); 
	gluPerspective(39.0, (GLdouble)larg/(GLdouble)alt, 0.6, 21.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, larg, alt);
	Desenha();
}


void Movimenta(void)
{
	diaRosa += diaRosaRotac;
	diaTerra += diaTerraRotac;
	cicloLunar += cicloLunarTransl;
	anoTerra += anoTerraTransl;
	anoRosa += anoRosaTransl;
	Desenha();
}

/*
void Rotaciona(int value)
{
	diaRosa += diaRosa;
	rotacaoTerra += 1.0f;
	if (rotacaoTerra > 360.f)
	    rotacaoTerra -= 360;
	glutPostRedisplay();
	glutTimerFunc(500, Rotaciona, 0);

	rotacaoRosa += 1.0f;
	if (rotacaoRosa > 360.f)
	    rotacaoRosa -= 360;
	glutPostRedisplay();
	glutTimerFunc(500, Rotaciona, 0);
}*/

