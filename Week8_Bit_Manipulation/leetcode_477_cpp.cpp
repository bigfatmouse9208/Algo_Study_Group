/**
Runtime: 56 ms, faster than 93.06% of C++ online submissions for Total Hamming Distance.
Memory Usage: 10.2 MB, less than 25.00% of C++ online submissions for Total Hamming Distance.
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0 , N = nums.size();
        for (int i = 0 ; i < 32 ; ++i){
            int ones = 0;
            for (auto& n : nums){
                ones += (n >> i) & 1;
            }
            res += ones * (N - ones);
        }
        return res;
    }
};
