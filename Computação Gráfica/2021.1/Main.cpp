/* Trabalho Final de Computação Gráfica Alunos: Flávia Avelino dos Santos e Murilo de Jesus Santos Silva  */



#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<stdio.h>
#include <SistemaSolar.h>
#include<Asteroids.h>
#include<Constants.h>
#include "Main.h"

using namespace std;

int fig;
const int maxFig = 2;
const int sizeOfUniverse = 2500;
float pos[maxFig][3],inc[maxFig][3], movimento;
SistemaSolar s;


float dist_min = 2.2 * 149600000;
float dist_max = 3.2 * 149600000;

float tam_min = 0.2 * 12756;
float tam_max = 0.4 * 12756;

Asteroids a = Asteroids(dist_min, dist_max, tam_min, tam_max, 1000,.5);
double tempo, speed;
double ptempo = 0, pspeed = 0.001;
bool play, orbit;
GLuint background;
GLUquadric *bgQ;

GLfloat  luz[4], sourceLuz[4], luzPos[4];


GLfloat matSpecular[] = { .8, .8, .8, 1 };
GLfloat matAmbience[] = { 0.7, 0.7, 0.7, 1.0 };

GLfloat mat_diffuse[] = { 1.0f, 0.5f, 0.8f, 1.0f };
GLfloat matShininess[] = { 2 };

//dados retirados deste site http://astro.if.ufrgs.br/ssolar.htm
double dados[9][6] = {
	{ 0,1,25,695000,0,0 },//sol
	{ 57900000,87.9,58.6,4878,.1,7},//mercúrio
	{ 108200000,224.7,243,12100,117, 2.4},//venus
	{ 149600000, 365, 1, 12756,24,0 },//terra
	{ 227900000,686.98,1,6786,25,1.9 },//marte
	{ 778400000,11.86 * 365,9 / 24.,142984,3,1.3 },//jupiter
	{ 1423600000,29.46 * 365,10 / 24.,120536,27,2.5 },//saturno
	{ 2867000000,84.04 * 365,17 / 24.,51108,98,.8 },//urano
	{ 4488000000,164.8 * 365,19 / 24.,49538,30,1.8 }//netuno
};



void reshapeFunc(int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(70, (GLdouble)x / (GLdouble)y, 0.0005, sizeOfUniverse*10);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
}

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, luzPos);
	

	 
	glTranslatef(-pos[0][0], -pos[0][1], -pos[0][2]);

	glRotatef(pos[1][1], 1, 0, 0);
	glRotatef(pos[1][0], 0, 1, 0);
	glRotatef(pos[1][2], 0, 0, 1);
	

	glColor3f(1, 1, 1);

	desenhaFundo();
	s.desenha(tempo);
	a.desenha();

	glFlush();
	glutSwapBuffers();
}


void TecladoDown(unsigned char key, int x, int y)
{
	cout << key << endl;
	if (key == 27)
		exit(0);
	if (key == 'a') {
		fig++;
		fig %= maxFig;
		memset(inc, 0, sizeof(inc));
	}

	if (key == 'l' && inc[fig][0]==0)inc[fig][0] += movimento;
	if (key == 'j' && inc[fig][0] == 0)inc[fig][0] -= movimento;
	if (key == 'i' && inc[fig][1] == 0)inc[fig][1] += movimento;
	if (key == 'k' && inc[fig][1] == 0)inc[fig][1] -= movimento;
	if (key == 'u' && inc[fig][2] == 0)inc[fig][2] += movimento;
	if (key == 'o' && inc[fig][2] == 0)inc[fig][2] -= movimento;
	if (key == 'q') {
		play = false;
		tempo -= speed;
	}
	if (key == 'w') {
		play = true;
		if (speed > 0)speed = -pspeed;
		speed *= 10;
	}
	if (key == 'e') {
		play = !play;
		speed = pspeed;
	}
	if (key == 'r') {
		play = true;
		speed *= 10;
	}
	if (key == 't') {
		play = false;
		tempo += speed;
	}
	if (key == '1')orbit = !orbit;
	if (key == '\'')setPadrao();
	
	if (tempo >= DBL_MAX || tempo < 0) {
		tempo = 0;
		speed = pspeed;
	}
}

