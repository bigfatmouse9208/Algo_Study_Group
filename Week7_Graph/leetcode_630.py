"""
Naive intuitive solution by minimizing total duration
Runtime: 144 ms, faster than 95.96% of Python3 online submissions for Course Schedule III.
Memory Usage: 16.7 MB, less than 71.88% of Python3 online submissions for Course Schedule III.
"""

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key = lambda c : c[1])
        end = 0
        heap = []
        heapq.heapify(heap) # durations of courses we choose to take

        for t , d in courses:
            if end + t <= d: # we have time to take the course
                end += t
                heapq.heappush(heap , -t)
            elif heap and -heap[0] > t:
                # we don't have time to take the course, but can take it by skiping a previous course
                end += heap[0] + t
                heapq.heappushpop(heap , -t)

        return len(heap)
