"""
Runtime: 92 ms, faster than 99.81% of Python3 online submissions for Counting Bits.
Memory Usage: 20 MB, less than 5.18% of Python3 online submissions for Counting Bits.
"""

class Solution:
    def countBits(self, num: int) -> List[int]:
        res = list(range(num + 1))

        for n in range(1 , num + 1):
            res[n] = (n & 1) + res[n >> 1]

        return res

"""
Runtime: 100 ms, faster than 98.34% of Python3 online submissions for Counting Bits.
Memory Usage: 20.1 MB, less than 5.18% of Python3 online submissions for Counting Bits.
"""

class Solution:
    def countBits(self, num: int) -> List[int]:
        res = list(range(num + 1))

        for n in range(2 , max(2 , num + 1)):
            res[n] = 1 + res[n & (n - 1)] # n & (n - 1) remove the rightmost set bit

        return res
