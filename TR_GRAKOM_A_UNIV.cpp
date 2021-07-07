#include <windows.h>
#include <gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
//=====================================================
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
//======================================================
float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;
void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}
void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 25.0;
        break;
    case 'd':
    case 'D':
        xmov -= 25.0;
        break;
    case 's':
    case 'S':
        zmov -= 25.0;
        break;
    case 'a':
    case 'A':
        xmov += 25.0;
        break;
    case 'q':
        ymov += 25.0;
        break;
    case 'e':
        ymov -= 25.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}
void mySpecialFunc(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        xmov += 10;
        if (xmov > 360) xmov = 0.0;
        break;
    case GLUT_KEY_LEFT:
        xmov -= 10;
        if (xmov > 360) xmov = 0.0;
        break;
    case GLUT_KEY_UP:
        ymov += 10;
        if (ymov > 360) ymov = 0.0;
        break;
    case GLUT_KEY_DOWN:
        ymov -= 10;
        if (ymov > 360) ymov = 0.0;
        break;
    }
    glutPostRedisplay();
}
void init(void) {
    glClearColor(0.53, 0.8, 0.98, 0.0);
    glViewport(10, 10, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}
void tampil(void) {
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();
    //alas
    glBegin(GL_QUADS);
    glColor3f(0.54, 0.54, 0.54);
    glVertex3f(-900, 0.0, 500.0);
    glVertex3f(1800, 0.0, 500.0);
    glVertex3f(1800, 0.0, -300.0);
    glVertex3f(-900, 0.0, -300.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.9, 0.1);
    glVertex3f(-900, 0.0, 500.0);
    glVertex3f(1800, 0.0, 500.0);
    glVertex3f(1800, 0.0, 700.0);
    glVertex3f(-900, 0.0, 700.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.9, 0.1);
    glVertex3f(1800, 0.0, -300.0);
    glVertex3f(2100, 0.0, -300.0);
    glVertex3f(2100, 0.0, 700.0);
    glVertex3f(1800, 0.0, 700.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.9, 0.1);
    glVertex3f(-900, 0.0, -300.0);
    glVertex3f(-1100, 0.0, -300.0);
    glVertex3f(-1100, 0.0, 700.0);
    glVertex3f(-900, 0.0, 700.0);
    glEnd();
    //tembok kiri
    glBegin(GL_QUADS);//tembok kiri
    glColor3f(0.48, 0.34, 0);
    glVertex3f(-720, 0.0, 0.0);
    glVertex3f(-720, 800.0, 0.0);
    glVertex3f(-720, 800.0, -200.0);
    glVertex3f(-720, 0.0, -200.0);
    //bawah coklat muda
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-725, 0.0, 0.0);
    glVertex3f(-725, 20.0, 0.0);
    glVertex3f(-725, 20.0, -200.0);
    glVertex3f(-725, 0.0, -200.0);
    //bawah
    glVertex3f(-720, 20.0, 0.0);
    glVertex3f(-725, 20.0, 0.0);
    glVertex3f(-725, 20.0, -200.0);
    glVertex3f(-720, 20.0, -200.0);
    //bawah
    glVertex3f(-720, 0.0, 0.0);
    glVertex3f(-725, 0.0, 0.0);
    glVertex3f(-725, 20.0, 0.0);
    glVertex3f(-720, 20.0, 0.0);
    //bawah
    glVertex3f(-720, 0.0, -200.0);
    glVertex3f(-725, 0.0, -200.0);
    glVertex3f(-725, 20.0, -200.0);
    glVertex3f(-720, 20.0, -200.0);
    //atas coklat muda
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-725, 760.0, 0.0);
    glVertex3f(-725, 800.0, 0.0);
    glVertex3f(-725, 800.0, -200.0);
    glVertex3f(-725, 760.0, -200.0);
    //atas
    glVertex3f(-720, 800.0, 0.0);
    glVertex3f(-725, 800.0, 0.0);
    glVertex3f(-725, 800.0, -200.0);
    glVertex3f(-720, 800.0, -200.0);
    //atas
    glVertex3f(-720, 760.0, 0.0);
    glVertex3f(-725, 760.0, 0.0);
    glVertex3f(-725, 800.0, 0.0);
    glVertex3f(-720, 800.0, 0.0);
    //atas
    glVertex3f(-720, 760.0, -200.0);
    glVertex3f(-725, 760.0, -200.0);
    glVertex3f(-725, 800.0, -200.0);
    glVertex3f(-720, 800.0, -200.0);
    //pilar
    glVertex3f(-720, 0.0, 0.0);
    glVertex3f(-720, 800.0, 0.0);
    glVertex3f(-720, 800.0, -10.0);
    glVertex3f(-720, 0.0, -10.0);
    //pilar
    glVertex3f(-720, 0.0, -200.0);
    glVertex3f(-720, 800.0, -200.0);
    glVertex3f(-720, 800.0, -190.0);
    glVertex3f(-720, 0.0, -190.0);
    //-===================================
    glBegin(GL_QUADS);//tembok belakang
    glColor3f(0.48, 0.34, 0);
    glVertex3f(-720, 0.0, -200);
    glVertex3f(-720, 800.0, -200);
    glVertex3f(1550, 800.0, -200);
    glVertex3f(1550, 0.0, -200);
    //list bawah coklat muda
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-725, 0.0, -200.1);
    glVertex3f(-725, 20.0, -200.1);
    glVertex3f(1555, 20.0, -200.1);
    glVertex3f(1555, 0.0, -200.1);
    //list atas coklat muda
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-725, 760.0, -200.1);
    glVertex3f(-725, 800.0, -200.1);
    glVertex3f(1555, 800.0, -200.1);
    glVertex3f(1555, 760.0, -200.1);
    glEnd();
    //============================
    glBegin(GL_QUADS);//tembok kanan
    glColor3f(0.48, 0.34, 0);
    glVertex3f(1550, 0.0, 0.0);
    glVertex3f(1550, 800.0, 0.0);
    glVertex3f(1550, 800.0, -200.0);
    glVertex3f(1550, 0.0, -200.0);
    //bawah coklat muda
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(1555, 0.0, 0.0);
    glVertex3f(1555, 20.0, 0.0);
    glVertex3f(1555, 20.0, -200.0);
    glVertex3f(1555, 0.0, -200.0);
    //bawah
    glVertex3f(1550, 20.0, 0.0);
    glVertex3f(1555, 20.0, 0.0);
    glVertex3f(1555, 20.0, -200.0);
    glVertex3f(1550, 20.0, -200.0);
    //bawah
    glVertex3f(1550, 0.0, 0.0);
    glVertex3f(1555, 0.0, 0.0);
    glVertex3f(1555, 20.0, 0.0);
    glVertex3f(1550, 20.0, 0.0);
    //bawah
    glVertex3f(1550, 0.0, -200.0);
    glVertex3f(1555, 0.0, -200.0);
    glVertex3f(1555, 20.0, -200.0);
    glVertex3f(1550, 20.0, -200.0);
    //atas
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(1555, 760.0, 0.0);
    glVertex3f(1555, 800.0, 0.0);
    glVertex3f(1555, 800.0, -200.0);
    glVertex3f(1555, 760.0, -200.0);
    //atas
    glVertex3f(1550, 800.0, 0.0);
    glVertex3f(1555, 800.0, 0.0);
    glVertex3f(1555, 800.0, -200.0);
    glVertex3f(1550, 800.0, -200.0);
    //atas
    glVertex3f(1550, 760.0, 0.0);
    glVertex3f(1555, 760.0, 0.0);
    glVertex3f(1555, 800.0, 0.0);
    glVertex3f(1550, 800.0, 0.0);
    //atas
    glVertex3f(1550, 760.0, -200.0);
    glVertex3f(1555, 760.0, -200.0);
    glVertex3f(1555, 800.0, -200.0);
    glVertex3f(1550, 800.0, -200.0);
    //pilar
    glVertex3f(1550.1, 0.0, 0.0);
    glVertex3f(1550.1, 800.0, 0.0);
    glVertex3f(1550.1, 800.0, -10.0);
    glVertex3f(1550.1, 0.0, -10.0);
    //pilar
    glVertex3f(1550.1, 0.0, -200.0);
    glVertex3f(1550.1, 800.0, -200.0);
    glVertex3f(1550.1, 800.0, -190.0);
    glVertex3f(1550.1, 0.0, -190.0);
    glEnd();
    //tembok tambahan kiri 1
    glBegin(GL_QUADS);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(-400, 0.0, 0.0);
    glVertex3f(-70, 0.0, 0.0);
    glVertex3f(-70, 800.0, 0.0);
    glVertex3f(-400, 800.0, 0.0);
    glEnd();
    //pintu kecil kiri
    glBegin(GL_QUADS);//frame pintu kecil kiri
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-370, 50.0, 0.1);
    glVertex3f(-370, 380.0, 0.1);
    glVertex3f(-480, 380.0, 0.1);
    glVertex3f(-480, 50.0, 0.1);
    glEnd();
    glBegin(GL_QUADS);//list pintu
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-370, 50.0, 0.2);
    glVertex3f(-375, 50.0, 0.2);
    glVertex3f(-375, 385.0, 0.2);
    glVertex3f(-370, 385.0, 0.2);
    //
    glVertex3f(-480, 50.0, 0.2);
    glVertex3f(-485, 50.0, 0.2);
    glVertex3f(-485, 385.0, 0.2);
    glVertex3f(-480, 385.0, 0.2);
    //
    glVertex3f(-375, 385.0, 0.1);
    glVertex3f(-375, 380.0, 0.1);
    glVertex3f(-485, 380.0, 0.1);
    glVertex3f(-485, 385.0, 0.1);
    glEnd();
    //tangga pintu 
    glBegin(GL_QUADS);//tangga pintu
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-375, 50.0, 0.0);
    glVertex3f(-375, 50.0, 20.0);
    glVertex3f(-485, 50.0, 20.0);
    glVertex3f(-485, 50.0, 0.0);
    //
    glVertex3f(-375, 25.0, 0.0);
    glVertex3f(-375, 25.0, 40.0);
    glVertex3f(-485, 25.0, 40.0);
    glVertex3f(-485, 25.0, 0.0);
    glEnd();
    //tangga
    glBegin(GL_QUADS);//tangga
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-375, 50.0, 20.2);
    glVertex3f(-375, 0.0, 20.2);
    glVertex3f(-485, 0.0, 20.2);
    glVertex3f(-485, 50.0, 20.2);
    //
    glVertex3f(-375, 25.0, 40.2);
    glVertex3f(-375, 0.0, 40.2);
    glVertex3f(-485, 0.0, 40.2);
    glVertex3f(-485, 25.0, 40.2);
    //
    glVertex3f(-375, 25.0, 20.2);
    glVertex3f(-375, 0.0, 20.2);
    glVertex3f(-375, 0.0, 40.2);
    glVertex3f(-375, 25.0, 40.2);
    //
    glVertex3f(-485, 25.0, 20.2);
    glVertex3f(-485, 0.0, 20.2);
    glVertex3f(-485, 0.0, 40.2);
    glVertex3f(-485, 25.0, 40.2);
    glEnd();
    //pintu kedepan
    glBegin(GL_QUADS);//list pintu
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-375, 0.0, 0);
    glVertex3f(-375, 0.0, 20);
    glVertex3f(-375, 385.0, 20);
    glVertex3f(-375, 385.0, 0);
    //
    glVertex3f(-485, 0.0, 0);
    glVertex3f(-485, 0.0, 20);
    glVertex3f(-485, 385.0, 20);
    glVertex3f(-485, 385.0, 0);
    //    
    glVertex3f(-375, 385.0, 0);
    glVertex3f(-375, 385.0, 20);
    glVertex3f(-485, 385.0, 20);
    glVertex3f(-485, 385.0, 0);
    glEnd();
    //pintu dalam
    glBegin(GL_QUADS);//pintu dalam
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(-380, 50.0, 0.2);
    glVertex3f(-380, 370.0, 0.2);
    glVertex3f(-470, 370.0, 0.2);
    glVertex3f(-470, 50.0, 0.2);
    glEnd();
    //handle pintu
    glBegin(GL_QUADS);//handle pintu dalam
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-460, 220.0, 0.3);
    glVertex3f(-460, 180.0, 0.3);
    glVertex3f(-465, 180.0, 0.3);
    glVertex3f(-465, 220.0, 0.3);
    glEnd();
    //jendela tambahan kiri
    // frame jendela kecil atas
    glBegin(GL_QUADS);//frame jendela kecil atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-100, 720.0, 0.1);
    glVertex3f(-100, 670.0, 0.1);
    glVertex3f(-150, 670.0, 0.1);
    glVertex3f(-150, 720.0, 0.1);
    //frame jendela kecil atas
    glVertex3f(-220, 720.0, 0.1);
    glVertex3f(-220, 670.0, 0.1);
    glVertex3f(-270, 670.0, 0.1);
    glVertex3f(-270, 720.0, 0.1);
    //frame jendela kecil atas
    glVertex3f(-280, 720.0, 0.1);
    glVertex3f(-280, 670.0, 0.1);
    glVertex3f(-330, 670.0, 0.1);
    glVertex3f(-330, 720.0, 0.1);
    glEnd();
    //jendela kecil atas
    glBegin(GL_QUADS);//jedela depan kecil atas
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-105, 715.0, 0.2);
    glVertex3f(-105, 675.0, 0.2);
    glVertex3f(-145, 675.0, 0.2);
    glVertex3f(-145, 715.0, 0.2);
    //jendela atas kecil
    glVertex3f(-225, 715.0, 0.2);
    glVertex3f(-225, 675.0, 0.2);
    glVertex3f(-265, 675.0, 0.2);
    glVertex3f(-265, 715.0, 0.2);
    //jendela atas kecil
    glVertex3f(-285, 715.0, 0.2);
    glVertex3f(-285, 675.0, 0.2);
    glVertex3f(-325, 675.0, 0.2);
    glVertex3f(-325, 715.0, 0.2);
    glEnd();
    //frame jendela panjang atas
    glBegin(GL_QUADS);//frame jendela panjang atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-100, 660.0, 0.1);
    glVertex3f(-100, 500.0, 0.1);
    glVertex3f(-150, 500.0, 0.1);
    glVertex3f(-150, 660.0, 0.1);
    //frame jendela panjang atas
    glVertex3f(-220, 660.0, 0.1);
    glVertex3f(-220, 500.0, 0.1);
    glVertex3f(-270, 500.0, 0.1);
    glVertex3f(-270, 660.0, 0.1);
    //frame jendela panjang atas
    glVertex3f(-280, 660.0, 0.1);
    glVertex3f(-280, 500.0, 0.1);
    glVertex3f(-330, 500.0, 0.1);
    glVertex3f(-330, 660.0, 0.1);
    glEnd();
    //jendela panjang atas
    glBegin(GL_QUADS);//jedela depan panjang atas
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-105, 655.0, 0.2);
    glVertex3f(-105, 505.0, 0.2);
    glVertex3f(-145, 505.0, 0.2);
    glVertex3f(-145, 655.0, 0.2);
    //jendela atas panjang
    glVertex3f(-225, 655.0, 0.2);
    glVertex3f(-225, 505.0, 0.2);
    glVertex3f(-265, 505.0, 0.2);
    glVertex3f(-265, 655.0, 0.2);
    //jendela atas kecil
    glVertex3f(-285, 655.0, 0.2);
    glVertex3f(-285, 505.0, 0.2);
    glVertex3f(-325, 505.0, 0.2);
    glVertex3f(-325, 655.0, 0.2);
    glEnd();
    //kotak tambahan kiri
    glBegin(GL_QUADS);//
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-105, 490.0, 0.2);
    glVertex3f(-105, 430.0, 0.2);
    glVertex3f(-145, 430.0, 0.2);
    glVertex3f(-145, 490.0, 0.2);
    //
    glVertex3f(-225, 490.0, 0.2);
    glVertex3f(-225, 430.0, 0.2);
    glVertex3f(-265, 430.0, 0.2);
    glVertex3f(-265, 490.0, 0.2);
    //
    glVertex3f(-285, 490.0, 0.2);
    glVertex3f(-285, 430.0, 0.2);
    glVertex3f(-325, 430.0, 0.2);
    glVertex3f(-325, 490.0, 0.2);
    glEnd();
    //frame jendela bawah kecil
    glBegin(GL_QUADS);//frame jendela kecil bawah
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-100, 420.0, 0.1);
    glVertex3f(-100, 370.0, 0.1);
    glVertex3f(-150, 370.0, 0.1);
    glVertex3f(-150, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(-220, 420.0, 0.1);
    glVertex3f(-220, 370.0, 0.1);
    glVertex3f(-270, 370.0, 0.1);
    glVertex3f(-270, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(-280, 420.0, 0.1);
    glVertex3f(-280, 370.0, 0.1);
    glVertex3f(-330, 370.0, 0.1);
    glVertex3f(-330, 420.0, 0.1);
    glEnd();
    //jendela putih kecil bawah
    glBegin(GL_QUADS);//jedela putih kecil bawah
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-105, 415.0, 0.2);
    glVertex3f(-105, 375.0, 0.2);
    glVertex3f(-145, 375.0, 0.2);
    glVertex3f(-145, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(-225, 415.0, 0.2);
    glVertex3f(-225, 375.0, 0.2);
    glVertex3f(-265, 375.0, 0.2);
    glVertex3f(-265, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(-285, 415.0, 0.2);
    glVertex3f(-285, 375.0, 0.2);
    glVertex3f(-325, 375.0, 0.2);
    glVertex3f(-325, 415.0, 0.2);
    glEnd();
    //frame jendela panjang bawah
    glBegin(GL_QUADS);//frame jendela panjang bawah
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-100, 360.0, 0.1);
    glVertex3f(-100, 200.0, 0.1);
    glVertex3f(-150, 200.0, 0.1);
    glVertex3f(-150, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(-220, 360.0, 0.1);
    glVertex3f(-220, 200.0, 0.1);
    glVertex3f(-270, 200.0, 0.1);
    glVertex3f(-270, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(-280, 360.0, 0.1);
    glVertex3f(-280, 200.0, 0.1);
    glVertex3f(-330, 200.0, 0.1);
    glVertex3f(-330, 360.0, 0.1);
    glEnd();
    //jendela putih panjang bawah
    glBegin(GL_QUADS);//jedela depan panjang bawah
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-105, 355.0, 0.2);
    glVertex3f(-105, 205.0, 0.2);
    glVertex3f(-145, 205.0, 0.2);
    glVertex3f(-145, 355.0, 0.2);
    //jendela atas bawah
    glVertex3f(-225, 355.0, 0.2);
    glVertex3f(-225, 205.0, 0.2);
    glVertex3f(-265, 205.0, 0.2);
    glVertex3f(-265, 355.0, 0.2);
    //jendela atas bawah
    glVertex3f(-285, 355.0, 0.2);
    glVertex3f(-285, 205.0, 0.2);
    glVertex3f(-325, 205.0, 0.2);
    glVertex3f(-325, 355.0, 0.2);
    glEnd();
    //=================================

    //tembok tambahan kiri 2
    glBegin(GL_QUADS);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(-720, 0.0, 0.0);
    glVertex3f(-400, 0.0, 0.0);
    glVertex3f(-400, 800.0, 0.0);
    glVertex3f(-720, 800.0, 0.0);
    glEnd();
    //jendela tambahan kiri
    // frame jendela kecil atas
    glBegin(GL_QUADS);//frame jendela kecil atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-400, 720.0, 0.1);
    glVertex3f(-400, 670.0, 0.1);
    glVertex3f(-450, 670.0, 0.1);
    glVertex3f(-450, 720.0, 0.1);
    //frame jendela kecil atas
    glVertex3f(-520, 720.0, 0.1);
    glVertex3f(-520, 670.0, 0.1);
    glVertex3f(-570, 670.0, 0.1);
    glVertex3f(-570, 720.0, 0.1);
    //frame jendela kecil atas
    glVertex3f(-580, 720.0, 0.1);
    glVertex3f(-580, 670.0, 0.1);
    glVertex3f(-630, 670.0, 0.1);
    glVertex3f(-630, 720.0, 0.1);
    glEnd();
    //jendela kecil atas
    glBegin(GL_QUADS);//jedela depan kecil atas
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-405, 715.0, 0.2);
    glVertex3f(-405, 675.0, 0.2);
    glVertex3f(-445, 675.0, 0.2);
    glVertex3f(-445, 715.0, 0.2);
    //jendela atas kecil
    glVertex3f(-525, 715.0, 0.2);
    glVertex3f(-525, 675.0, 0.2);
    glVertex3f(-565, 675.0, 0.2);
    glVertex3f(-565, 715.0, 0.2);
    //jendela atas kecil
    glVertex3f(-585, 715.0, 0.2);
    glVertex3f(-585, 675.0, 0.2);
    glVertex3f(-625, 675.0, 0.2);
    glVertex3f(-625, 715.0, 0.2);
    glEnd();
    //frame jendela panjang atas
    glBegin(GL_QUADS);//frame jendela panjang atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-400, 660.0, 0.1);
    glVertex3f(-400, 500.0, 0.1);
    glVertex3f(-450, 500.0, 0.1);
    glVertex3f(-450, 660.0, 0.1);
    //frame jendela panjang atas
    glVertex3f(-520, 660.0, 0.1);
    glVertex3f(-520, 500.0, 0.1);
    glVertex3f(-570, 500.0, 0.1);
    glVertex3f(-570, 660.0, 0.1);
    //frame jendela panjang atas
    glVertex3f(-580, 660.0, 0.1);
    glVertex3f(-580, 500.0, 0.1);
    glVertex3f(-630, 500.0, 0.1);
    glVertex3f(-630, 660.0, 0.1);
    glEnd();
    //jendela panjang atas
    glBegin(GL_QUADS);//jedela depan panjang atas
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-405, 655.0, 0.2);
    glVertex3f(-405, 505.0, 0.2);
    glVertex3f(-445, 505.0, 0.2);
    glVertex3f(-445, 655.0, 0.2);
    //jendela atas panjang
    glVertex3f(-525, 655.0, 0.2);
    glVertex3f(-525, 505.0, 0.2);
    glVertex3f(-565, 505.0, 0.2);
    glVertex3f(-565, 655.0, 0.2);
    //jendela atas panjang
    glVertex3f(-585, 655.0, 0.2);
    glVertex3f(-585, 505.0, 0.2);
    glVertex3f(-625, 505.0, 0.2);
    glVertex3f(-625, 655.0, 0.2);
    glEnd();
    //kotak tambahan kiri
    glBegin(GL_QUADS);//
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-405, 490.0, 0.2);
    glVertex3f(-405, 430.0, 0.2);
    glVertex3f(-445, 430.0, 0.2);
    glVertex3f(-445, 490.0, 0.2);
    //
    glVertex3f(-525, 490.0, 0.2);
    glVertex3f(-525, 430.0, 0.2);
    glVertex3f(-565, 430.0, 0.2);
    glVertex3f(-565, 490.0, 0.2);
    //
    glVertex3f(-585, 490.0, 0.2);
    glVertex3f(-585, 430.0, 0.2);
    glVertex3f(-625, 430.0, 0.2);
    glVertex3f(-625, 490.0, 0.2);
    glEnd();
    //frame jendela bawah kecil
    glBegin(GL_QUADS);//frame jendela kecil bawah
    glColor3f(0.43, 0.28, 0);
    /*glVertex3f(-400, 420.0, 0.1);
    glVertex3f(-400, 370.0, 0.1);
    glVertex3f(-450, 370.0, 0.1);
    glVertex3f(-450, 420.0, 0.1);*/
    //frame jendela kecil bawah
    glVertex3f(-520, 420.0, 0.1);
    glVertex3f(-520, 370.0, 0.1);
    glVertex3f(-570, 370.0, 0.1);
    glVertex3f(-570, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(-580, 420.0, 0.1);
    glVertex3f(-580, 370.0, 0.1);
    glVertex3f(-630, 370.0, 0.1);
    glVertex3f(-630, 420.0, 0.1);
    glEnd();
    //jendela putih kecil bawah
    glBegin(GL_QUADS);//jedela putih kecil bawah
    glColor3f(1.86, 0.78, 0.62);
    /*glVertex3f(-405, 415.0, 0.2);
    glVertex3f(-405, 375.0, 0.2);
    glVertex3f(-445, 375.0, 0.2);
    glVertex3f(-445, 415.0, 0.2);*/
    //jedela putih kecil bawah
    glVertex3f(-525, 415.0, 0.2);
    glVertex3f(-525, 375.0, 0.2);
    glVertex3f(-565, 375.0, 0.2);
    glVertex3f(-565, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(-585, 415.0, 0.2);
    glVertex3f(-585, 375.0, 0.2);
    glVertex3f(-625, 375.0, 0.2);
    glVertex3f(-625, 415.0, 0.2);
    glEnd();
    //frame jendela panjang bawah
    glBegin(GL_QUADS);//frame jendela panjang bawah
    glColor3f(0.43, 0.28, 0);
    /*glVertex3f(-400, 360.0, 0.1);
    glVertex3f(-400, 200.0, 0.1);
    glVertex3f(-450, 200.0, 0.1);
    glVertex3f(-450, 360.0, 0.1);*/
    //frame jendela panjang bawah
    glVertex3f(-520, 360.0, 0.1);
    glVertex3f(-520, 200.0, 0.1);
    glVertex3f(-570, 200.0, 0.1);
    glVertex3f(-570, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(-580, 360.0, 0.1);
    glVertex3f(-580, 200.0, 0.1);
    glVertex3f(-630, 200.0, 0.1);
    glVertex3f(-630, 360.0, 0.1);
    glEnd();
    //jendela putih panjang bawah
    glBegin(GL_QUADS);//jedela depan panjang bawah
    glColor3f(1.86, 0.78, 0.62);
    /*glVertex3f(-405, 355.0, 0.2);
    glVertex3f(-405, 205.0, 0.2);
    glVertex3f(-445, 205.0, 0.2);
    glVertex3f(-445, 355.0, 0.2);*/
    //jendela atas bawah
    glVertex3f(-525, 355.0, 0.2);
    glVertex3f(-525, 205.0, 0.2);
    glVertex3f(-565, 205.0, 0.2);
    glVertex3f(-565, 355.0, 0.2);
    //jendela atas bawah
    glVertex3f(-585, 355.0, 0.2);
    glVertex3f(-585, 205.0, 0.2);
    glVertex3f(-625, 205.0, 0.2);
    glVertex3f(-625, 355.0, 0.2);
    glEnd();
    //-=================================
    //tembok tambahan kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(900, 0.0, 0.0);
    glVertex3f(1250, 0.0, 0.0);
    glVertex3f(1250, 800.0, 0.0);
    glVertex3f(900, 800.0, 0.0);
    glEnd();
    //frame jendela kecil atas
    glBegin(GL_QUADS);//frame jendela atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(930, 720.0, 0.1);
    glVertex3f(930, 670.0, 0.1);
    glVertex3f(980, 670.0, 0.1);
    glVertex3f(980, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(1060, 720.0, 0.1);
    glVertex3f(1060, 670.0, 0.1);
    glVertex3f(1110, 670.0, 0.1);
    glVertex3f(1110, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(1120, 720.0, 0.1);
    glVertex3f(1120, 670.0, 0.1);
    glVertex3f(1170, 670.0, 0.1);
    glVertex3f(1170, 720.0, 0.1);
    glEnd();
    //jendela kecil atas
    glBegin(GL_QUADS);//jedela depan kecil atas
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(935, 715.0, 0.2);
    glVertex3f(935, 675.0, 0.2);
    glVertex3f(975, 675.0, 0.2);
    glVertex3f(975, 715.0, 0.2);
    //jendela atas kecil
    glVertex3f(1065, 715.0, 0.2);
    glVertex3f(1065, 675.0, 0.2);
    glVertex3f(1105, 675.0, 0.2);
    glVertex3f(1105, 715.0, 0.2);
    //jendela atas kecil
    glVertex3f(1125, 715.0, 0.2);
    glVertex3f(1125, 675.0, 0.2);
    glVertex3f(1165, 675.0, 0.2);
    glVertex3f(1165, 715.0, 0.2);
    glEnd();
    //frame jendela panjang atas
    glBegin(GL_QUADS);//frame jendela panjang atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(930, 660.0, 0.1);
    glVertex3f(930, 500.0, 0.1);
    glVertex3f(980, 500.0, 0.1);
    glVertex3f(980, 660.0, 0.1);
    //frame jendela panjang atas
    glVertex3f(1060, 660.0, 0.1);
    glVertex3f(1060, 500.0, 0.1);
    glVertex3f(1110, 500.0, 0.1);
    glVertex3f(1110, 660.0, 0.1);
    //frame jendela panjang atas
    glVertex3f(1120, 660.0, 0.1);
    glVertex3f(1120, 500.0, 0.1);
    glVertex3f(1170, 500.0, 0.1);
    glVertex3f(1170, 660.0, 0.1);
    glEnd();
    //jendela panjang atas
    glBegin(GL_QUADS);//jedela depan panjang atas
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(935, 655.0, 0.2);
    glVertex3f(935, 505.0, 0.2);
    glVertex3f(975, 505.0, 0.2);
    glVertex3f(975, 655.0, 0.2);
    //jendela atas panjang
    glVertex3f(1065, 655.0, 0.2);
    glVertex3f(1065, 505.0, 0.2);
    glVertex3f(1105, 505.0, 0.2);
    glVertex3f(1105, 655.0, 0.2);
    //jendela atas kecil
    glVertex3f(1125, 655.0, 0.2);
    glVertex3f(1125, 505.0, 0.2);
    glVertex3f(1165, 505.0, 0.2);
    glVertex3f(1165, 655.0, 0.2);
    glEnd();
    //kotak tambahan kiri
    glBegin(GL_QUADS);//
    glColor3f(0.43, 0.28, 0);
    glVertex3f(935, 490.0, 0.2);
    glVertex3f(935, 430.0, 0.2);
    glVertex3f(975, 430.0, 0.2);
    glVertex3f(975, 490.0, 0.2);
    //
    glVertex3f(1065, 490.0, 0.2);
    glVertex3f(1065, 430.0, 0.2);
    glVertex3f(1105, 430.0, 0.2);
    glVertex3f(1105, 490.0, 0.2);
    //
    glVertex3f(1125, 490.0, 0.2);
    glVertex3f(1125, 430.0, 0.2);
    glVertex3f(1165, 430.0, 0.2);
    glVertex3f(1165, 490.0, 0.2);
    glEnd();
    //frame jendela bawah kecil
    glBegin(GL_QUADS);//frame jendela kecil bawah
    glColor3f(0.43, 0.28, 0);
    glVertex3f(930, 420.0, 0.1);
    glVertex3f(930, 370.0, 0.1);
    glVertex3f(980, 370.0, 0.1);
    glVertex3f(980, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(1060, 420.0, 0.1);
    glVertex3f(1060, 370.0, 0.1);
    glVertex3f(1110, 370.0, 0.1);
    glVertex3f(1110, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(1120, 420.0, 0.1);
    glVertex3f(1120, 370.0, 0.1);
    glVertex3f(1170, 370.0, 0.1);
    glVertex3f(1170, 420.0, 0.1);
    glEnd();
    //jendela putih kecil bawah
    glBegin(GL_QUADS);//jedela putih kecil bawah
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(935, 415.0, 0.2);
    glVertex3f(935, 375.0, 0.2);
    glVertex3f(975, 375.0, 0.2);
    glVertex3f(975, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(1065, 415.0, 0.2);
    glVertex3f(1065, 375.0, 0.2);
    glVertex3f(1105, 375.0, 0.2);
    glVertex3f(1105, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(1125, 415.0, 0.2);
    glVertex3f(1125, 375.0, 0.2);
    glVertex3f(1165, 375.0, 0.2);
    glVertex3f(1165, 415.0, 0.2);
    glEnd();
    //frame jendela panjang bawah
    glBegin(GL_QUADS);//frame jendela panjang bawah
    glColor3f(0.43, 0.28, 0);
    glVertex3f(930, 360.0, 0.1);
    glVertex3f(930, 200.0, 0.1);
    glVertex3f(980, 200.0, 0.1);
    glVertex3f(980, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(1060, 360.0, 0.1);
    glVertex3f(1060, 200.0, 0.1);
    glVertex3f(1110, 200.0, 0.1);
    glVertex3f(1110, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(1120, 360.0, 0.1);
    glVertex3f(1120, 200.0, 0.1);
    glVertex3f(1170, 200.0, 0.1);
    glVertex3f(1170, 360.0, 0.1);
    glEnd();
    //jendela putih panjang bawah
    glBegin(GL_QUADS);//jedela depan panjang bawah
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(935, 355.0, 0.2);
    glVertex3f(935, 205.0, 0.2);
    glVertex3f(975, 205.0, 0.2);
    glVertex3f(975, 355.0, 0.2);
    //jendela atas bawah
    glVertex3f(1065, 355.0, 0.2);
    glVertex3f(1065, 205.0, 0.2);
    glVertex3f(1105, 205.0, 0.2);
    glVertex3f(1105, 355.0, 0.2);
    //jendela atas bawah
    glVertex3f(1125, 355.0, 0.2);
    glVertex3f(1125, 205.0, 0.2);
    glVertex3f(1165, 205.0, 0.2);
    glVertex3f(1165, 355.0, 0.2);
    glEnd();
    //-=================================
    //tembok tambahan kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(900, 0.0, 0.0);
    glVertex3f(1550, 0.0, 0.0);
    glVertex3f(1550, 800.0, 0.0);
    glVertex3f(900, 800.0, 0.0);
    glEnd();
    //frame jendela kecil atas
    glBegin(GL_QUADS);//frame jendela atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(1240, 720.0, 0.1);
    glVertex3f(1240, 670.0, 0.1);
    glVertex3f(1290, 670.0, 0.1);
    glVertex3f(1290, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(1350, 720.0, 0.1);
    glVertex3f(1350, 670.0, 0.1);
    glVertex3f(1400, 670.0, 0.1);
    glVertex3f(1400, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(1410, 720.0, 0.1);
    glVertex3f(1410, 670.0, 0.1);
    glVertex3f(1460, 670.0, 0.1);
    glVertex3f(1460, 720.0, 0.1);
    glEnd();
    //jendela kecil atas
    glBegin(GL_QUADS);//jedela depan kecil atas
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(1245, 715.0, 0.2);
    glVertex3f(1245, 675.0, 0.2);
    glVertex3f(1285, 675.0, 0.2);
    glVertex3f(1285, 715.0, 0.2);
    //jendela atas kecil
    glVertex3f(1355, 715.0, 0.2);
    glVertex3f(1355, 675.0, 0.2);
    glVertex3f(1395, 675.0, 0.2);
    glVertex3f(1395, 715.0, 0.2);
    //jendela atas kecil
    glVertex3f(1415, 715.0, 0.2);
    glVertex3f(1415, 675.0, 0.2);
    glVertex3f(1455, 675.0, 0.2);
    glVertex3f(1455, 715.0, 0.2);
    glEnd();
    //frame jendela panjang atas
    glBegin(GL_QUADS);//frame jendela panjang atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(1240, 660.0, 0.1);
    glVertex3f(1240, 500.0, 0.1);
    glVertex3f(1290, 500.0, 0.1);
    glVertex3f(1290, 660.0, 0.1);
    //frame jendela panjang atas
    glVertex3f(1350, 660.0, 0.1);
    glVertex3f(1350, 500.0, 0.1);
    glVertex3f(1400, 500.0, 0.1);
    glVertex3f(1400, 660.0, 0.1);
    //frame jendela panjang atas
    glVertex3f(1410, 660.0, 0.1);
    glVertex3f(1410, 500.0, 0.1);
    glVertex3f(1460, 500.0, 0.1);
    glVertex3f(1460, 660.0, 0.1);
    glEnd();
    //jendela panjang atas
    glBegin(GL_QUADS);//jedela depan panjang atas
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(1245, 655.0, 0.2);
    glVertex3f(1245, 505.0, 0.2);
    glVertex3f(1285, 505.0, 0.2);
    glVertex3f(1285, 655.0, 0.2);
    //jendela atas panjang
    glVertex3f(1355, 655.0, 0.2);
    glVertex3f(1355, 505.0, 0.2);
    glVertex3f(1395, 505.0, 0.2);
    glVertex3f(1395, 655.0, 0.2);
    //jendela atas kecil
    glVertex3f(1415, 655.0, 0.2);
    glVertex3f(1415, 505.0, 0.2);
    glVertex3f(1455, 505.0, 0.2);
    glVertex3f(1455, 655.0, 0.2);
    glEnd();
    //kotak tambahan kiri
    glBegin(GL_QUADS);//
    glColor3f(0.43, 0.28, 0);
    glVertex3f(1245, 490.0, 0.2);
    glVertex3f(1245, 430.0, 0.2);
    glVertex3f(1285, 430.0, 0.2);
    glVertex3f(1285, 490.0, 0.2);
    //
    glVertex3f(1355, 490.0, 0.2);
    glVertex3f(1355, 430.0, 0.2);
    glVertex3f(1395, 430.0, 0.2);
    glVertex3f(1395, 490.0, 0.2);
    //
    glVertex3f(1415, 490.0, 0.2);
    glVertex3f(1415, 430.0, 0.2);
    glVertex3f(1455, 430.0, 0.2);
    glVertex3f(1455, 490.0, 0.2);
    glEnd();
    //frame jendela bawah kecil
    glBegin(GL_QUADS);//frame jendela kecil bawah
    glColor3f(0.43, 0.28, 0);
    /*glVertex3f(1240, 420.0, 0.1);
    glVertex3f(1240, 370.0, 0.1);
    glVertex3f(1290, 370.0, 0.1);
    glVertex3f(1290, 420.0, 0.1);*/
    //frame jendela kecil bawah
    glVertex3f(1350, 420.0, 0.1);
    glVertex3f(1350, 370.0, 0.1);
    glVertex3f(1400, 370.0, 0.1);
    glVertex3f(1400, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(1410, 420.0, 0.1);
    glVertex3f(1410, 370.0, 0.1);
    glVertex3f(1460, 370.0, 0.1);
    glVertex3f(1460, 420.0, 0.1);
    glEnd();
    //jendela putih kecil bawah
    glBegin(GL_QUADS);//jedela putih kecil bawah
    glColor3f(1.86, 0.78, 0.62);
    /*glVertex3f(1245, 415.0, 0.2);
    glVertex3f(1245, 375.0, 0.2);
    glVertex3f(1285, 375.0, 0.2);
    glVertex3f(1285, 415.0, 0.2);*/
    //jedela putih kecil bawah
    glVertex3f(1355, 415.0, 0.2);
    glVertex3f(1355, 375.0, 0.2);
    glVertex3f(1395, 375.0, 0.2);
    glVertex3f(1395, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(1415, 415.0, 0.2);
    glVertex3f(1415, 375.0, 0.2);
    glVertex3f(1455, 375.0, 0.2);
    glVertex3f(1455, 415.0, 0.2);
    glEnd();
    //frame jendela panjang bawah
    glBegin(GL_QUADS);//frame jendela panjang bawah
    glColor3f(0.43, 0.28, 0);
    /*glVertex3f(1240, 360.0, 0.1);
    glVertex3f(1240, 200.0, 0.1);
    glVertex3f(1290, 200.0, 0.1);
    glVertex3f(1290, 360.0, 0.1);*/
    //frame jendela panjang bawah
    glVertex3f(1350, 360.0, 0.1);
    glVertex3f(1350, 200.0, 0.1);
    glVertex3f(1400, 200.0, 0.1);
    glVertex3f(1400, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(1410, 360.0, 0.1);
    glVertex3f(1410, 200.0, 0.1);
    glVertex3f(1460, 200.0, 0.1);
    glVertex3f(1460, 360.0, 0.1);
    glEnd();
    //jendela putih panjang bawah
    glBegin(GL_QUADS);//jedela depan panjang bawah
    glColor3f(1.86, 0.78, 0.62);
    /*glVertex3f(1245, 355.0, 0.2);
    glVertex3f(1245, 205.0, 0.2);
    glVertex3f(1285, 205.0, 0.2);
    glVertex3f(1285, 355.0, 0.2);*/
    //jendela atas bawah
    glVertex3f(1355, 355.0, 0.2);
    glVertex3f(1355, 205.0, 0.2);
    glVertex3f(1395, 205.0, 0.2);
    glVertex3f(1395, 355.0, 0.2);
    //jendela atas bawah
    glVertex3f(1415, 355.0, 0.2);
    glVertex3f(1415, 205.0, 0.2);
    glVertex3f(1455, 205.0, 0.2);
    glVertex3f(1455, 355.0, 0.2);
    glEnd();
    //pintu kecil kanan
    glBegin(GL_QUADS);//frame pintu kecil kanan
    glColor3f(0.43, 0.28, 0);
    glVertex3f(1210, 50.0, 0.1);
    glVertex3f(1210, 380.0, 0.1);
    glVertex3f(1310, 380.0, 0.1);
    glVertex3f(1310, 50.0, 0.1);
    glEnd();
    glBegin(GL_QUADS);//list pintu
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(1210, 50.0, 0.2);
    glVertex3f(1215, 50.0, 0.2);
    glVertex3f(1215, 385.0, 0.2);
    glVertex3f(1210, 385.0, 0.2);
    //
    glVertex3f(1310, 50.0, 0.2);
    glVertex3f(1315, 50.0, 0.2);
    glVertex3f(1315, 385.0, 0.2);
    glVertex3f(1310, 385.0, 0.2);
    //
    glVertex3f(1215, 385.0, 0.1);
    glVertex3f(1215, 380.0, 0.1);
    glVertex3f(1315, 380.0, 0.1);
    glVertex3f(1215, 385.0, 0.1);
    glEnd();
    //tangga pintu 
    glBegin(GL_QUADS);//tangga pintu
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(1215, 50.0, 0.0);
    glVertex3f(1215, 50.0, 20.0);
    glVertex3f(1315, 50.0, 20.0);
    glVertex3f(1315, 50.0, 0.0);
    //
    glVertex3f(1215, 25.0, 0.0);
    glVertex3f(1215, 25.0, 40.0);
    glVertex3f(1315, 25.0, 40.0);
    glVertex3f(1315, 25.0, 0.0);
    glEnd();
    //tangga
    glBegin(GL_QUADS);//tangga
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(1215, 50.0, 20.2);
    glVertex3f(1215, 0.0, 20.2);
    glVertex3f(1315, 0.0, 20.2);
    glVertex3f(1315, 50.0, 20.2);
    //
    glVertex3f(1215, 25.0, 40.2);
    glVertex3f(1215, 0.0, 40.2);
    glVertex3f(1315, 0.0, 40.2);
    glVertex3f(1315, 25.0, 40.2);
    //
    glVertex3f(1215, 25.0, 20.2);
    glVertex3f(1215, 0.0, 20.2);
    glVertex3f(1215, 0.0, 40.2);
    glVertex3f(1215, 25.0, 40.2);
    //
    glVertex3f(1315, 25.0, 20.2);
    glVertex3f(1315, 0.0, 20.2);
    glVertex3f(1315, 0.0, 40.2);
    glVertex3f(1315, 25.0, 40.2);
    glEnd();
    //pintu kedepan
    glBegin(GL_QUADS);//list pintu
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(1215, 0.0, 0);
    glVertex3f(1215, 0.0, 20);
    glVertex3f(1215, 385.0, 20);
    glVertex3f(1215, 385.0, 0);
    //
    glVertex3f(1315, 0.0, 0);
    glVertex3f(1315, 0.0, 20);
    glVertex3f(1315, 385.0, 20);
    glVertex3f(1315, 385.0, 0);
    //    
    glVertex3f(1215, 385.0, 0);
    glVertex3f(1215, 385.0, 20);
    glVertex3f(1315, 385.0, 20);
    glVertex3f(1315, 385.0, 0);
    glEnd();
    //pintu dalam
    glBegin(GL_QUADS);//pintu dalam
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(1220, 50.0, 0.2);
    glVertex3f(1220, 370.0, 0.2);
    glVertex3f(1300, 370.0, 0.2);
    glVertex3f(1300, 50.0, 0.2);
    glEnd();
    //handle pintu
    glBegin(GL_QUADS);//handle pintu dalam
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1295, 220.0, 0.3);
    glVertex3f(1295, 180.0, 0.3);
    glVertex3f(1290, 180.0, 0.3);
    glVertex3f(1290, 220.0, 0.3);
    glEnd();
    //===================================
    //-------- Atap -----------
     //kiri
    glBegin(GL_TRIANGLES);
    glColor3ub(114, 107, 97);
    glVertex3i(-740, 800, -220);
    glVertex3i(-740, 800, 20);
    glVertex3i(-670, 880, -100);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(114, 107, 97);
    glVertex3i(-740, 800, 20);
    glVertex3i(300, 800, 20);
    glVertex3i(400, 880, -100);
    glVertex3i(-670, 880, -100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(114, 107, 97);
    glVertex3i(400, 880, -100);
    glVertex3i(500, 800, 20);
    glVertex3i(1590, 800, 20);
    glVertex3i(1520, 880, -100);
    glEnd();

    //kanan
    glBegin(GL_TRIANGLES);
    glColor3ub(114, 107, 97);
    glVertex3i(1590, 800, -220);
    glVertex3i(1590, 800, 20);
    glVertex3i(1520, 880, -100);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(114, 107, 97);
    glVertex3i(1590, 800, -220);
    glVertex3i(-740, 800, -220);
    glVertex3i(-670, 880, -100);
    glVertex3i(1520, 880, -100);
    glEnd();

    //Trapesium
    glBegin(GL_QUADS);
    glColor3ub(114, 107, 97);
    glVertex3i(250, 800, 20);
    glVertex3i(250, 800, 60);
    glVertex3i(400, 880, 60);
    glVertex3i(400, 880, -100);
    glEnd();
    //Trapesium2
    glBegin(GL_QUADS);
    glColor3ub(114, 107, 97);
    glVertex3i(550, 800, 20);
    glVertex3i(550, 800, 60);
    glVertex3i(400, 880, 60);
    glVertex3i(400, 880, -100);
    glEnd();

    //isi atap segitiga timbul
    //segitiga kecil
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex3i(250, 800, 60);
    glVertex3i(290, 800, 60);
    glVertex3i(290, 821, 60);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex3i(550, 800, 60);
    glVertex3i(510, 800, 60);
    glVertex3i(510, 821, 60);
    glEnd();

    //trapesium panjang
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3i(250, 800, 60);
    glVertex3i(400, 880, 60);
    glVertex3i(400, 860, 60);
    glVertex3i(280, 800, 60);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3i(550, 800, 60);
    glVertex3i(400, 880, 60);
    glVertex3i(400, 860, 60);
    glVertex3i(520, 800, 60);
    glEnd();

    //====================================
    //jendeladepan
    glBegin(GL_QUADS);
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(275, 500.0, 50.2);
    glVertex3f(325, 500.0, 50.2);
    glVertex3f(325, 650.0, 50.2);
    glVertex3f(275, 650.0, 50.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(525, 500.0, 50.2);
    glVertex3f(475, 500.0, 50.2);
    glVertex3f(475, 650.0, 50.2);
    glVertex3f(525, 650.0, 50.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(350, 500.0, 50.2);
    glVertex3f(450, 500.0, 50.2);
    glVertex3f(450, 650.0, 50.2);
    glVertex3f(350, 650.0, 50.2);
    glEnd();
    //framejendeladepan
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.28, 0);
    glVertex3f(270, 500.0, 50.1);
    glVertex3f(270, 655.0, 50.1);
    glVertex3f(330, 655.0, 50.1);
    glVertex3f(330, 500.0, 50.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.28, 0);
    glVertex3f(530, 500.0, 50.1);
    glVertex3f(530, 655.0, 50.1);
    glVertex3f(470, 655.0, 50.1);
    glVertex3f(470, 500.0, 50.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.28, 0);
    glVertex3f(345, 500.0, 50.1);
    glVertex3f(345, 655.0, 50.1);
    glVertex3f(455, 655.0, 50.1);
    glVertex3f(455, 500.0, 50.1);
    glEnd();
    //frameatasdanjendela
    glBegin(GL_QUADS);
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(275, 670.0, 50.2);
    glVertex3f(325, 670.0, 50.2);
    glVertex3f(325, 705.0, 50.2);
    glVertex3f(275, 705.0, 50.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(525, 670.0, 50.2);
    glVertex3f(475, 670.0, 50.2);
    glVertex3f(475, 705.0, 50.2);
    glVertex3f(525, 705.0, 50.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(350, 670.0, 50.2);
    glVertex3f(450, 670.0, 50.2);
    glVertex3f(450, 705.0, 50.2);
    glVertex3f(350, 705.0, 50.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.28, 0);
    glVertex3f(270, 665.0, 50.1);
    glVertex3f(270, 710.0, 50.1);
    glVertex3f(330, 710.0, 50.1);
    glVertex3f(330, 665.0, 50.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.28, 0);
    glVertex3f(530, 665.0, 50.1);
    glVertex3f(530, 710.0, 50.1);
    glVertex3f(470, 710.0, 50.1);
    glVertex3f(470, 665.0, 50.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.43, 0.28, 0);
    glVertex3f(345, 665.0, 50.1);
    glVertex3f(345, 710.0, 50.1);
    glVertex3f(455, 710.0, 50.1);
    glVertex3f(455, 665.0, 50.1);
    glEnd();
    //ornamenatas
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(370, 800.0, 50.1);
    glVertex3f(370, 850.0, 50.1);
    glVertex3f(430, 850.0, 50.1);
    glVertex3f(430, 800.0, 50.1);
    glEnd();
    glBegin(GL_QUADS);//tembok depan
    //kiri
    glColor3f(0.48, 0.34, 0);
    glVertex3f(-70, 0.0, 0.0);
    glVertex3f(250, 0.0, 0.0);
    glVertex3f(250, 800.0, 0.0);
    glVertex3f(-70, 800.0, 0.0);
    //kanan
    glVertex3f(550, 0.0, 0.0);
    glVertex3f(900, 0.0, 0.0);
    glVertex3f(900, 800.0, 0.0);
    glVertex3f(550, 800.0, 0.0);
    //bagianmaju
    glVertex3f(250, 0.0, 50.0);
    glVertex3f(550, 0.0, 50.0);
    glVertex3f(550, 800.0, 50.0);
    glVertex3f(250, 800.0, 50.0);
    //sampingkiri
    glVertex3f(250, 0.0, 0.0);
    glVertex3f(250, 0.0, 50.0);
    glVertex3f(250, 800.0, 50.0);
    glVertex3f(250, 800.0, 0.0);
    //sampingkanan
    glVertex3f(550, 0.0, 0.0);
    glVertex3f(550, 0.0, 50.0);
    glVertex3f(550, 800.0, 50.0);
    glVertex3f(550, 800.0, 0.0);
    glEnd();
    //segitiga
    glBegin(GL_TRIANGLES);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(250, 800.0, 50.0);
    glVertex3f(550, 800.0, 50.0);
    glVertex3f(400, 870.0, 50.0);
    glEnd();
    //pilar
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-720.0, 0.0, 0.1);
    glVertex3f(-700, 0.0, 0.1);
    glVertex3f(-700, 800.0, 0.1);
    glVertex3f(-720, 800.0, 0.1);
    //pilar
    glVertex3f(1550, 0.0, 0.1);
    glVertex3f(1550, 800.0, 0.1);
    glVertex3f(1530, 800.0, 0.1);
    glVertex3f(1530, 0.0, 0.1);
    //glEnd();
    //list atas
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(-720.0, 800.0, 0.1);
    glVertex3f(1550.0, 800.0, 0.1);
    glVertex3f(1550.0, 760.0, 0.1);
    glVertex3f(-720.0, 760.0, 0.1);
    //list bawah
    glVertex3f(-720.0, 0.0, 0.1);
    glVertex3f(300.0, 0.0, 0.1);
    glVertex3f(300.0, 50.0, 0.1);
    glVertex3f(-720.0, 50.0, 0.1);
    //
    glVertex3f(1550.0, 0.0, 0.1);
    glVertex3f(500.0, 0.0, 0.1);
    glVertex3f(500.0, 50.0, 0.1);
    glVertex3f(1550.0, 50.0, 0.1);
    glEnd();
    glBegin(GL_QUADS);//frame jendela atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-30, 720.0, 0.1);
    glVertex3f(-30, 670.0, 0.1);
    glVertex3f(20, 670.0, 0.1);
    glVertex3f(20, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(30, 720.0, 0.1);
    glVertex3f(30, 670.0, 0.1);
    glVertex3f(80, 670.0, 0.1);
    glVertex3f(80, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(150, 720.0, 0.1);
    glVertex3f(150, 670.0, 0.1);
    glVertex3f(200, 670.0, 0.1);
    glVertex3f(200, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(210, 720.0, 0.1);
    glVertex3f(210, 670.0, 0.1);
    glVertex3f(260, 670.0, 0.1);
    glVertex3f(260, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(570, 720.0, 0.1);
    glVertex3f(570, 670.0, 0.1);
    glVertex3f(620, 670.0, 0.1);
    glVertex3f(620, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(630, 720.0, 0.1);
    glVertex3f(630, 670.0, 0.1);
    glVertex3f(680, 670.0, 0.1);
    glVertex3f(680, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(750, 720.0, 0.1);
    glVertex3f(750, 670.0, 0.1);
    glVertex3f(800, 670.0, 0.1);
    glVertex3f(800, 720.0, 0.1);
    //frame jendela atas
    glVertex3f(810, 720.0, 0.1);
    glVertex3f(810, 670.0, 0.1);
    glVertex3f(860, 670.0, 0.1);
    glVertex3f(860, 720.0, 0.1);
    glEnd();
    glBegin(GL_QUADS);//jedela depan kecil 345 305
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-25, 715.0, 0.2);
    glVertex3f(-25, 675.0, 0.2);
    glVertex3f(15, 675.0, 0.2);
    glVertex3f(15, 715.0, 0.2);
    //jendela atas
    glVertex3f(35, 715.0, 0.2);
    glVertex3f(35, 675.0, 0.2);
    glVertex3f(75, 675.0, 0.2);
    glVertex3f(75, 715.0, 0.2);
    //jendela atas
    glVertex3f(155, 715.0, 0.2);
    glVertex3f(155, 675.0, 0.2);
    glVertex3f(195, 675.0, 0.2);
    glVertex3f(195, 715.0, 0.2);
    //jendela atas
    glVertex3f(215, 715.0, 0.2);
    glVertex3f(215, 675.0, 0.2);
    glVertex3f(255, 675.0, 0.2);
    glVertex3f(255, 715.0, 0.2);
    //jendela atas
    glVertex3f(575, 715.0, 0.2);
    glVertex3f(575, 675.0, 0.2);
    glVertex3f(615, 675.0, 0.2);
    glVertex3f(615, 715.0, 0.2);
    //jendela atas
    glVertex3f(635, 715.0, 0.2);
    glVertex3f(635, 675.0, 0.2);
    glVertex3f(675, 675.0, 0.2);
    glVertex3f(675, 715.0, 0.2);
    //jendela atas
    glVertex3f(755, 715.0, 0.2);
    glVertex3f(755, 675.0, 0.2);
    glVertex3f(795, 675.0, 0.2);
    glVertex3f(795, 715.0, 0.2);
    //jendela atas
    glVertex3f(815, 715.0, 0.2);
    glVertex3f(815, 675.0, 0.2);
    glVertex3f(855, 675.0, 0.2);
    glVertex3f(855, 715.0, 0.2);
    glEnd();
    glBegin(GL_QUADS);//frame jendela panjang atas
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-30, 660.0, 0.1);
    glVertex3f(-30, 500.0, 0.1);
    glVertex3f(20, 500.0, 0.1);
    glVertex3f(20, 660.0, 0.1);
    //frame jendela atas panjang
    glVertex3f(30, 660.0, 0.1);
    glVertex3f(30, 500.0, 0.1);
    glVertex3f(80, 500.0, 0.1);
    glVertex3f(80, 660.0, 0.1);
    //frame jendela atas panjang
    glVertex3f(150, 660.0, 0.1);
    glVertex3f(150, 500.0, 0.1);
    glVertex3f(200, 500.0, 0.1);
    glVertex3f(200, 660.0, 0.1);
    //frame jendela atas panjang
    glVertex3f(210, 660.0, 0.1);
    glVertex3f(210, 500.0, 0.1);
    glVertex3f(260, 500.0, 0.1);
    glVertex3f(260, 660.0, 0.1);
    //frame jendela atas panjang
    glVertex3f(570, 660.0, 0.1);
    glVertex3f(570, 500.0, 0.1);
    glVertex3f(620, 500.0, 0.1);
    glVertex3f(620, 660.0, 0.1);
    //frame jendela atas panjang
    glVertex3f(630, 660.0, 0.1);
    glVertex3f(630, 500.0, 0.1);
    glVertex3f(680, 500.0, 0.1);
    glVertex3f(680, 660.0, 0.1);
    //frame jendela atas panjang
    glVertex3f(750, 660.0, 0.1);
    glVertex3f(750, 500.0, 0.1);
    glVertex3f(800, 500.0, 0.1);
    glVertex3f(800, 660.0, 0.1);
    //frame jendela atas panjang
    glVertex3f(810, 660.0, 0.1);
    glVertex3f(810, 500.0, 0.1);
    glVertex3f(860, 500.0, 0.1);
    glVertex3f(860, 660.0, 0.1);
    glEnd();
    glBegin(GL_QUADS);//jedela depan atas panjang 1
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-25, 655.0, 0.2);
    glVertex3f(-25, 505.0, 0.2);
    glVertex3f(15, 505.0, 0.2);
    glVertex3f(15, 655.0, 0.2);
    //jendela atas
    glVertex3f(35, 655.0, 0.2);
    glVertex3f(35, 505.0, 0.2);
    glVertex3f(75, 505.0, 0.2);
    glVertex3f(75, 655.0, 0.2);
    //jendela atas
    glVertex3f(155, 655.0, 0.2);
    glVertex3f(155, 505.0, 0.2);
    glVertex3f(195, 505.0, 0.2);
    glVertex3f(195, 655.0, 0.2);
    //jendela atas
    glVertex3f(215, 655.0, 0.2);
    glVertex3f(215, 505.0, 0.2);
    glVertex3f(255, 505.0, 0.2);
    glVertex3f(255, 655.0, 0.2);
    //jendela atas
    glVertex3f(575, 655.0, 0.2);
    glVertex3f(575, 505.0, 0.2);
    glVertex3f(615, 505.0, 0.2);
    glVertex3f(615, 655.0, 0.2);
    //jendela atas
    glVertex3f(635, 655.0, 0.2);
    glVertex3f(635, 505.0, 0.2);
    glVertex3f(675, 505.0, 0.2);
    glVertex3f(675, 655.0, 0.2);
    //jendela atas
    glVertex3f(755, 655.0, 0.2);
    glVertex3f(755, 505.0, 0.2);
    glVertex3f(795, 505.0, 0.2);
    glVertex3f(795, 655.0, 0.2);
    //jendela atas
    glVertex3f(815, 655.0, 0.2);
    glVertex3f(815, 505.0, 0.2);
    glVertex3f(855, 505.0, 0.2);
    glVertex3f(855, 655.0, 0.2);
    glEnd();
    glBegin(GL_QUADS);//kotak bawah jendela
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-25, 490.0, 0.1);
    glVertex3f(-25, 430.0, 0.1);
    glVertex3f(15, 430.0, 0.1);
    glVertex3f(15, 490.0, 0.1);
    //
    glVertex3f(35, 490.0, 0.1);
    glVertex3f(35, 430.0, 0.1);
    glVertex3f(75, 430.0, 0.1);
    glVertex3f(75, 490.0, 0.1);
    //
    glVertex3f(155, 490.0, 0.1);
    glVertex3f(155, 430.0, 0.1);
    glVertex3f(195, 430.0, 0.1);
    glVertex3f(195, 490.0, 0.1);
    //
    glVertex3f(215, 490.0, 0.1);
    glVertex3f(215, 430.0, 0.1);
    glVertex3f(255, 430.0, 0.1);
    glVertex3f(255, 490.0, 0.1);
    //
    glVertex3f(575, 490.0, 0.1);
    glVertex3f(575, 430.0, 0.1);
    glVertex3f(615, 430.0, 0.1);
    glVertex3f(615, 490.0, 0.1);
    //
    glVertex3f(635, 490.0, 0.1);
    glVertex3f(635, 430.0, 0.1);
    glVertex3f(675, 430.0, 0.1);
    glVertex3f(675, 490.0, 0.1);
    //
    glVertex3f(755, 490.0, 0.1);
    glVertex3f(755, 430.0, 0.1);
    glVertex3f(795, 430.0, 0.1);
    glVertex3f(795, 490.0, 0.1);
    //
    glVertex3f(815, 490.0, 0.1);
    glVertex3f(815, 430.0, 0.1);
    glVertex3f(855, 430.0, 0.1);
    glVertex3f(855, 490.0, 0.1);
    glEnd();
    //jendela bawah
    //frame jendela kecil bawah
    glBegin(GL_QUADS);//frame jendela kecil bawah
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-30, 420.0, 0.1);
    glVertex3f(-30, 370.0, 0.1);
    glVertex3f(20, 370.0, 0.1);
    glVertex3f(20, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(30, 420.0, 0.1);
    glVertex3f(30, 370.0, 0.1);
    glVertex3f(80, 370.0, 0.1);
    glVertex3f(80, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(150, 420.0, 0.1);
    glVertex3f(150, 370.0, 0.1);
    glVertex3f(200, 370.0, 0.1);
    glVertex3f(200, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(210, 420.0, 0.1);
    glVertex3f(210, 370.0, 0.1);
    glVertex3f(260, 370.0, 0.1);
    glVertex3f(260, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(570, 420.0, 0.1);
    glVertex3f(570, 370.0, 0.1);
    glVertex3f(620, 370.0, 0.1);
    glVertex3f(620, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(630, 420.0, 0.1);
    glVertex3f(630, 370.0, 0.1);
    glVertex3f(680, 370.0, 0.1);
    glVertex3f(680, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(750, 420.0, 0.1);
    glVertex3f(750, 370.0, 0.1);
    glVertex3f(800, 370.0, 0.1);
    glVertex3f(800, 420.0, 0.1);
    //frame jendela kecil bawah
    glVertex3f(810, 420.0, 0.1);
    glVertex3f(810, 370.0, 0.1);
    glVertex3f(860, 370.0, 0.1);
    glVertex3f(860, 420.0, 0.1);
    glEnd();
    //Jendela putih kecil bawah
    glBegin(GL_QUADS);//jedela putih kecil bawah
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-25, 415.0, 0.2);
    glVertex3f(-25, 375.0, 0.2);
    glVertex3f(15, 375.0, 0.2);
    glVertex3f(15, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(35, 415.0, 0.2);
    glVertex3f(35, 375.0, 0.2);
    glVertex3f(75, 375.0, 0.2);
    glVertex3f(75, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(155, 415.0, 0.2);
    glVertex3f(155, 375.0, 0.2);
    glVertex3f(195, 375.0, 0.2);
    glVertex3f(195, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(215, 415.0, 0.2);
    glVertex3f(215, 375.0, 0.2);
    glVertex3f(255, 375.0, 0.2);
    glVertex3f(255, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(575, 415.0, 0.2);
    glVertex3f(575, 375.0, 0.2);
    glVertex3f(615, 375.0, 0.2);
    glVertex3f(615, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(635, 415.0, 0.2);
    glVertex3f(635, 375.0, 0.2);
    glVertex3f(675, 375.0, 0.2);
    glVertex3f(675, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(755, 415.0, 0.2);
    glVertex3f(755, 375.0, 0.2);
    glVertex3f(795, 375.0, 0.2);
    glVertex3f(795, 415.0, 0.2);
    //jedela putih kecil bawah
    glVertex3f(815, 415.0, 0.2);
    glVertex3f(815, 375.0, 0.2);
    glVertex3f(855, 375.0, 0.2);
    glVertex3f(855, 415.0, 0.2);
    glEnd();
    //frame jendela panjang bawah
    glBegin(GL_QUADS);//frame jendela panjang bawah
    glColor3f(0.43, 0.28, 0);
    glVertex3f(-30, 360.0, 0.1);
    glVertex3f(-30, 200.0, 0.1);
    glVertex3f(20, 200.0, 0.1);
    glVertex3f(20, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(30, 360.0, 0.1);
    glVertex3f(30, 200.0, 0.1);
    glVertex3f(80, 200.0, 0.1);
    glVertex3f(80, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(150, 360.0, 0.1);
    glVertex3f(150, 200.0, 0.1);
    glVertex3f(200, 200.0, 0.1);
    glVertex3f(200, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(210, 360.0, 0.1);
    glVertex3f(210, 200.0, 0.1);
    glVertex3f(260, 200.0, 0.1);
    glVertex3f(260, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(570, 360.0, 0.1);
    glVertex3f(570, 200.0, 0.1);
    glVertex3f(620, 200.0, 0.1);
    glVertex3f(620, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(630, 360.0, 0.1);
    glVertex3f(630, 200.0, 0.1);
    glVertex3f(680, 200.0, 0.1);
    glVertex3f(680, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(750, 360.0, 0.1);
    glVertex3f(750, 200.0, 0.1);
    glVertex3f(800, 200.0, 0.1);
    glVertex3f(800, 360.0, 0.1);
    //frame jendela panjang bawah
    glVertex3f(810, 360.0, 0.1);
    glVertex3f(810, 200.0, 0.1);
    glVertex3f(860, 200.0, 0.1);
    glVertex3f(860, 360.0, 0.1);
    glEnd();
    //jendela putih panjang bawah
    glBegin(GL_QUADS);//jendela putih panjang bawah
    glColor3f(1.86, 0.78, 0.62);
    glVertex3f(-25, 355.0, 0.2);
    glVertex3f(-25, 205.0, 0.2);
    glVertex3f(15, 205.0, 0.2);
    glVertex3f(15, 355.0, 0.2);
    //jendela putih panjang bawah
    glVertex3f(35, 355.0, 0.2);
    glVertex3f(35, 205.0, 0.2);
    glVertex3f(75, 205.0, 0.2);
    glVertex3f(75, 355.0, 0.2);
    //jendela putih panjang bawah
    glVertex3f(155, 355.0, 0.2);
    glVertex3f(155, 205.0, 0.2);
    glVertex3f(195, 205.0, 0.2);
    glVertex3f(195, 355.0, 0.2);
    ///jendela putih panjang bawah
    glVertex3f(215, 355.0, 0.2);
    glVertex3f(215, 205.0, 0.2);
    glVertex3f(255, 205.0, 0.2);
    glVertex3f(255, 355.0, 0.2);
    //jendela putih panjang bawah
    glVertex3f(575, 355.0, 0.2);
    glVertex3f(575, 205.0, 0.2);
    glVertex3f(615, 205.0, 0.2);
    glVertex3f(615, 355.0, 0.2);
    //jendela putih panjang bawah
    glVertex3f(635, 355.0, 0.2);
    glVertex3f(635, 205.0, 0.2);
    glVertex3f(675, 205.0, 0.2);
    glVertex3f(675, 355.0, 0.2);
    //jendela putih panjang bawah
    glVertex3f(755, 355.0, 0.2);
    glVertex3f(755, 205.0, 0.2);
    glVertex3f(795, 205.0, 0.2);
    glVertex3f(795, 355.0, 0.2);
    //jendela putih panjang bawah
    glVertex3f(815, 355.0, 0.2);
    glVertex3f(815, 205.0, 0.2);
    glVertex3f(855, 205.0, 0.2);
    glVertex3f(855, 355.0, 0.2);
    glEnd();
    //===================
    /*//out
    //batang
    GLUquadricObj* pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3ub(104, 70, 14);
    glTranslatef(25, -6, 110);
    glRotatef(270, 1, 0, 0);
    gluCylinder(pObj, 14, 8.7, 330, 225, 225);
    glPopMatrix();

    //daun
    glPushMatrix();
    glColor3ub(18, 118, 13);
    glScaled(37, 37, 10);
    glTranslatef(3.1, 10, 11);
    glutSolidDodecahedron();
    glPopMatrix();*/

    //INTERIOR//
//rak buku
    glBegin(GL_POLYGON);//rak buku1 bawah
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 0.0, -130);
    glVertex3f(-170, 0.0, -130);
    glVertex3f(-170, 0.0, -159);
    glVertex3f(-230, 0.0, -159);
    glEnd();

    glBegin(GL_POLYGON);//rak buku1 atas
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 150, -130);
    glVertex3f(-170, 150, -130);
    glVertex3f(-170, 150, -159);
    glVertex3f(-230, 150, -159);
    glEnd();

    glBegin(GL_POLYGON);//rak buku1 kanan
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 150, -130);
    glVertex3f(-230, 0.0, -130);
    glVertex3f(-230, 0.0, -159);
    glVertex3f(-230, 150, -159);
    glEnd();

    glBegin(GL_POLYGON);//rak buku1 kiri
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-170, 150, -130);
    glVertex3f(-170, 0.0, -130);
    glVertex3f(-170, 0.0, -159);
    glVertex3f(-170, 150, -159);
    glEnd();

    glBegin(GL_POLYGON);//rak buku1 belakang
    glColor3f(0.488, 0.388, 0.388);
    glVertex3f(-230, 150, -159);
    glVertex3f(-230, 0.0, -159);
    glVertex3f(-170, 0.0, -159);
    glVertex3f(-170, 150, -159);
    glEnd();

    //rak buku2
    glBegin(GL_POLYGON);//rak buku2 bawah
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 0.0, -130);
    glVertex3f(170, 0.0, -130);
    glVertex3f(170, 0.0, -159);
    glVertex3f(230, 0.0, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 atas
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 150, -130);
    glVertex3f(170, 150, -130);
    glVertex3f(170, 150, -159);
    glVertex3f(230, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 kanan
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 150, -130);
    glVertex3f(230, 0.0, -130);
    glVertex3f(230, 0.0, -159);
    glVertex3f(230, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 kiri
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(170, 150, -130);
    glVertex3f(170, 0.0, -130);
    glVertex3f(170, 0.0, -159);
    glVertex3f(170, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 belakang
    glColor3f(0.488, 0.388, 0.388);
    glVertex3f(230, 150, -159);
    glVertex3f(230, 0.0, -159);
    glVertex3f(170, 0.0, -159);
    glVertex3f(170, 150, -159);
    glEnd();

    //tempat sampah

    glBegin(GL_POLYGON);//tempat sampah bawah
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(150, 0.0, -125);
    glVertex3f(130, 0.0, -125);
    glVertex3f(130, 0.0, -155);
    glVertex3f(150, 0.0, -155);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah kiri
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 40, -125);
    glVertex3f(130, 0.0, -125);
    glVertex3f(130, 0.0, -155);
    glVertex3f(125, 40, -155);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah kanan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(155, 40, -125);
    glVertex3f(150, 0.0, -125);
    glVertex3f(150, 0.0, -155);
    glVertex3f(155, 40, -155);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah belakang
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 40, -155);
    glVertex3f(130, 0.0, -155);
    glVertex3f(150, 0.0, -155);
    glVertex3f(155, 40, -155);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah depan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 40, -125);
    glVertex3f(130, 0.0, -125);
    glVertex3f(150, 0.0, -125);
    glVertex3f(155, 40, -125);
    glEnd();

    //karpet merah
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0, 0);
    glVertex3f(475, 0.1, 30);
    glVertex3f(320, 0.1, 30);
    glVertex3f(320, 0.1, -30);
    glVertex3f(475, 0.1, -30);
    glEnd();

    //Papan Tulis
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-700, 250, -175);
    glVertex3f(-700, 250, -20);
    glVertex3f(-700, 150, -20);
    glVertex3f(-700, 150, -175);
    glEnd();

    //Garis papan tulis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(-700, 250, -175);
    glVertex3f(-700, 250, -20);
    glVertex3f(-700, 150, -20);
    glVertex3f(-700, 150, -175);
    glEnd();

    //penggaris
    glBegin(GL_POLYGON);
    glColor3ub(210, 105, 30);
    glVertex3f(-705, 0, -175);
    glVertex3f(-705, 0, -171);
    glVertex3f(-720, 50, -171);
    glVertex3f(-720, 50, -175);
    glEnd();

    /////////////////////////////////////////////////////////////////////////////////////
    //pintu depan
    //atap
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(275, 450.0, 350.0);
    glVertex3f(275, 450.0, 50.0);
    glVertex3f(525, 450.0, 50.0);
    glVertex3f(525, 450.0, 350.0);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(275, 0.0, 350.0);
    glVertex3f(275, 450.0, 350.0);
    glVertex3f(325, 450.0, 350.0);
    glVertex3f(325, 0.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(275, 0.0, 340.0);
    glVertex3f(275, 450.0, 340.0);
    glVertex3f(325, 450.0, 340.0);
    glVertex3f(325, 0.0, 340.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(475, 0.0, 350.0);
    glVertex3f(475, 450.0, 350.0);
    glVertex3f(525, 450.0, 350.0);
    glVertex3f(525, 0.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(475, 0.0, 340.0);
    glVertex3f(475, 450.0, 340.0);
    glVertex3f(525, 450.0, 340.0);
    glVertex3f(525, 0.0, 340.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(275, 300.0, 350.0);
    glVertex3f(275, 450.0, 350.0);
    glVertex3f(525, 450.0, 350.0);
    glVertex3f(525, 300.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(275, 300.0, 340.0);
    glVertex3f(275, 450.0, 340.0);
    glVertex3f(525, 450.0, 340.0);
    glVertex3f(525, 300.0, 340.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(275, 450.0, 350.1);
    glVertex3f(275, 425.0, 350.1);
    glVertex3f(525, 425.0, 350.1);
    glVertex3f(525, 450.0, 350.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(325, 0.0, 350.0);
    glVertex3f(325, 425.0, 350.0);
    glVertex3f(325, 425.0, 340.0);
    glVertex3f(325, 0.0, 340.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(475, 0.0, 350.0);
    glVertex3f(475, 425.0, 350.0);
    glVertex3f(475, 425.0, 340.0);
    glVertex3f(475, 0.0, 340.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(325, 300.0, 350.0);
    glVertex3f(325, 300.0, 340.0);
    glVertex3f(475, 300.0, 340.0);
    glVertex3f(475, 300.0, 350.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(275, 0.0, 50.0);
    glVertex3f(275, 450.0, 50.0);
    glVertex3f(275, 450.0, 100.0);
    glVertex3f(275, 0.0, 100.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(285, 0.0, 50.0);
    glVertex3f(285, 450.0, 50.0);
    glVertex3f(285, 450.0, 100.0);
    glVertex3f(285, 0.0, 100.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(275, 0.0, 300.0);
    glVertex3f(275, 450.0, 300.0);
    glVertex3f(275, 450.0, 350.0);
    glVertex3f(275, 0.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(285, 0.0, 300.0);
    glVertex3f(285, 450.0, 300.0);
    glVertex3f(285, 450.0, 350.0);
    glVertex3f(285, 0.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(275, 300.0, 50.0);
    glVertex3f(275, 450.0, 50.0);
    glVertex3f(275, 450.0, 350.0);
    glVertex3f(275, 300.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(285, 300.0, 50.0);
    glVertex3f(285, 450.0, 50.0);
    glVertex3f(285, 450.0, 350.0);
    glVertex3f(285, 300.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(274.9, 450.0, 50.0);
    glVertex3f(274.9, 425.0, 50.0);
    glVertex3f(274.9, 425.0, 350.0);
    glVertex3f(274.9, 450.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(285, 0.0, 100.0);
    glVertex3f(285, 425.0, 100.0);
    glVertex3f(275, 425.0, 100.0);
    glVertex3f(275, 0.0, 100.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(285, 0.0, 300.0);
    glVertex3f(285, 425.0, 300.0);
    glVertex3f(275, 425.0, 300.0);
    glVertex3f(275, 0.0, 300.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(275, 300.0, 350.0);
    glVertex3f(275, 300.0, 50.0);
    glVertex3f(285, 300.0, 50.0);
    glVertex3f(285, 300.0, 350.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(525, 0.0, 50.0);
    glVertex3f(525, 450.0, 50.0);
    glVertex3f(525, 450.0, 100.0);
    glVertex3f(525, 0.0, 100.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(515, 0.0, 50.0);
    glVertex3f(515, 450.0, 50.0);
    glVertex3f(515, 450.0, 100.0);
    glVertex3f(515, 0.0, 100.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(525, 0.0, 300.0);
    glVertex3f(525, 450.0, 300.0);
    glVertex3f(525, 450.0, 350.0);
    glVertex3f(525, 0.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(515, 0.0, 300.0);
    glVertex3f(515, 450.0, 300.0);
    glVertex3f(515, 450.0, 350.0);
    glVertex3f(515, 0.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.48, 0.34, 0);
    glVertex3f(525, 300.0, 50.0);
    glVertex3f(525, 450.0, 50.0);
    glVertex3f(525, 450.0, 350.0);
    glVertex3f(525, 300.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(515, 300.0, 50.0);
    glVertex3f(515, 450.0, 50.0);
    glVertex3f(515, 450.0, 350.0);
    glVertex3f(515, 300.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(525.1, 450.0, 50.0);
    glVertex3f(525.1, 425.0, 50.0);
    glVertex3f(525.1, 425.0, 350.0);
    glVertex3f(525.1, 450.0, 350.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(525, 0.0, 100.0);
    glVertex3f(525, 425.0, 100.0);
    glVertex3f(515, 425.0, 100.0);
    glVertex3f(515, 0.0, 100.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(525, 0.0, 300.0);
    glVertex3f(525, 425.0, 300.0);
    glVertex3f(515, 425.0, 300.0);
    glVertex3f(515, 0.0, 300.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(525, 300.0, 350.0);
    glVertex3f(525, 300.0, 50.0);
    glVertex3f(515, 300.0, 50.0);
    glVertex3f(515, 300.0, 350.0);
    glEnd();
    //pinggiran
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(249.9, 0.0, 0.0);
    glVertex3f(249.9, 0.0, 50.0);
    glVertex3f(249.9, 50, 50.0);
    glVertex3f(249.9, 50, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(250, 0.0, 50.1);
    glVertex3f(275, 0.0, 50.1);
    glVertex3f(275, 50, 50.1);
    glVertex3f(250, 50, 50.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(274.9, 0.0, 50.0);
    glVertex3f(274.9, 0.0, 100.0);
    glVertex3f(274.9, 50, 100.0);
    glVertex3f(274.9, 50, 50.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(274.9, 0.0, 300.0);
    glVertex3f(274.9, 0.0, 350.0);
    glVertex3f(274.9, 50, 350.0);
    glVertex3f(274.9, 50, 300.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(550.1, 0.0, 0.0);
    glVertex3f(550.1, 0.0, 50.0);
    glVertex3f(550.1, 50, 50.0);
    glVertex3f(550.1, 50, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(550, 0.0, 50.1);
    glVertex3f(525, 0.0, 50.1);
    glVertex3f(525, 50, 50.1);
    glVertex3f(550, 50, 50.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(525.1, 0.0, 50.0);
    glVertex3f(525.1, 0.0, 100.0);
    glVertex3f(525.1, 50, 100.0);
    glVertex3f(525.1, 50, 50.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(525.1, 0.0, 300.0);
    glVertex3f(525.1, 0.0, 350.0);
    glVertex3f(525.1, 50, 350.0);
    glVertex3f(525.1, 50, 300.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(525, 0.0, 350.1);
    glVertex3f(475, 0.0, 350.1);
    glVertex3f(475, 50, 350.1);
    glVertex3f(525, 50, 350.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(325, 0.0, 350.1);
    glVertex3f(275, 0.0, 350.1);
    glVertex3f(275, 50, 350.1);
    glVertex3f(325, 50, 350.1);
    glEnd();
    //ornamen
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(325, 380.0, 350.1);
    glVertex3f(300, 380.0, 350.1);
    glVertex3f(300, 355, 350.1);
    glVertex3f(325, 355, 350.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.51, 0.24);
    glVertex3f(500, 380.0, 350.1);
    glVertex3f(475, 380.0, 350.1);
    glVertex3f(475, 355, 350.1);
    glVertex3f(500, 355, 350.1);
    glEnd();
    //warnadalam
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.3);
    glVertex3f(275, 300.0, 50.1);
    glVertex3f(275, 450.0, 50.1);
    glVertex3f(525, 450.0, 50.1);
    glVertex3f(525, 300.0, 50.1);
    glEnd();
    ////////////////////////////////////////////////////////////////
    //jalan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.6, 0.2);
    glVertex3f(275, 0.1, 50.0);
    glVertex3f(525, 0.1, 50.0);
    glVertex3f(525, 0.1, 350.0);
    glVertex3f(275, 0.1, 350.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.6, 0.2);
    glVertex3f(475, 0.1, 350.0);
    glVertex3f(325, 0.1, 350.0);
    glVertex3f(325, 0.1, 500.0);
    glVertex3f(475, 0.1, 500.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.6, 0.2);
    glVertex3f(-900, 0.1, 100.0);
    glVertex3f(275, 0.1, 100.0);
    glVertex3f(275, 0.1, 300.0);
    glVertex3f(-900, 0.1, 300.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.6, 0.2);
    glVertex3f(1800, 0.1, 100.0);
    glVertex3f(525, 0.1, 100.0);
    glVertex3f(525, 0.1, 300.0);
    glVertex3f(1800, 0.1, 300.0);
    glEnd();
    //pintu
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(280, 300.0, 50.1);
    glVertex3f(280, 50.0, 50.1);
    glVertex3f(400, 50.0, 50.1);
    glVertex3f(400, 300.0, 50.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(400, 300.0, 50.1);
    glVertex3f(400, 50.0, 50.1);
    glVertex3f(520, 50.0, 50.1);
    glVertex3f(520, 300.0, 50.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(390, 175.0, 50.2);
    glVertex3f(390, 150.0, 50.2);
    glVertex3f(400, 150.0, 50.2);
    glVertex3f(400, 175.0, 50.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(405, 175.0, 50.2);
    glVertex3f(405, 150.0, 50.2);
    glVertex3f(415, 150.0, 50.2);
    glVertex3f(415, 175.0, 50.2);
    glEnd();

    //tangga
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(275, 50.0, 75.0);
    glVertex3f(275, 50.0, 50.0);
    glVertex3f(525, 50.0, 50.0);
    glVertex3f(525, 50.0, 75.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(275, 25.0, 75.0);
    glVertex3f(275, 25.0, 100.0);
    glVertex3f(525, 25.0, 100.0);
    glVertex3f(525, 25.0, 75.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(275, 50.0, 75.0);
    glVertex3f(275, 25.0, 75.0);
    glVertex3f(525, 25.0, 75.0);
    glVertex3f(525, 50.0, 75.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(285, 0.0, 100.0);
    glVertex3f(285, 25.0, 100.0);
    glVertex3f(515, 25.0, 100.0);
    glVertex3f(515, 0.0, 100.0);
    glEnd();
    //////////////////////////////////////////////////////////////////////////
    //lampu
    //batang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 300.0, 350);
    glVertex3f(100, 0.0, 350);
    glVertex3f(110, 0.0, 350);
    glVertex3f(110, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 300.0, 340);
    glVertex3f(100, 0.0, 340);
    glVertex3f(110, 0.0, 340);
    glVertex3f(110, 300.0, 340);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 300.0, 340);
    glVertex3f(100, 0.0, 340);
    glVertex3f(100, 0.0, 350);
    glVertex3f(100, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(110, 300.0, 340);
    glVertex3f(110, 0.0, 340);
    glVertex3f(110, 0.0, 350);
    glVertex3f(110, 300.0, 350);
    glEnd();
    //bengkok
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 325.0, 370);
    glVertex3f(100, 300.0, 340);
    glVertex3f(110, 300.0, 340);
    glVertex3f(110, 325.0, 370);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 325.0, 380);
    glVertex3f(100, 300.0, 350);
    glVertex3f(110, 300.0, 350);
    glVertex3f(110, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 325.0, 370);
    glVertex3f(100, 300.0, 340);
    glVertex3f(100, 300.0, 350);
    glVertex3f(100, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(110, 325.0, 370);
    glVertex3f(110, 300.0, 340);
    glVertex3f(110, 300.0, 350);
    glVertex3f(110, 325.0, 380);
    glEnd();
    //bengkok2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(110, 325.0, 370);
    glVertex3f(110, 325.0, 380);
    glVertex3f(85, 350.0, 380);
    glVertex3f(85, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 325.0, 370);
    glVertex3f(100, 325.0, 380);
    glVertex3f(75, 350.0, 380);
    glVertex3f(75, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 325.0, 370);
    glVertex3f(110, 325.0, 370);
    glVertex3f(85, 350.0, 370);
    glVertex3f(75, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 325.0, 380);
    glVertex3f(110, 325.0, 380);
    glVertex3f(85, 350.0, 380);
    glVertex3f(75, 350.0, 380);
    glEnd();
    //lurus
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(75, 360.0, 380);
    glVertex3f(75, 350.0, 380);
    glVertex3f(85, 350.0, 380);
    glVertex3f(85, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(75, 360.0, 380);
    glVertex3f(75, 360.0, 340);
    glVertex3f(85, 360.0, 340);
    glVertex3f(85, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(75, 350.0, 380);
    glVertex3f(75, 350.0, 340);
    glVertex3f(85, 350.0, 340);
    glVertex3f(85, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(75, 350.0, 340);
    glVertex3f(75, 360.0, 340);
    glVertex3f(75, 360.0, 380);
    glVertex3f(75, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(85, 350.0, 340);
    glVertex3f(85, 360.0, 340);
    glVertex3f(85, 360.0, 380);
    glVertex3f(85, 350.0, 380);
    glEnd();
    //bohlam
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65, 360.0, 310);
    glVertex3f(65, 360.0, 340);
    glVertex3f(95, 360.0, 340);
    glVertex3f(95, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65, 360.0, 340);
    glVertex3f(65, 350.0, 340);
    glVertex3f(95, 350.0, 340);
    glVertex3f(95, 360.0, 340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65, 360.0, 310);
    glVertex3f(65, 350.0, 310);
    glVertex3f(95, 350.0, 310);
    glVertex3f(95, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(65, 360.0, 340);
    glVertex3f(65, 350.0, 340);
    glVertex3f(65, 350.0, 310);
    glVertex3f(65, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95, 360.0, 340);
    glVertex3f(95, 350.0, 340);
    glVertex3f(95, 350.0, 310);
    glVertex3f(95, 360.0, 310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(65, 345.0, 310);
    glVertex3f(65, 345.0, 340);
    glVertex3f(95, 345.0, 340);
    glVertex3f(95, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(65, 345.0, 340);
    glVertex3f(65, 350.0, 340);
    glVertex3f(65, 350.0, 310);
    glVertex3f(65, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(95, 345.0, 340);
    glVertex3f(95, 350.0, 340);
    glVertex3f(95, 350.0, 310);
    glVertex3f(95, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(65, 345.0, 310);
    glVertex3f(65, 350.0, 310);
    glVertex3f(95, 350.0, 310);
    glVertex3f(95, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(65, 345.0, 340);
    glVertex3f(65, 350.0, 340);
    glVertex3f(95, 350.0, 340);
    glVertex3f(95, 345.0, 340);
    glEnd();

    //lampu2
    //batang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 300.0, 350);
    glVertex3f(700, 0.0, 350);
    glVertex3f(710, 0.0, 350);
    glVertex3f(710, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 300.0, 340);
    glVertex3f(700, 0.0, 340);
    glVertex3f(710, 0.0, 340);
    glVertex3f(710, 300.0, 340);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 300.0, 340);
    glVertex3f(700, 0.0, 340);
    glVertex3f(700, 0.0, 350);
    glVertex3f(700, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(710, 300.0, 340);
    glVertex3f(710, 0.0, 340);
    glVertex3f(710, 0.0, 350);
    glVertex3f(710, 300.0, 350);
    glEnd();
    //bengkok
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 325.0, 370);
    glVertex3f(700, 300.0, 340);
    glVertex3f(710, 300.0, 340);
    glVertex3f(710, 325.0, 370);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 325.0, 380);
    glVertex3f(700, 300.0, 350);
    glVertex3f(710, 300.0, 350);
    glVertex3f(710, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 325.0, 370);
    glVertex3f(700, 300.0, 340);
    glVertex3f(700, 300.0, 350);
    glVertex3f(700, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(710, 325.0, 370);
    glVertex3f(710, 300.0, 340);
    glVertex3f(710, 300.0, 350);
    glVertex3f(710, 325.0, 380);
    glEnd();
    //bengkok2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(710, 325.0, 370);
    glVertex3f(710, 325.0, 380);
    glVertex3f(685, 350.0, 380);
    glVertex3f(685, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 325.0, 370);
    glVertex3f(700, 325.0, 380);
    glVertex3f(675, 350.0, 380);
    glVertex3f(675, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 325.0, 370);
    glVertex3f(710, 325.0, 370);
    glVertex3f(685, 350.0, 370);
    glVertex3f(675, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(700, 325.0, 380);
    glVertex3f(710, 325.0, 380);
    glVertex3f(685, 350.0, 380);
    glVertex3f(675, 350.0, 380);
    glEnd();
    //lurus
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(675, 360.0, 380);
    glVertex3f(675, 350.0, 380);
    glVertex3f(685, 350.0, 380);
    glVertex3f(685, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(675, 360.0, 380);
    glVertex3f(675, 360.0, 340);
    glVertex3f(685, 360.0, 340);
    glVertex3f(685, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(675, 350.0, 380);
    glVertex3f(675, 350.0, 340);
    glVertex3f(685, 350.0, 340);
    glVertex3f(685, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(675, 350.0, 340);
    glVertex3f(675, 360.0, 340);
    glVertex3f(675, 360.0, 380);
    glVertex3f(675, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(685, 350.0, 340);
    glVertex3f(685, 360.0, 340);
    glVertex3f(685, 360.0, 380);
    glVertex3f(685, 350.0, 380);
    glEnd();
    //bohlam
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(665, 360.0, 310);
    glVertex3f(665, 360.0, 340);
    glVertex3f(695, 360.0, 340);
    glVertex3f(695, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(665, 360.0, 340);
    glVertex3f(665, 350.0, 340);
    glVertex3f(695, 350.0, 340);
    glVertex3f(695, 360.0, 340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(665, 360.0, 310);
    glVertex3f(665, 350.0, 310);
    glVertex3f(695, 350.0, 310);
    glVertex3f(695, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(665, 360.0, 340);
    glVertex3f(665, 350.0, 340);
    glVertex3f(665, 350.0, 310);
    glVertex3f(665, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(695, 360.0, 340);
    glVertex3f(695, 350.0, 340);
    glVertex3f(695, 350.0, 310);
    glVertex3f(695, 360.0, 310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(665, 345.0, 310);
    glVertex3f(665, 345.0, 340);
    glVertex3f(695, 345.0, 340);
    glVertex3f(695, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(665, 345.0, 340);
    glVertex3f(665, 350.0, 340);
    glVertex3f(665, 350.0, 310);
    glVertex3f(665, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(695, 345.0, 340);
    glVertex3f(695, 350.0, 340);
    glVertex3f(695, 350.0, 310);
    glVertex3f(695, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(665, 345.0, 310);
    glVertex3f(665, 350.0, 310);
    glVertex3f(695, 350.0, 310);
    glVertex3f(695, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(665, 345.0, 340);
    glVertex3f(665, 350.0, 340);
    glVertex3f(695, 350.0, 340);
    glVertex3f(695, 345.0, 340);
    glEnd();

    //lampu3
    //batang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 300.0, 350);
    glVertex3f(1100, 0.0, 350);
    glVertex3f(1110, 0.0, 350);
    glVertex3f(1110, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 300.0, 340);
    glVertex3f(1100, 0.0, 340);
    glVertex3f(1110, 0.0, 340);
    glVertex3f(1110, 300.0, 340);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 300.0, 340);
    glVertex3f(1100, 0.0, 340);
    glVertex3f(1100, 0.0, 350);
    glVertex3f(1100, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1110, 300.0, 340);
    glVertex3f(1110, 0.0, 340);
    glVertex3f(1110, 0.0, 350);
    glVertex3f(1110, 300.0, 350);
    glEnd();
    //bengkok
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 325.0, 370);
    glVertex3f(1100, 300.0, 340);
    glVertex3f(1110, 300.0, 340);
    glVertex3f(1110, 325.0, 370);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 325.0, 380);
    glVertex3f(1100, 300.0, 350);
    glVertex3f(1110, 300.0, 350);
    glVertex3f(1110, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 325.0, 370);
    glVertex3f(1100, 300.0, 340);
    glVertex3f(1100, 300.0, 350);
    glVertex3f(1100, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1110, 325.0, 370);
    glVertex3f(1110, 300.0, 340);
    glVertex3f(1110, 300.0, 350);
    glVertex3f(1110, 325.0, 380);
    glEnd();
    //bengkok2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1110, 325.0, 370);
    glVertex3f(1110, 325.0, 380);
    glVertex3f(1085, 350.0, 380);
    glVertex3f(1085, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 325.0, 370);
    glVertex3f(1100, 325.0, 380);
    glVertex3f(1075, 350.0, 380);
    glVertex3f(1075, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 325.0, 370);
    glVertex3f(1110, 325.0, 370);
    glVertex3f(1085, 350.0, 370);
    glVertex3f(1075, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1100, 325.0, 380);
    glVertex3f(1110, 325.0, 380);
    glVertex3f(1085, 350.0, 380);
    glVertex3f(1075, 350.0, 380);
    glEnd();
    //lurus
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1075, 360.0, 380);
    glVertex3f(1075, 350.0, 380);
    glVertex3f(1085, 350.0, 380);
    glVertex3f(1085, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1075, 360.0, 380);
    glVertex3f(1075, 360.0, 340);
    glVertex3f(1085, 360.0, 340);
    glVertex3f(1085, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1075, 350.0, 380);
    glVertex3f(1075, 350.0, 340);
    glVertex3f(1085, 350.0, 340);
    glVertex3f(1085, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1075, 350.0, 340);
    glVertex3f(1075, 360.0, 340);
    glVertex3f(1075, 360.0, 380);
    glVertex3f(1075, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1085, 350.0, 340);
    glVertex3f(1085, 360.0, 340);
    glVertex3f(1085, 360.0, 380);
    glVertex3f(1085, 350.0, 380);
    glEnd();
    //bohlam
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1065, 360.0, 310);
    glVertex3f(1065, 360.0, 340);
    glVertex3f(1095, 360.0, 340);
    glVertex3f(1095, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1065, 360.0, 340);
    glVertex3f(1065, 350.0, 340);
    glVertex3f(1095, 350.0, 340);
    glVertex3f(1095, 360.0, 340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1065, 360.0, 310);
    glVertex3f(1065, 350.0, 310);
    glVertex3f(1095, 350.0, 310);
    glVertex3f(1095, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1065, 360.0, 340);
    glVertex3f(1065, 350.0, 340);
    glVertex3f(1065, 350.0, 310);
    glVertex3f(1065, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1095, 360.0, 340);
    glVertex3f(1095, 350.0, 340);
    glVertex3f(1095, 350.0, 310);
    glVertex3f(1095, 360.0, 310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1065, 345.0, 310);
    glVertex3f(1065, 345.0, 340);
    glVertex3f(1095, 345.0, 340);
    glVertex3f(1095, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1065, 345.0, 340);
    glVertex3f(1065, 350.0, 340);
    glVertex3f(1065, 350.0, 310);
    glVertex3f(1065, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1095, 345.0, 340);
    glVertex3f(1095, 350.0, 340);
    glVertex3f(1095, 350.0, 310);
    glVertex3f(1095, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1065, 345.0, 310);
    glVertex3f(1065, 350.0, 310);
    glVertex3f(1095, 350.0, 310);
    glVertex3f(1095, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1065, 345.0, 340);
    glVertex3f(1065, 350.0, 340);
    glVertex3f(1095, 350.0, 340);
    glVertex3f(1095, 345.0, 340);
    glEnd();

    //lampu4
    //batang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 300.0, 350);
    glVertex3f(1500, 0.0, 350);
    glVertex3f(1510, 0.0, 350);
    glVertex3f(1510, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 300.0, 340);
    glVertex3f(1500, 0.0, 340);
    glVertex3f(1510, 0.0, 340);
    glVertex3f(1510, 300.0, 340);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 300.0, 340);
    glVertex3f(1500, 0.0, 340);
    glVertex3f(1500, 0.0, 350);
    glVertex3f(1500, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1510, 300.0, 340);
    glVertex3f(1510, 0.0, 340);
    glVertex3f(1510, 0.0, 350);
    glVertex3f(1510, 300.0, 350);
    glEnd();
    //bengkok
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 325.0, 370);
    glVertex3f(1500, 300.0, 340);
    glVertex3f(1510, 300.0, 340);
    glVertex3f(1510, 325.0, 370);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 325.0, 380);
    glVertex3f(1500, 300.0, 350);
    glVertex3f(1510, 300.0, 350);
    glVertex3f(1510, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 325.0, 370);
    glVertex3f(1500, 300.0, 340);
    glVertex3f(1500, 300.0, 350);
    glVertex3f(1500, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1510, 325.0, 370);
    glVertex3f(1510, 300.0, 340);
    glVertex3f(1510, 300.0, 350);
    glVertex3f(1510, 325.0, 380);
    glEnd();
    //bengkok2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1510, 325.0, 370);
    glVertex3f(1510, 325.0, 380);
    glVertex3f(1485, 350.0, 380);
    glVertex3f(1485, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 325.0, 370);
    glVertex3f(1500, 325.0, 380);
    glVertex3f(1475, 350.0, 380);
    glVertex3f(1475, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 325.0, 370);
    glVertex3f(1510, 325.0, 370);
    glVertex3f(1485, 350.0, 370);
    glVertex3f(1475, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1500, 325.0, 380);
    glVertex3f(1510, 325.0, 380);
    glVertex3f(1485, 350.0, 380);
    glVertex3f(1475, 350.0, 380);
    glEnd();
    //lurus
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1475, 360.0, 380);
    glVertex3f(1475, 350.0, 380);
    glVertex3f(1485, 350.0, 380);
    glVertex3f(1485, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1475, 360.0, 380);
    glVertex3f(1475, 360.0, 340);
    glVertex3f(1485, 360.0, 340);
    glVertex3f(1485, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1475, 350.0, 380);
    glVertex3f(1475, 350.0, 340);
    glVertex3f(1485, 350.0, 340);
    glVertex3f(1485, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1475, 350.0, 340);
    glVertex3f(1475, 360.0, 340);
    glVertex3f(1475, 360.0, 380);
    glVertex3f(1475, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1485, 350.0, 340);
    glVertex3f(1485, 360.0, 340);
    glVertex3f(1485, 360.0, 380);
    glVertex3f(1485, 350.0, 380);
    glEnd();
    //bohlam
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1465, 360.0, 310);
    glVertex3f(1465, 360.0, 340);
    glVertex3f(1495, 360.0, 340);
    glVertex3f(1495, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1465, 360.0, 340);
    glVertex3f(1465, 350.0, 340);
    glVertex3f(1495, 350.0, 340);
    glVertex3f(1495, 360.0, 340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1465, 360.0, 310);
    glVertex3f(1465, 350.0, 310);
    glVertex3f(1495, 350.0, 310);
    glVertex3f(1495, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1465, 360.0, 340);
    glVertex3f(1465, 350.0, 340);
    glVertex3f(1465, 350.0, 310);
    glVertex3f(1465, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1495, 360.0, 340);
    glVertex3f(1495, 350.0, 340);
    glVertex3f(1495, 350.0, 310);
    glVertex3f(1495, 360.0, 310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1465, 345.0, 310);
    glVertex3f(1465, 345.0, 340);
    glVertex3f(1495, 345.0, 340);
    glVertex3f(1495, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1465, 345.0, 340);
    glVertex3f(1465, 350.0, 340);
    glVertex3f(1465, 350.0, 310);
    glVertex3f(1465, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1495, 345.0, 340);
    glVertex3f(1495, 350.0, 340);
    glVertex3f(1495, 350.0, 310);
    glVertex3f(1495, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1465, 345.0, 310);
    glVertex3f(1465, 350.0, 310);
    glVertex3f(1495, 350.0, 310);
    glVertex3f(1495, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1465, 345.0, 340);
    glVertex3f(1465, 350.0, 340);
    glVertex3f(1495, 350.0, 340);
    glVertex3f(1495, 345.0, 340);
    glEnd();

    //tempat sampah
    glBegin(GL_POLYGON);//tempat sampah bawah
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(150, 0.2, 55);
    glVertex3f(130, 0.2, 55);
    glVertex3f(130, 0.2, 85);
    glVertex3f(150, 0.2, 85);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah kiri
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 40, 55);
    glVertex3f(130, 0.0, 55);
    glVertex3f(130, 0.0, 85);
    glVertex3f(125, 40, 85);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah kanan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(155, 40, 55);
    glVertex3f(150, 0.0, 55);
    glVertex3f(150, 0.0, 85);
    glVertex3f(155, 40, 85);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah belakang
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 40, 85);
    glVertex3f(130, 0.0, 85);
    glVertex3f(150, 0.0, 85);
    glVertex3f(155, 40, 85);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah depan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 40, 55);
    glVertex3f(130, 0.0, 55);
    glVertex3f(150, 0.0, 55);
    glVertex3f(155, 40, 55);
    glEnd();

    //lampu5
    //batang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 300.0, 350);
    glVertex3f(-300, 0.0, 350);
    glVertex3f(-310, 0.0, 350);
    glVertex3f(-310, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 300.0, 340);
    glVertex3f(-300, 0.0, 340);
    glVertex3f(-310, 0.0, 340);
    glVertex3f(-310, 300.0, 340);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 300.0, 340);
    glVertex3f(-300, 0.0, 340);
    glVertex3f(-300, 0.0, 350);
    glVertex3f(-300, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-310, 300.0, 340);
    glVertex3f(-310, 0.0, 340);
    glVertex3f(-310, 0.0, 350);
    glVertex3f(-310, 300.0, 350);
    glEnd();
    //bengkok
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 325.0, 370);
    glVertex3f(-300, 300.0, 340);
    glVertex3f(-310, 300.0, 340);
    glVertex3f(-310, 325.0, 370);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 325.0, 380);
    glVertex3f(-300, 300.0, 350);
    glVertex3f(-310, 300.0, 350);
    glVertex3f(-310, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 325.0, 370);
    glVertex3f(-300, 300.0, 340);
    glVertex3f(-300, 300.0, 350);
    glVertex3f(-300, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-310, 325.0, 370);
    glVertex3f(-310, 300.0, 340);
    glVertex3f(-310, 300.0, 350);
    glVertex3f(-310, 325.0, 380);
    glEnd();
    //bengkok2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-310, 325.0, 370);
    glVertex3f(-310, 325.0, 380);
    glVertex3f(-335, 350.0, 380);
    glVertex3f(-335, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 325.0, 370);
    glVertex3f(-300, 325.0, 380);
    glVertex3f(-325, 350.0, 380);
    glVertex3f(-325, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 325.0, 370);
    glVertex3f(-310, 325.0, 370);
    glVertex3f(-335, 350.0, 370);
    glVertex3f(-325, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-300, 325.0, 380);
    glVertex3f(-310, 325.0, 380);
    glVertex3f(-335, 350.0, 380);
    glVertex3f(-325, 350.0, 380);
    glEnd();
    //lurus
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-325, 360.0, 380);
    glVertex3f(-325, 350.0, 380);
    glVertex3f(-335, 350.0, 380);
    glVertex3f(-335, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-325, 360.0, 380);
    glVertex3f(-325, 360.0, 340);
    glVertex3f(-335, 360.0, 340);
    glVertex3f(-335, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-325, 350.0, 380);
    glVertex3f(-325, 350.0, 340);
    glVertex3f(-335, 350.0, 340);
    glVertex3f(-335, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-325, 350.0, 340);
    glVertex3f(-325, 360.0, 340);
    glVertex3f(-325, 360.0, 380);
    glVertex3f(-325, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-335, 350.0, 340);
    glVertex3f(-335, 360.0, 340);
    glVertex3f(-335, 360.0, 380);
    glVertex3f(-335, 350.0, 380);
    glEnd();
    //bohlam
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-315, 360.0, 310);
    glVertex3f(-315, 360.0, 340);
    glVertex3f(-345, 360.0, 340);
    glVertex3f(-345, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-315, 360.0, 340);
    glVertex3f(-315, 350.0, 340);
    glVertex3f(-345, 350.0, 340);
    glVertex3f(-345, 360.0, 340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-315, 360.0, 310);
    glVertex3f(-315, 350.0, 310);
    glVertex3f(-345, 350.0, 310);
    glVertex3f(-345, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-315, 360.0, 340);
    glVertex3f(-315, 350.0, 340);
    glVertex3f(-315, 350.0, 310);
    glVertex3f(-315, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-345, 360.0, 340);
    glVertex3f(-345, 350.0, 340);
    glVertex3f(-345, 350.0, 310);
    glVertex3f(-345, 360.0, 310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-315, 345.0, 310);
    glVertex3f(-315, 345.0, 340);
    glVertex3f(-345, 345.0, 340);
    glVertex3f(-345, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-315, 345.0, 340);
    glVertex3f(-315, 350.0, 340);
    glVertex3f(-315, 350.0, 310);
    glVertex3f(-315, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-345, 345.0, 340);
    glVertex3f(-345, 350.0, 340);
    glVertex3f(-345, 350.0, 310);
    glVertex3f(-345, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-315, 345.0, 310);
    glVertex3f(-315, 350.0, 310);
    glVertex3f(-345, 350.0, 310);
    glVertex3f(-345, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-315, 345.0, 340);
    glVertex3f(-315, 350.0, 340);
    glVertex3f(-345, 350.0, 340);
    glVertex3f(-345, 345.0, 340);
    glEnd();
    //lampu5
    //batang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 300.0, 350);
    glVertex3f(-700, 0.0, 350);
    glVertex3f(-710, 0.0, 350);
    glVertex3f(-710, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 300.0, 340);
    glVertex3f(-700, 0.0, 340);
    glVertex3f(-710, 0.0, 340);
    glVertex3f(-710, 300.0, 340);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 300.0, 340);
    glVertex3f(-700, 0.0, 340);
    glVertex3f(-700, 0.0, 350);
    glVertex3f(-700, 300.0, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-710, 300.0, 340);
    glVertex3f(-710, 0.0, 340);
    glVertex3f(-710, 0.0, 350);
    glVertex3f(-710, 300.0, 350);
    glEnd();
    //bengkok
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 325.0, 370);
    glVertex3f(-700, 300.0, 340);
    glVertex3f(-710, 300.0, 340);
    glVertex3f(-710, 325.0, 370);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 325.0, 380);
    glVertex3f(-700, 300.0, 350);
    glVertex3f(-710, 300.0, 350);
    glVertex3f(-710, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 325.0, 370);
    glVertex3f(-700, 300.0, 340);
    glVertex3f(-700, 300.0, 350);
    glVertex3f(-700, 325.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-710, 325.0, 370);
    glVertex3f(-710, 300.0, 340);
    glVertex3f(-710, 300.0, 350);
    glVertex3f(-710, 325.0, 380);
    glEnd();
    //bengkok2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-710, 325.0, 370);
    glVertex3f(-710, 325.0, 380);
    glVertex3f(-735, 350.0, 380);
    glVertex3f(-735, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 325.0, 370);
    glVertex3f(-700, 325.0, 380);
    glVertex3f(-725, 350.0, 380);
    glVertex3f(-725, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 325.0, 370);
    glVertex3f(-710, 325.0, 370);
    glVertex3f(-735, 350.0, 370);
    glVertex3f(-725, 350.0, 370);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-700, 325.0, 380);
    glVertex3f(-710, 325.0, 380);
    glVertex3f(-735, 350.0, 380);
    glVertex3f(-725, 350.0, 380);
    glEnd();
    //lurus
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-725, 360.0, 380);
    glVertex3f(-725, 350.0, 380);
    glVertex3f(-735, 350.0, 380);
    glVertex3f(-735, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-725, 360.0, 380);
    glVertex3f(-725, 360.0, 340);
    glVertex3f(-735, 360.0, 340);
    glVertex3f(-735, 360.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-725, 350.0, 380);
    glVertex3f(-725, 350.0, 340);
    glVertex3f(-735, 350.0, 340);
    glVertex3f(-735, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-725, 350.0, 340);
    glVertex3f(-725, 360.0, 340);
    glVertex3f(-725, 360.0, 380);
    glVertex3f(-725, 350.0, 380);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-735, 350.0, 340);
    glVertex3f(-735, 360.0, 340);
    glVertex3f(-735, 360.0, 380);
    glVertex3f(-735, 350.0, 380);
    glEnd();
    //bohlam
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-715, 360.0, 310);
    glVertex3f(-715, 360.0, 340);
    glVertex3f(-745, 360.0, 340);
    glVertex3f(-745, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-715, 360.0, 340);
    glVertex3f(-715, 350.0, 340);
    glVertex3f(-745, 350.0, 340);
    glVertex3f(-745, 360.0, 340);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-715, 360.0, 310);
    glVertex3f(-715, 350.0, 310);
    glVertex3f(-745, 350.0, 310);
    glVertex3f(-745, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-715, 360.0, 340);
    glVertex3f(-715, 350.0, 340);
    glVertex3f(-715, 350.0, 310);
    glVertex3f(-715, 360.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-745, 360.0, 340);
    glVertex3f(-745, 350.0, 340);
    glVertex3f(-745, 350.0, 310);
    glVertex3f(-745, 360.0, 310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-715, 345.0, 310);
    glVertex3f(-715, 345.0, 340);
    glVertex3f(-745, 345.0, 340);
    glVertex3f(-745, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-715, 345.0, 340);
    glVertex3f(-715, 350.0, 340);
    glVertex3f(-715, 350.0, 310);
    glVertex3f(-715, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-745, 345.0, 340);
    glVertex3f(-745, 350.0, 340);
    glVertex3f(-745, 350.0, 310);
    glVertex3f(-745, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-715, 345.0, 310);
    glVertex3f(-715, 350.0, 310);
    glVertex3f(-745, 350.0, 310);
    glVertex3f(-745, 345.0, 310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-715, 345.0, 340);
    glVertex3f(-715, 350.0, 340);
    glVertex3f(-745, 350.0, 340);
    glVertex3f(-745, 345.0, 340);
    glEnd();
    //matahari
    glEnable(GL_COLOR_MATERIAL);
    glTranslatef(350, 3000, -2000);
    glColor3f(0.9, 1, 0);
    glScalef(10, 10, 10);
    glutSolidSphere(30.0, 100, 30);
    glDisable(GL_COLOR_MATERIAL);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, lebar / tinggi, 5.0, 5000.0);
    glViewport(0, 0, 900, 600);
    glTranslatef(0.0, -5.0, -220.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("National Cheng Kung University-Taiwan");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(mySpecialFunc);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
