#include "glut.h"

void display(void) {
	glutWireTeapot(1);// GLdouble size
	glutSwapBuffers();// doublebuffer�̐؂�ւ�
}

void (idle)(void) {
	//�Fclear
	glClear(GL_COLOR_BUFFER_BIT);//GLbitfield mask
	//��]
	glRotatef(
		1,// GLfloat angle
		0, 0, 1);// GLfloat x, GLfloat y, GLfloat z

	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(
		&argc,// int *argcp
		argv);// char **argv
	//doublebuffering��
	glutInitDisplayMode(GL_DOUBLE);// unsigned int mode
	glutInitWindowPosition(640, 0);// int x, y
	glutInitWindowSize(640, 640);// int width, height
	glutCreateWindow("title");// const char *title
	glutDisplayFunc(display);// void (GLUTCALLBACK *func)(void)
	glutIdleFunc(idle);// void (GLUTCALLBACK *func)(void)
	glutMainLoop();
}