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

int flag = 0;

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
void bahamas() {
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	{
		glVertex3f(-2.5, 1.5, 0);
		glVertex3f(-0.5, 0, 0);
		glVertex3f(-2.5, -1.5, 0);
	}
	glEnd();
	rectangle(0, -1, 5, 1, 0.2, 0.2, 0.75);
	rectangle(0, 0, 5, 1, 0.75, 0.75, 0);
	rectangle(0, 1, 5, 1, 0.2, 0.2, 0.75);
}

void germany() {
	rectangle(0, -1, 5, 1, 1, 0.8078, 0);
	rectangle(0, 0, 5, 1, .866666, 0, 0);
	rectangle(0, 1, 5, 1, 0, 0, 0);
}
void somalia() {
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON); //figura
	{
		glVertex3f(0, 0.6, 0);//A
		glVertex3f(.5, -0.5, 0);//B
		glVertex3f(0, -0.25, 0);//C
		glVertex3f(-.5, -0.5, 0);//D
	}
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON); //figura
	{
		glVertex3f(-.6, .2, 0);
		glVertex3f(.6, .2, 0);
		glVertex3f(0, -0.2, 0);

	}
	glEnd();
	rectangle(0, 0, 4, 3, .2549, 0.5372, 0.87);
}
void greece() {//las figuras entran por jerarquia
	//Cuadro
	rectangle(-1.375, 0.5, 1.25, 0.25, 1, 1, 1);
	rectangle(-1.375, 0.5, 0.25, 1.25, 1, 1, 1);
	rectangle(-1.375, 0.5, 1.25, 1.25, .05, 0.368, 0.6862);
	//Lineas
	rectangle(0, 1, 4, 0.25, .05, 0.368, 0.6862);	 //Azul
	rectangle(0, 0.75, 4, 0.25, 1, 1, 1);				 //Blanco
	rectangle(0, 0.5, 4, 0.25, .05, 0.368, 0.6862);
	rectangle(0, 0.25, 4, 0.25, 1, 1, 1);
	rectangle(0, 0, 4, 0.25, 0.05, 0.368, 0.6862);
	rectangle(0, -0.25, 4, 0.25, 1, 1, 1);
	rectangle(0, -0.5, 4, 0.25, .05, 0.368, 0.6862);
	rectangle(0, -0.75, 4, 0.25, 1, 1, 1);
	rectangle(0, -1, 4, 0.25, .05, 0.368, 0.6862);
	
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	gluLookAt(0.0, 0.0, 10.0,										// Where the camera is.
		      0.0, 0.0, 0.0,										// To where the camera points at.
		      0.0, 1.0, 0.0);										// "UP" vector.

	

	//Flag Excersise
	switch (flag)
	{
	case 1:
		japan();
		break;
	case 2:
		germany();
		break;
	case 3:
		jamaica();
		break;
	case 4:
		finland();
		break;
	case 5:
		bahamas();
		break;
	case 6:
		somalia();
		break;
	case 7:
		greece();
		break;
	default:
		japan();
	}

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
	case '1':
		flag = 1;
		break;
	case '2':
		flag = 2;
		break;
	case '3':
		flag = 3;
		break;
	case '4':
		flag = 4;
		break;
	case '5':
		flag = 5;
		break;
	case '6':
		flag = 6;
		break;
	case '7':
		flag = 7;
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
