#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
//Definition for a binary tree node.
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	bool ismirror(TreeNode *l,TreeNode *r)
	{
		if(!l&&!r) return true;
		if(!l||!r) return false;
		if(l->val==r->val)
		{
			return ismirror(l->left,r->right)&&ismirror(l->right,r->left);
		}
		return false;
	}
    bool isSymmetric(TreeNode* root) 
	{
		if(!root) return true;
        return ismirror(root,root);
    }
};
int main()
{
	TreeNode *x1 = new TreeNode(1);
	TreeNode *x2 = new TreeNode(2);
	TreeNode *x3 = new TreeNode(3);
	//TreeNode *x4 = new TreeNode(2);
	//TreeNode *x5 = new TreeNode(3);
	x1->left = x2;
	x1->right = x3;
	//x2->left = x3;
	//x4->left = x5;
	Solution a;
	if(a.isSymmetric(x1)) cout<<"yes"<<endl;

}