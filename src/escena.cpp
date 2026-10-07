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

void graficarHUD() {
    if (vistaActual != 2) return; // Dibujar solo en la cámara 2

    // Cambiar a proyección ortográfica 2D
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0); // Lienzo 2D de 100x100
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Desactivar profundidad para dibujar por encima de todo
    glDisable(GL_DEPTH_TEST);

    // --- Dibujar el recuadro (Cabina de la nave) ---
    glColor3f(0.5, 0.5, 0.5); // Color gris metálico
    glLineWidth(10.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(5.0, 5.0);
        glVertex2f(95.0, 5.0);
        glVertex2f(95.0, 95.0);
        glVertex2f(5.0, 95.0);
    glEnd();

    // Líneas diagonales para dar efecto 3D a la ventana
    glLineWidth(4.0);
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0); glVertex2f(5.0, 5.0);
        glVertex2f(100.0, 0.0); glVertex2f(95.0, 5.0);
        glVertex2f(100.0, 100.0); glVertex2f(95.0, 95.0);
        glVertex2f(0.0, 100.0); glVertex2f(5.0, 95.0);
    glEnd();

    // --- Dibujar el puntero (mira) ---
    glColor3f(0.0, 1.0, 0.0); // Puntero verde
    glLineWidth(2.0);
    glBegin(GL_LINES);
        // Cruz horizontal
        glVertex2f(48.0, 50.0);
        glVertex2f(52.0, 50.0);
        // Cruz vertical
        glVertex2f(50.0, 48.0);
        glVertex2f(50.0, 52.0);
    glEnd();
    
    // Un puntito central para mayor precisión
    glPointSize(3.0);
    glBegin(GL_POINTS);
        glVertex2f(50.0, 50.0);
    glEnd();

    // Restaurar la configuración 3D normal
    glEnable(GL_DEPTH_TEST);
    glLineWidth(1.0);

    glPopMatrix(); 
    glMatrixMode(GL_PROJECTION);
    glPopMatrix(); 
    glMatrixMode(GL_MODELVIEW);
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
    
    graficarHUD(); 
    
    glutSwapBuffers();
}
