#include<stdio.h>
#include<GL/glut.h>

float angle = 0.0;
int direction = 1;

void keyboard(unsigned char key, int x, int y)
{
	//-------- spin --------
	if(key=='a')
	{
		direction = -1;
		glutPostRedisplay();
	}
	else{
		direction = 1;
		glutPostRedisplay();	
	}
	
}


void update(int value) {

	if(direction == 1)
    	angle += 2.0f;
    else if(direction == -1)
    	angle -= 2.0f;
    if (angle > 360) {
        angle -= 360;
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


void drawSmile (int xa, int ya, int r)
{
int p = 3-2*r;
int x=0,y=r;
 
//glClear (GL_COLOR_BUFFER_BIT);
 
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POINTS);

	while(x <= y){
		//draw all points
		//glVertex2i(x+xa,y+ya);
		glVertex2i(x+xa,-1*y+ya);
		//glVertex2i(-1*x+xa,y+ya);
		glVertex2i(-1*x+xa,-1*y+ya);

		//glVertex2i(y+xa,x+ya);
		glVertex2i(y+xa,-1*x+ya);
		//glVertex2i(-1*y+xa,x+ya);
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
	int cx = 250, cy = 250;


	//face
	drawCircle(cx,cy,100);

	//eyes
	drawCircle(cx-30,cy+30,30);
	drawCircle(cx+30,cy+30,30);

	//draw smile
	drawSmile(cx, 210, 30);

	glScalef(1.0f, 1.0f, 2.0f);

	//draw eyeballs

	glPushMatrix();
	glTranslatef(cx-30, cy+30, 0);
	glRotatef(angle , 0.0 , 0.0 , 1.0);
    glTranslatef(-(cx-30) , -(cy+30), 0);

    drawCircle(cx-30,cy+30+20,10);

    glPopMatrix();
	


	glPushMatrix();
	glTranslatef(cx+30, cy+30, 0);
	glRotatef(angle , 0.0 , 0.0 , 1.0);
    glTranslatef(-(cx+30) , -(cy+30), 0);

	drawCircle(cx+30,cy+30+20,10);

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
	glutKeyboardFunc(keyboard);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
}