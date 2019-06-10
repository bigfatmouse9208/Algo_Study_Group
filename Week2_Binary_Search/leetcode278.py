"""
Runtime: 32 ms, faster than 94.77% of Python3 online submissions for First Bad Version.
Memory Usage: 13 MB, less than 86.03% of Python3 online submissions for First Bad Version.
"""

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l , h = 1 , n + 1
        while l < h:
            m = l + ((h - l) >> 1)
            if isBadVersion(m):
                h = m
            else:
                l = m + 1
        return l
