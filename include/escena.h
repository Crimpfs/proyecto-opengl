#ifndef ESCENA_H
#define ESCENA_H

#include <GL/glut.h>

void dibujarFocoLuz(float x, float y, float z);
void animacionescena();
void inicializar();
void graficar();

class escena {
private:
    float x, y, z;

public:
    escena(float x = 0.0, float y = 0.0, float z = 0.0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    // Setters
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }

    void graficarCuadricula() {
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);
        int limites = 50;
        int separacion = 2;
        for (int i = -limites; i <= limites; i += separacion) {
            glVertex3f(-limites, 0.0f, (float)i);
            glVertex3f( limites, 0.0f, (float)i);

            glVertex3f((float)i, 0.0f, -limites);
            glVertex3f((float)i, 0.0f,  limites);
        }
        glEnd();
    }

    void graficarejes() {
        glLineWidth(3.0f);

        glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-40.0f, 0.0f, 0.0f);
        glVertex3f( 40.0f, 0.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, -30.0f, 0.0f);
        glVertex3f(0.0f,  30.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, -30.0f);
        glVertex3f(0.0f, 0.0f,  30.0f);
        glEnd();

        glLineWidth(1.0f);      
    }
};

extern escena miEscena;

#endif
