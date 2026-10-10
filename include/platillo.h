#ifndef PLATILLO_H
#define PLATILLO_H

#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

class Platillo {
private:
  float x, y, z;
  float yaw;
  float anguloBase;

public:

  Platillo(float x, float y, float z, float yaw, float anguloBase) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->yaw = yaw;
    this->anguloBase = anguloBase;
  };

  // Getters
  float getX() const { 
    return this->x; 
  };

  float getY() const { 
    return this->y; 
  };

  float getZ() const { 
    return this->z; 
  };

  float getYaw() const { 
    return this->yaw; 
  };
  
  float getAnguloBase() const { 
    return this->anguloBase; 
  };



  // Metodos

void animar() {
    this->anguloBase += 0.5;
    if (this->anguloBase >= 360.0)
      this->anguloBase -= 360.0;
};

void moverAdelante(float distancia) {
    x += sin(yaw * 3.14159265 / 180.0) * distancia;
    z -= cos(yaw * 3.14159265 / 180.0) * distancia;
};

void moverAtras(float distancia) {
    x -= sin(yaw * 3.14159265 / 180.0) * distancia;
    z += cos(yaw * 3.14159265 / 180.0) * distancia;
};

void moverIzquierda(float distancia) {
    x -= cos(yaw * 3.14159265 / 180.0) * distancia;
    z -= sin(yaw * 3.14159265 / 180.0) * distancia;
};

void moverDerecha(float distancia) {
    x += cos(yaw * 3.14159265 / 180.0) * distancia;
    z += sin(yaw * 3.14159265 / 180.0) * distancia;
};

void moverArriba(float distancia) { 
    y += distancia; 
};

void moverAbajo(float distancia) { 
    y -= distancia; 
};

void rotar(float grados) { 
    yaw += grados; 
};

void dibujar() {

    //base
    glPushMatrix();
    glRotatef(anguloBase, 0.0, 1.0, 0.0);

    glColor3f(0.0, 0.6, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 1.0);
    glutSolidSphere(10.0, 50, 50);
    glPopMatrix();

    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < 360; i += 45) {
      glPushMatrix();
      glRotatef((float)i, 0.0, 1.0, 0.0);
      glTranslatef(9.5, 0.0, 0.0);
      glScalef(1.0, 0.2, 1.0);
      glutSolidSphere(1.0, 20, 20);
      glPopMatrix();
    }

    glPopMatrix(); 

    // Cabina
    glColor3f(0.0, 0.6, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 1.5, 0.0);
    glutSolidSphere(4.0, 40, 40);
    glPopMatrix();

    // camara visual
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, 3.5, -3.5);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

};

};

extern Platillo miNave;
extern Platillo miPlato;
void animacionNave();

#endif
