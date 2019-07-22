/**
Runtime: 12 ms, faster than 95.23% of C++ online submissions for Single Number III.
Memory Usage: 9.9 MB, less than 40.66% of C++ online submissions for Single Number III.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for (auto& n : nums){
            temp ^= n;
        }
        int refbit = temp & -temp; // find the rightmost setbit
        int a = 0 , b = 0;

        for (auto& n : nums){
            if (n & refbit){
                a ^= n;
            }
            else{
                b ^= n;
            }
        }

        return {a , b};
    }
};
