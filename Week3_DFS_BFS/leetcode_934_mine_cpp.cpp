/**
Runtime: 32 ms, faster than 99.61% of C++ online submissions for Shortest Bridge.
Memory Usage: 14.7 MB, less than 69.51% of C++ online submissions for Shortest Bridge.
*/

class Solution {
public:
    const int dx[4] = {1 , -1 , 0 , 0};
    const int dy[4] = {0 , 0 , 1 , -1};
    void dfs(int x , int y , vector<vector<int>>& A , vector<vector<int>>& visited
            , queue<int>& boundary){
        bool flag = false;
        for (int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i] , ny = y + dy[i];
            if ((0 <= nx && nx < A.size()) && (0 <= ny && ny < A.size())){
                if (!visited[nx][ny]){
                    if (!A[nx][ny]){
                        flag = true;
                    }
                    else{
                        visited[nx][ny] = true;
                        dfs(nx , ny , A , visited , boundary);
                    }
                }
            }
        }
        if (flag){
            boundary.push(x);
            boundary.push(y);
        }
        return;
    }

    int shortestBridge(vector<vector<int>>& A) {
        const int N = A.size();
        queue<int> boundary;
        int d = 0;
        vector<vector<int>> visited (N , vector<int> (N , 0));
        for (int i = 0 ; i < N ; ++i){
            if (!boundary.empty()){
                break;
            }
            for (int j = 0 ; j < N ; ++j){
                if(A[i][j]){
                    visited[i][j] = 1;
                    dfs(i , j , A , visited , boundary);
                    break;
                }
            }
        }

        while (!boundary.empty()){
            for (int n = boundary.size()/2 ; n > 0 ; n--){
                int x = boundary.front();
                boundary.pop();
                int y = boundary.front();
                boundary.pop();
                for (int i = 0 ; i < 4 ; ++i){
                    int nx = x + dx[i] , ny = y + dy[i];
                    if ((0 <= nx && nx < A.size()) && (0 <= ny && ny < A.size())){
                        if (!visited[nx][ny]){
                            if (A[nx][ny]){
                                return d;
                            }
                            else{
                                visited[nx][ny] = true;
                                boundary.push(nx);
                                boundary.push(ny);
                            }
                        }
                    }
                }
            }
            d++;
        }
        return 0;
    }
};
