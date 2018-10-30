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
    void dfs(TreeNode* root,vector<int> &vec)
    {
        if(root->left) dfs(root->left,vec);
        vec.push_back(root->val);
        if(root->right) dfs(root->right,vec);
    } 
    void find(TreeNode* root,TreeNode **lChangeValueNode,int lChangeValue,TreeNode **rChangeValueNode,int rChangeValue)
    {
        if(root->val==lChangeValue) *lChangeValueNode = root;
        if(root->val==rChangeValue) *rChangeValueNode = root;
        if(*lChangeValueNode && *rChangeValueNode) return ;
        if(root->left) find(root->left,lChangeValueNode,lChangeValue,rChangeValueNode,rChangeValue);
        if(root->right) find(root->right,lChangeValueNode,lChangeValue,rChangeValueNode,rChangeValue);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        vector<int> vec;
        vec.clear();
        dfs(root,vec);
        int lChangeValue,rChangeValue;
		int i;
        for(i=1;i<vec.size();i++)
        {
            if(vec[i]<vec[i-1]) 
            {
                lChangeValue = vec[i-1];
                break;
            }
        }
        for(i=vec.size()-2;i>=0;i--)
        {
            if(vec[i]>vec[i+1])
            {
                rChangeValue = vec[i + 1];
                break;
            }
        }
        TreeNode** lChangeValueNode = new TreeNode*(NULL);
        TreeNode** rChangeValueNode = new TreeNode*(NULL);
        find(root,lChangeValueNode,lChangeValue,rChangeValueNode,rChangeValue);
        int tmp;
        tmp = (*lChangeValueNode)->val;
        (*lChangeValueNode)->val = (*rChangeValueNode)->val;
        (*rChangeValueNode)->val = tmp;
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