#include "platillo.h"
#include <GL/glut.h>

float anguloRotacion = 0.0;

void animacion() {
    anguloRotacion += 0.5;
    if (anguloRotacion >= 360.0) {
        anguloRotacion -= 360.0;
    }
    glutPostRedisplay();
}

void graficarPlatillo(){
    glPushMatrix();
    
    // Base del platillo 
    glColor3f(0.0, 0.6, 0.0); 
    glPushMatrix();
    glRotatef(anguloRotacion, 0.0, 1.0, 0.0);
    glScalef(1.0, 0.2, 1.0); // Aplanado en el eje Y
    glutWireSphere(10.0, 50, 50);
    glPopMatrix();

    // Cabina  
    glColor3f(0.0, 0.6, 1.0); 
    glPushMatrix();
    
    glTranslatef(0.0, 1.5, 0.0); // Subir la cabina en Y
    glutWireSphere(4.0, 40, 40);
    glPopMatrix();
    
    // camara visual
    glColor3f(1.0, 0.0, 0.0); 
    glPushMatrix();
    glTranslatef(0.0, 3.5, -3.5);
    glutSolidSphere(0.5, 20, 20); 
    glPopMatrix();

    glPopMatrix();
}
