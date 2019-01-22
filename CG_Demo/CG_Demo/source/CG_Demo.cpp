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

void axes() {
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
		
	}
	glEnd();
}

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

//PONG Game Logic

//	Left Paddle
float lpX = -3;
float lpY = 0;
void leftPaddle() {
	rectangle(lpX,lpY,0.1,0.3,1,1,1);
}
//	Right Paddle
float rpX = 3;
float rpY = 0;
void rightPaddle() {
	rectangle(rpX, rpY, 0.1, 0.3, 1, 1, 1);
}
//	Ball
float ballX = 0;
float ballY = 0;
float ballVel = 0.01;
float ballAngle = 35.0;
float DEG2RAD = 0.0174533;

void ball() {
	//printf("%0.3f %0.3f \n", ballX, ballY);
	if (ballX < 3.5  && ballX > -3.5) {
		ballX += ballVel * cos(DEG2RAD*ballAngle);
	}
	else 
	{
		ballAngle = ballAngle - 90;
		ballX += ballVel * cos(DEG2RAD*ballAngle);
	}
	if (ballY > -3.5 && ballY < 3.5) {
		ballY += ballVel * -sin(DEG2RAD*ballAngle);
	}
	else {
		ballAngle = ballAngle - 90;
		ballY += ballVel * -sin(DEG2RAD*ballAngle);
	}
	rectangle(ballX, ballY, 0.1, 0.1, 1, 1, 1);
}
//End of game logic

void init() // FOR GLUT LOOP
{
	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}


void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	gluLookAt(0.0, 0.0, 10.0,										// Where the camera is.
		      0.0, 0.0, 0.0,										// To where the camera points at.
		      0.0, 1.0, 0.0);										// "UP" vector.



	axes();

	leftPaddle();
	rightPaddle();
	ball();

	glutSwapBuffers();												// Swap the hidden and visible buffers.


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
	case 'w':
		if (rpY < 3.5)
		{
			rpY = rpY + 0.1;
		}
		break;
	case 's':
		if (rpY > -3.5) {
			rpY = rpY - 0.1;
		}
		break;
	}
	//glutPostRedisplay();
}

void specialKey(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		if (lpY < 3.5)
		{
			lpY = lpY + 0.1;
		}
		break;
	case GLUT_KEY_DOWN:
		if (lpY > -3.5) {
		lpY = lpY - 0.1;
		}
		break;
	}
	//glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 800);
	glutCreateWindow("PONG!");
	
	init();

	glutKeyboardFunc(littleKey);
	glutSpecialFunc(specialKey);

	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutIdleFunc(idle);												// Idle CALLBACK function.
	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}
