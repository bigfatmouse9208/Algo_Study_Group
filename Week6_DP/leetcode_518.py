"""
Runtime: 132 ms, faster than 94.44% of Python3 online submissions for Coin Change 2.
Memory Usage: 13.1 MB, less than 95.63% of Python3 online submissions for Coin Change 2.
"""

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        #coins.sort()
        dp = [0 for _ in range(amount + 1)]
        dp[0] = 1

        for coin in coins:
            for cap in range(amount + 1 - coin):
                dp[cap + coin] += dp[cap]
        return dp[-1]
