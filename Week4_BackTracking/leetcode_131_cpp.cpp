/**
Runtime: 36 ms, faster than 62.65% of C++ online submissions for Palindrome Partitioning.
Memory Usage: 18.4 MB, less than 62.56% of C++ online submissions for Palindrome Partitioning.
*/

class Solution {
private:
    bool is_palindrome(string s){
        int i = 0 , j = s.size() - 1;
        while (i < j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void dfs(vector<string>& path , string& s , int start , vector<vector<string>>& res){
        if (start == s.size()){
            res.push_back(path);
            return;
        }
        for (int i = start ; i < s.size() ; ++i){
            if (is_palindrome(s.substr(start , i - start + 1))){
                path.push_back(s.substr(start , i - start + 1));
                dfs(path , s , i + 1 , res);
                path.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path ({});
        dfs(path , s , 0 , res);
        return res;
    }
};
