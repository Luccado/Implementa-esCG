/*
		Feito por:
	Bruno Belo Comachio;
	Lucca Souza Di Oliveira.	
*/
#include <GL/glut.h>
#include <windows.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5.0);
    glBegin(GL_POINTS);

    // Ponto 1 no centro
    glColor3f(1.0, 0.0, 0.0); // cor
    glVertex2f(0.0, 0.0); // localização

    // Ponto 2
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.2, 0.5);
    
    // Ponto 3
    glColor3f(0.0,0, 1);
	glVertex2f(0.5, 0.1);
	
	// Ponto 4
	glColor3f(0.5, 1.5, 0.5);
    glVertex2f(-0.5, 0.);
    
    // Ponto 5
    glColor3f(1.5, 0.2, 0.7);
    glVertex2f(0.3, -0.3);

    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Cor de fundo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set das coordenadas
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade de Implementação #1");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

