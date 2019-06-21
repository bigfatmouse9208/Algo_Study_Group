"""
Runtime: 60 ms, faster than 99.86% of Python3 online submissions for Word Ladder.
Memory Usage: 13.8 MB, less than 86.21% of Python3 online submissions for Word Ladder.
"""

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordset = set(wordList)
        if endWord not in wordset:
            return 0
        if beginWord == endWord:
            return 1
        wordset.remove(endWord)
        s1 , s2 = {beginWord} , {endWord}
        l = len(beginWord)
        step = 1

        while s1 and s2: # BFS. Check if one can reach s2 from s1
            s = set()
            if len(s1) > len(s2): # we always work on the smaller side to decrease the search space
                s1 , s2 = s2 , s1
            for word in s1:
                for i in range(l):
                    prefix , postfix = word[:i] , word[i + 1:]
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        w = prefix + c + postfix
                        if w in s2: # reach s2
                            return step + 1
                        if w in wordset: # reach a new word
                            s.add(w)
                            wordset.remove(w)
            s1 = s
            step += 1
        return 0
