"""
Runtime: 16 ms, faster than 86.36% of Python online submissions for Reverse Bits.
Memory Usage: 11.6 MB, less than 86.14% of Python online submissions for Reverse Bits.
"""

class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        for i in range(16):
            j = 31 - i
            if (n >> i) & 1 != (n >> j) & 1: # if different then we swtich 2 bits
                n = n ^ (1 << i | 1 << j) # by just flipping
        return n
