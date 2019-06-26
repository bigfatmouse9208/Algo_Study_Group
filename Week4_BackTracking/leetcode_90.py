"""
Runtime: 44 ms, faster than 90.93% of Python3 online submissions for Subsets II.
Memory Usage: 13.4 MB, less than 24.02% of Python3 online submissions for Subsets II.
"""

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        nums.sort()
        def dfs(prev , start):
            for i in range(start , len(nums)):
                if i > start and nums[i] == nums[i - 1]:
                    continue
                res.append(prev + [nums[i]])
                dfs(prev + [nums[i]] , i + 1)

        dfs([] , 0)
        return res
