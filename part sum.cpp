#include<iostream>
using namespace std;
int a[100],m,k;
bool f(int i,int sum)
{
	if(i==m) return sum==k;
	if(f(i+1,sum)) return true;
	if(f(i+1,sum+a[i])) return true;
	return false;
}
int main()
{
	int i;
	scanf("%d %d",&m,&k);
	for(i=0;i<m;i++) scanf("%d",&a[m]);
	if(f(0,0)) printf("yes\n");
	else printf("no\n");

}