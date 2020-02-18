#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y11,y2;
float red =1, green =1, blue=1;

#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4

static int win;
static int menyid;
static int animeringsmeny;
static int springmeny;
static int val = 0;
static int fyrkantRoed = 1;
static int fyrkantGroen = 0;
static int fyrkantBla = 0;
static int trekantRoed = 1;
static int trekantGroen = 0;
static int trekantBla = 0;
static int menu, menyid;;

void processMenuEvents(int option) {

	switch (option) {
		case RED :
			red = 1.0f;
			green = 0.0f;
			blue = 0.0f; break;
		case GREEN :
			red = 0.0f;
			green = 1.0f;
			blue = 0.0f; break;
		case BLUE :
			red = 0.0f;
			green = 0.0f;
			blue = 1.0f; break;
		case ORANGE :
			red = 1.0f;
			green = 0.5f;
			blue = 0.5f; break;
	}
}
 

void createGLUTMenus() {

	

	// // create the menu and
	// // tell glut that "processMenuEvents" will
	// // handle the events
	menu = glutCreateMenu(processMenuEvents);

	// //add entries to our menu
	glutAddMenuEntry("Red",RED);
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("Orange",ORANGE);

	menyid = glutCreateMenu(processMenuEvents);

	glutAddSubMenu("Animering", menu);

	// // attach the menu to the right button
	// glutAttachMenu(GLUT_RIGHT_BUTTON);


	//////////
	// MENU //
	//////////
	
	// Create a submenu, this has to be done first.
	// animeringsmeny = glutCreateMenu(processMenuEvents);
	
	// Add sub menu entry
	// glutAddMenuEntry("På", 1);
	// glutAddMenuEntry("Av", 2);
	
	// springmeny = glutCreateMenu(processMenuEvents);
	
	// glutAddMenuEntry("Gå", 3);
	// glutAddMenuEntry("Galopp", 4);
					 
	// Create the menu, this menu becomes the current menu
	// menyid = glutCreateMenu(processMenuEvents);
	
	// Create an entry
	// glutAddSubMenu("Animering", animeringsmeny);
	// glutAddSubMenu("Löpstil", springmeny);
	// // Create an entry
	// glutAddMenuEntry("Avluta", 0);
	
	// Let the menu respond on the right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
}

void display(void)
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

glColor3f(red, green, blue);
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
 
void init(void)
{
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
 
int main(int argc, char** argv) {
printf("Enter  x1 : ");
scanf("%f",&x1);
printf("Enter  y1 : ");
scanf("%f",&y11);
printf("Enter x2 : ");
scanf("%f",&x2);
printf("Enter y2 : ");
scanf("%f",&y2);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA");
init();
createGLUTMenus();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}