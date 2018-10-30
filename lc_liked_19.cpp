#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
        ListNode *t = head;
		vector<ListNode*> g;
		while(t)
		{
			g.push_back(t);
			t = t->next;
		}
		if(n==g.size()) return head->next;
		ListNode *front = g[g.size()-n-1];
		if(n==0) return head;
		if(n==1) front->next = NULL;
		else front->next = g[g.size()-n+1];
		return head;
    }
};
int main()
{
	Solution a;
	ListNode t0(1);
	ListNode t1(2);
	ListNode t2(3);
	ListNode t3(4);
	ListNode t4(5);
	t0.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	ListNode *head;
	head = a.removeNthFromEnd(&t0,1);
	while(head)
	{
		cout<<head->val;
		head = head->next;
	}
}