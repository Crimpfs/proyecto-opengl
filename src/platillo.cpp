#include "platillo.h"
#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265358979323846

float anguloRotacion = 0.5;
float theta = 0.0;
float radio = 0.0;
float altura = 0.0;

float posicionBaseX = 0.0f;
float posicionBaseY = 0.0f;
float posicionBaseZ = 0.0f;

float posicionTrayectoriaX = 0.0f;
float posicionTrayectoriaZ = 0.0f;

void rotarPlatillo(int valor) {
    anguloRotacion += 0.8;
    if (anguloRotacion >= 360.0) anguloRotacion -= 360.0;
    glutPostRedisplay();
    glutTimerFunc(16, rotarPlatillo, 0);
}

void platillo(){
    glPushMatrix();
        glColor3f(0.0, 0.6, 0.0); 
        glTranslatef(posicionBaseX, posicionBaseY, posicionBaseZ);
        glRotatef(theta, 0, 1, 0);
        glTranslatef(radio, altura, 0);
        glRotatef(anguloRotacion, 0.0, 1.0, 0.0);
        glPushMatrix();
            glScalef(1.0, 0.2, 1.0); 
            glutWireSphere(10.0, 50, 50);
        glPopMatrix();
    glPopMatrix();
}

void cabina(){
    glPushMatrix();
        posicionTrayectoriaX = posicionBaseX + radio * cos(theta * PI / 180.0f);
        posicionTrayectoriaZ = posicionBaseZ - radio * sin(theta * PI / 180.0f);
        glTranslatef(posicionTrayectoriaX, posicionBaseY + altura, posicionTrayectoriaZ);
        glPushMatrix();//cabina
            glColor3f(0.0, 0.6, 1.0); 
            glTranslatef(0.0, 1.5, 0.0);
            glutWireSphere(4.0, 40, 40);
        glPopMatrix();
        glPushMatrix(); //camara visual
            glColor3f(1.0, 0.0, 0.0);
            glTranslatef(0.0, 3.5, -3.5);
            glutSolidSphere(0.5, 20, 20); 
        glPopMatrix();
    glPopMatrix();
}

void graficarPlatillo(){
    platillo();
    cabina();    
}
