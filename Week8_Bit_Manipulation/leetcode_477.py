"""
Runtime: 476 ms, faster than 50.63% of Python3 online submissions for Total Hamming Distance.
Memory Usage: 15.4 MB, less than 7.23% of Python3 online submissions for Total Hamming Distance.
"""

class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        if not nums:
            return 0
        bin_nums = ["{:032b}".format(n) for n in nums]
        N , n = len(nums) , len(bin_nums[0])
        res = 0

        for i in range(n):
            ones = 0
            for bn in bin_nums:
                ones += (bn[i] == '1')
            res += (N - ones) * ones
        return res
