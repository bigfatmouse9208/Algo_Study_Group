/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths III.
Memory Usage: 8.5 MB, less than 83.05% of C++ online submissions for Unique Paths III.
*/

class Solution {
private:
    int res = 0 , remaining = 1;
    int sx , sy , ex , ey , m , n;
    const int dx[4] = {1 , -1 , 0 , 0};
    const int dy[4] = {0 , 0 , 1 , -1};

    void initialize(vector<vector<int>>& grid){
        m = grid.size();
        n = grid[0].size();
        for (int x = 0 ; x < m ; x++){
            for (int y = 0 ; y < n ; y++){
                if (grid[x][y] == 0){
                    remaining++;
                }
                else{
                    if (grid[x][y] == 1){
                        sx = x;
                        sy = y;
                    }
                    else if(grid[x][y] == 2){
                        ex = x;
                        ey = y;
                    }
                }
            }
        }
        return;
    }

    void dfs(int x , int y , int remaining , vector<vector<int>>& grid){
        if (x == ex && y == ey){
            res += (remaining == 0) ? 1 : 0;
            return;
        }
        if (!((0 <= x && x < m) && (0 <= y && y < n) && (grid[x][y] >= 0))){
            return;
        }
        grid[x][y] = -1;
        for (int i = 0 ; i < 4 ; i++){
            dfs(x + dx[i] , y + dy[i] , remaining - 1 , grid);
        }
        grid[x][y] = 0;
        return;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        initialize(grid);
        dfs(sx , sy , remaining , grid);
        return res;
    }
};
