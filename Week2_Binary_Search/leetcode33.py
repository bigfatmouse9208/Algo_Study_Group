"""
Runtime: 36 ms, faster than 87.54% of Python3 online submissions for Search in Rotated Sorted Array.
Memory Usage: 13.4 MB, less than 12.28% of Python3 online submissions for Search in Rotated Sorted Array.
"""

class Solution:
    """
    the rotated sorted array can be viewed as 2 sorted array concatenating together
    we just need to find which part we are currently at then appply normal binary
    searching
    """
    def search(self, nums: List[int], target: int) -> int:
        l , h = 0 , len(nums)
        while l < h:
            m = l + ((h - l) >> 1)
            if nums[m] == target:
                return m
            ref = nums[m] if ((nums[m] < nums[0]) == (target < nums[0])) \
            # check which array we should be
            else (-float('inf') if target < nums[0] else float('inf'))
            # if not at the correct array, we move to it by "cheating"
            if (ref < target):
                l = m + 1
            else:
                h = m
        return -1
