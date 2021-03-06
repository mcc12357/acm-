#include<iostream>
using namespace std;
#include<stdio.h>
#define M 50005  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
/*left,right,root,middle*/  
int sum[M<<2]; 
void pushplus(int rt)
{
	sum[rt] = (sum[rt<<1] + sum[rt<<1|1]);
} 
void build(int l,int r,int rt)
{
	if(l==r) 
	{
		scanf("%d",&sum[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushplus(rt);
}
void update(int p,int add,int l,int r,int rt)//p为待更新结点，add为更新量，rt为当前节点，l,r分别为左儿子和右儿子
{
	if(l==r)
	{
		sum[rt] += add;
		return ;
	}
	int m = (l + r) >> 1;
	if(p<=m) update(p,add,lson);
	else update(p,add,rson);
	pushplus(rt);
}
int query(int L,int R,int l,int r,int rt)//L,R为待查找区间，rt为当前节点，l,r为当前节点左儿子和右儿子
{
	if(L<=l && R>=r) return sum[rt];
	int m = (l + r) >> 1;
	int ans = 0;
	if(L<=m) ans += query(L,R,lson);
	if(R>m) ans += query(L,R,rson);
	return ans;
}
int main()  
{     
    int T, n, a, b;  
    scanf("%d",&T);  
    for( int i = 1; i <= T; ++i )  
    {  
        printf("Case %d:\n",i);  
        scanf("%d",&n);  
        build(1,n,1);  
  
        char op[10];  
  
        while( scanf("%s",op) &&op[0]!='E' )  
        {  
  
            scanf("%d %d", &a, &b);  
            if(op[0] == 'Q')  
                printf("%d\n",query(a,b,1,n,1));  
            else if(op[0] == 'S')  
                update(a,-b,1,n,1);  
            else  
                update(a,b,1,n,1);  
  
        }  
    }  
    return 0;  
}  