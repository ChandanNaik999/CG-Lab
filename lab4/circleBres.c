#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

int xa,ya,r;
void display(){
	int x = 0, y = r, p = 3 -2*r;

	glColor3f(1,1,1);
	glBegin(GL_POINTS);
		while( x <= y){
			x++;
			//draw points
			glVertex2i(x+xa, y+ya);
			glVertex2i(x+xa, -1*y+ya);
			glVertex2i(-1*x+xa, y+ya);
			glVertex2i(-1*x+xa, -1*y+ya);

			glVertex2i(y+ya, x+xa);
			glVertex2i(y+ya, -1*x+xa);
			glVertex2i(-1*y+ya, x+xa);
			glVertex2i(-1*y+ya, -1*x+xa);

			if( p < 0)
				p = p + 4*x + 6;
			else{
				p = p + 4*(x-y) + 10;
				y--;
			}
		}
	glEnd();
	glFlush();
}

void init(){
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,100,-100,100,-1,1);
}

void main(int argc, char** argv){
	printf("Enter the center (x,y): ");
	scanf("%d %d", &xa, &ya);

	printf("Enter the radius: ");
	scanf("%d", &r);


	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Circle-Bresenham");
	init();
	glutDisplayFunc(display);
	glutMainLoop();


}