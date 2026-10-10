#include "platillo.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;

Platillo miNave(0.0, 0.0, 0.0, 0.0, 0.0);
Platillo miPlato(0.0, 0.0, 0.0, 0.0, 0.0);

void animacionNave() {
  miNave.animar();
  miPlato.animar();
  glutPostRedisplay();
}
