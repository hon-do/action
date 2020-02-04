#include <stdio.h>
#include "glut.h"

int windowWidth = 1000;
int windowHeight = 800;

bool keys[256];

void display(void) {
	//êFclear
	glClear(GL_COLOR_BUFFER_BIT);//GLbitfield mask

	glMatrixMode(GL_PROJECTION);// GLenum mode
	glLoadIdentity();
	gluOrtho2D(0, windowWidth,// GLdouble left, GLdouble right,
		windowHeight, 0);// GLdouble bottom,GLdouble top

	glMatrixMode(GL_MODELVIEW);// GLenum mode
	glLoadIdentity();

	glTranslatef(windowWidth/2,windowHeight/2,1);// GLfloat x, GLfloat y, GLfloat z
	static float angle;
	if (keys['d'])	angle += 1;
	if (keys['a'])	angle -= 1;

	//âÒì]
	glRotatef(
		angle,// GLfloat angle
		0, 0, 1);// GLfloat x, GLfloat y, GLfloat z

	glScalef(256,256,1);// GLfloat x, GLfloat y, GLfloat z
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
	//printf("reshape: width:%d height:%d\n", width, height);
	glViewport(0, 0, width, height);// GLint x, GLint y, GLsizei width, GLsizei height
	windowWidth = width;
	windowHeight = height;
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 0x1b)
		exit(0);
	printf("keyboard: \'%c\'(%#x)\n", key, key);
	keys[key] = true;
}

void keyboardUp(unsigned char key, int x, int y) {
	printf("keyboard: \'%c\'(%#x)\n", key, key);
	keys[key] = false;
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
	glutKeyboardFunc(keyboard);// void (GLUTCALLBACK *func)(unsigned char key, int x, int y
	glutKeyboardUpFunc(keyboardUp);// void (GLUTCALLBACK *func)(unsigned char key, int x, int y))
	glutIgnoreKeyRepeat(GL_TRUE);// int ignore
	glutMainLoop();
}