#include<gl/glut.h>
#include<windows.h>
void initial()
{
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CW);
	glClearColor(1.0, 1.0, 1.0, 0.0);
}
void ChangeSize(int w, int h)
{
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-4.0f, 4.0f, -4.0*h / w, 4.0f*h / w, -4.0f, 4.0f);
	else
		glOrtho(-4.0*h / w, 4.0f*h / w, -4.0f, 4.0f, -4.0f, 4.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glTranslatef(-2.0f, 0.0f, 0.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	GLdouble equ[4] = { -1.0f,2.3f,2.3f,2.3f };
	glClipPlane(GL_CLIP_PLANE0, equ);
	glutSolidTeapot(1.0);
	glPopMatrix();
	glDisable(GL_CULL_FACE);
	glTranslatef(2.0f, 0.0f, 0.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glClipPlane(GL_CLIP_PLANE0, equ);
	glEnable(GL_CLIP_PLANE0);
	glutSolidTeapot(1.0);
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("ÏûÒþ²âÊÔ");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(Display);
	initial();
	glutMainLoop();
	return 0;
}
