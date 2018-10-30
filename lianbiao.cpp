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
	b=(ListNode *)malloc(sizeof(ListNode));//不能少了这两句话，如果定义结构体指针，则系统并没有为其分配空间，需要自己开辟空间
	a->data=1;
	a->link=b;
	b->data=2;
	b->link=NULL;
	find(a);
}