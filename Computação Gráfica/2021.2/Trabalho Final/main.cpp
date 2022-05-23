/*
 Murilo de Jesus
 201220605411
 Trabalho Final - Computação Gráfica
*/

#if defined(__APPLE__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "RgbImage.h"

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592654

using namespace std;

void drawLegs();
void drawBody();
void drawHead(void);
void drawHand(int, int);
void drawArms(int, int);

char* filenameTexMetal1 = (char*) "./metalTexture1.bmp";
char* filenameEye = (char*) "./textureEye.bmp";

GLuint _textureIdMetal1;
GLuint _textureIdSphere;
GLuint _textureIdCylinder;
GLuint _textureIdCone;
GLuint _textureIdEye;
GLUquadric* quadSphere;
GLUquadric* quadCylinder;

bool textureOn = true;

float diameterCylinder = 0.3;
float diameterSphere = 0.4;
float sizeArm = 4.5;
float sizeForearm = 3.0;
float sizeLeg = 6.0;
float sizeHand = 2.0;
float sizeClampPart = 1.0;
float diameterBase = 2.0;
float heightBase = 0.5;

float eyeDistance = 30.0;
float eyeX;
float eyeY;
float eyeZ;
float viewAngleX = 90.0;
float viewAngleZ = 15.0;

float angleRobot = 0.0;
float angleForearm = 0.0;
float angleHand = 0.0;
float angleClampZ = 0.0;
float angleClampYLeft = 0.0;
float angleClampYRight = 0.0;

float angleLeftHandY = 0.0;
float angleLeftArmY = 180.0;
float angleLeftForearmY = 0.0;

float angleRightHandY = 0.0;
float angleRightArmY = 180.0;
float angleRightForearmY = 0.0;

GLfloat luzAmbiente[4] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat luzDifusa[4] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat posicaoLuz[4] = { 0.0, 50.0, 50.0, 1.0 };

void initLighting(void)
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glShadeModel(GL_SMOOTH);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    glEnable(GL_COLOR_MATERIAL);
}

GLuint loadTexture(char* filename) {
    GLuint textureId;
    RgbImage theTexMap(filename);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGB,
        theTexMap.GetNumCols(),
        theTexMap.GetNumRows(),
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        theTexMap.ImageData());
    return textureId;
}

void initRendering(void) {
    quadSphere = gluNewQuadric();
    quadCylinder = gluNewQuadric();
    _textureIdMetal1 = loadTexture(filenameTexMetal1);
    _textureIdEye = loadTexture(filenameEye);
    _textureIdCone =_textureIdMetal1;
    _textureIdCylinder = _textureIdMetal1;
    _textureIdSphere = _textureIdMetal1;
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        case 'q':
            if(angleLeftArmY < 180) angleLeftArmY -= 3;
            glutPostRedisplay();
            break;
        case 'Q':
            if(angleLeftArmY > 0) angleLeftArmY += 3;
            glutPostRedisplay();
            break;
        case 'w':
            if (angleLeftForearmY < 150) angleLeftForearmY += 3;
                glutPostRedisplay();
                break;
        case 'W':
            if (angleLeftForearmY > 0) angleLeftForearmY -= 3;
                glutPostRedisplay();
                break;
        case 'e':
            if (angleLeftHandY < 30) angleLeftHandY += 3;
                glutPostRedisplay();
                break;
        case 'E':
            if (angleLeftHandY > 0) angleLeftHandY -= 3;
                glutPostRedisplay();
                break;
        case 'a':
            if (angleClampYLeft < 90) angleClampYLeft += 3;
            glutPostRedisplay();
            break;
        case 'A':
            if (angleClampYLeft > 0) angleClampYLeft -= 3;
            glutPostRedisplay();
            break;
                
        case 'u':
            if(angleRightArmY < 180) angleRightArmY -= 3;
            glutPostRedisplay();
            break;
        case 'U':
            if(angleRightArmY > 0) angleRightArmY += 3;
            glutPostRedisplay();
            break;
            
      
        case 'i':
            if (angleRightForearmY < 150) angleRightForearmY += 3;
                glutPostRedisplay();
                break;
        case 'I':
            if (angleRightForearmY > 0) angleRightForearmY -= 3;
                glutPostRedisplay();
                break;
        case 'o':
            if (angleRightHandY < 30) angleRightHandY += 3;
                glutPostRedisplay();
                break;
        case 'O':
            if (angleRightHandY > 0) angleRightHandY -= 3;
                glutPostRedisplay();
                break;
        case 'h':
            if (angleClampYRight < 90) angleClampYRight += 3;
            glutPostRedisplay();
            break;
        case 'H':
            if (angleClampYRight > 0) angleClampYRight -= 3;
            glutPostRedisplay();
            break;
            
        case '1':
            angleRobot += 3;
            if (angleRobot >= 360) angleRobot = 0;
                glutPostRedisplay();
                break;
        case '2':
            angleRobot -= 3;
            if (angleRobot <= 0) angleRobot = 360;
                glutPostRedisplay();
                break;
        case '3':
            angleForearm += 3;
                glutPostRedisplay();
                break;
        case '4':
            angleForearm -= 3;
                glutPostRedisplay();
                break;
        case '5':
            if (angleClampZ < 90) angleClampZ += 3;
            glutPostRedisplay();
            break;
        case '6':
            if (angleClampZ > 0) angleClampZ -= 3;
            glutPostRedisplay();
            break;
    }
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_DOWN:
            if (viewAngleZ < 360) viewAngleZ -= 3;
            else viewAngleZ = 0;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            if (viewAngleZ < 360) viewAngleZ += 3;
            else viewAngleZ = 0;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            if (viewAngleX > 0) viewAngleX -= 3;
            else viewAngleX = 360;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            if (viewAngleX < 360) viewAngleX += 3;
            else viewAngleX = 0;
            glutPostRedisplay();
            break;
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) {
            if (eyeDistance > 20) eyeDistance -= 1;
        }
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN) {
            if (eyeDistance < 40) eyeDistance += 1;
        }
    glutPostRedisplay();
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
}

