#include<gl/glut.h>
void SetupRC()
{
	glEnable(GL_DEPTH_TEST);//深度测试
	glFrontFace(GL_CCW);//逆时针
	glClearColor(220/255.0,220/255.0,220/255.0,1);//灰色
}
void ChangeSize(int w,int h)
{
	if(h==0) h = 1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);//投影
	glLoadIdentity();
	GLfloat fAspect;
	fAspect = (float)w / (float)h;
	gluPerspective(60.0,fAspect,10.0,500.0);//对称透视
	glMatrixMode(GL_MODELVIEW);//模型视图
	glLoadIdentity();
}
void RenderScene(void)
{
	static float fElect1 = 0.0f;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);//置为模型视图矩阵
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-200.0f);//沿Z负方向移
	glColor3f(1.0f,0.0f,0.0f);
	glutSolidSphere(20.0f,15,15);//红色圆

	glPushMatrix();
	glRotatef(fElect1,0.0f,1.0f,0.0f);
	glTranslatef(90.0f,0.0f,0.0f);
	glColor3f(0.0f,1.0f,0.0f);
	glutSolidSphere(3.0f,15,15);//绿色圆
	glPopMatrix();

	glPushMatrix();
	glRotatef(45.0f,0.0f,0.0f,1.0f);//Z旋转
	glRotatef(fElect1,0.0f,1.0f,0.0f);
	glTranslatef(-70.0f,0.0f,0.0f);
	glColor3f(0.0f,0.0f,1.0f);
	glutSolidSphere(6.0f,15,15);//蓝色圆
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
	glutCreateWindow("窗口");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(500,TimerFunc,1);
	
	SetupRC();
	glutMainLoop();
	return 0;
}