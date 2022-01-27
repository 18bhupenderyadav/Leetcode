# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        
        def dfs(root,value):
            if(root):
                value*=2
                value+=root.val
                dfs(root.left,value)
                dfs(root.right,value)
                if(not root.left and not root.right):
                    self.ans+=value

        self.ans=0
        dfs(root,0)
        return self.ans
            
        