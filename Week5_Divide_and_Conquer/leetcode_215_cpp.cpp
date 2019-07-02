/**
Runtime: 4 ms, faster than 99.95% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 9.3 MB, less than 55.11% of C++ online submissions for Kth Largest Element in an Array.
*/

//cheating method

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k--;
        nth_element(nums.begin() , nums.begin() + k ,nums.end() , std::greater{});
        return nums[k];
    }
};

// binary search method
/**
Runtime: 12 ms, faster than 86.66% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 9.4 MB, less than 30.33% of C++ online submissions for Kth Largest Element in an Array.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap (nums.begin() , nums.begin() + k);
        sort(heap.begin() , heap.end());
        for (int i = k ; i < nums.size() ; ++i){
            auto pos = lower_bound(heap.begin() , heap.end() , nums[i]);
            int idx = pos - heap.begin();
            if (idx != 0){
                heap.insert(pos , nums[i]);
                heap.erase(heap.begin());
            }
        }
        return heap.front();
    }
};
