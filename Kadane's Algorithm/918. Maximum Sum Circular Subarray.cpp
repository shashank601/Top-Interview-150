class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = 0;
        int mn = 0;

        int ansMx = INT_MIN;
        int ansMn = INT_MAX;

        int total = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < nums.size(); i++) {
            mx += nums[i];
            ansMx = max(mx, ansMx);

            if (mx < 0) mx = 0;


            mn += nums[i];
            ansMn = min(mn, ansMn);

            if (mn > 0) mn = 0;
        }
        
        if (ansMx < 0) return ansMx; 

        return max(ansMx, total - ansMn);

    }
};


=========

return max(maxSum, total - minSum);


=========

total < 0 means -ve value dominates, 
not +ive elemnt dont exist.

=========

precise codnn is ansMx < 0
now maxSubarray is -ve 


so total - ansMn will be  0 

but 0 is empty array
not allowed


so we handle this case seprately if total - ansMn is 0 we return ansMx
