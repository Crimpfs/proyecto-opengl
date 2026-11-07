#include "platillo.h"
#include <GL/glut.h>

Platillo miNave(0.0, 0.0, 0.0, 0.0, 0.0);

void animacionNave() {
    miNave.animar();
    glutPostRedisplay();
}
