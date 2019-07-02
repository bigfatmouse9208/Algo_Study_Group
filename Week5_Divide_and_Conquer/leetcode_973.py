"""
Brute Force
Runtime: 388 ms, faster than 54.06% of Python3 online submissions for K Closest Points to Origin.
Memory Usage: 17.3 MB, less than 48.25% of Python3 online submissions for K Closest Points to Origin.
"""

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        def Euclidean_Distance(point):
            x , y = point
            return x**2 + y**2

        return heapq.nsmallest(K , points , key = Euclidean_Distance)


"""
Using heap
Runtime: 384 ms, faster than 58.38% of Python3 online submissions for K Closest Points to Origin.
Memory Usage: 17.5 MB, less than 34.62% of Python3 online submissions for K Closest Points to Origin.
"""

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        heap = []
        heapq.heapify(heap)

        for x , y in points:
            d = -(x**2 + y**2)
            if len(heap) != K:
                heapq.heappush(heap , [d , x , y])
            else:
                heapq.heappushpop(heap , [d , x , y])
        return [[x , y] for d , x ,y in heap]
