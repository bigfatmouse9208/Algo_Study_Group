#
Runtime: 32 ms, faster than 98.18% of Python3 online submissions for Different Ways to Add Parentheses.
Memory Usage: 13.1 MB, less than 90.95% of Python3 online submissions for Different Ways to Add Parentheses.
#

class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        tokens = re.split('(\D)', input) # \D matches any non-decimal-digit chacracter
        nums = list(map(int, tokens[::2]))
        ops = list(map({'+' : operator.add, '-' : operator.sub, '*' : operator.mul}.get, tokens[1::2]))

        dp = {}
        def build(lo, hi):
            if lo == hi:
                return [nums[lo]]
            if (lo , hi) in dp:
                return dp[lo , hi]

            dp[lo , hi] =  [ops[i](a, b)
                    for i in range(lo, hi)
                    for a in build(lo, i)
                    for b in build(i + 1, hi)]
            return dp[lo , hi]

        return build(0, len(nums) - 1)
