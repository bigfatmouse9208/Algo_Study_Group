"""
Runtime: 40 ms, faster than 55.71% of Python3 online submissions for Special Binary String.
Memory Usage: 13.3 MB, less than 16.38% of Python3 online submissions for Special Binary String.
"""

class Solution:
    def makeLargestSpecial(self, S: str) -> str:
        """
        from the definition of special string, we can prove that each special string is made up of
        several special substring. So if we divide the whole string into as many special substring as possible
        and make each substring the largest, in the end concatenate them together from largerst to smallest
        the problem is solved
        """
        status = 0
        start = 0
        substrings = []
        for i , e in enumerate(S):
            status += 1 if e == '1' else -1
            if status == 0: # means we find a sub-special string
            """
            since S is a speical string, it is guaranteed that once we have equal number of '1' and '0'
            the correponding substring must also be a speical string
            from definition we know a speical string must start with '1' and end with '0'
            hence from the substring[1:-1] is also a substring
            """
                substrings.append('1' + self.makeLargestSpecial(S[start + 1: i]) + '0')
                start = i + 1
        return ''.join(sorted(substrings)[::-1])
