#include "camara.h"
#include "escena.h"
#include "input.h"
#include "platillo.h"
#include <GL/freeglut.h>

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 400);
  glutInitWindowPosition(100, 200);
  glutCreateWindow("Hola Mundo");

  inicializar();

  glutDisplayFunc(graficar);
  glutReshapeFunc(redimensionar);
  glutKeyboardFunc(teclasNormales);
  glutIdleFunc(animacionNave);
  glutMainLoop();

  return 0;
}
