#include "camara.h"
#include "platillo.h"
#include <GL/glut.h>
#include <math.h>

int vistaActual = 1;
float posX = 5.0f, posY = 5.0f, posZ = 5.0f; 

void aplicarCamara() {
    if (vistaActual == 1) {
        gluLookAt(20, 15, 30, 0,0,0, 0,1,0);

    } else if (vistaActual == 2) {

        glTranslatef(0.0f, -1.75f, 1.75f);
        glRotatef(-anguloRotacion, 0.0f, 1.0f, 0.0f);
        glTranslatef(-posX, -posY, -posZ);
        
    } else if (vistaActual == 3) {
        gluLookAt(0, 50, 0, 0,0,0, 0,0,-1);
    }
}

void redimensionar(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(float)w/(float)h,1,1000);
}
