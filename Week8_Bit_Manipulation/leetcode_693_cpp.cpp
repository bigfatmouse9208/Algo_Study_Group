/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Number with Alternating Bits.
Memory Usage: 8.1 MB, less than 39.79% of C++ online submissions for Binary Number with Alternating Bits.
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool prev = n & 1;
        n >>= 1;
        while (n){
            if (prev ^ (n & 1)){
                prev = n & 1;
                n >>= 1;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
