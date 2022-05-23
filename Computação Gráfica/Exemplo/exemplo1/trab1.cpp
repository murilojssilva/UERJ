#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define PI 3.14159265358979323846

#define ORTHO_LEFT  -400.0
#define ORTHO_RIGHT  400.0
#define ORTHO_DOWN  -300.0
#define ORTHO_UP     300.0

const float ORTHO_WIDTH = ORTHO_RIGHT - ORTHO_LEFT;
const float ORTHO_HEIGHT = ORTHO_UP - ORTHO_DOWN;

#define FPS 30

const int FRAME_TIME_MS = 1000 / FPS;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;


float globalTimeSeconds = 0;
int globalFrameCounter = 0;
int globalMouseScreenX = 0;
int globalMouseScreenY = 0;
int globalTimerTriggered = 0;

#define ARROW_UNITS_PER_SEC 120.0
#define ARROW_THRESHOLD 5.0
float globalArrowX = 50;
float globalArrowY = 50;

//cefalotorax
GLfloat Xctx = 0;                        //posicao em X do centro da cabeça da aranha.
GLfloat Yctx = 0;                        //posicao em Y do centro do cabeça da aranha.
//abdomen
GLfloat Xabd = 0;                        //posicao em X do centro da bunda da aranha.
GLfloat Yabd = -70;                        //posicao em Y do centro da bunda da aranha.

GLfloat X11 = Xctx + -50;
GLfloat Y11 = Yctx + 50;
GLfloat X12 = Xctx + -75;
GLfloat Y12 = Yctx + 125;

GLfloat X21 = Xctx + -60;
GLfloat Y21 = Yctx + 23;
GLfloat X22 = Xctx + -119;
GLfloat Y22 = Yctx + 85;

GLfloat X31 = Xctx + -60;
GLfloat Y31 = Yctx + -18;
GLfloat X32 = Xctx + -129;
GLfloat Y32 = Yctx + -48;

GLfloat X41 = Xctx + -50;
GLfloat Y41 = Yctx + -40;
GLfloat X42 = Xctx + -95;
GLfloat Y42 = Yctx + -105;

GLfloat X11d = Xctx - -50;
GLfloat X12d = Xctx - -75;

GLfloat X21d = Xctx - -60;
GLfloat X22d = Xctx - -119;

GLfloat X31d = Xctx - -60;
GLfloat X32d = Xctx - -129;

GLfloat X41d = Xctx - -50;
GLfloat X42d = Xctx - -95;



void drawSpider() {
    glLineWidth(3.0f);
    
    //cefalotorax
    glBegin(GL_POLYGON);
    //Inicia o desenho de um poligono.
    glColor3f(0.02,0.02,0.02);                                            //Cor do poligono.
    for (float i = 0; i < 2*PI ; i+=0.1){                                //Rotaciona os pontos do poligono para formar um circulo.
        glVertex2f(30.0*(float)cos(i)+Xctx , 30.0*(float)sin(i)+Yctx);    //Coordenadas do circulo de raio 20 pixels.
    }
    glEnd();                                                            //Finaliza o circulo.
    
    //abdomen
    glBegin(GL_POLYGON);                                                //Inicia o desenho de um poligono.
    glColor3f(0.02,0.02,0.02);                                            //Cor do poligono.
    for (float i = 0; i < 2*PI ; i+=0.1){                                //Rotaciona os pontos do poligono para formar um circulo.
        glVertex2f(50.0*(float)cos(i)+Xabd , 50.0*(float)sin(i)+Yabd);    //Coordenadas do circulo de raio 20 pixels.
    }
    glEnd();
    
    //perna 1
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X11, Y11);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(X11, Y11);
    glVertex2f(X12, Y12);
    glEnd();
    
    //perna 2
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X21, Y21);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(X21, Y21);
    glVertex2f(X22, Y22);
    glEnd();
    
    //perna 3
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X31, Y31);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(X31, Y31);
    glVertex2f(X32, Y32);
    glEnd();
    
    //perna 4
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X41, Y41);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(X41, Y41);
    glVertex2f(X42, Y42);
    glEnd();
    
    //perna 1d
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X11d, Y11);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(X11d, Y11);
    glVertex2f(X12d, Y12);
    glEnd();
    
    //perna 2d
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X21d, Y21);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(X21d, Y21);
    glVertex2f(X22d, Y22);
    glEnd();
    
    //perna 3d
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X31d, Y31);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(X31d, Y31);
    glVertex2f(X32d, Y32);
    glEnd();
    
    //perna 4d
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(Xctx, Yctx);
    glVertex2f(X41d, Y41);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0,0,0.0);
    glVertex2f(X41d, Y41);
    glVertex2f(X42d, Y42);
    glEnd();
}


