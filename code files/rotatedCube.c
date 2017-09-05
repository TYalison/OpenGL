#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <glut.h>
#include <math.h>

GLfloat hfLen = 0.5f;
float rotX = 0.0f;
float rotY = 0.0f;
int winX = 600;
int winY = 600;

void drawCube(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//vertexs of cube
	GLfloat
		VertexA[3] = { -hfLen,-hfLen,-hfLen },
		VertexB[3] = { hfLen,-hfLen,-hfLen },
		VertexC[3] = { hfLen,hfLen,-hfLen },
		VertexD[3] = { -hfLen,hfLen,-hfLen },
		VertexE[3] = { -hfLen,-hfLen,hfLen },
		VertexF[3] = { hfLen,-hfLen,hfLen },
		VertexG[3] = { hfLen,hfLen,hfLen },
		VertexH[3] = { -hfLen,hfLen,hfLen };

#if 0
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif

	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);

	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
		glVertex3fv(VertexA);
		glVertex3fv(VertexB);
		glVertex3fv(VertexC);
		glVertex3fv(VertexD);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
		glVertex3fv(VertexA);
		glVertex3fv(VertexB);
		glVertex3fv(VertexF);
		glVertex3fv(VertexE);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
		glVertex3fv(VertexE);
		glVertex3fv(VertexF);
		glVertex3fv(VertexG);
		glVertex3fv(VertexH);
	glEnd();

	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
		glVertex3fv(VertexG);
		glVertex3fv(VertexH);
		glVertex3fv(VertexD);
		glVertex3fv(VertexC);
	glEnd();

	glColor3f(1, 0, 1);
	glBegin(GL_QUADS);
		glVertex3fv(VertexB);
		glVertex3fv(VertexC);
		glVertex3fv(VertexG);
		glVertex3fv(VertexF);
	glEnd();

	glColor3f(0, 1, 1);
	glBegin(GL_QUADS);
		glVertex3fv(VertexA);
		glVertex3fv(VertexD);
		glVertex3fv(VertexH);
		glVertex3fv(VertexE);
	glEnd();

	glutSwapBuffers();
}

void reShape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1.0 * w / h, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	//Camera_view: 
	//from (0,5,20) to (0,0,0), direct(0,1,0)
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void chgIdle()
{
	rotX += 0.01f;
	rotY += 0.02f;

	if (rotX > 360.0f)
		rotX -= 360.0f;
	if (rotY > 360.0f)
		rotY -= 360.0f;

	glutPostRedisplay();
}
/*
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winX, winY);
	glutCreateWindow("Rotated Cube");
	glutReshapeFunc(&reShape);
	glutDisplayFunc(&drawCube);
	glutIdleFunc(chgIdle);
	glutMainLoop();
	return 0;
}
*/