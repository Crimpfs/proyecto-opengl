#ifndef CAMARA_H
#define CAMARA_H

#include <GL/glut.h>
#include <cmath>
#include "objetos.h"

struct ViewportInfo {
    int x, y, w, h;
};

class camara : public Objeto {
private:
    float yaw, pitch, roll;

public:
    camara(float x, float y, float z, float yaw, float pitch, float roll) : Objeto(x, y, z) {
        this->yaw = yaw;
        this->pitch = pitch;
        this->roll = roll;
    }

    // Gets
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    float getRoll() const { return roll; }

    // Sets
    void setYaw(float yaw) { this->yaw = yaw; }
    void setPitch(float pitch) { this->pitch = pitch; }
    void setRoll(float roll) { this->roll = roll; }

    // Metodos de movimiento de la camara
    void orbitar(float movX, float movY) {
        yaw   += movX * 0.4f;
        pitch += movY * 0.4f;
    }

    void acercar() {
        const float rad = 3.14159265f / 180.0f;
        x -= sinf(yaw * rad) * cosf(pitch * rad) * 0.5f;
        y += sinf(pitch * rad) * 0.5f;
        z -= cosf(yaw * rad) * cosf(pitch * rad) * 0.5f;
    }

    void alejar() {
        const float rad = 3.14159265f / 180.0f;
        x += sinf(yaw * rad) * cosf(pitch * rad) * 0.5f;
        y -= sinf(pitch * rad) * 0.5f;
        z += cosf(yaw * rad) * cosf(pitch * rad) * 0.5f;
    }

    void moverPosicion(float dx, float dy, float dz) {
        x += dx;
        y += dy;
        z += dz;
    }
 
    void aplicarvista() {
        glRotatef(-roll,  0, 0, 1);   // Deshace el roll
        glRotatef(-pitch, 1, 0, 0);   // Deshace el pitch
        glRotatef(-yaw,   0, 1, 0);   // Deshace el yaw
        glTranslatef(-x, -y, -z);     // Mueve el mundo en sentido inverso
    }

    void dibujar() override {
        glPushMatrix();
        glTranslatef(this->x, this->y, this->z);        
        glRotatef(yaw,   0.0, 1.0, 0.0); 
        glRotatef(pitch, 1.0, 0.0, 0.0); 
        glRotatef(roll,  0.0, 0.0, 1.0); 

        glColor3f(0.2, 0.2, 0.2);
        glPushMatrix();
        glScalef(1.6, 1.0, 0.9);
        glutSolidCube(1.0);
        glPopMatrix();


        glColor3f(0.1, 0.1, 0.1);
        glPushMatrix();
        glTranslatef(0.0, 0.0, -0.45); 
        
        glRotatef(180.0, 0.0, 1.0, 0.0); 
        GLUquadric* q = gluNewQuadric();
        gluCylinder(q, 0.35, 0.25, 0.6, 20, 1); 
        glPushMatrix();
        glTranslatef(0.0, 0.0, 0.6);
        glColor3f(0.0, 0.5, 0.8); 
        gluDisk(q, 0.0, 0.25, 20, 1);
        glPopMatrix();
        gluDeleteQuadric(q);
        glPopMatrix();

        glPopMatrix();
    }
};
extern ViewportInfo viewportsCamaras[6];
extern camara camaras[6];
extern int ancho, alto;

void redimensionar(int w, int h);
void dibujarVista(int i);

#endif
