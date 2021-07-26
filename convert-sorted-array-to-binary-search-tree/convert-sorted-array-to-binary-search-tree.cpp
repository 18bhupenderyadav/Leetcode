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
    TreeNode* bst(vector<int>& ar,int st,int end)
    {
        if(st>end)
            return NULL;
        
        int mid=(st+end+1)/2;
        TreeNode* temp=new TreeNode;
        temp->val=ar[mid];
        temp->left=bst(ar,st,mid-1);
        temp->right=bst(ar,mid+1,end);
        
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums,0,nums.size()-1);
    }
};