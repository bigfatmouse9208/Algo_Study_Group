/**
Runtime: 4 ms, faster than 99.59% of C++ online submissions for Coin Change 2.
Memory Usage: 8.5 MB, less than 93.04% of C++ online submissions for Coin Change 2.
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1 , 0);
        dp[0] = 1;

        for (auto& coin : coins){
            for (int cap = 0 ; cap <= amount - coin ; cap++){
                dp[cap + coin] += dp[cap];
            }
        }

        return dp[amount];
    }
};
