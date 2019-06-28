"""
Runtime: 32 ms, faster than 99.91% of Python3 online submissions for N-Queens II.
Memory Usage: 13.1 MB, less than 72.42% of Python3 online submissions for N-Queens II.
"""

class Solution:
    def totalNQueens(self, n: int) -> int:
        self.count = 0
        def dfs(n, row , cols , diag1 , diag2):
            if row == n:
                self.count += 1
                return
            bits = (~(cols | diag1 | diag2)) & ((1 << n) - 1) # possible positions
            while bits:
                p = bits & -bits # find next possible positions
                dfs(n, row + 1 , cols | p, (diag1 | p) << 1 , (diag2 | p) >> 1)
                # modify the invalid positions
                bits = bits & (bits - 1)
                # set the previous possible postions to 0
        dfs(n , 0 , 0 , 0 , 0)
        return self.count
