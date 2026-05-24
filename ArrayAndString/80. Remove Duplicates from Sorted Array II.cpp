class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {              
            return nums.size();
        }

        int wrt = 2;

        for (int i = 2; i < nums.size(); i++) {

            if (nums[i] != nums[wrt - 2]) {
                nums[wrt++] = nums[i];
            }
        }
        return wrt;
    }
};


=======

only place at wrt if 

curr element is not equal to last second elemnet of valid window
