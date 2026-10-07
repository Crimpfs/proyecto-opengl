#ifndef PLATILLO_H
#define PLATILLO_H

#include <string>

// Declaración de la Clase Platillo
class Platillo {
private:
    float x, y, z;
    float yaw;          // Hacia dónde apunta (antes anguloCamaraY)
    float anguloBase;   // Rotación del trompo verde (antes anguloRotacion)

public:
    Platillo();
    Platillo(float startX, float startY, float startZ);

    void animar(); 
    void moverAdelante(float distancia);
    void moverAtras(float distancia);
    void moverIzquierda(float distancia);
    void moverDerecha(float distancia);
    void moverArriba(float distancia);
    void moverAbajo(float distancia);
    void rotar(float grados);

    // Getters para que la cámara pueda seguir a la nave
    float getX() const;
    float getY() const;
    float getZ() const;
    float getYaw() const;
    float getAnguloBase() const;

    // Método para imprimir estado (similar a Java)
    std::string toString() const;

    void dibujar();
};

// Instancia global (temporal) para conectar todo el proyecto
extern Platillo miNave;

// Callback global para GLUT
void animacionNave();

#endif

#endif
