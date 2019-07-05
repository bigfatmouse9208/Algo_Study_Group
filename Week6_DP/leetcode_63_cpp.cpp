/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
Memory Usage: 9.4 MB, less than 13.41% of C++ online submissions for Unique Paths II.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<long>>dp (m , vector<long> (n , 0));
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        for (int x = 0 ; x < m ; ++x){
            for (int y = 0 ; y < n ; ++y){
                if (x == 0 && y == 0){
                    continue;
                }
                if (x == 0){
                    dp[x][y] = (obstacleGrid[x][y] == 0) ? dp[x][y - 1] : 0;
                }
                else {if(y == 0){
                    dp[x][y] = (obstacleGrid[x][y] == 0) ? dp[x - 1][y] : 0;
                }
                else{
                    dp[x][y] = (obstacleGrid[x][y] == 0) ? dp[x][y - 1] + dp[x - 1][y] : 0;
                }
                     }
            }
        }
        return dp[m - 1][n - 1];
    }
};
