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
    // global variable for result
    int res = 0;
    
    void dfs(TreeNode* root, int direction){
        if(root == NULL) return;
        
        // leaf node
        if(root->left == NULL && root->right == NULL){
            
            // left leaf
            if(direction == 0)
                res += root->val;
            
            return;
        }
        
        dfs(root->left, 0); // 0 means left direction
        dfs(root->right, 1); // 1 means right direction
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, -1);
        return res;
    }
};