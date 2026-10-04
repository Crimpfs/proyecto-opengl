#include "escena.h"
#include "platillo.h"
#include "camara.h"
#include <GL/glut.h>

void inicializar(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 0.0); // Fondo negro como en tu imagen
}

void graficarEjes(){
    glDisable(GL_DEPTH_TEST); // Para que la cuadrícula no los tape
    glLineWidth(3.0f);        // Hacer las líneas más gruesas

    glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f); // X rojo
        glVertex3f(-40.0f, 0.0f, 0.0f);
        glVertex3f(40.0f, 0.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f); // Y verde
        glVertex3f(0.0f, -30.0f, 0.0f);
        glVertex3f(0.0f, 30.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f); // Z azul
        glVertex3f(0.0f, 0.0f, -30.0f);
        glVertex3f(0.0f, 0.0f, 30.0f);
    glEnd();

    glLineWidth(1.0f);       // Restaurar grosor normal
    glEnable(GL_DEPTH_TEST); // Volver a activar la profundidad
}

void graficarCuadricula() {
    glColor3f(0.3f, 0.3f, 0.3f); // Color gris oscuro para las líneas
    glBegin(GL_LINES);
    int limites = 40;
    int separacion = 2;
    for (int i = -limites; i <= limites; i += separacion) {
        // Lineas horizontales (paralelas al eje X)
        glVertex3f(-limites, 0, i);
        glVertex3f(limites, 0, i);
        
        // Lineas verticales (paralelas al eje Z)
        glVertex3f(i, 0, -limites);
        glVertex3f(i, 0, limites);
    }
    glEnd();
}

void graficarCajas() {
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); 
    glTranslatef(15.0f, 2.5f, 15.0f);
    glutSolidCube(5.0); 
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f); 
    glTranslatef(-15.0f, 2.5f, 15.0f);
    glutSolidCube(5.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(15.0f, 5.0f, -15.0f);
    glutSolidCube(10.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 1.0f); 
    glTranslatef(-15.0f, 2.5f, -15.0f);
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
    //glRotatef(45, 0.0f, 1.0f, 0.0f);
    glScalef(0.5f, 0.5f, 0.5f);
    graficarPlatillo(); 
    glPopMatrix();
    
    glutSwapBuffers();
}
