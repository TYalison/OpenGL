#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <glut.h>
#include <math.h> 

float angle = 0.0f;

void setLight()
{
	//light0: no ambient + white diffuse&specular(-10,10,10)
	const GLfloat light_ambient0[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_diffuse0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_specular0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_position0[] = { -10.0f, 10.0f, 10.0f, 0.0f };
	//light: no ambient + red diffuse&specular(10,10,10)
	const GLfloat light_ambient1[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_diffuse1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_specular1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_position1[] = { 10.0f, 10.0f, 10.0f, 0.0f };

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	//light_white
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	//light_red
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
}

void reProtrans(int w, int h)
{
	//set viewport:
	glViewport(0, 0, w, h);
	//projection transformation:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0 * w / h, 0.1, 10000.0);
}

void drawTPot(void)
{
	//set camera:
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutSolidTeapot(1.0);
	glPopMatrix();

	glutSwapBuffers();
}

void idleRot()
{
	angle+=0.1f;
	if (angle > 360.0f)
		angle -= 360.0f;
	glutPostRedisplay();
}
/*
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Rotated Teapot");
	setLight();
	glutReshapeFunc(&reProtrans);
	glutDisplayFunc(&drawTPot);
	glutIdleFunc(idleRot);
	glutMainLoop();
	return 0;
}
*/