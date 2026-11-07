
#ifndef OBJETOS_H
#define OBJETOS_H

#include <GL/glut.h>

class Objeto{
protected:
    float x, y, z;
public:
    Objeto(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    virtual ~Objeto() {} 

    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    // Setters
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }

    
    virtual void dibujar() = 0; 
    virtual void animar() {}    

};
    
#endif