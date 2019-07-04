/**
Runtime: 40 ms, faster than 51.74% of C++ online submissions for Count of Range Sum.
Memory Usage: 10.4 MB, less than 94.97% of C++ online submissions for Count of Range Sum.
*/


// merge_sort solution
class Solution {
private:
    int merge_sort(vector<long long>& accu_sum , int low , int high , int lower , int higher){
        int mid = low + ((high - low) >> 1);
        if (mid == low){
            return 0;
        }
        int count = merge_sort(accu_sum , low , mid , lower , higher) + merge_sort(accu_sum , mid , high , lower , higher);
        int i = mid , j = mid;
        for (int idx = low ; idx < mid ; idx ++){
            while (i < high && accu_sum[i] - accu_sum[idx] < lower){
                i++;
            }
            while (j < high && accu_sum[j] - accu_sum[idx] <= higher){
                j++;
            }
            count += (j - i);
        }
        sort(accu_sum.begin() + low , accu_sum.begin() + high);
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> accu_sum ({0});
        for (auto& n : nums){
            accu_sum.push_back(n + accu_sum.back());
        }
        return merge_sort(accu_sum , 0 , accu_sum.size() , lower , upper);
    }
};
