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
    int ans;
    int dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            return -1005;
        } 

        int l = dfs(root->left);
        int r = dfs(root->right);
        int curr = root->val;
        curr = max(curr,root->val+l);
        curr = max(curr,root->val+r);
        ans = max({ans,curr,root->val+l+r});
        return curr;
    }

    int maxPathSum(TreeNode* root) 
    {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};