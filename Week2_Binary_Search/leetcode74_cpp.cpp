/**
Runtime: 4 ms, faster than 99.89% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.9 MB, less than 59.58% of C++ online submissions for Search a 2D Matrix.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , x, y;
        if (m == 0){
            return false;
        }
        int n = matrix[0].size();
        if (n == 0){
            return false;
        }
        int l = 0, h = m * n - 1, mid = 0;
        if (h == 0) {
            return (matrix[0][0] == target);
        }
        while (l <= h)
        {
            mid = (l + h) >> 1;
            x = mid / n;
            y = mid % n;
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};
