/**
Runtime: 184 ms, faster than 89.99% of C++ online submissions for 01 Matrix.
Memory Usage: 22.4 MB, less than 72.92% of C++ online submissions for 01 Matrix.
*/

class Solution {
public:
    bool is_further(int x , int y , int d , vector<vector<int>>& matrix){
        if ((x == 0 or matrix[x - 1][y] >= d) &&
           (x == matrix.size() - 1 or matrix[x + 1][y] >= d) &&
           (y == 0 or matrix[x][y - 1] >= d) &&
           (y == matrix[0].size() - 1 or matrix[x][y + 1] >= d)){
            return true;
        }
        return false;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0){
            return matrix;
        }
        int N = matrix[0].size();
        queue<int> q;
        int d = 1;

        for (int i = 0 ; i < M ; ++i){
            for (int j = 0 ; j < N ; ++j){
                if (matrix[i][j]){
                    q.push(i);
                    q.push(j);
                }
            }
        }

        while (!q.empty()){
            for (int n = q.size()/2 ; n > 0 ; n--){
                int x = q.front();
                q.pop();
                int y = q.front();
                q.pop();
                if (is_further(x , y , d , matrix)){
                    matrix[x][y] = d + 1;
                    q.push(x);
                    q.push(y);
                }
            }
            d++;
        }

        return matrix;
    }
};
