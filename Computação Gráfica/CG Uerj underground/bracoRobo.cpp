#include <GL/glut.h>
#define BASE_HEIGHT 2.0
#define BASE_RADIUS 0.9

static int shoulderAngle = 0, elbowAngle = 0,centerAngle =0;
GLUquadricObj*  p = gluNewQuadric();

void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: (elbowAngle += 5) %= 360; break;
    case GLUT_KEY_RIGHT: (elbowAngle -= 5) %= 360; break;
    case GLUT_KEY_UP: (shoulderAngle += 5) %= 360; break;
    case GLUT_KEY_DOWN: (shoulderAngle -= 5) %= 360; break;
    case 'r': (centerAngle += 5) %= 360; break;
    case 'l': (centerAngle -= 5) %= 360; break;
    default: return;
  }
  glutPostRedisplay();
}

void mykey(GLubyte key, GLint x, GLint y)
{
    switch (key) {
    
    case 'r': (centerAngle += 5) %= 360; break;
    case 'l': (centerAngle -= 5) %= 360; break;
    default: return;
  }
  glutPostRedisplay();
}

void wireBox(GLdouble width, GLdouble height, GLdouble depth) {
  glPushMatrix();
  glScalef(width, height, depth);
  glutSolidCube(1.0);
  glPopMatrix();
}

void base()
{
   glPushMatrix();

   glRotatef(-90.0, 1.0, 0.0, 0.0);
   
   gluQuadricDrawStyle(p,  GLU_FILL);
   gluCylinder(p, BASE_RADIUS, BASE_RADIUS, BASE_HEIGHT, 5, 5);


   glPopMatrix();
}


void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glRotatef((GLfloat)centerAngle, 0.0, 1.0, 0.0);
  base();
 
  glRotatef((GLfloat)shoulderAngle, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 1.0, 0.0);
  wireBox(3.0,0.4, 0.5);

 
  glTranslatef(1.0, 0.0, 0.0);
  glRotatef((GLfloat)elbowAngle, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 0.0, 0.0);
  wireBox(2.0, 0.4, 0.5);

  glPopMatrix();
  glFlush();
}


void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, GLfloat(w)/GLfloat(h), 1.0, 20.0);
}

void init() {
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glClearColor (1.0, 1.0, 1.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_LEFT, GL_SPECULAR, mat_specular);

   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);


  glShadeModel(GL_FLAT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(1,2,8, 0,0,0, 0,1,0);
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Diego Robot Arm");
  glutDisplayFunc(display);
  glutKeyboardFunc(mykey);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  init();
  glutMainLoop();
}

