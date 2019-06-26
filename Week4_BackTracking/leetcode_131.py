"""
Runtime: 72 ms, faster than 99.57% of Python3 online submissions for Palindrome Partitioning.
Memory Usage: 14.6 MB, less than 15.18% of Python3 online submissions for Palindrome Partitioning.
"""

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        cache = {0 : [[]] , 1 : [[s[0]]]} # dp , cache[i] = all paritions for s[:i]
        for i in range(1 , len(s)):
            cache[i + 1] = []
            for j in range(i + 1):
                sub_palindrome = s[j : i + 1]
                if sub_palindrome == sub_palindrome[::-1]:
                    for line in cache[j]:
                        cache[i + 1].append(line + [sub_palindrome])

        return cache[len(s)]
