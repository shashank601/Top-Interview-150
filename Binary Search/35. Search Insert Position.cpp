class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            int mid = i + (j - i)/2;

            if (nums[mid] == target) {
                return mid;
            } 

            if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return  i;          <-- not j
        
    }
};


=========
j | i

i moven when nums[mid] < target =>  i = mid + 1


i moves past middle element if mid  is smaller < target
i will stop at insertion position



