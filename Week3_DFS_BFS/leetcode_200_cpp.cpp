?**
Runtime: 16 ms, faster than 82.46% of C++ online submissions for Number of Islands.
Memory Usage: 10.6 MB, less than 94.03% of C++ online submissions for Number of Islands.
*/

class Solution {
private:
    const int dx[4] = {1 , -1 , 0 , 0};
    const int dy[4] = {0 , 0 , 1 , -1};
    void dfs(int x , int y , vector<vector<char>>& grid){
        grid[x][y] = '0';
        for (int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i] , ny = y + dy[i];
            if ((0 <= nx && nx < grid.size()) && (0 <= ny && ny < grid[0].size())
               && (grid[nx][ny] == '1')){
                dfs(nx , ny , grid);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0 ; i < grid.size() ; ++i){
            for (int j = 0 ; j < grid[0].size() ; ++j){
                if (grid[i][j] == '1'){
                    dfs(i , j , grid);
                    count++;
                }
            }
        }
        return count;
    }
};
