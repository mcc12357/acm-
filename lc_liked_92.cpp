#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
		if(m==n) return head;
        ListNode* prem = NULL;
        ListNode* mp;
        ListNode* np;
        ListNode* p = head;
        int i = 1;
        while(p)
        {
            if(i==m-1) prem = p;
            if(i==m) mp = p;
            if(i==n) np = p;
            i++;
            p = p->next;
        }
        p = mp;
        ListNode* q = p->next;
		ListNode* end = np->next;
        if(prem) 
        {
            prem->next = np; 
        }
		prem = mp;
        if(mp) p = mp->next;
        if(p) q = p->next;
        while(q&&q!=end)
        {
            ListNode* tmp = q->next;
            q->next = p;
            p->next = prem;
            prem = p;
            p = q;
            q = tmp;
        }
		p->next = prem;
        mp->next = end;
        if(m>1) return head;
		else return p;
        
    }
};
int main()
{
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	int i;
	int t;
	cin>>t;
	for(i=2;i<=t;i++)
	{
		ListNode *q = new ListNode(i);
		p->next = q;
		p = q;
	}
	int m,n;
	cin>>m>>n;
	Solution a;
	head = a.reverseBetween(head,m,n);
	while(head) 
	{
		cout<<head->val<<endl;
		head = head->next;
	}
}