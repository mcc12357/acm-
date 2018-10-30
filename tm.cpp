#include <iostream>
#include <vector>
using namespace std;
#include<stdio.h>
#define MY_MAX 220000
int C[MY_MAX];
typedef vector<int> VCT_INT;
vector<VCT_INT> G(MY_MAX/2); //�ڽӱ�
int Lowbit[MY_MAX];
bool HasApple[MY_MAX/2];
int Start[MY_MAX]; //dfsʱ�Ŀ�ʼʱ��
int End[MY_MAX]; //dfsʱ�Ľ���ʱ��
int nCount = 0;
void Dfs(int v)
{
Start[v] = ++ nCount;
for( int i = 0;i < G[v].size();i ++ )
Dfs(G[v][i]);
End[v] = ++ nCount;
}
int QuerySum(int p) //�� sum(p)
{
int nSum = 0;
while( p > 0 ) {
nSum += C[p];
p -= Lowbit[p];
}
return nSum;
}
void Modify( int p,int val)
{
while( p <= nCount ) {
C[p] += val;
p += Lowbit[p];
}
}
int main()
{
int n;
scanf("%d",&n);
int x,y;
int i,j,k;
//��ͼ
for( i = 0;i < n -1 ;i ++ ) {
int a,b;
scanf("%d%d",&a,&b);
G[a].push_back(b); //a�б�����b
}
nCount = 0;
Dfs(1);
//��״����Ҫ�����ԭʼ�����±귶Χ 1 -- nCount
for( i = 1;i <= nCount;i ++) {
Lowbit[i] = i & ( i ^( i - 1));
}
for( i = 1;i <= n;i ++ )
HasApple[i] = 1;
int m;
//��C���飬����״����Ľڵ��ֵ
for( i = 1;i <= nCount;i ++ )
C[i] = i - (i - Lowbit[i]);
// C[i] = Sum[i] - Sum[i-lowbit(i)]
scanf("%d",&m); for( i = 0;i < m;i ++ ) { 
	char cmd[10]; 
	int a; 
	scanf("%s%d",cmd,&a); 
	if( cmd[0] == 'C' ) { 
		if( HasApple[a] ) {
			Modify( Start[a],-1); 
			Modify( End[a],-1); 
			HasApple[a] = 0; } 
		else { 
			Modify( Start[a],1); 
			Modify( End[a],1); 
			HasApple[a] = 1; } } else { 
				int t1 = QuerySum(End[a]); 
				int t2 = QuerySum(Start[a]-1); 
				printf("%d\n",(t1-t2)/2 ); } 
} 
return 0;
}