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
    TreeNode* cnt(vector<int>&nums, int low, int high)
    {
        if(low>high)
        {
            return NULL;
        }
        int x=low;
       for(int i=low;i<=high;i++)
       {
           if(nums[x]<nums[i])
           {
               x=i;
           }  
       }
        TreeNode* root = new TreeNode(nums[x]);
        root->left=cnt(nums,low,x-1);
        root->right=cnt(nums,x+1,high);
        return root;
        
    } 
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return cnt(nums,0,nums.size()-1);
    }
};