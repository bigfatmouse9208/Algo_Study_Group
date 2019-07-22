"""
Runtime: 56 ms, faster than 64.86% of Python3 online submissions for Partition to K Equal Sum Subsets.
Memory Usage: 13.3 MB, less than 35.20% of Python3 online submissions for Partition to K Equal Sum Subsets.
"""
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        self.nums = nums
        self.nums.sort(reverse = True)
        self.k = k
        self.buckets = [0] * k

        if k == 1:
            return True
        if len(nums) < k:
            return False
        S = sum(nums)
        if S % k:
            return False
        self.target = S / k
        return self.put(0)

    def put(self , idx): # return whether possible to put nums[idx:] into buckets
        for i in range(self.k):
            if self.buckets[i] + self.nums[idx] > self.target: # too large
                continue
            if idx == len(self.nums) - 1: # reach the end and put everything in
                return True
            self.buckets[i] += self.nums[idx]
            if self.put(idx + 1): # means we can put nums[idx:]
                return True
            else:
                self.buckets[i] -= self.nums[idx]
                if self.buckets[i] == 0:
                    return False
        return False
