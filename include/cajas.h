#include "escena.h"

#include <GL/glut.h>

class cajas : public escena {
    protected:
        float tamano;
        int color;
    public:
        cajas(float x, float y, float z, float tamano, int color) : escena(x, y, z) {
            this->tamano = tamano;
            this->color = color;
        };

        //gets
        float getTamano() const { return tamano; }
        
        //sets
        void setTamano(float tamano) { this->tamano = tamano; }

        void dibujar() {
            glPushMatrix();
            switch(color) {
                case 1: glColor3f(1.0, 0.0, 0.0); break; // Rojo
                case 2: glColor3f(0.0, 1.0, 0.0); break; // Verde
                case 3: glColor3f(0.0, 0.0, 1.0); break; // Azul
                case 4: glColor3f(1.0, 1.0, 0.0); break; // Amarillo
                case 5: glColor3f(1.0, 0.0, 1.0); break; // Magenta
                default: glColor3f(1.0, 1.0, 1.0); break; // Blanco por defecto
            }
            glTranslatef(x, y, z);
            glutSolidCube(tamano);
            glPopMatrix();
        };

};

extern cajas miCaja;
extern cajas miCaja2;
extern cajas miCaja3;
extern cajas miCaja4;