#include "escena.h"
#include "camara.h"
#include "platillo.h"
#include <GL/glut.h>

void inicializar() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void graficarEjes() {
  glDisable(GL_DEPTH_TEST);
  glLineWidth(3.0);

  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(-40.0, 0.0, 0.0);
  glVertex3f(40.0, 0.0, 0.0);

  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(0.0, -30.0, 0.0);
  glVertex3f(0.0, 30.0, 0.0);

  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.0, 0.0, -30.0);
  glVertex3f(0.0, 0.0, 30.0);
  glEnd();

  glLineWidth(1.0);        // Restaurar grosor normal
  glEnable(GL_DEPTH_TEST); // Volver a activar la profundidad
}

void graficarCuadricula() {
  glColor3f(0.3, 0.3, 0.3);
  glBegin(GL_LINES);
  int limites = 40;
  int separacion = 2;
  for (int i = -limites; i <= limites; i += separacion) {

    glVertex3f(-limites, 0, i);
    glVertex3f(limites, 0, i);

    glVertex3f(i, 0, -limites);
    glVertex3f(i, 0, limites);
  }
  glEnd();
}

void graficarCajas() {
  glPushMatrix();
  glColor3f(1.0, 0.0, 0.0);
  glTranslatef(15.0, 2.5, 15.0);
  glutSolidCube(5.0);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.0, 0.0, 1.0);
  glTranslatef(-15.0, 2.5, 15.0);
  glutSolidCube(5.0);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.0, 1.0, 0.0);
  glTranslatef(15.0, 5.0, -15.0);
  glutSolidCube(10.0);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.0, 0.0, 1.0);
  glTranslatef(-15.0, 2.5, -15.0);
  glutSolidCube(5.0);
  glPopMatrix();
}

void graficarHUD() {
  if (vistaActual != 2)

    return;

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, 100.0, 0.0, 100.0);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glDisable(GL_DEPTH_TEST);

  // --- MARCO DE LA CABINA ---
  glColor3f(0.12, 0.12, 0.15);

  glBegin(GL_QUADS);
  // Abajo
  glVertex2f(30.0, 0.0);
  glVertex2f(70.0, 0.0);
  glVertex2f(70.0, 15.0);
  glVertex2f(30.0, 15.0);
  // Arriba
  glVertex2f(30.0, 85.0);
  glVertex2f(70.0, 85.0);
  glVertex2f(70.0, 100.0);
  glVertex2f(30.0, 100.0);
  // Izquierda
  glVertex2f(0.0, 30.0);
  glVertex2f(15.0, 30.0);
  glVertex2f(15.0, 70.0);
  glVertex2f(0.0, 70.0);
  // Derecha
  glVertex2f(85.0, 30.0);
  glVertex2f(100.0, 30.0);
  glVertex2f(100.0, 70.0);
  glVertex2f(85.0, 70.0);
  glEnd();

  // Esquinas
  glBegin(GL_POLYGON);
  glVertex2f(0.0, 0.0);
  glVertex2f(30.0, 0.0);
  glVertex2f(30.0, 15.0);
  glVertex2f(15.0, 30.0);
  glVertex2f(0.0, 30.0);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex2f(70.0, 0.0);
  glVertex2f(100.0, 0.0);
  glVertex2f(100.0, 30.0);
  glVertex2f(85.0, 30.0);
  glVertex2f(70.0, 15.0);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex2f(0.0, 70.0);
  glVertex2f(15.0, 70.0);
  glVertex2f(30.0, 85.0);
  glVertex2f(30.0, 100.0);
  glVertex2f(0.0, 100.0);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex2f(70.0, 85.0);
  glVertex2f(85.0, 70.0);
  glVertex2f(100.0, 70.0);
  glVertex2f(100.0, 100.0);
  glVertex2f(70.0, 100.0);
  glEnd();

  // --- BORDES  ---
  glColor3f(0.4, 0.4, 0.45);
  glLineWidth(6.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(30.0, 15.0);
  glVertex2f(70.0, 15.0);
  glVertex2f(85.0, 30.0);
  glVertex2f(85.0, 70.0);
  glVertex2f(70.0, 85.0);
  glVertex2f(30.0, 85.0);
  glVertex2f(15.0, 70.0);
  glVertex2f(15.0, 30.0);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(30.0, 15.0);
  glVertex2f(0.0, 0.0);
  glVertex2f(70.0, 15.0);
  glVertex2f(100.0, 0.0);
  glVertex2f(30.0, 85.0);
  glVertex2f(0.0, 100.0);
  glVertex2f(70.0, 85.0);
  glVertex2f(100.0, 100.0);
  glEnd();

  // --- PANELES DE CONTROL  ---
  // Pantalla Izquierda
  glColor3f(0.0, 0.8, 1.0);
  glBegin(GL_QUADS);
  glVertex2f(35.0, 3.0);
  glVertex2f(43.0, 3.0);
  glVertex2f(43.0, 10.0);
  glVertex2f(35.0, 10.0);
  glEnd();

  // Pantalla Derecha
  glColor3f(1.0, 0.5, 0.0);
  glBegin(GL_QUADS);
  glVertex2f(57.0, 3.0);
  glVertex2f(65.0, 3.0);
  glVertex2f(65.0, 10.0);
  glVertex2f(57.0, 10.0);
  glEnd();

  // Radar Central Hexagonal
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f(48.5, 3.0);
  glVertex2f(51.5, 3.0);
  glVertex2f(54.0, 6.5);
  glVertex2f(51.5, 10.0);
  glVertex2f(48.5, 10.0);
  glVertex2f(46.0, 6.5);
  glEnd();

  // --- MIRA LÁSER ---
  glColor3f(1.0, 0.0, 0.0);
  glLineWidth(2.0);
  glBegin(GL_LINES);
  // Cruz horizontal
  glVertex2f(48.0, 50.0);
  glVertex2f(52.0, 50.0);
  // Cruz vertical
  glVertex2f(50.0, 48.0);
  glVertex2f(50.0, 52.0);
  glEnd();

  glPointSize(4.0);
  glBegin(GL_POINTS);
  glVertex2f(50.0, 50.0);
  glEnd();

  glEnable(GL_DEPTH_TEST);
  glLineWidth(1.0);

  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

void graficar() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  aplicarCamara();

  graficarCuadricula();
  graficarEjes();
  graficarCajas();

  // Dibujamos la nave usando su propio método encapsulado
  miNave.dibujar();

  graficarHUD();

  glutSwapBuffers();
}
