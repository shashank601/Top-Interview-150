class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int wrt = 1;
        for (int read = 1; read < nums.size(); ++read) {
            if (nums[read] != nums[read - 1]) {
                nums[wrt] = nums[read];
                ++wrt;
            }
        }

        return wrt;
    }
};