void TecladoUP(unsigned char key, int x, int y) {
	
	if (key == 'l' || key == 'j')inc[fig][0]=0;
	if (key == 'i'|| key == 'k')inc[fig][1]=0;
	if (key == 'u'|| key == 'o')inc[fig][2]=0;
}


void idleFunc(void) {
	if (tempo >= DBL_MAX || tempo < 0) {
		tempo = 0;
		speed = pspeed;
	}
	if (play) {
		
		tempo += speed;
	}
	for (int i = 0; i < maxFig; i++)for (int j = 0; j < 3; j++) {
		
		pos[i][j] += inc[i][j];
		
		if (i == 0)pos[i][j] = max(pos[i][j], -sizeOfUniverse / 10);
		if (i == 0)pos[i][j] = min(pos[i][j], sizeOfUniverse/10);
		
		inc[i][j] *= 1.02;
	}
	glutPostRedisplay();
}

void init() {
	setPadrao();
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLuz);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz);
	glLightfv(GL_LIGHT0, GL_POSITION, luzPos);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);


	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbience);


	background = loadTexture("texture/star2.bmp");
	bgQ = gluNewQuadric();

	Planeta *p;
	char texture[100];
	for (int i = 0; i < 9; i++) {
		sprintf(texture, "texture/%d.bmp", i);
		p = &Planeta(dados[i][0], dados[i][1], dados[i][2], dados[i][3],dados[i][4],dados[i][5],texture);
		
		if (i == 3) (*p).adicionaLua(Planeta(16440000, 27.3, 27.1, 1737,23.45,0,"texture/9.bmp"));
		
		if (i == 6)(*p).setAneis(Asteroids(125000000, 135000000, 100, 750, 200,0));
		s.adicionaPlaneta(*p);
	}

	
}

void setPadrao() {
	play = true;
	orbit = true;
	tempo = 0;
	speed = .001;
	fig = 0;
	memset(pos, 0, sizeof(pos));
	memset(inc, 0, sizeof(inc));
	pos[0][2] = 9;
	pos[1][1] = -60;
	movimento = .1;


	memset(luz, 0.3f, sizeof(luz));
	memset(sourceLuz, 1.0f, sizeof(sourceLuz));
	memset(luzPos, 0, sizeof(luzPos));

	luz[3] = 1.0f;
	sourceLuz[3] =1.0f;
	luzPos[3] = 1.0f;
}

bool showOrbit()
{
	return orbit;
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Trabalho Final Computação Gráfica  UERJ 2021-1");
	
	init();
	glutDisplayFunc(Desenha);
	glutReshapeFunc(reshapeFunc);
	glutIdleFunc(idleFunc);

	glutKeyboardFunc(TecladoDown);
	glutKeyboardUpFunc(TecladoUP);

	glutMainLoop();
}



GLuint loadTexture(char *filename) {
	cout << filename << endl;
	GLuint textureId;
	RgbImage theTexMap(filename); 
	glGenTextures(1, &textureId); 
	glBindTexture(GL_TEXTURE_2D, textureId); 
											
	glTexImage2D(GL_TEXTURE_2D, 
		0, 
		GL_RGB, 
		theTexMap.GetNumCols(), 
		theTexMap.GetNumRows(), 
		0, 
		GL_RGB, 
		GL_UNSIGNED_BYTE, 
		theTexMap.ImageData()); 
	cout << theTexMap.GetNumCols() << " " << textureId << endl;
	return textureId; 
}

void desenhaFundo() {
	GLUquadric* quad = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, background);

	gluQuadricOrientation(quad, GLU_INSIDE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	gluQuadricTexture(quad, 1);

	gluSphere(quad, sizeOfUniverse, 500, 500);
	
	
	gluQuadricOrientation(quad, GLU_OUTSIDE);
}