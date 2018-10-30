#include<iostream>
using namespace std;
int main()
{
	int m,a,b;
	while(1)
	{
		cin >> m;
		if(m==0) break;
		cin >> a >> b ;
		int sum = a + b;
		int res[100];
		int i=0,j;
		while(sum)
		{
			res[i++] = sum % m;
			sum /= m;
		}
		for(j=i-1;j>=0;j--) cout << res[j];
		cout << endl;
	}
}