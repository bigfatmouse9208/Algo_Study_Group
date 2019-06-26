"""
Runtime: 44 ms, faster than 97.04% of Python3 online submissions for Valid Palindrome.
Memory Usage: 14.5 MB, less than 27.01% of Python3 online submissions for Valid Palindrome.
"""

import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = re.sub('\W+', '', s.lower()) # \W matches any non-alphanumeric characters
        # + matches one or more preceding regular expression
        return True if t == t[::-1] else False
