#include "escena.h"
#include "camara.h"
#include "platillo.h"
#include "sol.h"
#include <GL/gl.h>
#include <GL/glut.h>

escena miEscena;
Sol miSol(0.0, 25.0, 15.0, 5.0); 

void animacionescena() {
    miNave.animar();
    glutPostRedisplay();
}

void inicializar() {
    glEnable(GL_DEPTH_TEST);
     glEnable(GL_NORMALIZE);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Iluminacion
    GLfloat lightKa[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat lightKd[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat lightKs[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT,  lightKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  lightKd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

    GLfloat matKs[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, matKs);
    glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}

void graficar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    for (int i = 0; i < 6; i++) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity(); 
        glEnable(GL_DEPTH_TEST);

        dibujarVista(i); 
        camaras[i].aplicarvista();
        miSol.posicionarLuz();  
        miSol.dibujar();      

        glEnable(GL_LIGHTING);
        for (int j = 0; j < 6; j++) {
            if (j != i) camaras[j].dibujar();
        }
/*
        glPushMatrix(); 
        glScalef(0,2.5,0);
        glutSolidTeapot(3.0);
        glPopMatrix();
*/

        glPushMatrix();
            glTranslatef(miNave.getX(), miNave.getY(), miNave.getZ());
            glRotatef(-miNave.getYaw(), 0.0, 1.0, 0.0);
            glScalef(0.5, 0.5, 0.5);
            miNave.dibujar();
        glPopMatrix();

        glDisable(GL_LIGHTING);
        miEscena.graficarCuadricula();
        miEscena.graficarejes();
        //crm7
    }
    glutSwapBuffers();
}
