#ifndef SOL_H
#define SOL_H

#include "objetos.h"
#include <GL/glut.h>

class Sol : public Objeto {
private:
    float radio;
public:
    Sol(float x, float y, float z, float radio) : Objeto(x, y, z) {
        this->radio = radio;
    };

    // Gets
    float getRadio() const { return this->radio; }
    // Sets
    void setRadio(float radio) { this->radio = radio; }

    void posicionarLuz() {
        GLfloat posLuz[] = { this->x, this->y, this->z, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, posLuz);
    }

    void dibujar() override {
        glDisable(GL_LIGHTING); 
        glPushMatrix();
        glTranslatef(this->x, this->y, this->z);
        glColor3f(1.0, 1.0, 0.0);
        glutSolidSphere(this->radio, 30, 30);
        glPopMatrix();
        glEnable(GL_LIGHTING);  
    }
};
#endif
