/**
Runtime: 8 ms, faster than 91.37% of C++ online submissions for Subsets II.
Memory Usage: 9.3 MB, less than 63.86% of C++ online submissions for Subsets II.
*/

class Solution {
private:
    void dfs(vector<int>& prev , int start , vector<int>& nums , vector<vector<int>>& res){
        res.push_back(prev);
        for (int i = start ; i < nums.size() ; ++i){
            if ((i > start) && (nums[i] == nums[i - 1])){
                continue;
            }
            prev.push_back(nums[i]);
            dfs(prev , i + 1 , nums , res);
            prev.pop_back(); // backtrack
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;
        vector<int> prev ({});
        dfs(prev , 0 , nums , res);
        return res;
    }
};
