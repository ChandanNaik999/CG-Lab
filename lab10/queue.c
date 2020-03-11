#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MAX = 6;
int size = 0;
int arr[10];
int latest = 0;
int flag = 0;
int head, tail;
//0 push
//1 pop



void displayText(unsigned char string[], int x, int y){
	int w;
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glRasterPos2i(x -  w / 2, y);
	glColor3f(1., 0., 0.);
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
	    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
}

void drawArrow(int posx,int posy, int angle){

	glPushMatrix();
		glRotatef(angle, 0, 0, 1);
		glBegin(GL_TRIANGLES);
			glVertex2i(posx, posy);
			glVertex2i(posx-10, posy-10);
			glVertex2i(posx+10, posy-10);
		glEnd();
	glPopMatrix();

}


void display(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	int st_x = 100, st_y = 300, width = 50, height = 50;


	
	displayText("QUEUE", 250, 400);
	glColor3f(1,1,1);
	for(int i =0 ; i < MAX;i++){
		glBegin(GL_POLYGON);
			glVertex2i(st_x, st_y);
			glVertex2i(st_x+width, st_y);
			glVertex2i(st_x+width, st_y+height);
			glVertex2i(st_x, st_y+height);
		glEnd();

		st_x += height+2; 
	}

	glColor3f(0,0,0);
	if(size == 0){
		glColor3f(1,1,1);
		displayText("QUEUE EMPTY", 300, 20);
		drawArrow(100, 300, 0);

	}
	else if(size == MAX){
		glColor3f(1,1,1);
		displayText("QUEUE FULL", 300, 20);
	}
	else{
		glColor3f(1,1,1);
		char final[100];
		if(flag == 1)
			strcpy(final, "inserted element: ");
		else if(flag ==2)
			strcpy(final, "deleted element: ");
		char s[5];
		sprintf(s, "%d", latest);
		strcat(final, s);
		displayText(final, 300, 20);
	}

	int posX = 125, posY = 325; 
	for(int i =head; i < tail; i++){
		char s[5];
		sprintf(s, "%d", arr[i]);
		// itoa(arr[i], s, 10);
		printf("%s",s );
		displayText(s, posX, posY);
		if( i == tail-1)
			drawArrow(posX, posY-50, 0);
		posX += 50;
	}

	glFlush();
}






void init(){
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void enqueue(){
	flag = 1;
	int n = rand()%10;
	latest = n;
	if(size < MAX){
		arr[size] = n;
		size++;
		tail++;
	}
	
	display();

}

void dequeue(){
	flag =2;
	if(size > 0)
		size--;
	latest = arr[head];
	head++;
	display();
}


void keyboardFunc(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'i':enqueue(); break;
	case 'd': dequeue(); break;
	}
}

void main(int argc, char** argv){



	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Stack Implementation");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardFunc);
	glutMainLoop();


}