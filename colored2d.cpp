/*#include <windows.h>
#include <gl\GL.h>
#include <glut.h>*/

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>



#include <time.h>
int i=0, R=0, G=0, B=0, speed=250;
int Ra=250, Ga=250, Ba=250;
static GLfloat spin = 0.0;


int __nsleep(const struct timespec *req, struct timespec *rem)
{
    struct timespec temp_rem;
    if(nanosleep(req,rem)==-1)
        __nsleep(rem,&temp_rem);
    else
        return 1;
}
 
int msleep(unsigned long milisec)
{
    struct timespec req={0},rem={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    __nsleep(&req,&rem);
    return 1;
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glRotatef(spin, 0.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    i++;

        if(i==5)
                i=1;
    
    if(speed>0)
        speed -=2;
        else
                speed = 200;
    
 msleep(speed);
    

                
    R=rand() % 250 + 1;  
     G=rand() % 250 + 1;  
     B=rand() % 250 + 1;  
    Ra=rand() % 250 + 1;  
     Ga=rand() % 250 + 1;  
     Ba=rand() % 250 + 1; 
    
    if(i==1){
    glPushMatrix();
    
		glColor3ub(R,G,B);
			glBegin(GL_POLYGON);
				glVertex3f (-25, 25, 0.0);
				glVertex3f (-25, -25, 0.0);
				glVertex3f (0, -25, 0.0);
				glVertex3f (0, 25, 0.0);   
			glEnd();
        

		glColor3ub(Ra,Ga,Ba);
			glBegin(GL_POLYGON);
				glVertex3f (0, 25, 0.0);
				glVertex3f (0, -25, 0.0);
				glVertex3f (25, -25, 0.0);
				glVertex3f (25, 25, 0.0);   
		glEnd();
		
    glPopMatrix();
    } if(i==2){
               glPushMatrix();
    
		glColor3ub(R,G,B);
			glBegin(GL_POLYGON);
				glVertex3f (0, 25, 0.0);
				glVertex3f (0, -25, 0.0);
				glVertex3f (25, -25, 0.0);
				glVertex3f (25, 25, 0.0);   
			glEnd();
        

		glColor3ub(Ra,Ga,Ba);
			glBegin(GL_POLYGON);
				
				glVertex3f (-25, 25, 0.0);
				glVertex3f (-25, -25, 0.0);
				glVertex3f (0, -25, 0.0);
				glVertex3f (0, 25, 0.0);    
		glEnd();
		
    
    }
    if(i==3){

    glPushMatrix();
    
		glColor3ub(R,G,B);
			glBegin(GL_POLYGON);
				glVertex3f (-25, 25, 0.0);
				glVertex3f (-25, 0, 0.0);
				glVertex3f (25, 0, 0.0);
				glVertex3f (25, 25, 0.0);   
			glEnd();
        

		glColor3ub(Ra,Ga,Ba);
			glBegin(GL_POLYGON);
				glVertex3f (-25, 0, 0.0);
				glVertex3f (-25, -25, 0.0);
				glVertex3f (25, -25, 0.0);
				glVertex3f (25, 0, 0.0);   
		glEnd();
		
    glPopMatrix();
    } if(i==4){
               glPushMatrix();
    
		glColor3ub(R,G,B);
			glBegin(GL_POLYGON);
				glVertex3f (-25, 25, 0.0);
				glVertex3f (-25, 0, 0.0);
				glVertex3f (25, 0, 0.0);
				glVertex3f (25, 25, 0.0);   
			glEnd();
        

		glColor3ub(Ra,Ga,Ba);
			glBegin(GL_POLYGON);
				glVertex3f (-25, 0, 0.0);
				glVertex3f (-25, -25, 0.0);
				glVertex3f (25, -25, 0.0);
				glVertex3f (25, 0, 0.0);   
		glEnd();
		
    
    }  
 
    glutSwapBuffers();
    
    printf("%d\n", speed);
    

}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // glOrtho( -w/2.0, w/2.0, -h/2.0, h/2.0, -1, 1);
  
}

void reDisplay(void){
   glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(reDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(400,400);
    glutCreateWindow("3ª parte");

       
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
  
    glutMainLoop();
    return 0;
}

   /*spin = spin + 2.0;
   if (spin > 360.0)
      spin = spin - 360.0;*/
