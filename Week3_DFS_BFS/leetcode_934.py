"""
Runtime: 144 ms, faster than 87.40% of Python3 online submissions for Shortest Bridge.
Memory Usage: 17.8 MB, less than 14.23% of Python3 online submissions for Shortest Bridge.
"""
from collections import deque
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        m , n= len(A) , len(A[0])
        boundary , new_boundary = deque([]) , deque([])
        visited = set()
        moves = [[1 , 0] , [-1 , 0] , [0 , 1] , [0 , -1]]
        d = 0

        def dfs(x , y): # find boundary of one island
            count = 0
            for dx , dy in moves:
                nx , ny = x + dx , y + dy
                if (nx , ny) not in visited and 0 <= nx < m and 0 <= ny < n:
                    if A[nx][ny]:
                        visited.add((nx , ny))
                        count += 1
                        dfs(nx , ny)
            if count != 4:
                boundary.append((x , y))

        flag = False
        for x in range(m):
            if flag:
                break
            for y in range(n):
                if A[x][y]:
                    visited.add((x , y))
                    dfs(x , y)
                    flag = True
                    break

        while boundary: # bfs to find the shortest path
            x , y = boundary.popleft()
            for dx , dy in moves:
                nx , ny = x + dx , y + dy
                if (nx , ny) not in visited and 0 <= nx < m and 0 <= ny < n:
                    if A[nx][ny]:
                        return d
                    visited.add((nx , ny))
                    new_boundary.append((nx , ny))
            if not boundary:
                boundary , new_boundary = new_boundary , deque([])
                d += 1

        return -1
