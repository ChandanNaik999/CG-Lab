//17co212
// rotate shapes
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 


float angle = 0.0;

void update(int value) {
    angle += 2.0f;
    if (angle > 360) {
        angle -= 360;
    }
    glutPostRedisplay(); 
    glutTimerFunc(25, update, 0);
}


void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 

	glMatrixMode(GL_MODELVIEW);

	//rotate triangle
	glPushMatrix();
	glTranslatef(-0.50f , 0.50f, 0.0f);
	glRotatef(angle , 0.0 , 0.0 ,1.0);
	
    glTranslatef(0.50f, -0.50f, 0.0f);

    glBegin(GL_TRIANGLES);
	    glVertex2f(-0.50f , 0.75f);
	    glVertex2f(-0.75f, 0.50f);
	    glVertex2f(-0.25f , 0.50f);
    glEnd();

    glPopMatrix();



    //rotate square
    glPushMatrix();
	glTranslatef(0.50f , 0.50f, 0.0f);
	glRotatef(angle , 0.0 , 0.0 , 1.0);
	
    glTranslatef(-0.50f, -0.50f, 0.0f);

    glBegin(GL_POLYGON);
	    glVertex2f(0.55f , 0.55f);
	    glVertex2f(0.45f, 0.55f);
	    glVertex2f(0.45f , 0.45f);
	    glVertex2f(0.55f , 0.45f);
    glEnd();

    glPopMatrix();

    //rotate pentagon
    glPushMatrix();
	glTranslatef(0.0f , -0.80f, 0.0f);
	glRotatef(angle , 1.0 , 0.0 , 0.0);
	
    glTranslatef(0.0f, 0.60f, 0.0f);

    glBegin(GL_POLYGON);
	    glVertex2f(0.0f , -0.4f);
	    glVertex2f(-0.25f, -0.5f);
	    glVertex2f(-0.15f , -0.8f);
	    glVertex2f( 0.15f , -0.8f);
	    glVertex2f( 0.25f, -0.5f);
    glEnd();

    glPopMatrix();



   

	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("Rotate Shapes"); 

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	glColor3f(1.0, 1.0, 1.0); 
	
	glutDisplayFunc(display); 
	glutTimerFunc(25, update, 0);
	glutMainLoop(); 
} 
