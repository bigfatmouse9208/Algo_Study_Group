"""
Runtime: 72 ms, faster than 81.24% of Python3 online submissions for Permutations II.
Memory Usage: 13.4 MB, less than 46.99% of Python3 online submissions for Permutations II.
"""

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        def helper(path , pool):
            if len(path) == len(nums):
                res.append(path)
                return
            for i , e in enumerate(pool):
                if i > 0 and e == pool[i - 1]:
                    continue
                helper(path + [e] , pool[ : i] + pool[i + 1 :])

        helper([] , nums)
        return res
