#include <glut.h>
#include <math.h>

GLfloat len = 0.5;
GLfloat Pi = 3.1415926536f;

void drawStar(void)
{
	//Vstar 'ABCDE'
	GLfloat a = len / sin(36.0 * Pi / 180);
	GLfloat bx = a * cos(18.0 * Pi / 180);
	GLfloat by = a * sin(18.0 * Pi / 180);
	GLfloat cy = -a * cos(36.0 * Pi / 180);
	GLfloat
		PointO[2] = { 0.0, 0.0 },
		PointA[2] = { 0.0, a },
		PointB[2] = { bx, by },
		PointC[2] = { len, cy },
		PointD[2] = { -len, cy },
		PointE[2] = { -bx, by };
	//Varea 'MNOPQ'
	GLfloat my = a * tan(18.0 * Pi / 180) / (tan(18.0 * Pi / 180) + tan(36.0 * Pi / 180));//ny=my
	GLfloat mx = -my * tan(36.0 * Pi / 180);//nx=-mx
	GLfloat py = mx / sin(36.0 * Pi / 180);//px=0
	GLfloat qx = py * sin(72.0 * Pi / 180);//kx=-qx
	GLfloat qy = py * cos(72.0 * Pi / 180);//ky=qy
	GLfloat
		PointM[2] = { mx, my },
		PointN[2] = { -mx, my },
		PointK[2] = { -qx, qy },
		PointP[2] = { 0, py },
		PointQ[2] = { qx, qy };

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

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
/*
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(600, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Five-pointed Star");
	glutDisplayFunc(&drawStar);
	glutMainLoop();
	return 0;
}
*/