/**
Runtime: 4 ms, faster than 74.61% of C++ online submissions for Reverse Bits.
Memory Usage: 8.1 MB, less than 51.64% of C++ online submissions for Reverse Bits.
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0 ; i < 16 ; ++i){
            int j = 31 - i;
            if (((n >> i) & 1) != ((n >> j) & 1)){
                n = n ^ ((1 << i) | (1 << j));
            }
        }
        return n;
    }
};
