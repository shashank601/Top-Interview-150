class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l)/2;

            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                } else {
                    l = mid + 1;
                }
            } else if (mid == nums.size() - 1) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                } else {    
                    r = mid - 1;
                }
            } else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            } else if (nums[mid] > nums[mid + 1]) {
                r = mid - 1;
            } else if (nums[mid] < nums[mid + 1] ) {
                l = mid + 1;
            }
        }


        return -1;
    }

};


==========

A peak always exists because:

treat boundaries as -∞
a strictly increasing run ends in a peak
a strictly decreasing run starts with a peak
mixed arrays must change direction somewhere
==========

Binary search doesn't promise:
next mid gets closer to answer

It promises:
answer stays inside [l, r]
