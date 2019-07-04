"""
Runtime: 64 ms, faster than 93.94% of Python3 online submissions for The Skyline Problem.
Memory Usage: 17 MB, less than 63.93% of Python3 online submissions for The Skyline Problem.
"""

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        res = [[0 , 0]] # start with nothing
        corners = sorted({b[0] for b in buildings} | {b[1] for b in buildings})
        # the final answer will be solely determined by building corners

        heap = [[0 , float('inf')]] # heap[0] = height, heap[1] = ending position
        heapq.heapify(heap)
        idx = 0 # index for buildings

        for x in corners:
            while idx < len(buildings) and x == buildings[idx][0]:
                # current building starts at the previous building end
                heapq.heappush(heap , [-buildings[idx][2] , buildings[idx][1]])
                idx += 1
            while heap[0][1] <= x:
                # tallest building already passed, so pop out
                heapq.heappop(heap)
            if res[-1][1] != -heap[0][0]: # new height
                res.append([x , -heap[0][0]])

        return res[1:]
