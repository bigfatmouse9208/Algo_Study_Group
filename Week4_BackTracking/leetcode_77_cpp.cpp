/**
Runtime: 84 ms, faster than 67.81% of C++ online submissions for Combinations.
Memory Usage: 11.8 MB, less than 60.02% of C++ online submissions for Combinations.
*/

class Solution {
private:
    void dfs(vector<int>& path , int k , int n , int start , vector<vector<int>>& res){
        if (path.size() == k){
            res.push_back(path);
            return;
        }
            for (int i = start ; i <= n ; ++i){
                path.push_back(i);
                dfs(path , k , n , i + 1 , res);
                path.pop_back();
            }
            return;
        }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path ({});
        dfs(path , k , n , 1 , res);
        return res;
    }
};
