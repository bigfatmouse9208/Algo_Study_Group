/**
Runtime: 4 ms, faster than 99.24% of C++ online submissions for Maximum Subarray.
Memory Usage: 9.4 MB, less than 20.21% of C++ online submissions for Maximum Subarray.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN , sum = 0;
        for (auto& n : nums){
            sum = (sum < 0) ? n : sum + n;
            ans = max(ans , sum);
        }
        return ans;
    }
};
