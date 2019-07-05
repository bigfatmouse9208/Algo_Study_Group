/**
Runtime: 8 ms, faster than 92.50% of C++ online submissions for Minimum Path Sum.
Memory Usage: 10.4 MB, less than 90.15% of C++ online submissions for Minimum Path Sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 1 ; i < grid.size() ; ++i){
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1 ; j < grid[0].size() ; ++j){
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1 ; i < grid.size() ; ++i){
            for (int j = 1 ; j < grid[0].size() ; ++j){
                grid[i][j] += min(grid[i - 1][j] , grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
