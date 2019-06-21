"""
Runtime: 68 ms, faster than 91.67% of Python3 online submissions for Number of Islands.
Memory Usage: 13.8 MB, less than 83.40% of Python3 online submissions for Number of Islands.
"""

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        if not any(grid):
            return 0
        m , n= len(grid) , len(grid[0])
        directs = [[1 , 0] , [-1 , 0] , [0 , 1] , [0 , -1]]
        def dfs(x , y):
            grid[x][y] = '0'
            for dx , dy in directs:
                nx , ny = x + dx , y + dy
                if 0<= nx < m and 0 <= ny < n and grid[nx][ny] == '1':
                    dfs(nx , ny)

        for x in range(m):
            for y in range(n):
                if grid[x][y] == '1':
                    dfs(x , y)
                    count += 1

        return count
