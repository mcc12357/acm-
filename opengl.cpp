#include<gl/glut.h>
void SetupRC()
{
	glEnable(GL_DEPTH_TEST);//��Ȳ���
	glFrontFace(GL_CCW);//��ʱ��
	glClearColor(220/255.0,220/255.0,220/255.0,1);//��ɫ
}
void ChangeSize(int w,int h)
{
	if(h==0) h = 1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);//ͶӰ
	glLoadIdentity();
	GLfloat fAspect;
	fAspect = (float)w / (float)h;
	gluPerspective(60.0,fAspect,10.0,500.0);//�Գ�͸��
	glMatrixMode(GL_MODELVIEW);//ģ����ͼ
	glLoadIdentity();
}
void RenderScene(void)
{
	static float fElect1 = 0.0f;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);//��Ϊģ����ͼ����
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-200.0f);//��Z��������
	glColor3f(1.0f,0.0f,0.0f);
	glutSolidSphere(20.0f,15,15);//��ɫԲ

	glPushMatrix();
	glRotatef(fElect1,0.0f,1.0f,0.0f);
	glTranslatef(90.0f,0.0f,0.0f);
	glColor3f(0.0f,1.0f,0.0f);
	glutSolidSphere(3.0f,15,15);//��ɫԲ
	glPopMatrix();

	glPushMatrix();
	glRotatef(45.0f,0.0f,0.0f,1.0f);//Z��ת
	glRotatef(fElect1,0.0f,1.0f,0.0f);
	glTranslatef(-70.0f,0.0f,0.0f);
	glColor3f(0.0f,0.0f,1.0f);
	glutSolidSphere(6.0f,15,15);//��ɫԲ
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45.0,0.0f,0.0f,1.0f);
	glRotatef(fElect1,0.0f,1.0f,0.0f);
	glTranslatef(0.0f,0.0f,60.0f);
	glColor3f(1.0f,1.0f,0.0f);
	glutSolidSphere(9.0f,15,15);
	glPopMatrix();

	fElect1 += 10.0f;
	if(fElect1 > 360.0f) fElect1 = 10.0f;
	glutSwapBuffers();
}

void TimerFunc(int value)
{
	glutPostRedisplay();
	glutTimerFunc(100,TimerFunc,1);
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("����");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(500,TimerFunc,1);
	
	SetupRC();
	glutMainLoop();
	return 0;
}