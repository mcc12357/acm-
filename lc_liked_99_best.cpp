#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* wrong1;
    TreeNode* wrong2;
    TreeNode* pre_max;
    void FindWrongNode(TreeNode* root)
    {
        if(root->left) FindWrongNode(root->left);
        if(pre_max)
        {
            if(pre_max->val > root->val)
            {
				wrong2 = root;
                if(!wrong1) wrong1 = pre_max;
            }
        }
        pre_max = root;
        if(root->right) FindWrongNode(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        wrong1 = wrong2 = pre_max = NULL;
        FindWrongNode(root);
        swap(wrong1->val,wrong2->val);
    }
};

void show(TreeNode *root)
{
	if(root->left) show(root->left);
	printf("%d\n",root->val);
	if(root->right) show(root->right);
}
int main()
{
	Solution a;
	TreeNode* root = new TreeNode(3);
	TreeNode* x1 = new TreeNode(1);
	TreeNode* x2 = new TreeNode(4);
	TreeNode* x3 = new TreeNode(2);
	root->left = x1;
	root->right = x2;
	x2->left = x3;
	a.recoverTree(root);
	show(root);
}
