#include <GL/glut.h>

void init(void);
void display(void);

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glOrtho (-1, 1, -1, 1, -1, 1);
}

void keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case 32 :
		glClearColor(0.0, 0.0, 0.0, 1.0);
	break;
  default:
    glClearColor(1.0, 1.0, 1.0, 1.0);
  break;
	
	}
display();
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
      glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f( 0.0, 0.2);
        glVertex2f(-0.2,0.0);
        glVertex2f( 0.2,0.0);
      glEnd();
      
      glBegin(GL_POLYGON);
  	    glColor3f(0, 0, 1);
  	    glVertex2f(-0.2, -0.4);
  	    glVertex2f(0.2, -0.4);
  	    glVertex2f(0.2, 0.0);
  	    glVertex2f(-0.2, 0.0);
  	  glEnd();
      glBegin(GL_POLYGON);
  	    glColor3f(1, 1, 1);
  	    glVertex2f(-0.05, -0.39);
  	    glVertex2f(0.05, -0.39);
  	    glVertex2f(0.05, -0.19);
  	    glVertex2f(-0.05, -0.19);
  	  glEnd();

      glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glVertex2f (0.10,-0.26);
        glVertex2f (0.10, 0.0);
        glVertex2f (0.10, -0.26);
        glVertex2f (0.10, -0.2);
        glVertex2f (0.18, -0.2);
        glVertex2f (0.18, -0.26);
        glVertex2f (0.18, -0.2);
        glVertex2f (0.18, -0.2);
    glEnd();
      glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glVertex2f(0.10, -0.23);
        glVertex2f(0.18, -0.23);
      glEnd();
      glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glVertex2f(0.14, -0.26);
        glVertex2f(0.14, -0.20);
      glEnd();
  glFlush();
}

int main(int argc, char** argv)
{

  glutInit(&argc, argv);

  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize (800, 800);
  glutInitWindowPosition (200, 200);

  glutCreateWindow ("Exercicio 1");

  init();
  glutDisplayFunc(display);

  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return 0;

}
