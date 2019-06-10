/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
Memory Usage: 8.2 MB, less than 24.27% of C++ online submissions for First Bad Version.
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0 , h = n, m; // to prevent overflow
        while (l < h){
            m = l + ((h - l) >> 1);
            m++; // add 1 to match the 1-indexed n
            if (isBadVersion(m)){
                h = m - 1;
            }
            else{
                l = m;
            }
        }
        return l + 1; //add 1 to match the 1-indexed n
    }
};
