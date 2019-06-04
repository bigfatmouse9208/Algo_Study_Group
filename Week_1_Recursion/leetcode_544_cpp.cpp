/**
Runtime: 8 ms, faster than 93.12% of C++ online submissions for Output Contest Matches.
Memory Usage: 13.6 MB, less than 23.62% of C++ online submissions for Output Contest Matches.
*/

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> matches;
        for (int i = 1 ; i <= n ; ++i){
            matches.push_back(to_string(i));
        }
        while (matches.size() != 1){
            matches = helper(matches);
        }
        return matches[0];
    }
    vector<string> helper(auto& matches){
        int i = 0 , j = matches.size()- 1;
        vector<string> res;
        while (i < j){
            string line = '(' + matches[i] + ',' + matches[j] + ')';
            res.push_back(line);
            ++i;
            --j;
        }
        return res;
    }
};
