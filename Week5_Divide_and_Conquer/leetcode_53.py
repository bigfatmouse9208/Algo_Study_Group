"""
Runtime: 40 ms, faster than 90.59% of Python3 online submissions for Maximum Subarray.
Memory Usage: 13.6 MB, less than 70.22% of Python3 online submissions for Maximum Subarray.
"""

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans , accu_sum = -float('inf') , 0
        for n in nums:
            accu_sum = accu_sum + n if accu_sum >= 0 else n
            ans = max(ans , accu_sum)
        return ans
        
