#include <GL/glut.h>

GLdouble size=1;
int flag = 0;




void display(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-4.5);
    glColor3f(1, 0.0, 0.0); 
    glScalef(1.0,1.0,1.0);
    if(flag == 1)
        glutSolidTeapot(1);
    if(flag == 2)
        glutWireTeapot(1);
    glFlush();        
}

void menu(int num){
  if(num == 1)
    flag = 1;
 else if(num == 2)
    flag = 2;
  glutPostRedisplay();
} 


void reshapeFunc(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
 
    glViewport(0,0,x,y);  
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(400,350);
    glutCreateWindow("Teapot");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);

    glutCreateMenu(menu);
    glutAddMenuEntry("Cross", 1);
    glutAddMenuEntry("straight", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}