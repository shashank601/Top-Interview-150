class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l)/2;

            if (nums[mid] == target) return mid;

            if (nums[mid] < nums[r]) {

                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }

            }
        }

        return -1;
    }
};

=========

Find which half is sorted.                      <-- one hald either left of mid or righit of mid will always be perfectly sorted no valley
Check if target is inside that sorted range.     <-- we can decide with 100% guratee whether target exist there or not
Keep that half if it contains the target; otherwise discard it.  


the key is to check target with both l and r of sorted range

(target < nums[mid] && target >= nums[l]
