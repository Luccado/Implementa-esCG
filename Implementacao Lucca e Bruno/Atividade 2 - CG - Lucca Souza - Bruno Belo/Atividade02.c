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

    // Ponto 1 principal cima
    glColor3f(1.0, 0.0, 0.0); // cor
    glVertex2f(0.0, 0.4); // localização

    // esquerda 
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.03, 0.43);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.06, 0.46);

    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.09, 0.46);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.12, 0.46);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.15, 0.43);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.18, 0.4);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.18, 0.37);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.18, 0.34);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.15, 0.31);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.12, 0.28);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.09, 0.25);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.06, 0.22);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(-0.03, 0.19);
    
    
    //principal baixo
    glColor3f(1.0, 0.0, 0.0); 
    glVertex2f(0.0, 0.16);
        
    // direita
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.03, 0.43);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.06, 0.46);

    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.09, 0.46);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.12, 0.46);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.15, 0.43);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.18, 0.4);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.18, 0.37);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.18, 0.34);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.15, 0.31);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.12, 0.28);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.09, 0.25);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.06, 0.22);
    
    glColor3f(0.0, 1.0, 0.0); 
    glVertex2f(0.03, 0.19);

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

