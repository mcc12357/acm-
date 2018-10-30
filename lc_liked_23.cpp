#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution 
{
public:
	void merge2Lists(ListNode *p1,ListNode *p2)
	{
		while(p1&&p1->next&&p2)
		{
			while(p1->next && p1->next->val<p2->val) p1 = p1->next;
			ListNode *tmp = new ListNode(p2->val);
			p2 = p2->next;
			tmp->next = p1->next;
			p1->next = tmp;
			p1 = tmp;
		}
		while(p2)
		{
			ListNode *tmp = new ListNode(p2->val);
			p2 = p2->next;
			p1->next = tmp;
			p1 = tmp;
		}
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
        int i;
		if(lists.size()==0) return NULL;
		while(lists.size()>1)
		{
			for(i=0;i<lists.size();i+=2)
			{
				if(i+1<lists.size())
				{
					if(lists[i]&&lists[i+1]) 
					{
						if(lists[i]->val<lists[i+1]->val) 
						{
							merge2Lists(lists[i],lists[i+1]);
							lists.erase(lists.begin()+i+1);
						}
						else 
						{
							merge2Lists(lists[i+1],lists[i]);
							lists.erase(lists.begin()+i);
						}
					}
					else if(lists[i])
					{
						lists.erase(lists.begin()+i+1);
					}
					else if(lists[i+1])
					{
						lists.erase(lists.begin()+i);
					}
					else
					{
						lists.erase(lists.begin()+i);
						lists.erase(lists.begin()+i);
					}
				}
			}
		}
		return lists[0];
    }
};
int main()
{
	Solution a;
	vector<ListNode*> lists;
	/*ListNode *x1 = new ListNode(1);
	ListNode *x2 = new ListNode(0);
	lists.push_back(NULL);
	lists.push_back(NULL);*/
	ListNode *x00 = new ListNode(-1);
	ListNode *x01 = new ListNode(5);
	ListNode *x10 = new ListNode(1);
	ListNode *x11 = new ListNode(4);
	ListNode *x12 = new ListNode(6);
	ListNode *x20 = new ListNode(4);
	ListNode *x21 = new ListNode(5);
	ListNode *x22 = new ListNode(6);
	lists.push_back(NULL);
	lists.push_back(x00);
	lists.push_back(x01);
	lists.push_back(x10);
	lists.push_back(x11);
	lists.push_back(x12);
	lists.push_back(x20);
	lists.push_back(x21);
	lists.push_back(x22);
	ListNode *res = a.mergeKLists(lists);
	while(res)
	{
		cout<<res->val;
		res = res->next;
	}
}