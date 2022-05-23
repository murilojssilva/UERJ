#include <GL/glut.h>
#include <stdlib.h>

static int pae,pad,pbe,pbd,pce,pcd,pde,pdd=0 ;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  void glutSolidSphere(GLdouble radius,
                     GLint slices, GLint stacks);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key)
  {
    case 27:
        exit(0);
        break;
    default:
        break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (1200, 800);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
