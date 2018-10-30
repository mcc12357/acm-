#include<iostream>
using namespace std;
#include<cstdlib>
typedef char Datatype;
typedef BinNode* PBinNode
struct BinNode
{
	Datatype data;
	PBinNode lchild;
	PBinNode rchild;
};
typedef BinNode* BinTree;
void createBinTree(BinTree &t)
{
	Datatype c;
	t=(BinTree)malloc(sizeof BinNode);
	cin>>c;
	if(c=='#') t=NULL;
	else 
	{
		t->data = c;
		createBinTree(t->lchild);
		createBinTree(t->rchild);
	}
}
int main()
{
	BinTree &m;
	createBinTree(m);
}
