#include <GL/glut.h>
float x,y;
bool check=false;

void mouse(int button, int state, int mousex, int mousey)
{
  if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
  {
   check=true;
   x = mousex;
   y = 480-mousey;
  }
            
  else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
  {
   glClearColor(1, 1, 1, 0); 
   glClear(GL_COLOR_BUFFER_BIT);
   check = false;        
  }
  glutPostRedisplay();
}
          
void display(void)
{  
  glColor3f(0,0,0); 
  glPointSize(50); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);

  if(check)  
  {      
   glBegin(GL_POINTS); 
     glVertex2i(x,y); 
   glEnd();
  }
  glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
  glutInitWindowSize(640,480); 
  glutInitWindowPosition(10,10); 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("Exercício 2");
        
  glClearColor(1, 1, 1, 0); 
  glClear(GL_COLOR_BUFFER_BIT);  
  
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMainLoop();
}

