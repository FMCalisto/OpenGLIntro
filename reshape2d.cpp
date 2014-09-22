/*#include <windows.h>
#include <gl\GL.h>
#include <glut.h>*/
#include <GL/glut.h>
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    glPushMatrix();
		glColor3ub(0,255,0);
			glBegin(GL_POLYGON);
				glVertex3f (-25, 25, 0.0);
				glVertex3f (-25, -25, 0.0);
				glVertex3f (0, -25, 0.0);
				glVertex3f (0, 25, 0.0);   
			glEnd();
        

		glColor3ub(255,0,0);
			glBegin(GL_POLYGON);
				glVertex3f (0, 25, 0.0);
				glVertex3f (0, -25, 0.0);
				glVertex3f (25, -25, 0.0);
				glVertex3f (25, 25, 0.0);   
		glEnd();
		
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( -w/2.0, w/2.0, -h/2.0, h/2.0, -1, 1);
  
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(400,400);
    glutCreateWindow("3ª parte");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
