#include "camara.h"
#include <GL/glut.h>

int vistaActual = 1;
float posX = 5.0, posY = 5.0, posZ = 5.0; 

void aplicarCamara() {
    if (vistaActual == 1) {
        gluLookAt(20, 15, 30, 0,0,0, 0,1,0);
        
    } else {
    if (vistaActual == 2) {
        glTranslatef(0.0, -1.75, 1.75);
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        glTranslatef(-posX, -posY, -posZ); 
        
    } 
    else {
        if (vistaActual == 3) {
            gluLookAt(0, 50, 0, 0,0,0, 0,0,-1);

             }
        }
    }
}


void redimensionar(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(float)w/(float)h,1,1000);
}
