/**
Runtime: 4 ms, faster than 93.01% of C++ online submissions for Sqrt(x).
Memory Usage: 8.4 MB, less than 47.20% of C++ online submissions for Sqrt(x).
*/

class Solution {
/**
Mathematical solution: Newton's method for solving equation y^2 = x -> f(y) = y^2 - x
f'(y) = 2y
y_n+1 = y_n - (f(y_n) / f'(y_n)) = (y_n + (x / y_n))/2
*/
public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x){
            r = (r + (x / r)) >> 1;
        }
        return r;
    }
};
