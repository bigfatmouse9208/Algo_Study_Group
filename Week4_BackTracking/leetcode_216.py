"""
Runtime: 32 ms, faster than 95.75% of Python3 online submissions for Combination Sum III.
Memory Usage: 13.2 MB, less than 43.76% of Python3 online submissions for Combination Sum III.
"""

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        def dfs(path , target , start):
            if len(path) == k:
                if target == 0:
                    res.append(path)
                return
            for i in range(start , 10):
                if i > target:
                    return
                dfs(path + [i] , target - i , i + 1)

        dfs([] , n , 1)
        return res
