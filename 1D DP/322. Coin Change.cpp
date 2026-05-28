class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (auto& coin : coins) {
            for (int amt = 1; amt < dp.size(); ++amt) {
                if (amt - coin >= 0 && dp[amt - coin] != INT_MAX) {
                    dp[amt] = min(dp[amt], dp[amt - coin] + 1);
                }
            }
        }   

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


===========

do not try to simulate the process in unbounded knapsack



State:
dp[x] = answer for amount x

Transition:
dp[x] = combine(dp[x - something])
Every value is formed by adding one choice to a smaller solved value

dp[x] = best over all choices:
        (answer for x - choice) + cost_of_choice
