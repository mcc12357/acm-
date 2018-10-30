#include<iostream>
using namespace std;
#include<stdio.h>
//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        if(p->val==q->val)
        {
            if( ((!p->left&&!q->left)||(p->left&&q->left&&isSameTree(p->left,q->left))) && ((!p->right&&!q->right)||(p->right&&q->right&&isSameTree(p->right,q->right))) ) 
			{
				return true;
			}
        }
        return false;
    }
};
int main()
{
	TreeNode *p = new TreeNode(2);
	TreeNode *q = new TreeNode(2);
	TreeNode *pr = new TreeNode(4);
	TreeNode *ql = new TreeNode(3);
	TreeNode *qr = new TreeNode(4);
	p->right = pr;
	q->left = ql;
	q->right = qr;
	Solution a;
	if(a.isSameTree(p,q)) cout<<"yes"<<endl;

}