//给n个数，可以求出每k个数的最大值或是最小值。下面程序是求最大值，最小值只要改下不等号
#include<iostream>
using namespace std;
#include<queue>
struct node
{
	int val;
	int index;
};
void getmax(int *numsequence,int len,int *result,int k)
{
	node *que = new node[len];
	int head = 0;
	int end = 0;
	int i;
	for(i=0;i<len;i++)
	{
		node tmp;
		tmp.val = numsequence[i];
		tmp.index = i;
		while(end!=0 && que[end].val<= numsequence[i]) end--;
		end++;
		que[end] = tmp;
		while(end!=0 && que[head].index<i-k+1) head++;
		result[i] = que[head].val;

	}
	delete []que;
}
int main()
{
	int len,k;
	cin >> len >> k;
	int *numsequence = new int[len];
	int *maxresult = new int[len];
	int i;
	for(i=0;i<len;i++) cin >> numsequence[i];
	getmax(numsequence,len,maxresult,k);
	for(i=k-1;i<len;i++)  
        cout<<i<<": "<<maxresult[i]<<endl;  
    delete[]numsequence;  
    delete[]maxresult;  
    numsequence = NULL;  
    maxresult = NULL;  
    return 0;  
}
