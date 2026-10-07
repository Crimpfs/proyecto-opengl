#include "camara.h"
#include <GL/glut.h>

int vistaActual = 1;
float posX = 5.0, posY = 5.0, posZ = 5.0;
     

void aplicarCamara() {
  if (vistaActual == 1) {
    // Equivalente a gluLookAt usando funciones matriciales nativas de OpenGL (glRotatef y glTranslatef)
    glRotatef(22.58, 1.0, 0.0, 0.0);   // Inclinación (Pitch)
    glRotatef(-33.69, 0.0, 1.0, 0.0);  // Giro (Yaw)
    glTranslatef(-20.0, -15.0, -30.0); // Mover el mundo hacia atrás

  } else {
    if (vistaActual == 2) {
      glTranslatef(0.0, -1.75, 1.75);
      glRotatef(-2.0, 0.0, 1.0, 0.0);
      glTranslatef(-posX, -posY, -posZ);

    } else {
      if (vistaActual == 3) {
        // Equivalente a gluLookAt usando transformaciones nativas de OpenGL
        glRotatef(90.0, 1.0, 0.0, 0.0);    // Rotar 90 grados para mirar hacia abajo (-Y)
        glTranslatef(0.0, -50.0, 0.0);     // Elevar la cámara a 50 unidades de altura
      }
    }
  }
}

void redimensionar(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, (float)w / (float)h, 1, 1000);
}
