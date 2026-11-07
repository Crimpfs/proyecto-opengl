#include "input.h"
#include "camara.h"
#include "platillo.h"
#include <GL/glut.h>

void teclasNormales(unsigned char key, int, int) {
    if (key >= '1' && key <= '6') {
        camaraSeleccionada = key - '1';
        glutPostRedisplay();
        return;
    }

    // Mover la nave con W, A, S, D, Q, E, R, F
    switch (key) {
        case 'w': case 'W': miNave.moverAdelante(1.0f); break;
        case 's': case 'S': miNave.moverAtras(1.0f); break;
        case 'a': case 'A': miNave.moverIzquierda(1.0f); break;
        case 'd': case 'D': miNave.moverDerecha(1.0f); break;

        case 'q': case 'Q': miNave.rotar(-5.0f); break;
        case 'e': case 'E': miNave.rotar(5.0f); break;

        case 'r': case 'R': miNave.moverArriba(1.0f); break;
        case 'f': case 'F': miNave.moverAbajo(1.0f); break;
    }

    glutPostRedisplay();
}

void flechas(int key, int, int) {
    camara& c = camaras[camaraSeleccionada];
    if (key == GLUT_KEY_LEFT)  c.orbitar(-5, 0);
    if (key == GLUT_KEY_RIGHT) c.orbitar( 5, 0);
    if (key == GLUT_KEY_UP)    c.orbitar( 0,-5);
    if (key == GLUT_KEY_DOWN)  c.orbitar( 0, 5);
    glutPostRedisplay();
}

void clicMouse(int boton, int estado, int x, int y) {
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        camaraSeleccionada = detectarCamara(x, y);
        arrastrando    = true;
        mouseAnteriorX = x;
        mouseAnteriorY = y;
        glutPostRedisplay();
    }
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_UP)
        arrastrando = false;

    if (estado == GLUT_DOWN && (boton == 3 || boton == 4)) {
        camaraSeleccionada = detectarCamara(x, y);
        if (boton == 3) camaras[camaraSeleccionada].acercar();
        else            camaras[camaraSeleccionada].alejar();
        glutPostRedisplay();
    }
}

void moverMouse(int x, int y) {
    if (arrastrando) {
        camaras[camaraSeleccionada].orbitar(
            (float)(x - mouseAnteriorX),
            (float)(y - mouseAnteriorY)
        );
        mouseAnteriorX = x;
        mouseAnteriorY = y;
        glutPostRedisplay();
    }
}
