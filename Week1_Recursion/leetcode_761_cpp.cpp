/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Special Binary String.
Memory Usage: 8.8 MB, less than 68.10% of C++ online submissions for Special Binary String.
*/

class Solution {
public:
    string makeLargestSpecial(string S) {
      //from the definition of special string, we can prove that each special string is made up of
      // several special substring. So if we divide the whole string into as many special substring as possible
      // and make each substring the largest, in the end concatenate them together from largerst to smallest
      // the problem is solved
        vector<string> substrings;
        int status = 0 , start = 0;
        for (int i = 0 ; i < S.size() ; ++i){
            status += (S[i] == '1') ? 1 : -1;
            if (status == 0){
              // since S is a speical string, it is guaranteed that once we have equal number of '1' and '0'
              // the correponding substring must also be a speical string
              // from definition we know a speical string must start with '1' and end with '0'
              // hence from the substring[1:-1] is also a substring
                substrings.push_back("1" + makeLargestSpecial(S.substr(start + 1 , i - start - 1)) + "0");
                // we find the largerst substring
                start = i + 1;
            }
        }
        sort(substrings.begin() , substrings.end() , greater<string>());
        string ans;
        for (auto& s : substrings){
            ans += s;
        }
        return ans;
    }
};
