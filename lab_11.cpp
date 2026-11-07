#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

int ancho = 1000;
int alto  = 700;
int camaraSeleccionada = 0;
bool arrastrando    = false;
int mouseAnteriorX  = 0;
int mouseAnteriorY  = 0;
//int tiempoUltimoClic  = 0;
//int viewportUltimoClic = -1;

// ========================================================
// 0. CLASE BASE - padre
// ========================================================
class Objeto {
protected:
    float x, y, z;
public:
    Objeto(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

        virtual ~Objeto() {} 

    //gets
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    //sets 
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }

    virtual void dibujar() = 0; 
    virtual void animar() {} 
};

// ========================================================
// 1. CLASE SOL - hijo
// ========================================================
class Sol : public Objeto{
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


// ========================================================
// 1. CLASE PLATILLO - hijo
// ========================================================
class Platillo : public Objeto {
private:
    float yaw;
    float anguloBase;

public:
    Platillo(float x, float y, float z, float yaw, float anguloBase) :Objeto(x, y, z){
        this->yaw = yaw;
        this->anguloBase = anguloBase;
    }

    // Getters
    float getYaw() const { return this->yaw; }
    float getAnguloBase() const { return this->anguloBase; }

    //sets
    void setYaw(float yaw) { this->yaw = yaw; }
    void setAnguloBase(float anguloBase) { this->anguloBase = anguloBase; }

    // Metodos de movimiento y rotacion
    void moverAdelante(float distancia) {
        x += sin(yaw * 3.14159265 / 180.0) * distancia;
        z -= cos(yaw * 3.14159265 / 180.0) * distancia;
    }

    void moverAtras(float distancia) {
        x -= sin(yaw * 3.14159265 / 180.0) * distancia;
        z += cos(yaw * 3.14159265 / 180.0) * distancia;
    }

    void moverIzquierda(float distancia) {
        x -= cos(yaw * 3.14159265 / 180.0) * distancia;
        z -= sin(yaw * 3.14159265 / 180.0) * distancia;
    }

    void moverDerecha(float distancia) {
        x += cos(yaw * 3.14159265 / 180.0) * distancia;
        z += sin(yaw * 3.14159265 / 180.0) * distancia;
    }

    void moverArriba(float distancia) { 
        y += distancia; 
    }

    void moverAbajo(float distancia) { 
        y -= distancia; 
    }

    void rotar(float grados) { 
        yaw += grados; 
    }

    void animar() override {
        this->anguloBase += 0.5;
        if (this->anguloBase >= 360.0)
            this->anguloBase -= 360.0;

    }

    void dibujar() override {
        // Base
        glPushMatrix();
        glRotatef(anguloBase, 0.0, 1.0, 0.0);

        glColor3f(0.0, 0.6, 0.0);
        glPushMatrix();
        glScalef(1.0, 0.2, 1.0);
        glutSolidSphere(10.0, 50, 50);
        glPopMatrix();

        glColor3f(1.0, 1.0, 0.0);
        for (int i = 0; i < 360; i += 45) {
            glPushMatrix();
            glRotatef((float)i, 0.0, 1.0, 0.0);
            glTranslatef(9.5, 0.0, 0.0);
            glScalef(1.0, 0.2, 1.0);
            glutSolidSphere(1.0, 20, 20);
            glPopMatrix();
        }
        glPopMatrix(); 

        // Cabina
        glColor3f(0.0, 0.6, 1.0);
        glPushMatrix();
        glTranslatef(0.0, 1.5, 0.0);
        glutSolidSphere(4.0, 40, 40);
        glPopMatrix();

        // Camara visual
        glColor3f(1.0, 0.0, 0.0);
        glPushMatrix();
        glTranslatef(0.0, 3.5, -3.5);
        glutSolidSphere(0.5, 20, 20);
        glPopMatrix();
    }
};

// ========================================================
// 2. CLASE CAMARA - hijo
// ========================================================
class camara : public Objeto {
private:
    float yaw, pitch, roll;

public:
    camara(float x, float y, float z, float yaw, float pitch, float roll) :Objeto(x, y, z){
        this->yaw = yaw;
        this->pitch = pitch;
        this->roll = roll;
    }

    // Gets
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    float getRoll() const { return roll; }

