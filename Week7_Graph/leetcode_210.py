"""
Runtime: 52 ms, faster than 73.46% of Python3 online submissions for Course Schedule II.
Memory Usage: 13.9 MB, less than 98.90% of Python3 online submissions for Course Schedule II.
"""

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0 for _ in range(numCourses)]
        advanced_course = collections.defaultdict(list)

        for c , p in prerequisites:
            indegree[c] += 1
            advanced_course[p].append(c)

        queue = collections.deque([c for c , e in enumerate(indegree) if e == 0])
        res = []

        while queue:
            curr = queue.popleft()
            res.append(curr)
            for c in advanced_course[curr]:
                indegree[c] -= 1
                if indegree[c] == 0:
                    queue.append(c)

        return res if len(res) == numCourses else []
