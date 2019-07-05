"""
Initial Solution
Runtime: 1024 ms, faster than 60.32% of Python3 online submissions for Longest Palindromic Substring.
Memory Usage: 13.1 MB, less than 73.75% of Python3 online submissions for Longest Palindromic Substring.
"""

class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        pos = collections.defaultdict(list)
        dp = [idx for idx in range(len(s))]
        self.longest = 1
        res = s[0]

        for i , c in enumerate(s):
            for j in pos[c]:
                if dp[j + 1] == i - 1 or j == i - 1:
                    dp[j] = i
                    if (i - j + 1) > self.longest:
                        self.longest = i - j + 1
                        res = s[j : i + 1]
            pos[c].append(i)

        return res

"""
Linear Solution
Runtime: 40 ms, faster than 100.00% of Python3 online submissions for Longest Palindromic Substring.
Memory Usage: 13.1 MB, less than 74.78% of Python3 online submissions for Longest Palindromic Substring.
"""
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2 or s == s[::-1]:
            return s

        l , length = len(s) , 1
        even_mid = odd_mid = 0 # mid index of 2 types of palindrome
        even_left = 0

        # search for even palindrome
        for i in range(l - 1):
            if i - even_left >= 0 and s[i - even_left] == s[i + 1]:
                # we are always looking for longer substring
                substring = s[i - even_left : i + 2]
                if substring == substring[::-1]:
                    length = even_left + 2
                    even_left += 2
                    even_mid = i

        half = odd_left = (length + 1) >> 1 # +1 to ensure we get a positive number
        # also we only search for longer substring

        # search for odd palindrome
        for i in range(half , l - half):
            if i - odd_left >= 0 and s[i - odd_left] == s[i + half]:
                # again, we are always looking for longer substring sincer half is not updated
                substring = s[i - odd_left : i + half + 1]
                if substring == substring[::-1]:
                    length = odd_left + half + 1
                    odd_left += 2
                    odd_mid = i

        if length % 2: # odd palindrome
            return s[odd_mid - odd_left + 2 : odd_mid + half + 1]
        else:
            return s[even_mid - even_left + 2 : even_mid + 2]
