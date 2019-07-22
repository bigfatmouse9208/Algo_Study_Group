"""
Runtime: 164 ms, faster than 80.87% of Python3 online submissions for Strobogrammatic Number II.
Memory Usage: 19.9 MB, less than 81.10% of Python3 online submissions for Strobogrammatic Number II.
"""
class Solution:
    # by add mid_seed into previous shorter strobogrammatic strings, we can create longer strings
    def findStrobogrammatic(self, n):
        cache = {1 : ["0", "1", "8"] , 2 : ["11","69","88","96"]}
        odd_seed = ["0", "1", "8"]
        even_seed = ["11","69","88","96", "00"]
        if n < 3:
            return cache[n]
        if n % 2:
            prev , mid_seed = self.findStrobogrammatic(n-1), odd_seed
        else:
            prev , mid_seed = self.findStrobogrammatic(n-2), even_seed
        mid = (n - 1) >> 1
        return [p[:mid] + c + p[mid:] for c in mid_seed for p in prev]
