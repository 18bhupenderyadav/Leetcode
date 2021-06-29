/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL)
            return t2;
        if(t2==NULL)
            return t1;
        t1->val=t1->val+t2->val;
        t1->left=dfs(t1->left,t2->left);
        t1->right=dfs(t1->right,t2->right);
        return t1;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        return dfs(t1,t2);
    }
};