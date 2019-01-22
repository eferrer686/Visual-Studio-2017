/*
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Basic template OpenGL project.
 */

// Please don't change lines 9-31 (It helps me to grade)
#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
	#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
	#include "GL/freeglut.h"
	#include "GL/gl.h"
#endif

#include <stdio.h>
#include <math.h>

void rectangle(float x, float y ,float w, float h, float r, float g, float b) {
	
	//printf("%.3f %.3f %.3f \n", r, g, b);

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	{
		glVertex3f(x - (w/2), y - (h/2) , 0);
		glVertex3f(x + (w/2), y - (h/2) , 0);
		glVertex3f(x + (w/2), y + (h/2) , 0);
		glVertex3f(x - (w/2) , y + (h/2) , 0);
	}
	glEnd();
}


void init() // FOR GLUT LOOP
{
	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}

float posX;

// Japan Flag
void circle() {
	glColor3f(1.0, 0, 0);
	glBegin(GL_POLYGON);
	{
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.75*cos(i), -0.75*sin(i) , 0);
		}		
	}
	glEnd();
}
void japan() {
	circle();
	rectangle(0,0,4,3,1,1,1);
	glEnd();
}

//Jamaica Flag
void jamaica() {
	//Black triangles
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	{
		glVertex3f(-2, 1.2, 0);
		glVertex3f(-0.3, 0, 0);
		glVertex3f(-2, -1.2, 0);
	}
	glEnd();
	glBegin(GL_POLYGON);
	{
		glVertex3f(2, 1.2, 0);
		glVertex3f(0.3, 0, 0);
		glVertex3f(2, -1.2, 0);
	}
	glEnd();

	//Green triangles
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	{
		glVertex3f(-1.5, 1.5, 0);
		glVertex3f(0, 0.5, 0);
		glVertex3f(1.5, 1.5, 0);
	}
	glEnd();
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	{
		glVertex3f(-1.5, -1.5, 0);
		glVertex3f(0, -0.5, 0);
		glVertex3f(1.5, -1.5, 0);
	}
	glEnd();
	
	//Yellow background
	rectangle(0,0,4,3,1,1,0);

}
void finland() {
	rectangle(0, 0, 4, 0.65, 0, 0, 1);
	rectangle(-0.75, 0, 0.65, 3, 0, 0, 1);
	rectangle(0, 0, 4, 3, 1, 1, 1);
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	gluLookAt(0.0, 0.0, 10.0,										// Where the camera is.
		      0.0, 0.0, 0.0,										// To where the camera points at.
		      0.0, 1.0, 0.0);										// "UP" vector.

	

	//Flag Excersise
	finland();

	glutSwapBuffers();												// Swap the hidden and visible buffers.

	posX = posX - 0.01;

}

void idle()															// Called when drawing is finished.
{
	glutPostRedisplay();											// Display again.
}

void reshape(int x, int y)											// Called when the window geometry changes.
{
	glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
	glLoadIdentity();												// Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);		// Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
	glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
	gluLookAt(0.0, 1.0, 4.0,
		      0.0, 0.0, 0.0,
		      0.0, 1.0, 0.0);
	display();
}

void littleKey(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'a':
		printf("aaaaa\n");
		break;
	case 'b':
		printf("bbbbb\n");
		break;
	case 'c':
		printf("ccccc\n");
		break;
	case 'd':
		printf("ddddd\n");
		break;
	}
	glutPostRedisplay();
}

void specialKey(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		printf("up\n");
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	posX = 0.0;

	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG first program");
	
	init();

	glutKeyboardFunc(littleKey);
	glutSpecialFunc(specialKey);

	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutIdleFunc(idle);												// Idle CALLBACK function.
	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}
