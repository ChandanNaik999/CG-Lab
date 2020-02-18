#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define XAXIS 0
#define YAXIS 1

int trans[3][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
};

int flag= 0;
int x1, y11, x2, y2, xa, ya, r, points[100][2],n, sx, sy, angle;
int result[3][1]={0,0,0};


// glutPostRedisplay();


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

void translate(int x1, int x2, int tx, int ty){

	result[1][0] = x1 + tx;
	result[2][0] = x2 + ty;
}

void resetResult(){
	result[1][0]  = 0;
	result[2][0]  = 0;
	result[3][0]  = 0;
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 1.0);


	glBegin(GL_LINES);
		glVertex2i(0, -100);
		glVertex2i(0, 100);
	glEnd();

	glBegin(GL_LINES);
		glVertex2i(-100, 0);
		glVertex2i(100, 0);
	glEnd();

	if(flag == XAXIS){
		glBegin(GL_POLYGON);
			for(int i=0; i <n; i++ ){
				glVertex2i(points[i][0], points[i][1]);
			}
			
		glEnd();


		glBegin(GL_POLYGON);

			for(int i=0; i <n; i++ ){
				translate(points[i][0], points[i][1], 0,-2*points[i][1]);
			
				glVertex2i(result[1][0], result[2][0]);
				resetResult();
				
			}
		glEnd();

	}


	if(flag == YAXIS){
		glBegin(GL_POLYGON);
			for(int i=0; i <n; i++ ){
				glVertex2i(points[i][0], points[i][1]);
			}
			
		glEnd();


		glBegin(GL_POLYGON);

			for(int i=0; i <n; i++ ){
				translate(points[i][0], points[i][1], -2*points[i][0], 0);
			
				glVertex2i(result[1][0], result[2][0]);
				resetResult();
				
			}
		glEnd();

	}
	glFlush();
}

void init()
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -1, 1);
}
void main(int argc, char** argv)
{
	int op = 0;
	printf("Polygon Reflection: \n");

	printf("No of points: ");
	scanf("%d", &n);

	printf("Enter the points: ");
	for( int i =0; i < n; i++){
		for( int j =0; j < 2; j++){
			scanf("%d", &points[i][j]);	
		}
	}


	printf("1. X AXIS\n");
	printf("2. Y AXIS:  ");
	printf("Enter option: ");
	scanf("%d", &op);

	switch(op){
		case 1: 
				flag = XAXIS;
				break;
		case 2: 
				flag = YAXIS;
				break;
				

	}

		glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("rotation");
	init();
	glutDisplayFunc(display);
	// glutTimerFunc(25, update, 0);
	glutMainLoop();
	
	
}