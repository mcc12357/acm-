#include<iostream>
using namespace std;
int somefunc(int n,int &a)
{
	if(n>0)
	{
		a++;
		int test = somefunc(n-1,a);
		test--;return test;
	}
	else{return 0;}
}
void main()
{
	int nret = 0;
	int nn = 1000000;
	int nresult = somefunc(nn,nret);
	cout<<"nret="<<nret<<endl;
	cout<<"nresult = "<<nresult<<endl;
}
