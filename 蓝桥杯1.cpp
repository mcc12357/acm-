#include<iostream>
using namespace std;
int main()
{
	int f1 = 1,f2 = 1,f3;
	int i;
	int n;
	cin >> n;
	if(n==1 || n==2) cout << f1 << endl;
	else
	{
		for(i=3;i<=n;i++)
		{
			f3 = (f1 + f2)%10007;
			f1 = f2;
			f2 = f3;
		}
		cout << f3 << endl;
	}
}