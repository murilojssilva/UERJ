#include <math.h>
#include <GL/glut.h>

typedef struct _Vector{ 
    double x,y,z; 
} Vector;


static int pae,pad,pbe,pbd,pce,pcd,pde,pdd=0;
const int SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 800;
double radian, speed = 10, rot;

Vector pos, vel, dir, dis, mouseCoords; 

void display()
{ 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   //glOrtho(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2, -100, 100);
    
    glTranslated(pos.x, pos.y, 0);
    glRotatef(rot, 0, 0, 1);
    //glutSolidTeapot(10);
    glPushMatrix();

    //Abd�men
	glColor3f(0, 0, 1);
	glutSolidSphere(0.4, 50, 50);

    //Cefalot�rax
	glTranslatef(0, 0.7, 0.0);
	glColor3f(0, 0, 1);
	glutSolidSphere(0.3, 50, 50);

	    //olhos
	glTranslatef(-0.05, 0.17, 0.3);
	glColor3f(1, 0, -1);
	glutSolidSphere(0.05, 50, 50);
	glTranslatef(0.1, 0, 0);
	glutSolidSphere(0.05, 50, 50);

	glTranslatef(-0.05, -0.17, -0.3);
    //a esquerda
    glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pae-0.2), (pae+0.2));
        glVertex2f((pae-0.4), (pae+0.5));
        //2
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pae-0.4), (pae+0.5));
        glVertex2f((pae-0.8), (pae+0.75));
    glEnd();
    //a direita
    glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pad+0.2), (pad+0.2));
        glVertex2f((pad+0.4), (pad+0.5));
        //2
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pad+0.4), (pad+0.5));
        glVertex2f((pad+0.8), (pad+0.75));
    glEnd();

    //b esquerda
    glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pbe-0.23), (pbe+0.1));
        glVertex2f((pbe-0.45), (pbe+0.15));
        //2
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pbe-0.45), (pbe+0.15));
        glVertex2f((pbe-0.65), (pbe+0));
    glEnd();

    //b direita
    glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pbd+0.23), (pbd+0.1));
        glVertex2f((pbd+0.45), (pbd+0.15));
        //2
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pbd+0.45), (pbd+0.15));
        glVertex2f((pbd+0.65), (pbd+0));
    glEnd();
    //c esquerda
    glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pce-0.23), (pce-0.05));
        glVertex2f((pce-0.45), (pce-0.1));
        //2
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pce-0.45), (pce-0.1));
        glVertex2f((pce-0.65), (pce-0.3));
    glEnd();
    //c direita
    glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pcd+0.23), (pcd-0.05));
        glVertex2f((pcd+0.45), (pcd-0.1));
        //2
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pcd+0.45), (pcd-0.1));
        glVertex2f((pcd+0.65), (pcd-0.3));
    glEnd();

    //d esquerda
        glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pde-0.2), (pde-0.2));
        glVertex2f((pde-0.5), (pde-0.5));
        //2
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pde-0.5), (pde-0.5));
        glVertex2f((pde-0.75), (pde-0.9));
    glEnd();
    //d direita
        glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pdd+0.2), (pdd-0.2));
        glVertex2f((pdd+0.5), (pdd-0.5));
        //2
        glTranslatef (1.0, 0.0, 0.0);
        glVertex2f((pdd+0.5), (pdd-0.5));
        glVertex2f((pdd+0.75), (pdd-0.9));
    glEnd();

  glPopMatrix();
  glutSwapBuffers();
    glFlush();
    glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{
    mouseCoords.x = x - SCREEN_WIDTH/2;
    mouseCoords.y = -y + SCREEN_HEIGHT/2;
}

void move()
{
    dis.x = mouseCoords.x - pos.x;
    dis.y = mouseCoords.y - pos.y;
    if(sqrt(dis.y*dis.y + dis.x*dis.x) < speed)
    {
        pos.x = mouseCoords.x;
        pos.y = mouseCoords.y;
    }
    else
    {
        radian = atan2(dis.y, dis.x);
        pos.x += cos(radian) * speed;
        pos.y += sin(radian) * speed;
        rot = radian * 100 / 3.14;
    }
}

void update(int value)
{
    move();
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void init()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Teste");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutTimerFunc(25, update, 0);
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutMainLoop();
    return 0;
}