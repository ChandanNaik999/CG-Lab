#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

int xa,ya,r;

void drawCircle(){
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
}

void drawLine (int xa, int ya, int xb, int yb)
{
	int dx=xb-xa;
	int dy=yb-ya;
	int p = 2*dy - dx;
	int x=xa,y=ya;
	 
	
	 
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_POINTS);

		while(x <= xb){
			glVertex2i(y,x+r);
			x++;
			if( p < 0){
				p = p + 2*dy;
			}
			else{
				p = p + 2*dy - 2*dx;
				y++;
			}
		}

	glEnd();
	glFlush();
}
void display(){

	drawCircle();
	drawLine(xa,ya,xa+4*r,ya);
	
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