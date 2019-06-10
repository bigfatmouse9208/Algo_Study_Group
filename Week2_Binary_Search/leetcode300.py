"""
Runtime: 32 ms, faster than 99.21% of Python3 online submissions for Longest Increasing Subsequence.
Memory Usage: 13.2 MB, less than 78.07% of Python3 online submissions for Longest Increasing Subsequence.
"""
import bisect # import the python binary search package
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0

        seq = [nums[0]] # the longest increasubg subsequence

        for n in nums[1:]:
            if n > seq[-1]: # largest number so far
                seq.append(n)
            else:
                idx = bisect.bisect_left(seq , n)
                seq[idx] = n # replace the current number with a smaller one

        return len(seq)
