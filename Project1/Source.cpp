#include <stdio.h>
#include "glut.h"

int windowWidth = 1000;
int windowHeight = 800;

void display(void) {
	//êFclear
	glClear(GL_COLOR_BUFFER_BIT);//GLbitfield mask
	//âÒì]
	glRotatef(
		1,// GLfloat angle
		0, 0, 1);// GLfloat x, GLfloat y, GLfloat z

	glutWireTeapot(1);// GLdouble size
	glutSwapBuffers();// doublebufferÇÃêÿÇËë÷Ç¶
}

void (timer)(int value) {
	glutPostRedisplay();

	glutTimerFunc(
		1000 / 60,// unsigned int millis
		timer,	// void (GLUTCALLBACK *func)(int value)
		0);		// int value
}


//void (idle)(void) {
//	//êFclear
//	glClear(GL_COLOR_BUFFER_BIT);//GLbitfield mask
//	//âÒì]
//	glRotatef(
//		1,// GLfloat angle
//		0, 0, 1);// GLfloat x, GLfloat y, GLfloat z
//
//	glutPostRedisplay();
//}

void reshape(int width, int height) {
	printf("reshape: width:%d height:%d\n", width, height);
	windowWidth = width;
	windowHeight = height;
}

int main(int argc, char* argv[]) {
	glutInit(
		&argc,// int *argcp
		argv);// char **argv
	//doublebufferingÅ´
	glutInitDisplayMode(GL_DOUBLE);// unsigned int mode
	glutInitWindowPosition(640, 0);// int x, y
	glutInitWindowSize(windowWidth, windowHeight);// int width, height
	glutCreateWindow("title");// const char *title
	glutDisplayFunc(display);// void (GLUTCALLBACK *func)(void)
	glutTimerFunc(
		0,		// unsigned int millis
		timer,	// void (GLUTCALLBACK *func)(int value)
		0);		// int value
	glutReshapeFunc(reshape);// void (GLUTCALLBACK *func)(int width, int height)
	//glutIdleFunc(idle);// void (GLUTCALLBACK *func)(void)
	glutMainLoop();
}