float hypotenuse(float a, float b) {
    return sqrtf(a * a + b * b);
}


void updateArrowPosition(float targetX, float targetY) {
    float directionX = targetX - globalArrowX;
    float directionY = targetY - globalArrowY;
    
    float distance = hypotenuse(directionX, directionY);
    
    if(distance <= ARROW_THRESHOLD) {
        return;
    }
    
    float speedX = (ARROW_UNITS_PER_SEC / FRAME_TIME_MS) * directionX / distance;
    float speedY = (ARROW_UNITS_PER_SEC / FRAME_TIME_MS) * directionY / distance;
    
    globalArrowX += speedX;
    globalArrowY += speedY;
}

// Rotaciona matriz para olhar na direção do cursor
void lookTowards(float fromX, float fromY, float toX, float toY) {
    GLfloat directionX = toX - fromX;
    GLfloat directionY = toY - fromY;
    
    GLfloat length = hypotenuse(directionX, directionY);
    
    GLfloat sinA = directionX / length;
    GLfloat cosA = directionY / length;
    
    GLfloat colMajorTransform[16] = {
        cosA, -sinA, 0, 0,
        sinA, cosA, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1,
    };
    
    glMultMatrixf(colMajorTransform);
}


void screenToWorldCoordinates(float screenX, float screenY, float *worldX, float *worldY) {
    *worldX = (screenX * ORTHO_WIDTH / WINDOW_WIDTH) + ORTHO_LEFT;
    // Window Y starts at top, but OpenGL Y starts at bottom
    *worldY =(ORTHO_UP - (screenY * ORTHO_HEIGHT / WINDOW_HEIGHT));
}


void onDisplay(void) {
    if(globalTimerTriggered != 1) {
        return;
    }
    
    globalTimerTriggered = 0;
    
    // fundo branco
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_DOWN, ORTHO_UP);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    float mouseX, mouseY;
    screenToWorldCoordinates(globalMouseScreenX, globalMouseScreenY, &mouseX, &mouseY);
    
    glPushMatrix();
    {
        glTranslatef(globalArrowX, globalArrowY, 0.0);
        lookTowards(globalArrowX, globalArrowY, mouseX, mouseY);
        drawSpider();
    }
    glPopMatrix();
    
    updateArrowPosition(mouseX, mouseY);
    
    glutSwapBuffers();
}


void onTimerTick(int frameCounter) {
    globalTimerTriggered = 1;
    globalFrameCounter = frameCounter;
    globalTimeSeconds = frameCounter * FRAME_TIME_MS / 1000.0f;
    
    glutTimerFunc(FRAME_TIME_MS, onTimerTick, frameCounter + 1);
    glutPostRedisplay();
}

void Mouse(GLint botao, GLint estado,  GLint x, GLint y) {
    //Verifica se houve click com o botao esquerdo do mouse.
    if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        
        globalMouseScreenX = x;
        globalMouseScreenY = y;
    }
}

void InputeOutput() {
    glutMouseFunc(Mouse);                        //Funcao responsavel pelos controles do mouse.
    glutDisplayFunc(onDisplay);                //Funcao responsavel por redesenhar a tela.
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(800, 600);
    glutCreateWindow("OpenGL");
    
    glutDisplayFunc(onDisplay);
    InputeOutput();
    glutIdleFunc(InputeOutput);
    glutTimerFunc(0, onTimerTick, 0);
    glutMainLoop();
    return 0;
}
