#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define LINE 0
#define POLY 1
#define CIRCLE 2

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

void rotate(int x1, int x2, int angle){

	result[1][0] = x1*cos(angle) - x2*sin(angle);
	result[2][0] = x2*cos(angle) + x1*sin(angle);
}

void resetResult(){
	result[1][0]  = 0;
	result[2][0]  = 0;
	result[3][0]  = 0;
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 1.0);

	if(flag == LINE){
		glBegin(GL_LINES);
			glVertex2i(x1, y11);
			glVertex2i(x2, y2);
		glEnd();

		
		
		

		glBegin(GL_LINES);
			translate(x1, y11, -x1 ,-y11);
			rotate(result[1][0], result[2][0],angle);
			translate(result[1][0], result[2][0], x1 ,y11);
			glVertex2i(result[1][0], result[2][0]);
			resetResult();

			translate(x2, y2, -x1 ,-y11);
			rotate(result[1][0], result[2][0],angle);
			translate(result[1][0], result[2][0], x1 ,y11);
			glVertex2i(result[1][0], result[2][0]);
			resetResult();
		glEnd();

	}

	if(flag == POLY){
		glBegin(GL_POLYGON);
			for(int i=0; i <n; i++ ){
				glVertex2i(points[i][0], points[i][1]);
			}
			
		glEnd();


		glBegin(GL_POLYGON);

			for(int i=0; i <n; i++ ){
				translate(points[i][0], points[i][1], -points[0][0],-points[0][1]);
				rotate(result[1][0], result[2][0], angle);
				translate(result[1][0], result[2][0], points[0][0],points[0][1]);
				printf("%d %d\n", result[1][0], result[2][0]);
				translate(result[1][0], result[2][0], 100 ,0);
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
	glOrtho(0, 500, 0, 500, -1, 1);
}
void main(int argc, char** argv)
{
	int op = 0;


	printf("Rotation: \n");
	printf("1. line\n");
	printf("2. polygon\n");
	printf("Enter option :");
	scanf("%d", &op);

	switch(op){
		case 1: printf("Enter the endpoints of the line: ");
				scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
				flag = LINE;
				break;
		case 2: printf("No of points: ");
				scanf("%d", &n);

				printf("Enter the points: ");
				for( int i =0; i < n; i++){
					for( int j =0; j < 2; j++){
						scanf("%d", &points[i][j]);	
					}
				}
				flag = POLY;
				break;
				

	}

	printf("angle: ");
	scanf("%d", &angle );

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