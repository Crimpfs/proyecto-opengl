#include "camara.h"
#include <GL/glut.h>
#include "platillo.h"


int vistaActual = 1;

class camara camara(20.0, 15.0, 30.0, 33.69, -22.58, 0.0);

void redimensionar(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, (float)w / (float)h, 1, 1000);
}
