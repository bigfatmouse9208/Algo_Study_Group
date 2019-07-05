"""
Runtime: 32 ms, faster than 96.72% of Python3 online submissions for Unique Paths II.
Memory Usage: 13.3 MB, less than 23.87% of Python3 online submissions for Unique Paths II.
"""

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not any(obstacleGrid):
            return 0
        m , n = len(obstacleGrid) , len(obstacleGrid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]

        for x in range(m):
            for y in range(n):
                if x == y == 0:
                    if obstacleGrid[0][0]:
                        return 0
                    dp[0][0] = 1
                elif x == 0:
                    dp[x][y] = 0 if obstacleGrid[x][y] else dp[x][y - 1]
                elif y == 0:
                    dp[x][y] = 0 if obstacleGrid[x][y] else dp[x - 1][y]
                else:
                    dp[x][y] = 0 if obstacleGrid[x][y] else dp[x - 1][y] + dp[x][y - 1]

        return dp[-1][-1]
