# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
Runtime: 32 ms, faster than 97.84% of Python3 online submissions for Minimum Distance Between BST Nodes.
Memory Usage: 13.1 MB, less than 76.29% of Python3 online submissions for Minimum Distance Between BST Nodes.
"""

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        self.min = float('inf')
        self.dfs(root)
        return self.min

    def dfs(self , node): # return the smallest and largest value of the subtree rooted at node
        if not node:
            return
        smallest = biggest = node.val
        if node.left:
            smallest , left = self.dfs(node.left)
            self.min = min(self.min , node.val - left) # update
        if node.right:
            right , biggest = self.dfs(node.right)
            self.min = min(self.min , right - node.val) # update
        return (smallest , biggest)
