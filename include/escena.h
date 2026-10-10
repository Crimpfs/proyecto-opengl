#ifndef ESCENA_H
#define ESCENA_H
#include <GL/glut.h>

void inicializar();
void graficar();

class escena {
    protected:
    float x, y, z;

    public:
    escena(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };
    
    //gets 
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    //sets
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }

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
};

void graficarejes(){
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
};

};


#endif