void drawCylinder(float diameter, float lenght) {
    if (textureOn) {
        glBindTexture(GL_TEXTURE_2D, _textureIdCylinder);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        gluQuadricTexture(quadCylinder, 1);
    }
    else
        gluQuadricTexture(quadCylinder, 0);
    gluCylinder(quadCylinder, diameter, diameter, lenght, 40.0, lenght * 30.0);
}

void drawCone(float diameter, float lenght) {
    if (textureOn) {
        glBindTexture(GL_TEXTURE_2D, _textureIdCone);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        gluQuadricTexture(quadCylinder, 1);
    }
    else
        gluQuadricTexture(quadCylinder, 0);
    gluCylinder(quadCylinder, diameter, 0, lenght, 40.0, lenght * 30.0);
}

void drawDisk(float diameterInner, float diameterOuter) {
    if (textureOn) {
        glBindTexture(GL_TEXTURE_2D, _textureIdCylinder);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        gluQuadricTexture(quadCylinder, 1);
    }
    else {
        gluQuadricTexture(quadCylinder, 0);
    }
    gluDisk(quadCylinder, diameterInner, diameterOuter, 40.0, 30.0);
}

void drawSphere(float diameter) {
    if (textureOn) {
        glBindTexture(GL_TEXTURE_2D, _textureIdSphere);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        gluQuadricTexture(quadSphere, 1);
    }
    else
        gluQuadricTexture(quadSphere, 0);
    gluSphere(quadSphere, diameter, 40.0, 40.0);
}

void drawScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    eyeX = eyeDistance * cos(viewAngleZ*PI / 180) * cos(viewAngleX*PI / 180);
    eyeY = eyeDistance * cos(viewAngleZ*PI / 180) * sin(viewAngleX*PI / 180);
    eyeZ = eyeDistance * sin(viewAngleZ*PI / 180);
    if (viewAngleZ<90)
        gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    else
        gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    
    glRotatef(angleRobot, 0.0f, 0.0f, 1.0f);
    
    glTranslatef(0.0f, 0.0f, sizeArm + diameterSphere / 5);
    glRotatef(angleForearm, 0.0f, 1.0f, 0.0f);
    
    drawLegs();
    drawBody();
    drawArms(angleLeftArmY, angleRightArmY);
    drawHead();

    glutSwapBuffers();
}

void drawHead(void) {
    glTranslatef(0.0f, 0.0f, heightBase - 0.5);
    glPushMatrix();
    
    drawCylinder(diameterCylinder * 1.5, sizeArm / 5);
    glTranslatef(0.0f, 0.0f, heightBase + 2);
    drawSphere(diameterSphere*4);
    
    glBindTexture(GL_TEXTURE_2D, _textureIdEye);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluQuadricTexture(quadCylinder, 1);
    glPushMatrix();
    glTranslatef(heightBase + 0.1, heightBase + 1, heightBase + 0.3);
    glRotatef(angleForearm, 1.0f, 0.0f, 0.0f);
    drawCylinder(diameterCylinder, sizeArm / 10);
    drawDisk(0, diameterCylinder);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, _textureIdEye);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluQuadricTexture(quadCylinder, 1);
    glPushMatrix();
    glTranslatef(-(heightBase + 0.1), heightBase + 1, heightBase + 0.3);
    glRotatef(angleForearm, 1.0f, 0.0f, 0.0f);
    drawCylinder(diameterCylinder, sizeArm / 10);
    drawDisk(0, diameterCylinder);
    glPopMatrix();
    glPopMatrix();
}

void drawBody() {
    glPushMatrix();
    drawDisk(0,diameterCylinder * 11);
    glTranslatef(0, 0, -9);
    drawCylinder(diameterCylinder * 11, sizeLeg * 1.5);
    drawDisk(0, diameterCylinder * 11);
    glPopMatrix();
}

