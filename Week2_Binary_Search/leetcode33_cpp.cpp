/**
Runtime: 4 ms, faster than 93.73% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 8.8 MB, less than 68.85% of C++ online submissions for Search in Rotated Sorted Array.
*/
class Solution {
/**
the rotated sorted array can be viewed as 2 sorted array concatenating together
we just need find which array the target is supposed to be at then apply normal
binary search
*/
public:
    int search(vector<int>& nums, int target){
    int l = 0, h = nums.size();
    int ref;
    while (l < h) {
        int m = l + ((h - l) >> 1);
        ref = ((nums[m] < nums[0]) == (target < nums[0])) // check which array
            ? nums[m] : (target < nums[0] ? -INT_MAX : INT_MAX);
        // if both nums[m] and target has the same comparison relation with respect to
        // nums[0] then we are at the correct array
        // if not we find which array we should be by "cheating"
        if (ref < target){
            l = m + 1;
        }
        else if (ref > target){
            h = m;
        }
        else{
            return m;
        }
    }
    return -1;
}
};
