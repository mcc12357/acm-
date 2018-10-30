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
    TreeNode* l_change_node;
    TreeNode* r_change_node;
    TreeNode* MostLeftNode(TreeNode *root)
    {
        TreeNode *p = root;
        while(p->left) p = p->left;
        return p;
    }
    TreeNode* MostRightNode(TreeNode *root)
    {
        TreeNode *p = root;
        while(p->right) p = p->right;
        return p;
    }
    void FindLNode(TreeNode* root)
    {
        if(l_change_node) return ;
        if(root->left) 
        {
            FindLNode(root->left);
			if(l_change_node) return ;
            //compute most right node of left tree
            TreeNode* most_right_node = MostRightNode(root->left);
            if(most_right_node->val > root->val) {l_change_node = most_right_node;return ;}
        }
        if(root->right && !l_change_node)
        {
			if(l_change_node) return ;
            //compute most left node of right tree
            TreeNode* most_left_node = MostLeftNode(root->right);
            if(root->val > most_left_node->val) {l_change_node = root;return ;}
			if(l_change_node) return ;
            FindLNode(root->right);
        }
    }
    void FindRNode(TreeNode* root)
    {
        if(r_change_node) return ;
        if(root->right && !r_change_node) 
        {
			if(r_change_node) return ;
            FindRNode(root->right);
			if(r_change_node) return ;
            TreeNode* most_left_node = MostLeftNode(root->right);
            if(root->val > most_left_node->val) {r_change_node = most_left_node;return ;}
        }
        if(root->left && !r_change_node)
        {
			if(r_change_node) return ;
            TreeNode* most_right_node = MostRightNode(root->left);
            if(most_right_node->val > root->val) {r_change_node = root;return ;}
			if(r_change_node) return ;
			FindRNode(root->left);
        }
    }
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        //find l_change_node by pre-order DFS
		l_change_node = NULL;
        FindLNode(root);
        //find r_change_node by post-order DFS
		r_change_node = NULL;
        FindRNode(root);
        //change these two nodes' values
        int tmp = l_change_node->val;
        l_change_node->val = r_change_node->val;
        r_change_node->val = tmp;
        return ;
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
	TreeNode *root = new TreeNode(1);
	TreeNode *x1 = new TreeNode(3);
	TreeNode *x2 = new TreeNode(2);
	root->left = x1;
	x1->right = x2;
	a.recoverTree(root);
	show(root);
}