void drawHand(int pIntAngleHand, int pIntForearm) {
    drawSphere(diameterSphere);
    glTranslatef(0.0f, 0.0f, diameterSphere / 20);
    drawCylinder(diameterCylinder, sizeHand);
    glTranslatef(0.0f, 0.0f, sizeHand + diameterSphere / 5);
    glRotatef(angleClampZ, 0.0f, 0.0f, 1.0f);
    drawSphere(diameterSphere);
    glTranslatef(0.0f, 0.0f, diameterSphere / 2);
    
    glPushMatrix();
    glRotatef(pIntAngleHand + 60, 0.0f, 1.0f, 0.0f);
    drawCylinder(diameterCylinder / 3, sizeClampPart);
    glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
    drawSphere(diameterSphere / 3);
    glTranslatef(0.0f, 0.0f, diameterSphere / 15);
    glRotatef(-60, 0.0f, 1.0f, 0.0f);
    drawCylinder(diameterCylinder / 3, sizeClampPart);
    glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
    drawSphere(diameterSphere / 3);
    glTranslatef(0.0f, 0.0f, diameterSphere / 15);
    glRotatef(-60, 0.0f, 1.0f, 0.0f);
    drawCone(diameterCylinder / 3, sizeClampPart);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-pIntAngleHand - 60, 0.0f, 1.0f, 0.0f);
    drawCylinder(diameterCylinder / 3, sizeClampPart);
    glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
    drawSphere(diameterSphere / 3);
    glTranslatef(0.0f, 0.0f, diameterSphere / 15);
    glRotatef(60, 0.0f, 1.0f, 0.0f);
    drawCylinder(diameterCylinder / 3, sizeClampPart);
    glTranslatef(0.0f, 0.0f, sizeClampPart + diameterSphere / 15);
    drawSphere(diameterSphere / 3);
    glTranslatef(0.0f, 0.0f, diameterSphere / 15);
    glRotatef(60, 0.0f, 1.0f, 0.0f);
    drawCone(diameterCylinder / 3, sizeClampPart);
    glPopMatrix();
}

void drawArms(int pIntAngleLeftArmY, int pIntAngleRightArmY) {
    glBindTexture(GL_TEXTURE_2D, _textureIdMetal1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPushMatrix();
    glTranslatef(3.6f, 0.0f, heightBase - 1.5);
    glRotatef((-angleClampYRight), 0.0f, 1.0f, 0.0f);
    drawSphere(diameterSphere + 0.2);
    glTranslatef(0.0f, 0.0f, (diameterSphere / 5));
    glRotatef(pIntAngleRightArmY , 1.0f, 0.0f, 0.0f);
    drawCylinder(diameterCylinder, sizeForearm);
    glTranslatef(0.0f, 0.0f, sizeForearm + diameterSphere);
    glRotatef(angleRightForearmY, 1.0f, 0.0f, 0.0f);
    drawSphere(diameterSphere);
    drawHand(angleRightHandY, angleRightForearmY);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, _textureIdMetal1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPushMatrix();
    glTranslatef(-3.6f, 0.0f, heightBase - 1.5);
    glRotatef(angleClampYLeft, 0.0f, 1.0f, 0.0f);
    drawSphere(diameterSphere + 0.2);
    glTranslatef(0.0f, 0.0f, (diameterSphere / 5));
    glRotatef(pIntAngleLeftArmY, 0.0f, 0.0f, 0.0f);
    drawCylinder(diameterCylinder, sizeForearm);
    glTranslatef(0.0f, 0.0f, sizeForearm + diameterSphere);
    glRotatef(angleLeftForearmY, 1.0f, 0.0f, 0.0f);
    drawSphere(diameterSphere);
    drawHand(angleLeftHandY, angleLeftForearmY);
    glPopMatrix();
}


void drawLegs() {
    glPushMatrix();
    glTranslatef(2, 0, heightBase * (-20));
    drawCylinder(diameterCylinder, sizeLeg / 5);
    drawSphere(diameterSphere);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2, 0, heightBase* (-25.0));
    drawCylinder(diameterCylinder, sizeLeg);
    drawCylinder(diameterBase, heightBase);
    glTranslatef(0.0f, 0.0f, heightBase);
    drawDisk(diameterCylinder, diameterBase);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2, 0, heightBase * (-20));
    drawCylinder(diameterCylinder, sizeLeg / 5);
    drawSphere(diameterSphere);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2, 0, heightBase* (-25.0));
    drawCylinder(diameterCylinder, sizeLeg);
    drawCylinder(diameterBase, heightBase);
    glTranslatef(0.0f, 0.0f, heightBase);
    drawDisk(diameterCylinder, diameterBase);
    glPopMatrix();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Trabalho Final");

    initLighting();
    initRendering();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutReshapeFunc(handleResize);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
