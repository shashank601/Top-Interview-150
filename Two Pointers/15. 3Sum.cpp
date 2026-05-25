class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i = 0;

        while (i < n) {

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j - 1] == nums[j]) {
                        j++;
                    }

                    while (j < k && nums[k + 1] == nums[k]) {
                        k--;
                    }
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    j++;
                }   
            }

            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
        }

        return ans;
        
    }
};

==== 
challenging part was skipping dups

first we do 
k++/--   <-- inc pointer
while ( ) k++/--   <-- now we can check with prev element safely and skip curr



and order matters
