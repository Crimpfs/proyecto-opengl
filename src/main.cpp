#include <GL/glut.h>
#include "escena.h"
#include "platillo.h"
#include "input.h"
#include "camara.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,200);
    glutCreateWindow("Hola Mundo");

    inicializar();

    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);
    glutKeyboardFunc(teclasNormales);
    glutIdleFunc(animacion);

    glutMainLoop();

    return 0;
}
