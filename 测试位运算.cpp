#include<iostream>
using namespace std;
bool power2(int x)    
	{    
      return ( (x&(x-1))==0) && (x!=0);    
	}    
int main()
{
	//int a = 303;
	//a = a & ~(1 << 2);
	//a = a & (0 << 2);
	//a = a & ((1 << 5)-1);
	//a = a | (1 << 3);
	//a = (a ^ (a+1)) ;
	//cout << a << endl;
	if(power2(7)) cout << 1 << endl;
	else cout << 0 << endl;
	
}