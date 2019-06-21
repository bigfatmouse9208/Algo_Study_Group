"""
Runtime: 320 ms, faster than 99.83% of Python3 online submissions for 01 Matrix.
Memory Usage: 15.1 MB, less than 87.41% of Python3 online submissions for 01 Matrix.
"""

class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        if not any(matrix):
            return [[]]
        q = [(i , j) for i in range(len(matrix)) for j in range(len(matrix[0])) if matrix[i][j]]
        d = 1

        def is_further(x , y): # return whether x , y is getting further from nearest zero
            if (((y == 0) or matrix[x][y - 1] >= d) and
                ((y == len(matrix[0]) - 1) or matrix[x][y + 1] >= d) and
                ((x == 0) or matrix[x - 1][y] >= d) and
                ((x == len(matrix) - 1) or matrix[x + 1][y] >= d)
               ):
                return True
            return False

        while q:
            nq = []
            for x , y in q:
                if is_further(x , y):
                    nq.append((x , y))
                    matrix[x][y] = d + 1 # we are at least one step further
            q , nq = nq , []
            d += 1
        return matrix
