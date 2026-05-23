class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = nums[0];                        <-- not 0

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];     

          
            ans = max(sum, ans);
            
            if (sum < 0) {
                sum = 0;
            }
        }

        return ans;
        
    }
};

=============
extend old subarray or start a new one (= 0,  then sum += -8)

