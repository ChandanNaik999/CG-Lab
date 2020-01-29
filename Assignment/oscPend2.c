#include<stdio.h>
#include<GL/freeglut.h>
#include<math.h>
int n=10;
GLfloat v[4][3]={{0.0,0.0,1.0},{0.0,0.942809,-0.33333},{-0.816497,-0.471405,-0.33333},{0.816497,-0.471405,-0.333333}};
GLfloat a[2][3]={{0.0,0.0,-0.333333},{0.0,3.0,-0.333333}};
void normalize(GLfloat *p)
{
    double d=0.0;
    int i;
    for(i=0;i<3;i++)
        d+=p[i]*p[i];
    d=sqrt(d);
    if(d>0.0)
        for(i=0;i<3;i++)
            p[i]/=d;
}


void triangle(GLfloat *a,GLfloat *b,GLfloat *c)
{
    glBegin(GL_POLYGON);
        glNormal3fv(a);
        glVertex3fv(a); 
        glVertex3fv(b);
        glVertex3fv(c);
    glEnd();
}
void divide_triangle(GLfloat *a,GLfloat *b,GLfloat *c,int n)
{
    GLfloat v1[3],v2[3],v3[3];
    int j;
    if(n>0)
    {
        for(j=0;j<3;j++)
            v1[j]=a[j]+b[j];
        normalize(v1);
        for(j=0;j<3;j++)
            v2[j]=a[j]+c[j];
        normalize(v2);
        for(j=0;j<3;j++)
            v3[j]=c[j]+b[j];
        normalize(v3);
        divide_triangle(a,v2,v1,n-1);
        divide_triangle(c,v3,v2,n-1);
        divide_triangle(b,v1,v3,n-1);
        divide_triangle(v1,v2,v3,n-1);
    }
    else
        triangle(a,b,c);
}
void tetrahedron(int n)
{
    divide_triangle(v[0],v[1],v[2],n);
    divide_triangle(v[3],v[2],v[1],n);
    divide_triangle(v[0],v[3],v[1],n);
    divide_triangle(v[0],v[2],v[3],n);
}
GLfloat theta=0.0;

void update(int value) {
    static float direction = 1.0f;
    if( theta > 45.0f )
        direction = -1.0f;
    if( theta < -45.0f )
        direction = 1.0f;

    theta += 10.0 * direction;
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex3fv(a[0]);
        glVertex3fv(a[1]);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    tetrahedron(n);
    glColor3f(0.0,0.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,+3.0,-0.333333);
    glRotatef(theta,0.0,0.0,1.0);
    glTranslatef(0.0,-3.0,+0.333333);   
    glFlush();
}
void myReshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
            glOrtho(-4.0,4.0,-4.0*(GLfloat)h/(GLfloat)w,4.0*(GLfloat)h/(GLfloat)w,-20.0,20.0);
    else
            glOrtho(-4.0*(GLfloat)w/(GLfloat)h,4.0*(GLfloat)w/(GLfloat)h,-4.0,4.0,-20.0,20.0);
    glMatrixMode(GL_MODELVIEW);
}
// void oscillate()
// {
//     static float direction = 1.0f;
//     if( theta > 45.0f )
//         direction = -1.0f;
//     if( theta < -45.0f )
//         direction = 1.0f;

//     theta += 5.0 * direction;
//     glutPostRedisplay();
// }

void init(){
    // glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100,100,-100,100,-1,1);
}


void main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1366,768);
    glutCreateWindow("Pendulum");
    glutReshapeFunc(myReshape);

    glutDisplayFunc(display);
    // glutIdleFunc(oscillate);
    // glEnable(GL_DEPTH_TEST);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
}