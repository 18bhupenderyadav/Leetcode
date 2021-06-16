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
    struct info{
        int sum;
        int mx;
        int mn;
        int ans;
        bool isbst;
    };
    
    info dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,INT_MIN,INT_MAX,0,1};
        }
        if(root->left==NULL && root->right==NULL)
        {
            return {root->val,root->val,root->val,root->val,1};
        }
        
        info l = dfs(root->left);
        info r = dfs(root->right);
        
        info temp;
        if(l.isbst && r.isbst && root->val>l.mx && root->val<r.mn)
        {
            temp.mx=max(root->val,r.mx);
            temp.mn=min(root->val,l.mn);
            temp.ans=max({l.ans,r.ans,root->val+l.sum+r.sum});
            temp.sum=root->val+l.sum+r.sum;
            temp.isbst=1;
            
            return temp;
        }
        
        temp.mx=max(root->val,r.mx);
        temp.mn=min(root->val,l.mn);
        temp.ans=max(l.ans,r.ans);
        temp.sum=root->val+l.sum+r.sum;
        temp.isbst=0;
        
        return temp;
    }
    
    int maxSumBST(TreeNode* root) {
        return max(0,dfs(root).ans);
    }
};