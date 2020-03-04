#include<stdio.h>
#include<GL/glut.h>
int n;



void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
     glVertex2fv(a);    
     glVertex2fv(b);
     glVertex2fv(c);
}

void draw_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int k)
{
     GLfloat ab[2], bc[2], ac[2]; 
     int j;
if(k>0)           
     {
    for(j=0;j<2;j++) ab[j] = ((a[j]+b[j])/2.0); 
    for(j=0;j<2;j++) bc[j] = ((b[j]+c[j])/2.0); 
    for(j=0;j<2;j++) ac[j] = ((a[j]+c[j])/2.0); 
    draw_triangle(a, ab, ac, k-1);      
    draw_triangle(ab, b, bc, k-1);      
    draw_triangle(ac, bc, c, k-1);      
     }
else
     triangle(a, b, c);             
     
}

void display()
{
     GLfloat a[2] = {0.0, 0.0};             
     GLfloat b[2] = {5.0, 10.0};
     GLfloat c[2] = {10.0, 0.0};

     glClear(GL_COLOR_BUFFER_BIT);          

     glBegin(GL_TRIANGLES);
       draw_triangle(a, b, c, n);     
     glEnd();
     glFlush();
}

void myInit()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);
     glColor3f(1.0, 0.0, 0.0);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, 10.0, 0.0, 10.0);
     glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    printf("Enter the number of recursions: ");
    scanf("%d", &n);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2d Gasket");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
return 0;
}