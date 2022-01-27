# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        
        
        def dfs(root,level):
            if(root):
                if(level>self.mxlevel):
                    self.mxlevel=level
                    self.ans=root.val
                
                dfs(root.left,level+1)
                dfs(root.right,level+1)
                
        
        self.ans=0
        self.mxlevel=0
        dfs(root,1)
        return self.ans