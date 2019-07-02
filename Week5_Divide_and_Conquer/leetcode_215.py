"""
Runtime: 36 ms, faster than 95.06% of Python3 online submissions for Kth Largest Element in an Array.
Memory Usage: 13.9 MB, less than 18.17% of Python3 online submissions for Kth Largest Element in an Array.
"""

# cheating solution
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k , nums)[-1]

"""
Runtime: 44 ms, faster than 60.58% of Python3 online submissions for Kth Largest Element in an Array.
Memory Usage: 13.5 MB, less than 90.41% of Python3 online submissions for Kth Largest Element in an Array.
"""

# real solution
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        heapq.heapify(heap)
        for n in nums:
            if len(heap) != k:
                heapq.heappush(heap , n)
            else:
                heapq.heappushpop(heap , n)
        return heap[0]
