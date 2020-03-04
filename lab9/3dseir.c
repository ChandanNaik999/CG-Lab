#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
GLfloat v[4][3]={{0.0,0.0,1.0},{0.0,1.0,0.0},
                     {-1.0,-0.5,0.0}, {1.0,-0.5,0.0}};
GLfloat colors[4][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,0.0,0.0}};
int n;
void triangle(GLfloat *va,GLfloat *vb,GLfloat *vc)
{
        glVertex3fv(va);
        glVertex3fv(vb);
        glVertex3fv(vc);
}
void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{
    glColor3fv(colors[0]);
    triangle( a, b, c);
    glColor3fv(colors[1]);
    triangle( a, c, d);
    glColor3fv(colors[2]);
    triangle( a, d, b);
    glColor3fv(colors[3]);
    triangle( b, d, c);
}

void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m)
{
    GLfloat mid[6][3];
    int j;
    if(m>0)
    {    /*compute six midpoints*/
        for(j=0;j<3;j++) mid[0][j]=(a[j]+b[j])/2;
        for(j=0;j<3;j++) mid[1][j]=(a[j]+c[j])/2;
        for(j=0;j<3;j++) mid[2][j]=(a[j]+d[j])/2;
        for(j=0;j<3;j++) mid[3][j]=(b[j]+c[j])/2;
        for(j=0;j<3;j++) mid[4][j]=(c[j]+d[j])/2;
        for(j=0;j<3;j++) mid[5][j]=(b[j]+d[j])/2;
        divide_tetra(a,mid[0],mid[1],mid[2],m-1);
        divide_tetra(mid[0],b,mid[3],mid[5],m-1);
        divide_tetra(mid[1],mid[3],c,mid[4],m-1);
        divide_tetra(mid[2],mid[5],mid[4],d,m-1);
    }
    else
        tetra( a, b, c, d);      //draw triangle at end of recursion//
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);      // This glBegin is to draw triangles taking three
    divide_tetra(v[0],v[1],v[2],v[3],n); // vertices at a time. divide_tetra calls itself
    glEnd();                                 //  and finally tetra which calls triangle four times
                                                         // which in-turn calls vertex function.
    glFlush();                                 // Call flush at the end to send output to screen
                                                                // making the gasket visible
}

void myReshape(int w,int h)
{
    glViewport(0,0,w,h);                 // Set the viewport to span the entire window
glMatrixMode(GL_PROJECTION);//Change the matrix mode to GL_PROJECTION
    glLoadIdentity();                       // Load the identity matrix to GL_PROJECTION
    glOrtho(-2.0,2.0,-2.0,2.0 ,-10.0,10.0);//Multiply orthographic projection matrix
                             // to this GL_PROJECTION matrix to change projection type to
                                                                  // Orthographic
glMatrixMode(GL_MODELVIEW);//Change the matrix mode to GL_MODELVIEW
    glutPostRedisplay();     //Arrange or fix or appoint or schedule a call to display
                                                          // function  as soon as possible.
}

int main(int argc,char **argv)//Comments for main included only in this program
{
printf("enter the no of division ");
scanf("%d",&n);
glutInit(&argc,argv);                                  // Initialize the graphics system
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
                                                   // Initialize the display mode
                             // to use a single buffer in the frame buffer and not DOUBLE                                       // and to use RGB color system(and not CMYK)
                                             // and to make use of DEPTH buffer since this
                                                      // is a 3D program
glutInitWindowSize(500,500);       // Initialize window size
glutCreateWindow("3d gasket");   // Create a window
glutReshapeFunc(myReshape);//Register the reshape function for call back when
                                                       // current window size changes.
glutDisplayFunc(display);       // Register the display function for call back.
                                       // Display function is called when ever the contents of
                            // the window changes as in an animation or any overlapping
                       //window gets closed and our window needs to be redrawn or our
                    // window changes shape or our window gets maximized and hence
                                     // visible from invisible
glEnable(GL_DEPTH_TEST);
                        // Enable hidden surface removal or visible surface determination
                            // this test is usually enabled in conjunction with use of
                            // GLUT_DEPTH in glutInitDisplayMode and hence only in 3D
                                         // programs
glClearColor(1.0,1.0,1.0,1.0);        // Set the background color to white
glutMainLoop();     // most important line of every program. This calls the event
                               // loop which is an infinite loop. It terminates when program
                          // is terminated. It is responsible for calling the display function, 
                           // the mouse function, the reshape function the idle function, the
                     // keyboard function, the special keyboard  function at appropriate
                         // times during the running of the program.
return 0;
}