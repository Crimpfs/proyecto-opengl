#include "camara.h"
#include <GL/glut.h>

ViewportInfo viewportsCamaras[6];

camara camaras[6] = {
    camara( 20.0, 15.0,  30.0,  33.0, -22.0, 0.0), 
    camara( 25.0,  5.0,   0.0,  90.0, -10.0, 0.0), 
    camara(  0.0,  5.0,  25.0,   0.0, -10.0, 0.0), 
    camara(-25.0,  5.0,   0.0, -90.0, -10.0, 0.0), 
    camara(  0.0,  5.0, -25.0, 180.0, -10.0, 0.0), 
    camara(  0.0, 35.0,   0.1,   0.0, -88.0, 0.0)  
};

// se podria meter en clas camara 
int ancho = 1000;
int alto  = 700;
int camaraSeleccionada = 0;
bool arrastrando    = false;
int mouseAnteriorX  = 0;
int mouseAnteriorY  = 0;
int tiempoUltimoClic  = 0;
int viewportUltimoClic = -1;
float paso = 0.5;

int detectarCamara(int mouseX, int mouseY) {
    int yDesdeAbajo = alto - mouseY;
    if (yDesdeAbajo >= alto / 2) {
        return (mouseX < (ancho * 2) / 3) ? 0 : 1;
    }
    if (mouseX < ancho / 4) return 5;
    if (mouseX < ancho / 2) return 4;
    if (mouseX < (ancho * 2) / 3) return 3;
    return 2;
}

void redimensionar(int w, int h) {
    ancho = w;
    alto  = h;
    int mitad = h / 2;

    viewportsCamaras[0] = { 0,              mitad, (w * 2) / 3,     h - mitad }; // Cam 1 
    viewportsCamaras[1] = { (w * 2) / 3,    mitad, w - (w * 2) / 3, h - mitad }; // Cam 2
    viewportsCamaras[5] = { 0,              0,     w / 4,           mitad };     // Cam 6
    viewportsCamaras[4] = { w / 4,          0,     w / 4,           mitad };     // Cam 5
    viewportsCamaras[3] = { w / 2,          0,     w / 6,           mitad };     // Cam 4
    viewportsCamaras[2] = { (w * 2) / 3,    0,     w - (w * 2) / 3, mitad }; 
}

void dibujarVista(int i) {
    glViewport(viewportsCamaras[i].x, viewportsCamaras[i].y, viewportsCamaras[i].w, viewportsCamaras[i].h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float asp = (float)viewportsCamaras[i].w / (float)viewportsCamaras[i].h;
    if (i == 0)
        glFrustum(-2.0 * asp, 2.0 * asp, -2.0, 2.0, 2.0, 500.0);
    else
        glFrustum(-1.0 * asp, 1.0 * asp, -1.0, 1.0, 2.0, 500.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}