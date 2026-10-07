#include "escena.h"
#include "platillo.h"
#include "camara.h"
#include <GL/glut.h>

void inicializar(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void graficarEjes(){
    glDisable(GL_DEPTH_TEST);
    glLineWidth(3.0);        

    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0); 
        glVertex3f(-40.0, 0.0, 0.0);
        glVertex3f(40.0, 0.0, 0.0);

        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, -30.0, 0.0);
        glVertex3f(0.0, 30.0, 0.0);

        glColor3f(0.0, 0.0, 1.0); 
        glVertex3f(0.0, 0.0, -30.0);
        glVertex3f(0.0, 0.0, 30.0);
    glEnd();

    glLineWidth(1.0);       // Restaurar grosor normal
    glEnable(GL_DEPTH_TEST); // Volver a activar la profundidad
}

void graficarCuadricula() {
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_LINES);
    int limites = 40;
    int separacion = 2;
    for (int i = -limites; i <= limites; i += separacion) {
        
        glVertex3f(-limites, 0, i);
        glVertex3f(limites, 0, i);
        
        glVertex3f(i, 0, -limites);
        glVertex3f(i, 0, limites);
    }
    glEnd();
}

void graficarCajas() {
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0); 
    glTranslatef(15.0, 2.5, 15.0);
    glutSolidCube(5.0); 
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0); 
    glTranslatef(-15.0, 2.5, 15.0);
    glutSolidCube(5.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(15.0, 5.0, -15.0);
    glutSolidCube(10.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0); 
    glTranslatef(-15.0, 2.5, -15.0);
    glutSolidCube(5.0);
    glPopMatrix();
}

void graficar(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    aplicarCamara();
    
    graficarCuadricula();
    graficarEjes();
    graficarCajas();
    
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    //glRotatef(45, 0.0, 1.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    graficarPlatillo(); 
    glPopMatrix();
    
    glutSwapBuffers();
}
