"""
Runtime: 60 ms, faster than 94.91% of Python3 online submissions for N-Queens.
Memory Usage: 13.4 MB, less than 70.44% of Python3 online submissions for N-Queens.
"""

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res , board = [] , []
        cols , diag1 , diag2 = set() , set() , set()

        def dfs(row):
            if row == n:
                res.append(list(board))
                return
            for c in range(n):
                if c not in cols and c + row not in diag1 and c - row not in diag2:
                # c + row/c - row are keys for 2 diagnal lines
                    cols.add(c)
                    diag1.add(c + row)
                    diag2.add(c - row)
                    board.append('.' * c + 'Q' + '.' * (n - c  -1))
                    dfs(row + 1)
                    board.pop()
                    diag2.remove(c - row)
                    diag1.remove(c + row)
                    cols.remove(c)

        dfs(0)
        return res
