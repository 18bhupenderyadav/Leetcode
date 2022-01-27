# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        def dfs(root,mx):
            if(root):
                if(root.val>=mx):
                    self.ans+=1
                mx=max(mx,root.val)
                dfs(root.left,mx)
                dfs(root.right,mx)
        
        self.ans=0;
        dfs(root,-10005)
        return self.ans
        