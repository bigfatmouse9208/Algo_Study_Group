/**
Runtime: 4 ms, faster than 98.83% of C++ online submissions for N-Queens.
Memory Usage: 10 MB, less than 75.78% of C++ online submissions for N-Queens.
*/

class Solution {
private:
    bitset<30> cols , diag1 , diag2;
    void dfs(int r , int n , vector<string>& board , vector<vector<string>>& res){
        if (r == n){
            res.push_back(board);
            return;
        }
        for (int c = 0 ; c < n ; ++c){
            if ( cols[c] || diag1[c + r] || diag2[c - r] ){
                continue;
            }
            cols[c] = 1;
            diag1[c + r] = 1;
            diag2[c - r] = 1;
            board.push_back(string(c , '.') + "Q" + string(n - c - 1 , '.'));
            dfs(r + 1 , n , board , res);
            board.pop_back();
            diag2[c - r] = 0;
            diag1[c + r] = 0;
            cols[c] = 0;
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        vector<vector<string>> res;
        dfs(0 , n , board , res);
        return res;
    }
};
