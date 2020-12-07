/******************************************************
* Zeus CMD - OpenGL ES Tutorial 14 : Backface Culling *
* By Grant James (ZEUS)                               *
* http://www.zeuscmd.com                              *
******************************************************/
#pragma comment(lib, "libGLES_CM.lib")

#define GLUTES_STATIC

#include <GL/glut.h>
#include <GL/glut.h>
#include <GL/glut.c>

float xrot = 0.0f;
float yrot = 0.0f;

bool acw = true;

GLfloat box[] = {
	// FRONT
	-0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	// BACK
	-0.5f, -0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	// LEFT
	-0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,
	// RIGHT
	 0.5f, -0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	// BOTTOM
	-0.5f, -0.5f,  0.5f,
	-0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f, -0.5f,
};

void init()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepthf(1.0f);

	glVertexPointer(3, GL_FLOAT, 0, box);
	glEnableClientState(GL_VERTEX_ARRAY);

	glShadeModel(GL_FLAT);

	glEnable(GL_CULL_FACE);
}

void display()
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   gluLookAtf(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

   glRotatef(xrot, 1.0f, 0.0f, 0.0f);
   glRotatef(yrot, 0.0f, 1.0f, 0.0f);

   glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
   glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
   glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);

   glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
   glDrawArrays(GL_TRIANGLE_STRIP, 8, 4);
   glDrawArrays(GL_TRIANGLE_STRIP, 12, 4);

   glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
   glDrawArrays(GL_TRIANGLE_STRIP, 16, 4);

   glFlush ();
   glutSwapBuffers();
}

void idle()
{
	xrot += 2.0f;
	yrot += 3.0f;

	glutPostRedisplay();
}

void keyboard2(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP : exit(0); break;
	}
}

void menu(int entry)
{
	switch(entry)
	{
	case 1 : exit(0); break;
	case 2 : 
		acw = !acw;

		glFrontFace(acw ? GL_CCW : GL_CW);
		
		break;
	case 3 : 
		if (glIsEnabled(GL_CULL_FACE))
			glDisable(GL_CULL_FACE);
		else
			glEnable(GL_CULL_FACE);
		break;
	}
}

void reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, width, height);
	gluPerspectivef(45.0f, 1.0f * width / height, 1.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutCreateWindow("14 - Backface Culling");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard2);

	glutIdleFunc(idle);

	glutCreateMenu(menu);
	glutAddMenuEntry("Toggle Culling", 3);
	glutAddMenuEntry("Reverse Culling", 2);
	glutAddMenuEntry("Quit", 1);

	glutAttachMenu(GLUT_LEFT_BUTTON);
	
	glutMainLoop();

	return 0;
}
