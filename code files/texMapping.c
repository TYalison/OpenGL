#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <gl.h>
#include <glu.h>
#include <glut.h>

char *imgFile = "TT.bmp";
float rX = 0.0f, rY = 0.0f, rZ = 0.0f;
GLuint texId;
GLfloat hfEdge = 0.3f;
GLint tWidth, tHeight;
GLint pLen;//pixel_length
GLubyte* pData;//pixel_data

/*
<glaux.h>
typedef struct _AUX_RGBImageRec
{
	GLint sizeX, sizeY;
	unsigned char *data;
}AUX_RGBImageRec;
*/

void loadTex()
{
	FILE* img = fopen(imgFile, "rb");

	fseek(img, 18, SEEK_SET);
	fread(&tWidth, 4, 1, img);
	fread(&tHeight, 4, 1, img);
	fseek(img, 0, SEEK_END);
	pLen = ftell(img) - 54;
	pData = (GLubyte*)malloc(pLen);
	fseek(img, 54, SEEK_SET);
	fread(pData, pLen, 1, img);

	fclose(img);

	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, tWidth, tHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, pData);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	free(pData);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}
void initLight()
{
	//light: ambient + white diffuse(10,10,10)
	const GLfloat light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_position[] = { 10.0f, 10.0f, 10.0f, 0.0f };
/*
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
*/
	glEnable(GL_DEPTH_TEST);

//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}
void Cube()
{
	GLfloat//vertexs of cube
		VertexA[3] = { -hfEdge,-hfEdge,-hfEdge },
		VertexB[3] = { hfEdge,-hfEdge,-hfEdge },
		VertexC[3] = { hfEdge,-3 * hfEdge,-hfEdge },
		VertexD[3] = { -hfEdge,-3 * hfEdge,-hfEdge },
		VertexE[3] = { -hfEdge,-hfEdge,hfEdge },
		VertexF[3] = { hfEdge,-hfEdge,hfEdge },
		VertexG[3] = { hfEdge,-3 * hfEdge,hfEdge },
		VertexH[3] = { -hfEdge,-3 * hfEdge,hfEdge };

#if 0
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif
	
	loadTex();
	glEnable(GL_TEXTURE_2D);
	glRotatef(rX, 1.0f, 0.0f, 0.0f);
	glRotatef(rY, 0.0f, 1.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(VertexA);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(VertexB);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(VertexC);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(VertexD);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(VertexE);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(VertexF);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(VertexG);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(VertexH);
	glEnd();
/*
	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(VertexA);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(VertexB);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(VertexF);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(VertexE);
	glEnd();
*/
	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(VertexB);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(VertexC);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(VertexG);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(VertexF);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(VertexA);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(VertexD);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(VertexH);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(VertexE);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texId);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(VertexG);
		glTexCoord2f(1.0f, 0.0f); glVertex3fv(VertexH);
		glTexCoord2f(1.0f, 1.0f); glVertex3fv(VertexD);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(VertexC);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
/*
#if 0
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif
*/
	glRotatef(rX, 1.0f, 0.0f, 0.0f);
	glRotatef(rY, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	{
		Cube();
		glTranslatef(0.0f, 0.3f, 0.0f);
		glutSolidTeapot(0.15);
		glTranslatef(0.0f, -0.3f, 0.0f);
		
		//set model:
		glEnable(GL_STENCIL_TEST);
		glStencilFunc(GL_ALWAYS, 1, 0xff);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

		glDepthMask(GL_FALSE);

//		glTranslatef(0.0f, -1.0f, 0.0f);
//		glRotatef(rX, 1.0f, 0.0f, 0.0f);
//		glRotatef(rY, 0.0f, 1.0f, 0.0f);

		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glBegin(GL_QUADS);
			glNormal3f(0.0f,1.0f,0.0f);
			glVertex3f(-hfEdge, -hfEdge, -hfEdge);
			glVertex3f(-hfEdge, -hfEdge, hfEdge);
			glVertex3f(hfEdge, -hfEdge, hfEdge);
			glVertex3f(hfEdge, -hfEdge, -hfEdge);
		glEnd();

//		glTranslatef(0.0f, 1.0f, 0.0f);

		glDepthMask(GL_TRUE);

		glStencilFunc(GL_EQUAL, 1, 0xff);
		glStencilFunc(GL_KEEP, GL_KEEP, GL_KEEP);

		//reflection:
		glPushMatrix();
		glTranslatef(0.0f, -0.5f, 0.0f);
		glScalef(1.0, -1.0, 1.0);
		glutSolidTeapot(0.15);
		glTranslatef(0.0f, 0.5f, 0.0f);
		glPopMatrix();
		glDisable(GL_STENCIL_TEST);
		
	}
	glPopMatrix();

	glutSwapBuffers();
}
void reSh(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	gluPerspective(90, 0.1*w/h, 0.1, 1000);
}
/*
void ctrlKboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: rX -= 1.0f; break;
	case GLUT_KEY_DOWN: rX += 1.0f; break;
	case GLUT_KEY_LEFT: rY -= 1.0f; break;
	case GLUT_KEY_RIGHT: rY += 1.0f; break;
	default: break;
	}

	if (rX > 360.0f) rX -= 360.0f;
	if (rX < 0.0f) rX += 360.0f;
	if (rY > 360.0f) rY -= 360.0f;
	if (rY < 0.0f) rY += 360.0f;
	
	glutPostRedisplay();
}
*/
void texIdle()
{
	rX += 0.1f;
	rY += 0.2f;

	if (rX > 360.0f)
		rX -= 360.0f;
	if (rY > 360.0f)
		rY -= 360.0f;

	glutPostRedisplay();
}
/*
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(600, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Texture Mapping");
	initLight();
	glutReshapeFunc(&reSh);
	glutDisplayFunc(&display);
//	glutSpecialFunc(ctrlKboard);
	glutIdleFunc(texIdle);
	glutMainLoop();
	return 0;
}
*/
