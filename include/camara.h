#ifndef CAMARA_H
#define CAMARA_H

#include <GL/glut.h>
#include <cmath>

struct ViewportInfo {
    int x, y, w, h;
};

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
    }

    // Gets
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    float getRoll() const { return roll; }

    // Sets
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }
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

    void dibujar() {
        glPushMatrix();
        glTranslatef(x, y, z);        
        glRotatef(yaw,   0.0f, 1.0f, 0.0f); 
        glRotatef(pitch, 1.0f, 0.0f, 0.0f); 
        glRotatef(roll,  0.0f, 0.0f, 1.0f); 

        glColor3f(0.2f, 0.2f, 0.2f);
        glPushMatrix();
        glScalef(1.6f, 1.0f, 0.9f);
        glutSolidCube(1.0);
        glPopMatrix();


        glColor3f(0.1f, 0.1f, 0.1f);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -0.45f); 
        
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f); 
        GLUquadric* q = gluNewQuadric();
        gluCylinder(q, 0.35, 0.25, 0.6, 20, 1); // Tubo del lente cónico
        // Tapa frontal del lente (cristal del lente en la punta)
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.6f);
        glColor3f(0.0f, 0.5f, 0.8f); 
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
extern int camaraSeleccionada;
extern bool arrastrando;
extern int mouseAnteriorX, mouseAnteriorY;
extern int tiempoUltimoClic, viewportUltimoClic;
extern float paso;

int  detectarCamara(int mouseX, int mouseY);
void redimensionar(int w, int h);

#endif
