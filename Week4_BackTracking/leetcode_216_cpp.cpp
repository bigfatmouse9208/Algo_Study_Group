/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum III.
Memory Usage: 8.8 MB, less than 31.54% of C++ online submissions for Combination Sum III.
*/

class Solution {
private:
    void dfs(vector<int> path , int target , int start , int k , vector<vector<int>>& res){
        if (path.size() == k){
            if (!target){
                res.push_back(path);
            }
            return;
        }
        for (int i = start ; i < 9 ; ++i){
            if (pool[i] > target){
                return;
            }
            path.push_back(pool[i]);
            dfs(path , target - pool[i] , i + 1 , k , res);
            path.pop_back();
        }
        return;
    }
public:
    vector<int> pool = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path ({});
        dfs(path , n , 0 , k , res);
        return res;
    }
};
