/**
Runtime: 12 ms, faster than 80.05% of C++ online submissions for Jump Game II.
Memory Usage: 10 MB, less than 76.41% of C++ online submissions for Jump Game II.
*/

class Solution {
private:
    bool all_one(vector<int>& nums){
        for (auto& n : nums){
            if (n != 1){
                return false;
            }
        }
        return true;
    }
public:
    int jump(vector<int>& nums) {
        int end = nums.size() - 1;
        if (all_one(nums)){ // all-1
            return nums.size() - 1;
        }
        int jumps = 0;
        while (end > 0){
            for (int i = 0 ; i < end ; ++i){
                if (i + nums[i] >= end){
                    jumps++;
                    end = i;
                    cout << jumps << " " << end << endl;
                    break;
                }
            }
        }
        return jumps;
    }
};
