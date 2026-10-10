#include "input.h"
#include "camara.h"
#include <GL/glut.h>
#include "platillo.h"

void teclasNormales(unsigned char key, int x, int y) {
  switch (key) {
  case '1': vistaActual = 1; break;
  case '2': vistaActual = 2; break;
  case '3': vistaActual = 3; break;


  case 'w': miNave.moverAdelante(1.0); break;
  case 's': miNave.moverAtras(1.0); break;
  case 'a': miNave.moverIzquierda(1.0); break;
  case 'd': miNave.moverDerecha(1.0); break;

  case 'q': miNave.rotar(-5.0); break;
  case 'e': miNave.rotar(5.0); break;

  case 'r': miNave.moverArriba(1.0); break;
  case 'f': miNave.moverAbajo(1.0); break;

  }

  glutPostRedisplay();
}
