"""
Runtime: 28 ms, faster than 99.68% of Python3 online submissions for Search a 2D Matrix.
Memory Usage: 14.2 MB, less than 7.39% of Python3 online submissions for Search a 2D Matrix.
"""

import bisect
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        m , n = len(matrix) , len(matrix[0])
        heads = [row[0] for row in matrix]
        idx = bisect.bisect_left(heads , target)
        if idx < m and heads[idx] == target:
            return True
        if idx > 0:
            i = bisect.bisect_left(matrix[idx - 1] , target)
            return i < n and matrix[idx - 1][i] == target
        return False
