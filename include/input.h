

#ifndef INPUT_H
#define INPUT_H

extern int camaraSeleccionada;
extern bool arrastrando;
extern int mouseAnteriorX, mouseAnteriorY;
extern int tiempoUltimoClic, viewportUltimoClic;

int detectarCamara(int mouseX, int mouseY);
void teclasNormales(unsigned char key, int x, int y);
void flechas(int key, int x, int y);
void clicMouse(int boton, int estado, int x, int y);
void moverMouse(int x, int y);

#endif