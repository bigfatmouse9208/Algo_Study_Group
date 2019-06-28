"""
Runtime: 40 ms, faster than 85.49% of Python3 online submissions for Generate Parentheses.
Memory Usage: 13.7 MB, less than 8.33% of Python3 online submissions for Generate Parentheses.
"""

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def dfs(path , status):
            if status == 0 and len(path) == 2*n:
                res.append(path)
                return
            if status > 2*n - len(path) or status < 0:
                return
            dfs(path + '(' , status + 1)
            dfs(path + ')' , status - 1)

        dfs('' , 0)
        return res
