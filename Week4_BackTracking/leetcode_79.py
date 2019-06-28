"""
Runtime: 208 ms, faster than 87.34% of Python3 online submissions for Word Search.
Memory Usage: 14.2 MB, less than 75.02% of Python3 online submissions for Word Search.
"""

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.res = False
        m , n = len(board) , len(board[0])
        moves = [[0 , 1] , [0 , -1] , [1 , 0] , [-1 , 0]]
        def dfs(x , y , idx):
            if idx == len(word):
                self.res = True
                return
            if self.res:
                return
            for dx , dy in moves:
                nx , ny = x + dx , y + dy
                if 0 <= nx < m and 0 <= ny < n and board[nx][ny] == word[idx]:
                    temp = board[nx][ny]
                    board[nx][ny] = "#"
                    dfs(nx , ny , idx + 1)
                    board[nx][ny] = temp

        for x in range(m):
            for y in range(n):
                if self.res:
                    break
                if board[x][y] == word[0]:
                    temp = board[x][y]
                    board[x][y] = "#"
                    dfs(x , y , 1)
                    board[x][y] = temp

        return self.res
