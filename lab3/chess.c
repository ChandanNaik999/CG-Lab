#include <stdio.h>
#include <GL/glut.h>

int x = 50, y = 50;
int isBlack = 1;

void drawLine(int x1, int y11, int x2, int y2)
{
float dy,dx,step,x,y,i,Xin,Yin;
dx=x2-x1;
dy=y2-y11;
 
if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);
 
Xin = dx/step;
Yin = dy/step;
 
x= x1;
y=y11;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
 
	for (i=1 ;i<=step;i++)
	{
	x= x + Xin;
	y= y + Yin;
	 
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	}
 
 
glFlush();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);

	for (int j = 0; j <= 400; j+=50)
	{
		drawLine(j,0,j+50,400);
		drawLine(0,j,400,j+50);
	}

	glFlush();
}


void myInit(void)
{
	// glClearColor(0,0,0,0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	// glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Chessboard");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}