//这里f()为被积函数，输入a,b为积分上下限，
//eps为计算精度[这里要注意假收敛，一般设小一点好]
#include <iostream>
#include <cmath>
const double pi = 3.141592653;
const double e = 2.71828182845;
#define  eps 1e-5
using namespace std;
double f(double x){
    //return 0.2 + 25 * x - 200 * x * x + 675 * x * x * x - 900 * x * x * x * x + 400 * x * x * x * x * x;
	//return cos(1/x)/x;
	return sin(x);
	//return (10 * pow(e,-x) * sin(2 * pi * x)) * (10 * pow(e,-x) * sin(2 * pi * x));
}//被积函数
double Sn(double a,double b,double n){
    double h=(a+b)/(2*n);
    double sum=0;
    for(int k=1;k<=n;k++){
        sum+=2*f(a+(2*k-1)*h);
        sum+=f(a+2*k*h);
    }
    sum=(sum*2+f(a)-f(b))*h/3;
    return sum;
}//辛普森公式
double Solve(double a,double b){
    int i=1;
    double S1n=Sn(a,b,i);
    double S2n=Sn(a,b,2*i);
    while(fabs(S1n-S2n)>eps){
        cout<<"n = "<<i<<"  S1 = "<<S1n<<"  S2 = "<<S2n<<'\n';
        i++;
        S1n=S2n;
        S2n=Sn(a,b,2*i);
    }
    return S2n;
}
int main(){
    printf("%.15f\n",Solve(0,pi));
}