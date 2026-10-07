#include "input.h"
#include "camara.h"
#include "platillo.h"
#include <GL/glut.h>
#include <math.h>
#include "platillo.h"

void teclasNormales(unsigned char key, int x, int y) {
  switch (key) {
  case '1': vistaActual = 1; break;
  case '2': vistaActual = 2; break;
  case '3': vistaActual = 3; break;

<<<<<<< HEAD
  // Usamos los métodos del objeto miNave
  case 'w': miNave.moverAdelante(1.0f); break;
  case 's': miNave.moverAtras(1.0f); break;
  case 'a': miNave.moverIzquierda(1.0f); break;
  case 'd': miNave.moverDerecha(1.0f); break;

  case 'q': miNave.rotar(-5.0f); break;
  case 'e': miNave.rotar(5.0f); break;

  case 'r': miNave.moverArriba(1.0f); break;
  case 'f': miNave.moverAbajo(1.0f); break;
=======
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

  case 't':  
    theta += 6.0f;
    radio += 0.05f;
    altura += 0.01f;      
    if(theta >= 360.0f) theta -= 360.0f;
    break; // Avanzar por la trayectoria
  case 'g':
    theta -= 6.0f;
    if(radio > 0.0f) radio -= 0.05f;
    if(altura > 0.0f) altura -= 0.01f;
    if(theta < 0.0f) theta += 360.0f;
    break; // Retroceder por la trayectoria
  case 'r':
    posicionBaseX = posicionTrayectoriaX;
    posicionBaseZ = posicionTrayectoriaZ;
    posicionBaseY += altura;
    theta = 0.0f;
    radio = 0.0f;
    altura = 0.0f;
    break; // Reiniciar trayectoria
>>>>>>> abcde66da20f22b84cb76318df36ac68cf896ce5
  }

  glutPostRedisplay();
}
