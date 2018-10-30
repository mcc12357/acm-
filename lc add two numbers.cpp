#include<iostream>
using namespace std;
#include<stdio.h>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        //ListNode head(0);
		ListNode* head = new ListNode(0);//�ڶ��η����ִ����ˣ��ṹ��ָ���ʼ��һ��Ҫ��������ռ䣬���ܽ�һ���ṹ�����Ȼ���ýṹ��ָ������������������У�����
        ListNode* s = head;
        while( !(l1==NULL && l2==NULL) )
        {
            int sum = 0;
            if(l1==NULL)
            {
                sum = add + l2->val;
                l2 = l2->next;
            }
            else if(l2==NULL)
            {
                sum = add + l1->val;
                l1 = l1->next;
            }
            else 
            {
                sum = add + l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
			s->val = sum % 10;
			if(sum>=10)
            {
                add = 1;
            }
            else
            {
                add = 0;
            }
            if( !(l1==NULL && l2==NULL && add==0) ) 
			{
				ListNode *tmp = new ListNode(0);
				s->next = tmp;
			}
            s = s->next;
        }
        if(add) 
        {
            s->val = 1;
			s->next = NULL;
        }
        return head;
    }
};
int main()
{
	ListNode a(5);
	ListNode b(5);
	ListNode* l1 = &a;
	ListNode* l2 = &b;
	Solution c;
	ListNode *res = c.addTwoNumbers(l1,l2);
	while(res)
	{
		printf("%d\n",res->val);
		res = res->next;
	}
}
