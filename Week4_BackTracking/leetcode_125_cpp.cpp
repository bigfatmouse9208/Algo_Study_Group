/**
Runtime: 8 ms, faster than 92.15% of C++ online submissions for Valid Palindrome.
Memory Usage: 9.3 MB, less than 67.26% of C++ online submissions for Valid Palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0 , j = s.size() - 1;
        while (true){
            while ((i < s.size() - 1) && (!isalnum(s[i]))){
                i++;
            }
            while ((j >= 0) && (!isalnum(s[j]))){
                j--;
            }
            if (i >= j){
                return true;
            }
            if (tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
