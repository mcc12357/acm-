#include<iostream>
using namespace std;
#include<stdio.h>
//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
	{
        ListNode *l1 = head;
		if(head==NULL) return head;
		ListNode *l2 = head->next;
		if(l2==NULL) return head;
		ListNode *x = new ListNode(l1->val);
		while(l1&&l2)
		{
			/*x->val = l1->val;
			x->next = l2->next; 
		    l1->val = l2->val;
			l2->val = x->val;
			l2->next = l1;
			l1->next = x->next;
			l1 = l2;
			l2 = l2->next;*/
			x->val = l1->val;
			l1->val = l2->val;
			l2->val = x->val;
			if(l2->next&&l2->next->next)
			{
				l1 = l1->next->next;
				l2 = l2->next->next;
			}
			else break;
		}
		return head;
    }
};
int main()
{
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(4);
	ListNode l5(5);
	//ListNode l6(6);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	//l5.next = &l6;
	Solution a;
	ListNode *head = a.swapPairs(&l1);
	while(head)
	{
		cout<<head->val<<endl;
		head = head->next;
	}
}