#include<iostream>
#include<cstdlib>
using namespace std;
//typedef int DataType;
//struct ListNode;
//typedef ListNode* PListLink;
struct ListNode
{
	int data;
	ListNode* link;
};
void find( ListNode* plist)
{
	if(plist->link==NULL) cout<<(plist->data)<<endl;
	else find(plist->link);
}
int main()
{
	ListNode *a,*b;
	a=(ListNode *)malloc(sizeof(ListNode));
	b=(ListNode *)malloc(sizeof(ListNode));//�������������仰���������ṹ��ָ�룬��ϵͳ��û��Ϊ�����ռ䣬��Ҫ�Լ����ٿռ�
	a->data=1;
	a->link=b;
	b->data=2;
	b->link=NULL;
	find(a);
}