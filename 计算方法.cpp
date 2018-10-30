/*
���л���ΪMicrosoft Visual C++ 6.0
���������ַ���
*/
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
const double eps = 0.000001;
const int inf = 100000;
double cal1(double x)
{
	return x * (x * (230 * x * x + 18 * x + 9) - 221) - 9;
}
double cal2(double x)
{
	return x * (x * (230 * x * x + 18 * x + 9) - 220) - 9;
}
double cal3(double x)
{
	return x - (x * (x * (230 * x * x + 18 * x + 9) - 221) - 9) / ( x * (920 * x * x + 54 * x + 18) - 22);
}
double cal4(double x1,double x2)
{
	return x2 - cal1(x2) * (x2 - x1) / (cal1(x2) - cal1(x1));
}
double f1(double l,double r)
{
	int count = 0;
	while(r-l>eps)
	{
		count++;
		double mid = (l + r) / 2;
		if(cal1(l)*cal1(mid)<eps) r = mid;
		else l = mid;
	}
	printf("%d\n",count);
	return l;
}
double f2(double x)
{
	double y;
	int count = 0;
	while(1)
	{
		count++;
		y = cal2(x);
		if(fabs(x-y)<eps) break;
		x = y;
		if(count>=inf) return -2;
	}
	//printf("%d\n",count);
	return x;
}
double f3(double x)
{
	double y;
	int count = 0;
	while(1)
	{
		count++;
		y = cal3(x);
		if(fabs(x-y)<eps) break;
		x = y;
		if(count>=inf) return -2;
	}
	printf("%d\n",count);
	return x;
}
double f4(double x1,double x2)
{
	double x3;
	int count = 0;
	while(1)
	{
		count++;
		x3 = cal4(x1,x2);
		if(fabs(x2-x3)<eps) break;
		x1 = x2;
		x2 = x3;
		if(count>inf) return -2;
	}
	printf("%d\n",count);
	return x3;
}
void bisection()
{
	printf("���ַ�������:\n");
	double x;
	printf("��������Ϊ: ");
	x = f1(-1.0,0.0);
	if(x>=-1 && x<=0) printf("��һ����Ϊ%.6lf\n",x);
	else printf("���ַ��������ڴ˺���\n");
	printf("��������Ϊ: ");
	x = f1(0.0,1.0);
	if(x>=0 && x<=1) printf("�ڶ�����Ϊ%.6lf\n",x);
	else printf("���ַ��������ڴ˺���\n");
}
void fixed_point()
{
	printf("�����㷨������:\n");
	double x;
	x = f2(-1.0);
	if(x>=-1 && x<=0) printf("��һ����Ϊ%.6lf\n",x);
	else printf("��������������㷨�������ڴ˺���\n");
	x = f2(1.0);
	if(x>=0 && x<=1) printf("�ڶ�����Ϊ%.6lf\n",x);
	else printf("��������������㷨�������ڴ˺���\n");
}
void newton()
{
	printf("ţ�ٷ�������:\n");
	double x;
	printf("��������Ϊ: ");
	x = f3(-1.0);
	if(x>=-1 && x<=0) printf("��һ����Ϊ%.6lf\n",x);
	else printf("ţ�ٷ��������ڴ˺���\n");
	printf("��������Ϊ: ");
	x = f3(1.0);
	if(x>=0 && x<=1) printf("�ڶ�����Ϊ%.6lf\n",x);
	else printf("ţ�ٷ��������ڴ˺���\n");
}
void secant()
{
	printf("secant������:\n");
	double x;
	printf("��������Ϊ: ");
	x = f4(-1.0,0.0);
	if(x>=-1 && x<=0) printf("��һ����Ϊ%.6lf\n",x);
	else printf("secant�������ڴ˺���\n");
	printf("��������Ϊ: ");
	x = f4(1.0,2.0);
	if(x>=0 && x<=1) printf("�ڶ�����Ϊ%.6lf\n",x);
	else printf("secant�������ڴ˺���\n");
}
int main()
{
	bisection();
	fixed_point();
	newton();
	secant();
}