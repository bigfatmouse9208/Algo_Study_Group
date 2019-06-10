"""
Runtime: 52 ms, faster than 54.42% of Python3 online submissions for Sqrt(x).
Memory Usage: 13.2 MB, less than 69.04% of Python3 online submissions for Sqrt(x).
"""

class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0: return 0
        if x < 3: return 1
        l , h = 0 , x
        while l < h:
            m = (l + h) >> 1
            ref = m*m
            for n in (l , m , h):
                if n**2 == x:
                    return n
            if ref > x:
                h = m
            else:
                if (l + 1) ** 2 > x:
                    return l
                l = m + 1
        for n in range(l - 1 , x):
            if n**2 <= x and (n + 1)**2 > x:
                return n
