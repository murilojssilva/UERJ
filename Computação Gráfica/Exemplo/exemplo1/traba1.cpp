#include <math.h>
#include <GL/glut.h>

typedef struct _Vector{ 
    double x,y,z; 
} Vector;

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
double radian, speed = 10, rot;

Vector pos, vel, dir, dis, mouseCoords; 

void display()
{ 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2, -100, 100);
    glColor3f(1,0,0);
    glTranslated(pos.x, pos.y, 0);
    glRotatef(rot*2, 0, 0, 1);
    glutSolidTeapot(10);
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
        rot = radian * 180 / 3.14;
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