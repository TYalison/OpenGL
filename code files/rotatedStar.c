#include <glut.h>
#include <math.h>

float rot_angle = 0.0f;
GLfloat tlen = 0.2;
GLfloat PI = 3.1415926536f;
GLfloat rotP[2];

void Star(void)
{
	//Vstar 'ABCDE'
	GLfloat a = tlen / sin(36.0 * PI / 180);
	GLfloat bx = a * cos(18.0 * PI / 180);
	GLfloat by = a * sin(18.0 * PI / 180);
	GLfloat cy = -a * cos(36.0 * PI / 180);
	GLfloat
		PointO[2] = { 0.0, 0.0 },
		PointA[2] = { 0.0, a },
		PointB[2] = { bx, by },
		PointC[2] = { tlen, cy },
		PointD[2] = { -tlen, cy },
		PointE[2] = { -bx, by };
	//Varea 'MNOPQ'
	GLfloat my = a * tan(18.0 * PI / 180) / (tan(18.0 * PI / 180) + tan(36.0 * PI / 180));//ny=my
	GLfloat mx = -my * tan(36.0 * PI / 180);//nx=-mx
	GLfloat py = mx / sin(36.0 * PI / 180);//px=0
	GLfloat qx = py * sin(72.0 * PI / 180);//ox=-qx
	GLfloat qy = py * cos(72.0 * PI / 180);//oy=qy
	GLfloat
		PointM[2] = { mx, my },
		PointN[2] = { -mx, my },
		PointK[2] = { -qx, qy },
		PointP[2] = { 0, py },
		PointQ[2] = { qx, qy };

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(PointE[0], PointE[1], 0.0f);
	glRotatef(rot_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-PointE[0], -PointE[1], 0.0f);

	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
		glVertex2fv(PointM);
		glVertex2fv(PointN);
		glVertex2fv(PointK);
		glVertex2fv(PointP);
		glVertex2fv(PointQ);
	glEnd();

	glColor3f(0, 0, 0);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
		glVertex2fv(PointA);
		glVertex2fv(PointD);
		glVertex2fv(PointB);
		glVertex2fv(PointE);
		glVertex2fv(PointC);
	glEnd();

	
	glBegin(GL_LINE_LOOP);
		glVertex2fv(PointA);
		glVertex2fv(PointD);
		glVertex2fv(PointB);
		glVertex2fv(PointE);
		glVertex2fv(PointC);
	glEnd();

	glFlush();
}

void rotIdle()
{
	rot_angle += 0.01f;
	if (rot_angle > 360.0f)
		rot_angle -= 360.0f;
	glutPostRedisplay();
}
/*
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(600, 200);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Rotated Star");
	glutDisplayFunc(&Star);
	glutIdleFunc(rotIdle);
	glutMainLoop();
	return 0;
}
*/