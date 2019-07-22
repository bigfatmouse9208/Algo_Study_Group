/**
Runtime: 4 ms, faster than 69.99% of C++ online submissions for Binary Watch.
Memory Usage: 8.6 MB, less than 66.48% of C++ online submissions for Binary Watch.
*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0 ; h < 12 ; ++h){
            for (int m = 0 ; m < 60 ; ++m){
                if (bitset<10>(h << 6 | m).count() == num){
                    // 10 = 4 + 6; we just need to check how many setbits we have
                    res.push_back(to_string(h) +
                                 (m < 10 ? ":0" : ":") +
                                 to_string(m));
                }
            }
        }
        return res;
    }
};
