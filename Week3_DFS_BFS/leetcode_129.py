"""
top-down method
Runtime: 32 ms, faster than 97.25% of Python3 online submissions for Sum Root to Leaf Numbers.
Memory Usage: 13.1 MB, less than 70.81% of Python3 online submissions for Sum Root to Leaf Numbers.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        self.ans = 0
        def dfs(node , cur):
            cur = cur * 10 + node.val
            if not node.left and not node.right:
                self.ans += cur
                return
            if node.left:
                dfs(node.left, cur)
            if node.right:
                dfs(node.right, cur)
        dfs(root, 0)
        return self.ans


"""
bottom-up method
Runtime: 36 ms, faster than 89.52% of Python3 online submissions for Sum Root to Leaf Numbers.
Memory Usage: 13.2 MB, less than 54.03% of Python3 online submissions for Sum Root to Leaf Numbers.
"""

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        def helper(node):
            if not node:
                return ['']
            if not node.left and not node.right:
                return [str(node.val)]
            res = []
            if node.left:
                l = helper(node.left)
                res = [str(node.val) + e for e in l]
            if node.right:
                r = helper(node.right)
                res += [str(node.val) + e for e in r]
            return res
        return sum(int(e) for e in helper(root))
