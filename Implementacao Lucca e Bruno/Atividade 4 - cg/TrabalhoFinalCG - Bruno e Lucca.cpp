#include <gl/gl.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <cmath>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

//Camera
float camX = 0.0f;
float camY = 0.0f;
float camZ = 5.0f;
float camYaw = 0.0f;
float camPitch = 0.0f;

// Mouse variaveis
int mouseX, mouseY;
bool mouseLeftButton = false;

bool firstLightEnabled = false;
bool secondLightEnabled = false;
bool thirdLightEnabled = false;

// Funcao pra setar a camera e sua direcao
void setCamera()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-camPitch, 1, 0, 0);
    glRotatef(-camYaw, 0, 1, 0);
    glTranslatef(-camX, -camY, -camZ);
}

// window resizing
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// input do teclado
void keyboard(unsigned char key, int x, int y)
{
    float moveSpeed = 0.3;
    
    
    if (key == 'f')
    {
        secondLightEnabled = !secondLightEnabled;
        glutPostRedisplay();
    }
    if (key == 'g')
    {
    	firstLightEnabled = !firstLightEnabled;
    	glutPostRedisplay();
    }
    if (key == 'h')
    {
    	thirdLightEnabled = !thirdLightEnabled;
    	glutPostRedisplay();
    }
    
    
    switch (key)
    {
    case 's':
        camX -= sin(camYaw * 3.14159265359 / 180.0) * moveSpeed;
        camZ += cos(camYaw * 3.14159265359 / 180.0) * moveSpeed;
        break;
    case 'w':
        camX += sin(camYaw * 3.14159265359 / 180.0) * moveSpeed;
        camZ -= cos(camYaw * 3.14159265359 / 180.0) * moveSpeed;
        break;
    case 'd':
        camX += sin((camYaw + 90.0) * 3.14159265359 / 180.0) * moveSpeed;
        camZ -= cos((camYaw + 90.0) * 3.14159265359 / 180.0) * moveSpeed;
        break;
    case 'a':
        camX += sin((camYaw - 90.0) * 3.14159265359 / 180.0) * moveSpeed;
        camZ -= cos((camYaw - 90.0) * 3.14159265359 / 180.0) * moveSpeed;
        break;
     case 'q':
        camY += moveSpeed;
        break;
    case 'e':
        camY -= moveSpeed;
        break;
    }
    

    glutPostRedisplay();
}

//Inputs do mouse
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            mouseX = x;
            mouseY = y;
            mouseLeftButton = true;
        }
        else if (state == GLUT_UP)
        {
            mouseLeftButton = false;
        }
    }
}

// Movimento do mouse
void motion(int x, int y)
{
    if (mouseLeftButton)
    {
        camYaw += (x - mouseX) * 0.5;
        camPitch -= (y - mouseY) * 0.5;

        mouseX = x;
        mouseY = y;
        glutPostRedisplay();
    }
}


// Iluminacao
void setLighting()
{
	glEnable(GL_LIGHTING);
	
	if (firstLightEnabled)
	{

    glEnable(GL_LIGHT0);

    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0}; // Posicao da luz
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  // luz branca

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	}
	else
	{
		glDisable(GL_LIGHT0);
	}
    
    if (secondLightEnabled)
    {
        glEnable(GL_LIGHT1);
        GLfloat light_position1[] = {-1.0, 1.0, -1.0, 0.0};  
        GLfloat light_diffuse1[] = {0.0, 0.0, 1.0, 1.0};     
        glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
    }
    else
    {
        glDisable(GL_LIGHT1); 
    }
    
    if (thirdLightEnabled)
    {
        glEnable(GL_LIGHT2);
        GLfloat light_position2[] = {0.0, -1.0, 0.0, 0.0};
        GLfloat light_diffuse2[] = {1.0, 0.0, 0.0, 1.0};     
        glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
    }
    else
    {
        glDisable(GL_LIGHT2); 
    }
}


void setMaterial()
{
    GLfloat material_diffuse[] = {0.5, 0.5, 0.5, 0.3}; 

    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
}


// Funcao para renderizar o cenario
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    setCamera();
	setLighting();
	setMaterial();
	
// Cubo 3D
    glPushMatrix();
    glTranslatef(2.0, 0.0, 0.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Esfera
    glPushMatrix();
    glTranslatef(0.0, 1.0, 2.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Piramide
    glPushMatrix();
    glTranslatef(-2.0, 0.0, 0.0);
    glutSolidCone(1.0, 1.5, 4, 4);
    glPopMatrix();

    // outro cubo
    glPushMatrix();
    glTranslatef(0.0, -1.0, -2.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
	
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Projeto Final");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glutMainLoop();

    return 0;
}
