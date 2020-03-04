#include<GL/glut.h>
#include<math.h>
#include<stdio.h>


void display();

float xmin=-100;
float ymin=-100;
float xmax=100;
float ymax=100;
float xd[100];
float yd[100];
float xa[100];
float ya[100];
int N;

void init(void)
{

    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);

}

int code(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void cohen_Line(float x1,float y1,float x2,float y2,int i)
{
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
            return;
        }

    float xi=x1;float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else
       if((c & 2)>0)
       {
           x=xmax;
           y=yi+m*(xmax-xi);
       }
       else
       if((c & 1)>0)
       {
           x=xmin;
           y=yi+m*(xmin-xi);
       }

       if(c==c1)
       {
           xd[i]=x;
           yd[i]=y;
           c1=code(xd[i],yd[i]);
       }

       if(c==c2)
       {
           xd[(i+1)%N]=x;
           yd[(i+1)%N]=y;
           c2=code(xd[(i+1)%N],yd[(i+1)%N]);
       }
}

 display();

}

void mykey(unsigned char key,int x,int y)
{
    if(key=='s')
    {  //printf("Hello\n");
        int i=0;
        for(;i<N;i++)
        {
            cohen_Line(xd[i],yd[i],xd[(i+1)%N],yd[(i+1)%N],i);
        }
        
        glFlush();
    }
}
void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();
    int i=0;
   for(;i<N;i++)
   {
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(xd[i],yd[i]);
    glVertex2i(xd[(i+1)%N],yd[(i+1)%N]);
    glEnd();
   }
//     for(i=0;i<N;i++)
//     {
//       glColor3f(0.0,0.0,1.0);
//    glBegin(GL_LINES);
//    glVertex2i(xa[i],ya[i]);
//    glVertex2i(xd[i],yd[i]);
//    glEnd();
//     }
   glFlush();




}


int main(int argc,char** argv)
{
    printf("Enter number of edges: ");
    scanf("%d",&N);
    printf("Enter co-ordinates(xi,yi)\n");
    int i=0;
    for(;i<N;i++)
    {
        scanf("%f%f",&xd[i],&yd[i]);
        xa[i]=xd[i];
        ya[i]=yd[i];
    }
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}