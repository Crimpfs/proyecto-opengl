#ifndef CAMARA_H
#define CAMARA_H
#include"platillo.h"
#include <GL/glut.h>


extern int vistaActual;
void redimensionar(int w, int h);

class camara {
private:
    float x, y, z;
    float yaw, pitch, roll;
public:
    camara(float x, float y, float z, float yaw, float pitch, float roll) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->yaw = yaw;
        this->pitch = pitch;
        this->roll = roll;
    };

 //gets
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    float getRoll() const { return roll; }

    //sets
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }
    void setYaw(float yaw) { this->yaw = yaw; }
    void setPitch(float pitch) { this->pitch = pitch; }
    void setRoll(float roll) { this->roll = roll; }

void camara_1(){
    glRotatef(22.58, 1.0, 0.0, 0.0);   
    glRotatef(-33.69, 0.0, 1.0, 0.0);  
    glTranslatef(-20.0, -15.0, -30.0); 
}

void camara_2(){
    glTranslatef(0.0, -1.75, 1.75); 
    glRotatef(miNave.getYaw(), 0.0, 1.0, 0.0);
    glTranslatef(-miNave.getX(), -miNave.getY(), -miNave.getZ());
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

void camara_3(){
    glRotatef(90.0, 1.0, 0.0, 0.0);   
    glTranslatef(0.0, -50.0, 0.0);   
}

void aplicarCamara() {
  if (vistaActual == 1) {
    camara_1();

  } else {
    if (vistaActual == 2) {
      camara_2();

    } else {
      if (vistaActual == 3) {
        camara_3();
       
      }
    }
  }
}

};

extern class camara camara;

#endif
