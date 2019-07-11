"""
Runtime: 64 ms, faster than 62.89% of Python3 online submissions for Unique Paths III.
Memory Usage: 13.2 MB, less than 55.15% of Python3 online submissions for Unique Paths III.
"""

class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        m , n = len(grid) , len(grid[0])
        remaining = 1
        self.res = 0

        for x in range(m):
            for y in range(n):
                if grid[x][y] == 0:
                    remaining += 1
                elif grid[x][y] == 1:
                    sx , sy = x , y
                elif grid[x][y] == 2:
                    ex , ey = x , y

        def dfs(x , y , remaining):
            if x == ex and y == ey:
                self.res += int(remaining == 0)
                return
            if not (0 <= x < m and 0 <= y < n and grid[x][y] >= 0):
                return
            grid[x][y] = -1
            for dx , dy in [[1 , 0] , [-1 , 0] , [0 , 1] , [0 , -1]]:
                dfs(x + dx , y + dy , remaining - 1)
            grid[x][y] = 0

        dfs(sx ,  sy , remaining)
        return self.res
