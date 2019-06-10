/**
Runtime: 4 ms, faster than 96.83% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 8.6 MB, less than 66.04% of C++ online submissions for Longest Increasing Subsequence.
*/

public:
    int lengthOfLIS(vector<int>& nums) {
        if (not nums.size()){
            return 0;
        }
        vector<int> seq ({nums[0]});
        for (int i = 1 ; i < nums.size() ; ++i){
            if (nums[i] > seq.back()){
                seq.push_back(nums[i]);
            }
            else{
                auto pos = lower_bound(seq.begin() , seq.end() , nums[i]);
                seq[pos - seq.begin()] = nums[i];
            }
        }
        return seq.size();
    }
};
