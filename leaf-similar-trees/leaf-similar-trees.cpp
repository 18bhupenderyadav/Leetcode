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
    void dfs(TreeNode* root,vector<int>& ans)
    {
        if(root!=NULL)
        {
            if(root->left==NULL && root->right==NULL)
            {
                ans.push_back(root->val);
                return;
            }
            dfs(root->left,ans);
            dfs(root->right,ans);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> a,b;
        dfs(root1,a);
        dfs(root2,b);
        if(a==b)
            return true;
        return false;
    }
};