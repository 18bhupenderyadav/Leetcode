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
    map<pair<TreeNode*,pair<int,int>>,int> memo;
    int dp(TreeNode* root,int cam,int lit)
    {
        if(!root)
            return 0;
        
        if(memo.find({root,{cam,lit}})!=memo.end())
            return memo[{root,{cam,lit}}];
        if(cam)
        {
            return 1 + dp(root->left,0,1) + dp(root->right,0,1);
        }
        if(lit)
        {
            int usecam = 1 + dp(root->left,0,1) + dp(root->right,0,1);
            int nocam = dp(root->left,0,0) + dp(root->right,0,0);
            
            return min(usecam,nocam);
        }
        
        int ans = 1 + dp(root->left,0,1) + dp(root->right,0,1);
        
        if(root->left)
        {
            ans = min(ans, dp(root->left,1,1) + dp(root->right,0,0));
        }
        if(root->right)
        {
            ans = min(ans,dp(root->left,0,0) + dp(root->right,1,1));
        }
        
        return memo[{root,{cam,lit}}]=ans;
    }
    int minCameraCover(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        return dp(root,0,0);

    }
};