#include "input.h"
#include "camara.h"
#include <GL/glut.h>

void teclasNormales(unsigned char key, int x, int y) {
  switch (key) {
  case '1':
    vistaActual = 1;
    break; // Cámara 1
  case '2':
    vistaActual = 2;
    break; // Cámara 2
  case '3':
    vistaActual = 3;
    break; // Cámara 3

  case 'w':
    posZ -= 1.0;
    break; // Mover adelante (hacia el fondo)
  case 's':
    posZ += 1.0;
    break; // Mover atrás
  case 'a':
    posX -= 1.0;
    break; // Mover a la izquierda
  case 'd':
    posX += 1.0;
    break; // Mover a la derecha
  case 'q':
    posY += 1.0;
    break; // Mover arriba
  case 'e':
    posY -= 1.0;
    break; // Mover abajo
  }

  glutPostRedisplay();
}
