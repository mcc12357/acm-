#include<iostream>
using namespace std;
#include <stdio.h>
#include <math.h>

#define size_t int
#define max_num 100
#define d double
const double pi = 3.141592653;
const double e = 2.71828182845;

void show_row(size_t i, d *R)
{
	printf("R[%d] = ", i);
	size_t j;
	for (j = 0; j <= i; ++j){
		printf("%f ", R[j]);
	}
	printf("\n");
}

d f(d x)
{
	d y;
	return sin(x);
	//return y = ((((400 * x - 900)*x + 675)*x - 200)*x + 25)*x + 0.2;
	//return y = 4 / (1 + x*x);
	//return cos(1/x)/x;
	//return (10 * pow(e,-x) * sin(2 * pi * x)) * (10 * pow(e,-x) * sin(2 * pi * x));
}

d Romberg(d(*f)(d), d  a, d b, d  acc)/* function to integrate *//*lower limit*/ /*upper limit*//*desired accuracy*/
{
	d R1[max_num], R2[max_num]; //buffers
	d *Rp = &R1[0], *Rc = &R2[0]; //Rp(previous) Rc(current)
	d h = (b - a);
	Rp[0] = (f(a) + f(b))*h*.5; // 第一次梯形

	show_row(0, Rp);
	size_t i;
	size_t j;
	for (i = 1; i < max_num; ++i){
		h /= 2.;
		d c = 0;
		size_t ep = 1 << (i - 1); //2^(n-1)
		for (j = 1; j <= ep; ++j){
			c += f(a + (2 * j - 1)*h);
		}
		Rc[0] = h*c + .5*Rp[0]; //R(i,0)
		for (j = 1; j <= i; ++j){
			d n_k = pow(4.0, j);//4^j
			Rc[j] = (n_k*Rc[j - 1] - Rp[j - 1]) / (n_k - 1); //计算 R(i,j)
		}

		//输出Rc, R[i,i] 为当前最佳结果
		show_row(i, Rc);

		if (i > 1 && fabs(Rp[i - 1] - Rc[i]) < acc){
			return Rc[i - 1];
		}

		//交换Rn 和 Rc
		d *rt = Rp;
		Rp = Rc;
		Rc = rt;
	}
	return Rp[max_num - 1]; 
}

void main()
{
	d a, b,s;
	printf("输入积分上下限a,b(a为下限，b为上限):");
	scanf("%lf %lf", &a, &b);
	d eps = 1e-5;
	s = Romberg(f, a, b, eps);
	printf("result= %.15f\n", s);

}