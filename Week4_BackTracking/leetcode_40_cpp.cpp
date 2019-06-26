/**
Runtime: 4 ms, faster than 99.62% of C++ online submissions for Combination Sum II.
Memory Usage: 9 MB, less than 74.35% of C++ online submissions for Combination Sum II.
*/

class Solution {
private:
    void dfs(vector<int>& path , int target , vector<int>& candidates , vector<vector<int>>& res , int start){
        if (target == 0){
            res.push_back(path);
            return;
        }
        for (int i = start ; i < candidates.size() ; ++i){
            if (candidates[i] > target){
                return;
            }
            if ((i > start) && (candidates[i] == candidates[i - 1])){
                continue;
            }
            path.push_back(candidates[i]);
            dfs(path , target - candidates[i] , candidates , res , i + 1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> res;
        vector<int> path ({});
        dfs(path , target , candidates , res , 0);
        return res;
    }
};
