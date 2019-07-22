"""
Runtime: 72 ms, faster than 11.90% of Python3 online submissions for Single Number III.
Memory Usage: 15.5 MB, less than 5.34% of Python3 online submissions for Single Number III.
"""

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        temp = 0
        for n in nums:
            temp ^= n

        refbit = temp & - temp
        a = b = 0

        for n in nums:
            if n & refbit:
                a ^= n
            else:
                b ^= n

        return [a , b]
