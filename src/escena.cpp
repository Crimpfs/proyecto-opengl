#include "escena.h"
#include "cajas.h"
#include "camara.h"
#include "platillo.h"
#include <GL/glut.h>

void inicializar() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

escena miEscenaPrincipal(0.0, 0.0, 0.0);

  
cajas miCaja(15.0, 2.5, 15.0, 5.0, 1);
cajas miCaja2(-15.0, 2.5, 15.0, 5.0, 3);
cajas miCaja3(15.0, 5.0, -15.0, 10.0, 4);
cajas miCaja4(-15.0, 2.5, -15.0, 5.0, 5);



void graficar() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  camara.aplicarCamara();

  miEscenaPrincipal.graficarCuadricula();
  miEscenaPrincipal.graficarejes();
  miCaja.dibujar();
  miCaja2.dibujar();
  miCaja3.dibujar();
  miCaja4.dibujar();

  glPushMatrix();
  glTranslatef(miNave.getX(), miNave.getY(), miNave.getZ());
  glRotatef(-miNave.getYaw(), 0.0f, 1.0f, 0.0f);
  glScalef(0.5f, 0.5f, 0.5f);
  miNave.dibujar();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5.0f, 5.0f, 5.0f);
  glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
  glScalef(0.5f, 0.5f, 0.5f);
  miPlato.dibujar();
  glPopMatrix();

  camara.graficarHUD();

  glutSwapBuffers();
}
