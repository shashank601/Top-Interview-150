class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;

        int len = INT_MAX;

        int st = 0;        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];


            while (st <= i && sum >= target) {
                if (sum >= target) len = min(len, i - st + 1);
                sum -= nums[st];
                st++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};

==============


lets say newly added element is 98 and target is 71  
now when we shrink we should account new win shrinked len too

and eventualy only new element will left and ans will be 1

==============

slliding window bcz of only +ives values (add element will always increase the sum)
