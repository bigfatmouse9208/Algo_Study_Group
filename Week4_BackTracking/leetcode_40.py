"""
Runtime: 48 ms, faster than 93.46% of Python3 online submissions for Combination Sum II.
Memory Usage: 13.2 MB, less than 62.64% of Python3 online submissions for Combination Sum II.
"""

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        #print(candidates)
        res = []
        def dfs(path , target , start):
            if target == 0:
                #print(start , path)
                res.append(path)
                return
            for i in range(start , len(candidates)):
                if candidates[i] > target:
                    return
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                dfs(path + [candidates[i]] , target - candidates[i] , i + 1)

        dfs([] , target , 0)
        return res
