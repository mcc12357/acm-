#include<iostream>
using namespace std;
#include<stdio.h>
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
	{
        int i;
		if(!head||k==0||k==1) return head;
		ListNode *l = head;
		ListNode *r = l->next;
		ListNode *newHead = head;
		ListNode *look = head;
		for(i=1;i<=k-1;i++)
		{
			if(!look) break;
			look = look->next;
		}
		if(!look) return newHead;
		look = look->next;
		int num = 0;
		while(l)
		{
			num++;
			for(i=1;i<=k-1;i++) 
			{
				if(r&&i!=k-1)
				{
					ListNode *tmp = r->next;
					r->next = l;
					l = r;
					r = tmp;
				}
				if(r&&i==k-1)
				{
					for(i=1;i<=k-1;i++)
					{
						if(!look) break;
						look = look->next;
					}
					ListNode *tmp = r->next;
					r->next = l;
					if(num==1) newHead = r;
					if(!look) 
					{
						head->next = tmp;
						return newHead;
					}
					head->next = look;
					if(look) look = look->next;
					head = tmp;
					l = head;
					if(head) r = l->next;
				}
			}
		}
		return newHead;

    }
};
int main()
{
	Solution a;
	ListNode *x1 = new ListNode(1);
	ListNode *x2 = new ListNode(2);
	ListNode *x3 = new ListNode(3);
	ListNode *x4 = new ListNode(4);
	ListNode *x5 = new ListNode(5);
	ListNode *x6 = new ListNode(6);
	x1->next = x2;
	x2->next = x3;
	x3->next = x4;
	x4->next = x5;
	x5->next = x6;
	ListNode *res = a.reverseKGroup(x1,2);
	while(res)
	{
		cout<<res->val<<endl;
		res = res->next;
	}

}