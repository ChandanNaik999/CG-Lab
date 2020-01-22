#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

int xa,ya,r,dir=0,yinc = 0;

void update(int value) {
    if(dir == 0){
    	if(yinc > 80)
    		dir = 1;
    	yinc++;
    }
    else{
    	if(yinc < -80)
    		dir = 0;
    	yinc--;
    }
    
    glutPostRedisplay(); 
    glutTimerFunc(25, update, 0);
}


void display(){
	int x = 0, y = r, p = 3 -2*r;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glBegin(GL_POINTS);
		while( x <= y){
			x++;
			//draw points
			glVertex2i(x+xa+yinc, y+ya+yinc);
			glVertex2i(x+xa+yinc, -1*y+ya+yinc);
			glVertex2i(-1*x+xa+yinc, y+ya+yinc);
			glVertex2i(-1*x+xa+yinc, -1*y+ya+yinc);

			glVertex2i(y+ya+yinc, x+xa+yinc);
			glVertex2i(y+ya+yinc, -1*x+xa+yinc);
			glVertex2i(-1*y+ya+yinc, x+xa+yinc);
			glVertex2i(-1*y+ya+yinc, -1*x+xa+yinc);

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
	glutTimerFunc(25, update, 0);
	glutMainLoop();


}