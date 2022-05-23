#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
static int shoulder = 0, elbow = 0,indicador=0, medio=0, polegar=0;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  /* origem posicionada no ombro */
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);

  /* origem posicionada no centro do braço */
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (1.0);
  glPopMatrix();

  /* origem posicionada no cotovelo */
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (1.0);
  glPopMatrix();
  //indicador
  glTranslatef (1.0, 0, 0);
  glRotatef ((GLfloat) indicador, 0.0, 0.0, 1.0);
  glTranslatef (0.25, 0, -0.5);
  glPushMatrix();
  glScalef (0.5, 0.1, 0.1);
  glutWireCube (1.0);
  glPopMatrix();
  /* origem volta para o sistema de coordenadas original */
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
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 'i':
    indicador = (indicador + 5) % 360;
    //printf("%i \n",indicador);
    if(indicador>90){
	indicador=90;
	}
    if(indicador<-90){
	indicador=-90;
	}
    glutPostRedisplay();
    break;
  case 'I':
    indicador = (indicador - 5) % 360;
    if(indicador>90){
	indicador=90;
	}
    if(indicador<-90){
	indicador=-90;
	}
    glutPostRedisplay();
  case 'm':
    medio = (medio + 5) % 360;
    if(medio>90){
	medio=90;
	}
    if(medio<-90){
	medio=-90;
	}
    glutPostRedisplay();
    break;
  case 'M':
    medio = (medio - 5) % 360;
	if(medio>90){
	medio=90;
	}
    if(medio<-90){
	medio=-90;
	}
    glutPostRedisplay();
    break;
  case 'p':
    polegar = (polegar + 5) % 360;
    if(polegar>90){
	polegar=90;
	}
    if(polegar<-90){
	polegar=-90;
	}
    glutPostRedisplay();
    break;
  case 'P':
    polegar = (polegar - 5) % 360;
	if(polegar>90){
	polegar=90;
	}
    if(polegar<-90){
	polegar=-90;
	}
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}