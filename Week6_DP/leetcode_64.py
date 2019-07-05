"""
Runtime: 52 ms, faster than 83.39% of Python3 online submissions for Minimum Path Sum.
Memory Usage: 14.5 MB, less than 69.99% of Python3 online submissions for Minimum Path Sum.
"""

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not any(grid):
            return 0

        for i in range(1 , len(grid)):
            grid[i][0] += grid[i - 1][0]

        for j in range(1 , len(grid[0])):
            grid[0][j] += grid[0][j - 1]

        for i in range(1 , len(grid)):
            for j in range(1 , len(grid[0])):
                grid[i][j] += min(grid[i - 1][j] , grid[i][j - 1])

        return grid[-1][-1]
