"""
Runtime: 88 ms, faster than 98.78% of Python3 online submissions for Count of Range Sum.
Memory Usage: 13.5 MB, less than 98.61% of Python3 online submissions for Count of Range Sum.
"""

class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        if not nums:
            return 0
        acc_sum = [0]
        n = len(nums)
        res = 1 if lower <= nums[0] <= upper else 0
        lower, upper = lower - nums[0], upper - nums[0]
        # subtract current number from the lower/upper bound
        last = 0 # last accumulative sum
        for i in range(1 , n):
            last -= nums[i - 1] 
            bisect.insort_left(acc_sum , last)
            lower -= nums[i]
            upper -= nums[i]
            left = bisect.bisect_left(acc_sum , lower)
            right = bisect.bisect_right(acc_sum , upper)
            res += right - left # how many pairs ending at i
        return res
