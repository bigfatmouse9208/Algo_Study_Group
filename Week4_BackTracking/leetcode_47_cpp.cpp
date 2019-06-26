/**
Runtime: 24 ms, faster than 82.07% of C++ online submissions for Permutations II.
Memory Usage: 9.9 MB, less than 83.62% of C++ online submissions for Permutations II.
*/

class Solution {
private:
    void helper(vector<int>& path , vector<int>& pool , int l , vector<vector<int>>& res){
        if (path.size() == l){
            res.push_back(path);
            return;
        }
        for (int i = 0 ; i < pool.size() ; ++i){
            if ((i > 0) && (pool[i] == pool[i - 1])){
                continue;
            }
            path.push_back(pool[i]);
            int temp = pool[i];
            pool.erase(pool.begin() + i);
            helper(path , pool , l , res);
            path.pop_back();
            pool.insert(pool.begin() + i , temp);
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;
        vector<int> path ({});
        helper(path , nums , nums.size() , res);
        return res;
    }
};
