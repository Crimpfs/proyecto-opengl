#include "camara.h"
#include <GL/glut.h>
#include "platillo.h"

int vistaActual = 1;

void aplicarCamara() {
  if (vistaActual == 1) {
   
    glRotatef(22.58, 1.0, 0.0, 0.0);   
    glRotatef(-33.69, 0.0, 1.0, 0.0);  
    glTranslatef(-20.0, -15.0, -30.0); 

  } else {
    if (vistaActual == 2) {
      
      glTranslatef(0.0, -1.75, 1.75); 
      glRotatef(miNave.getYaw(), 0.0, 1.0, 0.0);
      glTranslatef(-miNave.getX(), -miNave.getY(), -miNave.getZ());

    } else {
      if (vistaActual == 3) {
    
        glRotatef(90.0, 1.0, 0.0, 0.0);   
        glTranslatef(0.0, -50.0, 0.0);    
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
