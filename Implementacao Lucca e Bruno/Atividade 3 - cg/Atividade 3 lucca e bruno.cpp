#include <gl/glut.h>
#include <cmath>

using namespace std;

void piramide(){
	
	glBegin(GL_TRIANGLES);
	
	//face vermelha da piramide
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2i(-4,1);
	glVertex2i(-2,4);
	glVertex2i(-2,0);
	
	//face azul da piramide
	glColor3f(0.0f,0.0f,1.0f);
	glVertex2i(-2,4);
	glVertex2i(0,1);
	glVertex2i(-2,0);
	
	glEnd();
}

void draw_piramide(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	
	//desenho original
	piramide();
	
	//transladado para a direita
	glPushMatrix();
	glTranslatef(10.0f, 0.0f, 0.0f);
	piramide();
	glPopMatrix();
	
	
	//transladado para a baixo
	glPushMatrix();
	glTranslatef(0.0f, -10.0f, 0.0f);
	piramide();
	glPopMatrix();
	
	//escalonando e transladado para alinhar
	//com os demais
	glPushMatrix();
	glScalef(0.5f, 1.0f, 1.0f);
	glTranslatef(18.0f, -10.0f, 0.0f);
	piramide();
	glPopMatrix();
	
	
	glFlush();
}

//cor de fundo
void fundo(){
	glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
}

//funcao para caso seja feita um resize da janela
void tamanhoJanela(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5,15,-15,10);
}

int main(int argc, char** argv){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(750, 750);
	glutInitWindowPosition(0, 0);
	glutInit(&argc, argv);
	glutCreateWindow("Atividade 3, Bruno e Lucca");
	glutDisplayFunc(draw_piramide);
	glutReshapeFunc(tamanhoJanela);
	fundo();
	glutMainLoop();
		
}

