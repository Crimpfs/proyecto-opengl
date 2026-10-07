#include "platillo.h"
#include <GL/glut.h>
<<<<<<< HEAD
#include <math.h>

// Instanciamos el objeto global
Platillo miNave(0.0f, 0.0f, 0.0f);

// Constructor completo con 3 parámetros iniciales
Platillo::Platillo(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->yaw = 0.0f;
    this->anguloBase = 0.0f;
}

// Sobrecarga de constructor por defecto
Platillo::Platillo() {
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
    this->yaw = 0.0f;
    this->anguloBase = 0.0f;
}

// Getters explícitos
float Platillo::getX() const {
    return this->x;
}

float Platillo::getY() const {
    return this->y;
}

float Platillo::getZ() const {
    return this->z;
}

float Platillo::getYaw() const {
    return this->yaw;
}

float Platillo::getAnguloBase() const {
    return this->anguloBase;
}

#include <sstream>
// Método similar al toString de Java para inspección
std::string Platillo::toString() const {
    std::ostringstream ss;
    ss << "Nave [ X: " << this->x 
       << ", Y: " << this->y 
       << ", Z: " << this->z 
       << " | Yaw: " << this->yaw 
       << " ]";
    return ss.str();
}

// Métodos de acción
void Platillo::animar() {
    this->anguloBase += 0.5f;
    if (this->anguloBase >= 360.0f) {
        this->anguloBase -= 360.0f;
    }
}

void Platillo::moverAdelante(float distancia) {
    this->x += sin(this->yaw * 3.14159265f / 180.0f) * distancia;
    this->z -= cos(this->yaw * 3.14159265f / 180.0f) * distancia;
}

void Platillo::moverAtras(float distancia) {
    this->x -= sin(this->yaw * 3.14159265f / 180.0f) * distancia;
    this->z += cos(this->yaw * 3.14159265f / 180.0f) * distancia;
}

void Platillo::moverIzquierda(float distancia) {
    this->x -= cos(this->yaw * 3.14159265f / 180.0f) * distancia;
    this->z -= sin(this->yaw * 3.14159265f / 180.0f) * distancia;
}

void Platillo::moverDerecha(float distancia) {
    this->x += cos(this->yaw * 3.14159265f / 180.0f) * distancia;
    this->z += sin(this->yaw * 3.14159265f / 180.0f) * distancia;
}

void Platillo::moverArriba(float distancia) { this->y += distancia; }
void Platillo::moverAbajo(float distancia) { this->y -= distancia; }
void Platillo::rotar(float grados) { this->yaw += grados; }

// Método dibujar (POO) encapsulado
void Platillo::dibujar() {
    glPushMatrix();
    
    // El objeto mismo se posiciona y se escala en el mundo
    glTranslatef(x, y, z);
    glRotatef(-yaw, 0.0, 1.0, 0.0);
    glScalef(0.5, 0.5, 0.5);

    // --- ROTACIÓN DE LA BASE ---
    glPushMatrix();
    glRotatef(anguloBase, 0.0, 1.0, 0.0);

    // 1. Esfera verde 
    glColor3f(0.0, 0.6, 0.0); 
    glPushMatrix();
    glScalef(1.0, 0.2, 1.0); 
    glutSolidSphere(10.0, 50, 50);
    glPopMatrix();

    // 2. Focos amarillos 
    glColor3f(1.0, 1.0, 0.0); 
    for(int i = 0; i < 360; i += 45) {
        glPushMatrix();
        glRotatef((float)i, 0.0, 1.0, 0.0);
        glTranslatef(9.5, 0.0, 0.0); 
        glScalef(1.0, 0.2, 1.0); 
        glutSolidSphere(1.0, 20, 20); 
        glPopMatrix();
    }
    
    glPopMatrix(); // Fin de la rotación de la base

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

    glPopMatrix(); // Fin del dibujo de Platillo
}

// Wrapper para GLUT (se comunica con el objeto global)
void animacionNave() {
    miNave.animar();
    glutPostRedisplay();
=======
#include <cmath>

#define PI 3.14159265358979323846

float anguloRotacion = 0.5;
float theta = 0.0;
float radio = 0.0;
float altura = 0.0;

float posicionBaseX = 0.0f;
float posicionBaseY = 0.0f;
float posicionBaseZ = 0.0f;

float posicionTrayectoriaX = 0.0f;
float posicionTrayectoriaZ = 0.0f;

void rotarPlatillo(int valor) {
    anguloRotacion += 0.8;
    if (anguloRotacion >= 360.0) anguloRotacion -= 360.0;
    glutPostRedisplay();
    glutTimerFunc(16, rotarPlatillo, 0);
}

void platillo(){
    glPushMatrix();
        glColor3f(0.0, 0.6, 0.0); 
        glTranslatef(posicionBaseX, posicionBaseY, posicionBaseZ);
        glRotatef(theta, 0, 1, 0);
        glTranslatef(radio, altura, 0);
        glRotatef(anguloRotacion, 0.0, 1.0, 0.0);
        glPushMatrix();
            glScalef(1.0, 0.2, 1.0); 
            glutWireSphere(10.0, 50, 50);
        glPopMatrix();
    glPopMatrix();
}

void cabina(){
    glPushMatrix();
        posicionTrayectoriaX = posicionBaseX + radio * cos(theta * PI / 180.0f);
        posicionTrayectoriaZ = posicionBaseZ - radio * sin(theta * PI / 180.0f);
        glTranslatef(posicionTrayectoriaX, posicionBaseY + altura, posicionTrayectoriaZ);
        glPushMatrix();//cabina
            glColor3f(0.0, 0.6, 1.0); 
            glTranslatef(0.0, 1.5, 0.0);
            glutWireSphere(4.0, 40, 40);
        glPopMatrix();
        glPushMatrix(); //camara visual
            glColor3f(1.0, 0.0, 0.0);
            glTranslatef(0.0, 3.5, -3.5);
            glutSolidSphere(0.5, 20, 20); 
        glPopMatrix();
    glPopMatrix();
}

void graficarPlatillo(){
    platillo();
    cabina();    
>>>>>>> abcde66da20f22b84cb76318df36ac68cf896ce5
}
