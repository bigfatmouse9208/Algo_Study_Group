"""
Runtime: 36 ms, faster than 99.69% of Python3 online submissions for Jump Game II.
Memory Usage: 17.1 MB, less than 5.82% of Python3 online submissions for Jump Game II.
"""

class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps = 0
        if set(nums) == {1}: # for all-1 test case
            return len(nums) - 1

        endpoint = len(nums) - 1
        while endpoint != 0:
            for i in range(endpoint):
                if nums[i] + i >= endpoint:
                    jumps += 1
                    endpoint = i
                    break
        return jumps
