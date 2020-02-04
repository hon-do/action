#include "font.h"
#include "glm\glm.hpp"
#include <stdio.h>
#include "glut.h"



using namespace glm;

ivec2 windowSize = { 800, 600 };


bool keys[256];

void display(void) {
	//êFclear
	glClear(GL_COLOR_BUFFER_BIT);//GLbitfield mask

	glMatrixMode(GL_PROJECTION);// GLenum mode
	glLoadIdentity();
	gluOrtho2D(0, windowSize.x,// GLdouble left, GLdouble right,
		windowSize.y, 0);// GLdouble bottom,GLdouble top

	glMatrixMode(GL_MODELVIEW);// GLenum mode
	glLoadIdentity();

	glTranslatef(windowSize.x / 2, windowSize.y / 2, 1);// GLfloat x, GLfloat y, GLfloat z
	static float angle;
	if (keys['d'])	angle += 1;
	if (keys['a'])	angle -= 1;

	//âÒì]
	glRotatef(
		angle,// GLfloat angle
		0, 0, 1);// GLfloat x, GLfloat y, GLfloat z

	glScalef(256, 256, 1);// GLfloat x, GLfloat y, GLfloat z
	glutWireTeapot(1);// GLdouble size


	fontBegin();
	fontSetColor(0, 0xff, 0x0b);
	fontSetSize(FONT_DEFAULT_SIZE);
	float lineHeight = fontGetSize() * 1.5;
	float y = windowSize.y - lineHeight * 2;

	fontSetWeight(fontGetWeightMin());
	fontSetPosition(0, y);
	fontDraw("min:%f", fontGetWeightMin());

	fontSetWeight(fontGetWeightMax());
	fontSetPosition(0, y += lineHeight);
	fontDraw("max:%f", fontGetWeightMax());

	fontEnd();

	glutSwapBuffers();// doublebufferÇÃêÿÇËë÷Ç¶
}

void (timer)(int value) {
	glutPostRedisplay();

	glutTimerFunc(
		1000 / 60,// unsigned int millis
		timer,	// void (GLUTCALLBACK *func)(int value)
		0);		// int value
}

void (idle)(void) {
	glutPostRedisplay();
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
	windowSize = ivec2(width, height);
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 0x1b)
		exit(0);
	//	printf("keyboard: \'%c\'(%#x)\n", key, key);
	keys[key] = true;
}

void keyboardUp(unsigned char key, int x, int y) {
	//	printf("keyboard: \'%c\'(%#x)\n", key, key);
	keys[key] = false;
}

int main(int argc, char* argv[]) {
	glutInit(
		&argc,// int *argcp
		argv);// char **argv
	//doublebufferingÅ´
	glutInitDisplayMode(GL_DOUBLE);// unsigned int mode
	glutInitWindowPosition(640, 0);// int x, y
	glutInitWindowSize(windowSize.x, windowSize.y);// int width, height
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