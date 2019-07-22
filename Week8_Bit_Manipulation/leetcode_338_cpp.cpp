/**
Runtime: 52 ms, faster than 92.67% of C++ online submissions for Counting Bits.
Memory Usage: 9.5 MB, less than 73.65% of C++ online submissions for Counting Bits.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> numBits(num + 1, 0);
        for(int i = 1; i <= num; i++)
            numBits[i] = (i & 1) + numBits[i / 2];
        return numBits;
    }
};