    // Sets
    void setYaw(float yaw) { this->yaw = yaw; }
    void setPitch(float pitch) { this->pitch = pitch; }
    void setRoll(float roll) { this->roll = roll; }

    // Metodos de movimiento de la camara
    void orbitar(float movX, float movY) {
        yaw   += movX * 0.4f;
        pitch += movY * 0.4f;
    }

    void acercar() {
        const float rad = 3.14159265f / 180.0f;
        x -= sinf(yaw * rad) * cosf(pitch * rad) * 0.5f;
        y += sinf(pitch * rad) * 0.5f;
        z -= cosf(yaw * rad) * cosf(pitch * rad) * 0.5f;
    }

    void alejar() {
        const float rad = 3.14159265f / 180.0f;
        x += sinf(yaw * rad) * cosf(pitch * rad) * 0.5f;
        y -= sinf(pitch * rad) * 0.5f;
        z += cosf(yaw * rad) * cosf(pitch * rad) * 0.5f;
    }

    void moverPosicion(float dx, float dy, float dz) {
        x += dx;
        y += dy;
        z += dz;
    }
 
    // Vista de la camara
    void aplicarvista() {
        glRotatef(-roll,  0, 0, 1);   // Deshace el roll
        glRotatef(-pitch, 1, 0, 0);   // Deshace el pitch
        glRotatef(-yaw,   0, 1, 0);   // Deshace el yaw
        glTranslatef(-x, -y, -z);     // Mueve el mundo en sentido inverso
    }

    void dibujar() override {
        glPushMatrix();
        glTranslatef(x, y, z);        
        glRotatef(yaw,   0.0, 1.0, 0.0); 
        glRotatef(pitch, 1.0, 0.0, 0.0); 
        glRotatef(roll,  0.0, 0.0, 1.0); 

        glColor3f(0.2f, 0.2f, 0.2f);
        glPushMatrix();
        glScalef(1.6f, 1.0f, 0.9f);
        glutSolidCube(1.0);
        glPopMatrix();

        glColor3f(0.1f, 0.1f, 0.1f);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -0.8f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f); 
        GLUquadric* q = gluNewQuadric();
        gluCylinder(q, 0.3, 0.25, 0.6, 16, 1);
        gluDeleteQuadric(q);
        glPopMatrix();

        glPopMatrix();
    }
};

// ========================================================
// 3. CLASE ESCENA 
// ========================================================
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
        int limites = 40;
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

//0=======================================================
// ESTABLECER ESCENA 
//========================================================

escena miEscena;
Platillo miNave(0.0, 0.0, 0.0, 0.0, 0.0);
Sol miSol(0.0, 25.0, 15.0, 5.0); 

struct ViewportInfo {
    int x, y, w, h;
};

ViewportInfo viewportsCamaras[6];

camara camaras[6] = {
    camara( 20.0, 15.0,  30.0,  33.0, -22.0, 0.0), 
    camara( 25.0,  5.0,   0.0,  90.0, -10.0, 0.0), 
    camara(  0.0,  5.0,  25.0,   0.0, -10.0, 0.0), 
    camara(-25.0,  5.0,   0.0, -90.0, -10.0, 0.0), 
    camara(  0.0,  5.0, -25.0, 180.0, -10.0, 0.0), 
    camara(  0.0, 35.0,   0.1,   0.0, -88.0, 0.0)  
};


void actualizarEscena() {
    miNave.animar();
    glutPostRedisplay();
}
//lo pude hacer class tambienxd
void dibujarFocoLuz(float x, float y, float z) {
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(1.0f, 1.0f, 0.2f);  
    glutSolidSphere(0.8, 20, 20);  
    glPopMatrix();
    glEnable(GL_LIGHTING); 
}

