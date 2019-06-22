/**
Runtime: 52 ms, faster than 89.89% of C++ online submissions for Word Ladder.
Memory Usage: 13 MB, less than 71.97% of C++ online submissions for Word Ladder.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord){
            return 1;
        }
        unordered_set<string> wordset (wordList.begin() , wordList.end());
        if (wordset.find(endWord) == wordset.end()){
            return 0;
        }
        wordset.erase(endWord);
        unordered_set<string> s1 ({beginWord}) , s2 ({endWord});
        int l = beginWord.size() , step = 1;
        string nw;
        string chars ("abcdefghijklmnopqrstuvwxyz");
        while (!s1.empty() && !s2.empty()){
            unordered_set<string> s;
            if (s1.size() < s2.size()){
                for (auto& w : s1){
                    for (int i = 0 ; i < l ; ++i){
                        for (auto& c : chars){
                            nw = w.substr(0 , i) + c + w.substr(i + 1, l - i - 1);
                            if (s2.find(nw) != s2.end()){
                                return step + 1;
                            }
                            if (wordset.find(nw) != wordset.end()){
                                s.insert(nw);
                                wordset.erase(nw);
                            }
                        }
                    }
                }
                s1 = s;
            }
            else{
                for (auto& w : s2){
                    for (int i = 0 ; i < l ; ++i){
                        for (auto& c : chars){
                            nw = w.substr(0 , i) + c + w.substr(i + 1, l - i - 1);
                            if (s1.find(nw) != s1.end()){
                                return step + 1;
                            }
                            if (wordset.find(nw) != wordset.end()){
                                s.insert(nw);
                                wordset.erase(nw);
                            }
                        }
                    }
                }
                s2 = s;
            }
            step++;
        }
        return 0;
    }
};
