"""
Runtime: 48 ms, faster than 92.75% of Python3 online submissions for Find Bottom Left Tree Value.
Memory Usage: 15.5 MB, less than 85.77% of Python3 online submissions for Find Bottom Left Tree Value.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        self.ans = root.val
        q = [root]

        while q:
            nq = []
            for node in q:
                if node.left:
                    nq.append(node.left)
                if node.right:
                    nq.append(node.right)
            if nq:
                self.ans = nq[0].val
                q = nq
            else:
                return self.ans

        return self.ans