void redimensionar(int w, int h) {
    ancho = w;
    alto  = h;
    int mitad = h / 2;

    viewportsCamaras[0] = { 0,              mitad, (w * 2) / 3,     h - mitad }; // Cam 1 (Grande)
    viewportsCamaras[1] = { (w * 2) / 3,    mitad, w - (w * 2) / 3, h - mitad }; // Cam 2
    viewportsCamaras[5] = { 0,              0,     w / 4,           mitad };     // Cam 6
    viewportsCamaras[4] = { w / 4,          0,     w / 4,           mitad };     // Cam 5
    viewportsCamaras[3] = { w / 2,          0,     w / 6,           mitad };     // Cam 4
    viewportsCamaras[2] = { (w * 2) / 3,    0,     w - (w * 2) / 3, mitad }; 
}
void dibujarVista(int i) {
    glViewport(viewportsCamaras[i].x, viewportsCamaras[i].y, 
               viewportsCamaras[i].w, viewportsCamaras[i].h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float asp = (float)viewportsCamaras[i].w / (float)viewportsCamaras[i].h;
    if (i == 0)
        glFrustum(-2.0*asp, 2.0*asp, -2.0, 2.0, 2.0, 500.0);
    else
        glFrustum(-1.0*asp, 1.0*asp, -1.0, 1.0, 2.0, 500.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void inicializar() {
    glEnable(GL_DEPTH_TEST);
     glEnable(GL_NORMALIZE);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Iluminacion
    GLfloat lightKa[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat lightKd[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat lightKs[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT,  lightKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  lightKd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

    GLfloat matKs[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_SPECULAR, matKs);
    glMaterialf(GL_FRONT, GL_SHININESS, 60.0f);

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

        
        glPushMatrix();
            glTranslatef(miNave.getX(), miNave.getY(), miNave.getZ());
            glRotatef(-miNave.getYaw(), 0.0f, 1.0f, 0.0f);
            glScalef(0.5f, 0.5f, 0.5f);
            miNave.dibujar();
        glPopMatrix();

        glDisable(GL_LIGHTING);
        miEscena.graficarCuadricula();
        miEscena.graficarejes();
    }
    glutSwapBuffers();
}

// ========================================================
// 4. INPUT 
// ========================================================

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

void teclasNormales(unsigned char key, int, int) {
    if (key >= '1' && key <= '6') {
        camaraSeleccionada = key - '1';
        glutPostRedisplay();
        return;
    }
    switch (key) {
        case 'w': case 'W': miNave.moverAdelante(1.0f); break;
        case 's': case 'S': miNave.moverAtras(1.0f); break;
        case 'a': case 'A': miNave.moverIzquierda(1.0f); break;
        case 'd': case 'D': miNave.moverDerecha(1.0f); break;

        case 'q': case 'Q': miNave.rotar(-5.0f); break;
        case 'e': case 'E': miNave.rotar(5.0f); break;

        case 'r': case 'R': miNave.moverArriba(1.0f); break;
        case 'f': case 'F': miNave.moverAbajo(1.0f); break;
    }
    glutPostRedisplay();
}

void flechas(int key, int, int) {
    camara& c = camaras[camaraSeleccionada];
    if (key == GLUT_KEY_LEFT)  c.orbitar(-5, 0);
    if (key == GLUT_KEY_RIGHT) c.orbitar( 5, 0);
    if (key == GLUT_KEY_UP)    c.orbitar( 0,-5);
    if (key == GLUT_KEY_DOWN)  c.orbitar( 0, 5);
    glutPostRedisplay();
}

void clicMouse(int boton, int estado, int x, int y) {
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        camaraSeleccionada = detectarCamara(x, y);
        arrastrando    = true;
        mouseAnteriorX = x;
        mouseAnteriorY = y;
        glutPostRedisplay();
    }
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_UP)
        arrastrando = false;

    if (estado == GLUT_DOWN && (boton == 3 || boton == 4)) {
        camaraSeleccionada = detectarCamara(x, y);
        if (boton == 3) camaras[camaraSeleccionada].acercar();
        else            camaras[camaraSeleccionada].alejar();
        glutPostRedisplay();
    }
}

void moverMouse(int x, int y) {
    if (arrastrando) {
        camaras[camaraSeleccionada].orbitar(
            (float)(x - mouseAnteriorX),
            (float)(y - mouseAnteriorY)
        );
        mouseAnteriorX = x;
        mouseAnteriorY = y;
        glutPostRedisplay();
    }
}



int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(ancho, alto);
    glutCreateWindow("Hola Mundo");

    inicializar();
    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);
    glutKeyboardFunc(teclasNormales);
    glutSpecialFunc(flechas);
    glutMouseFunc(clicMouse);
    glutMotionFunc(moverMouse);
    glutIdleFunc(actualizarEscena);

    glutMainLoop();
    return 0;
}
