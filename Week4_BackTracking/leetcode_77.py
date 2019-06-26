"""
Runtime: 148 ms, faster than 71.74% of Python3 online submissions for Combinations.
Memory Usage: 15 MB, less than 59.82% of Python3 online submissions for Combinations.
"""

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        def dfs(path , start):
            if len(path) == k:
                res.append(path)
                return
            if k - len(path) > n + 1 - start:
                return
            for i in range(start , n + 1):
                dfs(path + [i] , i + 1)

        dfs([] , 1)
        return res
