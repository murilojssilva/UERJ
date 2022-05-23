#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdlib.h>
#include <math.h>

static int  base = 0, shoulder = 0;
double centerX = 0, centerY = 0, width = 512, height = 512;
GLint view_w, view_h;

#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;

void makeCheckImage(void)
{
   int i, j, c;
    
   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
         c = ((((i&0x8)==0)^((j&0x8))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) c;
         checkImage[i][j][2] = (GLubyte) c;
         checkImage[i][j][3] = (GLubyte) 255;
      }
   }
}

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);

   makeCheckImage();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   glGenTextures(1, &texName);
   glBindTexture(GL_TEXTURE_2D, texName);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                checkImage);
}


void mouse( int button, int state, int mx, int my )
{
    my = glutGet( GLUT_WINDOW_HEIGHT ) - my;

    double x = ( mx / (double)glutGet( GLUT_WINDOW_WIDTH ) ) - 0.5;
    double y = ( my / (double)glutGet( GLUT_WINDOW_HEIGHT ) ) - 0.5;

    if( GLUT_UP == state )
    {
        double preX = ( x * width );
        double preY = ( y * height );

        double zoomFactor = 1.5;
        if( button == GLUT_LEFT_BUTTON )
        {
            width /= zoomFactor;
            height /= zoomFactor;
        }
        if( button == GLUT_RIGHT_BUTTON )
        {
            width *= zoomFactor;
            height *= zoomFactor;
        }

        double postX = ( x * width );
        double postY = ( y * height );

        centerX += ( preX - postX );
        centerY += ( preY - postY );
    }

    glutPostRedisplay();
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    glOrtho( -width, width, -height, height, -1, 1 );

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    
    glRotatef ((GLfloat) base, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);

    //cabeça
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-10, 210);
    glVertex2f( 10, 210);
    glVertex2f( 10, 180);
    glVertex2f(-10, 180);
    glEnd();
    
    //tronco
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(50, 180);
    glVertex2f(-50, 180);
    glVertex2f(-50, 0);
    glVertex2f(50, 0);
    glEnd();
    
    //pernas
    //perna esquerda
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-20, 0);
    glVertex2f(-40, 0);
    glVertex2f(-40, -210);
    glVertex2f(-20, -210);
    glEnd();
    
    //perna direita
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(40, 0);
    glVertex2f(20, 0);
    glVertex2f(20, -210);
    glVertex2f(40, -210);
    glEnd();
    
    //braços
    //braço direito
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(150, 160);
    glVertex2f(40, 160);
    glVertex2f(40, 140);
    glVertex2f(150, 140);
    glEnd();
    
    //braço esquerdo
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-150, 160);
    glVertex2f(-40, 160);
    glVertex2f(-40, 140);
    glVertex2f(-150, 140);
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texName);
    
    //garra direita
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(160, 170);
    glTexCoord2f(0.0, 1.0); glVertex2f(150, 170);
    glTexCoord2f(1.0, 1.0); glVertex2f(150, 130);
    glTexCoord2f(1.0, 0.0); glVertex2f(160, 130);
    glEnd();
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(150, 130);
    glTexCoord2f(0.0, 1.0); glVertex2f(190, 130);
    glTexCoord2f(1.0, 1.0); glVertex2f(190, 120);
    glTexCoord2f(1.0, 0.0); glVertex2f(150, 120);
    glEnd();
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(150, 170);
    glTexCoord2f(0.0, 1.0); glVertex2f(190, 170);
    glTexCoord2f(1.0, 1.0); glVertex2f(190, 180);
    glTexCoord2f(0.0, 0.0); glVertex2f(150, 180);
    glEnd();
    
    //garra esquerda
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0, 0.0); glVertex2f(-160, 170);
    glTexCoord2f(0.0, 1.0); glVertex2f(-150, 170);
    glTexCoord2f(1.0, 1.0); glVertex2f(-150, 130);
    glTexCoord2f(1.0, 0.0); glVertex2f(-160, 130);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0, 0.0); glVertex2f(-150, 130);
    glTexCoord2f(0.0, 1.0); glVertex2f(-190, 130);
    glTexCoord2f(1.0, 1.0); glVertex2f(-190, 120);
    glTexCoord2f(1.0, 0.0); glVertex2f(-150, 120);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0, 0.0); glVertex2f(-150, 170);
    glTexCoord2f(0.0, 1.0); glVertex2f(-190, 170);
    glTexCoord2f(1.0, 1.0); glVertex2f(-190, 180);
    glTexCoord2f(1.0, 0.0); glVertex2f(-150, 180);
    glEnd();
    
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void reshape (int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   
    view_w = w;
    view_h = h;
   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 'b':
    base = (base + 5) % 360;
    glutPostRedisplay();
    break;
  case 'B':
    base = (base - 5) % 360;
    glutPostRedisplay();
    break;
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}



int main( int argc, char **argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH |GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Trabalho Final");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    width = glutGet( GLUT_WINDOW_WIDTH );
    height = glutGet( GLUT_WINDOW_HEIGHT );

    glutMainLoop();
}
