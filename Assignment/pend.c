//draw pendulum

#include<stdio.h>
#include<GL/glut.h>
#define RIGHT 1
#define LEFT 0

float angle = 0.0;
int direction = 1;
float increment = 1.0f;

void update(int value) {

	if(direction == RIGHT){
		if(angle >= 45){
    		angle -= increment;
    		direction = LEFT;
		}
    	else
    		angle += increment;
	}
    if(direction == LEFT){
		if(angle <= -45){
    		angle += increment;
    		direction = RIGHT;
		}
    	else
    		angle -= increment;
	}
    glutPostRedisplay(); 
    glutTimerFunc(25, update, 0);
}

void drawCircle (int xa, int ya, int r)
{
int p = 3-2*r;
int x=0,y=r;
 
//glClear (GL_COLOR_BUFFER_BIT);
 
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POINTS);

	while(x <= y){
		//draw all points
		glVertex2i(x+xa,y+ya);
		glVertex2i(x+xa,-1*y+ya);
		glVertex2i(-1*x+xa,y+ya);
		glVertex2i(-1*x+xa,-1*y+ya);

		glVertex2i(y+xa,x+ya);
		glVertex2i(y+xa,-1*x+ya);
		glVertex2i(-1*y+xa,x+ya);
		glVertex2i(-1*y+xa,-1*x+ya);
		x++;
		if( p < 0){
			p = p + 4*x + 6;
		}
		else{
			p = p + 4*(x-y) + 10;
			y--;
		}
	}

glEnd();
glFlush();
}



void display(){
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 1.0);
	int cx = 250, cy = 100, r =30;
	int length = 5;

	glBegin(GL_LINES);
		glVertex2i(cx-50, cy + length*r);
		glVertex2i(cx+50, cy + length*r);
	glEnd();
	

	glPushMatrix();

	glTranslatef(cx, cy+length*r, 0);
	glRotatef(angle , 0.0 , 0.0 , 1.0);
    glTranslatef(-cx , -(cy+length*r), 0);

	glBegin(GL_LINES);
		glVertex2i(cx, cy);
		glVertex2i(cx, cy + length*r);
	glEnd();



    drawCircle(cx,cy,r);

    glPopMatrix();
	


	glFlush();
}

void init()
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500, -1, 1);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Smiley");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
}