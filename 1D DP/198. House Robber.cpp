class Solution {
public:
    int dp[100];
    
    int g(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];
        
        int skip = g(nums, i + 1);
        int take = g(nums, i + 2) + nums[i];
        
        return dp[i] = max(skip, take);
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return g(nums, 0);
    }
};







Consecutive skips (S S) only make sense if
the final element we take after the skips 
outweighs the single element we could have taken earlier

at max two skips


in iterative 
transformation  S T T => S S T from third Ts perspective (key: how the DP encodes multiple skips!)

000000000
101001010
100100100

