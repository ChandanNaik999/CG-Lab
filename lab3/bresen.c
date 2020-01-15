#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
 
int xa,xb,ya,yb;
void display (void)
{
int dx=xb-xa;
int dy=yb-ya;
int p = 2*dy - dx;
int x=xa,y=ya;
 
glClear (GL_COLOR_BUFFER_BIT);
 
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POINTS);

	while(x <= xb){
		glVertex2i(x,y);
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
 
void init(void)
{
glClearColor (0,0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-100, 100, -100, 100, -1.0, 1.0);
}
 
int main(int argc, char** argv)
{
// printf("Enter the points\n(X1,Y1,X2,Y2):-\n");
// scanf("%d %d %d %d",&xa,&ya,&xb,&yb);

printf("Enter  x1 : ");
scanf("%d",&xa);
printf("Enter  y1 : ");
scanf("%d",&ya);
printf("Enter  x2 : ");
scanf("%d",&xb);
printf("Enter  y2 : ");
scanf("%d",&yb);


glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Bresenham ");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}