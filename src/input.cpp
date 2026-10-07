#include "input.h"
#include "camara.h"
#include "platillo.h"
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
  }

  glutPostRedisplay();
}
