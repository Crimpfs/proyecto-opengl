#include "camara.h"
#include "escena.h"
#include "input.h"
#include "platillo.h"
#include <GL/glut.h>

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(ancho, alto);
    glutCreateWindow("Hola Mundo");

    inicializar();

    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);
    glutKeyboardFunc(teclasNormales);
    glutSpecialFunc(flechas);
    glutMouseFunc(clicMouse);
    glutMotionFunc(moverMouse);
    glutIdleFunc(animacionescena);

    glutMainLoop();
    return 0;
}
