/**
Runtime: 8 ms, faster than 91.05% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 13.2 MB, less than 42.35% of C++ online submissions for Longest Palindromic Substring.
*/

class Solution {
private:
    string reverse(string& s){
        string res = s;
        std::reverse(res.begin() , res.end());
        return res;
    }
public:
    string longestPalindrome(string s) {
        if (s.size() < 2 || s == reverse(s)){
            return s;
        }
        int l = s.size() , length = 0 , odd_mid = 0 , even_mid = 0;
        int even_left = 0;

        for (int i = 0 ; i < l - 1 ; ++i){
            if (i - even_left >= 0 and s[i - even_left] == s[i + 1]){
                string substr = s.substr(i - even_left , 2 + even_left);
                if (substr == reverse(substr)){
                    even_mid = i;
                    length = 2 + even_left;
                    even_left += 2;
                }
            }
        }

        int half = (length + 1) >> 1;
        int odd_left = half;

        for (int i = half ; i < l - half ; ++i){
            if (i - odd_left >= 0 and s[i - odd_left] == s[i + half]){
                string substr = s.substr(i - odd_left , 1 + half + odd_left);
                if (substr == reverse(substr)){
                    odd_mid = i;
                    length = 1 + half + odd_left;
                    odd_left += 2;
                }
            }
        }

        if (length % 2){
            return s.substr(odd_mid - odd_left + 2 , length);
        }
        else{
            return s.substr(even_mid - even_left + 2, length);
        }
    }
};
