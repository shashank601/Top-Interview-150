class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();


        vector<int> dp(n, 0);
        int ans = 1;
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

            }
                ans = max(dp[i], ans);
        }

        return ans;
    }
};

===========



lower bound is first occurence of target or value >= target

[1 2 3 [5] 5 6 5 [4] 3]
       lb         ub 
Finds the first 5	    vs   Finds the element just after the last 5

we need LB (a[i] >= 5) style binarySearch not UB (a[i] > 5)
                 ^ first 5                             ^ after last 5




key component TAILS vector:

1.we will maintain a vector which will [APPEND] curr value if its greater than all value in tails vector
                                          ^ key operation

2.if curr value is smaller than tails max  
we will either put it at its lowerBound and 
(never skip it )





eg. [0 0 3]  currVal is 2

=>  [0 0 3] wrong
=>  [0 0 2] right, 2 is not skipped

because Partion sorting have this rule that 
a larger value will always be better value to overwrite it will never decrease LIS






key: so this tails vector dont maintain a LIS but can tell the length of LIS in a 1D input

=============
i will try partition sorting later
