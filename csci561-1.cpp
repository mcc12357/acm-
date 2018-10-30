
/*#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
int n, ans;
int limit;
 
void dfs( int h, int r, int l ) {
    if ( h == limit ) {  //说明n列都站满了
        ans++;
        return;
    }
    int pos = limit & (~(h|r|l)), p; //pos的二进制位0的，并且这个limit不能省，limit保证了pos高于n的位为0
    while ( pos ) {
        p = pos & (-pos); //这个运算，即原码和补码取与的运算，可以得出最右边的1；
        pos -= p;
        dfs( h+p, (r+p)<<1, (l+p)>>1 );
    }
}
int main()
{
    while ( scanf("%d", &n) != EOF && n ) {
        ans = 0;
        limit = ( 1<<n ) - 1; //limit的二进制是n个1；
        //cout << limit << endl;
        dfs( 0, 0, 0 );
        printf("%d\n", ans);
    }
}*/
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include "time.h"  
class Solution 
{
public:
    int res;
    void dfs(int x,int column,int cnt1,int cnt2,int n)
    {
        if(x==n-1)
        {
            res++;
            return;
        }
        int i;
        for(i=0;i<n;i++)//put current queen in column i
        {
            if( !((1<<i)&column) && !((1<<(x+1+i))&cnt1) && !((1<<(n-2-x+i))&cnt2) )
            {
                column |= (1<<i);
                cnt1 |= (1<<(x+1+i));
                cnt2 |= (1<<(n-2-x+i));
                dfs(x+1,column,cnt1,cnt2,n);
                column &= ~(1<<i);
                cnt1 &= ~(1<<(x+1+i));
                cnt2 &= ~(1<<(n-2-x+i));
            }
        }
    }
    int totalNQueens(int n) 
    {
        res = 0;
        int column = 0,cnt1 = 0,cnt2 = 0;
        int i;
        for(i=0;i<n;i++)
        {
            column |= (1<<i);
            cnt1 |= (1<<i);
            cnt2 |= (1<<(n-1+i));
            dfs(0,column,cnt1,cnt2,n);
            column &= ~(1<<i);
            cnt1 &= ~(1<<i);
            cnt2 &= ~(1<<(n-1+i));
        }
        return res;
    }
};


int main() {
	
        int n;
		while(cin>>n)
        {
			clock_t start, finish;
			start = clock();
			double  duration; 
			int ret = Solution().totalNQueens(n);
			cout << ret << endl;
			finish = clock();  
			duration = (double)(finish - start) / CLOCKS_PER_SEC;  
			printf( "%f seconds\n", duration ); 
		}
    return 0;
}