/**
Runtime: 16 ms, faster than 93.91% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 9.6 MB, less than 65.58% of C++ online submissions for Median of Two Sorted Arrays.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size() , l2 = nums2.size();
        if (l1 > l2){
            return findMedianSortedArrays(nums2 , nums1);
        }
        int start = 0 , end = l1;
        while (start <= end){
            int m1 = (start + end) >> 1;
            int m2 = ((l1 + l2 + 1) >> 1) - m1;
            int left1 = (m1 == 0) ? INT_MIN : nums1[m1 - 1];
            int left2 = (m2 == 0) ? INT_MIN : nums2[m2 - 1];
            int right1 = (m1 == l1) ? INT_MAX : nums1[m1];
            int right2 = (m2 == l2) ? INT_MAX : nums2[m2];
            if ((left1 <= right2) && (left2 <= right1)){
                if ((l1 + l2) % 2){
                    return max(left1 , left2);
                }
                else{
                    return (max(left1 , left2) + min(right1 , right2)) / 2.0;
                }
            }
            else if(left1 > right2){
                end = m1 - 1;
            }
            else{
                start = m1 + 1;
            }
        }
        return 0;
    }
};
