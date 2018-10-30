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
	int min(int x,int y){return x<y?x:y;}
	int max(int x,int y){return x>y?x:y;}
    bool dfs(TreeNode* root,int &curmin,int &curmax)
    {
        int lmin,rmin,lmax,rmax;
        bool flagLeft = true,flagRight = true;
        if(root->left) 
        {
            lmin = root->left->val;
            lmax = root->left->val;
            flagLeft = dfs(root->left,lmin,lmax);
            if(root->val<=lmax||!flagLeft) return false;
            curmin = min(curmin,lmin);
            curmax = max(curmax,lmax);
        }
        if(root->right) 
        {
            rmin = root->right->val;
            rmax = root->right->val;
            flagRight = dfs(root->right,rmin,rmax);
            if(root->val>=rmin||!flagRight) return false;
            curmin = min(curmin,rmin);
            curmax = max(curmax,rmax);
        }
        
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return dfs(root,root->val,root->val);
        
    }
};
int main()
{
	TreeNode* root = new TreeNode(10);
	TreeNode* x1 = new TreeNode(5);
	TreeNode* x2 = new TreeNode(15);
	TreeNode* x3 = new TreeNode(6);
	TreeNode* x4 = new TreeNode(20);
	root->left = x1;
	root->right = x2;
	x2->left = x3;
	x2->right = x4;
	Solution a;
	if(a.isValidBST(root)) printf("yes\n");
	else printf("no\n");
	//printf("%d\n",0x7fff);
}