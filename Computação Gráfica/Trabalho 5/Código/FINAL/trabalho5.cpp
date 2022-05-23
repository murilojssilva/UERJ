#include <stdlib.h>
#include <GL/glut.h>

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
// Variaveis que armazenam calculos feitos para movimentar os objetos:
GLfloat cicloLunarTransl = 15*velocidade;
GLfloat anoTerraTransl = ((365/360)*velocidade);
GLfloat anoRosaTransl = ((365/360)*5*velocidade);
GLfloat diaRosaRotac = 1*velocidade;
GLfloat diaTerraRotac = 10*velocidade;
// rotate_x armazena o valor do zoom atual
double rotate_x=0.5;
// O ponto de vista inicia como se estivesse vendo de cima:
char view = 't';  

void Desenha(void);
void AlteraTamanhoJanela(GLsizei larg, GLsizei alt);
void Inicializa (void);
void sistemaPlanetario(void);
void Movimenta(void);
void handleKeypress(unsigned char key, int x, int y);
void Rotaciona(int value);
void Zoom(int key, int x, int y);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("Sistema Planetário");
	Inicializa();
	glutSpecialFunc(Zoom);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutDisplayFunc(Desenha);
    glutKeyboardFunc(handleKeypress);
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
    glScalef( rotate_x,rotate_x,1.0f );		 
    switch (view) {
        case 't': // Vista de cima
           	gluLookAt(0.0,0.0,4.0, 0.0,0.0,3.0, 0.0,2.0,0.0);
            break;
        case 's': // Vista de lado
            gluLookAt(6.0,0.0,0.0, 0.0,0.0,0.0, 0.0,0.0,3.0);
            break;
        case 'b': // Vista de baixo
            gluLookAt(0.0,0.0,-10.0, 0.0,0.0,0.0, 0.0,1.0,0.0);
            break;
    }		   
	
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

// Funcao que incrementa os valores de rotacao e translacao dos objetos
void Movimenta(void)
{
	diaRosa += diaRosaRotac;
	diaTerra += diaTerraRotac;
	cicloLunar += cicloLunarTransl;
	anoTerra += anoTerraTransl;
	anoRosa += anoRosaTransl;
	Desenha();
}

void Zoom(int key, int x, int y) {
	// Ao pressionar a tecla 'Esc', o programa encerra
	if (key == 27) 
        exit(0);
	// Se aperta a tecla de seta para cima do teclado, o zoom aumenta
    if (key == GLUT_KEY_UP)
        rotate_x += .03;
	// Se aperta a tecla de seta para baixo do teclado, o zoom diminui
    if (key == GLUT_KEY_DOWN)
        rotate_x -= .03;
}   

// Funcao que age conforme acoes recebidas do teclado:
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: // Sai do programa
             exit(0); break;
        case 't': // Vista de cima
             view = key; glutPostRedisplay(); break;
        case 's': // Vista de lado
             view = key; glutPostRedisplay(); break;
        case 'b': // Vista de baixo
             view = key; glutPostRedisplay(); break;
    }
}

