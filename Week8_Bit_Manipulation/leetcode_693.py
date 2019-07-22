"""
Runtime: 36 ms, faster than 58.78% of Python3 online submissions for Binary Number with Alternating Bits.
Memory Usage: 13.8 MB, less than 5.15% of Python3 online submissions for Binary Number with Alternating Bits.
"""

class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        prev = n & 1
        n >>= 1
        while n:
            if (n & 1) ^ prev:
                prev = n & 1
                n >>= 1
            else:
                return False
        return True

"""
Runtime: 32 ms, faster than 82.80% of Python3 online submissions for Binary Number with Alternating Bits.
Memory Usage: 13.8 MB, less than 5.15% of Python3 online submissions for Binary Number with Alternating Bits.
"""
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        num = bin(n)[2:] # first 2 are always 0b
        for i in range(len(num)-1):
            if num[i] is num[i+1]:
                return False
        return True
