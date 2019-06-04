"""
Runtime: 32 ms, faster than 99.63% of Python3 online submissions for Output Contest Matches.
Memory Usage: 13.6 MB, less than 27.96% of Python3 online submissions for Output Contest Matches.
"""

class Solution:
    def findContestMatch(self, n: int) -> str:
        def helper(matches):
            i , j = 0 , len(matches) - 1
            res = []
            while i < j:
                line = '(' + matches[i] + ',' + matches[j] + ')'
                res.append(line)
                i += 1
                j -= 1
            return res
        matches = [str(x) for x in range(1 , n + 1)]
        while len(matches) != 1:
            matches = helper(matches)
        return matches[0]
